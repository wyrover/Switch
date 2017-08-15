#include <Pcf/Pcf>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> args = Environment::GetCommandLineArgs();
      if (args.Length == 1) {
        Environment::ExitCode = ECANCELED;
      } else {
        int64 value = 0;
        if (Int64::TryParse(args[1], value))
          if (value <= Int32::MinValue || value >= Int32::MaxValue)
            Environment::ExitCode = ERANGE;
          else
            Console::WriteLine("Result: {0}", value * 2);
        else
          Environment::ExitCode = EINVAL;
      }
    }
  };
}

pcf_startup (Examples::Program)

