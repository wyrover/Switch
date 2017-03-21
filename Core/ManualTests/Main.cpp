#include <Pcf/Core.h>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Action<const object&> action = pcf_delegate(const object&) {
        static int counter = 0;
        Console::WriteLine("counter = {0}, guid = {1}", ++counter, Guid::NewGuid());
      };

      System::Threading::Timer timer(action, 10, 10);
      System::Threading::Thread::Sleep(System::Threading::Timeout::Infinite);
    }
  };
}

pcf_startup (Examples::Program)
