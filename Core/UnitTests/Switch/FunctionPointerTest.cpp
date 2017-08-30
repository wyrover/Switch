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
      Assert::IsTrue(fct.IsEmpty(), sw_current_information);
      Assert::Throws<std::exception>(sw_delegate {fct.Invoke();}, sw_current_information);
    }
    
    void CreateFunctionPointerWithLambdaThenInvoke() {
      __opaque_function_pointer__<> fct = sw_delegate {
        result = "fct called";
      };
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      fct.Invoke();
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithLambdaAndWithArgumentThenInvoke() {
      __opaque_function_pointer__<void, const string&> fct = sw_delegate(const string& value) {
        result = value;
      };
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithLambdaAndWithReturnThenInvoke() {
      __opaque_function_pointer__<string> fct = sw_delegate {
        return "fct called";
      };
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithStaticMethodThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static void StaticFunc() {
          result = "fct called";
        }
      };
      __opaque_function_pointer__<> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      fct.Invoke();
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithStaticMethodAndWithArgumentThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static void StaticFunc(const string& value) {
          result = value;
        }
      };
      __opaque_function_pointer__<void, const string&> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithStaticMethodAndWithReturnThenInvoke() {
      struct TestStatic {
        TestStatic() = delete;
        static string StaticFunc() {
          return "fct called";
        }
      };
      __opaque_function_pointer__<string> fct = TestStatic::StaticFunc;
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithMemberMethodThenInvoke() {
      struct TestMember {
        void MemberFunc() {
          result = "fct called";
        }
      };
      TestMember testMember;
      __opaque_function_pointer__<> fct = __opaque_function_pointer__<>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      fct.Invoke();
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithMemberMethodAndWithArgumentThenInvoke() {
      struct TestMember {
        void MemberFunc(const string& value) {
          result = value;
        }
      };
      TestMember testMember;
      __opaque_function_pointer__<void, const string&> fct = __opaque_function_pointer__<void, const string&>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithMemberMethodAndWithReturnThenInvoke() {
      struct TestMember {
        string MemberFunc() {
          return "fct called";
        }
      };
      TestMember testMember;
      __opaque_function_pointer__<string> fct = __opaque_function_pointer__<string>(testMember, &TestMember::MemberFunc);
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithFunctorThenInvoke() {
      struct TestFunctor {
        void operator()() {
          result = "fct called";
        }
      };
      TestFunctor testFunctor;
      __opaque_function_pointer__<> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      fct.Invoke();
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithFunctorAndWithArgumentThenInvoke() {
      struct TestFunctor {
        void operator()(const string& value) {
          result = value;
        }
      };
      TestFunctor testFunctor;
      __opaque_function_pointer__<void, const string&> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      fct.Invoke("fct called");
      Assert::AreEqual("fct called", result, sw_current_information);
    }
    
    void CreateFunctionPointerWithFunctorAndWithReturnThenInvoke() {
      struct TestFunctor {
        string operator()() {
          return "fct called";
        }
      };
      TestFunctor testFunctor;
      __opaque_function_pointer__<string> fct = testFunctor;
      Assert::IsFalse(fct.IsEmpty(), sw_current_information);
      result = fct.Invoke();
      Assert::AreEqual("fct called", result, sw_current_information);
    }
  };
  
  string FunctionPointerTest::result;
  
  sw_test(FunctionPointerTest, CreateFunctionPointerEmptyThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithLambdaThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithLambdaAndWithArgumentThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithLambdaAndWithReturnThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodAndWithArgumentThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithStaticMethodAndWithReturnThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodAndWithArgumentThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithMemberMethodAndWithReturnThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithFunctorThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithFunctorAndWithArgumentThenInvoke)
  sw_test(FunctionPointerTest, CreateFunctionPointerWithFunctorAndWithReturnThenInvoke)
}
