#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
      std::shared_ptr<int> i1 = std::make_shared<int>(42);
      std::shared_ptr<int> i2 = std::move(i1);
      Console::WriteLine("i1 = {0}", i1.use_count());
      Console::WriteLine("i2 = {0}", i2.use_count());

      SharedPointer<int> i3 = SharedPointer<int>::Create(42);
      SharedPointer<int> i4 = Move(i3);
      Console::WriteLine("i3 = {0}", i3.GetUseCount());
      Console::WriteLine("i4 = {0}", i4.GetUseCount());

    }
  };
}

pcf_startup (Examples::Program)
