#include <Switch/Foreach.hpp>
#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/Var.hpp>
#include <Switch/System/Console.hpp>

#undef _export

#define _internal \
private:

#define _private \
private:

#define _protected \
protected:

#define _public \
public:

using namespace System;

namespace Examples {
  class Program {
  public:
    class Data {
      _public Data() = default;
      _public Data(const Data& data) : items(data.items) {};
      
      _public property<Array<int>> Items {
        _get {return this->items;},
        _set {this->items = value;}
      };
      
      _private Array<int> items = Array<>::CreateInstance<int>(8);
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

