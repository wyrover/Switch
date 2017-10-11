#if defined(__linux__) || defined(__APPLE__)

#include <cstdlib>

#include "Api.hpp"

string Native::RegistryApi::GetDefaultString() {
  return "Default";
}

int32 Native::RegistryApi::CloseKey(intptr key) {
  return 0;
}

int32 Native::RegistryApi::DeleteValue(intptr key, const string& subkeyName) {
  return 0;
}

int32 Native::RegistryApi::SetValue(intptr key, const string& keyName, Microsoft::Win32::RegistryValueKind type, const byte* data, int32 length) {
  return 0;
}

int32 Native::RegistryApi::Flush(intptr key) {
  return 0;
}

int32 Native::RegistryApi::DeleteTree(intptr key, const string& subkeyName) {
  return 0;
}

int32 Native::RegistryApi::OpenSubKey(intptr rootKey, const string& subKey, intptr& key) {
  return 0;
}

int32 Native::RegistryApi::CreateSubKey(intptr rootKey, const string& subKey, intptr& key) {
  return 0;
}

int32  Native::RegistryApi::EnumKey(intptr key, int32 index, string& subkeyname) {
  return 0;
}

int32 Native::RegistryApi::QueryInfoKey(intptr key,int32& subKey ,int32& value) {
  return 0;
}

int32  Native::RegistryApi::DeleteSubKey(intptr Key,const string& subkeyName) {
  return 0;
}

int32 Native::RegistryApi::GetValue(intptr key, const string& subKey, Microsoft::Win32::RegistryValueKind& type, System::Array<byte>& data) {
  return 0;
}

int32  Native::RegistryApi::GetHandleBaseKey (Microsoft::Win32::RegistryHive reghive, intptr& key) {
  return 0;
}

#endif
