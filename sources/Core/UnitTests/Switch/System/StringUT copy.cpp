#include <Switch/Switch>

using namespace System;

namespace {

  TEST(String, TrimSart_Multiple) {
    char32 numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    EXPECT_EQ(string("          string To Trim Start").TrimStart(' '),"string To Trim Start");
    EXPECT_EQ(string("          string To Trim Start").TrimStart('d'),"          string To Trim Start");
  
    EXPECT_EQ(string("2468013579abcdef1357924680").TrimStart(Array<char32>(numbers)),"abcdef1357924680");
    EXPECT_EQ(string("").TrimStart(Array<char32>(numbers)),"");
    EXPECT_EQ(string("24680135791357924680").TrimStart(Array<char32>(numbers)),"");
  }

  TEST(String, TrimSart_Multiple_Exceptions) {
    Array<char32>* nullCharArray = null;
    EXPECT_THROW(string("2468013579abcdef1357924680").TrimStart(*nullCharArray),ArgumentNullException);
  }

  TEST(String, TrimEnd) {
    EXPECT_EQ(string("string To Trim").TrimEnd('x'),"string To Trim");
    EXPECT_EQ(string("string To Trimxxx").TrimEnd('x'),"string To Trim");
    EXPECT_EQ(string("string To Trimxx").TrimEnd('x'),"string To Trim");
    EXPECT_EQ(string("string To Trimx").TrimEnd('x'),"string To Trim");
    EXPECT_EQ(string("").TrimEnd('x'),"");
    EXPECT_EQ(string("x").TrimEnd('x'),"");
    EXPECT_EQ(string("xx").TrimEnd('x'),"");
    EXPECT_EQ(string("xxx").TrimEnd('x'),"");
    EXPECT_EQ(string("x xx").TrimEnd('x'),"x ");

    EXPECT_EQ(string("string To Trim End          ").TrimEnd(' '),"string To Trim End");
    EXPECT_EQ(string("string To Trim End          ").TrimEnd('d'),"string To Trim End          ");
  }
  
  TEST(String, TrimEnd_Multiple) {
    char32 numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    EXPECT_EQ(string("2468013579abcdef1357924680").TrimEnd(Array<char32>(numbers, 10)),"2468013579abcdef");
  }

  TEST(String, TrimEnd_Multiple_Exceptions) {
    Array<char32>* nullCharArray = null;
    EXPECT_THROW(string("2468013579abcdef1357924680").TrimEnd(*nullCharArray),ArgumentNullException);
  }

  TEST(String, ConcatConstChar) {
    EXPECT_EQ(string("This is a simple test from const char []."), string("This is a simple") + string(" test from") + string(" const char []."));
    EXPECT_EQ(string("This is a simple test from const char []."), string("This is a simple") + " test from" + " const char [].");
  }

  TEST(String, Byte) {
    byte i = 5;
    EXPECT_EQ(string("i = 5"), string("i = ") + i);
    EXPECT_EQ(string("5"), string() + i);
  }

  TEST(String, Boolean) {
    bool b = false;
    EXPECT_EQ(string("b = 0"), string("b = ") + b);
    EXPECT_EQ(string("0"), string() + b);
    EXPECT_EQ(string("1"), string() + true);
    EXPECT_EQ(string("0"), string() + false);
  }

  TEST(String, Double) {
    double d = 2145;
    EXPECT_EQ(string("d = 2145"), string("d = ") + d);
    EXPECT_EQ(string("2145"), string() + d);
  }

  TEST(String, Int16) {
    int16 i = 12;
    EXPECT_EQ(string("i = 12"), string("i = ") + i);
    EXPECT_EQ(string("12"), string() + i);
  }

  TEST(String, Int32) {
    int32 i = 196;
    EXPECT_EQ(string("i = 196"), string("i = ") + i);
    EXPECT_EQ(string("196"), string() + i);
    EXPECT_EQ(string("54259"), string() + 54259);
  }

  TEST(String, Int64) {
    int64 i = 45898745587LL;
    EXPECT_EQ(string("i = 45898745587"), string("i = ") + i);
    EXPECT_EQ(string("45898745587"), string() + i);
    EXPECT_EQ(string("54898528497"), string() + 54898528497LL);
  }

  TEST(String, SByte) {
    sbyte i = -25;
    EXPECT_EQ(string("i = -25"), string("i = ") + i);
    EXPECT_EQ(string("-25"), string() + i);
  }

  TEST(String, UInt16) {
    uint16 i = 12;
    EXPECT_EQ(string("i = 12"), string("i = ") + i);
    EXPECT_EQ(string("12"), string() + i);
  }

  TEST(String, UInt32) {
    uint32 i = 196;
    EXPECT_EQ(string("i = 196"), string("i = ") + i);
    EXPECT_EQ(string("196"), string() + i);
    EXPECT_EQ(string("54259"), string() + 54259);
  }

  TEST(String, UInt64) {
    uint64 i = 45898745587LL;
    EXPECT_EQ(string("i = 45898745587"), string("i = ") + i);
    EXPECT_EQ(string("45898745587"), string() + i);
    EXPECT_EQ(string("54898528497"), string() + 54898528497LL);
  }

  template<int size> void TestToCCharArray(const String& testString, const char* expected) {
    char buffer[size];
    EXPECT_EQ((int)strlen(expected), testString.ToCCharArray(buffer, size));
    EXPECT_EQ(0, strcmp(buffer, expected));
  }

  TEST(String, ToCCharArray_Empty) {
    string s;
    TestToCCharArray<1>(s, "");
  }

  TEST(String, ToCCharArray_Unicode) {
    string s = string("Testing") + Char(0x1F428);
    TestToCCharArray<5>(s, "Test");
    TestToCCharArray<8>(s, "Testing");
    TestToCCharArray<9>(s, "Testing?");
    TestToCCharArray<10>(s, "Testing?");
    TestToCCharArray<11>(s, "Testing?");
    TestToCCharArray<15>(s, "Testing?");
  }

  TEST(String, ToCCharArray_PureAscii) {
    TestToCCharArray<5>("","");
    TestToCCharArray<5>("Testing!", "Test");
    TestToCCharArray<8>("Testing!", "Testing");
    TestToCCharArray<9>("Testing!", "Testing!");
    TestToCCharArray<10>("Testing!", "Testing!");
    TestToCCharArray<15>("Testing!", "Testing!");
  }

  //___________________________________________________________________________
  //                                                             std :: ustring

  TEST(ustring, Constructor) {
    EXPECT_EQ(std::ustring(),"");
    EXPECT_EQ(std::ustring("Hello World"),"Hello World");
    EXPECT_EQ(std::ustring(std::ustring("Test1")),"Test1");
    EXPECT_EQ(11u,std::ustring("Hello World").length());
    EXPECT_EQ(8u,std::ustring("私の第二の文字列").length());
  }

  TEST(ustring, Constructor_Char_Partial_Ansi_Exceptions) { 
    EXPECT_THROW(std::ustring("UNITest1", -1, 0),ArgumentOutOfRangeException);
    EXPECT_THROW(std::ustring("UNITest1", 10, 2),ArgumentOutOfRangeException);
    EXPECT_THROW(std::ustring("UNITest1", 10, 0),ArgumentOutOfRangeException);
  }

  TEST(ustring, Constructor_Char_Partial_Ansi) { 
    EXPECT_EQ(std::ustring("UNITest1", 0, 0),"");
    EXPECT_EQ(std::ustring("UNITest1", 0, 8),"UNITest1");
    EXPECT_EQ(std::ustring("UNITest1", 3, 4),"Test");
    EXPECT_EQ(std::ustring("UNITest1", 0),"UNITest1");
    EXPECT_EQ(std::ustring("UNITest1", 3),"Test1");
    EXPECT_EQ(std::ustring("UNITest1", 3, 6), "Test1");
    EXPECT_EQ(std::ustring("UNITest1", 3, 60), "Test1");
    EXPECT_EQ(std::ustring("UNITest1", 0, 10),"UNITest1");
  }

  TEST(ustring, Constructor_Char_Partial_UTF8_Exceptions) {
    EXPECT_THROW(std::ustring("私の第二の文字列", -1, 0),ArgumentOutOfRangeException);
    EXPECT_THROW(std::ustring("私の第二の文字列", 10, 2),ArgumentOutOfRangeException);  
    EXPECT_THROW(std::ustring("私の第二の文字列", 10, 0),ArgumentOutOfRangeException);
  }

  TEST(ustring, Constructor_Char_Partial_UTF8) {
    EXPECT_EQ(std::ustring("私の第二の文字列", 0, 0), "");
    EXPECT_EQ(std::ustring("私の第二の文字列", 0, 8), "私の第二の文字列");
    EXPECT_EQ(std::ustring("私の第二の文字列", 3, 4), "二の文字");
    EXPECT_EQ(std::ustring("私の第二の文字列", 0), "私の第二の文字列");
    EXPECT_EQ(std::ustring("私の第二の文字列", 3, 6), "二の文字列");
    EXPECT_EQ(std::ustring("私の第二の文字列", 0, 10), "私の第二の文字列");
  }

  TEST(ustring, operator_assign) {
    std::ustring s("Useless");
    s = "Testing assignement";
    EXPECT_EQ(s, "Testing assignement");
  
    s = "私の第二の文字列";
    EXPECT_EQ(s, "私の第二の文字列");

    s = std::ustring("Testing other assignement");
    EXPECT_EQ(s, "Testing other assignement");
  }

  TEST(ustring, append_char_int) {
    std::ustring s("Hello");
    s.append(" World Company");
    EXPECT_EQ(s, "Hello World Company");
  
    s = "私の第二";
    s.append("の文字列");
    EXPECT_EQ(s,"私の第二の文字列");
  }

  TEST(ustring, operator_plus_eq) {
    std::ustring s("Hello");
    s += " World";
    EXPECT_EQ(s, "Hello World");
  
    s = "私の第二";
    s += "の文字列";
    EXPECT_EQ(s,"私の第二の文字列");

    s = "Hello";
    s += std::ustring(" World");
    EXPECT_EQ(s, "Hello World");
  
    s = "私の第二";
    s += std::ustring(" 私の 第二");
    EXPECT_EQ(s,"私の第二 私の 第二");
  }

  TEST(ustring, iterator_ansi) {
    int reference[11] = { 'H','e','l','l','o',' ','w','o','r','l','d' };
    std::ustring s("Hello world");
    int index = 0;
    int bindex = 0;
    for (std::ustring::iterator it = s.begin(); it != s.end(); it++) {
      EXPECT_EQ(index, it.get_logical_index());
      EXPECT_EQ(bindex, it.get_byte_index());
      EXPECT_EQ(1,it.get_format());
      EXPECT_EQ(reference[it.get_logical_index()],(int)*it);
      index += 1;
      bindex += 1;
    }
    EXPECT_EQ(index, (int)s.length());
    index = 0;
    s = "";
    for (std::ustring::iterator it = s.begin(); it != s.end(); it++)  
      index += 1;
    EXPECT_EQ(0, index);
  }

  TEST(ustring, iterator_utf8) {
    int reference[10] = {31169, 12398, 31532, 32, 20108, 12398, 32, 25991, 23383, 21015 };
    std::ustring s("私の第 二の 文字列");
    int index = 0;
    int bindex = 0;
    for (std::ustring::iterator it = s.begin(); it != s.end(); it++)  {
      EXPECT_EQ(bindex, it.get_byte_index());
      EXPECT_EQ(index, it.get_logical_index());
      if (index == 3 || index == 6) {
        bindex += 1;
        EXPECT_EQ(1,it.get_format());
      } else {
        bindex += 3;
        EXPECT_EQ(3,it.get_format());
      }
      EXPECT_EQ(reference[it.get_logical_index()],(int)*it);
      index += 1;
    }
    EXPECT_EQ(index, (int)s.length());

    index = 0;
    s = "";
    for (std::ustring::iterator it = s.begin(); it != s.end(); it++) 
      index += 1;
    EXPECT_EQ(0, index);
  }

  TEST(ustring, reverse_iterator_ansi) {
    int reference[11] = { 'H','e','l','l','o',' ','w','o','r','l','d' };
    std::ustring s("Hello world");
    int index = 10;
    int bindex = 10;
    for (std::ustring::reverse_iterator it = s.rbegin(); it != s.rend(); it++)  {
      EXPECT_EQ(index, it.get_logical_index());
      EXPECT_EQ(bindex, it.get_byte_index());
      EXPECT_EQ(1,it.get_format());
      EXPECT_EQ(reference[it.get_logical_index()],(int)*it);
      index -= 1;
      bindex -= 1;
    }
    EXPECT_EQ(-1,index);

    index = 0;
    s = "";
    for (std::ustring::reverse_iterator it = s.rbegin(); it != s.rend(); it++) 
      index += 1;
    EXPECT_EQ(0, index);
  }

  TEST(ustring, reverse_iterator_utf8) {
    std::ustring s("私の第 二の 文字列");

                         // |00 01 02|03 04 05|06 07 08|09|10 11 12|13 14 15|16|17 18 19|20 21 22|23 24 25|
                         // |        |        |        |  |        |        |  |        |        |        |
    int formats[10]     = {         3,       3,       3, 1,       3,       3, 1,       3,       3,       3  };
    int byteIndices[10] = {   0      , 3      , 6      , 9,10      ,13      ,16,17      ,20      ,23        };
    int codes[10]       = {     31169,   12398,   31532,32,   20108,   12398,32,   25991,   23383,    21015 };
    int index = 9;
    for (std::ustring::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
      EXPECT_EQ(index, it.get_logical_index());
      EXPECT_EQ(codes[it.get_logical_index()],(int)*it);
      EXPECT_EQ(formats[it.get_logical_index()],it.get_format());
      EXPECT_EQ(byteIndices[it.get_logical_index()], it.get_byte_index());
      index -= 1;
    }
    EXPECT_EQ(-1,index);

    index = 0;
    s = "";
    for (std::ustring::reverse_iterator it = s.rbegin(); it != s.rend(); it++) 
      index += 1;
    EXPECT_EQ(0, index);
  }

  TEST(ustring, rfind_ansi) {
    std::ustring s("Hello world, in a world full of nothing");
    EXPECT_EQ(std::ustring::npos, s.rfind("world",5));
    EXPECT_EQ(6u, s.rfind("world", 6));
    EXPECT_EQ(6u, s.rfind(std::ustring("world"), 7));
    EXPECT_EQ(6u, s.rfind("world", 8));
    EXPECT_EQ(6u, s.rfind("world", 9));
    EXPECT_EQ(6u, s.rfind("world", 17));
    EXPECT_EQ(18u, s.rfind(std::ustring("world"), 18));
    EXPECT_EQ(18u, s.rfind("world", 19));
    EXPECT_EQ(18u, s.rfind("world"));
    EXPECT_EQ(0u, s.rfind("Hell"));
    EXPECT_EQ(0u, s.rfind("Hell", 0));
    EXPECT_EQ(0u, s.rfind("Hell", 1));

    EXPECT_EQ(std::ustring::npos, s.rfind("ok"));
    EXPECT_EQ(std::ustring::npos, s.rfind("ok",100));
  }

  TEST(ustring, rfind_utf8) {
    std::ustring s("私の第 二の文字列 私の第二の文字列");
    EXPECT_EQ(std::ustring::npos, s.rfind("文字列",5));
    EXPECT_EQ(6u, s.rfind(std::ustring("文字列"), 6));
    EXPECT_EQ(6u, s.rfind("文字列", 7));
    EXPECT_EQ(6u, s.rfind("文字列", 8));
    EXPECT_EQ(6u, s.rfind(std::ustring("文字列"), 9));
    EXPECT_EQ(6u, s.rfind("文字列", 14));
    EXPECT_EQ(15u, s.rfind("文字列", 15));
    EXPECT_EQ(15u, s.rfind("文字列", 16));
    EXPECT_EQ(15u, s.rfind("文字列"));
    EXPECT_EQ(0u, s.rfind("私の第 "));
    EXPECT_EQ(0u, s.rfind("私の第 ", 0));
    EXPECT_EQ(0u, s.rfind("私の第 ", 1));

    EXPECT_EQ(std::ustring::npos, s.rfind("文文 "));
    EXPECT_EQ(std::ustring::npos, s.rfind("文文 ",100));
  }

  TEST(ustring, find_ansi) {
    std::ustring s("Hello world, in a world full of nothing");
    EXPECT_EQ(6u, s.find("world", 5));
    EXPECT_EQ(6u, s.find("world", 6));
    EXPECT_EQ(18u, s.find(std::ustring("world"), 7));
    EXPECT_EQ(18u, s.find("world", 8));
    EXPECT_EQ(18u, s.find("world", 9));
    EXPECT_EQ(18u, s.find("world", 17));
    EXPECT_EQ(18u, s.find(std::ustring("world"), 18));
    EXPECT_EQ(std::ustring::npos, s.find("world", 19));
    EXPECT_EQ(6u, s.find("world"));

    EXPECT_EQ(std::ustring::npos, s.find("ok"));
    EXPECT_THROW(s.find("ok",100),ArgumentOutOfRangeException);
  }

  TEST(ustring, find_utf8) {
    std::ustring s("私の第 二の文字列 私の第二の文字列");
    EXPECT_EQ(6u, s.find("文字列",5));
    EXPECT_EQ(6u, s.find(std::ustring("文字列"), 6));
    EXPECT_EQ(15u, s.find("文字列", 7));
    EXPECT_EQ(15u, s.find("文字列", 8));
    EXPECT_EQ(15u, s.find(std::ustring("文字列"), 9));
    EXPECT_EQ(15u, s.find("文字列", 14));
    EXPECT_EQ(15u, s.find("文字列", 15));
    EXPECT_EQ(std::ustring::npos, s.find("文字列", 16));
    EXPECT_EQ(6u, s.find("文字列"));
    EXPECT_EQ(0u, s.find("私の第 "));
    EXPECT_EQ(0u, s.find("私の第 ", 0));
    EXPECT_EQ(std::ustring::npos, s.find("私の第 ", 1));

    EXPECT_EQ(std::ustring::npos, s.find("文文 "));
    EXPECT_THROW(s.find("文文 ",100),ArgumentOutOfRangeException);
  }

  TEST(ustring, substr_ansi) {
    std::ustring s1("Hello");
    std::string  s2("Hello");
    EXPECT_EQ(s1.substr(), s2.substr().c_str());
    EXPECT_EQ(s1.substr(0),s2.substr(0).c_str());
    EXPECT_EQ(s1.substr(1),s2.substr(1).c_str());
    EXPECT_EQ(s1.substr(2),s2.substr(2).c_str());
    EXPECT_EQ(s1.substr(3),s2.substr(3).c_str());
    EXPECT_EQ(s1.substr(4),s2.substr(4).c_str());
    EXPECT_EQ(s1.substr(5),s2.substr(5).c_str());

    EXPECT_EQ(s1.substr(0,0),s2.substr(0,0).c_str());
    EXPECT_EQ(s1.substr(0,1),s2.substr(0,1).c_str());
    EXPECT_EQ(s1.substr(0,5),s2.substr(0,5).c_str());
    EXPECT_EQ(s1.substr(0,6),s2.substr(0,6).c_str());
    EXPECT_EQ(s1.substr(0,10),s2.substr(0,10).c_str());
    EXPECT_EQ(s1.substr(4,0),s2.substr(4,0).c_str());
    EXPECT_EQ(s1.substr(4,1),s2.substr(4,1).c_str());
    EXPECT_EQ(s1.substr(4,5),s2.substr(4,5).c_str());
    EXPECT_EQ(s1.substr(4,6),s2.substr(4,6).c_str());
    EXPECT_EQ(s1.substr(4,10),s2.substr(4,10).c_str());
  
    EXPECT_EQ(s1.substr(5,0),s2.substr(5,0).c_str());
    EXPECT_EQ(s1.substr(5,1),s2.substr(5,1).c_str());
    EXPECT_EQ(s1.substr(5,5),s2.substr(5,5).c_str());
    EXPECT_EQ(s1.substr(5,6),s2.substr(5,6).c_str());
    EXPECT_EQ(s1.substr(5,10),s2.substr(5,10).c_str());
  }

  TEST(ustring, substr_utf8) {
    std::ustring s1("私の第 二の文");
    EXPECT_EQ(s1.substr(),  "私の第 二の文");
    EXPECT_EQ(s1.substr(0),  "私の第 二の文");
    EXPECT_EQ(s1.substr(1), "の第 二の文");
    EXPECT_EQ(s1.substr(2), "第 二の文");
    EXPECT_EQ(s1.substr(3), " 二の文");
    EXPECT_EQ(s1.substr(4), "二の文");
    EXPECT_EQ(s1.substr(5), "の文");
    EXPECT_EQ(s1.substr(6), "文");
    EXPECT_EQ(s1.substr(7), "");

    EXPECT_EQ(s1.substr(4,0),  "");
    EXPECT_EQ(s1.substr(4,1),  "二");
    EXPECT_EQ(s1.substr(4,2),  "二の");
    EXPECT_EQ(s1.substr(4,3),  "二の文");
    EXPECT_EQ(s1.substr(4,4),  "二の文");
    EXPECT_EQ(s1.substr(4,10),  "二の文");

    EXPECT_EQ(s1.substr(7,0),  "");
    EXPECT_EQ(s1.substr(7,1),  "");
    EXPECT_EQ(s1.substr(7,2),  "");
    EXPECT_EQ(s1.substr(7,3),  "");
    EXPECT_EQ(s1.substr(7,4),  "");
    EXPECT_EQ(s1.substr(7,10),  "");
  }

  TEST(ustring, insert) {
    std::ustring s("HelloCompany");
    s.insert(5," world ");
    EXPECT_EQ(s,"Hello world Company");

    s = "私 の第二の私の第文";
    s.insert(5," coucou ");
    EXPECT_EQ(s,"私 の第二 coucou の私の第文");
  }

  TEST(ustring, compare) {
    std::ustring s1("Hello world");
    std::ustring s2("Hello");
    std::ustring s3;
    std::ustring s4("A");

    EXPECT_TRUE( s1.compare(s1) == 0 );
    EXPECT_TRUE( s1.compare(s2) >  0 );
    EXPECT_TRUE( s1.compare(s3) >  0 );
    EXPECT_TRUE( s1.compare(s4) >  0 );

    EXPECT_TRUE( s2.compare(s1) <  0 );
    EXPECT_TRUE( s2.compare(s2) == 0 );
    EXPECT_TRUE( s2.compare(s3) >  0 );
    EXPECT_TRUE( s2.compare(s4) >  0 );

    EXPECT_TRUE( s3.compare(s1) <  0 );
    EXPECT_TRUE( s3.compare(s2) <  0 );
    EXPECT_TRUE( s3.compare(s3) ==  0);
    EXPECT_TRUE( s3.compare(s4) <  0 );

    EXPECT_TRUE( s4.compare(s1) <  0 );
    EXPECT_TRUE( s4.compare(s2) <  0 );
    EXPECT_TRUE( s4.compare(s3) >  0 );
    EXPECT_TRUE( s4.compare(s4) == 0 );
  }

  TEST(ustring, random_access) {
    std::ustring s("Hello !");

    EXPECT_THROW(s[-1], ArgumentOutOfRangeException);
    EXPECT_EQ('H', (signed)s[0]);
    EXPECT_EQ('e', (signed)s[1]);
    EXPECT_EQ('l', (signed)s[2]);
    EXPECT_EQ('l', (signed)s[3]);
    EXPECT_EQ('o', (signed)s[4]);
    EXPECT_EQ(' ', (signed)s[5]);
    EXPECT_EQ('!', (signed)s[6]);
    EXPECT_THROW(s[7], ArgumentOutOfRangeException);

    s = "私 の第二 私";
    EXPECT_THROW(s[-1], ArgumentOutOfRangeException);
    EXPECT_EQ(0x79C1, (signed)s[0]);
    EXPECT_EQ(' ', (signed)s[1]);
    EXPECT_EQ(0x306E, (signed)s[2]);
    EXPECT_EQ(0x7B2C, (signed)s[3]);
    EXPECT_EQ(0x4E8C, (signed)s[4]);
    EXPECT_EQ(' ', (signed)s[5]);
    EXPECT_EQ(0x79C1, (signed)s[6]);
    EXPECT_THROW(s[7], ArgumentOutOfRangeException);

    // http://www.ltg.ed.ac.uk/~richard/utf-8.cgi?input=&mode=bytes
    // E0 A4 95 . E0 A4 BE . E0 A4 81 . E0 A4 9A . 20 . E0 A4 96 . E0 A4 BE . 20 . E0 A4 B8 . E0 A4 95 . E0 A4 A4
    s = "काँच खा सकत";
    EXPECT_EQ(2325, (signed)s[0]);
    EXPECT_EQ(2366, (signed)s[1]);
    EXPECT_EQ(2305, (signed)s[2]);
    EXPECT_EQ(2330, (signed)s[3]);
    EXPECT_EQ(  32, (signed)s[4]);
    EXPECT_EQ(2326, (signed)s[5]);
    EXPECT_EQ(2366, (signed)s[6]);
    EXPECT_EQ(  32, (signed)s[7]);
    EXPECT_EQ(2360, (signed)s[8]);
    EXPECT_EQ(2325, (signed)s[9]);
    EXPECT_EQ(2340, (signed)s[10]);
  }

  TEST(ustring, erase_ansi) {
    std::ustring s("Hello there !");
    EXPECT_EQ(s.erase(),"");

    s = "Hello there !";
    EXPECT_THROW(s.erase(13,1), ArgumentOutOfRangeException);

    s = "Hello there !";
    EXPECT_EQ(s.erase(12,0),"Hello there !");

    s = "Hello there !";
    EXPECT_EQ(s.erase(0,0),"Hello there !");

    s = "Hello there !";
    EXPECT_EQ(s.erase(0),"");

    s = "Hello there !";
    EXPECT_EQ(s.erase(0,13),"");

    s = "Hello there !";
    EXPECT_EQ(s.erase(0,12),"!");

    s = "Hello there !";
    s.erase(4,1);
    s.erase(5,1);
    s.erase(9,2);
    s.insert(9,".");
    EXPECT_EQ(s,"Hell here.");
  }

  TEST(ustring, erase_utf8) {
    std::ustring s("私 の第二の私の第文!");
    EXPECT_EQ(s.erase(),"");

    s = "私 の第二の私の第文!";
    EXPECT_THROW(s.erase(13,1), ArgumentOutOfRangeException);

    s = "私 の第二の私の第文!";
    EXPECT_EQ(s.erase(0),"");

    s = "私 の第二の私の第文!";
    EXPECT_EQ(s.erase(0,0),"私 の第二の私の第文!");

    s = "私 の第二の私の第文!";
    EXPECT_EQ(s.erase(10,0),"私 の第二の私の第文!");

    s = "私 の第二の私の第文!";
    EXPECT_EQ(s.erase(0,11),"");

    s = "私 の第二の私の第文!";
    EXPECT_EQ(s.erase(0,10),"!");

    s = "私 の第二の私の第文";
    s.erase(4,1);
    s.erase(5,1);
    s.erase(7,10);
    s.insert(7,".");
    EXPECT_EQ(s,"私 の第のの第.");
  }

  TEST(ustring, replace_ansi) {
    std::ustring s("Hotel california");
    s.replace(2,2,2,'l');
    EXPECT_EQ(s, "Holll california");
    EXPECT_EQ(s.replace(1,1,1,'e'), "Helll california");
    EXPECT_EQ(s.replace(4,1,1,'o'), "Hello california");
    EXPECT_EQ(s.replace(6,10,"there !"), "Hello there !");

    s = "Hotel";
    EXPECT_EQ(s.replace(2,40,1,'l'),"Hol");

    s = "Hotel";
    EXPECT_THROW(s.replace(5,2,2,'l'),ArgumentOutOfRangeException);
  }

  TEST(ustring, replace_utf8) {
    std::ustring s("私 の第二の私の第文!");
    s.replace(2,2,2,'l');
    EXPECT_EQ(s, "私 ll二の私の第文!");
    EXPECT_EQ(s.replace(1,1,1,'e'), "私ell二の私の第文!");
    EXPECT_EQ(s.replace(4,1,1,'o'), "私elloの私の第文!");
    EXPECT_EQ(s.replace(5,10," there !"), "私ello there !");

    s = "の私の第文";
    EXPECT_EQ(s.replace(2,40,1,'l'),"の私l");
  }

  TEST(ustring, trim_end_utf8) {
    std::vector<uint32_t> match;
    match.push_back('!');
    match.push_back('?');
    match.push_back('.');
    match.push_back(' ');

    std::ustring s("Hyper enthousiast !?.?!!");
    s.trim_end(match);
    EXPECT_EQ(s,"Hyper enthousiast");

    s = "Hyper enthousiast !?.?!!&";
    s.trim_end(match);
    EXPECT_EQ(s,"Hyper enthousiast !?.?!!&");

    s = "";
    s.trim_end(match);
    EXPECT_EQ(s,"");

    s = "?";
    s.trim_end(match);
    EXPECT_EQ(s,"");

    s = "?!";
    s.trim_end(match);
    EXPECT_EQ(s,"");

    s = "!? !";
    s.trim_end(match);
    EXPECT_EQ(s,"");

    s = "Hyper enthousiast !?.?!&!";
    s.trim_end(match);
    EXPECT_EQ(s,"Hyper enthousiast !?.?!&");

    match.clear();
    s = "Hyper enthousiast !";
    s.trim_end(match);
    EXPECT_EQ(s,"Hyper enthousiast !");

    match.clear();
    s = "";
    s.trim_end(match);
    EXPECT_EQ(s,"");
  }

  TEST(ustring, compare_utf8) {
    std::ustring s1("私 の第二の私の第文1");
    std::ustring s2("私 の第二の私の第文2");
    EXPECT_GT(s2.compare(s1),0);
  }

  TEST(ustring, encode) {
    std::ustring s("私 の第二の私の第文1");
    std::ustring out;

    for (std::ustring::iterator it = s.begin(); it != s.end(); it++) {
      uint32_t codePoint = *it;
      out.append(codePoint);
    }
  
    EXPECT_EQ(0,s.compare(out));
  }
}


