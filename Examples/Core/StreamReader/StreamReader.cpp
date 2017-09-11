#include <Switch/Switch>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      try {
        // Create an instance of StreamReader to read from a file.
        // The _using statement also closes the StreamReader.
        _using (StreamReader sr("TestFile.txt")) {
          string line;
          // Read and display lines from the file until the end of
          // the file is reached.
          while (!sr.EndOfStream()) {
            line = sr.ReadLine();
            Console::WriteLine(line);
          }
        }
      } catch (const Exception& e) {
        // Let the user know what went wrong.
        Console::WriteLine("The file could not be read:");
        Console::WriteLine(e.Message);
      }
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// This file is only present for
// a StreamReader class test.
