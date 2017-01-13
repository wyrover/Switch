#include <Pcf/Pcf>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Net;
using namespace System::Threading;

namespace Examples {
  class Program {
  public:
    static void Main(const Array<string>& args) {
      Console::WriteLine("Hello, World!");
    }
  };
}

pcf_startup (Examples::Program)
