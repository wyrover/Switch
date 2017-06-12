#include <Pcf/System/Collections/ArrayList.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/System/Uri.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace System::Collections;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      //Console::WriteLine("Hello, World!");
      ArrayList arrayList = {42, "This is a string", DayOfWeek::Wednesday, "Another string", Uri("http://www.gammasoft.com"), 4.2f};
      
      Console::WriteLine("arrayList = [{0}]", string::Join(", ", arrayList));
      Console::WriteLine();

      for(auto item : arrayList)
        if (is<string>(item))
          Console::WriteLine("\"{0}\"", as<string>(item).ToUpper());
        else
          Console::WriteLine("{0}", item);
    }
  };
}

pcf_startup (ManualTests::Program)
