#if defined(__linux__) || defined(__APPLE__)

#include <cstdlib>

#include "CoreApi.hpp"

string __OS::CoreApi::Registry::GetDefaultString() {
  return "Default";
}

int32 __OS::CoreApi::Registry::CloseKey(intptr key) {
  return 0;
}

int32 __OS::CoreApi::Registry::DeleteValue(intptr key, const string& subkeyName) {
  return 0;
}

int32 __OS::CoreApi::Registry::SetValue(intptr key, const string& keyName, int32 type, const Array<byte>& data) {
  return 0;
}

int32 __OS::CoreApi::Registry::Flush(intptr key) {
  return 0;
}

int32 __OS::CoreApi::Registry::DeleteTree(intptr key, const string& subkeyName) {
  return 0;
}

int32 __OS::CoreApi::Registry::OpenSubKey(intptr rootKey, const string& subKey, intptr& key) {
  return 0;
}

int32 __OS::CoreApi::Registry::CreateSubKey(intptr rootKey, const string& subKey, intptr& key) {
  return 0;
}

int32  __OS::CoreApi::Registry::EnumKey(intptr hkey, int32 index, string& subkeyname) {
  return 0;
}

int32 __OS::CoreApi::Registry::QueryInfoKey(intptr hkey,int32& subKey ,int32& value) {
  return 0;
}

int32  __OS::CoreApi::Registry::DeleteSubKey(intptr hKey,const string& subkeyName) {
  return 0;
}

int32 __OS::CoreApi::Registry::GetValue(intptr hkey, const string& subKey, int32& type, System::Array<byte>& data) {
  return 0;
}

int32  __OS::CoreApi::Registry::GetHandleBaseKey (Microsoft::Win32::RegistryHive reghive, intptr& key) {
  return 0;
}

#endif
