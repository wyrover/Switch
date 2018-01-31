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

// Add flags operator (+, -, &, |, ^, ~, +=, -=, &=, |= and ^=) for enum class
template <>
class AddFlagOperators<Examples::Letters> : public TrueType {};

// Register enum class
template<>
struct EnumRegister<Examples::Letters> {
  void operator()(System::Collections::Generic::IDictionary<Examples::Letters, string>& values, bool& flags) {
    values[Examples::Letters::None] = "None";
    values[Examples::Letters::A] = "A";
    values[Examples::Letters::B] = "B";
    values[Examples::Letters::C] = "C";
    values[Examples::Letters::D] = "D";
    values[Examples::Letters::E] = "E";
    values[Examples::Letters::F] = "F";
    values[Examples::Letters::G] = "G";
    values[Examples::Letters::H] = "H";
    values[Examples::Letters::I] = "I";
    values[Examples::Letters::J] = "J";
    values[Examples::Letters::K] = "K";
    values[Examples::Letters::L] = "L";
    values[Examples::Letters::M] = "M";
    values[Examples::Letters::N] = "N";
    values[Examples::Letters::O] = "O";
    values[Examples::Letters::P] = "P";
    values[Examples::Letters::Q] = "Q";
    values[Examples::Letters::R] = "R";
    values[Examples::Letters::S] = "S";
    values[Examples::Letters::T] = "T";
    values[Examples::Letters::U] = "U";
    values[Examples::Letters::V] = "V";
    values[Examples::Letters::W] = "W";
    values[Examples::Letters::X] = "X";
    values[Examples::Letters::Y] = "Y";
    values[Examples::Letters::Z] = "Z";
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
      letter = Enum<>::Parse<Letters>("A, F");
      Console::WriteLine("letter is equal to {0}.", letter);

      // Give name of value Numbers
      Console::WriteLine("The Letters::Q name is {0}.", Enum<>::GetName(Letters::Q));

      // Give value of value Numbers
      Console::WriteLine("The Letters::G value is {0}.", (int)Letters::G);

      // Give Nimbers names list
      Console::WriteLine("Letters names list : {0}", string::Join(", ", Enum<>::GetNames<Letters>()));
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
