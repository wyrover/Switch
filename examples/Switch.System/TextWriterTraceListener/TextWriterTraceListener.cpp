#include <Switch/Switch>

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    static int Main() {
      // Create a file for output named TestFile.txt.
      FileStream myFile = File::Create("TestFile.txt");

      // Create a new text writer using the output stream, and add it to the trace listeners.
      TextWriterTraceListener myTextListener(myFile);
      Trace::Listeners().Add(myTextListener);

      // Write output to the file.
      Trace::Write("Test output ");

      // Flush the output.
      Trace::Flush();

      return 0;
    }
  };
}

_startup(Examples::Program);
