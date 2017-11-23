#include "EncodingUT.hpp"
#include <Switch/System/Text/UTF8Encoding.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {

  TEST(UTF8_EncodingTest, Badly_Formed_UTF8_Begining) {
    Text::UTF8Encoding u8;
    byte bytes[] = {233, 'a', 'b' };
    string s = u8.GetString(bytes, 3);
    ASSERT_EQ("ab", s);
  }
  
  TEST(UTF8_EncodingTest, Badly_Formed_UTF8_Middle) {
    Text::UTF8Encoding u8;
    byte bytes[] = {'a', 233, 'b' };
    string s = u8.GetString(bytes, 3);
    ASSERT_EQ("ab", s);
  }
  
  TEST(UTF8_EncodingTest, Badly_Formed_UTF8_Multiple) {
    Text::UTF8Encoding u8;
    byte bytes[] = {'a', 233, 233, 253, 'b', 233 };
    string s = u8.GetString(bytes, 6);
    ASSERT_EQ("ab", s);
  }
  
  TEST(UTF8_EncodingTest, Badly_Formed_UTF8_End) {
    Text::UTF8Encoding u8;
    byte bytes[] = {'a', 'b', 233};
    string s = u8.GetString(bytes, 3);
    ASSERT_EQ("ab", s);
  }
  
  TEST(UTF8_EncodingTest, GetBytes_Exceptions) {
    Text::UTF8Encoding u8;
    EncodingUT::CheckErrorsGetBytes(u8);
  }
  
  TEST(UTF8_EncodingTest, GetByteCount_Exceptions) {
    Text::UTF8Encoding u8;
    EncodingUT::CheckErrorsString(u8);
  }
  
  TEST(UTF8_EncodingTest, GetCharCount_Exceptions) {
    Text::UTF8Encoding u8;
    EncodingUT::CheckErrorsString(u8);
  }
  
  TEST(UTF8_EncodingTest, GetChars_Exceptions) {
    Text::UTF8Encoding u8;
    EncodingUT::CheckErrorsString(u8);
  }
  
  TEST(UTF8_EncodingTest, String_Exceptions) {
    Text::UTF8Encoding u8;
    EncodingUT::CheckErrorsString(u8);
  }
  
  TEST(UTF8_EncodingTest, Encode) {
    Text::UTF8Encoding utf8;
    ASSERT_EQ(65001, utf8.GetCodePage());
    ASSERT_TRUE(utf8.GetEncodingName().Equals("utf-8"));
    ASSERT_TRUE(utf8.IsReadOnly());
    
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
        101, 32, 114, 97, 110, 103, 101, 44, 32, 80, 105, 32, 40, 206, 160, 41, 44,
        32, 83, 105, 103, 109, 97, 32, 40, 206, 163, 41, 32, 97, 110, 100, 32, 75,
        79, 65, 76, 65, 32, 40, 240, 159, 144, 168, 41, 46
      };
      
    // Encode the string.
    EncodingUT::Bytes encodedBytes = utf8.GetBytes(unicodeString);
    int index = 0;
    for (byte b : encodedBytes)
      ASSERT_EQ(reference[index++], b);
      
    ASSERT_EQ(unicodeString.Length(), utf8.GetCharCount(encodedBytes.Data, encodedBytes.Length, 0, encodedBytes.Length));
    
    ASSERT_EQ(206, encodedBytes.GetValue(indexOfPi));
    ASSERT_EQ(160, encodedBytes.GetValue(indexOfPi + 1));
    // one more byte because pi is 2 bytes encoded before in the byte stream
    ASSERT_EQ(206, encodedBytes.GetValue(indexOfSigma + 1));
    ASSERT_EQ(163, encodedBytes.GetValue(indexOfSigma + 2));
    // two more bytes because pi and sigma are 2 bytes encoded before in the byte stream
    ASSERT_EQ(240, encodedBytes.GetValue(indexOfKoala + 2));
    ASSERT_EQ(159, encodedBytes.GetValue(indexOfKoala + 3));
    ASSERT_EQ(144, encodedBytes.GetValue(indexOfKoala + 4));
    ASSERT_EQ(168, encodedBytes.GetValue(indexOfKoala + 5));
    
    // Decode bytes back to a string.
    // Notice missing the Pi and Sigma characters.
    string decodedString = utf8.GetString(encodedBytes.Data, encodedBytes.Length);
    ASSERT_TRUE(decodedString.Equals(unicodeString));
  }
  
  TEST(UTF8_EncodingTest, BOM) {
    Text::UTF8Encoding utf8;
    Text::UTF8Encoding utf8EmitBOM(true);
    
    EncodingUT::Bytes preamble;
    preamble = utf8.GetPreamble();
    ASSERT_EQ(0, preamble.Length);
    
    preamble = utf8EmitBOM.GetPreamble();
    ASSERT_EQ(3, preamble.Length);
    ASSERT_EQ(239, preamble.GetValue(0));
    ASSERT_EQ(187, preamble.GetValue(1));
    ASSERT_EQ(191, preamble.GetValue(2));
  }
  
  TEST(UTF8_EncodingTest, GetByteCount) {
    EncodingUT::GetByteCountTest(new Text::UTF8Encoding(), 1, 2, 2, 4);
  }
  
  TEST(UTF8_EncodingTest, GetBytes) {
    EncodingUT::GetBytesTest(new Text::UTF8Encoding(), 1, 2, 2, 4,
      "80, 105, 32, 206, 160, 32, 83, 105, 103, 109, 97, 32, 206, 163, 32, 75, 79, 65, 76, 65, 32, 240, 159, 144, 168",
      "97", "206, 160", "240, 159, 144, 168");
  }
  
  TEST(UTF8_EncodingTest, GetCharCount_byte_array_null) {
    Text::UTF8Encoding encoding;
    ASSERT_EQ(0, encoding.GetCharCount(null, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
  }
  
  TEST(UTF8_EncodingTest, GetCharCount_byte_array_index_count_null) {
    Text::UTF8Encoding encoding;
    ASSERT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
  }
  
  /*
  TEST(UTF8_EncodingTest, GetCharCount_and_GetChars) {
    byte unicodeBytesUTF8[] = { 80, 105, 32, 206, 160, 32, 83, 105, 103, 109, 97,
      32, 206, 163, 32, 75, 79, 65, 76, 65, 32, 240, 159, 144, 168 };
    EncodingUT::Bytes charBytes = {97};
    EncodingUT::Bytes piBytes = {206, 160};
    EncodingUT::Bytes koalaBytes = {240, 159, 144, 168};
  
    GetCharCountTest(new Text::UTF8Encoding), 1, 2, 2, 4, new EncodingUT::Bytes(unicodeBytesUTF8),
      charBytes, piBytes, koalaBytes);
  
    GetCharsTest(new Text::UTF8Encoding), 1, 2, 2, 4, new EncodingUT::Bytes(unicodeBytesUTF8),
      charBytes, piBytes, koalaBytes);
  }*/
  
  
}
