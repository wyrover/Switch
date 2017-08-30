#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Clear the screen, then save the top and left coordinates.
      Console::Clear();
      origRow = Console::CursorTop;
      origCol = Console::CursorLeft;
      
      // Draw the left side of a 5x5 rectangle, from top to bottom.
      WriteAt("+", 0, 0);
      WriteAt("|", 0, 1);
      WriteAt("|", 0, 2);
      WriteAt("|", 0, 3);
      WriteAt("+", 0, 4);
      
      // Draw the bottom side, from left to right.
      WriteAt("-", 1, 4); // shortcut: WriteAt("---", 1, 4)
      WriteAt("-", 2, 4); // ...
      WriteAt("-", 3, 4); // ...
      WriteAt("+", 4, 4);
      
      // Draw the right side, from bottom to top.
      WriteAt("|", 4, 3);
      WriteAt("|", 4, 2);
      WriteAt("|", 4, 1);
      WriteAt("+", 4, 0);
      
      // Draw the top side, from right to left.
      WriteAt("-", 3, 0); // shortcut: WriteAt("---", 1, 0)
      WriteAt("-", 2, 0); // ...
      WriteAt("-", 1, 0); // ...
      //
      WriteAt("All done!", 0, 6);
      Console::WriteLine();
    }
  protected:
    static int origRow;
    static int origCol;
    
    static void WriteAt(const string& s, int x, int y) {
      try {
        Console::SetCursorPosition(origCol + x, origRow + y);
        Console::Write(s);
      } catch (const ArgumentOutOfRangeException& e) {
        Console::Clear();
        Console::WriteLine(e.Message);
      }
    }
  };
  
  int Program::origRow = 0;
  int Program::origCol = 0;
}

sw_startup (Examples::Program)

// This code produces the following output:
//
// +---+
// |   |
// |   |
// |   |
// +---+
//
// All done!
