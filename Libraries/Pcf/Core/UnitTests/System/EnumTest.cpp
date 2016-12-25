#include <Pcf/System/Enum.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
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
class EnumToStrings<PcfUnitTests::Pet> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)PcfUnitTests::Pet::None, "None"}, {(int64)PcfUnitTests::Pet::Dog, "Dog"}, {(int64)PcfUnitTests::Pet::Cat, "Cat"}, {(int64)PcfUnitTests::Pet::Bird, "Bird"}};
    flags = false;
  }
};

template<>
class EnumToStrings<PcfUnitTests::Number> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)PcfUnitTests::Number::Zero, "Zero"}, {(int64)PcfUnitTests::Number::One, "One"}, {(int64)PcfUnitTests::Number::Two, "Two"}, {(int64)PcfUnitTests::Number::Three, "Three"}, {(int64)PcfUnitTests::Number::Four, "Four"}, {(int64)PcfUnitTests::Number::Five, "Five"}, {(int64)PcfUnitTests::Number::Six, "Six"}, {(int64)PcfUnitTests::Number::Seven, "Seven"}, {(int64)PcfUnitTests::Number::Eight, "Eight"}, {(int64)PcfUnitTests::Number::Nine, "Nine"}};
    flags = false;
  }
};

template <> class AddFlagOperators<PcfUnitTests::Letter> : public TrueType {};

template<>
class EnumToStrings<PcfUnitTests::Letter> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)PcfUnitTests::Letter::None, "None"}, {(int64)PcfUnitTests::Letter::A, "A"}, {(int64)PcfUnitTests::Letter::B, "B"}, {(int64)PcfUnitTests::Letter::C, "C"}, {(int64)PcfUnitTests::Letter::D, "D"}, {(int64)PcfUnitTests::Letter::E, "E"}, {(int64)PcfUnitTests::Letter::F, "F"}, {(int64)PcfUnitTests::Letter::G, "G"}, {(int64)PcfUnitTests::Letter::H, "H"}, {(int64)PcfUnitTests::Letter::I, "I"}, {(int64)PcfUnitTests::Letter::J, "J"}, {(int64)PcfUnitTests::Letter::K, "K"}, {(int64)PcfUnitTests::Letter::L, "L"}, {(int64)PcfUnitTests::Letter::M, "M"}, {(int64)PcfUnitTests::Letter::N, "N"}, {(int64)PcfUnitTests::Letter::O, "O"}, {(int64)PcfUnitTests::Letter::P, "P"}, {(int64)PcfUnitTests::Letter::Q, "Q"}, {(int64)PcfUnitTests::Letter::R, "R"}, {(int64)PcfUnitTests::Letter::S, "S"}, {(int64)PcfUnitTests::Letter::T, "T"}, {(int64)PcfUnitTests::Letter::U, "U"}, {(int64)PcfUnitTests::Letter::V, "V"}, {(int64)PcfUnitTests::Letter::W, "W"}, {(int64)PcfUnitTests::Letter::X, "X"}, {(int64)PcfUnitTests::Letter::Y, "Y"}, {(int64)PcfUnitTests::Letter::Z, "Z"}};
    flags = true;
  }
};
/// @endcond

namespace PcfUnitTests {
  class EnumTest : public TestFixture {
  protected:
    void SetUp() override {}
    void TearDown() override {}
    
    void Constructor() {
      TUnit::Assert::AreEqual(0, Enum<Number>::ToInt32(Number::Zero), pcf_current_information);
      TUnit::Assert::AreEqual(1, Enum<Number>::ToInt32(Number::One), pcf_current_information);
      TUnit::Assert::AreEqual(2, Enum<Number>::ToInt32(Number::Two), pcf_current_information);
      TUnit::Assert::AreEqual(3, Enum<Number>::ToInt32((Number)3), pcf_current_information);
      TUnit::Assert::AreEqual(24, Enum<Number>::ToInt32((Number)24), pcf_current_information);
      
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
      
      TUnit::Assert::AreEqual(0, Enum<Number>::ToInt32(number0), pcf_current_information);
      TUnit::Assert::AreEqual(1, Enum<Number>::ToInt32(number1), pcf_current_information);
      TUnit::Assert::AreEqual(2, Enum<Number>::ToInt32(number2), pcf_current_information);
      TUnit::Assert::AreEqual(3, Enum<Number>::ToInt32(number3), pcf_current_information);
      TUnit::Assert::AreEqual(4, Enum<Number>::ToInt32(number4), pcf_current_information);
      TUnit::Assert::AreEqual(5, Enum<Number>::ToInt32(number5), pcf_current_information);
      TUnit::Assert::AreEqual(6, Enum<Number>::ToInt32(number6), pcf_current_information);
      TUnit::Assert::AreEqual(7, Enum<Number>::ToInt32(number7), pcf_current_information);
      TUnit::Assert::AreEqual(8, Enum<Number>::ToInt32(number8), pcf_current_information);
      TUnit::Assert::AreEqual(9, Enum<Number>::ToInt32(number9), pcf_current_information);
      
      TUnit::Assert::AreEqual(0b00000000000000000000000000000000, Enum<Letter>::ToInt32(Letter::None), pcf_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000001000, Enum<Letter>::ToInt32(Letter::D), pcf_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000000111, Enum<Letter>::ToInt32(Letter::A|Letter::B|Letter::C), pcf_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000100000000000, Enum<Letter>::ToInt32((Letter)0b00000000000000000000100000000000), pcf_current_information);
      TUnit::Assert::AreEqual(0b01100000000000000000000000000000, Enum<Letter>::ToInt32((Letter)0b01100000000000000000000000000000), pcf_current_information);
      
      Letter letterNone = Letter::None;
      Letter letterAB = Letter::A|Letter::B;
      Letter letterBC = (Letter)Enum<Letter>::Parse("B, C");
      Letter letterCD = (Letter)Enum<Letter>::Parse("c, d", true);
      
      TUnit::Assert::AreEqual(0b00000000000000000000000000000000, Enum<Letter>::ToInt32(letterNone), pcf_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000000011, Enum<Letter>::ToInt32(letterAB), pcf_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000000110, Enum<Letter>::ToInt32(letterBC), pcf_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000001100, Enum<Letter>::ToInt32(letterCD), pcf_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<RGBPixel>::ToInt32(RGBPixel::Red), pcf_current_information);
      TUnit::Assert::AreEqual(1, Enum<RGBPixel>::ToInt32(RGBPixel::Green), pcf_current_information);
      TUnit::Assert::AreEqual(2, Enum<RGBPixel>::ToInt32(RGBPixel::Blue), pcf_current_information);
      TUnit::Assert::AreEqual(1, Enum<RGBPixel>::ToInt32((RGBPixel)1), pcf_current_information);
      TUnit::Assert::AreEqual(5, Enum<RGBPixel>::ToInt32((RGBPixel)5), pcf_current_information);
    }
    
    void Equality() {
      Number number0 = Number::Zero;
      Number number1 = Number::One;
      Number number2 = (Number)Enum<Number>::Parse("Two");
      Number number3 = (Number)Enum<Number>::Parse("three", true);
      Number number4 = (Number)4;
      
      TUnit::Assert::IsTrue(number0 == Number::Zero, pcf_current_information);
      TUnit::Assert::IsTrue(number1 == Number::One, pcf_current_information);
      TUnit::Assert::IsTrue(number2 == Number::Two, pcf_current_information);
      TUnit::Assert::IsTrue(number3 == Number::Three, pcf_current_information);
      TUnit::Assert::IsTrue(number4 == Number::Four, pcf_current_information);
      
      TUnit::Assert::IsFalse(number0 == Number::Nine, pcf_current_information);
      TUnit::Assert::IsFalse(number1 == Number::Nine, pcf_current_information);
      TUnit::Assert::IsFalse(number2 == Number::Nine, pcf_current_information);
      TUnit::Assert::IsFalse(number3 == Number::Nine, pcf_current_information);
      TUnit::Assert::IsFalse(number4 == Number::Nine, pcf_current_information);
      
      TUnit::Assert::IsFalse(number0 != Number::Zero, pcf_current_information);
      TUnit::Assert::IsFalse(number1 != Number::One, pcf_current_information);
      TUnit::Assert::IsFalse(number2 != Number::Two, pcf_current_information);
      TUnit::Assert::IsFalse(number3 != Number::Three, pcf_current_information);
      TUnit::Assert::IsFalse(number4 != Number::Four, pcf_current_information);
      
      TUnit::Assert::IsTrue(number0 != Number::Nine, pcf_current_information);
      TUnit::Assert::IsTrue(number1 != Number::Nine, pcf_current_information);
      TUnit::Assert::IsTrue(number2 != Number::Nine, pcf_current_information);
      TUnit::Assert::IsTrue(number3 != Number::Nine, pcf_current_information);
      TUnit::Assert::IsTrue(number4 != Number::Nine, pcf_current_information);
    }
    
    void SwitchCase() {
      Pet PetDog = Pet::Dog;
      switch (PetDog) {
        case Pet::Dog : TUnit::Assert::Succeed(pcf_current_information); break;
        case Pet::Cat : TUnit::Assert::Fail(pcf_current_information); break;
        case Pet::Bird : TUnit::Assert::Fail(pcf_current_information); break;
        default: TUnit::Assert::Fail(pcf_current_information); break;
      }
      
      Number number8 = Number::Eight;
      switch (number8) {
        case Number::Zero : TUnit::Assert::Fail(pcf_current_information); break;
        case Number::One : TUnit::Assert::Fail(pcf_current_information); break;
        case Number::Two : TUnit::Assert::Fail(pcf_current_information); break;
        case Number::Three : TUnit::Assert::Fail(pcf_current_information); break;
        case Number::Four : TUnit::Assert::Fail(pcf_current_information); break;
        case Number::Five : TUnit::Assert::Fail(pcf_current_information); break;
        case Number::Six : TUnit::Assert::Fail(pcf_current_information); break;
        case Number::Seven : TUnit::Assert::Fail(pcf_current_information); break;
        case Number::Eight : TUnit::Assert::Succeed(pcf_current_information); break;
        case Number::Nine : TUnit::Assert::Fail(pcf_current_information); break;
        default: TUnit::Assert::Fail(pcf_current_information); break;
      }
    }
    
    void GetName() {
      TUnit::Assert::AreEqual("Zero", Enum<Number>::GetName(Number::Zero), pcf_current_information);
      TUnit::Assert::AreEqual("One", Enum<Number>::GetName(Number::One), pcf_current_information);
      TUnit::Assert::AreEqual("Two", Enum<Number>::GetName(Number::Two), pcf_current_information);
      TUnit::Assert::AreEqual("Three", Enum<Number>::GetName(Number::Three), pcf_current_information);
      TUnit::Assert::AreEqual("Four", Enum<Number>::GetName(Number::Four), pcf_current_information);
      TUnit::Assert::AreEqual("Five", Enum<Number>::GetName(Number::Five), pcf_current_information);
      
      TUnit::Assert::AreEqual("None", Enum<Letter>::GetName(Letter::None).ToString(), pcf_current_information);
      TUnit::Assert::AreEqual("G", Enum<Letter>::GetName(Letter::G).ToString(), pcf_current_information);
      TUnit::Assert::AreEqual("A, B, C", Enum<Letter>::GetName(Letter::A|Letter::B|Letter::C).ToString(), pcf_current_information);
      
      TUnit::Assert::AreEqual("0", Enum<RGBPixel>::GetName(RGBPixel::Red), pcf_current_information);
      TUnit::Assert::AreEqual("1", Enum<RGBPixel>::GetName(RGBPixel::Green), pcf_current_information);
      TUnit::Assert::AreEqual("2", Enum<RGBPixel>::GetName(RGBPixel::Blue), pcf_current_information);
    }
    
    void GetNames() {
      TUnit::Assert::AreEqual(10, Enum<Number>::GetNames().Count(), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Zero"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("One"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Two"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Three"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Four"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Five"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Six"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Seven"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Eight"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetNames().Contains("Nine"), pcf_current_information);
      
      TUnit::Assert::AreEqual(27, Enum<Letter>::GetNames().Count(), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("None"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("A"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("B"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("C"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("D"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("E"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("F"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("G"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("H"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("I"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("J"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("K"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("L"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("M"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("N"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("O"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("P"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("Q"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("R"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("S"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("T"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("U"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("V"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("W"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("X"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("Y"), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetNames().Contains("Z"), pcf_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<RGBPixel>::GetNames().Count(), pcf_current_information);
      TUnit::Assert::AreEqual(0, Enum<NoEnum>::GetNames().Count(), pcf_current_information);
    }
    
    void GetValues() {
      TUnit::Assert::AreEqual(10, Enum<Number>::GetValues().Count(), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Zero), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::One), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Two), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Three), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Four), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Five), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Six), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Seven), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Eight), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::GetValues().Contains(Number::Nine), pcf_current_information);
      
      TUnit::Assert::AreEqual(27, Enum<Letter>::GetValues().Count(), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::None), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::A), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::B), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::C), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::D), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::E), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::F), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::G), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::H), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::I), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::J), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::K), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::L), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::M), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::N), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::O), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::P), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::Q), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::R), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::S), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::T), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::U), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::V), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::W), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::X), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::Y), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::GetValues().Contains(Letter::Z), pcf_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<RGBPixel>::GetValues().Count(), pcf_current_information);
      TUnit::Assert::AreEqual(0, Enum<NoEnum>::GetValues().Count(), pcf_current_information);
    }
    
    void HasFlag() {
      TUnit::Assert::IsTrue(Enum<Letter>(Letter::A|Letter::B|Letter::C).HasFlag(Letter::B | Letter::C), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>(Letter::A).HasFlag(0b00000000000000000000000000000001), pcf_current_information);
      TUnit::Assert::IsFalse(Enum<Letter>(Letter::None).HasFlag(Letter::A), pcf_current_information);
      TUnit::Assert::IsFalse(Enum<Letter>(Letter::None).HasFlag(0b10000000000000000000000000000000), pcf_current_information);
    }
    
    void IsDefined() {
      TUnit::Assert::IsTrue(Enum<Number>::IsDefined(Number::Two), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::IsDefined(5), pcf_current_information);
      TUnit::Assert::IsFalse(Enum<Number>::IsDefined(12), pcf_current_information);
      
      TUnit::Assert::IsTrue(Enum<Letter>::IsDefined(Letter::B), pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::IsDefined(0x00020000), pcf_current_information);
      TUnit::Assert::IsFalse(Enum<Letter>::IsDefined(0x20000000), pcf_current_information);
      TUnit::Assert::IsFalse(Enum<Letter>::IsDefined(Letter::B|Letter::C|Letter::Z), pcf_current_information);
      
      TUnit::Assert::IsFalse(Enum<NoEnum>::IsDefined(NoEnum::None), pcf_current_information);
    }
    
    void FromInt32() {
      TUnit::Assert::AreEqual(0, Enum<Number>().FromInt32(0).ToInt32(), pcf_current_information);
      TUnit::Assert::AreEqual(1, Enum<Number>().FromInt32(1).ToInt32(), pcf_current_information);
      TUnit::Assert::AreEqual(2, Enum<Number>().FromInt32(2).ToInt32(), pcf_current_information);
      TUnit::Assert::AreEqual(3, Enum<Number>().FromInt32(3).ToInt32(), pcf_current_information);
      TUnit::Assert::AreEqual(4, Enum<Number>().FromInt32(4).ToInt32(), pcf_current_information);
      TUnit::Assert::AreEqual(5, Enum<Number>().FromInt32(5).ToInt32(), pcf_current_information);
    }
    
    void Parse() {
      TUnit::Assert::AreEqual(0, (int)Enum<Number>::Parse("Zero"), pcf_current_information);
      TUnit::Assert::AreEqual(1, (int)Enum<Number>::Parse("One"), pcf_current_information);
      TUnit::Assert::AreEqual(2, (int)Enum<Number>::Parse("Two"), pcf_current_information);
      TUnit::Assert::AreEqual(3, (int)Enum<Number>::Parse("Three"), pcf_current_information);
      TUnit::Assert::AreEqual(4, (int)Enum<Number>::Parse("Four"), pcf_current_information);
      TUnit::Assert::AreEqual(5, (int)Enum<Number>::Parse("Five"), pcf_current_information);
      TUnit::Assert::Throws<FormatException>(pcf_delegate {Enum<Number>::Parse("BadValue");}, pcf_current_information);
      
      TUnit::Assert::AreEqual(0b00000000000000000000000000000000, (int)Enum<Letter>::Parse("None"), pcf_current_information);
      TUnit::Assert::AreEqual(0b00000000000000000000000000000111, (int)Enum<Letter>::Parse("A, B, C"), pcf_current_information);
      
      TUnit::Assert::AreEqual(1, (int)Enum<Number>::Parse("one", true));
      
      TUnit::Assert::Throws<FormatException>(pcf_delegate {Enum<RGBPixel>::Parse("Red");}, pcf_current_information);
      TUnit::Assert::Throws<FormatException>(pcf_delegate {Enum<RGBPixel>::Parse("Green");}, pcf_current_information);
      TUnit::Assert::Throws<FormatException>(pcf_delegate {Enum<RGBPixel>::Parse("Blue");}, pcf_current_information);
      TUnit::Assert::Throws<FormatException>(pcf_delegate {Enum<RGBPixel>::Parse("BadValue");}, pcf_current_information);
    }
    
    void ToInt32() {
      TUnit::Assert::AreEqual(0, Enum<Number>::ToInt32(Number::Zero), pcf_current_information);
      TUnit::Assert::AreEqual(1, Enum<Number>::ToInt32(Number::One), pcf_current_information);
      TUnit::Assert::AreEqual(2, Enum<Number>::ToInt32(Number::Two), pcf_current_information);
      TUnit::Assert::AreEqual(3, Enum<Number>::ToInt32(Number::Three), pcf_current_information);
      TUnit::Assert::AreEqual(4, Enum<Number>::ToInt32(Number::Four), pcf_current_information);
      TUnit::Assert::AreEqual(5, Enum<Number>::ToInt32(Number::Five), pcf_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<RGBPixel>::ToInt32(RGBPixel::Red), pcf_current_information);
      TUnit::Assert::AreEqual(1, Enum<RGBPixel>::ToInt32(RGBPixel::Green), pcf_current_information);
      TUnit::Assert::AreEqual(2, Enum<RGBPixel>::ToInt32(RGBPixel::Blue), pcf_current_information);
      
      TUnit::Assert::AreEqual(0, Enum<NoEnum>::ToInt32(NoEnum::None), pcf_current_information);
    }
    
    void ToString() {
      TUnit::Assert::AreEqual("Zero", Enum<Number>::ToString(Number::Zero), pcf_current_information);
      TUnit::Assert::AreEqual("One", Enum<Number>::ToString(Number::One), pcf_current_information);
      TUnit::Assert::AreEqual("Two", Enum<Number>::ToString(Number::Two), pcf_current_information);
      TUnit::Assert::AreEqual("Three", Enum<Number>::ToString(Number::Three), pcf_current_information);
      TUnit::Assert::AreEqual("Four", Enum<Number>::ToString(Number::Four), pcf_current_information);
      TUnit::Assert::AreEqual("Five", Enum<Number>::ToString(Number::Five), pcf_current_information);
      TUnit::Assert::AreEqual("52", Enum<Number>::ToString((Number)52), pcf_current_information);
      
      TUnit::Assert::AreEqual("None", Enum<Letter>::ToString(Letter::None), pcf_current_information);
      TUnit::Assert::AreEqual("A", Enum<Letter>::ToString(Letter::A), pcf_current_information);
      TUnit::Assert::AreEqual("B", Enum<Letter>::ToString(Letter::B), pcf_current_information);
      TUnit::Assert::AreEqual("A, B", Enum<Letter>::ToString(Letter::A|Letter::B), pcf_current_information);
      TUnit::Assert::AreEqual("D, G, I", Enum<Letter>::ToString(Letter::D|Letter::G|Letter::I), pcf_current_information);
      
      TUnit::Assert::AreEqual("0", Enum<RGBPixel>::ToString(RGBPixel::Red), pcf_current_information);
      TUnit::Assert::AreEqual("1", Enum<RGBPixel>::ToString(RGBPixel::Green), pcf_current_information);
      TUnit::Assert::AreEqual("2", Enum<RGBPixel>::ToString(RGBPixel::Blue), pcf_current_information);
      
      TUnit::Assert::AreEqual("0", Enum<NoEnum>::ToString(NoEnum::None), pcf_current_information);
    }
    
    void TryParse() {
      Number numberResult;
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Zero", numberResult));
      TUnit::Assert::AreEqual(0, (int32)numberResult, pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("One", numberResult));
      TUnit::Assert::AreEqual(1, (int32)numberResult, pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Two", numberResult));
      TUnit::Assert::AreEqual(2, (int32)numberResult, pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Three", numberResult));
      TUnit::Assert::AreEqual(3, (int32)numberResult, pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Four", numberResult));
      TUnit::Assert::AreEqual(4, (int32)numberResult, pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("Five", numberResult));
      TUnit::Assert::AreEqual(5, (int32)numberResult, pcf_current_information);
      TUnit::Assert::IsFalse(Enum<Number>::TryParse("BadValue", numberResult));
      
      Letter LetterResult;
      TUnit::Assert::IsTrue(Enum<Letter>::TryParse("None", LetterResult));
      TUnit::Assert::AreEqual(0x00000000, (int32)LetterResult, pcf_current_information);
      TUnit::Assert::IsTrue(Enum<Letter>::TryParse("A, B, C", LetterResult));
      TUnit::Assert::AreEqual(0x00000007, (int32)LetterResult, pcf_current_information);
      
      RGBPixel RGBPixelResult;
      TUnit::Assert::IsTrue(Enum<RGBPixel>::TryParse("0", RGBPixelResult));
      TUnit::Assert::AreEqual(0, (int32)RGBPixelResult, pcf_current_information);
      TUnit::Assert::IsTrue(Enum<RGBPixel>::TryParse("1", RGBPixelResult));
      TUnit::Assert::AreEqual(1, (int32)RGBPixelResult, pcf_current_information);
      TUnit::Assert::IsTrue(Enum<RGBPixel>::TryParse("2", RGBPixelResult));
      TUnit::Assert::AreEqual(2, (int32)RGBPixelResult, pcf_current_information);
      TUnit::Assert::IsFalse(Enum<RGBPixel>::TryParse("Red", RGBPixelResult));
      TUnit::Assert::IsFalse(Enum<RGBPixel>::TryParse("Green", RGBPixelResult));
      TUnit::Assert::IsFalse(Enum<RGBPixel>::TryParse("Blue", RGBPixelResult));
      TUnit::Assert::IsFalse(Enum<RGBPixel>::TryParse("BadValue", RGBPixelResult));
      
      TUnit::Assert::IsTrue(Enum<Number>::TryParse("one", true, numberResult));
      TUnit::Assert::AreEqual(1, (int32)numberResult, pcf_current_information);
    }
  };
  
  pcf_test(EnumTest, Constructor);
  pcf_test(EnumTest, Equality);
  pcf_test(EnumTest, SwitchCase);
  pcf_test(EnumTest, GetName);
  pcf_test(EnumTest, GetNames);
  pcf_test(EnumTest, GetValues);
  pcf_test(EnumTest, HasFlag);
  pcf_test(EnumTest, IsDefined);
  pcf_test(EnumTest, FromInt32);
  pcf_test(EnumTest, Parse);
  pcf_test(EnumTest, ToInt32);
  pcf_test(EnumTest, ToString);
  pcf_test(EnumTest, TryParse);
}
