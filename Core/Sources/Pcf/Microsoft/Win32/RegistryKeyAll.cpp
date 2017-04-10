#if defined(__linux__) || defined(__APPLE__)

#include "../../../../Includes/Pcf/Microsoft/Win32/Registry.h"
#include "../../../../Includes/Pcf/Microsoft/Win32/RegistryKey.h"
#include "../../../../Includes/Pcf/System/IO/Directory.h"
#include "../../../../Includes/Pcf/System/IO/DirectoryInfo.h"
#include "../../../../Includes/Pcf/System/IO/File.h"
#include "../../../../Includes/Pcf/System/IO/Path.h"

using namespace System;
using namespace System::IO;
using namespace Microsoft::Win32;
using namespace System::Collections::Generic;

namespace {
  static void CreateDefaultFile(const System::String &path) {
    System::IO::File::WriteAllText(path, "<Values>\n<Value Key=\"(Default)\"\nKind=\"String\"></Value>\n</Values>\n");
  }
  
  static bool ExistSubKey(const System::String& path, const System::String& subKey) {
    if (subKey == "")
      return true;
    
    Array<DirectoryInfo> directories = DirectoryInfo(path).GetDirectories();
    System::String subKeyLowered = subKey.ToLower();
    for (DirectoryInfo directory : directories) {
      if (directory.Name().ToLower() == subKeyLowered)
        return true;
    }
    return false;
  }
  
  static System::String MakePath(const System::String& path, const System::String& subKey) {
    if (subKey == "")
      return path;
    
    Array<DirectoryInfo> directories = DirectoryInfo(path).GetDirectories();
    System::String subKeyLowered = subKey.ToLower();
    for (DirectoryInfo directory : directories) {
      if (directory.Name().ToLower() == subKeyLowered)
        return Path::Combine(path, directory.Name());
    }
    return Path::Combine(path, subKey);
  }
}

RegistryKey::RegistryHandle::RegistryHandle(void* key, const System::String& name) : handle(this) {
}

RegistryKey::RegistryHandle::RegistryHandle(RegistryHive rhive) : handle(this) {
}

RegistryKey::RegistryHandle::~RegistryHandle() {
}

RegistryKey::RegistryKey(): permission(RegistryKeyPermissionCheck::ReadWriteSubTree) {
}

RegistryKey::RegistryKey(RegistryHive rhive)  : name(ToName(rhive)), permission(RegistryKeyPermissionCheck::ReadWriteSubTree) {
  this->path = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::UserProfile), ".Pcf", "Registry", ToName(rhive));
  if (not Directory::Exists(this->path)) {
    Directory::CreateDirectory(this->path);
    ::CreateDefaultFile(Path::Combine(this->path, "Values.xml"));
  }
  
  this->handle = RefPtr<RegistryHandle>::Create();
  this->Load();
}

RegistryKey::~RegistryKey() {
}

int32 RegistryKey::SubKeyCount() const {
  return DirectoryInfo(this->path).GetDirectories().Count;
}

void RegistryKey::Close() {
}

RegistryKey RegistryKey::CreateSubKey(const System::String& subKey, RegistryKeyPermissionCheck permissionCheck) {
  RegistryKey key = OpenSubKey(subKey, permissionCheck);
  if (key != RegistryKey::Null())
      return key;
  
  if (this->permission != RegistryKeyPermissionCheck::ReadWriteSubTree)
    throw UnauthorizedAccessException(pcf_current_information);
  
  key.handle = RefPtr<RegistryHandle>::Create();
  key.path = ::MakePath(this->path, subKey);
  Directory::CreateDirectory(key.path);
  ::CreateDefaultFile(Path::Combine(key.path, "Values.xml"));
  key.name = System::String::Format("{0}\\{1}", this->name, subKey);
  key.permission = permissionCheck == RegistryKeyPermissionCheck::Default ? this->permission : permissionCheck;

  return key;
}

void  RegistryKey::DeleteSubKey(const System::String& subKey, bool throwOnMissingSubKey) {
  if (subKey == "")
    throw InvalidOperationException(pcf_current_information);
  
  if (IsBaseKey(subKey))
    throw ArgumentException(pcf_current_information);
  
  System::String path = ::MakePath(this->path, subKey);
  if (::ExistSubKey(this->path, subKey)) {
    if (DirectoryInfo(path).GetDirectories().Count != 0)
      throw InvalidOperationException(pcf_current_information);
    Directory::Delete(path, true);
    return;
  }
  
  if (throwOnMissingSubKey)
    throw ArgumentException(pcf_current_information);
}

void  RegistryKey::DeleteSubKeyTree(const System::String& subKey, bool throwOnMissingSubKey) {
  if (subKey == "" or IsBaseKey(subKey))
    throw ArgumentNullException(pcf_current_information);
  
  System::String path = ::MakePath(this->path, subKey);
  if (::ExistSubKey(this->path, subKey)) {
    Directory::Delete(path, true);
    return;
  }
  
  if (throwOnMissingSubKey)
    throw ArgumentException(pcf_current_information);
}

Array<System::String> RegistryKey::GetSubKeyNames() {
  Array<IO::DirectoryInfo> dirInfo = DirectoryInfo(System::String::Format("{0}", this->path)).GetDirectories();
  System::Collections::Generic::List<System::String> subKeyNames;
  for (IO::DirectoryInfo item : dirInfo)
    subKeyNames.Add(item.Name());
  subKeyNames.Sort();
  return subKeyNames.ToArray();
}

void RegistryKey::Flush() {
  System::String value = System::String::Format("<Values>{0}{1}{0}</Values>{0}", Environment::NewLine, System::String::Join(Environment::NewLine, this->values.Values()));
  System::IO::File::WriteAllText(Path::Combine(this->path, "Values.xml"), value);
}

RegistryKey RegistryKey::OpenSubKey(const System::String& subKeyName, RegistryKeyPermissionCheck permissionCheck) {
  System::String path = ::MakePath(this->path, subKeyName);
  if (not ::ExistSubKey(this->path, subKeyName))
    return RegistryKey::Null();
  
  RegistryKey key;
  key.path = path;
  key.name = System::String::Format("{0}\\{1}", this->name, subKeyName);
  key.permission = permissionCheck == RegistryKeyPermissionCheck::Default ? this->permission : permissionCheck;
  key.Load();
  
  return key;
}

void RegistryKey::Load() {
  try {
    this->values.Clear();

    System::String s = System::IO::File::ReadAllText(Path::Combine(this->path, "Values.xml"));
    System::String toParse = s.Remove(s.IndexOf("</Values>\n")).Substring(s.IndexOf("<Values>\n")+9).Replace(System::Environment::NewLine, "");
    while (not toParse.IsEmpty()) {
      RegistryKeyValue rkv = RegistryKeyValue::Parse(toParse.Substring(0, toParse.IndexOf("</Value>")+8));
      toParse = toParse.Remove(0, toParse.IndexOf("</Value>")+8);
      this->values[rkv.Key().ToLower()] = rkv;
    }
  } catch(const System::Exception& e) {
    throw System::FormatException(pcf_current_information);
  }
}

#endif
