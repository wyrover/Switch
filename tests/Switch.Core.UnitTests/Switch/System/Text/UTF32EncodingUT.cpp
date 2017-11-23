#include "EncodingUT.hpp"
#include <Switch/System/Text/UTF32Encoding.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {

  TEST(UTF32_EncodingTest, GetBytes_Exceptions) {
    Text::UTF32Encoding u32(false);
    EncodingUT::CheckErrorsGetBytes(u32);
  }
  
  TEST(UTF32_EncodingTest, GetByteCount_Exceptions) {
    Text::UTF32Encoding u32(false);
    EncodingUT::CheckErrorsGetByteCount(u32);
  }
  
  TEST(UTF32_EncodingTest, GetCharCount_Exceptions) {
    Text::UTF32Encoding u32(false);
    EncodingUT::CheckErrorsGetCharCount(u32);
  }
  
  TEST(UTF32_EncodingTest, GetChars_Exceptions) {
    Text::UTF32Encoding u32(false);
    EncodingUT::CheckErrorsGetChars(u32);
  }
  
  TEST(UTF32_EncodingTest, String_Exceptions) {
    Text::UTF32Encoding u32(false);
    EncodingUT::CheckErrorsString(u32);
  }
  
  TEST(UTF32_EncodingTest, Ctor) {
    EncodingUT::Bytes preamble;
    refptr<Text::Encoding> def = new Text::UTF32Encoding();
    refptr<Text::Encoding> eFF = new Text::UTF32Encoding(false, false);
    refptr<Text::Encoding> eFT = new Text::UTF32Encoding(false, true);
    refptr<Text::Encoding> eTF = new Text::UTF32Encoding(true, false);
    refptr<Text::Encoding> eTT = new Text::UTF32Encoding(true, true);
    
    ASSERT_EQ(12000, def->GetCodePage());
    ASSERT_TRUE(def->IsReadOnly());
    ASSERT_FALSE(def->IsSingleByte());
    preamble = def->GetPreamble();
    ASSERT_EQ(4, preamble.Length);
    ASSERT_EQ(string::Join(", ", preamble), "255, 254, 0, 0");
    
    ASSERT_EQ(12000, eFF->GetCodePage());
    ASSERT_TRUE(eFF->IsReadOnly());
    ASSERT_FALSE(eFF->IsSingleByte());
    preamble = eFF->GetPreamble();
    ASSERT_EQ(0, preamble.Length);
    
    ASSERT_EQ(12000, eFT->GetCodePage());
    ASSERT_TRUE(eFT->IsReadOnly());
    ASSERT_FALSE(eFT->IsSingleByte());
    preamble = eFT->GetPreamble();
    ASSERT_EQ(4, preamble.Length);
    ASSERT_EQ(string::Join(", ", preamble), "255, 254, 0, 0");
    
    ASSERT_EQ(12001, eTF->GetCodePage());
    ASSERT_TRUE(eTF->IsReadOnly());
    ASSERT_FALSE(eTF->IsSingleByte());
    preamble = eTF->GetPreamble();
    ASSERT_EQ(0, preamble.Length);
    
    ASSERT_EQ(12001, eTT->GetCodePage());
    ASSERT_TRUE(eTT->IsReadOnly());
    ASSERT_FALSE(eTT->IsSingleByte());
    preamble = eTT->GetPreamble();
    ASSERT_EQ(4, preamble.Length);
    ASSERT_EQ(string::Join(", ", preamble), "0, 0, 254, 255");
  }
  
  TEST(UTF32_EncodingTest, Encode) {
    // The encoding, utf32 big endian, BOM.
    refptr<Text::UTF32Encoding> unicode = new Text::UTF32Encoding();
    
    // Create a string that contains Unicode characters.
    string unicodeString("This unicode string contains two characters "
      "with codes outside the ASCII code range, "
      "Pi (" + Char(928) + "), Sigma (" + Char(931) + ") and KOALA (" + Char(128040) + ").");
      
    byte reference[] = { 84, 0, 0, 0, 104, 0, 0, 0, 105, 0, 0, 0, 115, 0, 0, 0,
        32, 0, 0, 0, 117, 0, 0, 0, 110, 0, 0, 0, 105, 0, 0, 0, 99, 0, 0, 0, 111, 0,
        0, 0, 100, 0, 0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 115, 0, 0, 0, 116, 0, 0, 0,
        114, 0, 0, 0, 105, 0, 0, 0, 110, 0, 0, 0, 103, 0, 0, 0, 32, 0, 0, 0, 99, 0,
        0, 0, 111, 0, 0, 0, 110, 0, 0, 0, 116, 0, 0, 0, 97, 0, 0, 0, 105, 0, 0, 0,
        110, 0, 0, 0, 115, 0, 0, 0, 32, 0, 0, 0, 116, 0, 0, 0, 119, 0, 0, 0, 111,
        0, 0, 0, 32, 0, 0, 0, 99, 0, 0, 0, 104, 0, 0, 0, 97, 0, 0, 0, 114, 0, 0, 0,
        97, 0, 0, 0, 99, 0, 0, 0, 116, 0, 0, 0, 101, 0, 0, 0, 114, 0, 0, 0, 115, 0,
        0, 0, 32, 0, 0, 0, 119, 0, 0, 0, 105, 0, 0, 0, 116, 0, 0, 0, 104, 0, 0, 0,
        32, 0, 0, 0, 99, 0, 0, 0, 111, 0, 0, 0, 100, 0, 0, 0, 101, 0, 0, 0, 115, 0,
        0, 0, 32, 0, 0, 0, 111, 0, 0, 0, 117, 0, 0, 0, 116, 0, 0, 0, 115, 0, 0, 0,
        105, 0, 0, 0, 100, 0, 0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 116, 0, 0, 0, 104,
        0, 0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 65, 0, 0, 0, 83, 0, 0, 0, 67, 0, 0, 0,
        73, 0, 0, 0, 73, 0, 0, 0, 32, 0, 0, 0, 99, 0, 0, 0, 111, 0, 0, 0, 100, 0,
        0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 114, 0, 0, 0, 97, 0, 0, 0, 110, 0, 0, 0,
        103, 0, 0, 0, 101, 0, 0, 0, 44, 0, 0, 0, 32, 0, 0, 0, 80, 0, 0, 0, 105, 0,
        0, 0, 32, 0, 0, 0, 40, 0, 0, 0, 160, 3, 0, 0, 41, 0, 0, 0, 44, 0, 0, 0, 32,
        0, 0, 0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0, 97, 0, 0,
        0, 32, 0, 0, 0, 40, 0, 0, 0, 163, 3, 0, 0, 41, 0, 0, 0, 32, 0, 0, 0, 97, 0,
        0, 0, 110, 0, 0, 0, 100, 0, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0, 79, 0, 0, 0,
        65, 0, 0, 0, 76, 0, 0, 0, 65, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 0, 40, 244,
        1, 0, 41, 0, 0, 0, 46, 0, 0, 0
      };
      
    // Encode the string.
    EncodingUT::Bytes encodedBytes = unicode->GetBytes(unicodeString);
    int index = 0;
    for(byte b : encodedBytes)
      ASSERT_EQ(reference[index++], b);
      
    ASSERT_EQ(unicodeString.Length(), unicode->GetCharCount(encodedBytes.Data, encodedBytes.Length, 0, encodedBytes.Length));
    
    // Decode bytes back to string.
    // Notice Pi and Sigma characters are still present.
    string decodedString = unicode->GetString(encodedBytes.Data, encodedBytes.Length);
    ASSERT_TRUE(decodedString.Equals(unicodeString));
  }
  
  TEST(UTF32_EncodingTest, EncodeBigEndian) {
    // The encoding, utf32 big endian, BOM.
    refptr<Text::UTF32Encoding> unicode = new Text::UTF32Encoding(true);
    
    // Create a string that contains Unicode characters.
    string unicodeString("This unicode string contains two characters "
      "with codes outside the ASCII code range, "
      "Pi (" + Char(928) + "), Sigma (" + Char(931) + ") and KOALA (" + Char(128040) + ").");
      
    byte reference[] = { 0, 0, 0, 84, 0, 0, 0, 104, 0, 0, 0, 105, 0, 0, 0, 115,
        0, 0, 0, 32, 0, 0, 0, 117, 0, 0, 0, 110, 0, 0, 0, 105, 0, 0, 0, 99, 0, 0,
        0, 111, 0, 0, 0, 100, 0, 0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 115, 0, 0, 0,
        116, 0, 0, 0, 114, 0, 0, 0, 105, 0, 0, 0, 110, 0, 0, 0, 103, 0, 0, 0, 32,
        0, 0, 0, 99, 0, 0, 0, 111, 0, 0, 0, 110, 0, 0, 0, 116, 0, 0, 0, 97, 0, 0,
        0, 105, 0, 0, 0, 110, 0, 0, 0, 115, 0, 0, 0, 32, 0, 0, 0, 116, 0, 0, 0,
        119, 0, 0, 0, 111, 0, 0, 0, 32, 0, 0, 0, 99, 0, 0, 0, 104, 0, 0, 0, 97, 0,
        0, 0, 114, 0, 0, 0, 97, 0, 0, 0, 99, 0, 0, 0, 116, 0, 0, 0, 101, 0, 0, 0,
        114, 0, 0, 0, 115, 0, 0, 0, 32, 0, 0, 0, 119, 0, 0, 0, 105, 0, 0, 0, 116,
        0, 0, 0, 104, 0, 0, 0, 32, 0, 0, 0, 99, 0, 0, 0, 111, 0, 0, 0, 100, 0, 0,
        0, 101, 0, 0, 0, 115, 0, 0, 0, 32, 0, 0, 0, 111, 0, 0, 0, 117, 0, 0, 0,
        116, 0, 0, 0, 115, 0, 0, 0, 105, 0, 0, 0, 100, 0, 0, 0, 101, 0, 0, 0, 32,
        0, 0, 0, 116, 0, 0, 0, 104, 0, 0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 65, 0, 0,
        0, 83, 0, 0, 0, 67, 0, 0, 0, 73, 0, 0, 0, 73, 0, 0, 0, 32, 0, 0, 0, 99, 0,
        0, 0, 111, 0, 0, 0, 100, 0, 0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 114, 0, 0, 0,
        97, 0, 0, 0, 110, 0, 0, 0, 103, 0, 0, 0, 101, 0, 0, 0, 44, 0, 0, 0, 32, 0,
        0, 0, 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 3, 160, 0, 0, 0,
        41, 0, 0, 0, 44, 0, 0, 0, 32, 0, 0, 0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0,
        0, 0, 109, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 3, 163, 0, 0, 0,
        41, 0, 0, 0, 32, 0, 0, 0, 97, 0, 0, 0, 110, 0, 0, 0, 100, 0, 0, 0, 32, 0,
        0, 0, 75, 0, 0, 0, 79, 0, 0, 0, 65, 0, 0, 0, 76, 0, 0, 0, 65, 0, 0, 0, 32,
        0, 0, 0, 40, 0, 1, 244, 40, 0, 0, 0, 41, 0, 0, 0, 46
      };
      
    // Encode the string.
    EncodingUT::Bytes encodedBytes = unicode->GetBytes(unicodeString);
    int index = 0;
    for(byte b : encodedBytes)
      ASSERT_EQ(reference[index++], b);
      
    ASSERT_EQ(unicodeString.Length(), unicode->GetCharCount(encodedBytes.Data, encodedBytes.Length, 0, encodedBytes.Length));
    
    // Decode bytes back to string.
    // Notice Pi and Sigma characters are still present.
    string decodedString = unicode->GetString(encodedBytes.Data, encodedBytes.Length);
    ASSERT_TRUE(decodedString.Equals(unicodeString));
  }
  
  TEST(UTF32_EncodingTest, GetByteCount) {
    EncodingUT::GetByteCountTest(new Text::UTF32Encoding(false), 4, 4, 4, 4);
  }
  
  TEST(UTF32_EncodingTest, GetByteCountBigEndian) {
    EncodingUT::GetByteCountTest(new Text::UTF32Encoding(true), 4, 4, 4, 4);
  }
  
  TEST(UTF32_EncodingTest, GetBytes) {
    EncodingUT::GetBytesTest(new Text::UTF32Encoding(false), 4, 4, 4, 4,
      "80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 0, 160, 3, 0, 0, 32, 0, 0, 0, 83, 0, "
      "0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, "
      "163, 3, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0, 79, 0, 0, 0, 65, 0, 0, 0, 76, 0, "
      "0, 0, 65, 0, 0, 0, 32, 0, 0, 0, 40, 244, 1, 0",
      "97, 0, 0, 0", "160, 3, 0, 0", "40, 244, 1, 0");
  }
  
  TEST(UTF32_EncodingTest, GetBytesBigEndian) {
    EncodingUT::GetBytesTest(new Text::UTF32Encoding(true), 4, 4, 4, 4,
      "0, 0, 0, 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 3, 160, 0, 0, 0, 32, 0, 0, "
      "0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0, 97, 0, 0, 0, 32, "
      "0, 0, 3, 163, 0, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0, 79, 0, 0, 0, 65, 0, 0, 0, "
      "76, 0, 0, 0, 65, 0, 0, 0, 32, 0, 1, 244, 40",
      "0, 0, 0, 97", "0, 0, 3, 160", "0, 1, 244, 40");
  }
  
  TEST(UTF32_EncodingTest, GetCharCount_byte_array_null) {
    Text::UTF32Encoding encoding(false);
    ASSERT_EQ(0, encoding.GetCharCount(null, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
  }
  
  TEST(UTF32_EncodingTest, GetCharCount_byte_array_index_count_null) {
    Text::UTF32Encoding encoding(false);
    ASSERT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
  }
  
  TEST(UTF32_EncodingTest, GetCharCount_byte_array_null_BigEndian) {
    Text::UTF32Encoding encoding(true);
    ASSERT_EQ(0, encoding.GetCharCount(null, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
  }
  
  TEST(UTF32_EncodingTest, GetCharCount_byte_array_index_count_null_BigEndian) {
    Text::UTF32Encoding encoding(true);
    ASSERT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
    ASSERT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
  }
  
  /*
  TEST(UTF32_EncodingTest, GetCharCount_and_GetChars) {
    byte unicodeBytesUTF32[] = { 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 0, 160, 3,
      0, 0, 32, 0, 0, 0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0,
      97, 0, 0, 0, 32, 0, 0, 0, 163, 3, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0, 79, 0, 0,
      0, 65, 0, 0, 0, 76, 0, 0, 0, 65, 0, 0, 0, 32, 0, 0, 0, 40, 244, 1, 0 };
    EncodingUT::Bytes charBytes = {97, 0, 0, 0};
    EncodingUT::Bytes piBytes = {160, 3, 0, 0};
    EncodingUT::Bytes koalaBytes = {40, 244, 1, 0};
  
    Text::UTF32Encoding e(false);
    GetCharCountTest(e, 4, 4, 4, 4, unicodeBytesUTF32,80);
    GetCharsTest(e, 4, 4, 4, 4, unicodeBytesUTF32,80);
  }
  
  TEST(UTF32_EncodingTest, GetCharCount_and_GetChars_BigEndian) {
    byte unicodeBytesUTF32BE[] = { 0, 0, 0, 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0,
      3, 160, 0, 0, 0, 32, 0, 0, 0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109,
      0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 3, 163, 0, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0,
      79, 0, 0, 0, 65, 0, 0, 0, 76, 0, 0, 0, 65, 0, 0, 0, 32, 0, 1, 244, 40 };
    EncodingUT::Bytes charBytes = {0, 0, 0, 97};
    EncodingUT::Bytes piBytes = {0, 0, 3, 160};
    EncodingUT::Bytes koalaBytes = {0, 1, 244, 40};
  
    GetCharCountTest(new Text::UTF32Encoding(true), 4, 4, 4, 4, new EncodingUT::Bytes(unicodeBytesUTF32BE),
      charBytes, piBytes, koalaBytes);
  
    GetCharsTest(new Text::UTF32Encoding(true), 4, 4, 4, 4, new EncodingUT::Bytes(unicodeBytesUTF32BE),
      charBytes, piBytes, koalaBytes);
  }
  */
  
}
