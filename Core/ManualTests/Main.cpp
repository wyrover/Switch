#include <Switch/Foreach.hpp>
#include <Switch/Startup.hpp>
#include <Switch/Var.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    class Data {
    public:
      Data() {}
      Data(const Data& data) {}
      
      Property<Array<int>, ReadOnly> Items {
        _get {return this->items;}
      };
      
    private:
      Array<int> items = Array<>::CreateInstance<int>(8);
    };
    // The main entry point for the application.
    static void Main() {
      _<Version> version = gcnew<Version>(1, 2, 3);
      Console::WriteLine("version = {0}", *version);
      Data data;
      Console::WriteLine("Length = {0}", data.Items().Length);
      
      Array<int> a = {1, 2, 3, 4, 5};
      _foreach(_var i _in a)
        Console::WriteLine(i);
    }
  };
}

_startup (Examples::Program)

