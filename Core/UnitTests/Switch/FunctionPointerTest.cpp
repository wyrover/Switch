#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class FunctionPointerTest : public TestFixture {
  protected:
    static string result;
    void SetUp() override {result = string::Empty;}
    
    void CreateFunctionPointerEmptyThenInvoke() {
      __opaque_function_pointer__<> fct;
      Assert::IsTrue(fct.IsEmpty(), _caller);
      Assert::Throws<std::exception>(_delegate {fct.Invoke();}, _caller);
    }
    
    void CreateFunctionPointerWithLambdaThenInvoke() {
      __opaque_function_pointer__<> fct = _delegate {
        result = "fct called";
      };
      Assert::IsFalse(fct.IsEmpty(), _caller);
      fct.Invoke();
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithLambdaAndWithArgumentThenInvoke() {
      __opaque_function_pointer__<void, const string&> fct = _delegate(const string& value) {
        result = value;
      };
      Assert::IsFalse(fct.IsEmpty(), _caller);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithLambdaAndWithReturnThenInvoke() {
      __opaque_function_pointer__<string> fct = _delegate {
        return "fct called";
      };
      Assert::IsFalse(fct.IsEmpty(), _caller);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithStaticMethodThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static void StaticFunc() {
          result = "fct called";
        }
      };
      __opaque_function_pointer__<> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), _caller);
      fct.Invoke();
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithStaticMethodAndWithArgumentThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static void StaticFunc(const string& value) {
          result = value;
        }
      };
      __opaque_function_pointer__<void, const string&> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), _caller);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithStaticMethodAndWithReturnThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static string StaticFunc() {
          return "fct called";
        }
      };
      __opaque_function_pointer__<string> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), _caller);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithMemberMethodThenInvoke() {
      struct TestMember {
        void MemberFunc() {
          result = "fct called";
        }
      };
      TestMember testMember;
      __opaque_function_pointer__<> fct = __opaque_function_pointer__<>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), _caller);
      fct.Invoke();
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithMemberMethodAndWithArgumentThenInvoke() {
      struct TestMember {
        void MemberFunc(const string& value) {
          result = value;
        }
      };
      TestMember testMember;
      __opaque_function_pointer__<void, const string&> fct = __opaque_function_pointer__<void, const string&>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), _caller);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithMemberMethodAndWithReturnThenInvoke() {
      struct TestMember {
        string MemberFunc() {
          return "fct called";
        }
      };
      TestMember testMember;
      __opaque_function_pointer__<string> fct = __opaque_function_pointer__<string>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), _caller);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithFunctorThenInvoke() {
      struct TestFunctor {
        void operator()() {
          result = "fct called";
        }
      };
      TestFunctor testFunctor;
      __opaque_function_pointer__<> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), _caller);
      fct.Invoke();
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithFunctorAndWithArgumentThenInvoke() {
      struct TestFunctor {
        void operator()(const string& value) {
          result = value;
        }
      };
      TestFunctor testFunctor;
      __opaque_function_pointer__<void, const string&> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), _caller);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, _caller);
    }
    
    void CreateFunctionPointerWithFunctorAndWithReturnThenInvoke() {
      struct TestFunctor {
        string operator()() {
          return "fct called";
        }
      };
      TestFunctor testFunctor;
      __opaque_function_pointer__<string> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), _caller);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, _caller);
    }
  };
  
  string FunctionPointerTest::result;
  
  _test(FunctionPointerTest, CreateFunctionPointerEmptyThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithLambdaThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithLambdaAndWithArgumentThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithLambdaAndWithReturnThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodAndWithArgumentThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodAndWithReturnThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodAndWithArgumentThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodAndWithReturnThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithFunctorThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithFunctorAndWithArgumentThenInvoke)
  _test(FunctionPointerTest, CreateFunctionPointerWithFunctorAndWithReturnThenInvoke)
}
