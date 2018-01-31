#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Guid.hpp>
#include <Switch/System/Collections/Hashtable.hpp>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Hashtable items;
      items["Test"] = 42;
      items[42] = "Test";
      items[.5] = Guid::NewGuid();

      for (auto item : items)
        Console::WriteLine("[{0}, {1}]", item.Key, item.Value);

      Console::WriteLine();
      Console::WriteLine(items[.5]);
      Console::WriteLine(items["Test"]);
    }
  };
}

startup_(Examples::Program);
