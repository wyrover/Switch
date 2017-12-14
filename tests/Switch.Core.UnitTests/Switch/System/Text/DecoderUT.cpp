#include <Switch/System/Text/ASCIIEncoding.hpp>
#include <Switch/System/Text/ANSIEncoding.hpp>
#include <Switch/System/Text/UnicodeEncoding.hpp>
#include <Switch/System/Text/UTF8Encoding.hpp>
#include <Switch/System/Text/UTF32Encoding.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Text;

namespace {

  /*
                   Unicode() ascii  437   ISO-L1  ISO-L2  UTF8                  UTF16           UTF32

  charA            0x61     0x61   0x61  0x61    0x61    0x61                  0x61            0x61
  charAE           0xE6     ?      0x91  0xE6    ?       0xC3 0xA6             0xE6            0xE6
  charSpecialT     0x163    ?      ?     ?       0xFE    0xC5 0xA3             0x163           0x163
  sigma            0x3A3    ?      0xE4  ?       ?       0xCE 0xA3             0x3A3           0x3A3
  syriacSemkath    0x723    ?      ?     ?       ?       0xDC 0xA3             0x723           0x723
  fullBlock        0x2588   ?      0xDB  ?       ?       0xE2 0x96 0x88        0x2588          0x2588
  cjk              0x597B   ?      ?     ?       ?       0xE5 0xA5 0xBB        0x597B          0x597B
  koala            0x1F428  ?      ?     ?       ?       0xF0 0x9F 0x90 0xA8   0xD83D 0xDC28   0x1F428
  */

  char32 charA = 0x61;
  char32 charAE = 0xE6;
  char32 charSpecialT = 0x163;
  char32 sigma = 0x3A3;
  char32 syriacSemkath = 0x723;
  char32 fullBlock = 0x2588;
  char32 cjk = 0x597B;
  char32 koala = 0x1F428;

  TEST(Decoder, CreateDecoder_ASCII) {
    ASCIIEncoding encoding;
    ASCIIEncoding::Decoder decoder;
    ASSERT_EQ("ASCIIDecoder", decoder.ToString());
  }

  TEST(Decoder, CreateDecoder_437) {
    CodePage437Encoding::Decoder decoder;
    ASSERT_EQ("Code Page 437 Decoder", decoder.ToString());
  }

  TEST(Decoder, CreateDecoder_28591) {
    CodePage28591Encoding::Decoder decoder;
    ASSERT_EQ("Code Page 28591 Decoder", decoder.ToString());
  }

  TEST(Decoder, CreateDecoder_28592) {
    CodePage28592Encoding::Decoder decoder;
    ASSERT_EQ("Code Page 28592 Decoder", decoder.ToString());
  }

  TEST(Decoder, CreateDecoder_UTF8) {
    UTF8Encoding::Decoder decoder;
    ASSERT_EQ("UTF8Decoder", decoder.ToString());
  }

  TEST(Decoder, CreateDecoder_UTF16) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_EQ("UnicodeDecoder", decoder.ToString());
  }

  TEST(Decoder, CreateDecoder_UTF16BE) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_EQ("UnicodeDecoder Big Endian", decoder.ToString());
  }

  TEST(Decoder, CreateDecoder_UTF32) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_EQ("UTF32Decoder", decoder.ToString());
  }

  TEST(Decoder, CreateDecoder_UTF32BE) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_EQ("UTF32Decoder Big Endian", decoder.ToString());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_ASCII_charA) {
    ASCIIEncoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_437_charA) {
    CodePage437Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_437_charAE) {
    CodePage437Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x91);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charAE, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_437_sigma) {
    CodePage437Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xE4);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(sigma, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_437_fullBlock) {
    CodePage437Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xDB);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(fullBlock, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_88591_charA) {
    CodePage28591Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_88591_charAE) {
    CodePage28591Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xE6);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charAE, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_88592_charA) {
    CodePage28592Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_88592_charSpecialT) {
    CodePage28592Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xFE);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charSpecialT, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_charA) {
    UTF8Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_charAE) {
    UTF8Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xC3);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA6);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charAE, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_charSpecialT) {
    UTF8Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xC5);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA3);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charSpecialT, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_sigma) {
    UTF8Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xCE);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA3);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(sigma, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_syriacSemkath) {
    UTF8Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xDC);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA3);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(syriacSemkath, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_fullBlock) {
    UTF8Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xE2);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x96);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x88);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(fullBlock, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_cjk) {
    UTF8Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xE5);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA5);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xBB);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(cjk, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_koala) {
    UTF8Encoding::Decoder decoder;
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xF0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x9F);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x90);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA8);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(koala, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_charA) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_charAE) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xE6);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charAE, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_charSpecialT) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x63);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x1);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charSpecialT, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_sigma) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA3);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x3);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(sigma, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_syriacSemkath) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x23);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x7);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(syriacSemkath, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_fullBlock) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x88);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x25);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(fullBlock, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_cjk) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x7B);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x59);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(cjk, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_koala) {
    UnicodeEncoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x3D);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xD8);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x28);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xDC);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(koala, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_charA) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_charAE) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xE6);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charAE, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_charSpecialT) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x1);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x63);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charSpecialT, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_sigma) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x3);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA3);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(sigma, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_syriacSemkath) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x7);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x23);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(syriacSemkath, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_fullBlock) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x25);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x88);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(fullBlock, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_cjk) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x59);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x7B);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(cjk, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_koala) {
    UnicodeEncoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xD8);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x3D);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xDC);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x28);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(koala, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_charA) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_charAE) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xE6);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charAE, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_charSpecialT) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x63);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x1);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charSpecialT, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_sigma) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA3);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x3);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(sigma, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_syriacSemkath) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x23);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x7);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(syriacSemkath, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_fullBlock) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x88);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x25);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(fullBlock, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_cjk) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x7B);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x59);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(cjk, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_koala) {
    UTF32Encoding::Decoder decoder(false);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x28);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xF4);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x1);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(koala, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_charA) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x61);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charA, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_charAE) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xE6);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charAE, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_charSpecialT) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x1);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x63);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(charSpecialT, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_sigma) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x3);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xA3);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(sigma, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_syriacSemkath) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x7);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x23);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(syriacSemkath, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_fullBlock) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x25);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x88);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(fullBlock, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_cjk) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x59);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x7B);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(cjk, decoder.CodePoint());
  }

  TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_koala) {
    UTF32Encoding::Decoder decoder(true);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x0);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x1);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0xF4);
    ASSERT_FALSE(decoder.CodePointDefined());
    decoder.Add(0x28);
    ASSERT_TRUE(decoder.CodePointDefined());
    ASSERT_EQ(koala, decoder.CodePoint());
  }

}
