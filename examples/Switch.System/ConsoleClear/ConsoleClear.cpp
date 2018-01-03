#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      // Save colors so they can be restored when use finishes input.
      ConsoleColor dftForeColor = Console::ForegroundColor;
      ConsoleColor dftBackColor = Console::BackgroundColor;
      bool continueFlag = true;
      Console::Clear();

      do {
        ConsoleColor newForeColor = ConsoleColor::White;
        ConsoleColor newBackColor = ConsoleColor::Black;

        char32 foreColorSelection = GetKeyPress("Select Text Color (B for Blue, R for Red, Y for Yellow): ", Array<char32> { 'B', 'R', 'Y' });
        switch (foreColorSelection) {
        case 'B':
        case 'b': newForeColor = ConsoleColor::DarkBlue; break;
        case 'R':
        case 'r': newForeColor = ConsoleColor::DarkRed; break;
        case 'Y':
        case 'y': newForeColor = ConsoleColor::DarkYellow; break;
        }

        Char backColorSelection = GetKeyPress("Select Background Color (W for White, G for Green, M for Magenta): ", Array<char32> { 'W', 'G', 'M' });
        switch (backColorSelection) {
        case 'W':
        case 'w': newBackColor = ConsoleColor::White; break;
        case 'G':
        case 'g': newBackColor = ConsoleColor::Green; break;
        case 'M':
        case 'm': newBackColor = ConsoleColor::Magenta; break;
        }

        Console::WriteLine();
        Console::Write("Enter a message to display: ");
        String textToDisplay = Console::ReadLine();
        Console::WriteLine();
        Console::ForegroundColor = newForeColor;
        Console::BackgroundColor = newBackColor;
        Console::WriteLine(textToDisplay);
        Console::WriteLine();
        if (Char::ToUpper(GetKeyPress("Display another message (Y/N): ", Array<char32> { 'Y', 'N' })) == 'N')
          continueFlag = false;

        // Restore the default settings and clear the screen.
        Console::ForegroundColor = dftForeColor;
        Console::BackgroundColor = dftBackColor;
        Console::Clear();
      } while (continueFlag);
    }

  private:
    static char32 GetKeyPress(String msg, const Array<char32>& validChars) {
      ConsoleKeyInfo keyPressed;
      bool valid = false;

      Console::WriteLine();
      do {
        Console::Write(msg);
        keyPressed = Console::ReadKey();
        Console::WriteLine();
        if (Array<>::Exists<char32>(validChars, delegate_(const char32 & ch) {return Char(ch).Equals(Char::ToUpper(keyPressed.KeyChar));}))
        valid = true;

      } while (! valid);
      return keyPressed.KeyChar;
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// >ConsoleBeep
// Usage: Enter the number of times (between 1 and 9) to beep
//
// >ConsoleBeep 9
// Beep number 1.
// Beep number 2.
// Beep number 3.
// Beep number 4.
// Beep number 5.
// Beep number 6.
// Beep number 7.
// Beep number 8.
// Beep number 9.
