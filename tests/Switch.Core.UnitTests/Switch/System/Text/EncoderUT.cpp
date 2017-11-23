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
                   unicode  ascii  437   ISO-L1  ISO-L2  UTF8                  UTF16           UTF32
  
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
  
  TEST(EncoderTest,   ASCII) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("ASCIIEncoder", encoder().ToString());
  }
  
  TEST(EncoderTest, CreateEncoder_437) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("Code Page 437 Encoder", encoder().ToString());
  }
  
  TEST(EncoderTest, CreateEncoder_28591) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("Code Page 28591 Encoder", encoder().ToString());
  }
  
  TEST(EncoderTest, CreateEncoder_28592) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("Code Page 28592 Encoder", encoder().ToString());
  }
  
  TEST(EncoderTest, CreateEncoder_UTF8) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("UTF8Encoder", encoder().ToString());
  }
  
  TEST(EncoderTest, CreateEncoder_UTF16) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("UnicodeEncoder", encoder().ToString());
  }
  
  TEST(EncoderTest, CreateEncoder_UTF16BE) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("UnicodeEncoder Big Endian", encoder().ToString());
  }
  
  TEST(EncoderTest, CreateEncoder_UTF32) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("UTF32Encoder", encoder().ToString());
  }
  
  TEST(EncoderTest, CreateEncoder_UTF32BE) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ("UTF32Encoder Big Endian", encoder().ToString());
  }
  
  TEST(EncoderTest, GetNbBytes_ASCII) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(1, encoder->GetNbBytes(charA));
    ASSERT_EQ(1, encoder->GetNbBytes(charAE));
    ASSERT_EQ(1, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(1, encoder->GetNbBytes(sigma));
    ASSERT_EQ(1, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(1, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(1, encoder->GetNbBytes(cjk));
    ASSERT_EQ(1, encoder->GetNbBytes(koala));
  }
  
  TEST(EncoderTest, GetNbBytes_437) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(1, encoder->GetNbBytes(charA));
    ASSERT_EQ(1, encoder->GetNbBytes(charAE));
    ASSERT_EQ(1, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(1, encoder->GetNbBytes(sigma));
    ASSERT_EQ(1, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(1, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(1, encoder->GetNbBytes(cjk));
    ASSERT_EQ(1, encoder->GetNbBytes(koala));
  }
  
  TEST(EncoderTest, GetNbBytes_88591) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(1, encoder->GetNbBytes(charA));
    ASSERT_EQ(1, encoder->GetNbBytes(charAE));
    ASSERT_EQ(1, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(1, encoder->GetNbBytes(sigma));
    ASSERT_EQ(1, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(1, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(1, encoder->GetNbBytes(cjk));
    ASSERT_EQ(1, encoder->GetNbBytes(koala));
  }
  
  TEST(EncoderTest, GetNbBytes_88592) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(1, encoder->GetNbBytes(charA));
    ASSERT_EQ(1, encoder->GetNbBytes(charAE));
    ASSERT_EQ(1, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(1, encoder->GetNbBytes(sigma));
    ASSERT_EQ(1, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(1, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(1, encoder->GetNbBytes(cjk));
    ASSERT_EQ(1, encoder->GetNbBytes(koala));
  }
  
  TEST(EncoderTest, GetNbBytes_UTF8) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(1, encoder->GetNbBytes(charA));
    ASSERT_EQ(2, encoder->GetNbBytes(charAE));
    ASSERT_EQ(2, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(2, encoder->GetNbBytes(sigma));
    ASSERT_EQ(2, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(3, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(3, encoder->GetNbBytes(cjk));
    ASSERT_EQ(4, encoder->GetNbBytes(koala));
  }
  
  TEST(EncoderTest, GetNbBytes_UTF16) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(2, encoder->GetNbBytes(charA));
    ASSERT_EQ(2, encoder->GetNbBytes(charAE));
    ASSERT_EQ(2, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(2, encoder->GetNbBytes(sigma));
    ASSERT_EQ(2, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(2, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(2, encoder->GetNbBytes(cjk));
    ASSERT_EQ(4, encoder->GetNbBytes(koala));
  }
  
  TEST(EncoderTest, GetNbBytes_UTF16BE) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(2, encoder->GetNbBytes(charA));
    ASSERT_EQ(2, encoder->GetNbBytes(charAE));
    ASSERT_EQ(2, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(2, encoder->GetNbBytes(sigma));
    ASSERT_EQ(2, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(2, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(2, encoder->GetNbBytes(cjk));
    ASSERT_EQ(4, encoder->GetNbBytes(koala));
  }
  
  TEST(EncoderTest, GetNbBytes_UTF32) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(4, encoder->GetNbBytes(charA));
    ASSERT_EQ(4, encoder->GetNbBytes(charAE));
    ASSERT_EQ(4, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(4, encoder->GetNbBytes(sigma));
    ASSERT_EQ(4, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(4, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(4, encoder->GetNbBytes(cjk));
    ASSERT_EQ(4, encoder->GetNbBytes(koala));
  }
  
  TEST(EncoderTest, GetNbBytes_UTF32BE) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    ASSERT_EQ(4, encoder->GetNbBytes(charA));
    ASSERT_EQ(4, encoder->GetNbBytes(charAE));
    ASSERT_EQ(4, encoder->GetNbBytes(charSpecialT));
    ASSERT_EQ(4, encoder->GetNbBytes(sigma));
    ASSERT_EQ(4, encoder->GetNbBytes(syriacSemkath));
    ASSERT_EQ(4, encoder->GetNbBytes(fullBlock));
    ASSERT_EQ(4, encoder->GetNbBytes(cjk));
    ASSERT_EQ(4, encoder->GetNbBytes(koala));
  }
  
  static void ResetBytes(byte bytes[]) {
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 0;
  }
  
  TEST(EncoderTest, Encode_TestResetBytes) {
    byte bytes[4];
    ResetBytes(bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_ASCII_charA) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_ASCII_charAE) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_ASCII_charSpecialT) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_ASCII_sigma) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_ASCII_syriacSemkath) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_ASCII_fullBlock) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_ASCII_cjk) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_ASCII_koala) {
    ASCIIEncoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_437_charA) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_437_charAE) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(0x91, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_437_charSpecialT) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_437_sigma) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(0xE4, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_437_syriacSemkath) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_437_fullBlock) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(0xDB, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_437_cjk) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_437_koala) {
    CodePage437Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88591_charA) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88591_charAE) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(0xE6, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88591_charSpecialT) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88591_sigma) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88591_syriacSemkath) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88591_fullBlock) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88591_cjk) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88591_koala) {
    CodePage28591Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88592_charA) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88592_charAE) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88592_charSpecialT) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(0xFE, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88592_sigma) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88592_syriacSemkath) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88592_fullBlock) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88592_cjk) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_88592_koala) {
    CodePage28592Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(Text::Encoding::Unknown(), bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF8_charA) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF8_charAE) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(0xC3, bytes[0]);
    ASSERT_EQ(0xA6, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF8_charSpecialT) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(0xC5, bytes[0]);
    ASSERT_EQ(0xA3, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF8_sigma) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(0xCE, bytes[0]);
    ASSERT_EQ(0xA3, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF8_syriacSemkath) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(0xDC, bytes[0]);
    ASSERT_EQ(0xA3, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF8_fullBlock) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(0xE2, bytes[0]);
    ASSERT_EQ(0x96, bytes[1]);
    ASSERT_EQ(0x88, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF8_cjk) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(0xE5, bytes[0]);
    ASSERT_EQ(0xA5, bytes[1]);
    ASSERT_EQ(0xBB, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF8_koala) {
    UTF8Encoding encoding;
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(0xF0, bytes[0]);
    ASSERT_EQ(0x9F, bytes[1]);
    ASSERT_EQ(0x90, bytes[2]);
    ASSERT_EQ(0xA8, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16_charA) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16_charAE) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(0xE6, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16_charSpecialT) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(0x63, bytes[0]);
    ASSERT_EQ(0x1, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16_sigma) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(0xA3, bytes[0]);
    ASSERT_EQ(0x3, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16_syriacSemkath) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(0x23, bytes[0]);
    ASSERT_EQ(0x7, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16_fullBlock) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(0x88, bytes[0]);
    ASSERT_EQ(0x25, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16_cjk) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(0x7B, bytes[0]);
    ASSERT_EQ(0x59, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16_koala) {
    UnicodeEncoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(0x3D, bytes[0]);
    ASSERT_EQ(0xD8, bytes[1]);
    ASSERT_EQ(0x28, bytes[2]);
    ASSERT_EQ(0xDC, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16BE_charA) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0x61, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16BE_charAE) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0xE6, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16BE_charSpecialT) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(0x1, bytes[0]);
    ASSERT_EQ(0x63, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16BE_sigma) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(0x3, bytes[0]);
    ASSERT_EQ(0xA3, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16BE_syriacSemkath) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(0x7, bytes[0]);
    ASSERT_EQ(0x23, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16BE_fullBlock) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(0x25, bytes[0]);
    ASSERT_EQ(0x88, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16BE_cjk) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(0x59, bytes[0]);
    ASSERT_EQ(0x7B, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF16BE_koala) {
    UnicodeEncoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(0xD8, bytes[0]);
    ASSERT_EQ(0x3D, bytes[1]);
    ASSERT_EQ(0xDC, bytes[2]);
    ASSERT_EQ(0x28, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32_charA) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0x61, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32_charAE) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(0xE6, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32_charSpecialT) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(0x63, bytes[0]);
    ASSERT_EQ(0x1, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32_sigma) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(0xA3, bytes[0]);
    ASSERT_EQ(0x3, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32_syriacSemkath) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(0x23, bytes[0]);
    ASSERT_EQ(0x7, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32_fullBlock) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(0x88, bytes[0]);
    ASSERT_EQ(0x25, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32_cjk) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(0x7B, bytes[0]);
    ASSERT_EQ(0x59, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32_koala) {
    UTF32Encoding encoding(false);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(0x28, bytes[0]);
    ASSERT_EQ(0xF4, bytes[1]);
    ASSERT_EQ(0x1, bytes[2]);
    ASSERT_EQ(0, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32BE_charA) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charA, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0x61, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32BE_charAE) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charAE, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0, bytes[2]);
    ASSERT_EQ(0xE6, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32BE_charSpecialT) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(charSpecialT, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0x1, bytes[2]);
    ASSERT_EQ(0x63, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32BE_sigma) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(sigma, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0x3, bytes[2]);
    ASSERT_EQ(0xA3, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32BE_syriacSemkath) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(syriacSemkath, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0x7, bytes[2]);
    ASSERT_EQ(0x23, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32BE_fullBlock) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(fullBlock, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0x25, bytes[2]);
    ASSERT_EQ(0x88, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32BE_cjk) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(cjk, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0, bytes[1]);
    ASSERT_EQ(0x59, bytes[2]);
    ASSERT_EQ(0x7B, bytes[3]);
  }
  
  TEST(EncoderTest, Encode_UTF32BE_koala) {
    UTF32Encoding encoding(true);
    refptr<Encoding::Encoder> encoder = encoding.CreateEncoder();
    byte bytes[4];
    
    ResetBytes(bytes);
    encoder->Encode(koala, bytes);
    ASSERT_EQ(0, bytes[0]);
    ASSERT_EQ(0x1, bytes[1]);
    ASSERT_EQ(0xF4, bytes[2]);
    ASSERT_EQ(0x28, bytes[3]);
  }
  
}
