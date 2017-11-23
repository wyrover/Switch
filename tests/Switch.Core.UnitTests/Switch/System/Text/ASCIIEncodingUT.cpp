#include "EncodingUT.hpp"
#include <Switch/System/Text/ASCIIEncoding.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  // Name             Unicode() ascii  437   ISO-L1  ISO-L2  UTF8                  UTF16           UTF32
  //
  // charA            0x61     0x61   0x61  0x61    0x61    0x61                  0x61            0x61
  // charAE           0xE6     ?      0x91  0xE6    ?       0xC3 0xA6             0xE6            0xE6
  // charSpecialT     0x163    ?      ?     ?       0xFE    0xC5 0xA3             0x163           0x163
  // sigma            0x3A3    ?      0xE4  ?       ?       0xCE 0xA3             0x3A3           0x3A3
  // syriacSemkath    0x723    ?      ?     ?       ?       0xDC 0xA3             0x723           0x723
  // fullBlock        0x2588   ?      0xDB  ?       ?       0xE2 0x96 0x88        0x2588          0x2588
  // cjk              0x597B   ?      ?     ?       ?       0xE5 0xA5 0xBB        0x597B          0x597B
  // koala            0x1F428  ?      ?     ?       ?       0xF0 0x9F 0x90 0xA8   0xD83D 0xDC28   0x1F428
  
  static char32 charA = 0x61;
  static char32 charAE = 0xE6;
  static char32 charSpecialT = 0x163;
  static char32 sigma = 0x3A3;
  static char32 syriacSemkath = 0x723;
  static char32 fullBlock = 0x2588;
  static char32 cjk = 0x597B;
  static char32 koala = 0x1F428;
  
  using Bytes = Array<byte>;
  using Chars = Array<char32>;
  
  TEST(ASCII_EncodingTest, IsSingleByte) {
    Text::ASCIIEncoding encoding;
    ASSERT_TRUE(encoding.IsSingleByte());
  }
  
  TEST(ASCII_EncodingTest, IsReadOnly) {
    Text::ASCIIEncoding encoding;
    ASSERT_TRUE(encoding.IsReadOnly());
  }
  
  TEST(ASCII_EncodingTest, IsAlwaysNormalized) {
    Text::ASCIIEncoding encoding;
    ASSERT_FALSE(encoding.IsAlwaysNormalized());
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_charA) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(1, e.GetByteCount(charA));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_charAE) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(1, e.GetByteCount(charAE));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_charSpecialT) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(1, e.GetByteCount(charSpecialT));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_sigma) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(1, e.GetByteCount(sigma));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_syriacSemkath) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(1, e.GetByteCount(syriacSemkath));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_fullBlock) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(1, e.GetByteCount(fullBlock));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_cjk) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(1, e.GetByteCount(cjk));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_koala) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(1, e.GetByteCount(koala));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_chars) {
    Text::ASCIIEncoding e;
    char32 chars[] = { charA, charAE, charSpecialT, sigma, syriacSemkath, fullBlock, cjk, koala};
    ASSERT_EQ(8, e.GetByteCount(chars, 8));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_chars_index_count) {
    Text::ASCIIEncoding e;
    char32 chars[3] = { charA, cjk, koala };
    ASSERT_EQ(1, e.GetByteCount(chars, 3, 0, 1));
    ASSERT_EQ(2, e.GetByteCount(chars, 3, 0, 2));
    ASSERT_EQ(3, e.GetByteCount(chars, 3, 0, 3));
    ASSERT_EQ(1, e.GetByteCount(chars, 3, 1, 1));
    ASSERT_EQ(2, e.GetByteCount(chars, 3, 1, 2));
    ASSERT_EQ(1, e.GetByteCount(chars, 3, 2, 1));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_chars_index_count_Exceptions) {
    Text::ASCIIEncoding e;
    char32 chars[3] = { charA, cjk, koala };
    ASSERT_THROW(e.GetByteCount(chars, 3, -1, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetByteCount(chars, 3, 0, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetByteCount(chars, 3, 0, 4), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetByteCount(chars, 3, 1, 3), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetByteCount(chars, 3, 2, 2), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetByteCount(chars, 3, 3, 1), ArgumentOutOfRangeException);
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_String) {
    Text::ASCIIEncoding e;
    String s1 = string() + Char(charA);
    String s2 = string() + Char(koala);
    String s3 = String::Concat(Char(charA), Char(cjk), Char(koala));
    ASSERT_EQ(1, e.GetByteCount(s1));
    ASSERT_EQ(1, e.GetByteCount(s2));
    ASSERT_EQ(3, e.GetByteCount(s3));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_String_Empty) {
    Text::ASCIIEncoding e;
    String empty;
    ASSERT_EQ(0, e.GetByteCount(empty));
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array) {
    Text::ASCIIEncoding e;
    char32 chars[3] = { charA, cjk, koala };
    Array<byte> bytes = e.GetBytes(chars, 3);
    ASSERT_EQ(3, bytes.Length);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[1]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[2]);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Empty) {
    Text::ASCIIEncoding e;
    Array<byte> bytes = e.GetBytes(null, 0);
    ASSERT_EQ(0, bytes.Length);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Null) {
    Text::ASCIIEncoding e;
    ASSERT_THROW(e.GetBytes(null, 2), ArgumentNullException);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_String) {
    Text::ASCIIEncoding e;
    String s1 = string() + Char(charA);
    String s2 = string() + Char(koala);
    String s3 = String::Concat(Char(charA), Char(cjk), Char(koala));
    Array<byte> bytes;
    bytes = e.GetBytes(s1);
    ASSERT_EQ(1, bytes.Length);
    ASSERT_EQ(0x61, bytes[0]);
    bytes = e.GetBytes(s2);
    ASSERT_EQ(1, bytes.Length);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    bytes = e.GetBytes(s3);
    ASSERT_EQ(3, bytes.Length);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[1]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[2]);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_String_Empty) {
    Text::ASCIIEncoding e;
    String s1;
    Array<byte> bytes = e.GetBytes(s1);
    ASSERT_EQ(0, bytes.Length);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_1char32) {
    Text::ASCIIEncoding e;
    char32 chars[1] = { cjk };
    Array<byte> bytes;
    bytes = e.GetBytes(chars, 1, 0, 1);
    ASSERT_EQ(1, bytes.Length);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    
    bytes = e.GetBytes(chars, 1, 0, 0);
    ASSERT_EQ(0, bytes.Length);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_1char32_Exceptions) {
    Text::ASCIIEncoding e;
    char32 chars[1] = { cjk };
    
    ASSERT_THROW(e.GetBytes(chars, 1, -1, 0), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 1, 0, -1), ArgumentOutOfRangeException);
  }
  
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_Empty) {
    Text::ASCIIEncoding e;
    Array<byte> bytes = e.GetBytes(null, 0, 0, 0);
    ASSERT_EQ(0, bytes.Length);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_Empty_Exceptions) {
    Text::ASCIIEncoding e;
    ASSERT_THROW(e.GetBytes(null, 0, 0, 1), ArgumentOutOfRangeException);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_index_count_3char32) {
    Text::ASCIIEncoding e;
    char32 chars[3] = { charA, cjk, koala };
    Array<byte> bytes;
    bytes = e.GetBytes(chars, 3, 0, 0);
    ASSERT_EQ(0, bytes.Length);
    bytes = e.GetBytes(chars, 3, 3, 0);
    ASSERT_EQ(0, bytes.Length);
    bytes = e.GetBytes(chars, 3, 0, 1);
    ASSERT_EQ(1, bytes.Length);
    ASSERT_EQ(0x61, bytes[0]);
    bytes = e.GetBytes(chars, 3, 0, 2);
    ASSERT_EQ(2, bytes.Length);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[1]);
    bytes = e.GetBytes(chars, 3, 0, 3);
    ASSERT_EQ(3, bytes.Length);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[1]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[2]);
    bytes = e.GetBytes(chars, 3, 1, 1);
    ASSERT_EQ(1, bytes.Length);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    bytes = e.GetBytes(chars, 3, 1, 2);
    ASSERT_EQ(2, bytes.Length);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[1]);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_index_count_3char32_Exceptions) {
    Text::ASCIIEncoding e;
    char32 chars[3] = { charA, cjk, koala};
    ASSERT_THROW(e.GetBytes(chars, 3, -1, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 0, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 0, 4), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 1, 3), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 2, 2), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 3, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 4, 0), ArgumentOutOfRangeException);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_Array_Index_Empty) {
    Text::ASCIIEncoding e;
    ASSERT_EQ(0, e.GetBytes(null, 0, 0, 0, null, 0));
    ASSERT_THROW(e.GetBytes(null, 0, 0, 1, null, 0), ArgumentOutOfRangeException);
    ASSERT_EQ(0, e.GetBytes(null, 0, 1, 0, null, 0));
    ASSERT_THROW(e.GetBytes(null, 0, 1, 1, null, 0), ArgumentOutOfRangeException);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_Array_Index_1char) {
    Text::ASCIIEncoding e;
    char32 chars[1] = { koala };
    byte bytes[1] = { 1 };
    ASSERT_EQ(0, e.GetBytes(chars, 1, 0, 0, bytes, 1, 0));
    ASSERT_EQ(1, e.GetBytes(chars, 1, 0, 1, bytes, 1, 0));
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, e.GetBytes(chars, 1, 1, 0, bytes, 1, 0));
    ASSERT_THROW(e.GetBytes(chars, 1, 1, 1, bytes, 1, 0), ArgumentOutOfRangeException);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_Array_Index_Null) {
    Text::ASCIIEncoding e;
    ASSERT_THROW(e.GetBytes(null, 0, 0, 1, null, 0, 0), ArgumentOutOfRangeException);
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_Array_Index_3char) {
    Text::ASCIIEncoding e;
    char32 chars[3] = { charA, cjk, koala };
    byte bytes[3];
    ASSERT_EQ(0, e.GetBytes(chars, 3, 0, 0, bytes, 3, 0));
    ASSERT_EQ(1, e.GetBytes(chars, 3, 0, 1, bytes, 3, 0));
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(0, e.GetBytes(chars, 3, 3, 0, bytes, 3, 0));
    ASSERT_EQ(2, e.GetBytes(chars, 3, 1, 2, bytes, 3, 0));
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[1]);
    ASSERT_EQ(3, e.GetBytes(chars, 3, 0, 3, bytes, 3, 0));
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[1]);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[2]);
    ASSERT_EQ(0, e.GetBytes(chars, 3, 0, 0, bytes, 3, 3));
  }
  
  TEST(ASCII_EncodingTest, GetBytes_Array_Index_Count_Array_Index_3char_Exceptions) {
    Text::ASCIIEncoding e;
    char32 chars[3] = { charA, cjk, koala };
    byte bytes[3];
    ASSERT_THROW(e.GetBytes(chars, 3, -1, 1, bytes, 3, 0), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 0, 4, bytes, 3, 0), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 1, 3, bytes, 3, 0), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 2, 2, bytes, 3, 0), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 3, 1, bytes, 3, 0), ArgumentOutOfRangeException);
    ASSERT_THROW(e.GetBytes(chars, 3, 0, 3, bytes, 3, 1), ArgumentException);
    ASSERT_THROW(e.GetBytes(chars, 3, 0, 3, bytes, 3, 1), ArgumentException);
    ASSERT_THROW(e.GetBytes(chars, 3, 0, 2, bytes, 3, 2), ArgumentException);
    ASSERT_THROW(e.GetBytes(chars, 3, 0, 1, bytes, 3, 3), ArgumentException);
    ASSERT_THROW(e.GetBytes(chars, 3, 0, 0, bytes, 3, 4), ArgumentException);
    ASSERT_THROW(e.GetBytes(chars, 3, 4, 0, bytes, 3, 0), ArgumentException);
  }
  
  TEST(ASCII_EncodingTest, x) {
    Text::ASCIIEncoding e;
    byte bytes[1];
    ASSERT_EQ(1, e.GetBytes(charA, bytes, 1, 0));
    ASSERT_EQ(0x61, bytes[0]);
  }
  
  
  TEST(ASCII_EncodingTest, GetBytes_Exceptions) {
    Text::ASCIIEncoding ascii;
    EncodingUT::CheckErrorsGetBytes(ascii);
  }
  
  TEST(ASCII_EncodingTest, GetByteCount_Exceptions) {
    Text::ASCIIEncoding ascii;
    EncodingUT::CheckErrorsString(ascii);
  }
  
  TEST(ASCII_EncodingTest, GetCharCount_Exceptions) {
    Text::ASCIIEncoding ascii;
    EncodingUT::CheckErrorsString(ascii);
  }
  
  TEST(ASCII_EncodingTest, GetChars_Exceptions) {
    Text::ASCIIEncoding ascii;
    EncodingUT::CheckErrorsString(ascii);
  }
  
  TEST(ASCII_EncodingTest, String_Exceptions) {
    Text::ASCIIEncoding ascii;
    EncodingUT::CheckErrorsString(ascii);
  }
  
  TEST(ASCII_EncodingTest, Encode) {
    Text::ASCIIEncoding ascii;
    ASSERT_EQ(20127, ascii.GetCodePage());
    ASSERT_TRUE(ascii.GetEncodingName().Equals("us-ascii"));
    ASSERT_TRUE(ascii.IsReadOnly());
    
    string unicodeString("This unicode string contains two characters "
      "with codes outside the ASCII code range, "
      "Pi (" + Char(928) + "), Sigma (" + Char(931) + ") and KOALA (" + Char(128040) + ").");
      
    // Save the positions of the special characters for later reference.
    int indexOfPi = unicodeString.IndexOf(Char(928));
    int indexOfSigma = unicodeString.IndexOf(Char(931));
    int indexOfKoala = unicodeString.IndexOf(Char(128040));
    ASSERT_EQ(89, indexOfPi);
    ASSERT_EQ(100, indexOfSigma);
    ASSERT_EQ(114, indexOfKoala);
    
    byte reference[] = { 84, 104, 105, 115, 32, 117, 110, 105, 99, 111, 100, 101,
        32, 115, 116, 114, 105, 110, 103, 32, 99, 111, 110, 116, 97, 105, 110, 115,
        32, 116, 119, 111, 32, 99, 104, 97, 114, 97, 99, 116, 101, 114, 115, 32,
        119, 105, 116, 104, 32, 99, 111, 100, 101, 115, 32, 111, 117, 116, 115,
        105, 100, 101, 32, 116, 104, 101, 32, 65, 83, 67, 73, 73, 32, 99, 111, 100,
        101, 32, 114, 97, 110, 103, 101, 44, 32, 80, 105, 32, 40, 63, 41, 44, 32,
        83, 105, 103, 109, 97, 32, 40, 63, 41, 32, 97, 110, 100, 32, 75, 79, 65,
        76, 65, 32, 40, 63, 41, 46
      };
      
    // Encode the string.
    Bytes encodedBytes = ascii.GetBytes(unicodeString);
    int index = 0;
    for(byte b : encodedBytes)
      ASSERT_EQ(reference[index++], b);
      
    ASSERT_EQ(unicodeString.Length(), ascii.GetCharCount(encodedBytes.Data, encodedBytes.Length, 0, encodedBytes.Length));
    
    // Notice that the special characters have been replaced with
    // the value 63, which is the ASCII character code for Text::Encoding::Unknown().
    ASSERT_EQ(Text::Encoding::Unknown(), encodedBytes.GetValue(indexOfPi));
    ASSERT_EQ(Text::Encoding::Unknown(), encodedBytes.GetValue(indexOfSigma));
    ASSERT_EQ(Text::Encoding::Unknown(), encodedBytes.GetValue(indexOfKoala));
    
    // Decode bytes back to a string.
    // Notice missing the Pi and Sigma characters.
    string asciiString("This unicode string contains two characters "
      "with codes outside the ASCII code range, "
      "Pi (?), Sigma (?) and KOALA (?).");
    string decodedString = ascii.GetString(encodedBytes.Data, encodedBytes.Length);
    ASSERT_TRUE(decodedString.Equals(asciiString));
  }
  
  TEST(ASCII_EncodingTest, GetByteCount) {
    EncodingUT::GetByteCountTest(new Text::ASCIIEncoding(), 1, 1, 1, 1);
  }
  
  TEST(ASCII_EncodingTest, GetBytes) {
    EncodingUT::GetBytesTest(new Text::ASCIIEncoding(), 1, 1, 1, 1,
      "80, 105, 32, 63, 32, 83, 105, 103, 109, 97, 32, 63, 32, 75, 79, 65, 76, 65, 32, 63",
      "97", "63", "63");
  }
  
  TEST(ASCII_EncodingTest, GetCharCount_byte_array_null) {
    Text::ASCIIEncoding encoding;
    ASSERT_EQ(0, encoding.GetCharCount(null, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
  }
  
  TEST(ASCII_EncodingTest, GetCharCount_byte_array_index_count_null) {
    Text::ASCIIEncoding encoding;
    ASSERT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
  }
  
  /*
  TEST(ASCII_EncodingTest, GetCharCount_and_GetChars) {
    byte unicodeBytesASCII[] = {80, 105, 32, 63, 32, 83, 105, 103, 109, 97, 32,
      63, 32, 75, 79, 65, 76, 65, 32, 63 };
    Bytes charBytes = {97};
    Bytes piBytes = {63};
    Bytes koalaBytes = {63};
  
    GetCharCountTest(new Text::ASCIIEncoding(), 1, 1, 1, 1, new Bytes(unicodeBytesASCII),
      charBytes, piBytes, koalaBytes);
  
    GetCharsTest(new Text::ASCIIEncoding(), 1, 1, 1, 1, new Bytes(unicodeBytesASCII),
      charBytes, piBytes, koalaBytes);
  }
  */
}
