#include <Switch/Abstract.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/Using.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(InterfaceTest, CreateClassNotInheritedFromAnInterface) {
    static string result;
    result = "";
    struct NotAnInterface {
      ~NotAnInterface() {result += "~NotAnInterface";}
    };

    struct NotInheritedFromAnInterface : public NotAnInterface {
      ~NotInheritedFromAnInterface() {result += "~NotInheritedFromAnInterface";}
    };

    using_(refptr<NotAnInterface> value = ref_new<NotInheritedFromAnInterface>());
    ASSERT_EQ("~NotAnInterface", result);
  }

  TEST(InterfaceTest, CreateClassInheritedFromAnInterface) {
    static string result;
    result = "";
    struct AnInterface abstract_ {
      ~AnInterface() {result += "~AnInterface";}
    };

    struct InheritedFromAnInterface : public AnInterface {
      ~InheritedFromAnInterface() {result += "~InheritedFromAnInterface";}
    };

    using_(refptr<AnInterface> value = ref_new<InheritedFromAnInterface>());
    ASSERT_EQ("~InheritedFromAnInterface~AnInterface", result);
  }
}

