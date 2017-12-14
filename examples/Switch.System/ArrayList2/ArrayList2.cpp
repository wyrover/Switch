#include <Switch/Switch>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    static void Main() {
      ArrayList arrayList = {42, "This is a string", DayOfWeek::Wednesday, "Another string", Uri("https://www.gammasoft71.wixsite.com/switch"), 4.2f, TimeSpan(2, 25, 43)};

      Console::WriteLine("arrayList = [{0}]", string::Join(", ", arrayList));
      Console::WriteLine();

      for (auto item : arrayList)
        if (is<string>(item))
          Console::WriteLine("\"{0}\"", as<string>(item).ToUpper());
        else
          Console::WriteLine("{0}", item);
    }
  };
}

_startup(Examples::Program);

// This code example produces the following output:
//
// arrayList = [42, This is a string, Wednesday, Another string, https://www.gammasoft71.wixsite.com/switch, 4.2, 02:25:43]
//
// 42
// "THIS IS A STRING"
// Wednesday
// "ANOTHER STRING"
// https://www.gammasoft71.wixsite.com/switch
// 4.2
// 02:25:43
