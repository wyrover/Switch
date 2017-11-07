#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class PropertyTestClass {
  public:
    PropertyTestClass() {}
    PropertyTestClass(const PropertyTestClass& property) : name(property.name) {}
    
    _property<string, _writeonly> Name {
      _set {this->name = value;}
    };
    
  public:
    string name = "Test property";
  };
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      refptr<PropertyTestClass>p1 = ref_new<PropertyTestClass>();
      
      p1->Name = "Other value";
      Console::WriteLine(p1->name);
      
    }
  };
}

_startup(Examples::Program)
