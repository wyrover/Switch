#pragma once

#include "../../Includes/Switch/Microsoft/Win32/RegistryHive.hpp"
#include "../../Includes/Switch/Microsoft/Win32/RegistryKey.hpp"
#include "../../Includes/Switch/Microsoft/Win32/RegistryValueKind.hpp"
#include "../../Includes/Switch/System/Collections/Generic/SortedDictionary.hpp"
#include "../../Includes/Switch/System/Diagnostics/ProcessStartInfo.hpp"
#include "../../Includes/Switch/System/IO/DriveType.hpp"
#include "../../Includes/Switch/System/IO/FileAttributes.hpp"
#include "../../Includes/Switch/System/Net/Sockets/AddressFamily.hpp"
#include "../../Includes/Switch/System/Net/Sockets/ProtocolType.hpp"
#include "../../Includes/Switch/System/Net/Sockets/SocketOptionName.hpp"
#include "../../Includes/Switch/System/Net/Sockets/SocketOptionLevel.hpp"
#include "../../Includes/Switch/System/Net/Sockets/SocketType.hpp"
#include "../../Includes/Switch/System/Net/IPAddress.hpp"
#include "../../Includes/Switch/System/Security/SecureString.hpp"
#include "../../Includes/Switch/System/Array.hpp"
#include "../../Includes/Switch/System/ConsoleColor.hpp"
#include "../../Includes/Switch/System/ConsoleSpecialKey.hpp"
#include "../../Includes/Switch/System/Environment.hpp"
#include "../../Includes/Switch/System/Guid.hpp"
#include "../../Includes/Switch/System/PlatformID.hpp"
#include "../../Includes/Switch/System/String.hpp"
#include "../../Includes/Switch/Static.hpp"
#include "../../Includes/Switch/Types.hpp"

namespace __OS {
  class CoreApi _static {
  public:
    class Console _static {
    public:
      static void Beep(int32 freq, int32 dur);
      static void Clrscr();
      static System::ConsoleColor GetBackgroundColor();
      static int32 GetBufferHeight();
      static int32 GetBufferWidth();
      static bool GetCapsLock();
      static int32 GetCursorLeft();
      static int32 GetCursorSize();
      static int32 GetCursorTop();
      static bool GetCursorVisible();
      static System::ConsoleColor GetForegroundColor();
      static System::Collections::Generic::SortedDictionary<int32, System::ConsoleSpecialKey> GetSignalKeys();
      static int32 GetInputCodePage();
      static int32 GetLargestWindowHeight();
      static int32 GetLargestWindowWidth();
      static bool GetNumberLock();
      static int32 GetOutputCodePage();
      static string GetTitle();
      static int32 GetWindowLeft();
      static int32 GetWindowHeight();
      static int32 GetWindowTop();
      static int32 GetWindowWidth();
      static bool KeyAvailable();
      static void ReadKey(int32& keyChar, int32& keyCode, bool& alt, bool& shift, bool& ctrl);
      static bool ResetColor();
      static bool SetBackgroundColor(System::ConsoleColor color);
      static bool SetBufferHeight(int32 height);
      static bool SetBufferWidth(int32 width);
      static bool SetCursorLeft(int32 left);
      static bool SetCursorTop(int32 top);
      static void SetCursorSize(int32 size);
      static void SetCursorVisible(bool visible);
      static void SetEchoVisible(bool visible);
      static bool SetForegroundColor(System::ConsoleColor color);
      static bool SetInputCodePage(int32 codePage);
      static bool SetOutputCodePage(int32 codePage);
      static bool SetTitle(const string& title);
      static bool SetWindowHeight(int32 height);
      static bool SetWindowLeft(int32 left);
      static bool SetWindowTop(int32 top);
      static bool SetWindowWidth(int32 width);
    };

    struct DateTime _static {
    public:
      static int32 Ftime(int64& seconds, int32& milliseconds, int32& timeZone, bool& daylight);
      static int32 Gmtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek);
      static int32 Localtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek);
      static int64 Mkgmtime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second);
      static int64 Mktime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second);
      static int32 Strftime(string& output, const string& format, int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 dayOfYear, int32 dayOfWeek, bool daylight);
      static bool IsDaylight(int64 localTime);
    };
    
    struct Debugger _static {
    public:
      static void Log(int32 level, const string& category, const string& message);
    };

    class Directory _static {
    public:
      static char32 AltDirectorySeparatorChar();
      static char32 DirectorySeparatorChar();
      static System::Array<char32> InvalidPathChars();
      static char32 PathSeparator();
      static char32 VolumeSeparator();
      static System::Collections::Generic::Enumerator<string> EnumerateDirectories(const string& path, const string& pattern);
      static System::Collections::Generic::Enumerator<string> EnumerateFiles(const string& path, const string& pattern);
      static int32 GetFileAttributes(const string& path, System::IO::FileAttributes& attributes);
      static int32 GetFileTime(const string& path, int64& creationTime, int64& lastAccessTime, int64& lastWriteTime);
      static string GetFullPath(const string& relativePath);
      static string GetCurrentDirectory();
      static int32 SetCurrentDirectory(const string& directoryName);
      static int64 GetFileSize(const string& path);
      static int32 CreateDirectory(const string& directoryName);
      static int32 RemoveDirectory(const string& directoryName);
      static int32 RemoveFile(const string& file);
      static int32 RenameFile(const string& oldPath, const string& newPath);
      static string GetKnowFolderPath(System::Environment::SpecialFolder id);
      static string GetTempPath();
    };

    class Drive _static {
    public:
      static bool GetAvailableFreeSpace(const string& rootPathName, int64& freeBytes, int64& totalNumberOfBytes, int64& totalNumberOfFreeBytes);
      static System::IO::DriveType GetDriveType(const string& rootPathName);
      static System::Array<string> GetDrives();
      static bool GetVolumeInformation(const string& rootPathName, string& volumeName, string& fileSystemName);
      static bool SetVolumeLabel(const string& rootPathName, const string& volumeName);
    };
    
    class Dns _static {
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
    
    class Environment _static {
    public:
      static string NewLine();
      static System::PlatformID GetOsPlatformID();
      static int32 GetOsVersion(int32& major, int32& minor, int32& build, int32& revision);
      static bool IsOs64Bit();
      static string GetMachineName();
      static int32 GetTickCount();
      static string GetUserDomainName();
      static string GetUserName();
      static int64 GetWorkingSet();
      static int32 SetEnv(const string& name, const string& value);
      static int32 UnsetEnv(const string& name);
      static System::Guid NewGuid();
    };
    
    class Format _static {
    public:
      static const string& Integer();
      static const string& IntegerWithPrecision();
      static const string& UnsignedInteger();
      static const string& UnsignedIntegerWithPrecision();
      static const string& HexadecimalWithPrecision();
      static const string& LowerHexadecimalWithPrecision();
    };
    
    class Interlocked _static {
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
    
    class Process _static {
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
    
    class Registry _static {
    public:
      static int32 CloseKey(intptr key);
      static int32 CreateSubKey(intptr rootKey, const string& subKey, intptr& key);
      static int32 DeleteSubKey(intptr key, const string& subkeyName);
      static int32 DeleteTree(intptr key, const string& subkeyName);
      static int32 DeleteValue(intptr key, const string& subkeyName);
      static int32 EnumKey(intptr hKey, int32 index, string& subkeyname);
      static int32 EnumValues(intptr key, int32 index, string& keyName, Microsoft::Win32::RegistryValueKind& kind);
      static int32 Flush(intptr hKey);
      static string GetDefaultString();
      static int32 GetHandleBaseKey(Microsoft::Win32::RegistryHive rhive, intptr& key);
      static int32 GetValue(intptr key, const string& subKey, Microsoft::Win32::RegistryValueKind& type, System::Array<byte>& data);
      static int32 NumberOfSubKey(intptr hkey);
      static int32 NumberOfValue(intptr hkey);
      static int32 OpenSubKey(intptr hrootKey, const string& subKey, intptr& hkey);
      static int32 QueryInfoKey(intptr hkey, int32& subKey, int32& value);
      static int32 SetValue(intptr key, const string& keyName, Microsoft::Win32::RegistryValueKind type, const byte* data, int32 length);
    };

    class Security _static {
    public:
      static System::Security::SecureString ToSecureSecureString(const string& unsecureString);
      static string ToSecureString(const string& unsecureString);
      static string ToUnsecureString(const System::Security::SecureString& secureString);
      static string ToUnsecureString(const string& secureString);
    };
    
    class Socket _static {
    public:
      static int32 AddressFamilyToNative(System::Net::Sockets::AddressFamily addressFamily);
      static System::Net::Sockets::AddressFamily NativeToAddressFamily(int32 addressFamily);
      static int32 Accept(intptr handle, byte* socketAddress, int32 addressLength, intptr* socket);
      static int32 Bind(intptr handle, byte* socketAddress, int32 addressLength);
      static int32 Close(intptr handle);
      static int32 Connect(intptr handle, byte* socketAddress, int32 addressLength);
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
      static int32 Send(intptr handle, byte* buffer, int32 bufferLength, int32 flags);
      static int32 SendTo(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength);
      static int32 SetBlocking(intptr handle, bool blocking);
      static int32 SetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32 optionLength);
      static int32 Receive(intptr handle, byte* buffer, int32 bufferLength, int32 flags);
      static int32 ReceiveFrom(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength);
      static int32 Shutdown(intptr handle, int32 how);
    };
    
    class Thread _static {
    public:
      static bool Cancel(intptr handle);
      static intptr GetCurrent();
      static void Resume(intptr handle);
      static void SetNameOfCurrentThread(const string& name);
      static bool SetPriority(intptr handle, int32 priority);
      static void Suspend(intptr handle);
    };
    
    class Type _static {
    public:
      static string Demangle(const string& name);
    };

    class UnicodeCharacters _static {
    public:
      static bool ValidateCodePoint(uint32 codePoint);
      static bool IsAlpha(uint32 codePoint);
      static bool IsDigit(uint32 codePoint);
      static bool IsPunctuation(uint32 codePoint);
    };

    class UnicodeEncodings _static {
    public:
      class ASCII _static {
      public:
      };

      class UTF8 _static {
      public:
        static byte GetFormat(byte b);
        static int32 GetNextCodeIndex(const std::string& str, int32 pos);
        static int32 GetPrevCodeIndex(const std::string& str, int32 pos);
        static uint32 GetCode(const byte* bytes, byte size);
        static uint32 GetLength(const std::string& str);
        static int32 GetLastIndex(const std::string& str);
        static int32 GetByteCount(uint32 code);
        static std::string Encode(uint32 code);
        static int32 Encode(uint32 code, byte bytes[]);
        static int32 Encode(uint32 code, std::string& utf8_encoding);
        static System::Array<byte> ToBytes(uint32 code);
      };

      class UTF16 _static {
      public:
        static int32 GetByteCount(uint32 code);
        static int32 Encode(uint32 code, byte bytes[], bool big_endian);
        static int32 Decode(const byte* bytes, uint32 bytes_size, bool big_endian, uint32& code_point);
        static int32 GetLength(const byte* bytes, uint32 nb_bytes, bool big_endian);
      };

      class UTF32 _static {
      public:
        static void Encode(uint32 code, byte& b1, byte& b2, byte& b3, byte& b4, bool big_endian);
        static uint32 Decode(byte b1, byte b2, byte b3, byte b4, bool big_endian);
      };

      static bool IsDigit(uint32 c);
      static bool IsAlpha(uint32 c);
      static bool IsPunctuation(uint32 c);
      static uint32 ToLower(uint32 c);
      static uint32 ToUpper(uint32 c);
      static uint32 ToTitle(uint32 c);
    };
  };
}
