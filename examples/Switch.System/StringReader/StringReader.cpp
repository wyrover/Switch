#include <Switch/Switch>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      string textReaderText = "TextReader is the abstract base "
        "class of StreamReader and StringReader, which read "
        "characters from streams and strings, respectively.\n\n"

        "Create an instance of TextReader to open a text file "
        "for reading a specified range of characters, or to "
        "create a reader based on an existing stream.\n\n"

        "You can also use an instance of TextReader to read "
        "text from a custom backing store using the same "
        "APIs you would use for a string or a stream.\n\n";

      Console::WriteLine("Original text:\n\n{0}", textReaderText);

      // From textReaderText, create a continuous paragraph
      // with two spaces between each sentence.
      string line, paragraph;
      StringReader strReader(textReaderText);
      while (strReader.Peek() != -1) {
        line = strReader.ReadLine();
        if (line != "")
          paragraph = paragraph + line + " ";
        else
          paragraph = paragraph + "\n";
      }
      Console::WriteLine("Modified text:\n\n{0}", paragraph);

      // Re-create textReaderText from paragraph.
      char32 convertedCharacter;
      StringWriter strWriter;
      strReader = StringReader(paragraph);
      while (true) {
        int intCharacter = strReader.Read();

        // Check for the end of the string
        // before converting to a character.
        if (intCharacter == -1) break;

        convertedCharacter = Convert::ToChar(intCharacter);
        if (convertedCharacter == '.') {
          strWriter.Write(".\n\n");

          // Bypass the spaces between sentences.
          strReader.Read();
          strReader.Read();
        } else
          strWriter.Write(convertedCharacter);
      }
      Console::WriteLine("\nOriginal text:\n\n{0}", strWriter.ToString());
    }
  };
}

_startup(Examples::Program);

// This code produces output similar to the following:
//
// Original text:
//
// TextReader is the abstract base class of StreamReader and StringReader, which read characters from streams and strings, respectively.
//
// Create an instance of TextReader to open a text file for reading a specified range of characters, or to create a reader based on an existing stream.
//
// You can also use an instance of TextReader to read text from a custom backing store using the same APIs you would use for a string or a stream.
//
//
// Modified text:
//
// TextReader is the abstract base class of StreamReader and StringReader, which read characters from streams and strings, respectively.
// Create an instance of TextReader to open a text file for reading a specified range of characters, or to create a reader based on an existing stream.
// You can also use an instance of TextReader to read text from a custom backing store using the same APIs you would use for a string or a stream.
//
//
// Original text:
//
// TextReader is the abstract base class of StreamReader and StringReader, which read characters from streams and strings, respectively.
//
// Create an instance of TextReader to open a text file for reading a specified range of characters, or to create a reader based on an existing stream.
//
//You can also use an instance of TextReader to read text from a custom backing store using the same APIs you would use for a string or a stream.
//
//
