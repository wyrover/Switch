#include <Pcf/TUnit/UnitTest.h>
#include <Pcf/Startup.h>

namespace {
  class MainTest {
  public:
    static int Main(const System::Array<string>& args) {
      System::Exception::StackTraceEnabled(false);
      return TUnit::UnitTest(args).Run();
    }
  };
}

pcf_startup (MainTest)
