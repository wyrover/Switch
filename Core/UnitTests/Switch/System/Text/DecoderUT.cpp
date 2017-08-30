#include <Switch/System/Text/ASCIIEncoding.hpp>
#include <Switch/System/Text/ANSIEncoding.hpp>
#include <Switch/System/Text/UnicodeEncoding.hpp>
#include <Switch/System/Text/UTF8Encoding.hpp>
#include <Switch/System/Text/UTF32Encoding.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Text;
using namespace TUnit;

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
  EXPECT_EQ("ASCIIDecoder", decoder.ToString());
}

TEST(Decoder, CreateDecoder_437) {
  CodePage437Encoding::Decoder decoder;
  EXPECT_EQ("Code Page 437 Decoder", decoder.ToString());
}

TEST(Decoder, CreateDecoder_28591) {
  CodePage28591Encoding::Decoder decoder;
  EXPECT_EQ("Code Page 28591 Decoder", decoder.ToString());
}

TEST(Decoder, CreateDecoder_28592) {
  CodePage28592Encoding::Decoder decoder;
  EXPECT_EQ("Code Page 28592 Decoder", decoder.ToString());
}

TEST(Decoder, CreateDecoder_UTF8) {
  UTF8Encoding::Decoder decoder;
  EXPECT_EQ("UTF8Decoder", decoder.ToString());
}

TEST(Decoder, CreateDecoder_UTF16) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_EQ("UnicodeDecoder", decoder.ToString());
}

TEST(Decoder, CreateDecoder_UTF16BE) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_EQ("UnicodeDecoder Big Endian", decoder.ToString());
}

TEST(Decoder, CreateDecoder_UTF32) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_EQ("UTF32Decoder", decoder.ToString());
}

TEST(Decoder, CreateDecoder_UTF32BE) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_EQ("UTF32Decoder Big Endian", decoder.ToString());
}

TEST(Decoder, CodePointDefined_GetCodePoint_ASCII_charA) {
  ASCIIEncoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_437_charA) {
  CodePage437Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_437_charAE) {
  CodePage437Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x91);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charAE, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_437_sigma) {
  CodePage437Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xE4);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(sigma, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_437_fullBlock) {
  CodePage437Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xDB);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(fullBlock, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_88591_charA) {
  CodePage28591Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_88591_charAE) {
  CodePage28591Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xE6);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charAE, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_88592_charA) {
  CodePage28592Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_88592_charSpecialT) {
  CodePage28592Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xFE);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charSpecialT, decoder.CodePoint());
}

//_____________________________________________________________________________
//                                                                         UTF8

TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_charA) {
  UTF8Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_charAE) {
  UTF8Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xC3);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA6);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charAE, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_charSpecialT) {
  UTF8Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xC5);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA3);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charSpecialT, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_sigma) {
  UTF8Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xCE);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA3);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(sigma, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_syriacSemkath) {
  UTF8Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xDC);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA3);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(syriacSemkath, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_fullBlock) {
  UTF8Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xE2);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x96);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x88);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(fullBlock, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_cjk) {
  UTF8Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xE5);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA5);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xBB);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(cjk, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF8_koala) {
  UTF8Encoding::Decoder decoder;
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xF0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x9F);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x90);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA8);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(koala, decoder.CodePoint());
}

//_____________________________________________________________________________
//                                                                        UTF16

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_charA) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_charAE) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xE6);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charAE, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_charSpecialT) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x63);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x1);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charSpecialT, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_sigma) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA3);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x3);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(sigma, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_syriacSemkath) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x23);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x7);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(syriacSemkath, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_fullBlock) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x88);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x25);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(fullBlock, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_cjk) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x7B);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x59);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(cjk, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16_koala) {
  UnicodeEncoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x3D);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xD8);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x28);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xDC);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(koala, decoder.CodePoint());
}

//_____________________________________________________________________________
//                                                                      UTF16BE

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_charA) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_charAE) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xE6);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charAE, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_charSpecialT) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x1);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x63);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charSpecialT, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_sigma) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x3);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA3);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(sigma, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_syriacSemkath) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x7);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x23);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(syriacSemkath, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_fullBlock) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x25);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x88);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(fullBlock, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_cjk) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x59);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x7B);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(cjk, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF16BE_koala) {
  UnicodeEncoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xD8);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x3D);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xDC);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x28);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(koala, decoder.CodePoint());
}

//_____________________________________________________________________________
//                                                                        UTF32

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_charA) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_charAE) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xE6);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charAE, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_charSpecialT) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x63);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x1);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charSpecialT, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_sigma) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA3);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x3);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(sigma, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_syriacSemkath) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x23);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x7);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(syriacSemkath, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_fullBlock) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x88);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x25);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(fullBlock, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_cjk) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x7B);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x59);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(cjk, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32_koala) {
  UTF32Encoding::Decoder decoder(false);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x28);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xF4);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x1);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(koala, decoder.CodePoint());
}

//_____________________________________________________________________________
//                                                                        UTF32

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_charA) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x61);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charA, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_charAE) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xE6);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charAE, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_charSpecialT) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x1);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x63);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(charSpecialT, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_sigma) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x3);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xA3);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(sigma, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_syriacSemkath) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x7);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x23);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(syriacSemkath, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_fullBlock) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x25);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x88);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(fullBlock, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_cjk) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x59);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x7B);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(cjk, decoder.CodePoint());
}

TEST(Decoder, CodePointDefined_GetCodePoint_UTF32BE_koala) {
  UTF32Encoding::Decoder decoder(true);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x0);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x1);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0xF4);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(0x28);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(koala, decoder.CodePoint());
}

}
