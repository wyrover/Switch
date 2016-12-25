#include <Corelib.h>

using namespace System;

namespace Test {
  class Program : public Object {
  public:
    static void Main(const Array<string>&) {
      var(t, Tuple<>::Create(25, string("My string")));

      Console::WriteLine("Tuple : " + t);
    }
  };
}

// Specify the Main entry point to System
InitMain(&Test::Program::Main);

// This code produces the following output:
//
// Tuple : (25, My string)
