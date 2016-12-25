#include <Pcf/Pcf>

using namespace System;

class Person : public object {
public:
  Person() {}
  Person(const Person& person) : name(person.name), age(person.age) {}

  // Declare a Name property of type string:
  Property<string> Name {
    pcf_get {return this->name;},
    pcf_set {this->name = value;}
  };
  
  // Declare an Age property of type int:
  Property<int> Age {
    pcf_get {return this->age;},
    pcf_set {this->age = value;}
  };
  
  string ToString() const override {
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

pcf_startup (Person)

// This code produces the following output :
//
// Simple Properties
// Person details - Name = N/A, Age = 0
// Person details - Name = Joe, Age = 99
// Person details - Name = Joe, Age = 100
