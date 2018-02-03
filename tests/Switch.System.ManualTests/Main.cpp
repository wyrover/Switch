#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Environment.hpp>
#include <Switch/System/Diagnostics/TextWriterTraceListener.hpp>
#include <Switch/System/Diagnostics/Trace.hpp>
#include <Switch/System/IO/Directory.hpp>

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Trace::Listeners().Add(TextWriterTraceListener(Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Desktop), "User.log")));

      Trace::WriteLine("This is the first line");
      Trace::Flush();
    }
  };
}

startup_(ManualTests::Program);
