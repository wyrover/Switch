#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Size size = {200, 300};
      Console::WriteLine("size = {0}", size);

      size.Width += 50;
      size.Height -= 100;
      Console::WriteLine("size = {0}", size);

      size = Size(300, 300) + Point(200, 100);
      Console::WriteLine("size = {0}", size);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// size = {Width=200, Height=300}
// size = {Width=250, Height=200}
// size = {Width=500, Height=400}

