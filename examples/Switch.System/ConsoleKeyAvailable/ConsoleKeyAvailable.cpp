#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      ConsoleKeyInfo cki;

      do {
        Console::WriteLine("\nPress a key to display; press the 'x' key to quit.");

        // Your code could perform some useful task in the following loop. However,
        // for the sake of this example we'll merely pause for a quarter second.

        while (Console::KeyAvailable == false)
          Thread::Sleep(250); // Loop until input is entered.

        cki = Console::ReadKey(true);
        Console::WriteLine("You pressed the '{0}' key.", cki.Key);
      } while (cki.Key != ConsoleKey::X);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// This example produces results similar to the following:
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'H' key.
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'E' key.
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'PageUp' key.
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'DownArrow' key.
//
// Press a key to display; press the 'x' key to quit.
// You pressed the 'X' key.
