#include <Switch/Switch>

using namespace System;

namespace Test {
  class Program {
  public:
    /// @brief The main entry point for the application.
    static void Main() {
      UniquePtr<string> str = MakeUnique<string>("Hello world!");
      Console::WriteLine("str = {0}", str.ToString());
      Console::WriteLine(*str);
      str = MakeUnique<string>("another string !");
      Console::WriteLine("str = {0}", str.ToString());
      Console::WriteLine(*str);
      
      UniquePtr<string> str2 = str;
      Console::WriteLine("str2 = {0}", str2.ToString());
      Console::WriteLine("str = {0}", str.ToString());
      Console::WriteLine(*str2);
      str2 = null;
      Console::WriteLine("str2 = {0}", str2.ToString());
      SharedPtr<string> sp = ref_new<string>("Test sp");
      Console::WriteLine("sp = {0}", sp.ToString());
      UniquePtr<int> a = MakeUnique<int>(234);
      Console::WriteLine("a = {0}", a.ToString());
      SharedPtr<string> b;
      Console::WriteLine("b = {0}", b.ToString());
    }
  };
}

_startup (Test::Program)

// This code produces the following output:
//
// str = Switch::UniquePtr [Pointer=140704215999824]
// Hello world!
// str = Switch::UniquePtr [Pointer=140704216001168]
// another string !
// str2 = Switch::UniquePtr [Pointer=140704216001168]
// str = Switch::UniquePtr [Pointer=null]
// another string !
// str2 = Switch::UniquePtr [Pointer=null]
// sp = Switch::RefPtr [Pointer=140704215999520, UseCount=1]
// a = Switch::UniquePtr [Pointer=140704215998368]
// b = Switch::RefPtr [Pointer=null]
