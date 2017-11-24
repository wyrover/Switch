#include <Switch/Switch>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      int index = 0;
      object sync;
      Thread thread((ParameterizedThreadStart)Profile::LockThread);
      thread.Name = "LockThread";
      thread.Start(sync);
      
      Stopwatch stopWatch;
      stopWatch.Start();
      while (index < Profile::CountMax()) {
        _lock(sync) {
          int cpt = Profile::Counter;
          if (cpt != Profile::Counter)
            Console::WriteLine("cpt != Counter : {0}", cpt + Profile::Counter);
          index++;
        }
      }
      stopWatch.Stop();
      thread.Join();
      
      Console::WriteLine("Lock Duration : {0}", stopWatch.Elapsed());
    }
    
  private:
    class Profile : public object {
    public:
      static int CountMax() { return 10000; }
      static int Counter;
      
      static void LockThread(const Object& sync) {
        for (int index = 0; index < CountMax(); index++) {
          _lock(sync)
          Counter++;
        }
      }
    };
  };
  int Program::Profile::Counter = 0;
}

_startup(Examples::Program);

// This code produces the following output :
//
// Lock Duration : 00:00:00.1326642
