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
      Console::WriteLine("Time since boot : {0}", TimeSpan::FromMilliseconds(Environment::TickCount & Int32::MaxValue));
      Console::WriteLine("Timeout::Infinite : {0}", System::Threading::Timeout::Infinite);
      Console::WriteLine("Timeout::InfiniteTimeSpan {0}", System::Threading::Timeout::InfiniteTimeSpan);
      Console::WriteLine("TimeSpan::FromMilliseconds(-1) {0}", TimeSpan::FromMilliseconds(-1));
      Console::WriteLine("TimeSpan(-1) {0}", TimeSpan(-1));
    }
  };
}

startup_(Examples::Program);
