#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Collections/Generic/SortedDictionary.hpp>

using namespace System;
using namespace System::Threading;

namespace ManualTests {
  enum class Color {
    Black, White, Red, Blue
  };

  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Collections::Generic::SortedDictionary<Color, string> values {{Color::Black, "Black"}, {Color::White, "White"}, {Color::Red, "Red"}, {Color::Blue, "Blue"}};
      for (auto value : values)
        Console::WriteLine(value);
    }
  };
}

startup_(ManualTests::Program);
