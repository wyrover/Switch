#include <Pcf/Startup.hpp>
#include <Pcf/System/Array.hpp>
#include <Pcf/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<int> a = {42, 84, 21};
      auto b = Move(a);
      Console::WriteLine("a = {{{0}}} and b = {{{1}}}", string::Join(", ", a), string::Join(", ", b));
    }
  };
}

pcf_startup (Examples::Program)

