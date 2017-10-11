#include <Switch/TUnit/UnitTest.hpp>
#include <Switch/Startup.hpp>

namespace {
  class MainTest {
  public:
    static int Main(const System::Array<string>& args) {
      return TUnit::UnitTest(args).Run();
    }
  };
}

_startup (MainTest)
