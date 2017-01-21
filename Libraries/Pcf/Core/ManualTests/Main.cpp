#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
      ArrayList al = {"Hello"_s.ToUpper(), 42, 12345_s, 4.2, Version(10, 7, 4), Guid::NewGuid(), Environment::CurrentDirectory, true, ConsoleColor::DarkBlue};
      for (auto item : al)
        Console::WriteLine(item);
      
      Nullable<int> n1;
      Nullable<int> n2 = 42;
      Console::WriteLine("n1 = {0}", n1.HasValue ? n1.ToString() : "<empty>");
      Console::WriteLine("n2 = {0}", n2.HasValue ? n2.ToString() : "<empty>");
      
      //std::shared_ptr<IComparable> s = std::make_shared<string>("Value");
      SharedPointer<IComparable> s = SharedPointer<IComparable>::Create<string>("Value");
    }
  };
}

pcf_startup (Examples::Program)
