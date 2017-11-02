#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    // Define the "TitleAuthor" table of the "Pubs" database.
    struct TitleAuthor : public object {
      // Author ID; format ###-##-####
      string authorId;
      // Title ID; format AA####
      string titleId;
      // Author ORD is nullable.
      Nullable<short> authorORD;
      // Royalty Percent is nullable.
      Nullable<int> royaltyPercent;
    };

    // The main entry point for the application.
    static void Main(const Array<string>& args) {
      // Declare and initialize the titleAuthor array.
      Array<TitleAuthor> titleAuthors(3);
      titleAuthors[0].authorId = "712-32-1176";
      titleAuthors[0].titleId = "PS3333";
      titleAuthors[0].authorORD = 1;
      titleAuthors[0].royaltyPercent = 100;
      
      titleAuthors[1].authorId = "213-46-8915";
      titleAuthors[1].titleId = "BU1032";
      titleAuthors[1].authorORD = null;
      titleAuthors[1].royaltyPercent = null;
      
      titleAuthors[2].authorId = "672-71-3249";
      titleAuthors[2].titleId = "TC7777";
      titleAuthors[2].authorORD = null;
      titleAuthors[2].royaltyPercent = 40;
      
      // Display the values of the titleAuthor array elements, and
      // display a legend.
      Display("Title Authors Table", titleAuthors);
      Console::WriteLine("Legend:");
      Console::WriteLine("An Author ORD of -1 means no value is defined.");
      Console::WriteLine("A Royalty % of 0 means no value is defined.");
    }
    
    // Display the values of the titleAuthor array elements.
    static void Display(const string& title, const Array<TitleAuthor>& titleAuthors) {
      Console::WriteLine("*** {0} ***", title);
      for (TitleAuthor titleAuthor : titleAuthors) {
        Console::WriteLine("Author ID ... {0}", titleAuthor.authorId);
        Console::WriteLine("Title ID .... {0}", titleAuthor.titleId);
        Console::WriteLine("Author ORD .. {0}", titleAuthor.authorORD.HasValue ? titleAuthor.authorORD : -1);
        Console::WriteLine("Royalty % ... {0}", titleAuthor.royaltyPercent.HasValue ? titleAuthor.royaltyPercent : 0);
        Console::WriteLine();
      }
    }
  };
}

_startup(Examples::Program)

// This code produces the following output if 3 is entered on command line:
//
// *** Title Authors Table ***
// Author ID ... 712-32-1176
// Title ID .... PS3333
// Author ORD .. 1
// Royalty % ... 100
//
// Author ID ... 213-46-8915
// Title ID .... BU1032
// Author ORD .. -1
// Royalty % ... 0
//
// Author ID ... 672-71-3249
// Title ID .... TC7777
// Author ORD .. -1
// Royalty % ... 40
//
// Legend:
// An Author ORD of -1 means no value is defined.
// A Royalty % of 0 means no value is defined.
