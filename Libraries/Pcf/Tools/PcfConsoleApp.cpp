#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    static void Main(const Array<string>& args) {
      //Console::WriteLine("Hello, World!");

      int counter = 0;
      TimerCallback tc = pcf_delegate(const object&) {
        Debug::WriteLine("ThreadId = {0}, counter= {1}", Thread::CurrentThread().ManagedThreadId, ++counter);
      };

      Timer timer(tc, 100, 100);
      Console::ReadKey(true);
    }
  };
}

pcf_startup (Examples::Program)
