#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
  string sentence = "This sentence has five words.";
  // Extract the second word.
  int startPosition = sentence.IndexOf(" ") + 1;
  string word2 = sentence.Substring(startPosition, sentence.IndexOf(" ", startPosition) - startPosition);
  Console::WriteLine("Second word: {0}", word2);
}

// This code produces the following output:
//
// Second word: sentence
