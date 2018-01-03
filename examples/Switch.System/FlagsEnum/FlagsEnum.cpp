#include <Switch/Switch>
using namespace System;

namespace Examples {
  // Define a Letter enum from Enum class
  enum class Letters {
    None = 0,
    A = 0b1,
    B = 0b10,
    C = 0b100,
    D = 0b1000,
    E = 0b10000,
    F = 0b100000,
    G = 0b1000000,
    H = 0b10000000,
    I = 0b100000000,
    J = 0b1000000000,
    K = 0b10000000000,
    L = 0b100000000000,
    M = 0b1000000000000,
    N = 0b10000000000000,
    O = 0b100000000000000,
    P = 0b1000000000000000,
    Q = 0b10000000000000000,
    R = 0b100000000000000000,
    S = 0b1000000000000000000,
    T = 0b10000000000000000000,
    U = 0b100000000000000000000,
    V = 0b1000000000000000000000,
    W = 0b10000000000000000000000,
    X = 0b100000000000000000000000,
    Y = 0b1000000000000000000000000,
    Z = 0b10000000000000000000000000
  };
}

template <>
class AddFlagOperators<Examples::Letters> : public TrueType {};

template<>
class EnumToStrings<Examples::Letters> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Examples::Letters::None, "None"}, {(int64)Examples::Letters::A, "A"}, {(int64)Examples::Letters::B, "B"}, {(int64)Examples::Letters::C, "C"}, {(int64)Examples::Letters::D, "D"}, {(int64)Examples::Letters::E, "E"}, {(int64)Examples::Letters::F, "F"}, {(int64)Examples::Letters::G, "G"}, {(int64)Examples::Letters::H, "H"}, {(int64)Examples::Letters::I, "I"}, {(int64)Examples::Letters::J, "J"}, {(int64)Examples::Letters::K, "K"}, {(int64)Examples::Letters::L, "L"}, {(int64)Examples::Letters::M, "M"}, {(int64)Examples::Letters::N, "N"}, {(int64)Examples::Letters::O, "O"}, {(int64)Examples::Letters::P, "P"}, {(int64)Examples::Letters::Q, "Q"}, {(int64)Examples::Letters::R, "R"}, {(int64)Examples::Letters::S, "S"}, {(int64)Examples::Letters::T, "T"}, {(int64)Examples::Letters::U, "U"}, {(int64)Examples::Letters::V, "V"}, {(int64)Examples::Letters::W, "W"}, {(int64)Examples::Letters::X, "X"}, {(int64)Examples::Letters::Y, "Y"}, {(int64)Examples::Letters::Z, "Z"}};
    flags = true;
  }
};

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a Letters Enum
      Letters letter = Letters::None;

      Console::WriteLine("letter is equal to {0}.", letter);

      // Assigne a Letters value
      letter  = Letters::D;
      Console::WriteLine("letter is equal to {0}.", letter);

      // Assigne a Int32 value
      letter = (Letters)9;
      Console::WriteLine("letter is equal to {0}.", letter);

      // Assigne bits value
      letter = Letters::A | Letters::L | Letters::T;
      Console::WriteLine("letter is equal to {0}.", letter);

      // Parse a Numbers
      letter = Enum<Letters>::Parse("A, F");
      Console::WriteLine("letter is equal to {0}.", letter);

      // Give name of value Numbers
      Console::WriteLine("The Letters::Q name is {0}.", Enum<Letters>(Letters::Q).GetName());

      // Give value of value Numbers
      Console::WriteLine("The Letters::G value is {0}.", Enum<Letters>(Letters::G).ToInt32());

      // Give Nimbers names list
      Console::WriteLine("Letters names list : {0}", string::Join(", ", Enum<Letters>::GetNames()));
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// letter is equal to None.
// letter is equal to D.
// letter is equal to A, D.
// letter is equal to A, L, T.
// letter is equal to A, F.
// The Letters::Q name is Q.
// The Letters::G value is 64.
// Letters names list : None, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
