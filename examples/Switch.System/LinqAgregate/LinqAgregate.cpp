#include <Switch/Switch>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Split two string into individual words.
      Array<string> words1 = "the quick brown fox jumps"_s.Split(' ');
      Array<string> words2 = "over the lazy dog"_s.Split(' ');

      // Prepend each word to the beginning of the
      // new sentence to reverse the word order.
      string reversed = from<string>(words1)
        | concat<string>(words2)
      | agregate<string>(_delegate(const string & workingSentence, const string & next) {return next + " " + workingSentence;});

      Console::WriteLine(reversed);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// dog lazy the over jumps fox brown quick the
//
