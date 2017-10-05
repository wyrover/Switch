#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("BackgroundColor = {0}", Console::BackgroundColor);
      Console::WriteLine("ForegroundColor = {0}", Console::ForegroundColor);
      Console::WriteLine("BufferHeight = {0}", Console::BufferHeight);
      Console::WriteLine("BufferWidth = {0}", Console::BufferWidth);
      Console::WriteLine("CapsLock = {0}", Console::CapsLock);
      Console::WriteLine("CursorLeft = {0}", Console::CursorLeft);
      Console::WriteLine("CursorSize = {0}", Console::CursorSize);
      Console::WriteLine("CursorTop = {0}", Console::CursorTop);
      Console::WriteLine("CursorVisible = {0}", Console::CursorVisible);
      Console::WriteLine("ForegroundColor = {0}", Console::ForegroundColor);
      Console::WriteLine("IsErrorRedirected = {0}", Console::IsErrorRedirected);
      Console::WriteLine("IsInputRedirected = {0}", Console::IsInputRedirected);
      Console::WriteLine("IsOutputRedirected = {0}", Console::IsOutputRedirected);
      Console::WriteLine("KeyAvailable = {0}", Console::KeyAvailable);
      Console::WriteLine("LargestWindowHeight = {0}", Console::LargestWindowHeight);
      Console::WriteLine("LargestWindowWidth = {0}", Console::LargestWindowWidth);
      Console::WriteLine("Title = {0}", Console::Title);
      Console::WriteLine("TreatControlCAsInput = {0}", Console::TreatControlCAsInput);
      Console::WriteLine("WindowHeight = {0}", Console::WindowHeight);
      Console::WriteLine("WindowLeft = {0}", Console::WindowLeft);
      Console::WriteLine("WindowTop = {0}", Console::WindowTop);
      Console::WriteLine("WindowWidth = {0}", Console::WindowWidth);
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!
