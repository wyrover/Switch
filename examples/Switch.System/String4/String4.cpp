#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string sentence = "This sentence has five words.";
      // Extract the second word.
      int startPosition = sentence.IndexOf(" ") + 1;
      string word2 = sentence.Substring(startPosition, sentence.IndexOf(" ", startPosition) - startPosition);
      Console::WriteLine("Second word: {0}", word2);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Second word: sentence
