#pragma once

#include "../../Includes/Pcf/System/Collections/Generic/SortedDictionary.h"
#include "../../Includes/Pcf/System/Diagnostics/ProcessStartInfo.h"
#include "../../Includes/Pcf/System/IO/DriveType.h"
#include "../../Includes/Pcf/System/IO/FileAttributes.h"
#include "../../Includes/Pcf/System/Net/Sockets/AddressFamily.h"
#include "../../Includes/Pcf/System/Net/Sockets/ProtocolType.h"
#include "../../Includes/Pcf/System/Net/Sockets/SocketOptionName.h"
#include "../../Includes/Pcf/System/Net/Sockets/SocketOptionLevel.h"
#include "../../Includes/Pcf/System/Net/Sockets/SocketType.h"
#include "../../Includes/Pcf/System/Net/IPAddress.h"
#include "../../Includes/Pcf/System/Security/SecureString.h"
#include "../../Includes/Pcf/System/Array.h"
#include "../../Includes/Pcf/System/ConsoleSpecialKey.h"
#include "../../Includes/Pcf/System/Environment.h"
#include "../../Includes/Pcf/System/PlatformID.h"
#include "../../Includes/Pcf/System/String.h"
#include "../../Includes/Pcf/Static.h"
#include "../../Includes/Pcf/Types.h"

namespace __OS {
  class CoreApi pcf_static {
  public:
    class Console pcf_static {
    public:
      static void Beep(int32 freq, int32 dur);
      static void Clrscr();
      static int32 GetBackgroundColor();
      static int32 GetCursorSize();
      static bool GetCursorVisible();
      static int32 GetForegroundColor();
      static System::Collections::Generic::SortedDictionary<int32, System::ConsoleSpecialKey> GetSignalKeys();
      static void Gotoxy(int32 x, int32 y);
      static bool KeyAvailable();
      static void ReadKey(int32& keyChar, int32& keyCode, bool& alt, bool& shift, bool& ctrl);
      static void SetBackgroundColor(int32 color);
      static void SetCursorSize(int32 size);
      static void SetCursorVisible(bool visible);
      static void SetEchoVisible(bool visible);
      static void SetForegroundColor(int32 color);
      static void Wherexy(int32& x, int32& y);
      static void GetBufferSize(int32& w, int32& h);
      static int32 GetInputCodePage();
      static int32 GetOutputCodePage();
      static bool SetInputCodePage(int32 codePage);
      static bool SetOutputCodePage(int32 codePage);
    };

    struct DateTime pcf_static {
    public:
      static int32 Ftime(int64& seconds, int32& milliseconds, int32& timeZone, bool& daylight);
      static int32 Gmtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek);
      static int32 Localtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek);
      static int64 Mkgmtime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second);
      static int64 Mktime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second);
      static int32 Strftime(string& output, const string& format, int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 dayOfYear, int32 dayOfWeek, bool daylight);
      static bool IsDaylight(int64 localTime);
    };
    
    struct Debugger pcf_static {
    public:
      static void Log(int32 level, const string& category, const string& message);
    };

    class Directory pcf_static {
    public:
      static char32 AltDirectorySeparatorChar();
      static char32 DirectorySeparatorChar();
      static System::Array<char32> InvalidPathChars();
      static char32 PathSeparator();
      static char32 VolumeSeparator();
      static System::Collections::Generic::Enumerator<string> EnumerateDirectories(const string& path, const string& pattern);
      static System::Collections::Generic::Enumerator<string> EnumerateFiles(const string& path, const string& pattern);
      #undef GetFileAttributes
      static int32 GetFileAttributes(const string& path, System::IO::FileAttributes& attributes);
      static int32 GetFileTime(const string& path, int64& creationTime, int64& lastAccessTime, int64& lastWriteTime);
      static string GetFullPath(const string& relativePath);
      #undef GetCurrentDirectory
      static string GetCurrentDirectory();
      #undef SetCurrentDirectory
      static int32 SetCurrentDirectory(const string& directoryName);
      static int64 GetFileSize(const string& path);
      #undef CreateDirectory
      static int32 CreateDirectory(const string& directoryName);
      #undef RemoveDirectory
      static int32 RemoveDirectory(const string& directoryName);
      static int32 RemoveFile(const string& file);
      static int32 RenameFile(const string& oldPath, const string& newPath);
      static string GetKnowFolderPath(System::Environment::SpecialFolder id);
      #undef GetTempPath
      static string GetTempPath();
    };

    class Drive pcf_static {
    public:
      static bool GetAvailableFreeSpace(const string& rootPathName, int64& freeBytes, int64& totalNumberOfBytes, int64& totalNumberOfFreeBytes);
      #undef GetDriveType
      static System::IO::DriveType GetDriveType(const string& rootPathName);
      #undef GetLogicalDriveStrings
      static System::Array<string> GetDrives();
      #undef GetVolumeInformation
      static bool GetVolumeInformation(const string& rootPathName, string& volumeName, string& fileSystemName);
      #undef SetVolumeLabel
      static bool SetVolumeLabel(const string& rootPathName, const string& volumeName);
    };
    
    class Dns pcf_static {
    public:
      static void Destroy(intptr host);
      static void EndHostent();
      static intptr GetHostByAddress(const string& hostAddress, System::Net::Sockets::AddressFamily hostAddressType);
      static intptr GetHostByName(const string& hostName);
      static System::Array<string> GetAliases(intptr host);
      static System::Array<System::Net::IPAddress> GetAddresses(intptr host);
      static string GetHostName(intptr host);
      static int GetHostName(string& hostName);
      static void SetHostent(bool stayOpen);
    };
    
    class Environment pcf_static {
    public:
      static string NewLine();
      static System::PlatformID GetOsPlatformID();
      static int32 GetOsVersion(int32& major, int32& minor, int32& build, int32& revision);
      static bool IsOs64Bit();
      static string GetMachineName();
      static int32 GetTickCount();
      static string GetUserDomainName();
      static bool GetUserInteractive();
      #undef GetUserName
      static string GetUserName();
      static int64 GetWorkingSet();
      static int32 SetEnv(const string& name, const string& value);
      static int32 UnsetEnv(const string& name);
    };
    
    class Format pcf_static {
    public:
      static const string& Integer();
      static const string& IntegerWithPrecision();
      static const string& UnsignedInteger();
      static const string& UnsignedIntegerWithPrecision();
      static const string& HexadecimalWithPrecision();
      static const string& LowerHexadecimalWithPrecision();
    };
    
    class Interlocked pcf_static {
    public:
      static int32 Add(int32& location, int32 value);
      static int64 Add(int64& location, int64 value);
      static int32 CompareExchange(int32& location, int32 value, int32 comparand);
      static int64 CompareExchange(int64& location, int64 value, int64 comparand);
      static llong CompareExchange(llong& location, llong value, llong comparand);
      static void* CompareExchange(void*& location, void* value, void* comparand);
      static int32 Decrement(int32& location);
      static int64 Decrement(int64& location);
      static int32 Exchange(int32& location, int32 value);
      static int64 Exchange(int64& location, int64 value);
      static llong Exchange(llong& location, llong value);
      static void* Exchange(void*& location, void* value);
      static int32 Increment(int32& location);
      static int64 Increment(int64& location);
    };
    
    class Process pcf_static {
    public:
      static intptr Start(const System::Diagnostics::ProcessStartInfo& processStartInfo);
      static bool Close(intptr handle);
      static bool Kill(intptr handle);
      static intptr GetCurrent();
      static intptr GetParent();
      static string GetName(intptr handle);
      static string GetPath(intptr handle);
      static System::Array<intptr> GetProcesses();
      static void WaitForExit(intptr handle, int32& exitCode);
      static bool WaitForExit(intptr handle, int32 timeout, int32& exitCode);
    };
    
    class Registry pcf_static {
    public:
      static int32 CloseKey(void* hKey);
      static int32 CreateSubKey(const char* rootKey, const char* subKey, void** hkey);
      static int32 CreateSubKey(const void* hrootKey, const char* subKey, void** hkey);
      static int32 OpenSubKey(const void* hrootKey, const char* subKey, void** hkey);
      static int32 GetValue(void* hkey, const char* subKey, int32 &type, void* data, int32* cbData);
      static int32 SetValue(void *hKey, const char* keyName, int32 type, byte* data, int32 cbData);
      static int32 Flush(void* hKey);
      static int32 DeleteTree(void* hKey, const char* subkeyName);
      static int32 DeleteSubKey(void* hKey, const char* subkeyName);
      static int32 DeleteValue(void* hKey, const char* subkeyName);
      static int32 ExpandString(const char *strtoexpand, char *result, int32 cbData);
      static int32 EnumValues(void* hkey, int32 dwIndex, char *avaluenamey, char* val, int32 &typeofvalue, int32& sizekey, int32& sizeval);
      static int32 EnumKey(void* hKey, int32 dwIndex, char *subkeyname, int32& sizesubkey);
      static int32 NumberOfSubKey(void* hkey);
      static int32 NumberOfValue(void* hkey);
      static int32 QueryInfoKey(void* hkey, int32& subKey, int32& value);
      static int32 GetHandleBaseKey(int32 reghive, void** hkey);
      static const char *GetDefaultString();
    };

    class Security pcf_static {
    public:
      static System::Security::SecureString ToSecureSecureString(const string& unsecureString);
      static string ToSecureString(const string& unsecureString);
      static string ToUnsecureString(const System::Security::SecureString& secureString);
      static string ToUnsecureString(const string& secureString);
    };
    
    class Socket pcf_static {
    public:
      static int32 AddressFamilyToNative(System::Net::Sockets::AddressFamily addressFamily);
      static System::Net::Sockets::AddressFamily NativeToAddressFamily(int32 addressFamily);
      static int32 Accept(intptr handle, byte *socketAddress, int32 addressLength, intptr* socket);
      static int32 Bind(intptr handle, byte *socketAddress, int32 addressLength);
      static int32 Close(intptr handle);
      static int32 Connect(intptr handle, byte *socketAddress, int32 addressLength);
      static int32 GetLastError();
      static int32 GetAvailable(intptr handle, int32* nbrBytesAvailable);
      static int32 GetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32* optionLength);
      static bool GetOSSupportsIPv4();
      static bool GetOSSupportsIPv6();
      static int32 IoCtl(intptr handle, int32 ioControl, byte* optionInValue, int32 optionInValueSize, byte* optionOutValue, int32 optionOutValueSize, int32* optionOutValueSizeReturned);
      static int32 Listen(intptr handle, int32 backLog);
      static int32 Open(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType, intptr* socket);
      static int32 Poll(intptr handle, int32 microseconds, int32 mode);
      static int32 Select(intptr* checkRead, int32 nbCheckRead, intptr* checkWrite, int32 nbCheckWrite, intptr* checkError, int32 nbCheckError, int32 microseconds);
      static int32 Send(intptr handle, byte *buffer, int32 bufferLength, int32 flags);
      static int32 SendTo(intptr handle, byte *buffer, int32 bufferLength, int32 flags, byte *socketAddress, int32 addressLength);
      static int32 SetBlocking(intptr handle, bool blocking);
      static int32 SetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32 optionLength);
      static int32 Receive(intptr handle, byte* buffer, int32 bufferLength, int32 flags);
      static int32 ReceiveFrom(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte *socketAddress, int32 addressLength);
      static int32 Shutdown(intptr handle, int32 how);
    };
    
    class Thread pcf_static {
    public:
      static bool Cancel(intptr handle);
      static intptr GetCurrent();
      static void Resume(intptr handle);
      static void SetNameOfCurrentThread(const string& name);
      static bool SetPriority(intptr handle, int32 priority);
      static void Suspend(intptr handle);
    };
    
    class Type pcf_static {
    public:
      static string Demangle(const string& name);
    };

    class UnicodeCharacters pcf_static {
    public:
      static bool ValidateCodePoint(uint32 codePoint);
      static bool IsAlpha(uint32 codePoint);
      static bool IsDigit(uint32 codePoint);
      static bool IsPunctuation(uint32 codePoint);
    };

    class UnicodeEncodings pcf_static {
    public:
      class ASCII pcf_static {
      public:
      };

      class UTF8 pcf_static {
      public:
        static byte GetFormat(byte b);
        static int GetNextCodeIndex(const std::string& str, int32 pos);
        static int GetPrevCodeIndex(const std::string& str, int32 pos);
        static uint32 GetCode(const byte* bytes, byte size);
        static uint32 GetLength(const std::string& str);
        static int GetLastIndex(const std::string& str);
        static int GetByteCount(uint32 code);
        static std::string Encode(uint32 code);
        static int Encode(uint32 code, byte bytes[]);
        static int Encode(uint32 code, std::string& utf8_encoding);
      };

      class UTF16 pcf_static {
      public:
        static int GetByteCount(uint32 code);
        static int Encode(uint32 code, byte bytes[], bool big_endian);
        static int Decode(const byte* bytes, uint32 bytes_size, bool big_endian, uint32& code_point);
        static int GetLength(const byte* bytes, uint32 nb_bytes, bool big_endian);
      };

      class UTF32 pcf_static {
      public:
        static void Encode(uint32 code, byte& b1, byte& b2, byte& b3, byte& b4, bool big_endian);
        static uint32 Decode(byte b1, byte b2, byte b3, byte b4, bool big_endian);
      };

      static uint32 to_lower(uint32 c);
      static uint32 to_upper(uint32 c);
      static uint32 to_title(uint32 c);
    };
  };
}
