#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    using Stuff = System::Threading::Mutex;

    class C {
    public:
      property_<int> Value {
        get_ {return this->value;},
        set_ {this->value = value;}
      };
      static int Method1(const string& x, int y) {return 0;}
      static int Method1(const string& x, const string& y) {return 0;}
      int Method2(int z) {return 0;}
      template<typename T>
      string f(const T& value) {return nameof_(value);}

    private:
      int value = 0;
    };

    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      C c;
      c.Value = 42;

      Console::WriteLine("{0} = {1}", nameof_(c.Value), c.Value);
      Console::WriteLine("{0} = {1}", nameof_(c.Value), typeof_(c.Value));
      C::Method1("", 24);

      Console::WriteLine(nameof_(C));
      Console::WriteLine(nameof_(C::Method1));
      Console::WriteLine(nameof_(C::Method2));
      Console::WriteLine(nameof_(c.Method1));
      Console::WriteLine(nameof_(c.Method2));
      Console::WriteLine(c.f(""));
      Console::WriteLine(nameof_(Stuff));
    }
  };
}

startup_(Examples::Program);

// This code produces the following output if 3 is entered on command line:
//
// c.Value = 42
// c.Value = property_<int, readwrite_>
// C
// C::Method1
// C::Method2
// c.Method1
// c.Method2
// value
// Stuff

