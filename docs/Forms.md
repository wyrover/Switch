![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

This tutorial describe the basic steps that you must complete to create and run a Windows Forms application from the command line.

# Create Windows Form

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

5. Add startup_ command to specity to Switch the class that contains the main method.

```c++
startup_ (Form1);
```

## To create the CMakeLists.txt

1. Add the cmake minimum version required.

```cmake
cmake_minimum_required(VERSION 3.2)
```

2. Set the project name and add Switch package.

```cmake
Project(Form1)
find_package(Switch REQUIRED)
```

3. Add build rules for the he project.

```cmake
add_executable(Form1 ${SWITCH_GUI} Form1.cpp)
target_link_libraries(Form1 Switch.System.Windows.Forms)
```

## To compile and run the application on Windows

1. At the Command prompt, navigate to the directory you created the Form1 class and CMakeLists.
2. Create build directory build.

```shell
mkdir build
cd build
```

3. Generate the solution.

```shell
cmake .. -DCMAKE_INSTALL_PREFIX=c:/usr/local
```

4. Compile the form.

```shell
cmake --build .
```

5. At the command prompt, type:

```shell
Debug\Form1.exe
```

## To compile and run the application on macOS

1. At the Terminal, navigate to the directory you created the Form1 class and CMakeLists.
2. Create build directory build.

```shell
mkdir build
cd build
```

3. Generate the project.

```shell
cmake ..
```

4. Compile the form.

```shell
cmake --build .
```

5. At the command prompt, type:

```shell
open ./Form1.app
```

## To compile and run the application on Linux

1. At the Terminal, navigate to the directory you created the Form1 class and CMakeLists.
2. Create build directory build.

```shell
mkdir build
cd build
```

3. Generate the project.

```shell
cmake ..
```

4. Compile the form.

```shell
cmake --build .
```

5. At the command prompt, type:

```shell
./Form1
```

# Adding a Control and Handling an Event

The previous procedure steps demonstrated how to just create a basic Windows Form that compiles and runs. The next procedure will show you how to create and add a control to the form, and handle an event for the control.

In addition to understanding how to create Windows Forms applications, you should understand event-based programming and how to handle user input.

## To declare a button control and handle its click event

1. Declare a button control named button1.
2. n the constructor, create the button and set its Size, Location and Text properties.
3. Add the button to the form.

The following code example demonstrates how to declare the button control.

```c++
public:
  Button button1;
  Form1() {
    button1.Size = System::Drawing::Size(40, 40);
    button1.Location = System::Drawing::Point(30, 30);
    button1.Text = "Click\nme";
    this->Controls().Add(button1);
    button1.Click += EventHandler(*this, &Form1::button1_Click);
  }
```

4. Create a method to handle the Click event for the button.
5. In the click event handler, display a MessageBox with the message, "Hello World".

The following code example demonstrates how to handle the button control's click event.

```c++
private:
  void button1_Click(const object& sender, const EventArgs& e) {
    MessageBox::Show("Hello World");
  }
```

6. Associate the Click event with the method you created.

The following code example demonstrates how to associate the event with the method.

```c++
button1.Click += EventHandler(*this, &Form1::button1_Click);
```

7. Compile and run the application as described in the previous tutorial.


# Example

Following code example is the complete example from the previous tutorial.

Form1.cpp:

```c++
#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace FormWithButton {
  class Form1 : public Form {
  public:
    Button button1;
    Form1() {
      button1.Size = System::Drawing::Size(40, 40);
      button1.Location = System::Drawing::Point(30, 30);
      button1.Text = "Click\nme";
      this->Controls().Add(button1);
      button1.Click += EventHandler(*this, &Form1::button1_Click);
    }

    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

  private:
    void button1_Click(const object& sender, const EventArgs& e) {
      MessageBox::Show("Hello World");
    }
  };
}

startup_ (FormWithButton::Form1);
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(Form1)
find_package(Switch REQUIRED)

add_executable(Form1 ${SWITCH_GUI} Form1.cpp)
target_link_libraries(Form1 Switch.System.Windows.Forms)
```

# See also
​
Other Resources

* [Tutorials](Tutorials.md)

______________________________________________________________________________________________

© 2010 - 2017 by Gammasoft.

<!--https://docs.microsoft.com/en-us/dotnet/framework/winforms/how-to-create-a-windows-forms-application-from-the-command-line-->
