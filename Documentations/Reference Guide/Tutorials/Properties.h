/// @page TutorialPropertiesPage Properties
///
/// This tutorial shows how properties are an integral part of the Pcf. It demonstrates how properties are declared and used.
///
/// @section TutorialSection Tutorial
/// This tutorial includes two examples. The first example shows how to declare and use read/write properties. The second example demonstrates abstract properties and shows how to override these properties in subclasses.
///
/// @section Example1Section Example 1
/// This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.
/// @code
/// //Person.cpp
/// #include <Pcf/Pcf>
///
/// using namespace System;
///
/// class Person : public object {
/// public:
///   Person() {}
///   Person(const Person& person) : name(person.name), age(person.age) {}
///
///   // Declare a Name property of type string:
///   Property<string> Name {
///     pcf_get {return this->name;},
///     pcf_set {this->name = value;}
///   };
///
///   // Declare an Age property of type int:
///   Property<int> Age {
///     pcf_get {return this->age;},
///     pcf_set {this->age = value;}
///   };
///
///   string ToString() const override {
///     return "Name = " + this->Name + ", this->Age = " + this->Age;
///   }
///
/// static void Main() {
///   System::Console::WriteLine("Simple Properties");
///
///   // Create a new Person object:
///   Person person;
///
///   // Print out the name and the age associated with the person:
///   Console::WriteLine("Person details - {0}", person);
///
///   // Set some values on the person object:
///   person.Name = "Joe";
///   person.Age = 99;
///   Console::WriteLine("Person details - {0}", person);
///
///   // Increment the Age property:
///   person.Age += 1;
///   Console::WriteLine("Person details - {0}", person);
/// }
///
/// private:
///   string name = "N/A";
///   int age = 0;
/// };
///
/// pcf_startup(Person)
/// @endcode
/// @b Output
/// @verbatim Simple Properties
 Person details - Name = N/A, Age = 0
 Person details - Name = Joe, Age = 99
 Person details - Name = Joe, Age = 100 @endverbatim
///
/// Code Discussion
///
/// Notice the way that the properties are declared, for example, consider the Name property:
/// @code
///   Property<string> Name {
///     pcf_get {return this->name;}
///     pcf_set {this->name = value;}
///   }
/// @endcode
