#include <Switch/Switch>

using namespace System;

namespace Examples {
  class IdInfo : public object {
  public :
    int idNumber;

    explicit IdInfo(int idNumber) { this->idNumber = idNumber; }
  };

  class Person : public object {
  public:
    int age;
    string name;
    IdInfo* idInfo;

    refptr<Person> ShallowCopy() { return as<Person>(MemberwiseClone<Person>()); }

    refptr<Person> DeepCopy() {
      refptr<Person> other = as<Person>(MemberwiseClone<Person>());
      other->idInfo = new IdInfo(idInfo->idNumber);
      return other;
    }
  };

  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create an instance of Person and assign values to its fields.
      refptr<Person> person1 = ref_new<Person>();
      person1->age = 42;
      person1->name = "Sam";
      person1->idInfo = new IdInfo(6565);

      // Perform a shallow copy of person1 and assign it to person2.
      refptr<Person> person2 = person1->ShallowCopy();

      // Display values of person1, person2
      Console::WriteLine("Original values of person1 and person2:");
      Console::WriteLine("   person1 instance values: ");
      DisplayValues(*person1);
      Console::WriteLine("   person2 instance values:");
      DisplayValues(*person2);

      // Change the value of person1 properties and display the values of person1 and person2.
      person1->age = 32;
      person1->name = "Frank";
      person1->idInfo->idNumber = 7878;
      Console::WriteLine("\nValues of person1 and person2 after changes to person1:");
      Console::WriteLine("   person1 instance values: ");
      DisplayValues(*person1);
      Console::WriteLine("   person2 instance values:");
      DisplayValues(*person2);

      // Make a deep copy of person1 and assign it to person3.
      refptr<Person> person3 = person1->DeepCopy();
      // Change the members of the person1 class to new values to show the deep copy.
      person1->name = "George";
      person1->age = 39;
      person1->idInfo->idNumber = 8641;
      Console::WriteLine("\nValues of person1 and person3 after changes to person1:");
      Console::WriteLine("   person1 instance values: ");
      DisplayValues(*person1);
      Console::WriteLine("   person3 instance values:");
      DisplayValues(*person3);

      delete (person1->idInfo);
      delete (person3->idInfo);
    }

    static void DisplayValues(const Person& person) {
      Console::WriteLine("      Name: "_S + person.name + ", Age: " + person.age);
      Console::WriteLine("      Value: "_S + person.idInfo->idNumber);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Original values of person1 and person2:
// person1 instance values:
// Name: Sam, Age: 42
// Value: 6565
// person2 instance values:
// Name: Sam, Age: 42
// Value: 6565
//
// Values of person1 and person2 after changes to person1:
// person1 instance values:
// Name: Frank, Age: 32
// Value: 7878
// person2 instance values:
// Name: Sam, Age: 42
// Value: 7878
//
// Values of person1 and person3 after changes to person1:
// person1 instance values:
// Name: George, Age: 39
// Value: 8641
// person3 instance values:
// Name: Frank, Age: 32
// Value: 7878
