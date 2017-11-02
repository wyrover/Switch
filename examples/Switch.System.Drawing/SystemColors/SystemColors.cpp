#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Color color = SystemColors::Control;
      Console::WriteLine("color = {0}", color);
      Console::WriteLine("Argb = 0x{0:X}", color.ToArgb());
      Console::WriteLine("Alpha = {0}", color.A);
      Console::WriteLine("Red = {0}", color.R);
      Console::WriteLine("Green = {0}", color.G);
      Console::WriteLine("Blue = {0}", color.B);
      Console::WriteLine();

      color = SystemColors::ActiveCaptionText;
      Console::WriteLine("color = {0}", color);
      Console::WriteLine("Argb = 0x{0:X}", color.ToArgb());
      Console::WriteLine("Alpha = {0}", color.A);
      Console::WriteLine("Red = {0}", color.R);
      Console::WriteLine("Green = {0}", color.G);
      Console::WriteLine("Blue = {0}", color.B);
      Console::WriteLine();
    }
  };
}

_startup(Examples::Program)

// This code can produces the following output:
//
// color = Color [Control]
// Argb = 0xFFE2E2E2
// Alpha = 255
// Red = 226
// Green = 226
// Blue = 226
//
// color = Color [ActiveCaptionText]
// Argb = 0xFF000000
// Alpha = 255
// Red = 0
// Green = 0
// Blue = 0
// 
