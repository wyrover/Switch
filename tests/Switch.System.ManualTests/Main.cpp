#define TRACE
#include <Switch/Startup.hpp>
#include <Switch/System/Media/SystemSounds.hpp>

using namespace System;
using namespace System::Threading;

namespace ManualTests {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Media::SystemSounds::Asterisk().Play();
    }
  };
}

startup_(ManualTests::Program);
