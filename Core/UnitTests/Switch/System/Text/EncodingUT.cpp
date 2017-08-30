#include "EncodingUT.hpp"
#include <Switch/System/Text/ASCIIEncoding.hpp>
#include <Switch/System/Text/ANSIEncoding.hpp>
#include <Switch/System/Text/UnicodeEncoding.hpp>
#include <Switch/System/Text/UTF8Encoding.hpp>
#include <Switch/System/Text/UTF32Encoding.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace TUnit;

namespace EncodingUT {

  UnicodeSequence UnicodeCharacter::operator+(const UnicodeCharacter& info) const {
    return UnicodeSequence(*this) + UnicodeSequence(info);
  }

  bool UnicodeCharacter::operator==(const UnicodeCharacter& c) const {
    return character == c.character && bytes == c.bytes && decodedCharacter == c.decodedCharacter;
  }

  UnicodeSequence UnicodeSequence::operator+(const UnicodeSequence& info) const {
    UnicodeSequence s(*this);
    s += info;
    return s;
  }

  UnicodeSequence& UnicodeSequence::operator+=(const UnicodeSequence& info) {
    for (int32 i = 0; i < info.chars.Count; i += 1) {
      chars.Add(info.chars[i]);
    }
    for (int32  i = 0; i < info.bytes.Count; i += 1) {
      bytes.Add(info.bytes[i]);
    }
    for (int32  i = 0; i < info.decodedChars.Count; i += 1) {
      decodedChars.Add(info.decodedChars[i]);
    }
    return *this;    
  }

  int32 ConcatBytes(byte destBytes[], int32 index, const byte bytes[], int32 size) {
    memcpy(&destBytes[index], bytes, size);
    return index + size;
  }

  void EXPECT_CHARS(const char32 expected[], int32 size, Array<char32> actual) {
    ASSERT_EQ(size, actual.Length);
    for (int32 i = 0; i < size; i += 1) {
      ASSERT_EQ(expected[i], actual[i]);
    }
  }

  void EXPECT_CHARS(const char32 expected[], int32 size, const char32 actual[]) {
    for (int32 i = 0; i < size; i += 1) {
      ASSERT_EQ(expected[i], actual[i]);
    }
  }

  void EXPECT_BYTES(const byte expected[], int32 size, Array<byte> actual) {
    ASSERT_EQ(size, actual.Length);
    for (int32 i = 0; i < size; i += 1) {
      ASSERT_EQ(expected[i], actual[i]);
    }
  }

  void EXPECT_BYTES(const byte expected[], int32 size, const byte actual[]) {
    for (int32 i = 0; i < size; i += 1) {
      ASSERT_EQ(expected[i], actual[i]);
    }
  }

  void CheckErrorsGetByteCount(const Encoding& encoding) {
    char32 chars[] = { 32, 32, 32, 32 };
    EXPECT_THROW(encoding.GetByteCount(chars, 4, -1,  3), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetByteCount(chars, 4, 0, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetByteCount(chars, 4, 0,  5), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetByteCount(chars, 4, 1,  4), ArgumentOutOfRangeException);
  }

  void CheckErrorsGetBytes(const Encoding& encoding) {
    byte bytes[4] = { 0x32, 0x32, 0x32, 0x32 };
    char32 chars[4] = { 32, 32, 32, 32 };

    EXPECT_THROW(encoding.GetBytes(null,  0,  0,  4, bytes, 4,  0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetBytes(chars, 4,  0,  4, null, 0,  0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetBytes(chars, 4, -1,  4, bytes, 4,  0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetBytes(chars, 4,  0, -1, bytes, 4,  0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetBytes(chars, 4,  0,  4, bytes, 4, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetBytes(chars, 4,  0,  5, bytes, 4,  0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetBytes(chars, 4,  1,  4, bytes, 4,  0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetBytes(chars, 4,  0,  4, bytes, 4,  1), ArgumentException);
  }

  void CheckErrorsGetCharCount(const Encoding& encoding) {
    byte bytes[] = { 0x32, 0x32, 0x32, 0x32 };
    EXPECT_THROW(encoding.GetCharCount(bytes, 4, -1, 4), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetCharCount(bytes, 4, 0,-1), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetCharCount(bytes, 4, 0, 5), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetCharCount(bytes, 4, 1, 4), ArgumentOutOfRangeException);
  }

  void CheckErrorsGetChars(const Encoding& encoding) {
    byte bytes[4] = { 0x32, 0x32, 0x32, 0x32 };
    char32 chars[4] = { 32, 32, 32, 32 };

    EXPECT_THROW(encoding.GetChars(bytes, 4,-1, 4, chars, 4, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetChars(bytes, 4, 0,-1, chars, 4, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetChars(bytes, 4, 0, 4, chars, 4,-1), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetChars(bytes, 4, 0, 5, chars, 4, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(encoding.GetChars(bytes, 4, 1, 4, chars, 4, 0), ArgumentOutOfRangeException);
  }

  void CheckErrorsString(const Encoding& encoding) {
    Bytes bytes = {0x32, 0x32, 0x32, 0x32};
    Chars chars = {32, 32, 32, 32};

    Bytes emptyBytes = encoding.GetBytes("");
    EXPECT_EQ(0, emptyBytes.Length);

    string emptyString = encoding.GetString(null,0);
    EXPECT_EQ(0, emptyString.Length());
  }

  void GetByteCountTest(refptr<Encoding> encoding, int charByteSize, int piByteSize, int sigmaByteSize, int koalaByteSize) {
    string unicodeString = "Pi " + Char(928) + " Sigma " + Char(931) + " KOALA " + Char(128040);
    Array<char32> chars = unicodeString.ToCharArray();

    EXPECT_EQ(charByteSize, encoding->GetByteCount(chars.Data, chars.Count, 0, 1));
    EXPECT_EQ(piByteSize, encoding->GetByteCount(chars.Data, chars.Count, 3, 1));
    EXPECT_EQ(sigmaByteSize, encoding->GetByteCount(chars.Data, chars.Count, 11, 1));
    EXPECT_EQ(koalaByteSize, encoding->GetByteCount(chars.Data, chars.Count, 19, 1));

    EXPECT_EQ(20, chars.Count);
    EXPECT_EQ(charByteSize * 17 + piByteSize + sigmaByteSize + koalaByteSize, encoding->GetByteCount(chars.Data, chars.Count));
    EXPECT_EQ(charByteSize * 17 + piByteSize + sigmaByteSize + koalaByteSize, encoding->GetByteCount(unicodeString));

    EXPECT_EQ(0, encoding->GetByteCount(chars.Data, chars.Count, 0, 0));
    EXPECT_EQ(0, encoding->GetByteCount(chars.Data, chars.Count, 1, 0));
    EXPECT_EQ(0, encoding->GetByteCount(chars.Data, chars.Count, 2, 0));

    EXPECT_EQ(0, encoding->GetByteCount(chars.Data, chars.Count, chars.Count - 2, 0));
    EXPECT_EQ(0, encoding->GetByteCount(chars.Data, chars.Count, chars.Count - 1, 0));
    EXPECT_EQ(0, encoding->GetByteCount(chars.Data, chars.Count, chars.Count, 0));
    EXPECT_THROW(encoding->GetByteCount(chars.Data, chars.Count, chars.Count + 1, 0), ArgumentOutOfRangeException);

    EXPECT_EQ(charByteSize * 3, encoding->GetByteCount(chars.Data, chars.Count,  0, 3));
    EXPECT_EQ(charByteSize * 6 + koalaByteSize, encoding->GetByteCount(chars.Data, chars.Count, 13, 7));
    EXPECT_THROW(encoding->GetByteCount(chars.Data, chars.Count, 13, 8), ArgumentOutOfRangeException);
  }

  void ExpectBytes(const Bytes& bytes, const string& strBytes) {
    string join = string::Join(", ", bytes);
    EXPECT_TRUE(join.Equals(strBytes));
  }

  void GetBytesTest(refptr<Encoding> encoding, int charByteSize, int piByteSize, int sigmaByteSize, int koalaByteSize, 
    const string& unicodeBytes, const string& charBytes, const string& piBytes, const string& koalaBytes) {   
      string unicodeString = "Pi " + Char(928) + " Sigma " + Char(931) + " KOALA " + Char(128040);
      string emptyString = "";
      string charString = "a";
      string piString = Char(928).ToString();
      string koalaString = Char(128040).ToString();

      Array<char32> unicodeChars = unicodeString.ToCharArray();
      Array<char32> emptyChars = emptyString.ToCharArray();
      Array<char32> charChars = charString.ToCharArray();
      Array<char32> piChars = piString.ToCharArray();
      Array<char32> koalaChars = koalaString.ToCharArray();

      ExpectBytes(encoding->GetBytes(unicodeString), unicodeBytes);
      ExpectBytes(encoding->GetBytes(emptyString), "");
      ExpectBytes(encoding->GetBytes(charString), charBytes);
      ExpectBytes(encoding->GetBytes(piString), piBytes);
      ExpectBytes(encoding->GetBytes(koalaString), koalaBytes);

      ExpectBytes(encoding->GetBytes(unicodeString), unicodeBytes );
      ExpectBytes(encoding->GetBytes(emptyString), "");
      ExpectBytes(encoding->GetBytes(charString), charBytes);
      ExpectBytes(encoding->GetBytes(piString), piBytes);
      ExpectBytes(encoding->GetBytes(koalaString), koalaBytes);

      ExpectBytes(encoding->GetBytes(unicodeString, 0, 0),"");
      ExpectBytes(encoding->GetBytes(unicodeString, 1, 0),"");
      ExpectBytes(encoding->GetBytes(unicodeString, 2, 0),"");
      ExpectBytes(encoding->GetBytes(unicodeString, 20, 0),"");
      EXPECT_THROW(encoding->GetBytes(unicodeString, 21, 0),ArgumentOutOfRangeException);
      EXPECT_THROW(encoding->GetBytes(unicodeString, 22, 0),ArgumentOutOfRangeException);

      EXPECT_THROW(encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 20, 1), ArgumentOutOfRangeException);
      ExpectBytes(encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 9, 1),charBytes);
      ExpectBytes(encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 3, 1),piBytes);
      ExpectBytes(encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 19, 1),koalaBytes);

      Bytes bytes(encoding->GetByteCount(unicodeChars.Data, unicodeChars.Count, 0, 0));
      EXPECT_EQ(0, encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 0, (byte*)bytes.Data(), bytes.Length, 0));

      bytes = Bytes(10 * charByteSize);
      EXPECT_EQ(0, encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 0, (byte*)bytes.Data(), bytes.Length, 0)); // ".........."
      EXPECT_EQ(charByteSize*3, encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 3, (byte*)bytes.Data(), bytes.Length, 0)); // "Pi ......."
      EXPECT_EQ(charByteSize*3, encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 3, (byte*)bytes.Data(), bytes.Length, 3*charByteSize)); // "Pi Pi ...."
      EXPECT_EQ(charByteSize*3, encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 3, (byte*)bytes.Data(), bytes.Length, 6*charByteSize)); // "Pi Pi Pi ."
      EXPECT_EQ(charByteSize, encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 1, (byte*)bytes.Data(), bytes.Length, 9*charByteSize)); // "Pi Pi Pi P"

      Array<string> splits = unicodeBytes.Split(',');
      for (string& s : splits)
        s = s.TrimStart(' ');
      string Pi_ = string::Join(", ", splits, 0, 3 * charByteSize);
      ExpectBytes(bytes, Pi_ + ", " + Pi_ + ", " + Pi_ + ", " + string::Join(", ", splits, 0,charByteSize));

      EXPECT_THROW(encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 3, (byte*)bytes.Data(), bytes.Length, 9*charByteSize), ArgumentException);

      EXPECT_EQ(0, encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 0, (byte*)bytes.Data(), bytes.Length, bytes.Length-1));
      EXPECT_EQ(0,encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 0, (byte*)bytes.Data(), bytes.Length, bytes.Length));
      EXPECT_THROW(encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 0, (byte*)bytes.Data(), bytes.Length, bytes.Length+1),ArgumentException);

      bytes = Bytes(encoding->GetByteCount(unicodeChars.Data, unicodeChars.Count, 0, 3));
      EXPECT_EQ(3 * charByteSize, encoding->GetBytes(unicodeChars.Data, unicodeChars.Count, 0, 3, (byte*)bytes.Data(), bytes.Length, 0));

      bytes = Bytes(10 * charByteSize);
      EXPECT_EQ(0, encoding->GetBytes(unicodeString, 0, 0, (byte*)bytes.Data(), bytes.Length, 0)); // ".........."
      EXPECT_EQ(charByteSize*3, encoding->GetBytes(unicodeString, 0, 3, (byte*)bytes.Data(), bytes.Length, 0)); // "Pi ......."
      EXPECT_EQ(charByteSize*3, encoding->GetBytes(unicodeString, 0, 3, (byte*)bytes.Data(), bytes.Length, 3*charByteSize)); // "Pi Pi ...."
      EXPECT_EQ(charByteSize*3, encoding->GetBytes(unicodeString, 0, 3, (byte*)bytes.Data(), bytes.Length, 6*charByteSize)); // "Pi Pi Pi ."
      EXPECT_EQ(charByteSize, encoding->GetBytes(unicodeString, 0, 1, (byte*)bytes.Data(), bytes.Length, 9*charByteSize)); // "Pi Pi Pi P"

      ExpectBytes(bytes, Pi_ + ", " + Pi_ + ", " + Pi_ + ", " + string::Join(", ", splits, 0,charByteSize));

      EXPECT_THROW(encoding->GetBytes(unicodeString, 0, 3, (byte*)bytes.Data(), bytes.Length, 9*charByteSize), ArgumentException);

      EXPECT_EQ(0, encoding->GetBytes(unicodeString, 0, 0, (byte*)bytes.Data(), bytes.Length, bytes.Length-1));
      EXPECT_EQ(0, encoding->GetBytes(unicodeString, 0, 0, (byte*)bytes.Data(), bytes.Length, bytes.Length));
      EXPECT_THROW(encoding->GetBytes(unicodeString, 0, 0, (byte*)bytes.Data(), bytes.Length, bytes.Length+1),ArgumentOutOfRangeException);

      bytes = Bytes(piByteSize);
      EXPECT_EQ(piByteSize, encoding->GetBytes(unicodeString, 3, 1, (byte*)bytes.Data(), bytes.Length, 0));
      ExpectBytes(bytes, piBytes);
      bytes = Bytes(sigmaByteSize);
      EXPECT_EQ(sigmaByteSize, encoding->GetBytes(unicodeString, 11, 1, (byte*)bytes.Data(), bytes.Length, 0));
      bytes = Bytes(koalaByteSize);
      EXPECT_EQ(koalaByteSize, encoding->GetBytes(unicodeString, 19, 1, (byte*)bytes.Data(), bytes.Length, 0));
      ExpectBytes(bytes, koalaBytes);
  }
  /*
  void GetCharCountTest(Encoding& encoding, int charByteSize, int piByteSize, int sigmaByteSize, int koalaByteSize, byte unicodeBytes[], int32 size) {
  // 3          pi           7          si          7            ko
  // "Pi " + Char(928) + " Sigma " + Char(931) + " KOALA " + Char(128040);
  Bytes emptyBytes;
  EXPECT_EQ(0, encoding.GetCharCount(null, 0, 0, 0));
  EXPECT_THROW(encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
  EXPECT_THROW(encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
  EXPECT_EQ(0, encoding.GetCharCount(null, 0));
  EXPECT_THROW(encoding.GetCharCount(null, 1), ArgumentNullException);
  EXPECT_EQ(0, encoding.GetCharCount(unicodeBytes, size,0,0));
  EXPECT_EQ(0, encoding.GetCharCount(unicodeBytes, size,1,0));
  EXPECT_EQ(0, encoding.GetCharCount(unicodeBytes, size,2,0));
  EXPECT_EQ(0, encoding.GetCharCount(unicodeBytes, size,3,0));
  EXPECT_EQ(0, encoding.GetCharCount(unicodeBytes, size,size-1,0));
  EXPECT_EQ(0, encoding.GetCharCount(unicodeBytes, size,size,0));
  EXPECT_THROW(encoding.GetCharCount(unicodeBytes, size,size+1,0), ArgumentOutOfRangeException);

  EXPECT_EQ(3,encoding.GetCharCount(unicodeBytes, size, 0, charByteSize * 3));
  EXPECT_EQ(1,encoding.GetCharCount(unicodeBytes, size, charByteSize * 3, piByteSize));
  EXPECT_EQ(1,encoding.GetCharCount(unicodeBytes, size, charByteSize * 17 + piByteSize + sigmaByteSize, koalaByteSize));

  EXPECT_THROW(encoding.GetCharCount(unicodeBytes, size, charByteSize * 17 + piByteSize + sigmaByteSize, koalaByteSize+1), ArgumentOutOfRangeException);
  }*/
  /*
  void GetCharsTest(const Encoding& encoding, int charByteSize, int piByteSize, int sigmaByteSize, int koalaByteSize, 
  UpBytes unicodeBytes, const Bytes& charBytes, const Bytes& piBytes, const Bytes& koalaBytes) {
  Bytes* null_bytes = null;
  Chars* null_chars = null;
  UpChars chars;
  UpBytes bytes;

  string charString = "a";
  string piString;
  string koalaString;
  if (encoding->GetCodePage() == 20127) { // if ascii
  piString = "?";
  koalaString = "?";
  } else {
  piString = Char(928).ToString();
  koalaString = Char(128040).ToString();
  }

  //encoding->GetChars(bytes);
  EXPECT_THROW(encoding->GetChars(null, 1),ArgumentNullException);
  chars = encoding->GetChars(charBytes);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(charString));
  chars = encoding->GetChars(piBytes);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(piString));
  chars = encoding->GetChars(koalaBytes);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(koalaString));

  //encoding->GetChars(bytes,0,0);
  EXPECT_THROW(encoding->GetChars(*null_bytes,0,0),ArgumentNullException);
  chars = encoding->GetChars(charBytes,charByteSize,0);
  EXPECT_EQ(0, chars->Length);
  chars = encoding->GetChars(piBytes,piByteSize,0);
  EXPECT_EQ(0, chars->Length);
  chars = encoding->GetChars(koalaBytes,koalaByteSize,0);
  EXPECT_EQ(0, chars->Length);    
  EXPECT_THROW(encoding->GetChars(charBytes,charByteSize+1,0),ArgumentOutOfRangeException);
  chars = encoding->GetChars(charBytes,0,charByteSize);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(charString));
  chars = encoding->GetChars(piBytes,0,piByteSize);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(piString));
  chars = encoding->GetChars(koalaBytes,0,koalaByteSize);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(koalaString));
  chars = encoding->GetChars(*unicodeBytes,0, 3 * charByteSize);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals("Pi "));
  chars = encoding->GetChars(*unicodeBytes,3 * charByteSize, piByteSize);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(piString));
  chars = encoding->GetChars(*unicodeBytes,17 * charByteSize + piByteSize + sigmaByteSize, koalaByteSize);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(koalaString));
  chars = encoding->GetChars(*unicodeBytes,10 * charByteSize + piByteSize + sigmaByteSize, 7 * charByteSize + koalaByteSize);
  EXPECT_TRUE(string(chars().GetData(), chars().Length).Equals(" KOALA " + koalaString));

  //encoding->GetChars(bytes,0,0,chars,0);
  chars = new Chars(10);
  bytes = new Bytes(10);
  EXPECT_THROW(encoding->GetChars(*null_bytes,0,0,*chars,0),ArgumentNullException);
  EXPECT_THROW(encoding->GetChars(*null_bytes,0,0,*null_chars,0),ArgumentNullException);
  EXPECT_THROW(encoding->GetChars(*bytes,0,0,*null_chars,0),ArgumentNullException); 
  }
  */
  void ConvertTest(const Encoding& srcEncoding, const Encoding& dstEncoding, const byte bytes[], int32 size, const string& reference) {
    Bytes newBytes = Encoding::Convert(srcEncoding,dstEncoding, bytes, size);
    String decoded = dstEncoding.GetString(newBytes.Data, newBytes.Length);
    EXPECT_EQ(reference, decoded);
  }

  TEST(Encoding, ConvertPi) {
    string asciiString = "?";
    string unicodeString = String::Format("{u03A0}");

    byte unicodeBytesASCII[1] = { 63 };
    byte unicodeBytesUTF8[2] = { 206, 160 };
    byte unicodeBytesUTF16[2] = { 160, 3 };
    byte unicodeBytesUTF16BE[2] = { 3, 160 };
    byte unicodeBytesUTF32[4] = { 160, 3, 0, 0 };
    byte unicodeBytesUTF32BE[4] = { 0, 0, 3, 160 };

    ASCIIEncoding ascii;
    UTF8Encoding utf8;
    UnicodeEncoding utf16;
    UnicodeEncoding utf16be(true);
    UTF32Encoding utf32;
    UTF32Encoding utf32be(true);

    ConvertTest(ascii, ascii, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf8, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf16, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf16be, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf32, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf32be, unicodeBytesASCII, 1, asciiString);

    ConvertTest(utf8, ascii, unicodeBytesUTF8, 2, asciiString);
    ConvertTest(utf8, utf8, unicodeBytesUTF8, 2, unicodeString);
    ConvertTest(utf8, utf16, unicodeBytesUTF8, 2, unicodeString);
    ConvertTest(utf8, utf16be, unicodeBytesUTF8, 2, unicodeString);
    ConvertTest(utf8, utf32, unicodeBytesUTF8, 2, unicodeString);
    ConvertTest(utf8, utf32be, unicodeBytesUTF8, 2, unicodeString);

    ConvertTest(utf16, ascii, unicodeBytesUTF16, 2, asciiString);
    ConvertTest(utf16, utf8, unicodeBytesUTF16, 2, unicodeString);
    ConvertTest(utf16, utf16, unicodeBytesUTF16, 2, unicodeString);
    ConvertTest(utf16, utf16be, unicodeBytesUTF16, 2, unicodeString);
    ConvertTest(utf16, utf32, unicodeBytesUTF16, 2, unicodeString);
    ConvertTest(utf16, utf32be, unicodeBytesUTF16, 2, unicodeString);

    ConvertTest(utf16be, ascii, unicodeBytesUTF16BE, 2, asciiString);
    ConvertTest(utf16be, utf8, unicodeBytesUTF16BE, 2, unicodeString);
    ConvertTest(utf16be, utf16, unicodeBytesUTF16BE, 2, unicodeString);
    ConvertTest(utf16be, utf16be, unicodeBytesUTF16BE, 2, unicodeString);
    ConvertTest(utf16be, utf32, unicodeBytesUTF16BE, 2, unicodeString);
    ConvertTest(utf16be, utf32be, unicodeBytesUTF16BE, 2, unicodeString);

    ConvertTest(utf32, ascii, unicodeBytesUTF32, 4, asciiString);
    ConvertTest(utf32, utf8, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf16, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf16be, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf32, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf32be, unicodeBytesUTF32, 4, unicodeString);

    ConvertTest(utf32be, ascii, unicodeBytesUTF32BE, 4, asciiString);
    ConvertTest(utf32be, utf8, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf16, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf16be, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf32, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf32be, unicodeBytesUTF32BE, 4, unicodeString);
  }

  TEST(Encoding, ConvertSigma) {
    string asciiString = "?";
    string unicodeString = String::Format("{u03A3}");

    byte unicodeBytesASCII[1] = { 63 };
    byte unicodeBytesUTF8[2] = { 0xCE, 0xA3 };
    byte unicodeBytesUTF16[2] = { 163, 3 };
    byte unicodeBytesUTF16BE[2] = { 3, 163 };
    byte unicodeBytesUTF32[4] = { 163, 3, 0, 0 };
    byte unicodeBytesUTF32BE[4] = { 0, 0, 3, 163 };

    ASCIIEncoding ascii;
    UTF8Encoding utf8;
    UnicodeEncoding utf16;
    UnicodeEncoding utf16be(true);
    UTF32Encoding utf32;
    UTF32Encoding utf32be(true);

    ConvertTest(ascii, ascii, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf8, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf16, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf16be, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf32, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf32be, unicodeBytesASCII, 1, asciiString);

    ConvertTest(utf8, ascii, unicodeBytesUTF8, 2, asciiString);
    ConvertTest(utf8, utf8, unicodeBytesUTF8, 2, unicodeString);
    ConvertTest(utf8, utf16, unicodeBytesUTF8, 2, unicodeString);
    ConvertTest(utf8, utf16be, unicodeBytesUTF8, 2, unicodeString);
    ConvertTest(utf8, utf32, unicodeBytesUTF8, 2, unicodeString);
    ConvertTest(utf8, utf32be, unicodeBytesUTF8, 2, unicodeString);

    ConvertTest(utf16, ascii, unicodeBytesUTF16, 2, asciiString);
    ConvertTest(utf16, utf8, unicodeBytesUTF16, 2, unicodeString);
    ConvertTest(utf16, utf16, unicodeBytesUTF16, 2, unicodeString);
    ConvertTest(utf16, utf16be, unicodeBytesUTF16, 2, unicodeString);
    ConvertTest(utf16, utf32, unicodeBytesUTF16, 2, unicodeString);
    ConvertTest(utf16, utf32be, unicodeBytesUTF16, 2, unicodeString);

    ConvertTest(utf16be, ascii, unicodeBytesUTF16BE, 2, asciiString);
    ConvertTest(utf16be, utf8, unicodeBytesUTF16BE, 2, unicodeString);
    ConvertTest(utf16be, utf16, unicodeBytesUTF16BE, 2, unicodeString);
    ConvertTest(utf16be, utf16be, unicodeBytesUTF16BE, 2, unicodeString);
    ConvertTest(utf16be, utf32, unicodeBytesUTF16BE, 2, unicodeString);
    ConvertTest(utf16be, utf32be, unicodeBytesUTF16BE, 2, unicodeString);

    ConvertTest(utf32, ascii, unicodeBytesUTF32, 4, asciiString);
    ConvertTest(utf32, utf8, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf16, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf16be, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf32, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf32be, unicodeBytesUTF32, 4, unicodeString);

    ConvertTest(utf32be, ascii, unicodeBytesUTF32BE, 4, asciiString);
    ConvertTest(utf32be, utf8, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf16, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf16be, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf32, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf32be, unicodeBytesUTF32BE, 4, unicodeString);
  }

  TEST(Encoding, ConvertKoala) {
    string asciiString = "?";
    string unicodeString = String::Format("{u1F428}");

    byte unicodeBytesASCII[1] = { 63 };
    byte unicodeBytesUTF8[4] = { 0xF0, 0x9F, 0x90, 0xA8 };
    byte unicodeBytesUTF16[4] = { 0x3D, 0xD8, 0x28, 0xDC };
    byte unicodeBytesUTF16BE[4] = { 0xD8, 0x3D, 0xDC, 0x28 };
    byte unicodeBytesUTF32[4] = { 0x28, 0xF4, 0x01, 0x00 };
    byte unicodeBytesUTF32BE[4] = { 0x00, 0x01, 0xF4, 0x28 };

    ASCIIEncoding ascii;
    UTF8Encoding utf8;
    UnicodeEncoding utf16;
    UnicodeEncoding utf16be(true);
    UTF32Encoding utf32;
    UTF32Encoding utf32be(true);

    ConvertTest(ascii, ascii, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf8, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf16, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf16be, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf32, unicodeBytesASCII, 1, asciiString);
    ConvertTest(ascii, utf32be, unicodeBytesASCII, 1, asciiString);

    ConvertTest(utf8, ascii, unicodeBytesUTF8, 4, asciiString);
    ConvertTest(utf8, utf8, unicodeBytesUTF8, 4, unicodeString);
    ConvertTest(utf8, utf16, unicodeBytesUTF8, 4, unicodeString);
    ConvertTest(utf8, utf16be, unicodeBytesUTF8, 4, unicodeString);
    ConvertTest(utf8, utf32, unicodeBytesUTF8, 4, unicodeString);
    ConvertTest(utf8, utf32be, unicodeBytesUTF8, 4, unicodeString);

    ConvertTest(utf16, ascii, unicodeBytesUTF16, 4, asciiString);
    ConvertTest(utf16, utf8, unicodeBytesUTF16, 4, unicodeString);
    ConvertTest(utf16, utf16, unicodeBytesUTF16, 4, unicodeString);
    ConvertTest(utf16, utf16be, unicodeBytesUTF16, 4, unicodeString);
    ConvertTest(utf16, utf32, unicodeBytesUTF16, 4, unicodeString);
    ConvertTest(utf16, utf32be, unicodeBytesUTF16, 4, unicodeString);

    ConvertTest(utf16be, ascii, unicodeBytesUTF16BE, 4, asciiString);
    ConvertTest(utf16be, utf8, unicodeBytesUTF16BE, 4, unicodeString);
    ConvertTest(utf16be, utf16, unicodeBytesUTF16BE, 4, unicodeString);
    ConvertTest(utf16be, utf16be, unicodeBytesUTF16BE, 4, unicodeString);
    ConvertTest(utf16be, utf32, unicodeBytesUTF16BE, 4, unicodeString);
    ConvertTest(utf16be, utf32be, unicodeBytesUTF16BE, 4, unicodeString);

    ConvertTest(utf32, ascii, unicodeBytesUTF32, 4, asciiString);
    ConvertTest(utf32, utf8, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf16, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf16be, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf32, unicodeBytesUTF32, 4, unicodeString);
    ConvertTest(utf32, utf32be, unicodeBytesUTF32, 4, unicodeString);

    ConvertTest(utf32be, ascii, unicodeBytesUTF32BE, 4, asciiString);
    ConvertTest(utf32be, utf8, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf16, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf16be, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf32, unicodeBytesUTF32BE, 4, unicodeString);
    ConvertTest(utf32be, utf32be, unicodeBytesUTF32BE, 4, unicodeString);
  }

  TEST(Encoding, Convert) {
    // "Pi " + Char(928) + " Sigma " + Char(931) + " KOALA " + Char(128040);
    string asciiString = "Pi ? Sigma ? KOALA ?";
    string unicodeString = String::Format("Pi {u03A0} Sigma {u03A3} KOALA {u1F428}");

    byte unicodeBytesASCII[20] = {80, 105, 32, 63, 32, 83, 105, 103, 109, 97, 32, 
      63, 32, 75, 79, 65, 76, 65, 32, 63 };

    byte unicodeBytesUTF8[25] = { 80, 105, 32, /*{u03A0}*/ 206, 160, /**/ 
      32, 83, 105, 103, 109, 97, 32,  /*{u03A3}*/206, 163, /**/
      32, 75, 79, 65, 76, 65, 32, /*{u1F428}*/ 0xF0, 0x9F, 0x90, 0xA8 /**/};

    byte unicodeBytesUTF16[42] = {80, 0, 105, 0, 32, 0, 160, 3, 32, 0, 83, 0, 105,
      0, 103, 0, 109, 0, 97, 0, 32, 0, 163, 3, 32, 0, 75, 0, 79, 0, 65, 0, 76, 0,
      65, 0, 32, 0, 61, 216, 40, 220 };

    byte unicodeBytesUTF16BE[42] = { 0, 80, 0, 105, 0, 32, 3, 160, 0, 32, 0, 83, 0,
      105, 0, 103, 0, 109, 0, 97, 0, 32, 3, 163, 0, 32, 0, 75, 0, 79, 0, 65, 0, 
      76, 0, 65, 0, 32, 216, 61, 220, 40 };

    byte unicodeBytesUTF32[80] = { 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 0, 160, 3, 
      0, 0, 32, 0, 0, 0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0, 
      97, 0, 0, 0, 32, 0, 0, 0, 163, 3, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0, 79, 0, 0,
      0, 65, 0, 0, 0, 76, 0, 0, 0, 65, 0, 0, 0, 32, 0, 0, 0, 40, 244, 1, 0 };

    byte unicodeBytesUTF32BE[80] = { 0, 0, 0, 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 
      3, 160, 0, 0, 0, 32, 0, 0, 0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109,
      0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 3, 163, 0, 0, 0, 32, 0, 0, 0, 75, 0, 0, 0,
      79, 0, 0, 0, 65, 0, 0, 0, 76, 0, 0, 0, 65, 0, 0, 0, 32, 0, 1, 244, 40 };

    ASCIIEncoding ascii;
    UTF8Encoding utf8;
    UnicodeEncoding utf16;
    UnicodeEncoding utf16be(true);
    UTF32Encoding utf32;
    UTF32Encoding utf32be(true);

    ConvertTest(ascii, ascii, unicodeBytesASCII, 20, asciiString);
    ConvertTest(ascii, utf8, unicodeBytesASCII, 20, asciiString);
    ConvertTest(ascii, utf16, unicodeBytesASCII, 20, asciiString);
    ConvertTest(ascii, utf16be, unicodeBytesASCII, 20, asciiString);
    ConvertTest(ascii, utf32, unicodeBytesASCII, 20, asciiString);
    ConvertTest(ascii, utf32be, unicodeBytesASCII, 20, asciiString);

    ConvertTest(utf8, ascii, unicodeBytesUTF8, 25, asciiString);
    ConvertTest(utf8, utf8, unicodeBytesUTF8, 25, unicodeString);
    ConvertTest(utf8, utf16, unicodeBytesUTF8, 25, unicodeString);
    ConvertTest(utf8, utf16be, unicodeBytesUTF8, 25, unicodeString);
    ConvertTest(utf8, utf32, unicodeBytesUTF8, 25, unicodeString);
    ConvertTest(utf8, utf32be, unicodeBytesUTF8, 25, unicodeString);

    ConvertTest(utf16, ascii, unicodeBytesUTF16, 42, asciiString);
    ConvertTest(utf16, utf8, unicodeBytesUTF16, 42, unicodeString);
    ConvertTest(utf16, utf16, unicodeBytesUTF16, 42, unicodeString);
    ConvertTest(utf16, utf16be, unicodeBytesUTF16, 42, unicodeString);
    ConvertTest(utf16, utf32, unicodeBytesUTF16, 42, unicodeString);
    ConvertTest(utf16, utf32be, unicodeBytesUTF16, 42, unicodeString);

    ConvertTest(utf16be, ascii, unicodeBytesUTF16BE, 42, asciiString);
    ConvertTest(utf16be, utf8, unicodeBytesUTF16BE, 42, unicodeString);
    ConvertTest(utf16be, utf16, unicodeBytesUTF16BE, 42, unicodeString);
    ConvertTest(utf16be, utf16be, unicodeBytesUTF16BE, 42, unicodeString);
    ConvertTest(utf16be, utf32, unicodeBytesUTF16BE, 42, unicodeString);
    ConvertTest(utf16be, utf32be, unicodeBytesUTF16BE, 42, unicodeString);

    ConvertTest(utf32, ascii, unicodeBytesUTF32, 80, asciiString);
    ConvertTest(utf32, utf8, unicodeBytesUTF32, 80, unicodeString);
    ConvertTest(utf32, utf16, unicodeBytesUTF32, 80, unicodeString);
    ConvertTest(utf32, utf16be, unicodeBytesUTF32, 80, unicodeString);
    ConvertTest(utf32, utf32, unicodeBytesUTF32, 80, unicodeString);
    ConvertTest(utf32, utf32be, unicodeBytesUTF32, 80, unicodeString);

    ConvertTest(utf32be, ascii, unicodeBytesUTF32BE, 80, asciiString);
    ConvertTest(utf32be, utf8, unicodeBytesUTF32BE, 80, unicodeString);
    ConvertTest(utf32be, utf16, unicodeBytesUTF32BE, 80, unicodeString);
    ConvertTest(utf32be, utf16be, unicodeBytesUTF32BE, 80, unicodeString);
    ConvertTest(utf32be, utf32, unicodeBytesUTF32BE, 80, unicodeString);
    ConvertTest(utf32be, utf32be, unicodeBytesUTF32BE, 80, unicodeString);
  }

  TEST(Encoding, CodePage437) {
    byte cp437Data[54] = {  0xDA, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xBF, 10, 
      0xB3, 0x20, 0xDA, 0xC4, 0xC4, 0xC4, 0xC4, 0xBF, 0x20, 0xB3, 10, 
      0xB3, 0x20, 0xB3, 0x20, 0x4F, 0x4B, 0x20, 0xB3, 0x20, 0xB3, 10, 
      0xB3, 0x20, 0xC0, 0xC4, 0xC4, 0xC4, 0xC4, 0xD9, 0x20, 0xB3, 10, 
      0xC0, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xD9 };

    string rawDataString = string() + Char(0x250C) + string(Char(0x2500),8) + Char(0x2510) + Char(10) +
      Char(0x2502) + Char(32) + Char(0x250C) + string(Char(0x2500),4) + Char(0x2510) + Char(32) + Char(0x2502) + Char(10) +
      Char(0x2502) + Char(32) + Char(0x2502) + " OK "                 + Char(0x2502) + Char(32) + Char(0x2502) + Char(10) +
      Char(0x2502) + Char(32) + Char(0x2514) + string(Char(0x2500),4) + Char(0x2518) + Char(32) + Char(0x2502) + Char(10) +
      Char(0x2514) + string(Char(0x2500),8)                                                     + Char(0x2518);


    CodePage437Encoding encoding;
    Chars chars = encoding.GetChars(cp437Data, 54);
    string decodedString(chars.Data, chars.Length);
    Bytes codedBytes = encoding.GetBytes(chars.Data, chars.Length);

    EXPECT_EQ(54, codedBytes.Length);

    EXPECT_EQ(rawDataString, decodedString);
    //Console::WriteLine(rawDataString);
  }

}
