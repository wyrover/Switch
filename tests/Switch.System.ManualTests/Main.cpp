#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Net/IPAddress.hpp>
#include <Switch/System/Threading/Monitor.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/System/Threading/Tasks/Task.hpp>

using namespace System;
using namespace System::Threading;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
    }
  };
}

_startup(ManualTests::Program)
