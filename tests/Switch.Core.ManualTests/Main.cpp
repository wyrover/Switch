#include <Switch/Startup.hpp>
#include <Switch/System/Collections/ArrayList.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Threading/Monitor.hpp>
#include <Switch/System/Guid.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Collections::ArrayList items = {"One", 2, TimeSpan::FromSeconds(3), Version(1, 2, 3), .5, Guid::NewGuid()};
      for (auto item : items)
        Console::WriteLine(item);

      Console::WriteLine("Many args {0} {1}", 12, .5);
    }
  };
}

startup_(Examples::Program);
