#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    template<typename T>
    static void Print(const System::Collections::Generic::IEnumerable<T>& values) {
      for (const auto& value : values)
        Console::WriteLine(value);
      //Console::WriteLine("values.Length = {0}", values.Length);
    }
    
    static void Main() {
      Console::WriteLine("Hello, World!");
      //Array<int> vals = {1, 2, 3};
      Array<Guid> vals = {Guid::NewGuid(), Guid::NewGuid(), Guid::NewGuid(), Guid::NewGuid()};
      //Array<string> vals = {string("One"), string("Two"), string("Three")};
      Print(vals);
      
      Console::WriteLine("A={0}", int32('A'));
    }
  };
}

pcf_startup (Examples::Program)
