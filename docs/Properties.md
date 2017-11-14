![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

This tutorial shows how properties are an integral part of the Switch. It demonstrates how properties are declared and used.

# Tutorial

This tutorial includes two examples. The first example shows how to declare and use read/write properties. The second example demonstrates abstract properties and shows how to override these properties in subclasses.

## Example 1

This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.

```c++
//Person.cpp
 
#include <Switch/Switch>
 
using namespace System;
 
class Person : public object {
public:
  Person() {}
  Person(const Person& person) : name(person.name), age(person.age) {}
  
  // Declare a Name property of type string:
  _property<string> Name {
    _get {return this->name;},
    _set {this->name = value;}
  };
  
  // Declare an Age property of type int:
  _property<int> Age {
    _get {return this->age;},
    _set {this->age = value;}
  };
  
  string ToString() const override {
    return "Name = " + this->Name + ", this->Age = " + this->Age;
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
 
_startup(Person);
```

**Output**

```
Simple Properties
Person details - Name = N/A, Age = 0
Person details - Name = Joe, Age = 99
Person details - Name = Joe, Age = 100
```

# Code Discussion

Notice the way that the properties are declared, for example, consider the Name property: 

```c++
_property<string> Name {
  _get {return this->name;}
  _set {this->name = value;}
}
```


# See also
​
Other Resources

* [Tutorials](Tutorials.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
