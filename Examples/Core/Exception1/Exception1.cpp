#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Person : public object {
  private:
    string name;
    
  public:
    _property<string> Name {
      _get { return this->name; },
      _set { this->name = value; }
    };
    
    int GetHashCode() const override {
      return this->Name().GetHashCode();
    }
    
    bool MyEquals(_<object> obj) const {
      // This implementation contains an error in program logic:
      // It assumes that the obj argument is not null.
      _<Person> p = as<Person>(obj);
      return this->Name().Equals(p().Name);
    }
  };
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      _<Person> p1 = ref_new<Person>();
      p1->Name = "John";
      _<Person> p2 = null;
      
      // The following throws a std::exception.
      Console::WriteLine("p1 = p2: {0}", p1->MyEquals(p2));
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// Exception occured : Specified argument is out of range of valid values.
