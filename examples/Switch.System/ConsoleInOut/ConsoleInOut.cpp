#include <Switch/Switch>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      TextReader& tIn = Console::In;
      TextWriter& tOut = Console::Out;
      
      tOut.WriteLine("Hola Mundo!");
      tOut.Write("What is your name: ");
      String name = tIn.ReadLine();
      
      tOut.WriteLine("Buenos Dias, {0}!", name);
    }
  };
}

_startup(Examples::Program)

// This code produces the following output:
//
// Hola Mundo!
// What is your name: James
// Buenos Dias, James!
