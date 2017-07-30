#include <Pcf/System/Linq/Linq.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> names = { "Burke", "Connor", "Frank", "Everett", "Albert", "George", "Harris", "David" };
      
      auto query = from<string>(names)
                   | where<string>([](string s) {return s.Length == 5;})
                   | orderby<string>([](string s) {return s;})
                   | select<string>([](string s) {return s.ToUpper();});
      
      for (string item : *query)
        Console::WriteLine(item);
    }
  };
}

pcf_startup (Examples::Program)

// This code example produces the following output:
//
// BURKE
// DAVID
// FRANK
