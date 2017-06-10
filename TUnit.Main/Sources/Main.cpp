#include <Pcf/TUnit/UnitTest.hpp>
#include <Pcf/Startup.hpp>

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
