#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      List<Tuple<string, string, DateTime>> list;
      list.Add(Tuple<string, string, DateTime>("John", "Doe", DateTime()));
      list.Add(Tuple<string, string, DateTime>("Marilyn", "Monroe", DateTime(1926, 6, 1)));
      list.Add(Tuple<string, string, DateTime>("Neil", "Armstrong", DateTime(1930, 8, 5)));

      Console::WriteLine("Enumeration using foreach: ");
      for (auto item : list)
        Console::WriteLine("({0}, {1}, {2})", item.Item1, item.Item2, item.Item3().ToShortDateString());
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// Enumeration using foreach:
// (John, Doe, 01/01/0001)
// (Marilyn, Monroe, 1/06/1926)
// (Neil, Armstrong, 5/08/1930)
