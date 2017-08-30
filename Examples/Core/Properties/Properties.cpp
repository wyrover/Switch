#include <Switch/Switch>

using namespace System;

class Person : public object {
public:
  Person() {}
  // Must be specified because the copycontructor of Property class is deleted. The implicit or default copy constructor is not suffisant.
  Person(const Person& person) : name(person.name), age(person.age) {}

  // Declare a Name property of type string:
  Property<string> Name {
    sw_get {return this->name;},
    sw_set {this->name = value;}
  };
  
  // Declare an Age property of type int:
  Property<int> Age {
    sw_get {return this->age;},
    sw_set {this->age = value;}
  };
  
  string ToString() const noexcept override {
    return "Name = " + this->Name + ", this->Age = " + Age;
  }
  
  static void Main() {
    System::Console::WriteLine("Simple Properties");
    
    // Create a new Person object:
    Person person;
  
    // Print out the name and the age associated with the person:
    Console::WriteLine("Person details - {0}", person);
    
    // Set some values on the person object:
    person.Name = "Joe";
    person.Age = 99;
    Console::WriteLine("Person details - {0}", person);
    
    // Increment the Age property:
    person.Age += 1;
    Console::WriteLine("Person details - {0}", person);
  }
  
private:
  string name = "N/A";
  int age = 0;
};

sw_startup (Person)

// This code produces the following output :
//
// Simple Properties
// Person details - Name = N/A, Age = 0
// Person details - Name = Joe, Age = 99
// Person details - Name = Joe, Age = 100
