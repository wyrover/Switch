#include <Pcf/Startup.hpp>
#include <Pcf/System/Array.hpp>
#include <Pcf/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<int> a1 = {1, 2, 3, 4, 5, 6, 7, 8};
      Console::WriteLine("a1(0) = {0}", a1(0));
      Console::WriteLine("a1(1) = {0}", a1(1));
      Console::WriteLine("a1(2) = {0}", a1(2));
      Console::WriteLine("a1(3) = {0}", a1(3));
      Console::WriteLine("a1(4) = {0}", a1(4));
      Console::WriteLine("a1(5) = {0}", a1(5));
      Console::WriteLine("a1(6) = {0}", a1(6));
      Console::WriteLine("a1(7) = {0}", a1(7));
      
      Array<int, 2> a2 = {{10, 20, 30, 40}, {50, 60, 70, 80}};
      Console::WriteLine("a2(0, 0) = {0}", a2(0, 0));
      Console::WriteLine("a2(0, 1) = {0}", a2(0, 1));
      Console::WriteLine("a2(0, 2) = {0}", a2(0, 2));
      Console::WriteLine("a2(0, 3) = {0}", a2(0, 3));
      Console::WriteLine("a2(1, 0) = {0}", a2(1, 0));
      Console::WriteLine("a2(1, 1) = {0}", a2(1, 1));
      Console::WriteLine("a2(1, 2) = {0}", a2(1, 2));
      Console::WriteLine("a2(1, 3) = {0}", a2(1, 3));
      
      Array<int, 3> a3 = {{{100, 200}, {300, 400}}, {{500, 600}, {700, 800}}};
      Console::WriteLine("a3(0, 0, 0) = {0}", a3(0, 0, 0));
      Console::WriteLine("a3(0, 0, 1) = {0}", a3(0, 0, 1));
      Console::WriteLine("a3(0, 1, 0) = {0}", a3(0, 1, 0));
      Console::WriteLine("a3(0, 0, 1) = {0}", a3(0, 1, 1));
      Console::WriteLine("a3(1, 0, 0) = {0}", a3(1, 0, 0));
      Console::WriteLine("a3(1, 0, 1) = {0}", a3(1, 0, 1));
      Console::WriteLine("a3(1, 1, 0) = {0}", a3(1, 1, 0));
      Console::WriteLine("a3(1, 1, 1) = {0}", a3(1, 1, 1));
    }
  };
}

pcf_startup (Examples::Program)

