#include <Switch/TUnit/UnitTest.hpp>
#include <Switch/Startup.hpp>
#include "../include/Switch/TUnitMainExport.hpp"

namespace {
  class MainTest {
  public:
    static int Main(const System::Array<string>& args) {
      return TUnit::UnitTest(args).Run();
    }
  };
}

tunit_main_export_ startup_(MainTest);
