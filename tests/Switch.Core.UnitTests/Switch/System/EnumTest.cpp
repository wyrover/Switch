#include <Switch/System/Enum.hpp>
#include <gtest/gtest.h>

using namespace System;

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
  
  inline Number& operator+=(Number& lhs, Number rhs) {lhs = static_cast<Number>(static_cast<int32>(lhs) + static_cast<int32>(rhs)); return lhs;}
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
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SwitchUnitTests::Pet::None, "None"}, {(int64)SwitchUnitTests::Pet::Dog, "Dog"}, {(int64)SwitchUnitTests::Pet::Cat, "Cat"}, {(int64)SwitchUnitTests::Pet::Bird, "Bird"}};
    flags = false;
  }
};

template<>
class EnumToStrings<SwitchUnitTests::Number> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SwitchUnitTests::Number::Zero, "Zero"}, {(int64)SwitchUnitTests::Number::One, "One"}, {(int64)SwitchUnitTests::Number::Two, "Two"}, {(int64)SwitchUnitTests::Number::Three, "Three"}, {(int64)SwitchUnitTests::Number::Four, "Four"}, {(int64)SwitchUnitTests::Number::Five, "Five"}, {(int64)SwitchUnitTests::Number::Six, "Six"}, {(int64)SwitchUnitTests::Number::Seven, "Seven"}, {(int64)SwitchUnitTests::Number::Eight, "Eight"}, {(int64)SwitchUnitTests::Number::Nine, "Nine"}};
    flags = false;
  }
};

template <> class AddFlagOperators<SwitchUnitTests::Letter> : public TrueType {};

template<>
class EnumToStrings<SwitchUnitTests::Letter> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SwitchUnitTests::Letter::None, "None"}, {(int64)SwitchUnitTests::Letter::A, "A"}, {(int64)SwitchUnitTests::Letter::B, "B"}, {(int64)SwitchUnitTests::Letter::C, "C"}, {(int64)SwitchUnitTests::Letter::D, "D"}, {(int64)SwitchUnitTests::Letter::E, "E"}, {(int64)SwitchUnitTests::Letter::F, "F"}, {(int64)SwitchUnitTests::Letter::G, "G"}, {(int64)SwitchUnitTests::Letter::H, "H"}, {(int64)SwitchUnitTests::Letter::I, "I"}, {(int64)SwitchUnitTests::Letter::J, "J"}, {(int64)SwitchUnitTests::Letter::K, "K"}, {(int64)SwitchUnitTests::Letter::L, "L"}, {(int64)SwitchUnitTests::Letter::M, "M"}, {(int64)SwitchUnitTests::Letter::N, "N"}, {(int64)SwitchUnitTests::Letter::O, "O"}, {(int64)SwitchUnitTests::Letter::P, "P"}, {(int64)SwitchUnitTests::Letter::Q, "Q"}, {(int64)SwitchUnitTests::Letter::R, "R"}, {(int64)SwitchUnitTests::Letter::S, "S"}, {(int64)SwitchUnitTests::Letter::T, "T"}, {(int64)SwitchUnitTests::Letter::U, "U"}, {(int64)SwitchUnitTests::Letter::V, "V"}, {(int64)SwitchUnitTests::Letter::W, "W"}, {(int64)SwitchUnitTests::Letter::X, "X"}, {(int64)SwitchUnitTests::Letter::Y, "Y"}, {(int64)SwitchUnitTests::Letter::Z, "Z"}};
    flags = true;
  }
};
/// @endcond

namespace SwitchUnitTests {
  TEST(EnumTest, Constructor) {
    ASSERT_EQ(0, Enum<Number>::ToInt32(Number::Zero));
    ASSERT_EQ(1, Enum<Number>::ToInt32(Number::One));
    ASSERT_EQ(2, Enum<Number>::ToInt32(Number::Two));
    ASSERT_EQ(3, Enum<Number>::ToInt32((Number)3));
    ASSERT_EQ(24, Enum<Number>::ToInt32((Number)24));
    
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
    
    ASSERT_EQ(0, Enum<Number>::ToInt32(number0));
    ASSERT_EQ(1, Enum<Number>::ToInt32(number1));
    ASSERT_EQ(2, Enum<Number>::ToInt32(number2));
    ASSERT_EQ(3, Enum<Number>::ToInt32(number3));
    ASSERT_EQ(4, Enum<Number>::ToInt32(number4));
    ASSERT_EQ(5, Enum<Number>::ToInt32(number5));
    ASSERT_EQ(6, Enum<Number>::ToInt32(number6));
    ASSERT_EQ(7, Enum<Number>::ToInt32(number7));
    ASSERT_EQ(8, Enum<Number>::ToInt32(number8));
    ASSERT_EQ(9, Enum<Number>::ToInt32(number9));
    
    ASSERT_EQ(0b00000000000000000000000000000000, Enum<Letter>::ToInt32(Letter::None));
    ASSERT_EQ(0b00000000000000000000000000001000, Enum<Letter>::ToInt32(Letter::D));
    ASSERT_EQ(0b00000000000000000000000000000111, Enum<Letter>::ToInt32(Letter::A | Letter::B | Letter::C));
    ASSERT_EQ(0b00000000000000000000100000000000, Enum<Letter>::ToInt32((Letter)0b00000000000000000000100000000000));
    ASSERT_EQ(0b01100000000000000000000000000000, Enum<Letter>::ToInt32((Letter)0b01100000000000000000000000000000));
    
    Letter letterNone = Letter::None;
    Letter letterAB = Letter::A | Letter::B;
    Letter letterBC = (Letter)Enum<Letter>::Parse("B, C");
    Letter letterCD = (Letter)Enum<Letter>::Parse("c, d", true);
    
    ASSERT_EQ(0b00000000000000000000000000000000, Enum<Letter>::ToInt32(letterNone));
    ASSERT_EQ(0b00000000000000000000000000000011, Enum<Letter>::ToInt32(letterAB));
    ASSERT_EQ(0b00000000000000000000000000000110, Enum<Letter>::ToInt32(letterBC));
    ASSERT_EQ(0b00000000000000000000000000001100, Enum<Letter>::ToInt32(letterCD));
    
    ASSERT_EQ(0, Enum<RGBPixel>::ToInt32(RGBPixel::Red));
    ASSERT_EQ(1, Enum<RGBPixel>::ToInt32(RGBPixel::Green));
    ASSERT_EQ(2, Enum<RGBPixel>::ToInt32(RGBPixel::Blue));
    ASSERT_EQ(1, Enum<RGBPixel>::ToInt32((RGBPixel)1));
    ASSERT_EQ(5, Enum<RGBPixel>::ToInt32((RGBPixel)5));
  }
  
  TEST(EnumTest, Equality) {
    Number number0 = Number::Zero;
    Number number1 = Number::One;
    Number number2 = (Number)Enum<Number>::Parse("Two");
    Number number3 = (Number)Enum<Number>::Parse("three", true);
    Number number4 = (Number)4;
    
    ASSERT_TRUE(number0 == Number::Zero);
    ASSERT_TRUE(number1 == Number::One);
    ASSERT_TRUE(number2 == Number::Two);
    ASSERT_TRUE(number3 == Number::Three);
    ASSERT_TRUE(number4 == Number::Four);
    
    ASSERT_FALSE(number0 == Number::Nine);
    ASSERT_FALSE(number1 == Number::Nine);
    ASSERT_FALSE(number2 == Number::Nine);
    ASSERT_FALSE(number3 == Number::Nine);
    ASSERT_FALSE(number4 == Number::Nine);
    
    ASSERT_FALSE(number0 != Number::Zero);
    ASSERT_FALSE(number1 != Number::One);
    ASSERT_FALSE(number2 != Number::Two);
    ASSERT_FALSE(number3 != Number::Three);
    ASSERT_FALSE(number4 != Number::Four);
    
    ASSERT_TRUE(number0 != Number::Nine);
    ASSERT_TRUE(number1 != Number::Nine);
    ASSERT_TRUE(number2 != Number::Nine);
    ASSERT_TRUE(number3 != Number::Nine);
    ASSERT_TRUE(number4 != Number::Nine);
  }
  
  TEST(EnumTest, SwitchCase) {
    Pet PetDog = Pet::Dog;
    switch(PetDog) {
    case Pet::Dog : SUCCEED(); break;
    case Pet::Cat : FAIL(); break;
    case Pet::Bird : FAIL(); break;
    default: FAIL(); break;
    }
    
    Number number8 = Number::Eight;
    switch(number8) {
    case Number::Zero : FAIL(); break;
    case Number::One : FAIL(); break;
    case Number::Two : FAIL(); break;
    case Number::Three : FAIL(); break;
    case Number::Four : FAIL(); break;
    case Number::Five : FAIL(); break;
    case Number::Six : FAIL(); break;
    case Number::Seven : FAIL(); break;
    case Number::Eight : SUCCEED(); break;
    case Number::Nine : FAIL(); break;
    default: FAIL(); break;
    }
  }
  
  TEST(EnumTest, GetName) {
    ASSERT_EQ("Zero", Enum<Number>::GetName(Number::Zero));
    ASSERT_EQ("One", Enum<Number>::GetName(Number::One));
    ASSERT_EQ("Two", Enum<Number>::GetName(Number::Two));
    ASSERT_EQ("Three", Enum<Number>::GetName(Number::Three));
    ASSERT_EQ("Four", Enum<Number>::GetName(Number::Four));
    ASSERT_EQ("Five", Enum<Number>::GetName(Number::Five));
    
    ASSERT_EQ("None", Enum<Letter>::GetName(Letter::None).ToString());
    ASSERT_EQ("G", Enum<Letter>::GetName(Letter::G).ToString());
    ASSERT_EQ("A, B, C", Enum<Letter>::GetName(Letter::A | Letter::B | Letter::C).ToString());
    
    ASSERT_EQ("0", Enum<RGBPixel>::GetName(RGBPixel::Red));
    ASSERT_EQ("1", Enum<RGBPixel>::GetName(RGBPixel::Green));
    ASSERT_EQ("2", Enum<RGBPixel>::GetName(RGBPixel::Blue));
  }
  
  TEST(EnumTest, GetNames) {
    ASSERT_EQ(10, Enum<Number>::GetNames().Count());
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Zero"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("One"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Two"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Three"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Four"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Five"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Six"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Seven"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Eight"));
    ASSERT_TRUE(Enum<Number>::GetNames().Contains("Nine"));
    
    ASSERT_EQ(27, Enum<Letter>::GetNames().Count());
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("None"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("A"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("B"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("C"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("D"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("E"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("F"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("G"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("H"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("I"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("J"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("K"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("L"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("M"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("N"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("O"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("P"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("Q"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("R"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("S"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("T"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("U"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("V"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("W"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("X"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("Y"));
    ASSERT_TRUE(Enum<Letter>::GetNames().Contains("Z"));
    
    ASSERT_EQ(0, Enum<RGBPixel>::GetNames().Count());
    ASSERT_EQ(0, Enum<NoEnum>::GetNames().Count());
  }
  
  TEST(EnumTest, GetValues) {
    ASSERT_EQ(10, Enum<Number>::GetValues().Count());
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Zero));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::One));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Two));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Three));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Four));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Five));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Six));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Seven));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Eight));
    ASSERT_TRUE(Enum<Number>::GetValues().Contains(Number::Nine));
    
    ASSERT_EQ(27, Enum<Letter>::GetValues().Count());
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::None));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::A));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::B));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::C));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::D));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::E));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::F));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::G));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::H));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::I));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::J));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::K));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::L));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::M));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::N));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::O));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::P));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::Q));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::R));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::S));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::T));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::U));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::V));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::W));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::X));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::Y));
    ASSERT_TRUE(Enum<Letter>::GetValues().Contains(Letter::Z));
    
    ASSERT_EQ(0, Enum<RGBPixel>::GetValues().Count());
    ASSERT_EQ(0, Enum<NoEnum>::GetValues().Count());
  }
  
  TEST(EnumTest, HasFlag) {
    ASSERT_TRUE(Enum<Letter>(Letter::A | Letter::B | Letter::C).HasFlag(Letter::B | Letter::C));
    ASSERT_TRUE(Enum<Letter>(Letter::A).HasFlag(0b00000000000000000000000000000001));
    ASSERT_FALSE(Enum<Letter>(Letter::None).HasFlag(Letter::A));
    ASSERT_FALSE(Enum<Letter>(Letter::None).HasFlag(0b10000000000000000000000000000000));
  }
  
  TEST(EnumTest, IsDefined) {
    ASSERT_TRUE(Enum<Number>::IsDefined(Number::Two));
    ASSERT_TRUE(Enum<Number>::IsDefined(5));
    ASSERT_FALSE(Enum<Number>::IsDefined(12));
    
    ASSERT_TRUE(Enum<Letter>::IsDefined(Letter::B));
    ASSERT_TRUE(Enum<Letter>::IsDefined(0x00020000));
    ASSERT_FALSE(Enum<Letter>::IsDefined(0x20000000));
    ASSERT_FALSE(Enum<Letter>::IsDefined(Letter::B | Letter::C | Letter::Z));
    
    ASSERT_FALSE(Enum<NoEnum>::IsDefined(NoEnum::None));
  }
  
  TEST(EnumTest, FromInt32) {
    ASSERT_EQ(0, Enum<Number>().FromInt32(0).ToInt32());
    ASSERT_EQ(1, Enum<Number>().FromInt32(1).ToInt32());
    ASSERT_EQ(2, Enum<Number>().FromInt32(2).ToInt32());
    ASSERT_EQ(3, Enum<Number>().FromInt32(3).ToInt32());
    ASSERT_EQ(4, Enum<Number>().FromInt32(4).ToInt32());
    ASSERT_EQ(5, Enum<Number>().FromInt32(5).ToInt32());
  }
  
  TEST(EnumTest, Parse) {
    ASSERT_EQ(0, (int)Enum<Number>::Parse("Zero"));
    ASSERT_EQ(1, (int)Enum<Number>::Parse("One"));
    ASSERT_EQ(2, (int)Enum<Number>::Parse("Two"));
    ASSERT_EQ(3, (int)Enum<Number>::Parse("Three"));
    ASSERT_EQ(4, (int)Enum<Number>::Parse("Four"));
    ASSERT_EQ(5, (int)Enum<Number>::Parse("Five"));
    ASSERT_THROW(Enum<Number>::Parse("BadValue"), FormatException);
    
    ASSERT_EQ(0b00000000000000000000000000000000, (int)Enum<Letter>::Parse("None"));
    ASSERT_EQ(0b00000000000000000000000000000111, (int)Enum<Letter>::Parse("A, B, C"));
    
    ASSERT_EQ(1, (int)Enum<Number>::Parse("one", true));
    
    ASSERT_THROW(Enum<RGBPixel>::Parse("Red"), FormatException);
    ASSERT_THROW(Enum<RGBPixel>::Parse("Green"), FormatException);
    ASSERT_THROW(Enum<RGBPixel>::Parse("Blue"), FormatException);
    ASSERT_THROW(Enum<RGBPixel>::Parse("BadValue"), FormatException);
  }
  
  TEST(EnumTest, ToInt32) {
    ASSERT_EQ(0, Enum<Number>::ToInt32(Number::Zero));
    ASSERT_EQ(1, Enum<Number>::ToInt32(Number::One));
    ASSERT_EQ(2, Enum<Number>::ToInt32(Number::Two));
    ASSERT_EQ(3, Enum<Number>::ToInt32(Number::Three));
    ASSERT_EQ(4, Enum<Number>::ToInt32(Number::Four));
    ASSERT_EQ(5, Enum<Number>::ToInt32(Number::Five));
    
    ASSERT_EQ(0, Enum<RGBPixel>::ToInt32(RGBPixel::Red));
    ASSERT_EQ(1, Enum<RGBPixel>::ToInt32(RGBPixel::Green));
    ASSERT_EQ(2, Enum<RGBPixel>::ToInt32(RGBPixel::Blue));
    
    ASSERT_EQ(0, Enum<NoEnum>::ToInt32(NoEnum::None));
  }
  
  TEST(EnumTest, ToString) {
    ASSERT_EQ("Zero", Enum<Number>::ToString(Number::Zero));
    ASSERT_EQ("One", Enum<Number>::ToString(Number::One));
    ASSERT_EQ("Two", Enum<Number>::ToString(Number::Two));
    ASSERT_EQ("Three", Enum<Number>::ToString(Number::Three));
    ASSERT_EQ("Four", Enum<Number>::ToString(Number::Four));
    ASSERT_EQ("Five", Enum<Number>::ToString(Number::Five));
    ASSERT_EQ("52", Enum<Number>::ToString((Number)52));
    
    ASSERT_EQ("None", Enum<Letter>::ToString(Letter::None));
    ASSERT_EQ("A", Enum<Letter>::ToString(Letter::A));
    ASSERT_EQ("B", Enum<Letter>::ToString(Letter::B));
    ASSERT_EQ("A, B", Enum<Letter>::ToString(Letter::A | Letter::B));
    //ASSERT_EQ("D, G, I", Enum<Letter>::ToString(Letter::D|Letter::G|Letter::I));
    
    ASSERT_EQ("0", Enum<RGBPixel>::ToString(RGBPixel::Red));
    ASSERT_EQ("1", Enum<RGBPixel>::ToString(RGBPixel::Green));
    ASSERT_EQ("2", Enum<RGBPixel>::ToString(RGBPixel::Blue));
    
    ASSERT_EQ("0", Enum<NoEnum>::ToString(NoEnum::None));
  }
  
  TEST(EnumTest, TryParse) {
    Number numberResult;
    ASSERT_TRUE(Enum<Number>::TryParse("Zero", numberResult));
    ASSERT_EQ(0, (int32)numberResult);
    ASSERT_TRUE(Enum<Number>::TryParse("One", numberResult));
    ASSERT_EQ(1, (int32)numberResult);
    ASSERT_TRUE(Enum<Number>::TryParse("Two", numberResult));
    ASSERT_EQ(2, (int32)numberResult);
    ASSERT_TRUE(Enum<Number>::TryParse("Three", numberResult));
    ASSERT_EQ(3, (int32)numberResult);
    ASSERT_TRUE(Enum<Number>::TryParse("Four", numberResult));
    ASSERT_EQ(4, (int32)numberResult);
    ASSERT_TRUE(Enum<Number>::TryParse("Five", numberResult));
    ASSERT_EQ(5, (int32)numberResult);
    ASSERT_FALSE(Enum<Number>::TryParse("BadValue", numberResult));
    
    Letter LetterResult;
    ASSERT_TRUE(Enum<Letter>::TryParse("None", LetterResult));
    ASSERT_EQ(0x00000000, (int32)LetterResult);
    ASSERT_TRUE(Enum<Letter>::TryParse("A, B, C", LetterResult));
    ASSERT_EQ(0x00000007, (int32)LetterResult);
    
    RGBPixel RGBPixelResult;
    ASSERT_TRUE(Enum<RGBPixel>::TryParse("0", RGBPixelResult));
    ASSERT_EQ(0, (int32)RGBPixelResult);
    ASSERT_TRUE(Enum<RGBPixel>::TryParse("1", RGBPixelResult));
    ASSERT_EQ(1, (int32)RGBPixelResult);
    ASSERT_TRUE(Enum<RGBPixel>::TryParse("2", RGBPixelResult));
    ASSERT_EQ(2, (int32)RGBPixelResult);
    ASSERT_FALSE(Enum<RGBPixel>::TryParse("Red", RGBPixelResult));
    ASSERT_FALSE(Enum<RGBPixel>::TryParse("Green", RGBPixelResult));
    ASSERT_FALSE(Enum<RGBPixel>::TryParse("Blue", RGBPixelResult));
    ASSERT_FALSE(Enum<RGBPixel>::TryParse("BadValue", RGBPixelResult));
    
    ASSERT_TRUE(Enum<Number>::TryParse("one", true, numberResult));
    ASSERT_EQ(1, (int32)numberResult);
  }
}

