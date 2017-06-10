#if defined(__linux__) || defined(__APPLE__)

#include <cstdlib>

#include "CoreApi.hpp"

const char *__OS::CoreApi::Registry::GetDefaultString() {
  return "Default";
}

int32 __OS::CoreApi::Registry::CloseKey(void* hKey) {
  return 0;
}

int32 __OS::CoreApi::Registry::DeleteValue(void* hKey,const char* subkeyName) {
  return 0;
}

int32 __OS::CoreApi::Registry::SetValue(void* hKey, const char* keyName, int32 type, byte* bData, int32 cbData) {
  return 0;
}

int32 __OS::CoreApi::Registry::Flush(void* hKey) {
  return 0;
}

int32 __OS::CoreApi::Registry::DeleteTree(void *hKey,const char* subkeyName) {
  return 0;
}

int32 __OS::CoreApi::Registry::OpenSubKey(const void* hrootKey, const char* subKey, void** hkey) {
  return 0;
}

int32 __OS::CoreApi::Registry::CreateSubKey(const char* rootKeystr, const char* subKey, void** hkey) {
  return 0;
}

int32 __OS::CoreApi::Registry::CreateSubKey(const void* hrootKey, const char* subKey, void** hkey) {
  return 0;
}

int32  __OS::CoreApi::Registry::EnumValues(void* hkey, int32 dwIndex,char *avaluenamey,char* val, int32 &pcf_typeofvalue,int32& sizekey,int32& sizeval) {
  return 0;
}

int32  __OS::CoreApi::Registry::EnumKey(void* hkey, int32 dwIndex,char *subkeyname,int32& sizesubkey) {
  return 0;
}

int32 __OS::CoreApi::Registry::QueryInfoKey(void* hkey,int32& subKey ,int32& value) {
  return 0;
}

int32 __OS::CoreApi::Registry::ExpandString(const char *strtoexpand,char *data_expanded,int32 cbData) {
  return 0;
}

int32  __OS::CoreApi::Registry::DeleteSubKey(void* hKey,const char* subkeyName) {
  return 0;
}

int32 __OS::CoreApi::Registry::GetValue(void* hkey, const char* subKey, int32 &type, void* data, int32* cbData) {
  return 0;
}

int32  __OS::CoreApi::Registry::GetHandleBaseKey (int32 reghive,void** hkey) {
  return 0;
}

#endif
