#include <Pcf/Pcf>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      string path = "MyTest.txt";
      
      try {
        if (File::Exists(path)) {
          File::Delete(path);
        }
        
        pcf_using (StreamWriter sw(path)) {
          sw.WriteLine("This");
          sw.WriteLine("is some text");
          sw.WriteLine("to test");
          sw.WriteLine("Reading");
        }
        
        pcf_using (StreamReader sr(path)) {
          while (sr.Peek() >= 0) {
            Console::WriteLine(sr.ReadLine());
          }
        }
      } catch (const Exception& e) {
        Console::WriteLine("The process failed: {0}", e);
      }
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// This
// is some text
// to test
// Reading
