#include <Pcf/Core.h>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    static void Main() {
      //Console::WriteLine("Hello, World!");
      Console::WriteLine("{0}", DateTime(1601, 1, 5));
      
      delegate<void, const string&> dlgA = pcf_delegate(const string& s) {
        Console::WriteLine("LA = {0}", s);
      };
      
      delegate<void, const string&> dlgB = pcf_delegate(const string& s) {
        Console::WriteLine("LB = {0}", s);
      };
      
      delegate<void, const string&> dlgC = pcf_delegate(const string& s) {
        Console::WriteLine("LC = {0}", s);
      };
      
      class Fct {
      public:
        Fct(const string& id): id(id) {}
        void operator()(const string& s) {
          Console::WriteLine("{0} = {0}", id, s);
        }
        
      private:
        string id;
      };
      
      delegate<void, const string&> all;
      all += dlgA;
      all += dlgB;
      all += dlgC;
      
      Fct fctA("FA");
      Fct fctB("FB");
      Fct fctC("FC");
      
      all += fctA;
      all += fctB;
      all += fctC;
      
      all -= dlgB;
      all -= fctB;
      
      all("Test");
      
    }
  };
}

pcf_startup (Examples::Program)
