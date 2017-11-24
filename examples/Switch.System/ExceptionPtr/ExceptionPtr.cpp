#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      ExceptionPtr exceptionPtr;
      
      Thread thread(ThreadStart(_delegate {
        try {
          throw ArgumentNullException("Ouch there are an error !", _caller);
        } catch (...) {
          exceptionPtr = ExceptionPtr::CurrentException();
        }
      }));
      thread.Start();
      thread.Join();
      
      if (exceptionPtr) {
        try {
          exceptionPtr.Rethrow();
        } catch (const ArgumentNullException& exception) {
          Console::WriteLine(exception.Message);
        }
      }
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Ouch there are an error !
