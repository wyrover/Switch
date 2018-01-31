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
      Console::WriteLine("Hello, World!");

      Hashtable hash;
      hash["Test"] = 42;
      hash[42] = "Test";
      hash[.5] = Guid::NewGuid();

      for (auto item : hash)
        Console::WriteLine(item);

      Console::WriteLine();
      Console::WriteLine(hash[.5]);
      Console::WriteLine(hash["Test"]);

    }
  };
}

startup_(Examples::Program);
