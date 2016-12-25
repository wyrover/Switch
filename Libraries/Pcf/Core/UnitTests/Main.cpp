#include <Pcf/Pcf>
#include <Pcf/TUnit/UnitTest.h>

using namespace System;

namespace UnitTests {
  class MainClass {
  public:
    /// @brief The main entry point for the application.
    static int Main(const Array<string>& args) {
      System::Exception::StackTraceEnabled(false);
      return TUnit::UnitTest(args).Run();
    }
  };
}

pcf_startup (UnitTests::MainClass)
