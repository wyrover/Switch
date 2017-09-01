#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Point location = {10, 235};
      Console::WriteLine("location = {0}", location);
      
      location.X += 20;
      location.Y -= 15;
      Console::WriteLine("location = {0}", location);
      
      location = Point(10, 10) + Point(20, 50);
      Console::WriteLine("location = {0}", location);
      
      location.Offset({70, 140});
      Console::WriteLine("location = {0}", location);
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// location = {X=10,Y=235}
// location = {X=30,Y=220}
// location = {X=30,Y=60}
// location = {X=100,Y=200}
