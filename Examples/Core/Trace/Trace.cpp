// Specify add_definitions(-DTRACE) in the CMakeLists.txt file or add "#define TRACE 1" to the top of your file.
#define TRACE 1

#include <Switch/Switch>

using namespace System;
using namespace System::Diagnostics;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Trace::Listeners().Add(TextWriterTraceListener(Console::Out()));
      Trace::AutoFlush = true;
      Trace::Indent();
      Trace::WriteLine("Entering Main");
      Console::WriteLine("Hello World.");
      Trace::WriteLine("Exiting Main");
      Trace::Unindent();
    }
  };
}

startup (Examples::Program)

// The example displays the following output if TRACE is defined:
//
//     Entering Main
// Hello World
//     Exiting Main
