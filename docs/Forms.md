![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

This tutorial describe the basic steps that you must complete to create and run a Windows Forms application from the command line.

# Tutorial

The following procedures describe the basic steps that you must complete to create and run a Windows Forms application from the command line. There is extensive support for these procedures in Visual Studio. Also see Walkthrough: Creating a Simple Windows Form.

## To create the form

1. In an empty code file, type the following include file and using statements:

```c++
#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
```

2. Declare a class named Form1 that inherits from the Form class.

```c++
  class Form1 : public Form
```

3. Create a default constructor for Form1.

You will add more code to the constructor in a subsequent procedure.

```c++
  public:
    Form1() {}
```

4. Add a Main method to the class.

a. Call EnableVisualStyles to give a modern Windows appearance to your application (no effect in macOS and Linux).
b. Create an instance of the form and run it.

```c++
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
```

5. Add _startup command to specity to Switch the class that contains the main method.

```c++
_startup (Form1);
```

## To create the CMakeLists.txt

1. Add the cmake minimum version required.

```bash
cmake_minimum_required(VERSION 3.8)
```

2. Set the project name.

```bash
Project(Form1)
```

3. Specify c++14 standard.

```bash
set(CMAKE_CXX_STANDARD 14)
```

4. Add build rules.

```bash
add_executable(Form1 ${SWITCH_GUI} Form1.cpp)
target_link_libraries(Form1 Switch.System.Windows.Forms)
```

## To compile and run the application on Windows

1. At the Command prompt, navigate to the directory you created the Form1 class adnd CMakeLists.
2. Create build directory build.

```batch
mkdir build
cd build
```

3. Generate the solution.

```batch
cmake .. -DCMAKE_INSTALL_PREFIX=c:/usr/local
```

4. Compile the form.

```batch
cmake --build .
```

# See also
​
Other Resources

* [Tutorials](Tutorials.md)

______________________________________________________________________________________________

© 2010 - 2018 by GAMMA Soft.
