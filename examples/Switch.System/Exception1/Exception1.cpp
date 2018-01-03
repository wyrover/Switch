#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Person : public object {
  private:
    string name;

  public:
    property_<string> Name {
      get_ { return this->name; },
      set_ { this->name = value; }
    };

    int GetHashCode() const override {
      return this->Name().GetHashCode();
    }

    bool MyEquals($<object> obj) const {
      // This implementation contains an error in program logic:
      // It assumes that the obj argument is not null.
      $<Person> p = as<Person>(obj);
      return this->Name().Equals(p().Name);
    }
  };

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      $<Person> p1 = new_<Person>();
      p1->Name = "John";
      $<Person> p2 = null;

      // The following throws a std::exception.
      Console::WriteLine("p1 = p2: {0}", p1->MyEquals(p2));
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// Exception occured : Specified argument is out of range of valid values.
