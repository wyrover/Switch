#include <Switch/Switch>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string sentence = "the quick brown fox jumps over the lazy dog";
      
      // Split the string into individual words.
      Array<string> words = sentence.Split(' ');
      
      // Prepend each word to the beginning of the
      // new sentence to reverse the word order.
      string reversed = words.Agregate(_delegate(const string& workingSentence, const string& next) {
        return next + " " + workingSentence;
      });
      
      Console::WriteLine(reversed);
    }
  };
}

_startup (Examples::Program)

// This code produces the following output:
//
// dog lazy the over jumps fox brown quick the
//
