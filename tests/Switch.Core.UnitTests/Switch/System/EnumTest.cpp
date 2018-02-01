#include <Switch/System/Enum.hpp>
#include <Switch/System/String.hpp>
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
struct EnumRegister<SwitchUnitTests::Pet> {
  void operator()(System::Collections::Generic::IDictionary<SwitchUnitTests::Pet, string>& values, bool& flags) {
    values[SwitchUnitTests::Pet::None] = "None";
    values[SwitchUnitTests::Pet::Dog] = "Dog";
    values[SwitchUnitTests::Pet::Cat] = "Cat";
    values[SwitchUnitTests::Pet::Bird] = "Bird";
    flags = false;
  }
};

template<>
struct EnumRegister<SwitchUnitTests::Number> {
  void operator()(System::Collections::Generic::IDictionary<SwitchUnitTests::Number, string>& values, bool& flags) {
    values[SwitchUnitTests::Number::Zero] = "Zero";
    values[SwitchUnitTests::Number::One] = "One";
    values[SwitchUnitTests::Number::Two] = "Two";
    values[SwitchUnitTests::Number::Three] = "Three";
    values[SwitchUnitTests::Number::Four] = "Four";
    values[SwitchUnitTests::Number::Five] = "Five";
    values[SwitchUnitTests::Number::Six] = "Six";
    values[SwitchUnitTests::Number::Seven] = "Seven";
    values[SwitchUnitTests::Number::Eight] = "Eight";
    values[SwitchUnitTests::Number::Nine] = "Nine";
    flags = false;
  }
};

template <> class AddFlagOperators<SwitchUnitTests::Letter> : public TrueType {};

template<>
struct EnumRegister<SwitchUnitTests::Letter> {
  void operator()(System::Collections::Generic::IDictionary<SwitchUnitTests::Letter, string>& values, bool& flags) {
    values[SwitchUnitTests::Letter::None] = "None";
    values[SwitchUnitTests::Letter::A] = "A";
    values[SwitchUnitTests::Letter::B] = "B";
    values[SwitchUnitTests::Letter::C] = "C";
    values[SwitchUnitTests::Letter::D] = "D";
    values[SwitchUnitTests::Letter::E] = "E";
    values[SwitchUnitTests::Letter::F] = "F";
    values[SwitchUnitTests::Letter::G] = "G";
    values[SwitchUnitTests::Letter::H] = "H";
    values[SwitchUnitTests::Letter::I] = "I";
    values[SwitchUnitTests::Letter::J] = "J";
    values[SwitchUnitTests::Letter::K] = "K";
    values[SwitchUnitTests::Letter::L] = "L";
    values[SwitchUnitTests::Letter::M] = "M";
    values[SwitchUnitTests::Letter::N] = "N";
    values[SwitchUnitTests::Letter::O] = "O";
    values[SwitchUnitTests::Letter::P] = "P";
    values[SwitchUnitTests::Letter::Q] = "Q";
    values[SwitchUnitTests::Letter::R] = "R";
    values[SwitchUnitTests::Letter::S] = "S";
    values[SwitchUnitTests::Letter::T] = "T";
    values[SwitchUnitTests::Letter::U] = "U";
    values[SwitchUnitTests::Letter::V] = "V";
    values[SwitchUnitTests::Letter::W] = "W";
    values[SwitchUnitTests::Letter::X] = "X";
    values[SwitchUnitTests::Letter::Y] = "Y";
    values[SwitchUnitTests::Letter::Z] = "Z";
    flags = true;
  }
};
/// @endcond

namespace SwitchUnitTests {
  TEST(EnumTest, Constructor) {
    //ASSERT_EQ(0, Enum<Number>::ToInt32(Number::Zero));
    //ASSERT_EQ(1, Enum<Number>::ToInt32(Number::One));
    //ASSERT_EQ(2, Enum<Number>::ToInt32(Number::Two));
    //ASSERT_EQ(3, Enum<Number>::ToInt32((Number)3));
    //ASSERT_EQ(24, Enum<Number>::ToInt32((Number)24));

    //Number number0 = Number::Zero;
    //Number number1 = Number::One;
    //Number number2 = Enum<>::Parse<Number>("Two");
    //Number number3 = Enum<>::Parse<Number>("three", true);
    //Number number4 = (Number)4;
    //Number number5 = Number(Number::Five);
    //Number number6 = (Number)6;
    //Number number7 = Number(Number(7));
    //Number number8 = Number::Zero;
    //Number number9 = Number::Zero;

    //number8 |= Number(8);
    //number9 += Number::Nine;

    //ASSERT_EQ(0, Enum<Number>::ToInt32(number0));
    //ASSERT_EQ(1, Enum<Number>::ToInt32(number1));
    //ASSERT_EQ(2, Enum<Number>::ToInt32(number2));
    //ASSERT_EQ(3, Enum<Number>::ToInt32(number3));
    //ASSERT_EQ(4, Enum<Number>::ToInt32(number4));
    //ASSERT_EQ(5, Enum<Number>::ToInt32(number5));
    //ASSERT_EQ(6, Enum<Number>::ToInt32(number6));
    //ASSERT_EQ(7, Enum<Number>::ToInt32(number7));
    //ASSERT_EQ(8, Enum<Number>::ToInt32(number8));
    //ASSERT_EQ(9, Enum<Number>::ToInt32(number9));

    //ASSERT_EQ(0b00000000000000000000000000000000, Enum<Letter>::ToInt32(Letter::None));
    //ASSERT_EQ(0b00000000000000000000000000001000, Enum<Letter>::ToInt32(Letter::D));
    //ASSERT_EQ(0b00000000000000000000000000000111, Enum<Letter>::ToInt32(Letter::A | Letter::B | Letter::C));
    //ASSERT_EQ(0b00000000000000000000100000000000, Enum<Letter>::ToInt32((Letter)0b00000000000000000000100000000000));
    //ASSERT_EQ(0b01100000000000000000000000000000, Enum<Letter>::ToInt32((Letter)0b01100000000000000000000000000000));

    //Letter letterNone = Letter::None;
    //Letter letterAB = Letter::A | Letter::B;
    //Letter letterBC = Enum<>::Parse<Letter>("B, C");
    //Letter letterCD = Enum<>::Parse<Letter>("c, d", true);

    //ASSERT_EQ(0b00000000000000000000000000000000, Enum<Letter>::ToInt32(letterNone));
    //ASSERT_EQ(0b00000000000000000000000000000011, Enum<Letter>::ToInt32(letterAB));
    //ASSERT_EQ(0b00000000000000000000000000000110, Enum<Letter>::ToInt32(letterBC));
    //ASSERT_EQ(0b00000000000000000000000000001100, Enum<Letter>::ToInt32(letterCD));

    //ASSERT_EQ(0, Enum<RGBPixel>::ToInt32(RGBPixel::Red));
    //ASSERT_EQ(1, Enum<RGBPixel>::ToInt32(RGBPixel::Green));
    //ASSERT_EQ(2, Enum<RGBPixel>::ToInt32(RGBPixel::Blue));
    //ASSERT_EQ(1, Enum<RGBPixel>::ToInt32((RGBPixel)1));
    //ASSERT_EQ(5, Enum<RGBPixel>::ToInt32((RGBPixel)5));
  }

  TEST(EnumTest, Equality) {
    Number number0 = Number::Zero;
    Number number1 = Number::One;
    Number number2 = Enum<>::Parse<Number>("Two");
    Number number3 = Enum<>::Parse<Number>("three", true);
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
    switch (PetDog) {
    case Pet::Dog : SUCCEED(); break;
    case Pet::Cat : FAIL(); break;
    case Pet::Bird : FAIL(); break;
    default: FAIL(); break;
    }

    Number number8 = Number::Eight;
    switch (number8) {
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
    ASSERT_EQ("Zero", Enum<>::GetName(Number::Zero));
    ASSERT_EQ("One", Enum<>::GetName(Number::One));
    ASSERT_EQ("Two", Enum<>::GetName(Number::Two));
    ASSERT_EQ("Three", Enum<>::GetName(Number::Three));
    ASSERT_EQ("Four", Enum<>::GetName(Number::Four));
    ASSERT_EQ("Five", Enum<>::GetName(Number::Five));

    ASSERT_EQ("None", Enum<>::GetName(Letter::None));
    ASSERT_EQ("G", Enum<>::GetName(Letter::G));
    ASSERT_EQ("A, B, C", Enum<>::GetName(Letter::A | Letter::B | Letter::C));

    ASSERT_EQ("0", Enum<>::GetName(RGBPixel::Red));
    ASSERT_EQ("1", Enum<>::GetName(RGBPixel::Green));
    ASSERT_EQ("2", Enum<>::GetName(RGBPixel::Blue));
  }

  TEST(EnumTest, GetNames) {
    ASSERT_EQ(10, Enum<>::GetNames<Number>().Count());
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Zero"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("One"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Two"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Three"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Four"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Five"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Six"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Seven"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Eight"));
    ASSERT_TRUE(Enum<>::GetNames<Number>().Contains("Nine"));

    ASSERT_EQ(27, Enum<>::GetNames<Letter>().Count());
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("None"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("A"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("B"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("C"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("D"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("E"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("F"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("G"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("H"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("I"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("J"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("K"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("L"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("M"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("N"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("O"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("P"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("Q"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("R"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("S"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("T"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("U"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("V"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("W"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("X"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("Y"));
    ASSERT_TRUE(Enum<>::GetNames<Letter>().Contains("Z"));

    ASSERT_EQ(0, Enum<>::GetNames<RGBPixel>().Count());
    ASSERT_EQ(0, Enum<>::GetNames<NoEnum>().Count());
  }

  TEST(EnumTest, GetValues) {
    ASSERT_EQ(10, Enum<>::GetValues<Number>().Count());
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Zero));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::One));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Two));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Three));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Four));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Five));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Six));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Seven));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Eight));
    ASSERT_TRUE(Enum<>::GetValues<Number>().Contains(Number::Nine));

    ASSERT_EQ(27, Enum<>::GetValues<Letter>().Count());
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::None));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::A));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::B));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::C));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::D));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::E));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::F));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::G));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::H));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::I));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::J));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::K));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::L));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::M));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::N));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::O));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::P));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::Q));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::R));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::S));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::T));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::U));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::V));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::W));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::X));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::Y));
    ASSERT_TRUE(Enum<>::GetValues<Letter>().Contains(Letter::Z));

    ASSERT_EQ(0, Enum<>::GetValues<RGBPixel>().Count());
    ASSERT_EQ(0, Enum<>::GetValues<NoEnum>().Count());
  }

  TEST(EnumTest, HasFlag) {
    ASSERT_TRUE(Enum<Letter>(Letter::A | Letter::B | Letter::C).HasFlag(Letter::B | Letter::C));
    ASSERT_TRUE(Enum<Letter>(Letter::A).HasFlag((Letter)0b00000000000000000000000000000001));
    ASSERT_FALSE(Enum<Letter>(Letter::None).HasFlag(Letter::A));
    ASSERT_FALSE(Enum<Letter>(Letter::None).HasFlag((Letter)0b10000000000000000000000000000000));
  }

  TEST(EnumTest, IsDefined) {
    ASSERT_TRUE(Enum<>::IsDefined<Number>(Number::Two));
    ASSERT_TRUE(Enum<>::IsDefined<Number>((Number)5));
    ASSERT_FALSE(Enum<>::IsDefined<Number>((Number)12));

    ASSERT_TRUE(Enum<>::IsDefined<Letter>(Letter::B));
    ASSERT_TRUE(Enum<>::IsDefined<Letter>((Letter)0x00020000));
    ASSERT_FALSE(Enum<>::IsDefined<Letter>((Letter)0x20000000));
    ASSERT_FALSE(Enum<>::IsDefined<Letter>(Letter::B | Letter::C | Letter::Z));

    ASSERT_FALSE(Enum<>::IsDefined<NoEnum>(NoEnum::None));
  }

  TEST(EnumTest, Parse) {
    ASSERT_EQ(0, (int)Enum<>::Parse<Number>("Zero"));
    ASSERT_EQ(1, (int)Enum<>::Parse<Number>("One"));
    ASSERT_EQ(2, (int)Enum<>::Parse<Number>("Two"));
    ASSERT_EQ(3, (int)Enum<>::Parse<Number>("Three"));
    ASSERT_EQ(4, (int)Enum<>::Parse<Number>("Four"));
    ASSERT_EQ(5, (int)Enum<>::Parse<Number>("Five"));
    ASSERT_THROW(Enum<>::Parse<Number>("BadValue"), FormatException);

    ASSERT_EQ(0b00000000000000000000000000000000, (int)Enum<>::Parse<Letter>("None"));
    ASSERT_EQ(0b00000000000000000000000000000111, (int)Enum<>::Parse<Letter>("A, B, C"));

    ASSERT_EQ(1, (int)Enum<>::Parse<Number>("one", true));

    ASSERT_THROW(Enum<>::Parse<RGBPixel>("Red"), FormatException);
    ASSERT_THROW(Enum<>::Parse<RGBPixel>("Green"), FormatException);
    ASSERT_THROW(Enum<>::Parse<RGBPixel>("Blue"), FormatException);
    ASSERT_THROW(Enum<>::Parse<RGBPixel>("BadValue"), FormatException);
  }

  TEST(EnumTest, ToString) {
    ASSERT_EQ("Zero", Enum<Number>(Number::Zero).ToString());
    ASSERT_EQ("One", Enum<Number>(Number::One).ToString());
    ASSERT_EQ("Two", Enum<Number>(Number::Two).ToString());
    ASSERT_EQ("Three", Enum<Number>(Number::Three).ToString());
    ASSERT_EQ("Four", Enum<Number>(Number::Four).ToString());
    ASSERT_EQ("Five", Enum<Number>(Number::Five).ToString());
    ASSERT_EQ("52", Enum<Number>((Number)52).ToString());

    ASSERT_EQ("None", Enum<Letter>(Letter::None).ToString());
    ASSERT_EQ("A", Enum<Letter>(Letter::A).ToString());
    ASSERT_EQ("B", Enum<Letter>(Letter::B).ToString());
    ASSERT_EQ("A, B", Enum<Letter>(Letter::A | Letter::B).ToString());
    ASSERT_EQ("D, G, I", Enum<Letter>(Letter::D | Letter::G | Letter::I).ToString());

    ASSERT_EQ("0", Enum<RGBPixel>(RGBPixel::Red).ToString());
    ASSERT_EQ("1", Enum<RGBPixel>(RGBPixel::Green).ToString());
    ASSERT_EQ("2", Enum<RGBPixel>(RGBPixel::Blue).ToString());

    ASSERT_EQ("0", Enum<NoEnum>(NoEnum::None).ToString());
  }

  TEST(EnumTest, TryParse) {
    Number numberResult;
    ASSERT_TRUE(Enum<>::TryParse<Number>("Zero", numberResult));
    ASSERT_EQ(0, (int32)numberResult);
    ASSERT_TRUE(Enum<>::TryParse<Number>("One", numberResult));
    ASSERT_EQ(1, (int32)numberResult);
    ASSERT_TRUE(Enum<>::TryParse<Number>("Two", numberResult));
    ASSERT_EQ(2, (int32)numberResult);
    ASSERT_TRUE(Enum<>::TryParse<Number>("Three", numberResult));
    ASSERT_EQ(3, (int32)numberResult);
    ASSERT_TRUE(Enum<>::TryParse<Number>("Four", numberResult));
    ASSERT_EQ(4, (int32)numberResult);
    ASSERT_TRUE(Enum<>::TryParse<Number>("Five", numberResult));
    ASSERT_EQ(5, (int32)numberResult);
    ASSERT_FALSE(Enum<>::TryParse<Number>("BadValue", numberResult));

    Letter LetterResult;
    ASSERT_TRUE(Enum<>::TryParse<Letter>("None", LetterResult));
    ASSERT_EQ(0x00000000, (int32)LetterResult);
    ASSERT_TRUE(Enum<>::TryParse<Letter>("A, B, C", LetterResult));
    ASSERT_EQ(0x00000007, (int32)LetterResult);

    RGBPixel RGBPixelResult;
    ASSERT_TRUE(Enum<>::TryParse<RGBPixel>("0", RGBPixelResult));
    ASSERT_EQ(0, (int32)RGBPixelResult);
    ASSERT_TRUE(Enum<>::TryParse<RGBPixel>("1", RGBPixelResult));
    ASSERT_EQ(1, (int32)RGBPixelResult);
    ASSERT_TRUE(Enum<>::TryParse<RGBPixel>("2", RGBPixelResult));
    ASSERT_EQ(2, (int32)RGBPixelResult);
    ASSERT_FALSE(Enum<>::TryParse<RGBPixel>("Red", RGBPixelResult));
    ASSERT_FALSE(Enum<>::TryParse<RGBPixel>("Green", RGBPixelResult));
    ASSERT_FALSE(Enum<>::TryParse<RGBPixel>("Blue", RGBPixelResult));
    ASSERT_FALSE(Enum<>::TryParse<RGBPixel>("BadValue", RGBPixelResult));

    ASSERT_TRUE(Enum<>::TryParse<Number>("one", true, numberResult));
    ASSERT_EQ(1, (int32)numberResult);
  }
}

