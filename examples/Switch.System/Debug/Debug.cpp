// Specify add_definitions(-DDEBUG) in the CMakeLists.txt file or add "#define DEBUG 1" to the top of your file.
#define DEBUG 1

#include <Switch/Switch>

using namespace System;
using namespace System::Diagnostics;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Debug::Listeners().Add(TextWriterTraceListener(Console::Out()));
      Debug::AutoFlush = true;
      Debug::Indent();
      Debug::WriteLine("Entering Main");
      Console::WriteLine("Hello World.");
      Debug::WriteLine("Exiting Main");
      Debug::Unindent();
    }
  };
}

_startup(Examples::Program)

// The example displays the following output if DEBUG is defined:
//
//     Entering Main
// Hello World
//     Exiting Main
