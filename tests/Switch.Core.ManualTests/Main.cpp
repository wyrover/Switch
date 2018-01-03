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
      $<Threading::Thread> thread = new_<Threading::Thread>(Threading::ThreadStart(delegate_ {
        
      }));
    }
  };
}

startup_(Examples::Program);
