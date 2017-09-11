#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Rectangle bounds = {10, 10, 200, 300};
      Console::WriteLine("bounds = {0}", bounds);
      Console::WriteLine("X = {0}", bounds.X);
      Console::WriteLine("Y = {0}", bounds.Y);
      Console::WriteLine("Width = {0}", bounds.Width);
      Console::WriteLine("Height = {0}", bounds.Height);
      Console::WriteLine("Location = {0}", bounds.Location);
      Console::WriteLine("Left = {0}", bounds.Left);
      Console::WriteLine("Top = {0}", bounds.Top);
      Console::WriteLine("Right = {0}", bounds.Right);
      Console::WriteLine("Bottom = {0}", bounds.Bottom);
      Console::WriteLine("Location = {0}", bounds.Location);
      Console::WriteLine("Size = {0}", bounds.Size);
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// bounds = {X=10,Y=10,Width=200,Height=300}
// X = 10
// Y = 10
// Width = 200
// Height = 300
// Left = 10
// Top = 10
// Right = 210
// Bottom = 310
// Location = {X=10,Y=10}
// Size = {Width=200, Height=300}

