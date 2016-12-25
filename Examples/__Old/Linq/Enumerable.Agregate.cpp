#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;

int main(int argc, char* argv[]) {
  string sentence = "the quick brown fox jumps over the lazy dog";
  
  // Split the string into individual words.
  Array<string> words = sentence.Split(' ');
  
  // Prepend each word to the beginning of the
  // new sentence to reverse the word order.
  string reversed = words.Agregate([&](const string& workingSentence, const string& next) {
    return next + " " + workingSentence;
  });
  
  Console::WriteLine(reversed);
}

// This code produces the following output:
//
// dog lazy the over jumps fox brown quick the
//
