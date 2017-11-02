#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      string output = String::Join(" ", *GetAlphabet(true).Where(_delegate(const string& letter) {return letter.CompareTo("M") >= 0;}));
      Console::WriteLine(output);
    }
    
  private:
    static List<string> GetAlphabet(bool upper) {
      List<string> alphabet;
      int charValue = upper ? 65 : 97;
      for (int ctr = 0; ctr <= 25; ctr++)
        alphabet.Add(Char(Convert::ToChar(charValue + ctr)).ToString());
      return alphabet;
    }
  };
}

_startup(Examples::Program)

// The example displays the following output:
//
// M N O P Q R S T U V W X Y Z
