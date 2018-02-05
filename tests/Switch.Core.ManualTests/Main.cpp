#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Guid.hpp>
#include <Switch/System/Collections/Hashtable.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      auto item = new_<Version>(1, 2, 3);
      auto item2 = item;
      $<Version> item3 = item2;
      item = new_<Version>(4, 5, 6);

      Console::WriteLine(item3.ToObject());
      auto itemm = new_ < $<Version >> (new_<Version>(7, 8, 9));
      Console::WriteLine(itemm.ToObject().ToObject());
    }
  };
}

startup_(Examples::Program);
