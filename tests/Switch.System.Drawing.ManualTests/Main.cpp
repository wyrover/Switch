#define TRACE

#include <Windows.h>
#include <Switch/Undef.hpp>

#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Net/IPAddress.hpp>
#include <Switch/System/Threading/Monitor.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/System/Threading/Tasks/Task.hpp>
#include <Switch/System/BitConverter.hpp>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      byte value = 0;
      Console::WriteLine("value = {0}", _nameof(value));
      Console::WriteLine("value = {0}", _typeof(value));
      Console::WriteLine("value = {0}", value);
    }
  };
}

_startup (Examples::Program)
