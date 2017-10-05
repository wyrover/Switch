#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/TUnit/Expect.hpp>
#include <Switch/TUnit/UnitTest.hpp>

using namespace System;

namespace Examples {
  
  class Program : public TUnit::TestFixture {
  public:
    void MyTest() {
      TUnit::Expect::IsTrue(false);
    }
    
    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      TUnit::UnitTest(args).Run();
    }
  };
  
  _test(Program, MyTest)
}

_startup (Examples::Program)
