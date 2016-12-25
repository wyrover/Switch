#include <Pcf/Pcf>

using namespace System;

namespace SystemInformation {
  enum class CompilatorID {
    Unknown = -1,
    MicrosoftVisualStudio = 0,
    Gcc = 1,
    Clang = 2,
  };
  
  enum class CompilatorMode {
    Release = 0,
    Debug = 1,
  };
  
  enum class LibcID {
    Unknown = -1,
    Cpp98 = 0,
    Cpp11 = 1,
    Cpp14 = 2,
  };
}

template<>
class EnumToStrings<SystemInformation::CompilatorID> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SystemInformation::CompilatorID::Unknown, "Unknown"}, {(int64)SystemInformation::CompilatorID::MicrosoftVisualStudio, "MicrosoftVisualStudio"}, {(int64)SystemInformation::CompilatorID::Gcc, "Gcc"}, {(int64)SystemInformation::CompilatorID::Clang, "Clang"}};
    flags = false;
  }
};

template<>
class EnumToStrings<SystemInformation::CompilatorMode> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SystemInformation::CompilatorMode::Release, "Release"}, {(int64)SystemInformation::CompilatorMode::Debug, "Debug"}};
    flags = false;
  }
};

template<>
class EnumToStrings<SystemInformation::LibcID> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SystemInformation::LibcID::Unknown, "Unknown"}, {(int64)SystemInformation::LibcID::Cpp98, "Cpp98"}, {(int64)SystemInformation::LibcID::Cpp11, "Cpp11"}, {(int64)SystemInformation::LibcID::Cpp14, "Cpp14"}};
    flags = false;
  }
};

namespace SystemInformation {
  class OperatingSystemInfo : public object {
  public:
    static string Name() {
      switch (ID()) {
        case PlatformID::Win32S: return "Microsoft Win32S "; break;
        case PlatformID::Win32Windows: return "Microsoft Windows 98 "; break;
        case PlatformID::Win32NT: return "Microsoft Windows NT "; break;
        case PlatformID::WinCE: return "Microsoft Windows CE "; break;
        case PlatformID::Unix: return "Unix "; break;
        case PlatformID::Xbox: return "Xbox "; break;
        case PlatformID::MacOSX: return "Mac OS X "; break;
        case PlatformID::IOs: return "iOS "; break;
        case PlatformID::Android:return "Android "; break;
        case PlatformID::Unknown: return "<Unknown> "; break;
      }
      return "<Unknown>";
    }
    
    static Pcf::System::Version Version() { return Environment::OSVersion().Version(); }
    
    static PlatformID ID() { return Environment::OSVersion().Platform(); }
    
    static OperatingSystem OSVersion() { return Environment::OSVersion(); }
    
    static bool Is32Bits() { return !Environment::Is64BitOperatingSystem(); }
    
    static bool Is64Bits() { return Environment::Is64BitOperatingSystem(); }
    
  private:
    OperatingSystemInfo() {}
  };
  
  class LibcInfo : public object {
  public:
    static string Name() {
      switch (ID()) {
        case LibcID::Cpp98: return "Lib C++ 98";
        case LibcID::Cpp11: return "Lib C++ 11";
        case LibcID::Cpp14: return "Lib C++ 14";
        case LibcID::Unknown: return "<unknown>";
      }
      return "<Unknown>";
    }
    
    static const System::Version& Version() {
      static System::Version ver(__cplusplus/100, __cplusplus%100);
      return ver;
    }
    
    static LibcID ID() {
      int cpp = __cplusplus;
      if (cpp >= 201402L)
        return LibcID::Cpp14;
      
      if (cpp >= 201103L)
        return LibcID::Cpp11;
      
      if (cpp >= 199711L)
        return LibcID::Cpp98;
      
      return LibcID::Unknown;
    }
    
    static bool IsCppSupported() { return ID() == LibcID::Cpp98 || ID() == LibcID::Cpp11 || ID() == LibcID::Cpp14; }
    
    static int GetYear() { return __cplusplus / 100; }
    
    static int GetMonth() { return __cplusplus % 100; }
    
  private:
    LibcInfo() {}
  };
  
  class CompilatorInfo : public object {
  public:
    static string Name() {
      switch (ID()) {
        case CompilatorID::MicrosoftVisualStudio: return "Microsoft Visual Studio";
        case CompilatorID::Gcc: return "gcc";
        case CompilatorID::Clang: return "clang";
        case CompilatorID::Unknown: return "<Unknown>";
        default: return "<Unknown>";
          
      }
    }
    
#if __clang__
    static System::Version Version() {return System::Version(__clang_major__ , __clang_minor__, __clang_patchlevel__);}
#elif __GNUC__
    static System::Version Version() {return System::Version(__GNUC__ , __GNUC_MINOR__, __GNUC_PATCHLEVEL__);}
#elif _MSC_VER
    static System::Version Version() {return System::Version(_MSC_VER/100, _MSC_VER%100, 0);}
#else
    static System::Version Version() {return System::Version(0, 0, 0);}
#endif
    
#if __clang__
    static CompilatorID ID() {return CompilatorID::Clang;}
#elif __GNUC__
    static CompilatorID ID() {return CompilatorID::Gcc;}
#elif _MSC_VER
    static CompilatorID ID() {return CompilatorID::MicrosoftVisualStudio;}
#else
    static CompilatorID ID() {return CompilatorID::Unknown;}
#endif
    
#if DEBUG
    static CompilatorMode Mode() {return CompilatorMode::Debug;}
#else
    static CompilatorMode Mode() {return CompilatorMode::Release;}
#endif
    
    static bool IsDebugMode() { return Mode() == CompilatorMode::Debug; }
    
    static bool IsReleaseMode() { return Mode() == CompilatorMode::Release; }
    
    static bool Is32Bits() { return !Environment::Is64BitProcess(); }
    
    static bool Is64Bits() { return Environment::Is64BitProcess(); }
    
  private:
    CompilatorInfo() {}
  };
}

int main(int argc, char* argv[]) {
  Console::WriteLine("System Information");
  Console::WriteLine("------------------");
  Console::WriteLine(" - Operating System");
  Console::WriteLine("   * Name : {0}", SystemInformation::OperatingSystemInfo::Name());
  Console::WriteLine("   * Version : {0}", SystemInformation::OperatingSystemInfo::Version());
  Console::WriteLine("   * ID : {0}", SystemInformation::OperatingSystemInfo::ID());
  Console::WriteLine("   * OS Version : {0}", SystemInformation::OperatingSystemInfo::OSVersion());
  Console::WriteLine("   * Is 64 bits : {0}", SystemInformation::OperatingSystemInfo::Is64Bits());
  Console::WriteLine(" - Lib c");
  Console::WriteLine("   * Name : {0}", SystemInformation::LibcInfo::Name());
  Console::WriteLine("   * Version : {0}", SystemInformation::LibcInfo::Version());
  Console::WriteLine("   * ID : {0}", SystemInformation::LibcInfo::ID());
  Console::WriteLine("   * Is supported : {0}", SystemInformation::LibcInfo::IsCppSupported());
  Console::WriteLine(" - Compilator");
  Console::WriteLine("   * Name : {0}", SystemInformation::CompilatorInfo::Name());
  Console::WriteLine("   * Version : {0}", SystemInformation::CompilatorInfo::Version());
  Console::WriteLine("   * ID : {0}", SystemInformation::CompilatorInfo::ID());
  Console::WriteLine("   * Mode : {0}", SystemInformation::CompilatorInfo::Mode());
  Console::WriteLine("   * Is 64 bits : {0}", SystemInformation::CompilatorInfo::Is64Bits());
}

// This code produces the following output if your are on Mac Os X:
//
// System Information
// ------------------
//  - Operating System
//    * Name : Mac OS X
//    * Version : 10.9.80996
//    * ID : MacOSX
//    * OS Version : Mac OS X 10.9.80996
//    * Is 64 bits : True
//  - Lib c
//    * Name : Lib C++ 11
//    * Version : 2011.3
//    * ID : Cpp11
//    * Is supported : True
//  - Compilator
//    * Name : clang
//    * Version : 4.2.1
//    * ID : Clang
//    * Mode : Release
//    * Is 64 bits : True
