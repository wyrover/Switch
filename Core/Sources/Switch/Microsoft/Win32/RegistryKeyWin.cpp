#if defined(_WIN32)

#include "../../../../Includes/Pcf/Microsoft/Win32/Registry.hpp"
#include "../../../../Includes/Pcf/Microsoft/Win32/RegistryKey.hpp"
#include "../../../../Includes/Pcf/System/IO/IOException.hpp"
#include "../../../../Includes/Pcf/System/Console.hpp"
#include "../../../__OS/CoreApi.hpp"

using namespace System;
using namespace Microsoft::Win32;

RegistryKey::RegistryHandle::RegistryHandle(intptr key, const string& name) {
  if (__OS::CoreApi::Registry::CreateSubKey(key, name, this->handle) != 0)
    throw IO::IOException(pcf_current_information);
}

RegistryKey::RegistryHandle::RegistryHandle(RegistryHive rhive) {
  __OS::CoreApi::Registry::GetHandleBaseKey(rhive, this->handle);
}

RegistryKey::RegistryHandle::~RegistryHandle() {
  __OS::CoreApi::Registry::CloseKey(this->handle);
}

RegistryKey::RegistryKey(RegistryHive rhive) : name(ToName(rhive)), permission(RegistryKeyPermissionCheck::ReadWriteSubTree) {
  handle = pcf_new<RegistryHandle>(rhive);
  this->Load();
}

RegistryKey::RegistryKey() : handle(0), name(""), permission(RegistryKeyPermissionCheck::ReadWriteSubTree) {
}

RegistryKey::~RegistryKey() {
  Close();
}

int32 RegistryKey::SubKeyCount() const {
  return __OS::CoreApi::Registry::NumberOfSubKey(this->handle->Handle());
}

void RegistryKey::Close() {
  this->Flush();
}

RegistryKey RegistryKey::CreateSubKey(const string& subKey, RegistryKeyPermissionCheck permissionCheck) {
  RegistryKey key = OpenSubKey(subKey, permissionCheck);
  if (key != RegistryKey::Null())
    return key;

  if (this->permission != RegistryKeyPermissionCheck::ReadWriteSubTree)
    throw UnauthorizedAccessException(pcf_current_information);

  key.handle = new RegistryHandle(this->handle->Handle(), subKey);
  key.path = string::Format("{0}\\{1}", this->name, subKey);
  key.name = string::Format("{0}\\{1}", this->name, subKey);
  key.permission = permissionCheck == RegistryKeyPermissionCheck::Default ? this->permission : permissionCheck;

  return key;
}

void  RegistryKey::DeleteSubKey(const string& subKey, bool throwOnMissingSubKey) {
  if (subKey == "")
    throw InvalidOperationException(pcf_current_information);

  if (IsBaseKey(subKey))
    throw ArgumentException(pcf_current_information);

  //if (__OS::CoreApi::Registry::NumberOfSubKey)

  int32 result = __OS::CoreApi::Registry::DeleteSubKey(this->handle->Handle(), subKey);

  if (result == 2 && throwOnMissingSubKey)
    throw ArgumentException(pcf_current_information);

  if (result != 0 && result != 2)
    throw IO::IOException(pcf_current_information);
}

void  RegistryKey::DeleteSubKeyTree(const string& subKey, bool throwOnMissingSubKey) {
  if (subKey == "" || IsBaseKey(subKey))
    throw ArgumentException(pcf_current_information);

  int32 result = __OS::CoreApi::Registry::DeleteTree(this->handle->Handle(), subKey);

  if (result == 2 && throwOnMissingSubKey)
    throw ArgumentException(pcf_current_information);

  if (result != 0 && result != 2)
    throw IO::IOException(pcf_current_information);
}

namespace {
  void SetValue(intptr key, const string& keyName, RegistryValueKind kind, const Array<byte>& value) {
    __OS::CoreApi::Registry::SetValue(key, keyName, kind, (const byte*)value.Data(), value.Length());
  }

  void SetValue(intptr key, const string& keyName, RegistryValueKind kind, const Int32& value) {
    int32 i = value;
    __OS::CoreApi::Registry::SetValue(key, keyName, kind, (const byte*)&i, 4);
  }

  void SetValue(intptr key, const string& keyName, RegistryValueKind kind, const Int64& value) {
    int64 i = value;
    __OS::CoreApi::Registry::SetValue(key, keyName, kind, (const byte*)&i, 8);
  }

  void SetValue(intptr key, const string& keyName, RegistryValueKind kind, const Array<string>& values) {
    int32 length = 1;
    for (auto& value : values)
      length += (int32)value.w_str().length() + 1;
    std::wstring str(length, '\0');
    int32 index = 0;
    for (auto& value : values) {
      std::wstring s = value.w_str();
      str = str.replace(index, s.length(), s);
      index += (int32)s.length() + 1;
    }
    str[index] = 0;
    __OS::CoreApi::Registry::SetValue(key, keyName, kind, (const byte*)str.c_str(), (int32)str.length() * sizeof(wchar_t));
  }

  void SetValue(intptr key, const string& keyName, RegistryValueKind kind, const string& value) {
    std::wstring str = value.w_str();
    __OS::CoreApi::Registry::SetValue(key, keyName, kind, (const byte*)str.c_str(), (int32)str.length() * sizeof(wchar_t));
  }

  void SetValue(intptr key, const string& keyName, RegistryValueKind kind, const object& value) {
    std::wstring str = value.ToString().w_str();
    __OS::CoreApi::Registry::SetValue(key, keyName, kind, (const byte*)str.c_str(), (int32)str.length() * sizeof(wchar_t));
  }
}

void RegistryKey::Flush() {
  for (const RegistryKeyValue& registryKeyValue : this->values.Values()) {
    switch (registryKeyValue.Kind()) {
    case RegistryValueKind::String: ::SetValue(this->handle->Handle(), registryKeyValue.Key(), registryKeyValue.Kind(), as<string>(registryKeyValue.InternalValue())); break;
    case RegistryValueKind::ExpandString: ::SetValue(this->handle->Handle(), registryKeyValue.Key(), registryKeyValue.Kind(), as<string>(registryKeyValue.InternalValue())); break;
    case RegistryValueKind::MultiString: ::SetValue(this->handle->Handle(), registryKeyValue.Key(), registryKeyValue.Kind(), as<System::Array<string>>(registryKeyValue.InternalValue())); break;
    case RegistryValueKind::Binary: ::SetValue(this->handle->Handle(), registryKeyValue.Key(), registryKeyValue.Kind(), as<System::Array<byte>>(registryKeyValue.InternalValue())); break;
    case RegistryValueKind::DWord: ::SetValue(this->handle->Handle(), registryKeyValue.Key(), registryKeyValue.Kind(), as<System::Int32>(registryKeyValue.InternalValue())); break;
    case RegistryValueKind::QWord: ::SetValue(this->handle->Handle(), registryKeyValue.Key(), registryKeyValue.Kind(), as<System::Int64>(registryKeyValue.InternalValue())); break;
    default: ::SetValue(this->handle->Handle(), registryKeyValue.Key(), RegistryValueKind::String, registryKeyValue.Value()); break;
    }
  }
}

namespace {
  const Array<byte>& BytesToBinary(const Array<byte>& bytes) {
    return bytes;
  }

  Int32 BytesToDWord(const Array<byte>& bytes) {
    return Int32((int32)*bytes.Data());
  }

  Array<string> BytesToMultiString(const Array<byte>& bytes) {
    Array<string> values;
    for (wchar* line = (wchar*)bytes.Data(); line[0] != 0; line += wcslen(line) + 1) {
      Array<string>::Resize(values, values.Length + 1);
      values[values.Length - 1] = line;
    }
    return values;
  }

  Int64 BytesToQWord(const Array<byte>& bytes) {
    return Int64((int64)*bytes.Data());
  }

  string BytesToString(const Array<byte>& bytes) {
    return string((const wchar*)bytes.Data());
  }
};

void RegistryKey::Load() {
  this->values.Clear();

  int32 subKeyNumber = 0;
  int32 keyvalueNumber = 0;
  if (__OS::CoreApi::Registry::QueryInfoKey(this->handle->Handle(), subKeyNumber, keyvalueNumber) != 0)
    return;
  
  for (int32 index = 0; index < keyvalueNumber; index++) {
    string keyName;
    RegistryValueKind kind;
    if (__OS::CoreApi::Registry::EnumValues(this->handle->Handle(), index, keyName, kind) != 0)
      break;
    Array<byte> data;
    __OS::CoreApi::Registry::GetValue(this->handle->Handle(), keyName, kind, data);

    switch (kind) {
    case RegistryValueKind::Binary: this->values[keyName.ToLower()] = RegistryKeyValue(keyName, BytesToBinary(data), kind); break;
    case RegistryValueKind::MultiString: this->values[keyName.ToLower()] = RegistryKeyValue(keyName, BytesToMultiString(data), kind); break;
    case RegistryValueKind::DWord: this->values[keyName.ToLower()] = RegistryKeyValue(keyName, BytesToDWord(data), kind); break;
    case RegistryValueKind::QWord: this->values[keyName.ToLower()] = RegistryKeyValue(keyName, BytesToQWord(data), kind); break;
    default: this->values[keyName.ToLower()] = RegistryKeyValue(keyName, BytesToString(data), kind); break;
    }
  }
}

RegistryKey RegistryKey::OpenSubKey(const string& subKeyName, RegistryKeyPermissionCheck permissionCheck) {
  intptr handle = 0;

  if (this->handle == null)
    throw ArgumentNullException(pcf_current_information);

  if (__OS::CoreApi::Registry::OpenSubKey(this->handle->Handle(), subKeyName.Data(), handle) != 0)
    return RegistryKey::Null();

  RegistryKey key;
  key.name = this->name + "\\" + subKeyName;
  key.permission = permissionCheck == RegistryKeyPermissionCheck::Default ? this->permission : permissionCheck;
  key.handle = new RegistryHandle(handle);
  key.Load();

  return key;
}

Array<string> RegistryKey::GetSubKeyNames() {
  int32 subKeyNumber = 0;
  int32 keyvalueNumber = 0;
  if (__OS::CoreApi::Registry::QueryInfoKey(this->handle->Handle(), subKeyNumber, keyvalueNumber) != 0)
    return Array<string>();

  Array<string> subKeys(subKeyNumber);
  for (int32 index = 0; index < subKeyNumber; index++)
    if (__OS::CoreApi::Registry::EnumKey(this->handle->Handle(), index, subKeys[index]) != 0)
      break;
  return subKeys;
}

#endif
