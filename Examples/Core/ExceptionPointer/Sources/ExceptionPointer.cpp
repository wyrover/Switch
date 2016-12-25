#include <Pcf/Pcf>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      ExceptionPointer exceptionPointer;
      
      Thread thread(ThreadStart(pcf_delegate {
        try {
          throw ArgumentNullException("Ouch there are an error !", pcf_current_information);
        } catch(...) {
          exceptionPointer = ExceptionPointer::CurrentException;
        }
      }));
      thread.Start();
      thread.Join();
      
      if (exceptionPointer) {
        try {
          exceptionPointer.Rethrow();
        } catch(const ArgumentNullException& exception) {
          Console::WriteLine(exception.Message);
        }
      }
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Ouch there are an error !
