#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/TUnit/Expect.hpp>
#include <Switch/TUnit/UnitTest.hpp>

using namespace System;

namespace Examples {
  struct TestFixture1 : public TUnit::TestFixture {
    void Test1() {
      TUnit::Expect::True(true);
    }
  };
  
  _add_test (TestFixture1, Test1)
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      TUnit::UnitTest(args).Run();
    }
  };
}

_startup (Examples::Program)
