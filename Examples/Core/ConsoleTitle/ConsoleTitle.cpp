#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("The current console title is: \"{0}\"", Console::Title);
      Console::WriteLine("  (Press any key to change the console title.)");
      Console::ReadKey(true);
      Console::Title = "The title has changed!";
      Console::WriteLine("Note that the new console title is \"{0}\"\n"
                         "  (Press any key to quit.)", Console::Title);
      Console::ReadKey(true);
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// The current console title is: "Command Prompt - ConsoleTitle"
// (Press any key to change the console title.)
// Note that the new console title is "The title has changed!"
// (Press any key to quit.)
