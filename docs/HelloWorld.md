[![Switch Header](Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

This tutorial shows several versions of a Hello World program with Switch.

# Tutorial

The following examples show different ways of writing the C++ Hello World program.

# Example 1

```c++
// Hello1.cpp
#include <Switch/Switch>
 
class Hello1 {
public:
  static void Main() {
    System::Console::WriteLine("Hello, World!");
  }
};
​
startup_(Hello1);
```

**Output**

```
Hello, World!
```

Code Discussion Every Main method must be contained inside a class (Hello1 in this case). The System::Console class contains a WriteLine method that can be used to display a string to the console.

# Example 2

To avoid fully qualifying classes throughout a program, you can use the using directive as shown below:

```c++
// Hello2.cpp
#include <Switch/Switch>
 
using namespace System;
 
class Hello2 {
public:
  static void Main() {
    Console::WriteLine("Hello, World!");
  }
};
​
startup_(Hello2);
```

**Output**

```
Hello, World!
```

# Example 3

If you need access to the command line parameters passed in to your application, simply change the signature of the Main method to include them as shown below. This example counts and displays the command line arguments.

```c++
// Hello3.cpp
// arguments: A B C D
#include <Switch/Switch>
 
using namespace System;
 
class Hello3 {
public:
  static void Main(const Array<string>& args) {
    Console::WriteLine("Hello, World!");
    Console::WriteLine("You entered the following {0} command line arguments:", args.Length);
    for (int i = 0; i < args.Length; i++) {
      Console::WriteLine("{0}", args[i]);
    }
  }
};
​
startup_(Hello3);
```

**Output**

```
Hello, World!
You entered the following 4 command line arguments:
A
B
C
D
```

# Example 4

To return a return code, change the signature of the Main method as shown below:

```c++
// Hello4.cpp
#include <Switch/Switch>
​
using namespace System;
​
class Hello4 {
public:
  static int Main() {
    Console::WriteLine("Hello, World!");
    return 0;
  }
};
 
startup_(Hello4);
```

**Output**

```
Hello, World!
```

# See also
​
Other Resources

* [Tutorials](Tutorials.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
