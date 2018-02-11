#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Linq/Linq.hpp>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      auto names = { "Burke"_s, "Connor"_s, "Frank"_s, "Everett"_s, "Albert"_s, "George"_s, "Harris"_s, "David"_s };

      auto query = from_(names)
      where_(delegate_(string s) {return s.Length == 5;})
      orderby_(delegate_(string s) {return s;})
      select_(delegate_(string s) {return s.ToUpper();});

      for (auto item : *query)
        Console::WriteLine(item);
    }
  };
}

startup_(Examples::Program);

