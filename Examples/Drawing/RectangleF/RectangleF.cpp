#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      RectangleF bounds = {10.5f, 10.5f, 200.8f, 300.8f};
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

sw_startup (Examples::Program)

// This code produces the following output:
//
// bounds = {X=10.5,Y=10.5,Width=200.8,Height=300.8}
// X = 10.5
// Y = 10.5
// Width = 200.8
// Height = 300.8
// Left = 10.5
// Top = 10.5
// Right = 211.3
// Bottom = 311.3
// Location = {X=10.5,Y=10.5}
// Size = {Width=200.8, Height=300.8}
