#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static int Main() {
      Array<string> args = Environment::GetCommandLineArgs();
      if (args.Length == 1) {
        return ECANCELED;
      } else {
        int64 value = 0;
        if (Int64::TryParse(args[1], value))
          if (value <= Int32::MinValue || value >= Int32::MaxValue)
            return ERANGE;
          else
            Console::WriteLine("Result: {0}", value * 2);
        else
          return EINVAL;
      }
      return 0;
    }
  };
}

pcf_startup (Examples::Program)

