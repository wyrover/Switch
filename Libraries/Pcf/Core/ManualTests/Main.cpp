#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    template<size_t Size>
    using CharArray = std::array<char, Size>;
    
    static void Main() {
      Console::WriteLine("Hello, World!");
      
      std::vector<int> v(100);
      
      v.data()[5] = 5;
      
      
      CharArray<9> umId  = {{0}};
      Console::WriteLine("umId = {0}", umId.data());
      strncpy(umId.data(), "Hello, world", umId.size()-1);
      Console::WriteLine("umId = {0}", umId.data());
      
    }
  };
}

pcf_startup (Examples::Program)
