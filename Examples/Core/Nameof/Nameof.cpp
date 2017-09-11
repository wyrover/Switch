#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    using Stuff = System::Threading::Mutex;
    
    class C {
    public:
      property<int> Value {
        _get {return this->value;},
        _set {this->value = value;}
      };
      static int Method1 (const string &x, int y) {return 0;}
      static int Method1 (const string& x, const string& y) {return 0;}
      int Method2 (int z) {return 0;}
      template<typename T>
      string f(const T& value) {return nameof(value);}
      
    private:
      int value = 0;
    };

    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      C c;
      c.Value = 42;
      
      Console::WriteLine("{0} = {1}", nameof(c.Value), c.Value);
      Console::WriteLine("{0} = {1}", nameof(c.Value), typeof(c.Value));
      C::Method1("", 24);
      
      Console::WriteLine(nameof(C));
      Console::WriteLine(nameof(C::Method1));
      Console::WriteLine(nameof(C::Method2));
      Console::WriteLine(nameof(c.Method1));
      Console::WriteLine(nameof(c.Method2));
      Console::WriteLine(c.f(""));
      Console::WriteLine(nameof(Stuff));
    }
  };
}

_startup (Examples::Program)

// This code produces the following output if 3 is entered on command line:
//
// c.Value = 42
// c.Value = property<int, readwrite>
// C
// C::Method1
// C::Method2
// c.Method1
// c.Method2
// value
// Stuff

