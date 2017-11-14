#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      double d = 41.6;
      int i1 = Convert::ToInt32(d);
      int i2 = as<int>(d);
      Console::WriteLine("d = {0}, Convert::ToInt32(d) = {1}, as<int>(d) = {2}", d, i1, i2);
      
      int i = 42;
      string s1 = Convert::ToString(i);
      string s2 = as<string>(i);
      Console::WriteLine("i = {0}, Convert::ToString(i) = {1}, as<string>(i) = {2}", i, s1, s2);
      
      any a = "string";
      s1 = Convert::ToString(a);
      s2 = as<string>(a);
      Console::WriteLine("a = {0}, Convert::ToString(a) = {1}, as<string>(a) = {2}", a, s1, s2);
      
      refptr<object> o = ref_new<Uri>("https://www.gammasoft71.wixsite.com/switch");
      refptr<Uri> u = as<Uri>(o);
      Console::WriteLine("o = {0}, as<Uri>(o) = {1}", *o, *u);
      
      ref<object> value = "a"_s;
      ref<string> value2 = as<string>(value);
      Console::WriteLine("value = {0}, as<string>(value) = {1}", *value, *value2);
      
      Random rand;
      try {
        Console::WriteLine("as<string>(rand) = {0}", as<string>(rand));
      } catch (const InvalidCastException& e) {
        Console::WriteLine("Bad cast : {0} !", e.Message);
      }
      
      refptr<object> version = ref_new<Version>(1, 1, 5);
      refptr<string> str = as<string>(version);
      if (str == null) {
        Console::WriteLine("Bad cast!");
      }
      
      ref<object> dateTime = DateTime::Now();
      ref<Byte> b = as<Byte>(dateTime);
      if (b == null) {
        Console::WriteLine("Bad cast!");
      }
    }
  };
}

_startup(Examples::Program);

// This code produces output similar to the following:
//
// d = 41.6, Convert::ToInt32(d) = 42, as<int>(d) = 42
// i = 42, Convert::ToString(i) = 42, as<string>(i) = 42
// a = string, Convert::ToString(a) = string, as<string>(a) = string
// o = https://www.gammasoft71.wixsite.com/switch, as<Uri>(o) = https://www.gammasoft71.wixsite.com/switch
// value = a, as<string>(value) = a
// Bad cast : Specified cast is not valid. !
// Bad cast!
// Bad cast!
