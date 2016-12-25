#pragma once

#include "../../../Includes/Pcf/Types.h"

/// @cond
namespace Pcf {
  namespace Os {
    /// @brief Represents a Os object that provides the access random API.
    /// This class cannot be inherited.
    /// Internal used only.
    class Registry final {
    public:
      static int32 CloseKey(void* hKey);
      static int32 CreateSubKey(const char* rootKey, const char* subKey, void** hkey);
      static int32 CreateSubKey(const void* hrootKey, const char* subKey, void** hkey);
      static int32 OpenSubKey(const void* hrootKey, const char* subKey, void** hkey);
      static int32 GetValue(void* hkey,const char* subKey,int32 &type, void* data, int32* cbData);
      static int32 SetValue(void *hKey,const char* keyName, int32 type, byte* data, int32 cbData);
      static int32 Flush(void* hKey);
      static int32 DeleteTree(void* hKey,const char* subkeyName);
      static int32 DeleteSubKey(void* hKey,const char* subkeyName);
      static int32 DeleteValue(void* hKey, const char* subkeyName);
      static int32 ExpandString(const char *strtoexpand, char *result,int32 cbData);
      static int32 EnumValues(void* hkey, int32 dwIndex,char *avaluenamey,char* val, int32 &typeofvalue,int32& sizekey,int32& sizeval);
      static int32 EnumKey(void* hKey, int32 dwIndex,char *subkeyname,int32& sizesubkey);
      static int32 NumberOfSubKey(void* hkey);
      static int32 NumberOfValue(void* hkey);
      static int32 QueryInfoKey(void* hkey, int32& subKey, int32& value);
      static int32 GetHandleBaseKey(int32 reghive, void** hkey);
      static const char *GetDefaultString();

    private:
      Registry() = delete;
    };
  }
}

using namespace Pcf;
/// @endcond
