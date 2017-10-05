#include <Switch/System/Char.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  
  TEST(Char, Constructor) {
    EXPECT_EQ(Char(), Char('\0'));
    EXPECT_EQ(Char('r'), Char('r'));
    EXPECT_EQ(Char('F'), Char('F'));
    EXPECT_EQ(Char(Char('T')), Char('T'));
  }
  
  TEST(Char, IsControl) {
    EXPECT_FALSE(Char::IsControl('a'));
    EXPECT_TRUE(Char::IsControl(0x7F));
    EXPECT_TRUE(Char::IsControl(0x00));
    EXPECT_TRUE(Char::IsControl(0x0F));
    EXPECT_TRUE(Char::IsControl(0x1F));
    EXPECT_FALSE(Char::IsControl(' '));
    EXPECT_FALSE(Char::IsControl(0x7E));
  }
  
  TEST(Char, IsLetter) {
    EXPECT_TRUE(Char::IsLetter('a'));
    EXPECT_TRUE(Char::IsLetter('F'));
    EXPECT_TRUE(Char::IsLetter('z'));
    EXPECT_TRUE(Char::IsLetter(106));
    EXPECT_TRUE(Char::IsLetter(391));
    EXPECT_TRUE(Char::IsLetter(644));
    EXPECT_TRUE(Char::IsLetter(2063));
    EXPECT_TRUE(Char::IsLetter(6346));
    EXPECT_TRUE(Char::IsLetter(69804));
    EXPECT_TRUE(Char::IsLetter(194751));

    EXPECT_FALSE(Char::IsLetter('0'));
    EXPECT_FALSE(Char::IsLetter('4'));
    EXPECT_FALSE(Char::IsLetter('9'));
    EXPECT_FALSE(Char::IsLetter(48));
    EXPECT_FALSE(Char::IsLetter(1781));
    EXPECT_FALSE(Char::IsLetter(2922));
    EXPECT_FALSE(Char::IsLetter(3437));
    EXPECT_FALSE(Char::IsLetter(3881));
    EXPECT_FALSE(Char::IsLetter(6476));
    EXPECT_FALSE(Char::IsLetter(43271));
  }
  
  TEST(Char, IsDigit) {
    EXPECT_FALSE(Char::IsDigit('a'));
    EXPECT_FALSE(Char::IsDigit('F'));
    EXPECT_FALSE(Char::IsDigit('z'));
    EXPECT_FALSE(Char::IsDigit(106));
    EXPECT_FALSE(Char::IsDigit(391));
    EXPECT_FALSE(Char::IsDigit(644));
    EXPECT_FALSE(Char::IsDigit(2063));
    EXPECT_FALSE(Char::IsDigit(6346));
    EXPECT_FALSE(Char::IsDigit(69804));
    EXPECT_FALSE(Char::IsDigit(194751));
    
    EXPECT_TRUE(Char::IsDigit('0'));
    EXPECT_TRUE(Char::IsDigit('4'));
    EXPECT_TRUE(Char::IsDigit('9'));
    EXPECT_TRUE(Char::IsDigit(48));
    EXPECT_TRUE(Char::IsDigit(1781));
    EXPECT_TRUE(Char::IsDigit(2922));
    EXPECT_TRUE(Char::IsDigit(3437));
    EXPECT_TRUE(Char::IsDigit(3881));
    EXPECT_TRUE(Char::IsDigit(6476));
    EXPECT_TRUE(Char::IsDigit(43271));
  }
  
  TEST(Char, Parse) {
    EXPECT_EQ('a', Char::Parse("a"));
    EXPECT_EQ('G', Char::Parse("G"));
    EXPECT_EQ('5', Char::Parse("5"));
    EXPECT_THROW(Char::Parse("589"), FormatException);
  }
  
  TEST(Char, Equals) {
    EXPECT_FALSE(Char('d').Equals(Char('K')));
    EXPECT_TRUE(Char('d').Equals(Char('d')));
  }
  
  TEST(Char, ToString) {
    EXPECT_EQ(string(""), Char().ToString());
    EXPECT_EQ(string("a"), Char('a').ToString());
    EXPECT_EQ(string("G"), Char('G').ToString());
    EXPECT_EQ(string("9"), Char('9').ToString());
  }
  
  TEST(Char, CompareTo) {
    EXPECT_GT(Char('a').CompareTo(Char('A')),0);
    EXPECT_LT(Char('B').CompareTo(Char('z')),0);
    EXPECT_EQ(Char('8').CompareTo(Char('8')),0);
    EXPECT_GT(Char('A').CompareTo(Int32(2)),0);
  }
  
  TEST(Char, GetTypeCode) {
    EXPECT_EQ(TypeCode::Char, Char().GetTypeCode());
  }
  
}

TEST(char32, Ctor) {
  char32 a('a');
  EXPECT_EQ('a', a);
}

TEST(char32, CopyCtor) {
  char32 a('a');
  char32 b(a);
  EXPECT_EQ('a', b);
}

TEST(char32, operator_eq) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  EXPECT_TRUE(a == a2);
  EXPECT_TRUE(a2 == a);
  EXPECT_FALSE(a == b);
  EXPECT_FALSE(b == a);
}

TEST(char32, operator_ne) {
  char32 a('a');
  char32 b('b');
  char32 a2('a');
  EXPECT_TRUE(a != b);
  EXPECT_TRUE(b != a);
  EXPECT_FALSE(a != a2);
  EXPECT_FALSE(a2 != a);
}

TEST(char32, operator_lt) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  EXPECT_FALSE(a < a2);
  EXPECT_FALSE(a2 < a);
  EXPECT_TRUE(a < b);
  EXPECT_FALSE(b < a);
}

TEST(char32, operator_gt) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  EXPECT_FALSE(a > a2);
  EXPECT_FALSE(a2 > a);
  EXPECT_FALSE(a > b);
  EXPECT_TRUE(b > a);
}

TEST(char32, operator_le) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  EXPECT_TRUE(a <= a2);
  EXPECT_TRUE(a2 <= a);
  EXPECT_TRUE(a <= b);
  EXPECT_FALSE(b <= a);
}

TEST(char32, operator_ge) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  EXPECT_TRUE(a >= a2);
  EXPECT_TRUE(a2 >= a);
  EXPECT_FALSE(a >= b);
  EXPECT_TRUE(b >= a);
}

TEST(char32, operator_p) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  EXPECT_TRUE((a + a2) == ('a'+'a'));
  EXPECT_TRUE((a2 + a) == ('a'+'a'));
  EXPECT_TRUE((a + b) == ('a'+'b'));
  EXPECT_TRUE((b + a) == ('a'+'b'));
}

TEST(char32, operator_m) {
  char32 a('a');
  char32 a2('a');
  char32 b('b');
  EXPECT_TRUE((a - a2) == ('a'-'a'));
  EXPECT_TRUE((a2 - a) == ('a'-'a'));
  EXPECT_TRUE((a - b) == unsigned('a'-'b'));
  EXPECT_TRUE((b - a) == ('b' - 'a'));
}

TEST(char32, operator_eq_int) {
  char32 a('a');
  EXPECT_TRUE(a == 'a');
  EXPECT_TRUE('a' == a);
  EXPECT_FALSE(a == 'b');
  EXPECT_FALSE('b' == a);
}

TEST(char32, operator_ne_int) {
  char32 a('a');
  EXPECT_TRUE(a != 'b');
  EXPECT_TRUE('b' != a);
  EXPECT_FALSE(a != 'a');
  EXPECT_FALSE('a' != a);
}

TEST(char32, operator_lt_int) {
  char32 a('a');
  EXPECT_FALSE(a < 'a');
  EXPECT_FALSE('a' < a);
  EXPECT_TRUE(a < 'b');
  EXPECT_FALSE('b' < a);
}

TEST(char32, operator_gt_int) {
  char32 a('a');
  EXPECT_FALSE(a > 'a');
  EXPECT_FALSE('a' > a);
  EXPECT_FALSE(a > 'b');
  EXPECT_TRUE('b' > a);
}

TEST(char32, operator_le_int) {
  char32 a('a');
  EXPECT_TRUE(a <= 'a');
  EXPECT_TRUE('a' <= a);
  EXPECT_TRUE(a <= 'b');
  EXPECT_FALSE('b' <= a);
  EXPECT_TRUE(char32('F') >= 'A');
}

TEST(char32, operator_ge_int) {
  char32 a('a');
  EXPECT_TRUE(a >= 'a');
  EXPECT_TRUE('a' >= a);
  EXPECT_FALSE(a >= 'b');
  EXPECT_TRUE('b' >= a);
}

TEST(char32, operator_p_int) {
  char32 a('a');
  EXPECT_TRUE((a + 'a') == ('a'+'a'));
  EXPECT_TRUE(('a' + a) == ('a'+'a'));
  EXPECT_TRUE((a + 'b') == ('a'+'b'));
  EXPECT_TRUE(('b' + a) == ('a'+'b'));
  
  EXPECT_TRUE(char32('0') + 9 == '9');
}

TEST(char32, operator_m_int) {
  char32 a('a');
  EXPECT_TRUE((a - 'a') == ('a'-'a'));
  EXPECT_TRUE(('a' - a) == ('a'-'a'));
  EXPECT_TRUE((a - 'b') == unsigned('a'-'b'));
  EXPECT_TRUE(('b' - a) == ('b' - 'a'));
}
