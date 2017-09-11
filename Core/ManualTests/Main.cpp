#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    class Data {
    public:
      Data() = default;
      Data(const Data& data) : items(data.items) {};
      
      _property<Array<int>> Items {
        _get {return this->items;},
        _set {this->items = value;}
      };
      
    private:
      Array<int> items = Array<>::CreateInstance<int>(8);
    };
    
    // The main entry point for the application.
    static void Main() {
      Data data;
      data.Items = {12, 24, 48};
      Console::WriteLine("{0} = {{{1}}}", _nameof(data.Items), _typeof(data.Items()));
      Console::WriteLine("{0} = {{{1}}}", _nameof(data.Items), string::Join(", ", data.Items()));
    }
  };
}

_startup (Examples::Program)

