#if defined(_WIN32)

#include <windows.hpp>
#include "../../Includes/Pcf/Undef.hpp"

#include <cstdlib>

#include "CoreApi.hpp"

const char *__OS::CoreApi::Registry::GetDefaultString() {
  return "";
}

int32 __OS::CoreApi::Registry::GetValue(void* hkey, const char* subKey, int32 &type, void* data, int32* cbData) {
  DWORD thetype;
  
  int32 returnCode = RegQueryValueExA((HKEY)hkey, subKey, 0, &thetype, (LPBYTE)data, (LPDWORD)cbData);
  if (returnCode == 0)  {
    type = thetype;
    return 0;
  }
  
  if (returnCode == ERROR_FILE_NOT_FOUND)
    return -1;
  
  return -2;
}

int32 __OS::CoreApi::Registry::ExpandString(const char* strtoexpand, char* data_expanded, int32 cbData) {
  return ExpandEnvironmentStringsA((LPSTR)strtoexpand, (LPSTR)data_expanded, cbData);
}

int32 __OS::CoreApi::Registry::NumberOfSubKey(void* hkey) {
  LPSTR className = null;
  DWORD classNameSize = MAX_PATH;
  DWORD subKey = 0;
  DWORD maxSubKey;
  DWORD maxClass;
  DWORD value;
  DWORD maxValue;
  DWORD maxValueData;
  DWORD securityDescriptor;
  FILETIME ftLastWriteTime;
  
  if (RegQueryInfoKeyA((HKEY)hkey, className, &classNameSize, null, &subKey, &maxSubKey, &maxClass, &value, &maxValue, &maxValueData, &securityDescriptor, &ftLastWriteTime) == 0)
    return subKey;
  return -1;
}

int32 __OS::CoreApi::Registry::NumberOfValue(void* hkey) {
  LPSTR className = null;
  DWORD classNameSize = MAX_PATH;
  DWORD subKey = 0;
  DWORD maxSubKey;
  DWORD maxClass;
  DWORD value;
  DWORD maxValue;
  DWORD maxValueData;
  DWORD securityDescriptor;
  FILETIME ftLastWriteTime;
  
  if (RegQueryInfoKeyA((HKEY)hkey, className, &classNameSize, null, &subKey, &maxSubKey, &maxClass, &value, &maxValue, &maxValueData, &securityDescriptor, &ftLastWriteTime) == 0)
    return value;
  return -1;
}

int32  __OS::CoreApi::Registry::QueryInfoKey(void* hkey, int32& subKey, int32& value) {
  int32 rcl;
  LPSTR className = null;
  DWORD classNameSize = MAX_PATH;
  DWORD subKeyResultQuery = 0;
  DWORD maxSubKey;
  DWORD maxClass;
  DWORD valueResultQuery;
  DWORD maxValue;
  DWORD maxValueData;
  DWORD securityDescriptor;
  FILETIME ftLastWriteTime;
  
  rcl = RegQueryInfoKeyA((HKEY)hkey, className, &classNameSize, null,  &subKeyResultQuery, &maxSubKey, &maxClass, &valueResultQuery, &maxValue, &maxValueData, &securityDescriptor, &ftLastWriteTime);
  if (rcl == 0) {
    subKey = subKeyResultQuery;
    value = valueResultQuery;
  }
  return rcl;
}

int32  __OS::CoreApi::Registry::EnumKey(void* hkey, int32 dwIndex, char *subkeyname, int32& sizesubkey) {
  int32 rcl;
  DWORD si;
  rcl = RegEnumKeyExA((HKEY)hkey, dwIndex, subkeyname, &si, null, null, null, null);
  if (rcl == 0) {
    sizesubkey = si;
  } else if (rcl == ERROR_NO_MORE_ITEMS)
    rcl = 1;
  
  return rcl;
}

/*
 char  avaluenamey[256];//le nom de la cl�
 BYTE val[256];//la valeur de la cl�
 DWORD  pcf_typeofvalue
 */
int32  __OS::CoreApi::Registry::EnumValues(void* hkey, int32 dwIndex, char *avaluename, char* val, int32 & pcf_typeofvalue, int32& sizekey, int32& sizeval) {
  int32 rcl = 0;
  int32 si = sizekey, cbData = sizeval;
  
  rcl = RegEnumValueA((HKEY)hkey, dwIndex, avaluename, (LPDWORD)&si, null, (LPDWORD)&pcf_typeofvalue, (LPBYTE)val, (LPDWORD)&cbData);
  if (rcl == ERROR_SUCCESS) {
    sizekey = si;
    sizeval = cbData;
    rcl = 0;
  } else if (rcl == ERROR_MORE_DATA) {
    sizekey = si;
    sizeval = cbData;
    rcl = 2;
  } else if (rcl == ERROR_NO_MORE_ITEMS)
    rcl = 1;
  else {
    rcl = rcl;
  }
  
  return rcl;
}

int32 __OS::CoreApi::Registry::CloseKey(void* hKey) {
  int32 returnCode = RegCloseKey((HKEY)hKey);
  
  if (returnCode != ERROR_SUCCESS)
    return -1;
  
  //if error, do something;
  return 0;
}

int32 __OS::CoreApi::Registry::DeleteValue(void* hKey, const char* subkeyName) {
  int32 returnCode = RegDeleteValueA((HKEY)hKey, subkeyName);
  
  if (returnCode != ERROR_SUCCESS)
    return -1;
  
  //if error, do something;
  return 0;
}

int32 __OS::CoreApi::Registry::SetValue(void* hKey, const char* keyName, int32 type, byte* bData, int32 cbData) {
  long long tmpll = 1000;
  int32 returnCode = -1;
  if (type == 11) {
    tmpll = *(long long*)bData;
    //returnCode = RegSetValueExA((HKEY)hKey, keyName, 0, type, (const BYTE*)&tmpll/*bData*/, cbData);
    returnCode = RegSetValueExA((HKEY)hKey, keyName, 0, type, (const BYTE*)bData, cbData);
  } else
    returnCode = RegSetValueExA((HKEY)hKey, keyName, 0, type, (const BYTE*)bData, cbData);
  
  if (returnCode != ERROR_SUCCESS)
    return -1;
  
  return 0;
}

int32 __OS::CoreApi::Registry::Flush(void* hKey) {
  int returnCode = RegFlushKey((HKEY)hKey);
  return returnCode == ERROR_SUCCESS ? 0 : -1;
}

int32 __OS::CoreApi::Registry::DeleteTree(void* hKey, const char* subkeyName) {
  return RegDeleteTreeA((HKEY)hKey, subkeyName);
}

int32  __OS::CoreApi::Registry::DeleteSubKey(void* hKey, const char* subkeyName) {
  return RegDeleteKeyExA((HKEY)hKey, subkeyName, 0x0100, 0);
}

int32 __OS::CoreApi::Registry::OpenSubKey(const void* hrootKey, const char* subKey, void** hkey) {
  int32 returnCode = 0;
  HKEY thenewkey;
  REGSAM samDesired = KEY_ALL_ACCESS | KEY_CREATE_SUB_KEY;
  
  returnCode = RegOpenKeyExA((HKEY)hrootKey, subKey, 0, samDesired, (PHKEY)&thenewkey);
  *hkey = thenewkey;
  
  if (returnCode == ERROR_SUCCESS)
    return 0;
  
  //if error, do something;
  
  return -2;
}

int32 __OS::CoreApi::Registry::GetHandleBaseKey(int32 reghive, void** hkey) {
  HKEY rootKey;
  switch (reghive) {
    case 0: rootKey = HKEY_CLASSES_ROOT; break;
    case 1: rootKey = HKEY_CURRENT_CONFIG; break;
    case 2: rootKey = HKEY_CURRENT_USER; break;
    case 3: rootKey = HKEY_DYN_DATA; break;
    case 4: rootKey = HKEY_LOCAL_MACHINE; break;
    case 5: rootKey = HKEY_PERFORMANCE_DATA; break;
    case 6: rootKey = HKEY_USERS; break;
    default:
      rootKey = 0;
      break;
  }
  *hkey = rootKey;
  return 0;
}

int32 __OS::CoreApi::Registry::CreateSubKey(const char* rootKeystr, const char* subKey, void** hkey) {
  int32 returnCode = 0;
  HKEY rootKey = HKEY_CURRENT_USER;
  uint32 resdword = 0;
  HKEY thenewkey;
  
  if (subKey == null)
    return -2;
  
  if (strncmp(rootKeystr, "HKEY_CURRENT_USER", strlen("HKEY_CURRENT_USER")) != 0 && strncmp(rootKeystr, "HKEY_CLASSES_ROOT", strlen("HKEY_CLASSES_ROOT")) != 0 && strncmp(rootKeystr, "HKEY_LOCAL_MACHINE", strlen("HKEY_LOCAL_MACHINE")) != 0 && strncmp(rootKeystr, "HKEY_USERS", strlen("HKEY_USERS")) != 0 && strncmp(rootKeystr, "HKEY_CURRENT_CONFIG", strlen("HKEY_CURRENT_CONFIG")) != 0 && strncmp(rootKeystr, "HKEY_DYN_DATA", strlen("HKEY_DYN_DATA")) != 0)
    return -1;
  
  if (strncmp(rootKeystr, "HKEY_CURRENT_USER", strlen("HKEY_CURRENT_USER")) == 0)
    rootKey = HKEY_CURRENT_USER;
  if (strncmp(rootKeystr, "HKEY_CLASSES_ROOT", strlen("HKEY_CLASSES_ROOT")) == 0)
    rootKey = HKEY_CLASSES_ROOT;
  if (strncmp(rootKeystr, "HKEY_LOCAL_MACHINE", strlen("HKEY_LOCAL_MACHINE")) == 0)
    rootKey = HKEY_LOCAL_MACHINE;
  if (strncmp(rootKeystr, "HKEY_USERS", strlen("HKEY_USERS")) == 0)
    rootKey = HKEY_USERS;
  if (strncmp(rootKeystr, "HKEY_CURRENT_CONFIG", strlen("HKEY_CURRENT_CONFIG")) == 0)
    rootKey = HKEY_CURRENT_CONFIG;
  if (strncmp(rootKeystr, "HKEY_DYN_DATA", strlen("HKEY_DYN_DATA")) == 0)
    rootKey = HKEY_DYN_DATA;
  
  returnCode = RegCreateKeyExA(rootKey, subKey, 0, null, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS | KEY_CREATE_SUB_KEY, null, (PHKEY)&thenewkey, (DWORD*)&resdword);
  *hkey = thenewkey;
  
  if (returnCode == ERROR_SUCCESS)
    return 0;
  
  //if error, do something;
  return -2;
}

int32 __OS::CoreApi::Registry::CreateSubKey(const void* hrootKey, const char* subKey, void** hkey) {
  int32 returnCode = 0;
  uint32 resdword = 0;
  HKEY thenewkey;
  
  if (subKey == null)
    return -2;
  
  if (hrootKey == null)
    return -1;
  
  returnCode = RegCreateKeyExA((HKEY)hrootKey, subKey, 0, null, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS | KEY_CREATE_SUB_KEY, null, (PHKEY)&thenewkey, (DWORD*)&resdword);
  *hkey = thenewkey;
  
  if (returnCode == ERROR_SUCCESS)
    return 0;
  
  //if error, do something;
  return -2;
}

#endif
