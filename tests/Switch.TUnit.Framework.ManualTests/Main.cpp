#include <Switch/Switch.TUnit.Framework>

#undef _ignore_test
#undef _set_up
#undef _tear_down
#undef _test
#undef _test_fixture
#undef _add_test
#undef _add_test_fixture

#define _one_time_set_up(methodName) \
methodName##_one_time_set_up_unused_method() {} \
struct methodName##_one_time_set_up { \
methodName##_one_time_set_up(Test_fixture_type* test) {test->oneTimeSetUps.Add({#methodName, {*test, &Test_fixture_type::methodName}});} \
} methodName##_one_time_set_up_value {this}; \
void methodName

#define _one_time_tear_down(methodName) \
methodName##_one_time_tear_down_unused_method() {} \
struct methodName##_one_time_tear_down { \
methodName##_one_time_tear_down(Test_fixture_type* test) {test->oneTimeTearDowns.Add({#methodName, {*test, &Test_fixture_type::methodName}});} \
} methodName##_one_time_tear_down_value {this}; \
void methodName

#define _set_up(methodName) \
methodName##_setup_unused_method() {} \
struct methodName##_setup { \
methodName##_setup(Test_fixture_type* test) {test->setUps.Add({#methodName, {*test, &Test_fixture_type::methodName}});} \
} methodName##_setup_value {this}; \
void methodName

#define _tear_down(methodName) \
methodName##_teardown_unused_method() {} \
struct methodName##_teardown { \
methodName##_teardown(Test_fixture_type* test) {test->tearDowns.Add({#methodName, {*test, &Test_fixture_type::methodName}});} \
} methodName##_teardown_value {this}; \
void methodName

#define _test_fixture(className) \
className; \
using Test_fixture_type = className; \
class className : public TUnit::Framework::TestFixture

#define _test(methodName) \
methodName##_test_unused_method() {} \
struct methodName##_test { \
methodName##_test(Test_fixture_type* test) {test->tests.Add({#methodName, {*test, &Test_fixture_type::methodName}});} \
} methodName##_test_value {this}; \
void methodName

#define _ignore_test(methodName) \
methodName##_test_unused_method() {} \
struct methodName##_test { \
methodName##_test(Test_fixture_type* test) {test->tests.Add({#methodName, {*test, &Test_fixture_type::methodName}, true});} \
} methodName##_test_value {this}; \
void methodName

#define _add_test_fixture(className) \
static struct className##_test_fixture { \
className##_test_fixture() {testFixtures.Add(ref_new<className>());} \
} className##_test_fixture_value;

#define _add_test(className, methodName)

#define _test_class_initialize(methodName) _one_time_set_up(methodName)

#define _test_class_cleanup(methodName) _one_time_tear_down((methodName)

#define _test_initialize(methodName) _set_up(methodName)

#define _test_cleanup(methodName) _tear_down((methodName)

#define _test_class(className) _test_fixture(className)

#define _test_method(methodName) _test(methodName)

#define _ignore_test_method(methodName) _ignore_test(methodName)

#define _add_test_class(className) _add_test_fixture(className)

namespace Switch {
  namespace TUnit {
    namespace Framework {
      class TestFixture;
      class RegisteredMethod : public object {
      public:
        RegisteredMethod() {}
        RegisteredMethod(const RegisteredMethod& registeredMethod) : name(registeredMethod.name), method(registeredMethod.method), ignore(registeredMethod.ignore) {}
        RegisteredMethod(const string& name, delegate<void> method) : RegisteredMethod(name, method, false) {}
        RegisteredMethod(const string& name, delegate<void> method, bool ignore) : name(name), method(method), ignore(ignore) {}
        
        //private:
        friend class TestFixture;
        
        _property<bool, _readonly> Ignore {
          _get {return this->ignore;}
        };
        
        _property<delegate<void>, _readonly> Method {
          _get {return this->method;}
        };
        
        _property<string, _readonly> Name {
          _get {return this->name;}
        };
        
        string name;
        delegate<void> method;
        bool ignore = false;
      };
      
      class TestFixture : public object {
      public:
        void OneTimeSetUp() {
          for (auto oneTimeSetUp : this->oneTimeSetUps) {
            oneTimeSetUp.Method().Invoke();
          }
        }
        
        void OneTimeTearDown() {
          for (auto oneTimeTearDown : this->oneTimeTearDowns) {
            oneTimeTearDown.Method().Invoke();
          }
        }
        
        void SetUp() {
          for (auto setup : this->setUps) {
            setup.Method().Invoke();
          }
        }
        
        void TearDown() {
          for (auto tearDown : this->tearDowns) {
            tearDown.Method().Invoke();
          }
        }
        
        //protected:
        System::Collections::Generic::List<RegisteredMethod> oneTimeSetUps;
        System::Collections::Generic::List<RegisteredMethod> oneTimeTearDowns;
        System::Collections::Generic::List<RegisteredMethod> tests;
        System::Collections::Generic::List<RegisteredMethod> setUps;
        System::Collections::Generic::List<RegisteredMethod> tearDowns;
      };
      /// @cond
      class UnitTest;
      /// @endcond
      
      struct RegisteredTestFixture {
      protected:
        RegisteredTestFixture(const string& name, refptr<TUnit::Framework::TestFixture> testFixture) : name(name), testFixture(testFixture) {
          RegisteredTestFixtures().Add(*this);
        }
        
      private:
        friend class UnitTest;
        string name;
        refptr<TestFixture> testFixture;
        
        static System::Collections::Generic::List<ref<RegisteredTestFixture>>& RegisteredTestFixtures() {
          static System::Collections::Generic::List<ref<RegisteredTestFixture>> registeredTestFixtures;
          return registeredTestFixtures;
        }
      };
      
      /// @brief UnitTest is...
      /*
       class UnitTest {
       public:
       void Run() {
       for (auto registeredTestFixture : RegisteredTestFixture::RegisteredTestFixtures()) {
       if (!registeredTest().ignore) {
       System::Console::WriteLine("Running {0}.{1}", registeredTest().testFixture->GetType().Name, registeredTest().name);
       registeredTest().testFixture().SetUp();
       registeredTest().test();
       registeredTest().testFixture().TearDown();
       }
       }
       }
       };*/
    }
  }
}

System::Collections::Generic::List<refptr<TUnit::Framework::TestFixture>> testFixtures;



#include <Switch/Switch.TUnit.Framework>

using namespace System;

namespace UnitTets {
  class _test_fixture(Test) {
    void _one_time_set_up(OneTimeInit)() {
      Console::WriteLine("Init Test");
    }
    
    void _one_time_tear_down(OneTimeCleanup)() {
      Console::WriteLine("Cleanup Test");
    }
    
    void _set_up(Init)() {
      Console::WriteLine("Init");
    }
    
    void _tear_down(Cleanup)() {
      Console::WriteLine("Cleanup");
    }
    
    void _test(TestCase1)() {
      Console::WriteLine("TestCase1");
    }
    
    void _test(TestCase2)() {
      Console::WriteLine("TestCase2");
    }
  };
  
  _add_test_fixture(Test)
}





namespace SwitchConsole {
  class Program {
  public:
    static void Main(const Array<string>& args) {
      for(auto testFixture : testFixtures) {
        Console::WriteLine(testFixture->GetType().Name);
        testFixture->OneTimeSetUp();
        for (auto test : testFixture->tests) {
          testFixture->SetUp();
          test.Method()();
          testFixture->TearDown();
        }
        testFixture->OneTimeTearDown();
      }
    }
  };
}

_startup(SwitchConsole::Program)

