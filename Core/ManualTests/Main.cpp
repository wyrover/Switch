#include <Switch/Foreach.hpp>
#include <Switch/Startup.hpp>
#include <Switch/Var.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      _<Version> version = gcnew<Version>(1, 2, 3);
      Console::WriteLine("version = {0}", version());
      
      Array<int> a = {1, 2, 3, 4, 5};
      _foreach(_var i _in a)
        Console::WriteLine(i);
    }
  };
}

_startup (Examples::Program)

