#include <Switch/TUnit/UnitTest.hpp>
#include <Switch/Startup.hpp>

namespace {
  class MainTest {
  public:
    static int Main(const System::Array<string>& args) {
      System::Exception::StackTraceEnabled(false);
      return TUnit::UnitTest(args).Run();
    }
  };
}

startup (MainTest)
