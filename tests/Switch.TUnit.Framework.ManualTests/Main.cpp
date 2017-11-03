#include <Switch/Switch.TUnit.Framework>

using namespace System;

namespace UnitTets {
  class _test_fixture(Test) {
    void _one_time_set_up(OneTimeInit)() {
    }
    
    void _one_time_tear_down(OneTimeCleanup)() {
    }
    
    void _set_up(Init)() {
    }
    
    void _tear_down(Cleanup)() {
    }
    
    void _test(TestCase1)() {
    }
    
    void _test(TestCase2)() {
    }
    
    void _ignore_test(TestCase3)() {
    }
  };
  
  _add_test_fixture(Test)

  namespace Other {
    class _test_fixture(Test2) {
      void _test(TestCase1)() {
      }
      
      void _test(TestCase2)() {
      }

      void _test(TestCase3)() {
      }

      void _test(TestCase4)() {
      }
    };
    
    _add_test_fixture(Test2)
  }
  
  class Program {
  public:
    static void Main(const Array<string>& args) {
      TUnit::Framework::UnitTest(args).Run();
    }
  };
}

_startup(UnitTets::Program)

