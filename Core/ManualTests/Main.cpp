#include <Pcf/System/Linq/Linq.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      int first[] = { 42, 23, 66, 13, 11, 7, 24, 10 };
      int second[] = { 67, 22, 13, 23, 41, 66, 6, 7, 10 };

      auto query = from<int>(first)
                   | intersect<int>(second)
                   | where<int>([](int i) {return i != 13;})
                   | orderby<descending, int>([](int i) {return i % 2 == 0;});

      /*
      for (int item : *query)
        Console::WriteLine(item);
       */
      
      Console::WriteLine(query);
    }
  };
}

pcf_startup (ManualTests::Program)
