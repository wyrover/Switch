#if defined(_WIN32)

#include "../../../../Includes/Pcf/Microsoft/Win32/Registry.hpp"
#include "../../../../Includes/Pcf/Microsoft/Win32/RegistryKey.hpp"
#include "../../../../Includes/Pcf/System/IO/IOException.hpp"
#include "../../../__OS/CoreApi.hpp"

using namespace System;
using namespace Microsoft::Win32;

namespace {
  refptr<object> BinaryToObject(const char* valueBytes, int32 length) {
    if (valueBytes == null)
      throw ArgumentNullException(pcf_current_information);

    if (length < 0)
      throw ArgumentException(pcf_current_information);

    return refptr<object>(new Array<byte>(reinterpret_cast<const byte*>(valueBytes), length));
  }

  refptr<object> DWordToObject(const char* valueBytes) {
    if (valueBytes == null)
      throw ArgumentNullException(pcf_current_information);

    return refptr<object>(new Int32(*reinterpret_cast<const int32*>(valueBytes)));
  }

  refptr<object> ExpandStringToObject(const char* valueBytes) {
    struct AutoDeleteCharPointer {
      AutoDeleteCharPointer(char* value) : value(value) {}
      ~AutoDeleteCharPointer() {delete value;}
      char* operator()() const {return this->value;}
    private:
      char* value;
    };
    
    if (valueBytes == null)
      throw ArgumentNullException(pcf_current_information);

    int32 length = 32768;
    AutoDeleteCharPointer expandedString(new char[length]);

    if (__OS::CoreApi::Registry::ExpandString(valueBytes, expandedString(), length) == 0)
      throw IO::IOException(pcf_current_information);

    return refptr<object>(new string(expandedString()));
  }

  refptr<object> MultiStringToObject(const char* valueBytes) {
    if (valueBytes == null)
      throw ArgumentNullException(pcf_current_information);

    refptr<Array<string>> vakues = new Array<string>();

    for (char* line = const_cast<char*>(valueBytes); line[0] != 0; line += strlen(line) + 1) {
      Array<string>::Resize(*vakues, vakues->Length + 1);
      (*vakues)[vakues->Length - 1] = line;
    }

    return vakues.ChangeType<object>();
  }

  refptr<object> QWordToObject(const char* valueBytes) {
    if (valueBytes == null)
      throw ArgumentNullException(pcf_current_information);

    return refptr<object>(new Int64(*reinterpret_cast<const int64*>(valueBytes)));
  }

  refptr<object> StringToObject(const char* valueBytes) {
    if (valueBytes == null)
      throw ArgumentNullException(pcf_current_information);

    return refptr<object>(new string(valueBytes));
  }
};

RegistryKey::RegistryHandle::RegistryHandle(void* key, const string& name) {
  if (__OS::CoreApi::Registry::CreateSubKey(key, name.Data(), &this->handle) != 0)
    throw IO::IOException(pcf_current_information);
}

RegistryKey::RegistryHandle::RegistryHandle(RegistryHive rhive) {
  __OS::CoreApi::Registry::GetHandleBaseKey((int32)rhive, &this->handle);
}

RegistryKey::RegistryHandle::~RegistryHandle() {
  __OS::CoreApi::Registry::CloseKey(this->handle);
}

RegistryKey::RegistryKey(RegistryHive rhive) : name(ToName(rhive)), permission(RegistryKeyPermissionCheck::ReadWriteSubTree) {
  handle = new RegistryHandle(rhive);
}

RegistryKey::RegistryKey() : handle(0), name(""), permission(RegistryKeyPermissionCheck::ReadWriteSubTree) {
}

RegistryKey::~RegistryKey() {
  Close();
}

int32 RegistryKey::SubKeyCount() const {
  return __OS::CoreApi::Registry::NumberOfSubKey((void*)this->handle->Handle());
}

void RegistryKey::Close() {
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

  int32 result = __OS::CoreApi::Registry::DeleteSubKey(this->handle->Handle(), subKey.Data());

  if (result == 2 && throwOnMissingSubKey)
    throw ArgumentException(pcf_current_information);

  if (result != 0 && result != 2)
    throw IO::IOException(pcf_current_information);
}

void  RegistryKey::DeleteSubKeyTree(const string& subKey, bool throwOnMissingSubKey) {
  if (subKey == "" || IsBaseKey(subKey))
    throw ArgumentException(pcf_current_information);

  int32 result = __OS::CoreApi::Registry::DeleteTree(this->handle->Handle(), subKey.Data());

  if (result == 2 && throwOnMissingSubKey)
    throw ArgumentException(pcf_current_information);

  if (result != 0 && result != 2)
    throw IO::IOException(pcf_current_information);
}

void RegistryKey::Flush() {
}

RegistryKey RegistryKey::OpenSubKey(const string& subKeyName, RegistryKeyPermissionCheck permissionCheck) {
  void* handle = null;

  if (this->handle == null)
    throw ArgumentNullException(pcf_current_information);

  if (__OS::CoreApi::Registry::OpenSubKey(this->handle->Handle(), subKeyName.Data(), &handle) != 0)
    return RegistryKey::Null();

  RegistryKey key;
  key.name = this->name + "\\" + subKeyName;
  key.permission = permissionCheck == RegistryKeyPermissionCheck::Default ? this->permission : permissionCheck;
  key.handle = new RegistryHandle(handle);

  return key;
}

Array<string> RegistryKey::GetSubKeyNames() {
  int32 nbsubKey = 0;
  int32 nbkeyvalue = 0;
  if (__OS::CoreApi::Registry::QueryInfoKey(this->handle->Handle(), nbsubKey, nbkeyvalue) != 0)
    return Array<string>();

  Array<string> ars(nbsubKey);
  int32 index = 0;
  while (index < nbsubKey) {
    char key[256];
    int keySize = 256;
    if (__OS::CoreApi::Registry::EnumKey(this->handle->Handle(), index, key, keySize) != 0)
      break;
    
    ars[index++] = key;
  }
  
  return ars;
}

#endif
