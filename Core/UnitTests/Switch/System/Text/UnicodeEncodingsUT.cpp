#include "EncodingUT.hpp"
#include <Switch/System/Text/ANSIEncoding.hpp>
#include <Switch/System/Text/ASCIIEncoding.hpp>
#include <Switch/System/Text/UnicodeEncoding.hpp>
#include <Switch/System/Text/UTF8Encoding.hpp>
#include <Switch/System/Text/UTF32Encoding.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {
  struct EncodingTypeData {
    Array<byte> aBytes;
    Array<byte> aeBytes;
    Array<byte> specialTBytes;
    Array<byte> sigmaBytes;
    Array<byte> syriacSemkathBytes;
    Array<byte> fullBlockBytes;
    Array<byte> cjkBytes;
    Array<byte> koalaBytes;
    
    int32 maxByteSize;
    int32 minByteSize;
    String encodingName;
    int32 codePage;
    bool isSingleByte;
  };
  
  template<typename UnicodeEncodingTest>
  class Encoding : public ::testing::Test, public UnicodeEncodingTest {
  public:
    Encoding() : UnicodeEncodingTest() { }
    ~Encoding() { }
    
    void SetUp() override {
      charA = EncodingUT::UnicodeCharacter(0x61, UnicodeEncodingTest::aBytes.Data, UnicodeEncodingTest::aBytes.Length);
      charAE = EncodingUT::UnicodeCharacter(0xE6, UnicodeEncodingTest::aeBytes.Data, UnicodeEncodingTest::aeBytes.Length);
      charSpecialT = EncodingUT::UnicodeCharacter(0x163, UnicodeEncodingTest::specialTBytes.Data, UnicodeEncodingTest::specialTBytes.Length);
      sigma = EncodingUT::UnicodeCharacter(0x3A3, UnicodeEncodingTest::sigmaBytes.Data, UnicodeEncodingTest::sigmaBytes.Length);
      syriacSemkath = EncodingUT::UnicodeCharacter(0x723, UnicodeEncodingTest::syriacSemkathBytes.Data, UnicodeEncodingTest::syriacSemkathBytes.Length);
      fullBlock = EncodingUT::UnicodeCharacter(0x2588, UnicodeEncodingTest::fullBlockBytes.Data, UnicodeEncodingTest::fullBlockBytes.Length);
      cjk = EncodingUT::UnicodeCharacter(0x597B, UnicodeEncodingTest::cjkBytes.Data, UnicodeEncodingTest::cjkBytes.Length);
      koala = EncodingUT::UnicodeCharacter(0x1F428, UnicodeEncodingTest::koalaBytes.Data, UnicodeEncodingTest::koalaBytes.Length);
    }
    
    void TearDown() override { }
    
  public:
    EncodingUT::UnicodeCharacter charA;
    EncodingUT::UnicodeCharacter charAE;
    EncodingUT::UnicodeCharacter charSpecialT;
    EncodingUT::UnicodeCharacter sigma;
    EncodingUT::UnicodeCharacter syriacSemkath;
    EncodingUT::UnicodeCharacter fullBlock;
    EncodingUT::UnicodeCharacter cjk;
    EncodingUT::UnicodeCharacter koala;
  };
  
  class CodePage437Type : public EncodingTypeData {
  public:
    CodePage437Type() {
      isSingleByte = true;
      codePage = 437;
      encodingName = "IBM437";
      maxByteSize = 1;
      minByteSize = 1;
      
      aBytes = {0x61};
      aeBytes = {0x91};
      specialTBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      sigmaBytes = {0xE4};
      syriacSemkathBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      fullBlockBytes = {0xDB};
      cjkBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      koalaBytes = {Convert::ToByte(Text::Encoding::Unknown())};
    }
    
    Text::CodePage437Encoding encoding;
  };
  
  class CodePage28591Type : public EncodingTypeData {
  public:
    CodePage28591Type() {
      isSingleByte = true;
      codePage = 28591;
      encodingName = "iso-8859-1";
      maxByteSize = 1;
      minByteSize = 1;
      
      aBytes = {0x61};
      aeBytes = {0xE6};
      specialTBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      sigmaBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      syriacSemkathBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      fullBlockBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      cjkBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      koalaBytes = {Convert::ToByte(Text::Encoding::Unknown())};
    }
    
    Text::CodePage28591Encoding encoding;
  };
  
  class CodePage28592Type : public EncodingTypeData {
  public:
    CodePage28592Type() {
      isSingleByte = true;
      codePage = 28592;
      encodingName = "iso-8859-2";
      maxByteSize = 1;
      minByteSize = 1;
      
      aBytes = {0x61};
      aeBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      specialTBytes = {0xFE};
      sigmaBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      syriacSemkathBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      fullBlockBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      cjkBytes = {Convert::ToByte(Text::Encoding::Unknown())};
      koalaBytes = {Convert::ToByte(Text::Encoding::Unknown())};
    }
    
    Text::CodePage28592Encoding encoding;
  };
  
  class UTF8Type : public EncodingTypeData {
  public:
    UTF8Type() {
      isSingleByte = false;
      codePage = 65001;
      encodingName = "utf-8";
      maxByteSize = 4;
      minByteSize = 1;
      
      aBytes = {0x61};
      aeBytes = {0xC3, 0xA6};
      specialTBytes = {0xC5, 0xA3};
      sigmaBytes = {0xCE, 0xA3};
      syriacSemkathBytes = {0xDC, 0xA3};
      fullBlockBytes = {0xE2, 0x96, 0x88};
      cjkBytes = {0xE5, 0xA5, 0xBB};
      koalaBytes = {0xF0, 0x9F, 0x90, 0xA8};
    }
    
    Text::UTF8Encoding encoding;
  };
  
  class UTF16LEType : public EncodingTypeData {
  public:
    UTF16LEType() : encoding(false) {
      isSingleByte = false;
      codePage = 1200;
      encodingName = "utf-16";
      maxByteSize = 4;
      minByteSize = 2;
      
      aBytes = {0x61, 0};
      aeBytes = {0xE6, 0};
      specialTBytes = {0x63, 0x1};
      sigmaBytes = {0xA3, 0x3};
      syriacSemkathBytes = {0x23, 0x7};
      fullBlockBytes = {0x88, 0x25};
      cjkBytes = {0x7B, 0x59};
      koalaBytes = {0x3D, 0xD8, 0x28, 0xDC};
    }
    
    Text::UnicodeEncoding encoding;
  };
  
  class UTF16BEType : public EncodingTypeData {
  public:
    UTF16BEType() : encoding(true) {
      isSingleByte = false;
      codePage = 1201;
      encodingName = "unicodeFFFE";
      maxByteSize = 4;
      minByteSize = 2;
      
      aBytes = {0, 0x61};
      aeBytes = {0, 0xE6};
      specialTBytes = {0x1, 0x63};
      sigmaBytes = {0x3, 0xA3};
      syriacSemkathBytes = {0x7, 0x23};
      fullBlockBytes = {0x25, 0x88};
      cjkBytes = {0x59, 0x7B};
      koalaBytes = {0xD8, 0x3D, 0xDC, 0x28};
    }
    
    Text::UnicodeEncoding encoding;
  };
  
  class UTF32LEType : public EncodingTypeData {
  public:
    UTF32LEType() : encoding(false) {
      isSingleByte = false;
      codePage = 12000;
      encodingName = "utf-32";
      maxByteSize = 4;
      minByteSize = 4;
      
      aBytes = {0x61, 0, 0, 0};
      aeBytes = {0xE6, 0, 0, 0};
      specialTBytes = {0x63, 0x1, 0, 0};
      sigmaBytes = {0xA3, 0x3, 0, 0};
      syriacSemkathBytes = {0x23, 0x7, 0, 0};
      fullBlockBytes = {0x88, 0x25, 0, 0};
      cjkBytes = {0x7B, 0x59, 0, 0};
      koalaBytes = {0x28, 0xF4, 0x1, 0};
    }
    
    Text::UTF32Encoding encoding;
  };
  
  class UTF32BEType : public EncodingTypeData {
  public:
    UTF32BEType() : encoding(true) {
      isSingleByte = false;
      codePage = 12001;
      encodingName = "utf-32BE";
      maxByteSize = 4;
      minByteSize = 4;
      
      aBytes = {0, 0, 0, 0x61};
      aeBytes = {0, 0, 0, 0xE6};
      specialTBytes = {0, 0, 0x1, 0x63};
      sigmaBytes = {0, 0, 0x3, 0xA3};
      syriacSemkathBytes = {0, 0, 0x7, 0x23};
      fullBlockBytes = {0, 0, 0x25, 0x88};
      cjkBytes = {0, 0, 0x59, 0x7B};
      koalaBytes = {0, 0x1, 0xF4, 0x28};
    }
    
    Text::UTF32Encoding encoding;
  };
  
  using TestedCodePages = ::testing::Types<CodePage437Type, CodePage28591Type, CodePage28592Type, UTF8Type, UTF16LEType, UTF16BEType, UTF32LEType, UTF32BEType>;
  
  TYPED_TEST_CASE(Encoding, TestedCodePages);
  
  //___________________________________________________________________________
  //                                    virtual Array<byte> GetPreamble() const
  
  TEST(EncodingTest, GetPreamble___CodePage437) {
    Text::CodePage437Encoding encoding;
    EXPECT_EQ(0, encoding.GetPreamble().Length);
  }
  
  TEST(EncodingTest, GetPreamble___CodePage28591) {
    Text::CodePage28591Encoding encoding;
    EXPECT_EQ(0, encoding.GetPreamble().Length);
  }
  
  TEST(EncodingTest, GetPreamble___CodePage28592) {
    Text::CodePage28592Encoding encoding;
    EXPECT_EQ(0, encoding.GetPreamble().Length);
  }
  
  TEST(EncodingTest, GetPreamble___UTF8) {
    Text::UTF8Encoding encoding;
    EXPECT_EQ(0, encoding.GetPreamble().Length);
  }
  
  TEST(EncodingTest, GetPreamble___UTF8_BOM) {
    Text::UTF8Encoding encoding(true);
    Array<byte> bom = encoding.GetPreamble();
    ASSERT_EQ(3, bom.Length);
    EXPECT_EQ(0xEF, bom[0]);
    EXPECT_EQ(0xBB, bom[1]);
    EXPECT_EQ(0xBF, bom[2]);
  }
  
  TEST(EncodingTest, GetPreamble___UTF16LE) {
    Text::UnicodeEncoding encoding(false, false);
    EXPECT_EQ(0, encoding.GetPreamble().Length);
  }
  
  union BOM {
    byte bytes[2];
    uint16 value;
  };
  
  TEST(EncodingTest, GetPreamble___UTF16LE_BOM) {
    Text::UnicodeEncoding encoding;
    Array<byte> array = encoding.GetPreamble();
    ASSERT_EQ(2, array.Length);
    BOM bom; // independent from endianness of compiler
    bom.bytes[0] = array[0];
    bom.bytes[1] = array[1];
    EXPECT_EQ(0xFEFF, bom.value);
  }
  
  TEST(EncodingTest, GetPreamble___UTF16BE) {
    Text::UnicodeEncoding encoding(true, false);
    EXPECT_EQ(0, encoding.GetPreamble().Length);
  }
  
  TEST(EncodingTest, GetPreamble___UTF16BE_BOM) {
    Text::UnicodeEncoding encoding(true);
    Array<byte> array = encoding.GetPreamble();
    ASSERT_EQ(2, array.Length);
    BOM bom; // independent from endianness of compiler
    bom.bytes[0] = array[0];
    bom.bytes[1] = array[1];
    EXPECT_EQ(0xFFFE, bom.value);
  }
  
  //___________________________________________________________________________
  //                                          virtual int32 GetCodePage() const
  
  TYPED_TEST(Encoding, GetCodePage) {
    EXPECT_EQ(TypeParam::codePage, TypeParam::encoding.GetCodePage());
  }
  
  //___________________________________________________________________________
  //                                          virtual bool IsSingleByte() const
  
  TYPED_TEST(Encoding, IsSingleByte) {
    EXPECT_EQ(TypeParam::isSingleByte, TypeParam::encoding.IsSingleByte());
  }
  
  //___________________________________________________________________________
  //                                     virtual String GetEncodingName() const
  
  TYPED_TEST(Encoding, GetEncodingName) {
    EXPECT_EQ(TypeParam::encodingName, TypeParam::encoding.GetEncodingName());
  }
  
  //___________________________________________________________________________
  //                                                    bool IsReadOnly() const
  
  TYPED_TEST(Encoding, IsReadOnly) {
    EXPECT_TRUE(TypeParam::encoding.IsReadOnly());
  }
  
  //___________________________________________________________________________
  //                               virtual bool Equals(const object& obj) const
  TYPED_TEST(Encoding, Equals) {
    refptr<Text::Encoding> byCodePage = Text::Encoding::CreateEncoding(TypeParam::codePage);
    EXPECT_TRUE(TypeParam::encoding.Equals(*byCodePage));
  }
  
  //___________________________________________________________________________
  //                                            bool IsAlwaysNormalized() const
  
  TYPED_TEST(Encoding, IsAlwaysNormalized) {
    EXPECT_FALSE(TypeParam::encoding.IsAlwaysNormalized());
  }
  
  //___________________________________________________________________________
  //                                 virtual int32 GetByteCount(char32 c) const
  
  TYPED_TEST(Encoding, GetByteCount___A) {
    EXPECT_EQ(Encoding<TypeParam>::charA.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::charA.Character()));
  }
  
  TYPED_TEST(Encoding, GetByteCount___AE) {
    EXPECT_EQ(Encoding<TypeParam>::charAE.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::charAE.Character()));
  }
  
  TYPED_TEST(Encoding, GetByteCount___SpecialT) {
    EXPECT_EQ(Encoding<TypeParam>::charSpecialT.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::charSpecialT.Character()));
  }
  
  TYPED_TEST(Encoding, GetByteCount___Sigma) {
    EXPECT_EQ(Encoding<TypeParam>::sigma.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::sigma.Character()));
  }
  
  TYPED_TEST(Encoding, GetByteCount___SyriacSemkath) {
    EXPECT_EQ(Encoding<TypeParam>::syriacSemkath.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::syriacSemkath.Character()));
  }
  
  TYPED_TEST(Encoding, GetByteCount___FullBlock) {
    EXPECT_EQ(Encoding<TypeParam>::fullBlock.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::fullBlock.Character()));
  }
  
  TYPED_TEST(Encoding, GetByteCount___Cjk) {
    EXPECT_EQ(Encoding<TypeParam>::cjk.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::cjk.Character()));
  }
  
  TYPED_TEST(Encoding, GetByteCount___Koala) {
    EXPECT_EQ(Encoding<TypeParam>::koala.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::koala.Character()));
  }
  
  //___________________________________________________________________________
  //            int32 GetByteCount(const char32 chars[], int32 charsSize) const
  
  TYPED_TEST(Encoding, GetByteCount_Chars) {
    EncodingUT::UnicodeSequence sequence =
    Encoding<TypeParam>::charA +
    Encoding<TypeParam>::charAE +
    Encoding<TypeParam>::charSpecialT +
    Encoding<TypeParam>::sigma +
    Encoding<TypeParam>::syriacSemkath +
    Encoding<TypeParam>::fullBlock +
    Encoding<TypeParam>::cjk +
    Encoding<TypeParam>::koala;
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetByteCount(sequence.Chars(), sequence.Count()));
  }
  
  TYPED_TEST(Encoding, GetByteCount_Chars___Chars_Null) {
    char32* chars = null;
    EXPECT_THROW(TypeParam::encoding.GetByteCount(chars, 1), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetByteCount_Chars___Chars_Invalid) {
    char32 chars[1] = { 32 };
    EXPECT_THROW(TypeParam::encoding.GetByteCount(chars, -1), ArgumentException);
  }
  
  //___________________________________________________________________________
  // int32 GetByteCount(const char32 chars[], int32 charsSize, int32 index, int32 count) const
  
  TYPED_TEST(Encoding, GetByteCount_Chars_Index_Count) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    EXPECT_EQ(Encoding<TypeParam>::charA.Size(), TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 0, 1));
    EXPECT_EQ(Encoding<TypeParam>::charA.Size() + Encoding<TypeParam>::cjk.Size(), TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 0, 2));
    EXPECT_EQ(Encoding<TypeParam>::charA.Size() + Encoding<TypeParam>::cjk.Size() + Encoding<TypeParam>::koala.Size(), TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 0, 3));
    EXPECT_EQ(Encoding<TypeParam>::cjk.Size(), TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 1, 1));
    EXPECT_EQ(Encoding<TypeParam>::cjk.Size() + Encoding<TypeParam>::koala.Size(), TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 1, 2));
    EXPECT_EQ(Encoding<TypeParam>::koala.Size(), TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 2, 1));
  }
  
  TYPED_TEST(Encoding, GetByteCount_Chars_Index_Count___Exceptions) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    EXPECT_THROW(TypeParam::encoding.GetByteCount(sequence.Chars(), 3, -1, 1), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 0, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 0, 4), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 1, 3), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 2, 2), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetByteCount(sequence.Chars(), 3, 3, 1), ArgumentOutOfRangeException);
  }
  
  //___________________________________________________________________________
  //                                  int32 GetByteCount(const String& s) const
  
  TYPED_TEST(Encoding, GetByteCount_String) {
    EXPECT_EQ(Encoding<TypeParam>::charA.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::charA.ToString()));
    EXPECT_EQ(Encoding<TypeParam>::koala.Size(), TypeParam::encoding.GetByteCount(Encoding<TypeParam>::koala.ToString()));
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetByteCount(sequence.ToString()));
  }
  
  TYPED_TEST(Encoding, GetByteCount_String___String_Empty) {
    String empty;
    EXPECT_EQ(0, TypeParam::encoding.GetByteCount(empty));
  }
  
  //___________________________________________________________________________
  //                       virtual int32 GetMaxByteCount(int32 charCount) const
  
  TYPED_TEST(Encoding, GetMaxByteCount) {
    EXPECT_EQ(0, TypeParam::encoding.GetMaxByteCount(0));
    EXPECT_EQ(TypeParam::maxByteSize, TypeParam::encoding.GetMaxByteCount(1));
    EXPECT_EQ(TypeParam::maxByteSize*3, TypeParam::encoding.GetMaxByteCount(3));
    EXPECT_THROW(TypeParam::encoding.GetMaxByteCount(-1), ArgumentOutOfRangeException);
    
    if (TypeParam::maxByteSize > 1) {
      EXPECT_THROW(TypeParam::encoding.GetMaxByteCount((Int32::MaxValue/2)+1), ArgumentOutOfRangeException);
    }
  }
  
  //___________________________________________________________________________
  //                       virtual int32 GetMaxCharCount(int32 byteCount) const
  
  TYPED_TEST(Encoding, GetMaxCharCount) {
    EXPECT_EQ(0, TypeParam::encoding.GetMaxCharCount(0));
    EXPECT_EQ(1, TypeParam::encoding.GetMaxCharCount(TypeParam::minByteSize));
    EXPECT_EQ(3, TypeParam::encoding.GetMaxCharCount(3 * TypeParam::minByteSize));
    
    EXPECT_THROW(TypeParam::encoding.GetMaxCharCount(-1), ArgumentOutOfRangeException);
    
    if (TypeParam::minByteSize == 2) {
      EXPECT_EQ(0, TypeParam::encoding.GetMaxCharCount(1));
    }
    
    if (TypeParam::minByteSize == 4) {
      EXPECT_EQ(0, TypeParam::encoding.GetMaxCharCount(1));
      EXPECT_EQ(0, TypeParam::encoding.GetMaxCharCount(2));
      EXPECT_EQ(0, TypeParam::encoding.GetMaxCharCount(3));
    }
  }
  
  //___________________________________________________________________________
  //       int32 GetBytes(const String& s, byte bytes[], int32 bytesSize) const
  
  TYPED_TEST(Encoding, GetBytes_String_Bytes___Exact_Buffer) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    System::Array<byte> bytes(sequence.Size());
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetBytes(sequence.ToString(), (byte*)bytes.Data(), sequence.Size()));
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Bytes___Larger_Buffer) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size()+10;
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetBytes(sequence.ToString(), (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Bytes___Too_Small_Buffer) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size()-1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), (byte*)bytes.Data(), bytesSize), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Bytes___String_Empty) {
    byte bytes[10];
    String str;
    EXPECT_EQ(0, TypeParam::encoding.GetBytes(str, bytes, 10));
    
  }
  
  //_______________________________________________________________________________________________
  //     int32 GetBytes(const char32 chars[], int32 charsSize, byte bytes[], int32 bytesSize) const
  
  TYPED_TEST(Encoding, GetBytes_Chars_Bytes) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size();
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Bytes___TooSmallBuffer) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size() - 1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), (byte*)bytes.Data(), bytesSize), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Bytes___LargerBuffer) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size()+1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Bytes___NullChars) {
    byte bytes[2];
    EXPECT_THROW(TypeParam::encoding.GetBytes(null, 1, bytes, 2), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Bytes___NullBytes) {
    char32 chars[1] = { 32 };
    EXPECT_THROW(TypeParam::encoding.GetBytes(chars, 1, (byte*)null, 1), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Bytes___InvalidChars) {
    byte bytes[2];
    char32 chars[1] = { 32 };
    EXPECT_THROW(TypeParam::encoding.GetBytes(chars, -1, bytes, 2), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Bytes___InvalidBytes) {
    char32 chars[1] = { 32 };
    byte bytes[2];
    EXPECT_THROW(TypeParam::encoding.GetBytes(chars, 1, bytes, -1), ArgumentException);
  }
  
  //_______________________________________________________________________________________________
  //                             Array<byte> GetBytes(const char32 chars[], int32 charsSize) const
  
  TYPED_TEST(Encoding, GetBytes_Array) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    Array<byte> bytes = TypeParam::encoding.GetBytes(sequence.Chars(), 3);
    ASSERT_EQ(sequence.Size(), bytes.Length);
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data);
  }
  
  TYPED_TEST(Encoding, GetBytes_Array_Empty) {
    char32 chars[1];
    Array<byte> bytes = TypeParam::encoding.GetBytes(chars, 0);
    EXPECT_EQ(0, bytes.Length);
  }
  
  TYPED_TEST(Encoding, GetBytes_Array_Null) {
    EXPECT_THROW(TypeParam::encoding.GetBytes(null, 1), ArgumentNullException);
  }
  
  //___________________________________________________________________________
  //                               Array<byte> GetBytes(const String& s) const
  
  TYPED_TEST(Encoding, GetBytes_String_A) {
    EncodingUT::EXPECT_BYTES(Encoding<TypeParam>::charA.Bytes(), Encoding<TypeParam>::charA.Size(), TypeParam::encoding.GetBytes(Encoding<TypeParam>::charA.ToString()));
  }
  
  TYPED_TEST(Encoding, GetBytes_String_FullBlock) {
    EncodingUT::EXPECT_BYTES(Encoding<TypeParam>::fullBlock.Bytes(), Encoding<TypeParam>::fullBlock.Size(), TypeParam::encoding.GetBytes(Encoding<TypeParam>::fullBlock.ToString()));
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Koala) {
    EncodingUT::EXPECT_BYTES(Encoding<TypeParam>::koala.Bytes(), Encoding<TypeParam>::koala.Size(), TypeParam::encoding.GetBytes(Encoding<TypeParam>::koala.ToString()));
  }
  
  TYPED_TEST(Encoding, GetBytes_String_A_Cjk_Koala) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), TypeParam::encoding.GetBytes(sequence.ToString()));
  }
  
  TYPED_TEST(Encoding, GetBytes_String_A_AE_Sigma_FullBlock) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::sigma + Encoding<TypeParam>::fullBlock;
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), TypeParam::encoding.GetBytes(sequence.ToString()));
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Empty) {
    String s;
    EXPECT_EQ(0, TypeParam::encoding.GetBytes(s).Length);
  }
  
  //___________________________________________________________________________
  // Array<byte> GetBytes(const char32 chars[], int32 charsSize, int32 index, int32 count) const
  
  TYPED_TEST(Encoding, GetBytes_Array_Index_Count_1char32_Exceptions) {
    EXPECT_THROW(TypeParam::encoding.GetBytes(Encoding<TypeParam>::cjk.Chars(), Encoding<TypeParam>::cjk.Count() , -1, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(Encoding<TypeParam>::cjk.Chars(), Encoding<TypeParam>::cjk.Count(), 0, -1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Array_Index_Count_Empty_Exceptions) {
    char32 chars[1];
    EXPECT_THROW(TypeParam::encoding.GetBytes(chars, 0, 1, 1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Array_index_count_Null) {
    EXPECT_THROW(TypeParam::encoding.GetBytes(null, 1, 0, 0), ArgumentNullException);
  }
  
  //_______________________________________________________________________________________________
  // int32 GetBytes(const char32 chars[], int32 charsSize, int32 index, int32 count, byte bytes[], int32 bytesSize) const
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size();
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, sequence.Count(), (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Bytes_Too_Small) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size()-1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, sequence.Count(), (byte*)bytes.Data(), bytesSize), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Bytes_Larger) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size()+1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, sequence.Count(), (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Chars_Null) {
    char32* chars = null;
    byte bytes[2];
    EXPECT_THROW(TypeParam::encoding.GetBytes(chars, 1, 0, 1, bytes, 2), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Bytes_Null) {
    char32 chars[1] = { 32 };
    byte* bytes = null;
    EXPECT_THROW(TypeParam::encoding.GetBytes(chars, 1, 0, 1, bytes, 1), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Index_Is_1) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    int32 index = 1;
    int32 bytesSize = sequence.Size();
    int32 bytesOffset = Encoding<TypeParam>::charA.Size();
    
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size() - bytesOffset, TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), index, sequence.Count()-index, (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(&sequence.Bytes()[bytesOffset], sequence.Size()-bytesOffset, bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Index_Is_3) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    int32 index = 3;
    int32 bytesSize = sequence.Size();
    int32 bytesOffset = Encoding<TypeParam>::charA.Size() + Encoding<TypeParam>::charSpecialT.Size() + Encoding<TypeParam>::fullBlock.Size();
    
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size() - bytesOffset, TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), index, sequence.Count()-index, (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(&sequence.Bytes()[bytesOffset], sequence.Size()-bytesOffset, bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Index_Is_1_And_Count_Is_Too_Large) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    int32 index = 1;
    int32 bytesSize = sequence.Size();
    
    System::Array<byte> bytes(bytesSize);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), index, 1 + (sequence.Count()-index), (byte*)bytes.Data(), bytesSize),
                 ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Index_Is_1_And_Count_Is_0) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    int32 index = 1;
    int32 bytesSize = sequence.Size();
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(0, TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), index, 0, (byte*)bytes.Data(), bytesSize));
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Index_Is_1_And_Count_Is_1) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    EncodingUT::UnicodeSequence expected = Encoding<TypeParam>::charSpecialT;
    int32 index = 1;
    int32 bytesSize = sequence.Size();
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(expected.Size(), TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), index, 1, (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(expected.Bytes(), expected.Count(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Index_Is_3_And_Count_Is_1) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    EncodingUT::UnicodeSequence expected = Encoding<TypeParam>::koala;
    int32 index = 3;
    int32 bytesSize = sequence.Size();
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(expected.Size(), TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), index, 1, (byte*)bytes.Data(), bytesSize));
    EncodingUT::EXPECT_BYTES(expected.Bytes(), expected.Count(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes___Index_Is_4_And_Count_Is_0) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::koala;
    int32 index = 1;
    int32 bytesSize = sequence.Size();
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(0, TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), index, 0, (byte*)bytes.Data(), bytesSize));
  }
  
  //___________________________________________________________________________
  // int32 GetBytes(const char32 chars[], int32 charsSize, int32 charIndex, int32 charCount, byte bytes[], int32 bytesSize, int32 byteIndex) const
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___Chars_Is_Null) {
    char32* chars = null;
    byte bytes[1];
    EXPECT_THROW(TypeParam::encoding.GetBytes(chars, 1, 0, 0, bytes, 1, 0), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___Bytes_Is_Null) {
    char32 chars[1] = { 0 };
    byte* bytes = null;
    EXPECT_THROW(TypeParam::encoding.GetBytes(chars, 1, 0, 0, bytes, 1, 0), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___CharsIndex_Is_Negative) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    byte bytes[3];
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), -1, 1, bytes, 3, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___CharsIndex_Is_Out_Of_Bounds) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    byte bytes[3];
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, 4, bytes, 3, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___Invalid_Range) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    byte bytes[3];
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 1, 3, bytes, 3, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 2, 2, bytes, 3, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 3, 1, bytes, 3, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___Bytes_Is_Too_Small) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size() - 1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, 3, (byte*)bytes.Data(), bytesSize, 0), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___CharsIndex_Is_1_And_Bytes_Is_Too_Small) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    EncodingUT::UnicodeSequence sequence2 = Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence2.Size() - 1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 1, 2, (byte*)bytes.Data(), bytesSize, 0), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___Bytes_Is_Larger) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size() + 1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, 3, (byte*)bytes.Data(), bytesSize, 0));
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index___CharsRange_2_1_Bytes_Is_Larger) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size();
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(Encoding<TypeParam>::koala.Size(), TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 2, 1, (byte*)bytes.Data(), bytesSize, 0));
    EncodingUT::EXPECT_BYTES(&sequence.Bytes()[Encoding<TypeParam>::charA.Size() + Encoding<TypeParam>::cjk.Size()], Encoding<TypeParam>::koala.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_Chars_Index_Count_Bytes_Index_Exceptions) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    byte bytes[3];
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, 3, bytes, 3, 1), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, 3, bytes, 3, 1), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, 2, bytes, 3, 2), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, 1, bytes, 3, 3), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 0, 0, bytes, 3, 4), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.Chars(), sequence.Count(), 4, 0, bytes, 3, 0),ArgumentException);
  }
  
  //_______________________________________________________________________________________________
  //int32 GetBytes(const String& s, int32 charIndex, int32 charCount, byte bytes[], int32 bytesLength, int32 byteIndex) const
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index___Bytes_Is_Null) {
    String str("ok");
    byte* bytes = null;
    EXPECT_THROW(TypeParam::encoding.GetBytes(str, 0, 0, bytes, 1, 0), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index___CharsIndex_Is_Negative) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    byte bytes[3];
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), -1, 1, bytes, 3, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index___CharsIndex_Is_Out_Of_Bounds) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    byte bytes[3];
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 0, 4, bytes, 3, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index___Invalid_Range) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    byte bytes[3];
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 1, 3, bytes, 3, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 2, 2, bytes, 3, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 3, 1, bytes, 3, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index___Bytes_Is_Too_Small) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size() - 1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 0, 3, (byte*)bytes.Data(), bytesSize, 0), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index___CharsIndex_Is_1_And_Bytes_Is_Too_Small) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    EncodingUT::UnicodeSequence sequence2 = Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence2.Size() - 1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 1, 2, (byte*)bytes.Data(), bytesSize, 0), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index___Bytes_Is_Larger) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size() + 1;
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(sequence.Size(), TypeParam::encoding.GetBytes(sequence.ToString(), 0, 3, (byte*)bytes.Data(), bytesSize, 0));
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index___CharsRange_2_1_Bytes_Is_Larger) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 bytesSize = sequence.Size();
    System::Array<byte> bytes(bytesSize);
    EXPECT_EQ(Encoding<TypeParam>::koala.Size(), TypeParam::encoding.GetBytes(sequence.ToString(), 2, 1, (byte*)bytes.Data(), bytesSize, 0));
    EncodingUT::EXPECT_BYTES(&sequence.Bytes()[Encoding<TypeParam>::charA.Size() + Encoding<TypeParam>::cjk.Size()], Encoding<TypeParam>::koala.Size(), bytes.Data());
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count_Bytes_Index_Exceptions) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    byte bytes[3];
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 0, 3, bytes, 3, 1), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 0, 3, bytes, 3, 1), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 0, 2, bytes, 3, 2), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 0, 1, bytes, 3, 3), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 0, 0, bytes, 3, 4), ArgumentException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(sequence.ToString(), 4, 0, bytes, 3, 0), ArgumentException);
  }
  
  //_______________________________________________________________________________________________
  //         virtual int32 GetBytes(char32 c, byte bytes[], int32 bytesSize, int32 byteIndex) const
  
  TYPED_TEST(Encoding, GetBytes_char32_Bytes_Index) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::sigma + Encoding<TypeParam>::syriacSemkath + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 size = sequence.Size();
    System::Array<byte> bytes(size);
    int32 index = 0;
    int32 charSize;
    charSize = TypeParam::encoding.GetBytes(Encoding<TypeParam>::charA.Character(), (byte*)bytes.Data(), size, index);
    EXPECT_EQ(Encoding<TypeParam>::charA.Size(), charSize);
    index += charSize;
    
    charSize = TypeParam::encoding.GetBytes(Encoding<TypeParam>::charAE.Character(), (byte*)bytes.Data(), size, index);
    EXPECT_EQ(Encoding<TypeParam>::charAE.Size(), charSize);
    index += charSize;
    
    charSize = TypeParam::encoding.GetBytes(Encoding<TypeParam>::charSpecialT.Character(), (byte*)bytes.Data(), size, index);
    EXPECT_EQ(Encoding<TypeParam>::charSpecialT.Size(), charSize);
    index += charSize;
    
    charSize = TypeParam::encoding.GetBytes(Encoding<TypeParam>::sigma.Character(), (byte*)bytes.Data(), size, index);
    EXPECT_EQ(Encoding<TypeParam>::sigma.Size(), charSize);
    index += charSize;
    
    charSize = TypeParam::encoding.GetBytes(Encoding<TypeParam>::syriacSemkath.Character(), (byte*)bytes.Data(), size, index);
    EXPECT_EQ(Encoding<TypeParam>::syriacSemkath.Size(), charSize);
    index += charSize;
    
    charSize = TypeParam::encoding.GetBytes(Encoding<TypeParam>::fullBlock.Character(), (byte*)bytes.Data(), size, index);
    EXPECT_EQ(Encoding<TypeParam>::fullBlock.Size(), charSize);
    index += charSize;
    
    charSize = TypeParam::encoding.GetBytes(Encoding<TypeParam>::cjk.Character(), (byte*)bytes.Data(), size, index);
    EXPECT_EQ(Encoding<TypeParam>::cjk.Size(), charSize);
    index += charSize;
    
    charSize = TypeParam::encoding.GetBytes(Encoding<TypeParam>::koala.Character(), (byte*)bytes.Data(), size, index);
    EXPECT_EQ(Encoding<TypeParam>::koala.Size(), charSize);
    index += charSize;
    
    EncodingUT::EXPECT_BYTES(sequence.Bytes(), sequence.Size(), (byte*)bytes.Data());
  }
  
  //_______________________________________________________________________________________________
  //                         Array<byte> GetBytes(const String& s, int32 index, int32 count) const
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count___String_Is_Empty) {
    EXPECT_EQ(0, TypeParam::encoding.GetBytes("", 0, 0).Length);
    EXPECT_EQ(0, TypeParam::encoding.GetBytes("", 1, 0).Length);
    EXPECT_THROW(TypeParam::encoding.GetBytes("", 2, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count___Index_Is_Negative) {
    EXPECT_THROW(TypeParam::encoding.GetBytes("", -1, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(":)", -1, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(":)", -1, 1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count___Count_Is_Negative) {
    EXPECT_THROW(TypeParam::encoding.GetBytes("", 0, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(":)", 0, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(":)", 1, -2), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes(":)", 2, -2), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count___Index_Out_Of_Range) {
    EXPECT_THROW(TypeParam::encoding.GetBytes("123", 3, 1), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes("123", 4, 1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count___Invalid_Ranges) {
    EXPECT_THROW(TypeParam::encoding.GetBytes("123", 0, 4), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes("123", 1, 3), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes("123", 2, 2), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetBytes("123", 3, 1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetBytes_String_Index_Count) {
    EncodingUT::UnicodeSequence expected;
    Array<byte> bytes;
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::koala;
    
    expected = Encoding<TypeParam>::charA;
    bytes = TypeParam::encoding.GetBytes(sequence.ToString(), 0, 1);
    EncodingUT::EXPECT_BYTES(expected.Bytes(), expected.Size(), bytes);
    
    expected = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT;
    bytes = TypeParam::encoding.GetBytes(sequence.ToString(), 0, 2);
    EncodingUT::EXPECT_BYTES(expected.Bytes(), expected.Size(), bytes);
    
    expected = Encoding<TypeParam>::charA + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::koala;
    bytes = TypeParam::encoding.GetBytes(sequence.ToString(), 0, 3);
    EncodingUT::EXPECT_BYTES(expected.Bytes(), expected.Size(), bytes);
    
    expected = Encoding<TypeParam>::charSpecialT;
    bytes = TypeParam::encoding.GetBytes(sequence.ToString(), 1, 1);
    EncodingUT::EXPECT_BYTES(expected.Bytes(), expected.Size(), bytes);
    
    expected = Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::koala;
    bytes = TypeParam::encoding.GetBytes(sequence.ToString(), 1, 2);
    EncodingUT::EXPECT_BYTES(expected.Bytes(), expected.Size(), bytes);
    
    expected = Encoding<TypeParam>::koala;
    bytes = TypeParam::encoding.GetBytes(sequence.ToString(), 2, 1);
    EncodingUT::EXPECT_BYTES(expected.Bytes(), expected.Size(), bytes);
    
  }
  
  //_______________________________________________________________________________________________
  //                                  int32 GetCharCount(const byte bytes[], int32 bytesSize) const
  
  using UnicodeCharacters = Array<EncodingUT::UnicodeCharacter>;
  
  int32 GetCompleteChars(const UnicodeCharacters& chars, int32 index) {
    int32 completed = 0;
    int32 size = 0;
    for (int32 i = 0; i < chars.Length; i++) {
      size += chars[i].Size();
      if (index < size) {
        return completed;
      }
      completed += 1;
    }
    return completed;
  }
  
  TYPED_TEST(Encoding, GetCompleteChars) {
    byte bytes1[2] = { 0x91, 0xE6 };
    byte bytes2[1] = { 0x61 };
    byte bytes3[3] = { 0xE2, 0x96, 0x88 };
    
    EncodingUT::UnicodeCharacter c1(0xE6,   bytes1, 2);
    EncodingUT::UnicodeCharacter c2(0x61,   bytes2, 1);
    EncodingUT::UnicodeCharacter c3(0x2588, bytes3, 3);
    UnicodeCharacters chars = {c1, c2, c3};
    
    // index    0123456
    // complete 0012223
    EXPECT_EQ(0, GetCompleteChars(chars, 0));
    EXPECT_EQ(0, GetCompleteChars(chars, 1));
    EXPECT_EQ(1, GetCompleteChars(chars, 2));
    EXPECT_EQ(2, GetCompleteChars(chars, 3));
    EXPECT_EQ(2, GetCompleteChars(chars, 4));
    EXPECT_EQ(2, GetCompleteChars(chars, 5));
    EXPECT_EQ(3, GetCompleteChars(chars, 6));
  }
  
  TYPED_TEST(Encoding, GetCharCount_Bytes) {
    UnicodeCharacters chars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::charSpecialT, Encoding<TypeParam>::sigma, Encoding<TypeParam>::syriacSemkath, Encoding<TypeParam>::fullBlock, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(chars);
    for (int32 i = 0; i <= sequence.Size(); i++) {
      EXPECT_EQ(GetCompleteChars(chars, i), TypeParam::encoding.GetCharCount(sequence.Bytes(), i));
    }
  }
  
  TYPED_TEST(Encoding, GetCharCount_byte_array_null) {
    EXPECT_EQ(0, TypeParam::encoding.GetCharCount(null, 0));
    EXPECT_THROW(TypeParam::encoding.GetCharCount(null, 1), ArgumentNullException);
  }
  
  //_______________________________________________________________________________________________
  // virtual int32 GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const
  
  TYPED_TEST(Encoding, GetCharCount_byte_array_index_count_null) {
    EXPECT_EQ(0, TypeParam::encoding.GetCharCount(null, 0, 0, 0));
    EXPECT_THROW(TypeParam::encoding.GetCharCount(null, 0, 0, 1), ArgumentOutOfRangeException);
    EXPECT_THROW(TypeParam::encoding.GetCharCount(null, 1, 0, 1), ArgumentNullException);
  }
  
  //_______________________________________________________________________________________________
  //                             Array<char32> GetChars(const byte bytes[], int32 bytesSize) const
  
  TYPED_TEST(Encoding, GetChars_Bytes___BytesEmpty) {
    byte bytes[1] = { 32 };
    EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0).Length);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::sigma + Encoding<TypeParam>::fullBlock;
    
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), 1,
                             TypeParam::encoding.GetChars(sequence.Bytes(), Encoding<TypeParam>::charA.Size()));
    
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), 2,
                             TypeParam::encoding.GetChars(sequence.Bytes(), Encoding<TypeParam>::charA.Size() + Encoding<TypeParam>::charAE.Size()));
    
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), 3,
                             TypeParam::encoding.GetChars(sequence.Bytes(), Encoding<TypeParam>::charA.Size() + Encoding<TypeParam>::charAE.Size() + Encoding<TypeParam>::sigma.Size()));
    
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), 4,
                             TypeParam::encoding.GetChars(sequence.Bytes(), Encoding<TypeParam>::charA.Size() + Encoding<TypeParam>::charAE.Size() + Encoding<TypeParam>::sigma.Size() + Encoding<TypeParam>::fullBlock.Size()));
  }
  
  //_______________________________________________________________________________________________
  //     int32 GetChars(const byte bytes[], int32 bytesSize, char32 chars[], int32 charsSize) const
  
  TYPED_TEST(Encoding, GetChars_Bytes_Chars) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    char32 chars[4];
    int32 nbBytes = 0;
    EXPECT_EQ(0, TypeParam::encoding.GetChars(sequence.Bytes(), nbBytes, chars, 0));
    
    nbBytes += Encoding<TypeParam>::charA.Size();
    EXPECT_EQ(1, TypeParam::encoding.GetChars(sequence.Bytes(), nbBytes, chars, 1));
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), 1, chars);
    
    nbBytes += Encoding<TypeParam>::charAE.Size();
    EXPECT_EQ(2, TypeParam::encoding.GetChars(sequence.Bytes(), nbBytes, chars, 2));
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), 2, chars);
    
    nbBytes += Encoding<TypeParam>::cjk.Size();
    EXPECT_EQ(3, TypeParam::encoding.GetChars(sequence.Bytes(), nbBytes, chars, 3));
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), 3, chars);
    
    nbBytes += Encoding<TypeParam>::koala.Size();
    EXPECT_EQ(4, TypeParam::encoding.GetChars(sequence.Bytes(), nbBytes, chars, 4));
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), 4, chars);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Chars___Chars_Too_Small) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    char32 chars[3];
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), chars, 3), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Chars___Bytes_Null) {
    char32 chars[3];
    EXPECT_THROW(TypeParam::encoding.GetChars(null, 1, chars, 3), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Chars___Chars_Null) {
    byte bytes[4] = { 0, 0, 0, 0 };
    char32* chars = null;
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 4, chars, 1), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Chars___Bytes_Size_Negative) {
    byte bytes[4] = { 0, 0, 0, 0 };
    char32 chars[1];
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, -1, chars, 1), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Chars___Chars_Size_Negative) {
    byte bytes[4] = { 0, 0, 0, 0 };
    char32 chars[1];
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, chars, -1), ArgumentException);
  }
  
  //_______________________________________________________________________________________________
  // int32 GetChars(const byte bytes[], int32 bytesSize, int32 index, int32 count, char32 chars[], int32 charsSize) const
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Bytes_Is_Null) {
    byte* bytes = null;
    char32 chars[1] = { 32 };
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 1), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Bytes_Is_Null_But_Zero_Length) {
    byte* bytes = null;
    char32 chars[1] = { 32 };
    EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 0, 0, chars, 1));
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Chars_Is_Null) {
    byte bytes[1] = { 32 };
    char32* chars = null;
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 1), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Chars_Is_Too_Small) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 nbChars = sequence.Count()-1;
    Array<char32> chars(nbChars);
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, sequence.Size(), (char32*)chars.Data(), nbChars), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Chars_Is_Larger) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::sigma + Encoding<TypeParam>::syriacSemkath + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 nbChars = sequence.Count()+1;
    Array<char32> chars(nbChars);
    EXPECT_EQ(sequence.Count(), TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, sequence.Size(), (char32*)chars.Data(), nbChars));
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), sequence.Count(), chars.Data());
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(uchars);
    int32 nbChars = sequence.Count();
    Array<char32> chars(nbChars);
    
    for (int32 i = 0; i <= sequence.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(uchars, i);
      EXPECT_EQ(expectedNbChars, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, i, (char32*)chars.Data(), nbChars));
      EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), expectedNbChars, chars.Data());
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Index_Is_SizeOf_A) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    UnicodeCharacters expectedChars = {Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(uchars);
    EncodingUT::UnicodeSequence expected(expectedChars);
    int32 nbChars = sequence.Count();
    Array<char32> chars(nbChars);
    
    for (int32 i = 0; i <= expected.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(expectedChars, i);
      EXPECT_EQ(expectedNbChars, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), uchars[0].Size(), i, (char32*)chars.Data(), nbChars));
      EncodingUT::EXPECT_CHARS(expected.DecodedChars(), expectedNbChars, chars.Data());
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Index_Last_Defined_Char) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    UnicodeCharacters prefixChars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk};
    UnicodeCharacters expectedChars = {Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(uchars);
    EncodingUT::UnicodeSequence expected(expectedChars);
    EncodingUT::UnicodeSequence prefix(prefixChars);
    
    int32 nbChars = sequence.Count();
    Array<char32> chars(nbChars);
    
    for (int32 i = 0; i <= expected.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(expectedChars, i);
      EXPECT_EQ(expectedNbChars, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), prefix.Size(), i, (char32*)chars.Data(), nbChars));
      EncodingUT::EXPECT_CHARS(expected.DecodedChars(), expectedNbChars, chars.Data());
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Index_Is_At_End_With_Zero_Length) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    char32 chars[3];
    EXPECT_EQ(0, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 3, 0, chars, 3));
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Index_Is_Negative) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    char32 chars[3];
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), -1, sequence.Size(), chars, 3), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Count_Is_Negative) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    char32 chars[3];
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, -1, chars, 3), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Index_Is_Out_Of_Range) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    char32 chars[3];
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), sequence.Size()+1, 1, chars, 3), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Count_Is_Out_Of_Range) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    char32 chars[3];
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, sequence.Size()+1, chars, 3), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars___Invalid_Range) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    char32 chars[3];
    
    for (int32 i = 0; i < sequence.Size(); i += 1) {
      EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), i, (sequence.Size()-i)+1, chars, 3), ArgumentOutOfRangeException);
    }
  }
  
  //______________________________________________________________________________________________
  //  Array<char32> GetChars(const byte bytes[], int32 bytesSize, int32 index, int32 count) const
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Bytes_Is_Null) {
    byte* bytes = null;
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 0), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Bytes_Is_Null_But_Zero_Length) {
    byte* bytes = null;
    EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 0, 0).Length);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(uchars);
    
    for (int32 i = 0; i <= sequence.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(uchars, i);
      EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), expectedNbChars, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, i));
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Index_Is_SizeOf_A) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    UnicodeCharacters expectedChars = {Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(uchars);
    EncodingUT::UnicodeSequence expected(expectedChars);
    
    for (int32 i = 0; i <= expected.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(expectedChars, i);
      EncodingUT::EXPECT_CHARS(expected.DecodedChars(), expectedNbChars,
                               TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), uchars[0].Size(), i));
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Index_Last_Defined_Char) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    UnicodeCharacters prefixChars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk};
    UnicodeCharacters expectedChars = {Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(uchars);
    EncodingUT::UnicodeSequence expected(expectedChars);
    EncodingUT::UnicodeSequence prefix(prefixChars);
    
    for (int32 i = 0; i <= expected.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(expectedChars, i);
      EncodingUT::EXPECT_CHARS(expected.DecodedChars(), expectedNbChars,
                               TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), prefix.Size(), i));
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Index_Is_At_End_With_Zero_Length) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    EXPECT_EQ(0, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 3, 0).Length);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Index_Is_Negative) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), -1, sequence.Size()), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Count_Is_Negative) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, -1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Index_Is_Out_Of_Range) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), sequence.Size()+1, 1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Count_Is_Out_Of_Range) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, sequence.Size()+1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count___Invalid_Range) {
    EncodingUT::UnicodeSequence sequence(Encoding<TypeParam>::charA + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala);
    for (int32 i = 0; i < sequence.Size(); i += 1) {
      EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), i, (sequence.Size()-i)+1), ArgumentOutOfRangeException);
    }
  }
  
  //__________________________________________________________________________________________________________________________________________________
  // int32 GetChars(const byte bytes[], int32 bytesLength, int32 byteIndex, int32 byteCount, char32 chars[], int32 charsLength, int32 charIndex) const
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::sigma + Encoding<TypeParam>::syriacSemkath + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 nbChars = sequence.Count();
    Array<char32> chars(nbChars);
    EXPECT_EQ(sequence.Count(), TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, sequence.Size(), (char32*)chars.Data(), nbChars, 0));
    EncodingUT::EXPECT_CHARS(sequence.DecodedChars(), nbChars, chars.Data());
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Bytes_Is_Null) {
    byte* bytes = null;
    char32 chars[1] = { 1 };
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 1, 0), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Chars_Is_Null) {
    byte bytes[1] = { 1 };
    char32* chars = null;
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 1, 0), ArgumentNullException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Byte_Index_Is_Negative) {
    byte bytes[1] = { 1 };
    char32 chars[1] = { 1 };
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, -1, 0, chars, 1, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Byte_Count_Is_Negative) {
    byte bytes[1] = { 1 };
    char32 chars[1] = { 1 };
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, -1, chars, 1, 0), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Char_Index_Is_Negative) {
    byte bytes[1] = { 1 };
    char32 chars[1] = { 1 };
    EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 1, -1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Bytes_Invalid_Range) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::sigma + Encoding<TypeParam>::syriacSemkath + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 nbChars = sequence.Count();
    Array<char32> chars(nbChars);
    for (int32 i = 0; i < sequence.Size(); i += 1) {
      EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), i, (sequence.Size()-i)+1, (char32*)chars.Data(), nbChars, 0), ArgumentOutOfRangeException);
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Chars_Is_Too_Small) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::sigma + Encoding<TypeParam>::syriacSemkath + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 nbChars = sequence.Count();
    Array<char32> chars(nbChars);
    for (int32 i = 1; i <= nbChars; i += 1) {
      EXPECT_THROW(TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, sequence.Size(), (char32*)chars.Data(), nbChars, i), ArgumentException);
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Chars_Index_At_End_With_Zero_Length) {
    EncodingUT::UnicodeSequence sequence = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::charSpecialT + Encoding<TypeParam>::sigma + Encoding<TypeParam>::syriacSemkath + Encoding<TypeParam>::fullBlock + Encoding<TypeParam>::cjk + Encoding<TypeParam>::koala;
    int32 nbChars = sequence.Count();
    Array<char32> chars(nbChars);
    EXPECT_EQ(0, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), 0, 0, (char32*)chars.Data(), nbChars, nbChars));
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Index_Last_Defined_Char) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    UnicodeCharacters prefixChars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk};
    UnicodeCharacters expectedChars = {Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(uchars);
    EncodingUT::UnicodeSequence expected(expectedChars);
    EncodingUT::UnicodeSequence prefix(prefixChars);
    
    int32 nbChars = expected.Count();
    Array<char32> chars(nbChars);
    
    for (int32 i = 0; i <= expected.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(expectedChars, i);
      EXPECT_EQ(expectedNbChars, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), prefix.Size(), i, (char32*)chars.Data(), nbChars, 0));
      EncodingUT::EXPECT_CHARS(expected.DecodedChars(), expectedNbChars, chars.Data());
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Index_Last_Defined_Char_Char_Index_Is_Three) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    UnicodeCharacters prefixChars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk};
    UnicodeCharacters expectedChars = {Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(uchars);
    EncodingUT::UnicodeSequence expected(expectedChars);
    EncodingUT::UnicodeSequence prefix(prefixChars);
    
    int32 nbChars = expected.Count() + 3;
    Array<char32> chars(nbChars);
    
    for (int32 i = 0; i <= expected.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(expectedChars, i);
      EXPECT_EQ(expectedNbChars, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), prefix.Size(), i, (char32*)chars.Data(), nbChars, 3));
      EncodingUT::EXPECT_CHARS(expected.DecodedChars(), expectedNbChars, &chars.Data()[3]);
    }
  }
  
  TYPED_TEST(Encoding, GetChars_Bytes_Index_Count_Chars_Index___Index_Two_Last_Defined_Char) {
    UnicodeCharacters uchars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    UnicodeCharacters prefixChars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE};
    UnicodeCharacters expectedChars = {Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    
    EncodingUT::UnicodeSequence sequence(uchars);
    EncodingUT::UnicodeSequence prefix(prefixChars);
    EncodingUT::UnicodeSequence expected(expectedChars);
    
    int32 nbChars = expected.Count();
    Array<char32> chars(nbChars);
    
    for (int32 i = 0; i <= expected.Size(); i += 1) {
      int32 expectedNbChars = GetCompleteChars(expectedChars, i);
      EXPECT_EQ(expectedNbChars, TypeParam::encoding.GetChars(sequence.Bytes(), sequence.Size(), prefix.Size(), i, (char32*)chars.Data(), nbChars, 0));
      EncodingUT::EXPECT_CHARS(expected.DecodedChars(), expectedNbChars, chars.Data());
    }
  }
  
  //_______________________________________________________________________________________________
  //                                    string GetString(const byte bytes[], int32 bytesSize) const
  
  String FromCharactersToDecodedString(UnicodeCharacters& characters, int32 index, int32 count) {
    String concat;
    for (EncodingUT::UnicodeCharacter character : characters) {
      if (index > 0)  {
        index -= 1;
      } else if (index == 0 && count > 0) {
        count -= 1;
        concat += character.DecodedCharacter();
      }
    }
    return concat;
  }
  
  TYPED_TEST(Encoding, FromCharactersToDecodedString) {
    byte bytes[1] = { 32 };
    EncodingUT::UnicodeCharacter c1('a', bytes, 1);
    EncodingUT::UnicodeCharacter c2('b', bytes, 1);
    EncodingUT::UnicodeCharacter c3('c', bytes, 1);
    UnicodeCharacters chars = {c1, c2, c3};
    
    EXPECT_EQ("", FromCharactersToDecodedString(chars, 0, 0));
    EXPECT_EQ("a", FromCharactersToDecodedString(chars, 0, 1));
    EXPECT_EQ("ab", FromCharactersToDecodedString(chars, 0, 2));
    EXPECT_EQ("abc", FromCharactersToDecodedString(chars, 0, 3));
    
    EXPECT_EQ("", FromCharactersToDecodedString(chars, 1, 0));
    EXPECT_EQ("b", FromCharactersToDecodedString(chars, 1, 1));
    EXPECT_EQ("bc", FromCharactersToDecodedString(chars, 1, 2));
    
    EXPECT_EQ("", FromCharactersToDecodedString(chars, 2, 0));
    EXPECT_EQ("c", FromCharactersToDecodedString(chars, 2, 1));
  }
  
  TYPED_TEST(Encoding, GetString_Bytes) {
    UnicodeCharacters chars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::charSpecialT, Encoding<TypeParam>::sigma, Encoding<TypeParam>::syriacSemkath, Encoding<TypeParam>::fullBlock, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(chars);
    for (int32 i = 0; i <= sequence.Size(); i++) {
      EXPECT_EQ(FromCharactersToDecodedString(chars, 0, GetCompleteChars(chars, i)), TypeParam::encoding.GetString(sequence.Bytes(), i));
    }
  }
  
  TYPED_TEST(Encoding, GetString_Bytes___Bytes_Is_Null) {
    EXPECT_EQ("", TypeParam::encoding.GetString(null, 0));
    EXPECT_THROW(TypeParam::encoding.GetString(null, 1), ArgumentNullException);
    EXPECT_THROW(TypeParam::encoding.GetString(null, -1), ArgumentException);
  }
  
  //_______________________________________________________________________________________________
  //          string GetString(const byte bytes[], int32 bytesSize, int32 index, int32 count) const
  
  TYPED_TEST(Encoding, GetString_Bytes_Index_Count___Index_Is_Zero) {
    UnicodeCharacters chars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::charSpecialT, Encoding<TypeParam>::sigma, Encoding<TypeParam>::syriacSemkath, Encoding<TypeParam>::fullBlock, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(chars);
    for (int32 i = 0; i <= sequence.Size(); i++) {
      EXPECT_EQ(FromCharactersToDecodedString(chars, 0, GetCompleteChars(chars, i)), TypeParam::encoding.GetString(sequence.Bytes(), sequence.Size(), 0, i));
    }
  }
  
  TYPED_TEST(Encoding, GetString_Bytes_Index_Count___Index_Is_Three) {
    UnicodeCharacters chars = {Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE, Encoding<TypeParam>::charSpecialT, Encoding<TypeParam>::sigma, Encoding<TypeParam>::syriacSemkath, Encoding<TypeParam>::fullBlock, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    UnicodeCharacters expectedChars = {Encoding<TypeParam>::sigma, Encoding<TypeParam>::syriacSemkath, Encoding<TypeParam>::fullBlock, Encoding<TypeParam>::cjk, Encoding<TypeParam>::koala};
    EncodingUT::UnicodeSequence sequence(chars);
    EncodingUT::UnicodeSequence prefix = Encoding<TypeParam>::charA + Encoding<TypeParam>::charAE + Encoding<TypeParam>::charSpecialT;
    EncodingUT::UnicodeSequence expected(expectedChars);
    for (int32 i = 0; i < expected.Size(); i++) {
      EXPECT_EQ(
                FromCharactersToDecodedString(chars, 3, GetCompleteChars(expectedChars, i)),
                TypeParam::encoding.GetString(sequence.Bytes(), sequence.Size(), prefix.Size(), i));
    }
  }
  
  TYPED_TEST(Encoding, GetString_Bytes_Index_Count___Bytes_Is_Null) {
    EXPECT_EQ("", TypeParam::encoding.GetString(null, 0, 0, 0));
    EXPECT_THROW(TypeParam::encoding.GetString(null, 1, 0, 0), ArgumentNullException);
    EXPECT_THROW(TypeParam::encoding.GetString(null, -1, 0, 0), ArgumentException);
  }
  
  TYPED_TEST(Encoding, GetString_Bytes_Index_Count___Index_Is_Negative) {
    byte bytes[1] = { 32 };
    EXPECT_THROW(TypeParam::encoding.GetString(bytes, 1, -1, 1), ArgumentOutOfRangeException);
  }
  
  TYPED_TEST(Encoding, GetString_Bytes_Index_Count___Count_Is_Negative) {
    byte bytes[1] = { 32 };
    EXPECT_THROW(TypeParam::encoding.GetString(bytes, 1, 0, -1), ArgumentOutOfRangeException);
  }
  
  //_____________________________________________________________________________________________
  //                                                              virtual String ToString() const
  
  TYPED_TEST(Encoding, ToString) {
    EXPECT_EQ(TypeParam::encodingName, TypeParam::encoding.GetEncodingName());
  }
  
  TYPED_TEST(Encoding, GetBytes_Exceptions) {
    EncodingUT::CheckErrorsGetBytes(TypeParam::encoding);
  }
  
  TYPED_TEST(Encoding, GetByteCount_Exceptions) {
    EncodingUT::CheckErrorsString(TypeParam::encoding);
  }
  
  TYPED_TEST(Encoding, GetCharCount_Exceptions) {
    EncodingUT::CheckErrorsString(TypeParam::encoding);
  }
  
  TYPED_TEST(Encoding, GetChars_Exceptions) {
    EncodingUT::CheckErrorsString(TypeParam::encoding);
  }
  
  TYPED_TEST(Encoding, String_Exceptions) {
    EncodingUT::CheckErrorsString(TypeParam::encoding);
  }
  
  /*
   TYPED_TEST(Encoding, GetCharCount_byte_array_index_count0) {
   byte bytes[2] = { 0x61, 0x91 };
   EXPECT_EQ(0, TypeParam::encoding.GetCharCount(bytes, 0, 0, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetCharCount(bytes, 1, 0, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetCharCount(bytes, 2, 0, 0));
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 1, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(0, TypeParam::encoding.GetCharCount(bytes, 1, 1, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetCharCount(bytes, 2, 1, 0));
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 2, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(0, TypeParam::encoding.GetCharCount(bytes, 2, 2, 0));
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 3, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 3, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 3, 0), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetCharCount_byte_array_index_count1) {
   byte bytes[2] = { 0x61, 0x91 };
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 0, 1), ArgumentException);
   EXPECT_EQ(1, TypeParam::encoding.GetCharCount(bytes, 1, 0, 1));
   EXPECT_EQ(1, TypeParam::encoding.GetCharCount(bytes, 2, 0, 1));
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 1, 1), ArgumentOutOfRangeException);
   EXPECT_EQ(1, TypeParam::encoding.GetCharCount(bytes, 2, 1, 1));
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 2, 1), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 3, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 3, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 3, 1), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetCharCount_byte_array_index_count2) {
   byte bytes[2] = { 0x61, 0x91 };
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 0, 2), ArgumentException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 0, 2), ArgumentOutOfRangeException);
   EXPECT_EQ(2, TypeParam::encoding.GetCharCount(bytes, 2, 0, 2));
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 1, 2), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 1, 2), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 1, 2), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 2, 2), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 2, 2), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 2, 2), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 3, 2), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 3, 2), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 3, 2), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetCharCount_byte_array_index_count3) {
   byte bytes[2] = { 0x61, 0x91 };
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 0, 3), ArgumentException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 0, 3), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 0, 3), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 1, 3), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 1, 3), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 1, 3), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 2, 3), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 2, 3), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 2, 3), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 0, 3, 3), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 1, 3, 3), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetCharCount(bytes, 2, 3, 3), ArgumentOutOfRangeException);
   }
   
   
   // index 0
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count0_char_array0_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 0, 0, chars, 0, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 0, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 0, 0, chars, 0, 0));
   
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 1, 0, chars, 0, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 1, 0, chars, 0, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 1, 0, chars, 0, 0));
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 0, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 0, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 2, 0, chars, 0, 0));
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count1_char_array0_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 1, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 1, chars, 0, 0), ArgumentException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 1, chars, 0, 0), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 1, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 1, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 1, chars, 0, 0), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 1, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 1, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 1, chars, 0, 0), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count2_char_array0_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 2, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 2, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 2, chars, 0, 0), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 2, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 2, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 2, chars, 0, 0), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 2, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 2, chars, 0, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 2, chars, 0, 0), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count0_char_array1_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 0, 0, chars, 1, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 1, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 0, 0, chars, 1, 0));
   
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 1, 0, chars, 1, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 1, 0, chars, 1, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 1, 0, chars, 1, 0));
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 0, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 0, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 2, 0, chars, 1, 0));
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count1_char_array1_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   char32 expected[2] = { Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE };
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 1, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 1, 0, 1, chars, 1, 0));
   EncodingUT::EXPECT_CHARS(expected, 1, chars);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 0, 1, chars, 1, 0));
   EncodingUT::EXPECT_CHARS(expected, 1, chars);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 1, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 1, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 1, 1, chars, 1, 0));
   EncodingUT::EXPECT_CHARS(&expected[1], 1, chars);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 1, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 1, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 1, chars, 1, 0), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count2_char_array1_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 2, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 2, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 2, chars, 1, 0), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 2, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 2, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 2, chars, 1, 0), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 2, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 2, chars, 1, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 2, chars, 1, 0), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count0_char_array2_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 0, 0, chars, 2, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 2, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 0, 0, chars, 2, 0));
   
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 1, 0, chars, 2, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 1, 0, chars, 2, 0));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 1, 0, chars, 2, 0));
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 0, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 0, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 2, 0, chars, 2, 0));
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count1_char_array2_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   char32 expected[2] = { Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE };
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 1, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 1, 0, 1, chars, 2, 0));
   EncodingUT::EXPECT_CHARS(expected, 1, chars);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 0, 1, chars, 2, 0));
   EncodingUT::EXPECT_CHARS(expected, 1, chars);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 1, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 1, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 1, 1, chars, 2, 0));
   EncodingUT::EXPECT_CHARS(&expected[1], 1, chars);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 1, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 1, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 1, chars, 2, 0), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count2_char_array2_index0) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   char32 expected[2] = { Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE };
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 2, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 2, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_EQ(2, TypeParam::encoding.GetChars(bytes, 2, 0, 2, chars, 2, 0));
   EncodingUT::EXPECT_CHARS(expected, 2, chars);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 2, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 2, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 2, chars, 2, 0), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 2, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 2, chars, 2, 0), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 2, chars, 2, 0), ArgumentOutOfRangeException);
   }
   
   // index 1
   TYPED_TEST(Encoding, GetChar_byte_array__index_count0_char_array0_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 0, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 0, chars, 0, 1), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 0, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 0, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 0, chars, 0, 1), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 0, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 0, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 0, chars, 0, 1), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count1_char_array0_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 1, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 1, chars, 0, 1), ArgumentException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 1, chars, 0, 1), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 1, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 1, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 1, chars, 0, 1), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 1, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 1, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 1, chars, 0, 1), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count2_char_array0_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 2, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 2, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 2, chars, 0, 1), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 2, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 2, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 2, chars, 0, 1), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 2, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 2, chars, 0, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 2, chars, 0, 1), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count0_char_array1_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 0, 0, chars, 1, 1));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 1, 1));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 0, 0, chars, 1, 1));
   
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 1, 0, chars, 1, 1));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 1, 0, chars, 1, 1));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 1, 0, chars, 1, 1));
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 0, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 0, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 2, 0, chars, 1, 1));
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count1_char_array1_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 1, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 1, chars, 1, 1), ArgumentException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 1, chars, 1, 1), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 1, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 1, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 1, chars, 1, 1), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 1, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 1, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 1, chars, 1, 1), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count2_char_array1_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 2, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 2, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 2, chars, 1, 1), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 2, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 2, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 2, chars, 1, 1), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 2, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 2, chars, 1, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 2, chars, 1, 1), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count0_char_array2_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 0, 0, chars, 2, 1));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 0, 0, chars, 2, 1));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 0, 0, chars, 2, 1));
   
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 0, 1, 0, chars, 2, 1));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 1, 1, 0, chars, 2, 1));
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 1, 0, chars, 2, 1));
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 0, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 0, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_EQ(0, TypeParam::encoding.GetChars(bytes, 2, 2, 0, chars, 2, 1));
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count1_char_array2_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   char32 expected[2] = { Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE };
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 1, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 1, 0, 1, chars, 2, 1));
   EncodingUT::EXPECT_CHARS(expected, 1, &chars[1]);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 0, 1, chars, 2, 1));
   EncodingUT::EXPECT_CHARS(expected, 1, &chars[1]);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 1, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 1, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 1, 1, chars, 2, 1));
   EncodingUT::EXPECT_CHARS(&expected[1], 1, &chars[1]);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 1, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 1, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 1, chars, 2, 1), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count2_char_array2_index1) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 0, 2, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 0, 2, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 0, 2, chars, 2, 1), ArgumentException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 1, 2, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 1, 2, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 1, 2, chars, 2, 1), ArgumentOutOfRangeException);
   
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 0, 2, 2, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 1, 2, 2, chars, 2, 1), ArgumentOutOfRangeException);
   EXPECT_THROW(TypeParam::encoding.GetChars(bytes, 2, 2, 2, chars, 2, 1), ArgumentOutOfRangeException);
   }
   
   TYPED_TEST(Encoding, GetChar_byte_array__index_count_char_array_index) {
   byte bytes[2] = { 0x61, 0x91 };
   char32 chars[2];
   char32 expected[2] = { Encoding<TypeParam>::charA, Encoding<TypeParam>::charAE };
   
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 0, 1, chars, 2, 0));
   EncodingUT::EXPECT_CHARS(expected, 1, chars);
   
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 0, 1, chars, 2, 1));
   EncodingUT::EXPECT_CHARS(expected, 1, &chars[1]);
   
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 1, 1, chars, 2, 0));
   EncodingUT::EXPECT_CHARS(&expected[1], 1, chars);
   
   EXPECT_EQ(1, TypeParam::encoding.GetChars(bytes, 2, 1, 1, chars, 2, 1));
   EncodingUT::EXPECT_CHARS(&expected[1], 1, &chars[1]);
   
   EXPECT_EQ(2, TypeParam::encoding.GetChars(bytes, 2, 0, 2, chars, 2, 0));
   EncodingUT::EXPECT_CHARS(expected, 1, chars);
   }*/
}
