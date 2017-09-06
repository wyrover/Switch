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
      Data() = default;
      Data(const Data& data) : items(data.items) {};
      
      property<Array<int>> Items {
        _get {return this->items;},
        _set {this->items = value;}
      };
      
    private:
      Array<int> items = Array<>::CreateInstance<int>(8);
    };
    
    // The main entry point for the application.
    static void Main() {
      __opaque_function_pointer__<void, const string&> fct = _delegate(const string& value) {
        Console::WriteLine("value = {0}", value);
      };
      
      fct("Test");
    }
  };
}

_startup (Examples::Program)

