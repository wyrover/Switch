#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Net/IPAddress.hpp>
#include <Switch/System/Threading/Monitor.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/System/Threading/Tasks/Task.hpp>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      enum class Number {Nine = 9};
      Write("1", " ", "2"_s, " ", 3, " ", 4_s, " ", .5, " ", Version(6, 0), " ", Net::IPAddress(7), " " , '8', " ", Number::Nine);
      Console::WriteLine();
    }
    
    static void Write() {}

    template<typename Arg, typename ...Args>
    static void Write(const Arg& arg, const Args& ...args) {
      Console::Write(arg);
      Write(args...);
    }
  };
}

_startup (Examples::Program)
