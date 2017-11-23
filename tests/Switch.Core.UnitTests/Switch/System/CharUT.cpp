#include <Switch/System/Char.hpp>
#include <Switch/System/FormatException.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(CharTest, Constructor) {
    ASSERT_EQ(Char(), Char('\0'));
    ASSERT_EQ(Char('r'), Char('r'));
    ASSERT_EQ(Char('F'), Char('F'));
    ASSERT_EQ(Char(Char('T')), Char('T'));
  }
  
  TEST(CharTest, IsControl) {
    ASSERT_FALSE(Char::IsControl('a'));
    ASSERT_TRUE(Char::IsControl(0x7F));
    ASSERT_TRUE(Char::IsControl(0x00));
    ASSERT_TRUE(Char::IsControl(0x0F));
    ASSERT_TRUE(Char::IsControl(0x1F));
    ASSERT_FALSE(Char::IsControl(' '));
    ASSERT_FALSE(Char::IsControl(0x7E));
  }
  
  TEST(CharTest, IsLetter) {
    ASSERT_TRUE(Char::IsLetter('a'));
    ASSERT_TRUE(Char::IsLetter('F'));
    ASSERT_TRUE(Char::IsLetter('z'));
    ASSERT_TRUE(Char::IsLetter(106));
    ASSERT_TRUE(Char::IsLetter(391));
    ASSERT_TRUE(Char::IsLetter(644));
    ASSERT_TRUE(Char::IsLetter(2063));
    ASSERT_TRUE(Char::IsLetter(6346));
    ASSERT_TRUE(Char::IsLetter(69804));
    ASSERT_TRUE(Char::IsLetter(194751));
    
    ASSERT_FALSE(Char::IsLetter('0'));
    ASSERT_FALSE(Char::IsLetter('4'));
    ASSERT_FALSE(Char::IsLetter('9'));
    ASSERT_FALSE(Char::IsLetter(48));
    ASSERT_FALSE(Char::IsLetter(1781));
    ASSERT_FALSE(Char::IsLetter(2922));
    ASSERT_FALSE(Char::IsLetter(3437));
    ASSERT_FALSE(Char::IsLetter(3881));
    ASSERT_FALSE(Char::IsLetter(6476));
    ASSERT_FALSE(Char::IsLetter(43271));
  }
  
  TEST(CharTest, IsDigit) {
    ASSERT_FALSE(Char::IsDigit('a'));
    ASSERT_FALSE(Char::IsDigit('F'));
    ASSERT_FALSE(Char::IsDigit('z'));
    ASSERT_FALSE(Char::IsDigit(106));
    ASSERT_FALSE(Char::IsDigit(391));
    ASSERT_FALSE(Char::IsDigit(644));
    ASSERT_FALSE(Char::IsDigit(2063));
    ASSERT_FALSE(Char::IsDigit(6346));
    ASSERT_FALSE(Char::IsDigit(69804));
    ASSERT_FALSE(Char::IsDigit(194751));
    
    ASSERT_TRUE(Char::IsDigit('0'));
    ASSERT_TRUE(Char::IsDigit('4'));
    ASSERT_TRUE(Char::IsDigit('9'));
    ASSERT_TRUE(Char::IsDigit(48));
    ASSERT_TRUE(Char::IsDigit(1781));
    ASSERT_TRUE(Char::IsDigit(2922));
    ASSERT_TRUE(Char::IsDigit(3437));
    ASSERT_TRUE(Char::IsDigit(3881));
    ASSERT_TRUE(Char::IsDigit(6476));
    ASSERT_TRUE(Char::IsDigit(43271));
  }
  
  TEST(CharTest, Parse) {
    ASSERT_EQ('a', Char::Parse("a"));
    ASSERT_EQ('G', Char::Parse("G"));
    ASSERT_EQ('5', Char::Parse("5"));
    ASSERT_THROW(Char::Parse("589"), FormatException);
  }
  
  TEST(CharTest, Equals) {
    ASSERT_FALSE(Char('d').Equals(Char('K')));
    ASSERT_TRUE(Char('d').Equals(Char('d')));
  }
  
  TEST(CharTest, ToString) {
    ASSERT_EQ(string(""), Char().ToString());
    ASSERT_EQ(string("a"), Char('a').ToString());
    ASSERT_EQ(string("G"), Char('G').ToString());
    ASSERT_EQ(string("9"), Char('9').ToString());
  }
  
  TEST(CharTest, CompareTo) {
    EXPECT_GT(Char('a').CompareTo(Char('A')), 0);
    EXPECT_LT(Char('B').CompareTo(Char('z')), 0);
    ASSERT_EQ(Char('8').CompareTo(Char('8')), 0);
    EXPECT_GT(Char('A').CompareTo(Int32(2)), 0);
  }
  
  TEST(CharTest, GetTypeCode) {
    ASSERT_EQ(TypeCode::Char, Char().GetTypeCode());
  }
  
}

TEST(char32, Ctor) {
  char32 a('a');
  ASSERT_EQ('a', a);
}

TEST(char32, CopyCtor) {
  char32 a('a');
  char32 b(a);
  ASSERT_EQ('a', b);
}

TEST(char32, operator_eq) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  ASSERT_TRUE(a == a2);
  ASSERT_TRUE(a2 == a);
  ASSERT_FALSE(a == b);
  ASSERT_FALSE(b == a);
}

TEST(char32, operator_ne) {
  char32 a('a');
  char32 b('b');
  char32 a2('a');
  ASSERT_TRUE(a != b);
  ASSERT_TRUE(b != a);
  ASSERT_FALSE(a != a2);
  ASSERT_FALSE(a2 != a);
}

TEST(char32, operator_lt) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  ASSERT_FALSE(a < a2);
  ASSERT_FALSE(a2 < a);
  ASSERT_TRUE(a < b);
  ASSERT_FALSE(b < a);
}

TEST(char32, operator_gt) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  ASSERT_FALSE(a > a2);
  ASSERT_FALSE(a2 > a);
  ASSERT_FALSE(a > b);
  ASSERT_TRUE(b > a);
}

TEST(char32, operator_le) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  ASSERT_TRUE(a <= a2);
  ASSERT_TRUE(a2 <= a);
  ASSERT_TRUE(a <= b);
  ASSERT_FALSE(b <= a);
}

TEST(char32, operator_ge) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  ASSERT_TRUE(a >= a2);
  ASSERT_TRUE(a2 >= a);
  ASSERT_FALSE(a >= b);
  ASSERT_TRUE(b >= a);
}

TEST(char32, operator_p) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  ASSERT_TRUE((a + a2) == ('a' + 'a'));
  ASSERT_TRUE((a2 + a) == ('a' + 'a'));
  ASSERT_TRUE((a + b) == ('a' + 'b'));
  ASSERT_TRUE((b + a) == ('a' + 'b'));
}

TEST(char32, operator_m) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  ASSERT_TRUE((a - a2) == ('a' - 'a'));
  ASSERT_TRUE((a2 - a) == ('a' - 'a'));
  ASSERT_TRUE((a - b) == unsigned('a' - 'b'));
  ASSERT_TRUE((b - a) == ('b' - 'a'));
}

TEST(char32, operator_eq_int) {
  char32 a('a');
  ASSERT_TRUE(a == 'a');
  ASSERT_TRUE('a' == a);
  ASSERT_FALSE(a == 'b');
  ASSERT_FALSE('b' == a);
}

TEST(char32, operator_ne_int) {
  char32 a('a');
  ASSERT_TRUE(a != 'b');
  ASSERT_TRUE('b' != a);
  ASSERT_FALSE(a != 'a');
  ASSERT_FALSE('a' != a);
}

TEST(char32, operator_lt_int) {
  char32 a('a');
  ASSERT_FALSE(a < 'a');
  ASSERT_FALSE('a' < a);
  ASSERT_TRUE(a < 'b');
  ASSERT_FALSE('b' < a);
}

TEST(char32, operator_gt_int) {
  char32 a('a');
  ASSERT_FALSE(a > 'a');
  ASSERT_FALSE('a' > a);
  ASSERT_FALSE(a > 'b');
  ASSERT_TRUE('b' > a);
}

TEST(char32, operator_le_int) {
  char32 a('a');
  ASSERT_TRUE(a <= 'a');
  ASSERT_TRUE('a' <= a);
  ASSERT_TRUE(a <= 'b');
  ASSERT_FALSE('b' <= a);
  ASSERT_TRUE(char32('F') >= 'A');
}

TEST(char32, operator_ge_int) {
  char32 a('a');
  ASSERT_TRUE(a >= 'a');
  ASSERT_TRUE('a' >= a);
  ASSERT_FALSE(a >= 'b');
  ASSERT_TRUE('b' >= a);
}

TEST(char32, operator_p_int) {
  char32 a('a');
  ASSERT_TRUE((a + 'a') == ('a' + 'a'));
  ASSERT_TRUE(('a' + a) == ('a' + 'a'));
  ASSERT_TRUE((a + 'b') == ('a' + 'b'));
  ASSERT_TRUE(('b' + a) == ('a' + 'b'));
  
  ASSERT_TRUE(char32('0') + 9 == '9');
}

TEST(char32, operator_m_int) {
  char32 a('a');
  ASSERT_TRUE((a - 'a') == ('a' - 'a'));
  ASSERT_TRUE(('a' - a) == ('a' - 'a'));
  ASSERT_TRUE((a - 'b') == unsigned('a' - 'b'));
  ASSERT_TRUE(('b' - a) == ('b' - 'a'));
}
