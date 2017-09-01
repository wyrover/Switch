#include <Switch/Switch>

using namespace System;

//________________________________________________________________
//                                                           Color
enum class Color {
  Black,
  DarkBlue,
  DarkGreen,
  DarkCyan,
  DarkRed,
  DarkMagenta,
  DarkYellow,
  Gray,
  DarkGray,
  Blue,
  Green,
  Cyan,
  Red,
  Magenta,
  Yellow,
  White
};

template<>
class EnumToStrings<Color> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Color::Black, "Black"}, {(int64)Color::DarkBlue, "DarkBlue"}, {(int64)Color::DarkGreen, "DarkGreen"}, {(int64)Color::DarkCyan, "DarkCyan"}, {(int64)Color::DarkRed, "DarkRed"}, {(int64)Color::DarkMagenta, "DarkMagenta"}, {(int64)Color::DarkYellow, "DarkYellow"}, {(int64)Color::Gray, "Gray"}, {(int64)Color::DarkGray, "DarkGray"}, {(int64)Color::Blue, "Blue"}, {(int64)Color::Green, "Green"}, {(int64)Color::Cyan, "Cyan"}, {(int64)Color::Red, "Red"}, {(int64)Color::Magenta, "Magenta"}, {(int64)Color::Yellow, "Yellow"}, {(int64)Color::White, "White"}};
    flags = false;
  }
};

//________________________________________________________________
//                                                          Letters
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

template <>
class AddFlagOperators<Letters> : public TrueType {};

template<>
class EnumToStrings<Letters> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Letters::None, "None"}, {(int64)Letters::A, "A"}, {(int64)Letters::B, "B"}, {(int64)Letters::C, "C"}, {(int64)Letters::D, "D"}, {(int64)Letters::E, "E"}, {(int64)Letters::F, "F"}, {(int64)Letters::G, "G"}, {(int64)Letters::H, "H"}, {(int64)Letters::I, "I"}, {(int64)Letters::J, "J"}, {(int64)Letters::K, "K"}, {(int64)Letters::L, "L"}, {(int64)Letters::M, "M"}, {(int64)Letters::N, "N"}, {(int64)Letters::O, "O"}, {(int64)Letters::P, "P"}, {(int64)Letters::Q, "Q"}, {(int64)Letters::R, "R"}, {(int64)Letters::S, "S"}, {(int64)Letters::T, "T"}, {(int64)Letters::U, "U"}, {(int64)Letters::V, "V"}, {(int64)Letters::W, "W"}, {(int64)Letters::X, "X"}, {(int64)Letters::Y, "Y"}, {(int64)Letters::Z, "Z"}};
    flags = true;
  }
};

//________________________________________________________________
//                                                             Pet
enum class Pet {
  Dog,
  Cat,
  Fish,
  Bird,
  Rabbit,
  Mouse,
  Chicken,
  Snake,
  Tigger,
  Lion,
  Leopard,
  Goat,
  Bear,
  Fox,
  Eagle
};

template<>
class EnumToStrings<Pet> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Pet::Dog, "Dog"}, {(int64)Pet::Cat, "Cat"}, {(int64)Pet::Fish, "Fish"}, {(int64)Pet::Bird, "Bird"}, {(int64)Pet::Rabbit, "Rabbit"}, {(int64)Pet::Mouse, "Mouse"}, {(int64)Pet::Chicken, "Chicken"}, {(int64)Pet::Snake, "Snake"}, {(int64)Pet::Tigger, "Tigger"}, {(int64)Pet::Lion, "Lion"}, {(int64)Pet::Leopard, "Leopard"}, {(int64)Pet::Goat, "Goat"}, {(int64)Pet::Bear, "Bear"}, {(int64)Pet::Fox, "Fox"}, {(int64)Pet::Eagle, "Eagle"}};
    flags = false;
  }
};

//________________________________________________________________
//                                                            Test

class Program {
public:
  static void Main() {
    Console::WriteLine("_______________________________________________________________________________________");
    Console::WriteLine("                                                                            class Color");
    Console::WriteLine("Color::Black = {0}", (int)Color::Black);
    Console::WriteLine("Enum<Color>(Color::DarkGreen).Value() = {0}", Enum<Color>(Color::DarkGreen).Value());
    Console::WriteLine("Enum<Color>(Color::DarkCyan).GetName() = {0}", Enum<Color>(Color::DarkCyan).GetName());
    Console::WriteLine("Enum<Color>(Color::DarkRed) = {0}", Enum<Color>(Color::DarkRed));
    Console::WriteLine("Enum<Color>(Color::DarkMagenta) = {0}", Enum<Color>(Color::DarkMagenta));
    Console::WriteLine("Enum<Color>(Color::DarkYellow).ToInt32() = {0}", Enum<Color>(Color::DarkYellow).ToInt32());
    Console::WriteLine("Enum<Color>::ToInt32(Color::Gray) = {0}", Enum<Color>::ToInt32(Color::Gray));
    Console::WriteLine("Enum<Color>(Color::DarkGray).ToString() = {0}", Enum<Color>(Color::DarkGray).ToString());
    Console::WriteLine("Enum<Color>::ToString(Color::Blue) = {0}", Enum<Color>::ToString(Color::Blue));
    Console::WriteLine("Enum<Color>(Color::Green).GetHashCode() = {0}", Enum<Color>(Color::Green).GetHashCode());
    Console::WriteLine("Enum<Color>(Color::Blue).HasFlag(Color::Red) = {0}", Enum<Color>(Color::Blue).HasFlag((int)Color::Red));
    Console::WriteLine("Enum<Color>(Color::DarkCyan).HasFlag(Color::DarkBlue) = {0}", Enum<Color>(Color::DarkCyan).HasFlag(Color::DarkBlue));
    Console::WriteLine("Enum<Color>::Parse(\"Magenta\") = {0}", Enum<Color>::Parse("Magenta"));
    Console::WriteLine("Enum<Color>::Parse(\"yellow\", true) = {0}", Enum<Color>::Parse("yellow", true));
    Console::WriteLine("Enum<Color>::Parse(\"25\") = {0}", Enum<Color>::Parse("25"));
    Console::WriteLine();
    Console::WriteLine("_______________________________________________________________________________________");
    Console::WriteLine("                                                                     enum class Letters");
    Console::WriteLine("Letters::A = 0x{0:X8}", int(Letters::A));
    Console::WriteLine("Enum<Letters>(Letters::C).Value() = 0x{0:X8}", Enum<Letters>(Letters::C).Value());
    Console::WriteLine("Enum<Letters>(Letters::D).GetName() = {0}", Enum<Letters>(Letters::D).GetName());
    Console::WriteLine("Enum<Letters>(Letters::D|Letters::E).GetName() = {0}", Enum<Letters>(Letters::D|Letters::E).GetName());
    Console::WriteLine("Enum<Letters>((Letters)0xFF).ToString() = {0}", Enum<Letters>((Letters)0xFF).GetName());
    Console::WriteLine("Enum<Letters>(Letters::F) = {0}", Enum<Letters>(Letters::F));
    Console::WriteLine("Enum<Letters>(Letters::G | Letters::H) = {0}", Enum<Letters>(Letters::G | Letters::H));
    Console::WriteLine("Enum<Letters>(Letters::I).ToInt32() = 0x{0:X8}", Enum<Letters>(Letters::I).ToInt32());
    Console::WriteLine("Enum<Letters>(Letters::J | Letters::K).ToInt32() = 0x{0:X8}", Enum<Letters>(Letters::J | Letters::K).ToInt32());
    Console::WriteLine("Enum<Letters>::ToInt32(Letters::L) = 0x{0:X8}", Enum<Letters>::ToInt32(Letters::L));
    Console::WriteLine("Enum<Letters>::ToInt32(Letters::M | Letters::N) = 0x{0:X8}", Enum<Letters>::ToInt32(Letters::M | Letters::N));
    Console::WriteLine("Enum<Letters>(Letters::O).ToString() = {0}", Enum<Letters>(Letters::O).ToString());
    Console::WriteLine("Enum<Letters>(Letters::P | Letters::Q).ToString() = {0}", Enum<Letters>(Letters::P | Letters::Q).ToString());
    Console::WriteLine("Enum<Letters>::ToString(Letters::R) = {0}", Enum<Letters>::ToString(Letters::R));
    Console::WriteLine("Enum<Letters>::ToString(Letters::S | Letters::T) = {0}", Enum<Letters>::ToString(Letters::S | Letters::T));
    Console::WriteLine("Enum<Letters>(Letters::U).GetHashCode() = 0x{0:X8}", Enum<Letters>(Letters::U).GetHashCode());
    Console::WriteLine("Enum<Letters>(Letters::V | Letters::W).HasFlag(0x00200000) = {0}", Enum<Letters>(Letters::V | Letters::W).HasFlag(0x00400000));
    Console::WriteLine("Enum<Letters>(Letters::V | Letters::W).HasFlag(Letters::W) = {0}", Enum<Letters>(Letters::V | Letters::W).HasFlag(Letters::W));
    Console::WriteLine("Enum<Letters>(Letters::V | Letters::W).HasFlag(Letters::X) = {0}", Enum<Letters>(Letters::V | Letters::W).HasFlag(Letters::X));
    Console::WriteLine("Enum<Letters>::Parse(\"X\") = 0x{0:X8}", Enum<Letters>::Parse("X"));
    Console::WriteLine("Enum<Letters>::Parse(\"Y, Z\") = 0x{0:X8}", Enum<Letters>::Parse("y, z", true));
    Console::WriteLine("Enum<Letters>::Parse(\"268435456\") = 0x{0:X8}", Enum<Letters>::Parse("268435456"));
    Console::WriteLine("_______________________________________________________________________________________");
    Console::WriteLine("                                                                             struct Pet");
    Console::WriteLine("Pet::Dog = {0}", int(Pet::Dog));
    Console::WriteLine("Enum<Pet>(Pet::Fish).Value() = {0}", Enum<Pet>(Pet::Fish).Value());
    Console::WriteLine("Enum<Pet>(Pet::Bird).GetName() = {0}", Enum<Pet>(Pet::Bird).GetName());
    Console::WriteLine("Enum<Pet>(Pet::Rabbit) = {0}", Enum<Pet>(Pet::Rabbit));
    Console::WriteLine("Enum<Pet>(Pet::Mouse).ToInt32() = {0}", Enum<Pet>(Pet::Mouse).ToInt32());
    Console::WriteLine("Enum<Pet>::ToInt32(Pet::Chicken) = {0}", Enum<Pet>::ToInt32(Pet::Chicken));
    Console::WriteLine("Enum<Pet>(Pet::Snake).ToString() = {0}", Enum<Pet>(Pet::Snake).ToString());
    Console::WriteLine("Enum<Pet>::ToString(Pet::Tigger) = {0}", Enum<Pet>::ToString(Pet::Tigger));
    Console::WriteLine("Enum<Pet>(Pet::Lion).GetHashCode() = {0}", Enum<Pet>(Pet::Lion).GetHashCode());
    Console::WriteLine("Enum<Pet>(Pet::Leopard).HasFlag(10) = {0}", Enum<Pet>(Pet::Leopard).HasFlag(10));
    Console::WriteLine("Enum<Pet>(Pet::Leopard).HasFlag(Pet::Lion) = {0}", Enum<Pet>(Pet::Leopard).HasFlag(Pet::Lion));
    Console::WriteLine("Enum<Pet>::Parse(\"Goat\") = {0}", Enum<Pet>::Parse("Goat"));
    Console::WriteLine("Enum<Pet>::Parse(\"boar\", true) = {0}", Enum<Pet>::Parse("bear", true));
    Console::WriteLine("Enum<Pet>::Parse(\"42\") = {0}", Enum<Pet>::Parse("42"));
    Console::WriteLine();
    Console::WriteLine("_______________________________________________________________________________________");
  }
};

_startup (Program)
