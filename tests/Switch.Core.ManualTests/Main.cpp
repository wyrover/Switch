#include <Switch/Startup.hpp>
#include <Switch/System/Boolean.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Guid.hpp>
#include <Switch/System/Threading/Timeout.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      int counter = 2000;
      $<Threading::Thread> thread = new_<Threading::Thread>(Threading::ThreadStart(delegate_ {
        while (true) {
          Console::WriteLine("counter = {0}", ++ counter);
          System::Threading::Thread::Sleep(250);
        }
      }));
      thread->Start();

      System::Threading::Thread::Sleep(System::Threading::Timeout::InfiniteTimeSpan);
      thread->Join();
    }
  };
}

startup_(Examples::Program);
