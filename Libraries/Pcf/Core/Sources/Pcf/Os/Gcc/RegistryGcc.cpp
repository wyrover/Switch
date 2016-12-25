#if !_WIN32

#include <cstdlib>

#include "../Registry.h"

using namespace Os;

const char *Registry::GetDefaultString() {
  return "Default";
}

int32 Registry::CloseKey(void* hKey) {
  return 0;
}

int32 Registry::DeleteValue(void* hKey,const char* subkeyName) {
  return 0;
}

int32 Registry::SetValue(void* hKey, const char* keyName, int32 type, byte* bData, int32 cbData) {
  return 0;
}

int32 Registry::Flush(void* hKey) {
  return 0;
}

int32 Registry::DeleteTree(void *hKey,const char* subkeyName) {
  return 0;
}

int32 Registry::OpenSubKey(const void* hrootKey, const char* subKey, void** hkey) {
  return 0;
}

int32 Registry::CreateSubKey(const char* rootKeystr, const char* subKey, void** hkey) {
  return 0;
}

int32 Registry::CreateSubKey(const void* hrootKey, const char* subKey, void** hkey) {
  return 0;
}

int32  Registry::EnumValues(void* hkey, int32 dwIndex,char *avaluenamey,char* val, int32 &typeofvalue,int32& sizekey,int32& sizeval) {
  return 0;
}

int32  Registry::EnumKey(void* hkey, int32 dwIndex,char *subkeyname,int32& sizesubkey) {
  return 0;
}

int32 Registry::QueryInfoKey(void* hkey,int32& subKey ,int32& value) {
  return 0;
}

int32 Registry::ExpandString(const char *strtoexpand,char *data_expanded,int32 cbData) {
  return 0;
}

int32  Registry::DeleteSubKey(void* hKey,const char* subkeyName) {
  return 0;
}

int32 Registry::GetValue(void* hkey, const char* subKey, int32 &type, void* data, int32* cbData) {
  return 0;
}

int32  Registry::GetHandleBaseKey (int32 reghive,void** hkey) {
  return 0;
}

#endif
