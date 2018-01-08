![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Folders and files organization

## Folders hierarchy

**√ DO** Respect the project hierarchy

```
root
  +- 3rdparty
  |    +- curl
  |    +- easywsclient
  |    +- ...
  +- build
  +- docs
  |    +- Diagrams
  |    |    +- UML
  |    +- Pictures
  +- examples
  |    +- DesignPatterns
  |    +- Switch.System
  |    +- Switch.System.Drawing
  |    +- ...
  +- scripts
  |    +- cmake
  |    +- install
  +- src
  |    +- Switch.Core
  |    |    +- include
  |    |    |    +- Switch
  |    |    |         +- Microsoft
  |    |    |         |    +- ...
  |    |    |         +- System
  |    |    |              +- ...
  |    |    +- src
  |    |         +- Switch
  |    |              +- Microsoft
  |    |              |    +- ...
  |    |              +- System
  |    |                   +- ...
  |    +- ...
  +- tests
       +- Switch.Core.UnitTests
       |    +- Switch
       |         +- Microsoft
       |         +- System
       |              +- ...
       +- ...
```

**root** folder is the project folder where Switch project was extracted or cloned.

**root/3rdparty** folder contains third party libraries like curl, easywsclient and others.

**root/build** folder contains the build result. This folder is automaticaly create by the install.

**root/docs** folder contains markdown documentations.

**root/docs/Diagrams** folder contains the diagrams used to illustrate the markdown documentation and website.

**root/docs/Diagrams/UML** folder contains the UML diagrams used to illustrate the markdown documentation and website.

**root/docs/Pictures** folder contains the pictures used to illustrate the markdown documentation and website.

**root/examples** folder contains examples to show how to used Switch libraries.

**root/scripts/cmake** folder contains scripts needed by cmake.

**root/scripts/install** folder contains installation scripts.

**root/src** folder contains source files organized by libraries.

For each library the hierarchy is identical :

**root/Switch.LibraryName/include** folder contains include files for Switch.LibraryName library.

**root/Switch.LibraryName/include/Namespace1/Namespace2/...** folder contains include files for Switch.LibraryName library organized by namespaces.

**root/Switch.LibraryName/src** folder contains source files for Switch.LibraryName library.

**root/Switch.LibraryName/src/Namespace1/Namespace2/...** folder contains source files for Switch.LibraryName library organized by namespaces.

**root/tests** folder contains tests organized by library and test types.

For example, the **root/src/Switch.Core** folder contains Switch.Core library source files and the **root/src/Switch.System.Drawing** folder contains Switch.System.Drawing library source files.

For exemple, the **root/tests/Switch.Core.UnitTests** contains Switch.Core library unit tests and the **root/tests/Switch.system.Drawing.ManualTets** folder contains Switch.System.Drawing manual tests.

For example, if a Switch.System.Windows.Forms library header file contains :

```c++
#pragma once

#include <Switch/System/EventArgs.hpp>

#include "../../ComponentModel/CancelEventArgs.hpp"
#include "CloseReason.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        class export_ FormClosingEventArgs : public ComponentModel::CancelEventArgs {
        public:
          FormClosingEventArgs() {}
          FormClosingEventArgs(bool cancel, System::Windows::Forms::CloseReason closeReason) : ComponentModel::CancelEventArgs(cancel), closeReason(closeReason) {}
          FormClosingEventArgs(const FormClosingEventArgs& e) : ComponentModel::CancelEventArgs(e), closeReason(e.closeReason) {}

          property_<System::Windows::Forms::CloseReason, readonly_> CloseReason {
            get_ { return this->closeReason; }
          };

        private:
          System::Windows::Forms::CloseReason closeReason = System::Windows::Forms::CloseReason::UserClosing;
        };
      }
    }
  }
}
```

The file will be in root/src/Switch.System.Windows.Forms/include/Switch/System/Windows/Forms/ path

## File names

**√ DO** Name file with same name of the class, struct, enum, delegate or event that contains.

For example, if file contains :

```c++
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "FormClosingEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        using FormClosingEventHandler = GenericEventHandler<FormClosingEventArgs&>;
      }
    }
  }
}
```

The file will be named to *FormClosingEventHandler.hpp*.

## File extensions

**√ DO** Use .hpp for header files.

**√ DO** Use .cpp for source files.

# Diagrams

**√ DO** Diagrams are generate by Draw.IO Desktop. [Draw.IO Desktop](https://chrome.google.com/webstore/detail/drawio-desktop/pebppomjfocnoigkeepgbmcifnnlndla?hl=en-GB) is a Google Chrome extension.

# UML diagrams

**√ DO** UML diuagrams are generate by [plantUML](http://plantuml.com).

# Editor

**√ DO** Replace tab character with double spaces in your editor or IDE properties. 

```c++
class MyCLass : public object {
public:
  MyCLass() {}
  MyCLass(const MyCLass&) = default;
};
```

# Order of parts in a class or struct declarations

**√ DO** Put public declaration in first.

**√ DO** Put protected declaration in second.

**√ DO** Put private declaration in last.

```c++
class MyClass : public object {
public:
  /// @brief Return a string that represents the current object.
  string ToString() const {return NameGenerator();}

protected:
  /// @brief 
  virtual string NameGenerator() const {return baseName;}

private:
  string baseName = "BaseName";
};
```

# #define

**X DO NOT** Use #define for any good or bad reason.

**√ DO** But instead use *static constexpr* or *static const* for constantes.

### header file :
```c++
class MyCLass : public object {
public:
  static constexpr int maxValue = System::Int32::MaxValue;
  static const System::TimeSpan maxDuration;
};
```

### source file :
```c++
int MyClass::MaxValue;
const System::Timespan MyClass::MaxDuration = 12_s;
```

**√ DO** But instead use template method for macros.

```c++
class Arithmetics static_ {
public:
  template<typename T>
  T Max(T value1, T value2) {return value1 >= value2 ? value1 : value2;} // equivalent : #define Max(value1, value2) (value1 >= value2 1 value1 : value2)
};
```

# Globals

## Global methods

**X DO NOT** Use glabal methods. All methods are in class. If necessary creates class contener like System::Console or System::Math to group static methods. 

## Gloabal variables

**X DO NOT** Use glabal variables. All variables are in class. If necessary a global or static variable can create in a source files (.cpp) but it can't visible in the header file (.hpp). 

**√ DO** Uses [factoryMethod](FactoryMethod.md), [Builder](Builder.md) or [Singleton](Singleton.md) patterns to create objects

# Comments

**√ DO** Using always simple line comment **//** instead block comment /* */

```c++
// This is my
// multiline comment
int x = 3;
```

# Documentation

The documentation is generate by Doxygen.

**√ DO** Write Doxygen documentation only in header file (**.hpp**).

**√ DO** All documentation comment must start by triple slash **///**

```c++
/// @brief MyClass do something
class MyClass {
};
```

**√ DO** Doxygen command start with at-sign **@**

```c++
/// @brief MyFunc do something
/// @param name A string that contains the name.
/// @remarks The name must be begin by a uppercase; otherwise ArgumentException throws.
/// @exception ArgumentException name not started by uppercase.
void MyFunc(string name) {
};
```

This example of doxygen documented class (Object.hpp) shows somes doxygen commands:

```c++
/// @file
/// @brief Contains Switch::System::Object class.
#pragma once

#include <ostream>

#include "../Types.hpp"
#include "../As.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @cond
  template<typename T>
  class RefPtr;
  /// @endcond
  
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class Type;
    class String;
    /// @endcond

    /// @brief Supports all classes in the Switch class hierarchy and provides low-level services to derived classes.
    /// This is the ultimate base class of all classes in the Switch.
    /// It is the root of the type hierarchy.
    /// @par Examples
    /// The following example defines a Point type derived from the Object class and virtuals many of the virtual methods of the Object class. In addition, the example shows how to call many of the static and instance methods of the Object class.
    /// @include Object.cpp
    class export_ Object {
    public:
      /// @brief Create a new instance of the ultimate base class Object
      /// @remarks This constructor is called by constructors in derived classes, but it can also be used to directly create an instance of the Object class.
      Object() = default;
      
      /// @cond
      Object(const Object&) = default;
      Object& operator=(const Object&) = default;
      virtual ~Object() = default;
      bool operator==(const Object& obj) const {return Equals(obj);}
      bool operator!=(const Object& obj) const {return !this->operator==(obj);}
      /// @endcond
      
      /// @brief Determines whether the specified Object is equal to the current Object.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      /// @par Examples
      /// The following code example compares the current instance with another object.
      /// @include ObjectEquals.cpp
      virtual bool Equals(const Object& obj) const {return this == &obj;}

      /// @brief Determines whether the specified Object instances are considered equal.
      /// @param objectA The first Object to compare.
      /// @param objectB The second Object to compare.
      /// @return bool true if objectA is the same instance as objectB or if both are null references or if objectA(objectB) returns true. otherwise, false.
      /// @par Examples
      /// The following code example compares different objects.
      /// @include ObjectEquals2.cpp
      static bool Equals(const Object& objectA, const Object& objectB) {return objectA.Equals(objectB);}

      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current Object.
      virtual int32 GetHashCode() const {return int32(int64(this) & 0x00000000FFFFFFFF) ^ int32((int64(this)>>32) & 0x00000000FFFFFFFF);}
      
      /// @brief Gets the Type of the current instance.
      /// @return Type The Type instance that represents the exact runtime type of the current instance.
      /// @par Examples
      /// The following code example demonstrates that GetType returns the runtime type of the current instance.
      /// @include ObjectGetType.cpp
      virtual Type GetType() const;

      /// @brief Creates a shallow copy of the current Object.
      /// @return refptr<Object> A shallow copy of the current Object.
      /// @par Examples
      /// The following code example shows how to copy an instance of a class using MemberwiseClone.
      /// @include ObjectMemberwiseClone.cpp
      template<typename T>
      RefPtr<Object> MemberwiseClone() const;

      /// @brief Determines whether the specified Object instances are the same instance.
      /// @param objectA The first Object to compare.
      /// @param objectB The second Object to compare.
      /// @return bool true if objectA is the same instance as objectB or if both are null references; otherwise, false.
      /// @par Examples
      /// The following code example uses ReferenceEquals to determine if two objects are the same instance.
      /// @include ObjectReferenceEquals.cpp
      static bool ReferenceEquals(const Object& objectA, const Object& objectB) {return &objectA == &objectB;}

      /// @brief Returns a String that represents the current Object.
      /// @return string A string that represents the current Object.
      /// @par Examples
      /// The following code example demonstrates what ToString returns.
      /// @include ObjectToString.cpp
      virtual String ToString() const;
    };
  }

  /// @brief Supports all classes in the Switch class hierarchy and provides low-level services to derived classes.
  /// @see System::Object
  using object = System::Object;
}

using namespace Switch;

```

For more commands see [Doxygen Special commands](http://www.stack.nl/~dimitri/doxygen/manual/commands.html) and for more informations see [Doxygen Manual](http://www.stack.nl/~dimitri/doxygen/manual/index.html).

# Indentation

**√ DO** Indent block contents

```c++
namespace Test {
  class AClass {
    void Method() {
      int x;
      int y;
    }
  };
}
```

**X DO NOT** Indent open and close braces

```c++
class AClass {
  int aField;

  void AMethod() {
  }
};
```

**X DO NOT** Indent switch sections

```c++
class AClass {
  void Method(int x) {
    switch (x) {
    case 1:
      break;
    }
  }
};
```

**√ DO** Indent case sections

```c++
class AClass {
  void Method(int x) {
    switch (x) {
    case 1:
      break;
    }
  }
};
```

**X DO NOT** Indent label

```c++
class Test {
  void Method() {
  label:
    Console::WriteLine("Hello World");
  }
};
```

# New lines

## New line options for braces

**X DO NOT** Place open brace on new line for types

```c++
class Example {
};
```

**X DO NOT** Place open brace on new line for methods

```c++
void Example() {
}
```

**X DO NOT** Place open brace on new line for properties

```c++
property_<int> Example {
  get_ {
    return 1;
  },
  set_ {
    // nothing
  }
};

```

**X DO NOT** Place open brace on new line for property accessors

```c++
property_<int> Example {
  get_ {
    return 1;
  },
  set_ {
    // nothing
  }
};

```

**X DO NOT** Place open brace on new line for lambda expressions

```c++
void Example() {
  auto del = delegate_(int i, int j) {
  };
}
```

**X DO NOT** Place open brace on new line for control blocks

```c++
void Example() {
  if (true) {
  }
}
```

**X DO NOT** Place open brace on new line for object initializers

```c++
void Example() {
  ArrayList {
    "One", 2, 3_min
  };
}
```

## New line options for keywords

**X DO NOT** Place "else" on new line

```c++
void Example() {
  if (true) {
    // ...
  } else {
    // ...
  }
}
```

**X DO NOT** Place "catch" on new line

```c++
void Example() {
  try {
    // ...
  } catch(...) {
    // ...
  }
}
```

## New line options for expressions

**X DO NOT** Place memberin object initializers on new line

```c++
void Example() {
  new ArrayList {
    "One", 2, 3_min
  };
}
```

**X DO NOT** Place query expression clauses on new line

```c++
void Example() {
  auto q = _from a _in e 
           _from b _in e _select a * b;
}
```

# Spacing

## Set spacing for method declarations

**X DO NOT** Insert space between method name and its opening parenthesis

```c++
void Example() {
}
```

**X DO NOT** Insert space within argument list parentheses

```c++
void Example(int i, int j) {
}
```


**X DO NOT** Insert space within empty argument list parentheses

```c++
void Example() {
}
```

## Set spacing for method calls

**X DO NOT** Insert space between method name and its opening parenthesis

```c++
void Example() {
  Test();
}
```

**X DO NOT** Insert space within argument list parentheses

```c++
void Example() {
  Test(int i, int j);
}
```


**X DO NOT** Insert space within empty argument list parentheses

```c++
void Example() {
  Test();
}
```

## Set other spacing options

**√ DO** Insert space after keywords in control flow statements

```c++
void Example() {
  if (condition) {
  }
}
```

**X DO NOT** Insert space within parentheses of expressions

```c++
void Example() {
  i = (5 + 3) * 2;
}
```

**X DO NOT** Insert space within parentheses of type casts

```c++
void Example() {
  test = (const ITest&)o;
}
```
**X DO NOT** Insert space within parentheses of control flow statements

```c++
void Example() {
  if (condition) {
  }
}
```

**X DO NOT** Insert space after casts

```c++
void Example() {
  test = (const ITest&)o;
}
```

**√ DO** Insert space in declaration statements

```c++
void Example() {
  int x = 5;
}
```

## Set spacing for square brackets

**X DO NOT** Insert space before open square bracket

```c++
void Example() {
  i[5] = 3;
}
```

**X DO NOT** Insert space within empty square brackets

```c++
void Example() {
  new int[] {1, 2};
}
```

**X DO NOT** Insert space within square brackets

```c++
void Example() {
  i[5] = 3;
}
```

## Set spacing for brackets

**√ DO** Insert space after colon for base or interface in type declaration

```c++
class Foo : public Bar {
}
```

**√ DO** Insert space after comma

```c++
void Example() {
  for (int i = 0; i < 10, i > 5; i++) {
  }
}
```

**X DO NOT** Insert space after dot

```c++
void Example() {
  Foo.Bar.Test();
}
```

**X DO NOT** Insert space after structure or class dereference 

```c++
void Example() {
  Foo->Bar->Test();
}
```

**√ DO** Insert space after semicolon in "for" statement

```c++
void Example() {
  for (int i = 0; i < 10; i++) {
  }
}
```

**√ DO** Insert space before colon for base or interface in type declaration

```c++
class Foo : public Bar {
}
```

**X DO NOT** Insert space before dot

```c++
void Example() {
  Foo.Bar.Test();
}
```

**X DO NOT** Insert space before Structure or class dereference 

```c++
void Example() {
  Foo->Bar->Test();
}
```

**X DO NOT** Insert space before semicolon in "for" statement

```c++
void Example() {
  for (int i = 0; i < 10; i++) {
  }
}
```

**√ DO** Set spacing for operators

```c++
void Example() {
  i = (5 + 3) * 2;
}
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
