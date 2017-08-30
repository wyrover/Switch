#include <Switch/System/Enum.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  enum class Pet {
    None = 0x00,
    Dog = 0x01,
    Cat = 0x02,
    Bird = 0x04
  };
  
  enum class Number {
    Zero = 0,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine
  };
  
  inline Number& operator +=(Number& lhs, Number rhs) {lhs = static_cast<Number>(static_cast<int32>(lhs) + static_cast<int32>(rhs)); return lhs;}
  inline Number& operator |=(Number& lhs, Number rhs) {lhs = static_cast<Number>(static_cast<int32>(lhs) | static_cast<int32>(rhs)); return lhs;}
  
  
  enum class Letter {
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
  
  inline Letter operator |(Letter lhs, Letter rhs) {return static_cast<Letter>(static_cast<int32>(lhs) | static_cast<int32>(rhs));}
  
  enum class RGBPixel {
    Red = 0,
    Green,
    Blue
  };
  
  enum class NoEnum {
    None = 0
  };
}

/// @cond
template<>
class EnumToStrings<SwitchUnitTests::Pet> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SwitchUnitTests::Pet::None, "None"}, {(int64)SwitchUnitTests::Pet::Dog, "Dog"}, {(int64)SwitchUnitTests::Pet::Cat, "Cat"}, {(int64)SwitchUnitTests::Pet::Bird, "Bird"}};
    flags = false;
  }
};

template<>
class EnumToStrings<SwitchUnitTests::Number> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SwitchUnitTests::Number::Zero, "Zero"}, {(int64)SwitchUnitTests::Number::One, "One"}, {(int64)SwitchUnitTests::Number::Two, "Two"}, {(int64)SwitchUnitTests::Number::Three, "Three"}, {(int64)SwitchUnitTests::Number::Four, "Four"}, {(int64)SwitchUnitTests::Number::Five, "Five"}, {(int64)SwitchUnitTests::Number::Six, "Six"}, {(int64)SwitchUnitTests::Number::Seven, "Seven"}, {(int64)SwitchUnitTests::Number::Eight, "Eight"}, {(int64)SwitchUnitTests::Number::Nine, "Nine"}};
    flags = false;
  }
};

template <> class AddFlagOperators<SwitchUnitTests::Letter> : public TrueType {};

template<>
class EnumToStrings<SwitchUnitTests::Letter> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SwitchUnitTests::Letter::None, "None"}, {(int64)SwitchUnitTests::Letter::A, "A"}, {(int64)SwitchUnitTests::Letter::B, "B"}, {(int64)SwitchUnitTests::Letter::C, "C"}, {(int64)SwitchUnitTests::Letter::D, "D"}, {(int64)SwitchUnitTests::Letter::E, "E"}, {(int64)SwitchUnitTests::Letter::F, "F"}, {(int64)SwitchUnitTests::Letter::G, "G"}, {(int64)SwitchUnitTests::Letter::H, "H"}, {(int64)SwitchUnitTests::Letter::I, "I"}, {(int64)SwitchUnitTests::Letter::J, "J"}, {(int64)SwitchUnitTests::Letter::K, "K"}, {(int64)SwitchUnitTests::Letter::L, "L"}, {(int64)SwitchUnitTests::Letter::M, "M"}, {(int64)SwitchUnitTests::Letter::N, "N"}, {(int64)SwitchUnitTests::Letter::O, "O"}, {(int64)SwitchUnitTests::Letter::P, "P"}, {(int64)SwitchUnitTests::Letter::Q, "Q"}, {(int64)SwitchUnitTests::Letter::R, "R"}, {(int64)SwitchUnitTests::Letter::S, "S"}, {(int64)SwitchUnitTests::Letter::T, "T"}, {(int64)SwitchUnitTests::Letter::U, "U"}, {(int64)SwitchUnitTests::Letter::V, "V"}, {(int64)SwitchUnitTests::Letter::W, "W"}, {(int64)SwitchUnitTests::Letter::X, "X"}, {(int64)SwitchUnitTests::Letter::Y, "Y"}, {(int64)SwitchUnitTests::Letter::Z, "Z"}};
    flags = true;
  }
};
/// @endcond

namespace SwitchUnitTests {
  class EnumTest : public TestFixture {
  protected:
    void SetUp() override {}
    void TearDown() override {}
    
    void Constructor() {
      TUnit::Assert::AreEqual(0, Enum<Number>::ToInt32(Number::Zero), sw_current_information);
      TUnit::Assert::AreEqual(1, Enum<Number>::ToInt32(Number::One), sw_current_information);
      TUnit::Assert::AreEqual(2, Enum<Number>::ToInt32(Number::Two), sw_current_information);
      TUnit::Assert::AreEqual(3, Enum<Number>::ToInt32((Number)3), sw_current_information);
      TUnit::Assert::AreEqual(24, Enum<Number>::ToInt32((Number)24), sw_current_information);
      
      Number number0 = Number::Zero;
      Number number1 = Number::One;
      Number number2 = (Number)Enum<Number>::Parse("Two");
      Number number3 = (Number)Enum<Number>::Parse("three", true);
      Number number4 = (Number)4;
      Number number5 = Number(Number::Five);
      Number number6 = (Number)6;
      Number number7 = Number(Number(7));
      Number number8 = Number::Zero;
      Number number9 = Number::Zero;
      
      number8 |= Number(8);
      number9 += Number::Nine;
      
      TUnit::Assert::AreEqual(0, Enum<Number>::ToInt32(number0), sw_current_information);
      TUnit::Assert::AreEqual(1, Enum<Number>::ToInt32(number1), sw_current_information);
      TUnit::Assert::AreEqual(2, Enum<Number>::ToInt32(number2), sw_current_information);
      TUnit::Assert::AreEqual(3, Enum<Number>::ToInt32(number3), sw_current_information);
      TUnit::Assert::AreEqual(4, Enum<Number>::ToInt32(number4), sw_current_information);
      TUnit::Assert::AreEqual(5, Enum<Number>::ToInt32(number5), sw_current_information);
      TUnit::Assert::AreEqual(6, Enum<Number>::ToInt32(number6), sw_current_information);
      TUnit::Assert::AreEqual(7, Enum<Number>::ToInt32(number7), sw_current_information);
      TUnit::Assert::AreEqual(8, Enum<Number>::ToInt32(number8), sw_current_information);
      TUnit::Assert::AreEqual(9, Enum<Number>::ToInt32(number9), sw_current_information);
      
      TUnit::Assert::AreEqual(0b00000000000000000000000000000000, Enum<Letter>::ToInt32(Letter::None), sw_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000001000, Enum<Letter>::ToInt32(Letter::D), sw_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000000111, Enum<Letter>::ToInt32(Letter::A|Letter::B|Letter::C), sw_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000100000000000, Enum<Letter>::ToInt32((Letter)0b00000000000000000000100000000000), sw_current_information);
      TUnit::Assert::AreEqual(0b01100000000000000000000000000000, Enum<Letter>::ToInt32((Letter)0b01100000000000000000000000000000), sw_current_information);
      
      Letter letterNone = Letter::None;
      Letter letterAB = Letter::A|Letter::B;
      Letter letterBC = (Letter)Enum<Letter>::Parse("B, C");
      Letter letterCD = (Letter)Enum<Letter>::Parse("c, d", true);
      
      TUnit::Assert::AreEqual(0b00000000000000000000000000000000, Enum<Letter>::ToInt32(letterNone), sw_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000000011, Enum<Letter>::ToInt32(letterAB), sw_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000000110, Enum<Letter>::ToInt32(letterBC), sw_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000001100, Enum<Letter>::ToInt32(letterCD), sw_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<RGBPixel>::ToInt32(RGBPixel::Red), sw_current_information);
      TUnit::Assert::AreEqual(1, Enum<RGBPixel>::ToInt32(RGBPixel::Green), sw_current_information);
      TUnit::Assert::AreEqual(2, Enum<RGBPixel>::ToInt32(RGBPixel::Blue), sw_current_information);
      TUnit::Assert::AreEqual(1, Enum<RGBPixel>::ToInt32((RGBPixel)1), sw_current_information);
      TUnit::Assert::AreEqual(5, Enum<RGBPixel>::ToInt32((RGBPixel)5), sw_current_information);
    }
    
    void Equality() {
      Number number0 = Number::Zero;
      Number number1 = Number::One;
      Number number2 = (Number)Enum<Number>::Parse("Two");
      Number number3 = (Number)Enum<Number>::Parse("three", true);
      Number number4 = (Number)4;
      
      TUnit::Assert::IsTrue(number0 == Number::Zero, sw_current_information);
      TUnit::Assert::IsTrue(number1 == Number::One, sw_current_information);
      TUnit::Assert::IsTrue(number2 == Number::Two, sw_current_information);
      TUnit::Assert::IsTrue(number3 == Number::Three, sw_current_information);
      TUnit::Assert::IsTrue(number4 == Number::Four, sw_current_information);
      
      TUnit::Assert::IsFalse(number0 == Number::Nine, sw_current_information);
      TUnit::Assert::IsFalse(number1 == Number::Nine, sw_current_information);
      TUnit::Assert::IsFalse(number2 == Number::Nine, sw_current_information);
      TUnit::Assert::IsFalse(number3 == Number::Nine, sw_current_information);
      TUnit::Assert::IsFalse(number4 == Number::Nine, sw_current_information);
      
      TUnit::Assert::IsFalse(number0 != Number::Zero, sw_current_information);
      TUnit::Assert::IsFalse(number1 != Number::One, sw_current_information);
      TUnit::Assert::IsFalse(number2 != Number::Two, sw_current_information);
      TUnit::Assert::IsFalse(number3 != Number::Three, sw_current_information);
      TUnit::Assert::IsFalse(number4 != Number::Four, sw_current_information);
      
      TUnit::Assert::IsTrue(number0 != Number::Nine, sw_current_information);
      TUnit::Assert::IsTrue(number1 != Number::Nine, sw_current_information);
      TUnit::Assert::IsTrue(number2 != Number::Nine, sw_current_information);
      TUnit::Assert::IsTrue(number3 != Number::Nine, sw_current_information);
      TUnit::Assert::IsTrue(number4 != Number::Nine, sw_current_information);
    }
    
    void SwitchCase() {
      Pet PetDog = Pet::Dog;
      switch (PetDog) {
        case Pet::Dog : TUnit::Assert::Succeed(sw_current_information); break;
        case Pet::Cat : TUnit::Assert::Fail(sw_current_information); break;
        case Pet::Bird : TUnit::Assert::Fail(sw_current_information); break;
        default: TUnit::Assert::Fail(sw_current_information); break;
      }
      
      Number number8 = Number::Eight;
      switch (number8) {
        case Number::Zero : TUnit::Assert::Fail(sw_current_information); break;
        case Number::One : TUnit::Assert::Fail(sw_current_information); break;
        case Number::Two : TUnit::Assert::Fail(sw_current_information); break;
        case Number::Three : TUnit::Assert::Fail(sw_current_information); break;
        case Number::Four : TUnit::Assert::Fail(sw_current_information); break;
        case Number::Five : TUnit::Assert::Fail(sw_current_information); break;
        case Number::Six : TUnit::Assert::Fail(sw_current_information); break;
        case Number::Seven : TUnit::Assert::Fail(sw_current_information); break;
        case Number::Eight : TUnit::Assert::Succeed(sw_current_information); break;
        case Number::Nine : TUnit::Assert::Fail(sw_current_information); break;
        default: TUnit::Assert::Fail(sw_current_information); break;
      }
    }
    
    void GetName() {
      TUnit::Assert::AreEqual("Zero", Enum<Number>::GetName(Number::Zero), sw_current_information);
      TUnit::Assert::AreEqual("One", Enum<Number>::GetName(Number::One), sw_current_information);
      TUnit::Assert::AreEqual("Two", Enum<Number>::GetName(Number::Two), sw_current_information);
      TUnit::Assert::AreEqual("Three", Enum<Number>::GetName(Number::Three), sw_current_information);
      TUnit::Assert::AreEqual("Four", Enum<Number>::GetName(Number::Four), sw_current_information);
      TUnit::Assert::AreEqual("Five", Enum<Number>::GetName(Number::Five), sw_current_information);
      
      TUnit::Assert::AreEqual("None", Enum<Letter>::GetName(Letter::None).ToString(), sw_current_information);
      TUnit::Assert::AreEqual("G", Enum<Letter>::GetName(Letter::G).ToString(), sw_current_information);
      TUnit::Assert::AreEqual("A, B, C", Enum<Letter>::GetName(Letter::A|Letter::B|Letter::C).ToString(), sw_current_information);
      
      TUnit::Assert::AreEqual("0", Enum<RGBPixel>::GetName(RGBPixel::Red), sw_current_information);
      TUnit::Assert::AreEqual("1", Enum<RGBPixel>::GetName(RGBPixel::Green), sw_current_information);
      TUnit::Assert::AreEqual("2", Enum<RGBPixel>::GetName(RGBPixel::Blue), sw_current_information);
    }
    
    void GetNames() {
      TUnit::Assert::AreEqual(10, Enum<Number>::GetNames().Count(), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Zero"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("One"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Two"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Three"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Four"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Five"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Six"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Seven"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Eight"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Nine"), sw_current_information);
      
      TUnit::Assert::AreEqual(27, Enum<Letter>::GetNames().Count(), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("None"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("A"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("B"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("C"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("D"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("E"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("F"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("G"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("H"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("I"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("J"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("K"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("L"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("M"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("N"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("O"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("P"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("Q"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("R"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("S"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("T"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("U"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("V"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("W"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("X"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("Y"), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("Z"), sw_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<RGBPixel>::GetNames().Count(), sw_current_information);
      TUnit::Assert::AreEqual(0, Enum<NoEnum>::GetNames().Count(), sw_current_information);
    }
    
    void GetValues() {
      TUnit::Assert::AreEqual(10, Enum<Number>::GetValues().Count(), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Zero), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::One), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Two), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Three), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Four), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Five), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Six), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Seven), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Eight), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Nine), sw_current_information);
      
      TUnit::Assert::AreEqual(27, Enum<Letter>::GetValues().Count(), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::None), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::A), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::B), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::C), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::D), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::E), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::F), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::G), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::H), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::I), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::J), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::K), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::L), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::M), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::N), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::O), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::P), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::Q), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::R), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::S), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::T), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::U), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::V), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::W), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::X), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::Y), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::Z), sw_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<RGBPixel>::GetValues().Count(), sw_current_information);
      TUnit::Assert::AreEqual(0, Enum<NoEnum>::GetValues().Count(), sw_current_information);
    }
    
    void HasFlag() {
      TUnit::Assert::IsTrue(Enum<Letter>(Letter::A|Letter::B|Letter::C).HasFlag(Letter::B | Letter::C), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>(Letter::A).HasFlag(0b00000000000000000000000000000001), sw_current_information);
      TUnit::Assert::IsFalse(Enum<Letter>(Letter::None).HasFlag(Letter::A), sw_current_information);
      TUnit::Assert::IsFalse(Enum<Letter>(Letter::None).HasFlag(0b10000000000000000000000000000000), sw_current_information);
    }
    
    void IsDefined() {
      TUnit::Assert::IsTrue(Enum<Number>::IsDefined(Number::Two), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::IsDefined(5), sw_current_information);
      TUnit::Assert::IsFalse(Enum<Number>::IsDefined(12), sw_current_information);
      
      TUnit::Assert::IsTrue(Enum<Letter>::IsDefined(Letter::B), sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::IsDefined(0x00020000), sw_current_information);
      TUnit::Assert::IsFalse(Enum<Letter>::IsDefined(0x20000000), sw_current_information);
      TUnit::Assert::IsFalse(Enum<Letter>::IsDefined(Letter::B|Letter::C|Letter::Z), sw_current_information);
      
      TUnit::Assert::IsFalse(Enum<NoEnum>::IsDefined(NoEnum::None), sw_current_information);
    }
    
    void FromInt32() {
      TUnit::Assert::AreEqual(0, Enum<Number>().FromInt32(0).ToInt32(), sw_current_information);
      TUnit::Assert::AreEqual(1, Enum<Number>().FromInt32(1).ToInt32(), sw_current_information);
      TUnit::Assert::AreEqual(2, Enum<Number>().FromInt32(2).ToInt32(), sw_current_information);
      TUnit::Assert::AreEqual(3, Enum<Number>().FromInt32(3).ToInt32(), sw_current_information);
      TUnit::Assert::AreEqual(4, Enum<Number>().FromInt32(4).ToInt32(), sw_current_information);
      TUnit::Assert::AreEqual(5, Enum<Number>().FromInt32(5).ToInt32(), sw_current_information);
    }
    
    void Parse() {
      TUnit::Assert::AreEqual(0, (int)Enum<Number>::Parse("Zero"), sw_current_information);
      TUnit::Assert::AreEqual(1, (int)Enum<Number>::Parse("One"), sw_current_information);
      TUnit::Assert::AreEqual(2, (int)Enum<Number>::Parse("Two"), sw_current_information);
      TUnit::Assert::AreEqual(3, (int)Enum<Number>::Parse("Three"), sw_current_information);
      TUnit::Assert::AreEqual(4, (int)Enum<Number>::Parse("Four"), sw_current_information);
      TUnit::Assert::AreEqual(5, (int)Enum<Number>::Parse("Five"), sw_current_information);
      TUnit::Assert::Throws<FormatException>(sw_delegate {Enum<Number>::Parse("BadValue");}, sw_current_information);
      
      TUnit::Assert::AreEqual(0b00000000000000000000000000000000, (int)Enum<Letter>::Parse("None"), sw_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000000111, (int)Enum<Letter>::Parse("A, B, C"), sw_current_information);
      
      TUnit::Assert::AreEqual(1, (int)Enum<Number>::Parse("one", true));
      
      TUnit::Assert::Throws<FormatException>(sw_delegate {Enum<RGBPixel>::Parse("Red");}, sw_current_information);
      TUnit::Assert::Throws<FormatException>(sw_delegate {Enum<RGBPixel>::Parse("Green");}, sw_current_information);
      TUnit::Assert::Throws<FormatException>(sw_delegate {Enum<RGBPixel>::Parse("Blue");}, sw_current_information);
      TUnit::Assert::Throws<FormatException>(sw_delegate {Enum<RGBPixel>::Parse("BadValue");}, sw_current_information);
    }
    
    void ToInt32() {
      TUnit::Assert::AreEqual(0, Enum<Number>::ToInt32(Number::Zero), sw_current_information);
      TUnit::Assert::AreEqual(1, Enum<Number>::ToInt32(Number::One), sw_current_information);
      TUnit::Assert::AreEqual(2, Enum<Number>::ToInt32(Number::Two), sw_current_information);
      TUnit::Assert::AreEqual(3, Enum<Number>::ToInt32(Number::Three), sw_current_information);
      TUnit::Assert::AreEqual(4, Enum<Number>::ToInt32(Number::Four), sw_current_information);
      TUnit::Assert::AreEqual(5, Enum<Number>::ToInt32(Number::Five), sw_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<RGBPixel>::ToInt32(RGBPixel::Red), sw_current_information);
      TUnit::Assert::AreEqual(1, Enum<RGBPixel>::ToInt32(RGBPixel::Green), sw_current_information);
      TUnit::Assert::AreEqual(2, Enum<RGBPixel>::ToInt32(RGBPixel::Blue), sw_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<NoEnum>::ToInt32(NoEnum::None), sw_current_information);
    }
    
    void ToString() {
      TUnit::Assert::AreEqual("Zero", Enum<Number>::ToString(Number::Zero), sw_current_information);
      TUnit::Assert::AreEqual("One", Enum<Number>::ToString(Number::One), sw_current_information);
      TUnit::Assert::AreEqual("Two", Enum<Number>::ToString(Number::Two), sw_current_information);
      TUnit::Assert::AreEqual("Three", Enum<Number>::ToString(Number::Three), sw_current_information);
      TUnit::Assert::AreEqual("Four", Enum<Number>::ToString(Number::Four), sw_current_information);
      TUnit::Assert::AreEqual("Five", Enum<Number>::ToString(Number::Five), sw_current_information);
      TUnit::Assert::AreEqual("52", Enum<Number>::ToString((Number)52), sw_current_information);
      
      TUnit::Assert::AreEqual("None", Enum<Letter>::ToString(Letter::None), sw_current_information);
      TUnit::Assert::AreEqual("A", Enum<Letter>::ToString(Letter::A), sw_current_information);
      TUnit::Assert::AreEqual("B", Enum<Letter>::ToString(Letter::B), sw_current_information);
      TUnit::Assert::AreEqual("A, B", Enum<Letter>::ToString(Letter::A|Letter::B), sw_current_information);
      TUnit::Assert::AreEqual("D, G, I", Enum<Letter>::ToString(Letter::D|Letter::G|Letter::I), sw_current_information);
      
      TUnit::Assert::AreEqual("0", Enum<RGBPixel>::ToString(RGBPixel::Red), sw_current_information);
      TUnit::Assert::AreEqual("1", Enum<RGBPixel>::ToString(RGBPixel::Green), sw_current_information);
      TUnit::Assert::AreEqual("2", Enum<RGBPixel>::ToString(RGBPixel::Blue), sw_current_information);
      
      TUnit::Assert::AreEqual("0", Enum<NoEnum>::ToString(NoEnum::None), sw_current_information);
    }
    
    void TryParse() {
      Number numberResult;
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Zero", numberResult));
      TUnit::Assert::AreEqual(0, (int32)numberResult, sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("One", numberResult));
      TUnit::Assert::AreEqual(1, (int32)numberResult, sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Two", numberResult));
      TUnit::Assert::AreEqual(2, (int32)numberResult, sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Three", numberResult));
      TUnit::Assert::AreEqual(3, (int32)numberResult, sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Four", numberResult));
      TUnit::Assert::AreEqual(4, (int32)numberResult, sw_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Five", numberResult));
      TUnit::Assert::AreEqual(5, (int32)numberResult, sw_current_information);
      TUnit::Assert::IsFalse(Enum<Number>::TryParse("BadValue", numberResult));
      
      Letter LetterResult;
      TUnit::Assert::IsTrue(Enum<Letter>::TryParse("None", LetterResult));
      TUnit::Assert::AreEqual(0x00000000, (int32)LetterResult, sw_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::TryParse("A, B, C", LetterResult));
      TUnit::Assert::AreEqual(0x00000007, (int32)LetterResult, sw_current_information);
      
      RGBPixel RGBPixelResult;
      TUnit::Assert::IsTrue(Enum<RGBPixel>::TryParse("0", RGBPixelResult));
      TUnit::Assert::AreEqual(0, (int32)RGBPixelResult, sw_current_information);
      TUnit::Assert::IsTrue(Enum<RGBPixel>::TryParse("1", RGBPixelResult));
      TUnit::Assert::AreEqual(1, (int32)RGBPixelResult, sw_current_information);
      TUnit::Assert::IsTrue(Enum<RGBPixel>::TryParse("2", RGBPixelResult));
      TUnit::Assert::AreEqual(2, (int32)RGBPixelResult, sw_current_information);
      TUnit::Assert::IsFalse(Enum<RGBPixel>::TryParse("Red", RGBPixelResult));
      TUnit::Assert::IsFalse(Enum<RGBPixel>::TryParse("Green", RGBPixelResult));
      TUnit::Assert::IsFalse(Enum<RGBPixel>::TryParse("Blue", RGBPixelResult));
      TUnit::Assert::IsFalse(Enum<RGBPixel>::TryParse("BadValue", RGBPixelResult));
      
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("one", true, numberResult));
      TUnit::Assert::AreEqual(1, (int32)numberResult, sw_current_information);
    }
  };
  
  sw_test(EnumTest, Constructor)
  sw_test(EnumTest, Equality)
  sw_test(EnumTest, SwitchCase)
  sw_test(EnumTest, GetName)
  sw_test(EnumTest, GetNames)
  sw_test(EnumTest, GetValues)
  sw_test(EnumTest, HasFlag)
  sw_test(EnumTest, IsDefined)
  sw_test(EnumTest, FromInt32)
  sw_test(EnumTest, Parse)
  sw_test(EnumTest, ToInt32)
  sw_test(EnumTest, ToString)
  sw_test(EnumTest, TryParse)
}
