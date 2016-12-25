#include <Pcf/Pcf>

using namespace System;
using namespace System::Text;

int main(int argc, char* argv[]) {
  int nAlphabeticChars = 0;
  int nWhitespace = 0;
  int nPunctuation = 0;
  StringBuilder sb("This is a simple sentence.");
  
  for (int ctr = 0; ctr < sb.Length; ctr++) {
    char32 ch = sb[ctr];
    if (Char::IsLetter(ch)) { nAlphabeticChars++;  continue; }
    if (Char::IsWhiteSpace(ch)) { nWhitespace++;  continue; }
    if (Char::IsPunctuation(ch)) nPunctuation++;
  }
  
  Console::WriteLine("The sentence '{0}' has:", sb);
  Console::WriteLine("   Alphabetic characters: {0}", nAlphabeticChars);
  Console::WriteLine("   Whitespace characters: {0}", nWhitespace);
  Console::WriteLine("   Punctuation characters: {0}", nPunctuation);
}

// The example displays the following output:
//
// The sentence 'This is a simple sentence.' has:
//    Alphabetic characters: 21
//    Whitespace characters: 4
//    Punctuation characters: 1