#include <Pcf/System/Collections/ArrayList.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/System/Uri.hpp>
#include <Pcf/Event.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace System::Collections;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      for(auto c : "yfiumefreddo"_s)
        Console::Write("{0:b}", byte(c));
      Console::WriteLine();
    }
  };
}

pcf_startup (ManualTests::Program)
