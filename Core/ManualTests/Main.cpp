#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Threading/Monitor.hpp>
#include <Switch/System/Threading/Thread.hpp>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Threading::Thread thread1(ThreadStart(_delegate {
        _lock ("myLock"_s) {
          for (int counter = 0; counter < 10; counter++) {
            Console::WriteLine("thread = {0}, counter = {1}", Thread::CurrentThread().ManagedThreadId, counter);
            Thread::Yield();
          }
        }
      }));
      
      System::Threading::Thread thread2(ThreadStart(_delegate {
        _lock ("myLock"_s) {
          for (int counter = 0; counter < 10; counter++) {
            Console::WriteLine("  thread = {0}, counter = {1}", Thread::CurrentThread().ManagedThreadId, counter);
            Thread::Yield();
          }
        }
      }));
      
      thread1.Start();
      thread2.Start();
    }
  };
}

_startup (Examples::Program)
