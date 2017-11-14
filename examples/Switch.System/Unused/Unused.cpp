#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    static void Main() {
      int counter = 42;
      const char* value = "Forty two";
      double pi = 3.14159265358979323846;
      
      // Remove "unused variable" compiler warnings...
      // f you comment on the next line, three warnings will appear during the build.
      Unused(counter, value, pi);
    }
  };
}

_startup(Examples::Program);
