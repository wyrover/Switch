#include <Switch/Switch>

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
        
        _using (StreamWriter sw(path)) {
          sw.WriteLine("This");
          sw.WriteLine("is some text");
          sw.WriteLine("to test");
          sw.WriteLine("Reading");
        }
        
        _using (StreamReader sr(path)) {
          //This allows you to do one Read operation.
          Console::WriteLine(sr.ReadToEnd());
        }
      } catch (const Exception& e) {
        Console::WriteLine("The process failed: {0}", e);
      }
    }
  };
}

_startup(Examples::Program)

// This code produces the following output:
//
// This
// is some text
// to test
// Reading
