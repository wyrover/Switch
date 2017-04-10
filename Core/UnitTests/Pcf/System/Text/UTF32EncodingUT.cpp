#include "EncodingUT.h"
#include <Pcf/System/Text/UTF32Encoding.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

TEST(UTF32_Encoding, GetBytes_Exceptions) {
  Text::UTF32Encoding u32(false);
  EncodingUT::CheckErrorsGetBytes(u32);
}

TEST(UTF32_Encoding, GetByteCount_Exceptions) {
  Text::UTF32Encoding u32(false);
  EncodingUT::CheckErrorsGetByteCount(u32);
}

TEST(UTF32_Encoding, GetCharCount_Exceptions) {
  Text::UTF32Encoding u32(false);
  EncodingUT::CheckErrorsGetCharCount(u32);
}

TEST(UTF32_Encoding, GetChars_Exceptions) {
  Text::UTF32Encoding u32(false);
  EncodingUT::CheckErrorsGetChars(u32);
}

TEST(UTF32_Encoding, String_Exceptions) {
  Text::UTF32Encoding u32(false);
  EncodingUT::CheckErrorsString(u32);
}

TEST(UTF32_Encoding, Ctor) {
  EncodingUT::Bytes preamble;
  RefPtr<Text::Encoding> def = new Text::UTF32Encoding();
  RefPtr<Text::Encoding> eFF = new Text::UTF32Encoding(false,false);
  RefPtr<Text::Encoding> eFT = new Text::UTF32Encoding(false, true);
  RefPtr<Text::Encoding> eTF = new Text::UTF32Encoding(true, false);
  RefPtr<Text::Encoding> eTT = new Text::UTF32Encoding(true, true);

  EXPECT_EQ(12000, def->GetCodePage());
  EXPECT_TRUE(def->IsReadOnly());
  EXPECT_FALSE(def->IsSingleByte());
  preamble = def->GetPreamble();
  EXPECT_EQ(4,preamble.Length);
  EXPECT_EQ(string::Join(", ", preamble), "255, 254, 0, 0");

  EXPECT_EQ(12000, eFF->GetCodePage());
  EXPECT_TRUE(eFF->IsReadOnly());
  EXPECT_FALSE(eFF->IsSingleByte());
  preamble = eFF->GetPreamble();
  EXPECT_EQ(0,preamble.Length);

  EXPECT_EQ(12000, eFT->GetCodePage());
  EXPECT_TRUE(eFT->IsReadOnly());
  EXPECT_FALSE(eFT->IsSingleByte());
  preamble = eFT->GetPreamble();
  EXPECT_EQ(4,preamble.Length);
  EXPECT_EQ(string::Join(", ", preamble), "255, 254, 0, 0");

  EXPECT_EQ(12001, eTF->GetCodePage());
  EXPECT_TRUE(eTF->IsReadOnly());
  EXPECT_FALSE(eTF->IsSingleByte());
  preamble = eTF->GetPreamble();
  EXPECT_EQ(0,preamble.Length);

  EXPECT_EQ(12001, eTT->GetCodePage());
  EXPECT_TRUE(eTT->IsReadOnly());
  EXPECT_FALSE(eTT->IsSingleByte());
  preamble = eTT->GetPreamble();
  EXPECT_EQ(4,preamble.Length);
  EXPECT_EQ(string::Join(", ", preamble), "0, 0, 254, 255");
}

TEST(UTF32_Encoding, Encode) {
  // The encoding, utf32 big endian, BOM.
  RefPtr<Text::UTF32Encoding> unicode = new Text::UTF32Encoding();

  // Create a string that contains Unicode characters.
  string unicodeString("This unicode string contains two characters "
      "with codes outside the ASCII code range, "
      "Pi (" + Char(928) +"), Sigma ("+ Char(931) +") and KOALA (" + Char(128040) + ").");

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
    1, 0, 41, 0, 0, 0, 46, 0, 0, 0 };

  // Encode the string.
  EncodingUT::Bytes encodedBytes = unicode->GetBytes(unicodeString);
  int index = 0;
  for (byte b : encodedBytes)
    EXPECT_EQ(reference[index++],b);

  EXPECT_EQ(unicodeString.Length(), unicode->GetCharCount(encodedBytes.Data, encodedBytes.Length,0,encodedBytes.Length));

  // Decode bytes back to string. 
  // Notice Pi and Sigma characters are still present.
  string decodedString = unicode->GetString(encodedBytes.Data, encodedBytes.Length);
  EXPECT_TRUE(decodedString.Equals(unicodeString));
}

TEST(UTF32_Encoding, EncodeBigEndian) {
  // The encoding, utf32 big endian, BOM.
  RefPtr<Text::UTF32Encoding> unicode = new Text::UTF32Encoding(true);

  // Create a string that contains Unicode characters.
  string unicodeString("This unicode string contains two characters "
      "with codes outside the ASCII code range, "
      "Pi (" + Char(928) +"), Sigma ("+ Char(931) +") and KOALA (" + Char(128040) + ").");

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
    0, 0, 0, 40, 0, 1, 244, 40, 0, 0, 0, 41, 0, 0, 0, 46 };

  // Encode the string.
  EncodingUT::Bytes encodedBytes = unicode->GetBytes(unicodeString);
  int index = 0;
  for (byte b : encodedBytes) {
    EXPECT_EQ(reference[index++],b);
  }

  EXPECT_EQ(unicodeString.Length(), unicode->GetCharCount(encodedBytes.Data, encodedBytes.Length,0,encodedBytes.Length));

  // Decode bytes back to string. 
  // Notice Pi and Sigma characters are still present.
  string decodedString = unicode->GetString(encodedBytes.Data, encodedBytes.Length);
  EXPECT_TRUE(decodedString.Equals(unicodeString));
}

TEST(UTF32_Encoding, GetByteCount) {
  EncodingUT::GetByteCountTest(new Text::UTF32Encoding(false),4,4,4,4);
}

TEST(UTF32_Encoding, GetByteCountBigEndian) {
  EncodingUT::GetByteCountTest(new Text::UTF32Encoding(true),4,4,4,4);
}

TEST(UTF32_Encoding, GetBytes) {
  EncodingUT::GetBytesTest(new Text::UTF32Encoding(false), 4, 4, 4, 4, 
    "80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 0, 160, 3, 0, 0, 32, 0, 0, 0, 83, 0, "
    "0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, "
    "163, 3, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0, 79, 0, 0, 0, 65, 0, 0, 0, 76, 0, "
    "0, 0, 65, 0, 0, 0, 32, 0, 0, 0, 40, 244, 1, 0", 
    "97, 0, 0, 0", "160, 3, 0, 0", "40, 244, 1, 0");
}

TEST(UTF32_Encoding, GetBytesBigEndian) {
  EncodingUT::GetBytesTest(new Text::UTF32Encoding(true), 4, 4, 4, 4, 
    "0, 0, 0, 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 3, 160, 0, 0, 0, 32, 0, 0, "
    "0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0, 97, 0, 0, 0, 32, "
    "0, 0, 3, 163, 0, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0, 79, 0, 0, 0, 65, 0, 0, 0, "
    "76, 0, 0, 0, 65, 0, 0, 0, 32, 0, 1, 244, 40",
    "0, 0, 0, 97", "0, 0, 3, 160", "0, 1, 244, 40");
}

TEST(UTF32_Encoding, GetCharCount_byte_array_null) {
  Text::UTF32Encoding encoding(false);
  EXPECT_EQ(0, encoding.GetCharCount(null, 0));
  EXPECT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
}

TEST(UTF32_Encoding, GetCharCount_byte_array_index_count_null) {
  Text::UTF32Encoding encoding(false);
  EXPECT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
  EXPECT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
  EXPECT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
}

TEST(UTF32_Encoding, GetCharCount_byte_array_null_BigEndian) {
  Text::UTF32Encoding encoding(true);
  EXPECT_EQ(0, encoding.GetCharCount(null, 0));
  EXPECT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
}

TEST(UTF32_Encoding, GetCharCount_byte_array_index_count_null_BigEndian) {
  Text::UTF32Encoding encoding(true);
  EXPECT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
  EXPECT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
  EXPECT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
}

/*
TEST(UTF32_Encoding, GetCharCount_and_GetChars) {
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

TEST(UTF32_Encoding, GetCharCount_and_GetChars_BigEndian) {
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
