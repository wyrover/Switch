#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  class FunctionPointerTest : public testing::Test {
  protected:
    static string result;
    void SetUp() override {result = string::Empty;}
  };
  
  string FunctionPointerTest::result;
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerEmptyThenInvoke) {
    __opaque_function_pointer__<> fct;
    ASSERT_TRUE(fct.IsEmpty());
    ASSERT_THROW(fct.Invoke(), std::exception);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithLambdaThenInvoke) {
    __opaque_function_pointer__<> fct = _delegate {
      result = "fct called";
    };
    ASSERT_FALSE(fct.IsEmpty());
    fct.Invoke();
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithLambdaAndWithArgumentThenInvoke) {
    __opaque_function_pointer__<void, const string&> fct = _delegate(const string& value) {
      result = value;
    };
    ASSERT_FALSE(fct.IsEmpty());
    fct.Invoke("fct called");
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithLambdaAndWithReturnThenInvoke) {
    __opaque_function_pointer__<string> fct = _delegate {
      return "fct called";
    };
    ASSERT_FALSE(fct.IsEmpty());
    result = fct.Invoke();
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithStaticMethodThenInvoke) {
    struct TestStatic {
      TestStatic() = delete;
      static void StaticFunc() {
        result = "fct called";
      }
    };
    __opaque_function_pointer__<> fct = TestStatic::StaticFunc;
    ASSERT_FALSE(fct.IsEmpty());
    fct.Invoke();
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithStaticMethodAndWithArgumentThenInvoke) {
    struct TestStatic {
      TestStatic() = delete;
      static void StaticFunc(const string& value) {
        result = value;
      }
    };
    __opaque_function_pointer__<void, const string&> fct = TestStatic::StaticFunc;
    ASSERT_FALSE(fct.IsEmpty());
    fct.Invoke("fct called");
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithStaticMethodAndWithReturnThenInvoke) {
    struct TestStatic {
      TestStatic() = delete;
      static string StaticFunc() {
        return "fct called";
      }
    };
    __opaque_function_pointer__<string> fct = TestStatic::StaticFunc;
    ASSERT_FALSE(fct.IsEmpty());
    result = fct.Invoke();
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithMemberMethodThenInvoke) {
    struct TestMember {
      void MemberFunc() {
        result = "fct called";
      }
    };
    TestMember testMember;
    __opaque_function_pointer__<> fct = __opaque_function_pointer__<>(testMember, &TestMember::MemberFunc);
    ASSERT_FALSE(fct.IsEmpty());
    fct.Invoke();
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithMemberMethodAndWithArgumentThenInvoke) {
    struct TestMember {
      void MemberFunc(const string& value) {
        result = value;
      }
    };
    TestMember testMember;
    __opaque_function_pointer__<void, const string&> fct = __opaque_function_pointer__<void, const string&>(testMember, &TestMember::MemberFunc);
    ASSERT_FALSE(fct.IsEmpty());
    fct.Invoke("fct called");
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithMemberMethodAndWithReturnThenInvoke) {
    struct TestMember {
      string MemberFunc() {
        return "fct called";
      }
    };
    TestMember testMember;
    __opaque_function_pointer__<string> fct = __opaque_function_pointer__<string>(testMember, &TestMember::MemberFunc);
    ASSERT_FALSE(fct.IsEmpty());
    result = fct.Invoke();
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithFunctorThenInvoke) {
    struct TestFunctor {
      void operator()() {
        result = "fct called";
      }
    };
    TestFunctor testFunctor;
    __opaque_function_pointer__<> fct = testFunctor;
    ASSERT_FALSE(fct.IsEmpty());
    fct.Invoke();
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithFunctorAndWithArgumentThenInvoke) {
    struct TestFunctor {
      void operator()(const string& value) {
        result = value;
      }
    };
    TestFunctor testFunctor;
    __opaque_function_pointer__<void, const string&> fct = testFunctor;
    ASSERT_FALSE(fct.IsEmpty());
    fct.Invoke("fct called");
    ASSERT_EQ("fct called", result);
  }
  
  TEST_F(FunctionPointerTest, CreateFunctionPointerWithFunctorAndWithReturnThenInvoke) {
    struct TestFunctor {
      string operator()() {
        return "fct called";
      }
    };
    TestFunctor testFunctor;
    __opaque_function_pointer__<string> fct = testFunctor;
    ASSERT_FALSE(fct.IsEmpty());
    result = fct.Invoke();
    ASSERT_EQ("fct called", result);
  }
}
