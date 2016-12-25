#include <Pcf/Pcf>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Path::AltDirectorySeparatorChar()='{0}'", Path::AltDirectorySeparatorChar);
      Console::WriteLine("Path::DirectorySeparatorChar()='{0}'", Path::DirectorySeparatorChar);
      Console::WriteLine("Path::PathSeparator()='{0}'", Path::PathSeparator);
      Console::WriteLine("Path::VolumeSeparatorChar()='{0}'", Path::VolumeSeparatorChar);
      
      Console::Write("Path::GetInvalidPathChars()=");
      for (char32 c : Path::GetInvalidPathChars())
        Console::Write(c);
      Console::WriteLine();
    }
  };
}

pcf_startup (Examples::Program)

// This code produces output similar to the following:
//
// Note that the InvalidPathCharacters contain characters
// outside of the printable character set.
//
// Path::AltDirectorySeparatorChar()='/'
// Path::DirectorySeparatorChar()='\'
// Path::PathSeparator()=';'
// Path::VolumeSeparatorChar()=':'
