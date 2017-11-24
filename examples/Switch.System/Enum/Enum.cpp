#include <Switch/Switch>

using namespace System;

namespace Examples {
  // Define a Numbers enum
  enum class Numbers {
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten
  };
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a Numbers Enum
      Numbers number = Numbers::Ten;
      
      Console::WriteLine("number is equal to {0}.", number);
      
      // Assigne a Numbers value
      number  = Numbers::Six;
      Console::WriteLine("number is equal to {0}.", number);
      
      // Assigne a int value
      number = (Numbers)9;
      Console::WriteLine("number is equal to {0}.", number);
      
      // Assigne a int value
      number = (Numbers)11;
      Console::WriteLine("number is equal to {0}.", number);
      
      // Parse a Numbers
      number = Enum<Numbers>::Parse("Four");
      Console::WriteLine("number is equal to {0}.", number);
      
      // Give name of value Numbers
      Console::WriteLine("The Numbers::Eight name is {0}.", Enum<Numbers>(Numbers::Eight).GetName());
      
      // Give value of value Numbers
      Console::WriteLine("The Numbers::Three value is {0}.", Enum<Numbers>(Numbers::Three).ToInt32());
      
      // Give Nimbers names list
      Console::WriteLine("Numbers names list : {0}", string::Join(", ", Enum<Numbers>::GetNames()));
    }
  };
}

// Associate enum values to strings
template<>
class EnumToStrings<Examples::Numbers> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Examples::Numbers::Zero, "Zero"}, {(int64)Examples::Numbers::One, "One"}, {(int64)Examples::Numbers::Two, "Two"}, {(int64)Examples::Numbers::Three, "Three"}, {(int64)Examples::Numbers::Four, "Four"}, {(int64)Examples::Numbers::Five, "Five"}, {(int64)Examples::Numbers::Six, "Six"}, {(int64)Examples::Numbers::Seven, "Seven"}, {(int64)Examples::Numbers::Eight, "Eight"}, {(int64)Examples::Numbers::Nine, "Nine"}, {(int64)Examples::Numbers::Ten, "Ten"}};
    flags = false;
  }
};

_startup(Examples::Program);

// This code produces the following output:
//
// number is equal to Ten.
// number is equal to Six.
// number is equal to Nine.
// number is equal to 11.
// number is equal to Four.
// The Numbers::Eight name is Eight.
// The Numbers::Three value is 3.
// Numbers names list : Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
