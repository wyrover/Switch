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
}

// Register enum class
template<>
class EnumRegister<Examples::Numbers> {
public:
  void operator()(System::Collections::Generic::IDictionary<Examples::Numbers, string>& values, bool& flags) {
    values[Examples::Numbers::Zero] = "Zero";
    values[Examples::Numbers::One] = "One";
    values[Examples::Numbers::Two] = "Two";
    values[Examples::Numbers::Three] = "Three";
    values[Examples::Numbers::Four] = "Four";
    values[Examples::Numbers::Five] = "Five";
    values[Examples::Numbers::Six] = "Six";
    values[Examples::Numbers::Seven] = "Seven";
    values[Examples::Numbers::Eight] = "Eight";
    values[Examples::Numbers::Nine] = "Nine";
    values[Examples::Numbers::Ten] = "Ten";
  }
};

namespace Examples {
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
      number = Enum<>::Parse<Numbers>("Four");
      Console::WriteLine("number is equal to {0}.", number);

      // Give name of value Numbers
      Console::WriteLine("The Numbers::Eight name is {0}.", Enum<>::GetName(Numbers::Eight));

      // Give value of value Numbers
      Console::WriteLine("The Numbers::Three value is {0}.", (int)Numbers::Three);

      // Give Nimbers names list
      Console::WriteLine("Numbers names list : {0}", string::Join(", ", Enum<>::GetNames<Numbers>()));
    }
  };
}

startup_(Examples::Program);

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
