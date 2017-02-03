#include <Pcf/System/IO/StreamWriter.h>
#include <Pcf/System/Text/ANSIEncoding.h>
#include <Pcf/System/Text/ASCIIEncoding.h>
#include <Pcf/System/Text/UnicodeEncoding.h>
#include <Pcf/System/Text/UTF32Encoding.h>
#include <Pcf/System/Text/UTF8Encoding.h>
#include <Pcf/System/IO/StreamReader.h>
#include <Pcf/System/IO/Directory.h>
#include <Pcf/System/IO/File.h>
#include <Pcf/System/IO/Path.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

#undef in

using namespace System;
using namespace System::IO;
using namespace TUnit;

// To use a test fixture, derive a class from testing::Test.  
class StreamReaderWriter : public testing::Test {  
protected: 

  void SetUp() override {
    PathWorkDir = IO::Path::Combine(IO::Directory::GetCurrentDirectory(), "StreamRWTest");
    if (IO::Directory::Exists(PathWorkDir))
      IO::Directory::Delete(PathWorkDir, true);
    IO::Directory::CreateDirectory(PathWorkDir);
    fileName = IO::Path::Combine(PathWorkDir ,"TestFile.txt");

    if (File::Exists(fileName))
      File::Delete(fileName);
  }    

  void TearDown() override {
    IO::Directory::Delete(PathWorkDir, true);
  }

  void Test_StreamReader_With_Encoding(const string& raw, sp<Text::Encoding> encoding) {
    string decoded;

    pcf_using(StreamReader sr(fileName, encoding)) {
      decoded  = sr.ReadLine() + Environment::NewLine;
      decoded += sr.ReadLine() + Environment::NewLine;
      decoded += sr.ReadLine() + Environment::NewLine;
      decoded += sr.ReadLine() + Environment::NewLine;
    }

    EXPECT_EQ(decoded.Length(), raw.Length());

    int index = 0;
    Collections::Generic::Enumerator<char32> it = raw.GetEnumerator();
    for (char32 c : decoded) {
      it.MoveNext();
      char32 rc = it.Current;
      ASSERT_EQ(rc,c);
      index++;
    }
    EXPECT_TRUE(raw.Equals(decoded));
  }

  void CreateMultiLineBytes(Array<byte>& bytes, const Array<byte>& src, sp<Text::Encoding> encoding) {
    int32 index = bytes.Length;
    Array<byte> eolBytes = encoding->GetBytes(Environment::NewLine);
    Array<byte>::Resize(bytes, index + src.Length + eolBytes.Length);
    src.CopyTo(0,bytes,index,src.Length);
    index += src.Length;
    eolBytes.CopyTo(0,bytes,index,eolBytes.Length);
  }

  void CheckFileBytes(const Array<byte>& bytes) {
    std::fstream in;
    in.open(fileName.ToCCharArray().Data(), std::fstream::binary | std::fstream::in);
    ASSERT_TRUE(in.is_open());
    
    in.seekg(0, std::ios::end);
    std::fstream::streamoff rawSize = in.tellg();
    EXPECT_EQ(bytes.Length, (int32)rawSize);
    up<byte[]> raw(new byte[static_cast<uint32>(rawSize)]);
    in.seekg(0, std::ios::beg);
    in.read((char*)(byte*)raw.ToPointer(), rawSize);
    in.close();
   
    for (int32 i = 0; i < bytes.Length; i++)
      ASSERT_EQ(bytes[i], raw[i]);
  }

  void Test_StreamWriter_With_Encoding(const Array<byte>& raw, sp<Text::Encoding> encoding) {
    //string unicode("Pi (" + Char(928) + ")\nSigma (" + Char(931) + ")\n Koala (" + Char(128040) + ")");
  
    string piString("Pi (" + Char(928) + ")");
    string sigmaString("Sigma (" + Char(931) + ")");
    string koalaString("Koala (" + Char(128040) + ")");
    string asciiString = "Un " + Char(233) + "l" + Char(232) + "ve "+Char(224)+" l'ou"+Char(239)+"e fine";

    pcf_using(StreamWriter sw(fileName, false, encoding)) {
      sw.WriteLine(piString);
      sw.WriteLine(sigmaString);
      sw.WriteLine(koalaString);
      sw.WriteLine(asciiString);
    }

    CheckFileBytes(raw);  
  }

  // Declares the variables your tests want to use.  
  string PathWorkDir;
  string fileName;
};  

namespace {

struct CharBuffer {
public:
  CharBuffer(int w, int h) : chars(w*h) {
    width = w;
    height = h;
  }

  char32& operator()(int32 x, int32 y) {
    return chars[x + y * width];
  }

  Array<char32> chars;
  int32 width;
  int32 height;
};

struct Rect {
public:
  Rect(int32 x, int32 y, int32 w, int32 h) {
    this->x = x;
    this->y = y;
    width = w;
    height = h;
  }

  int32 x, y, width, height;
};

struct RectCharPattern {
public:
  RectCharPattern(char32 lu, char32 u, char32 ru, char32 l, char32 r, char32 ld, char32 d, char32 rd) {
    leftUp = lu;
    up = u;
    rightUp = ru;
    left = l;
    right = r;
    leftDown = ld;
    down = d;
    rightDown = rd;
  }

  char32 leftUp, up, rightUp;
  char32 left, right;
  char32 leftDown, down, rightDown;
};

void FillRect(CharBuffer& chars, char32 c, const Rect& rect) {
  for (int32 y = rect.y; y < rect.y + rect.height ; y += 1)
    for (int32 x = rect.x; x < rect.x + rect.width ; x += 1)
      chars(x,y) = c;
}

void DrawRect(CharBuffer& chars, const RectCharPattern& pattern, const Rect& rect) {
  for (int32 y = rect.y; y < rect.y + rect.height ; y += 1) {
    if (y == rect.y) {
      chars(rect.x, y) = pattern.leftUp;
      for (int32 x = rect.x + 1; x < (rect.x + rect.width) - 1 ; x += 1)
        chars(x,y) = pattern.up;
      chars(rect.x + rect.width-1, y) = pattern.rightUp;
    } else if (y == rect.y + rect.height - 1) {
      chars(rect.x, y) = pattern.leftDown;
      for (int32 x = rect.x + 1; x < (rect.x + rect.width) - 1 ; x += 1)
        chars(x,y) = pattern.down;
      chars(rect.x + rect.width-1, y) = pattern.rightDown;
    } else {
      chars(rect.x, y) = pattern.left;
      chars(rect.x + rect.width-1, y) = pattern.right;    
    }
  }
}
} // namespace

TEST_F(StreamReaderWriter, Create_CodePage437_File) {
  sp<FileStream> fs = new FileStream(fileName, FileMode(FileMode::Create), FileAccess(FileAccess::Write), FileShare(FileShare::None));
  StreamWriter sw(fs.ChangeType<Stream>(), sp<Text::Encoding>(Text::Encoding::CreateEncoding(437).Release()));

  RectCharPattern doubleLine(0x2554, 0x2550, 0x2557, 0x2551, 0x2551, 0x255A, 0x2550, 0x255D);
  RectCharPattern simpleLine(0x250C, 0x2500, 0x2510, 0x2502, 0x2502, 0x2514, 0x2500, 0x2518);

  CharBuffer charBuffer(80,30);
  FillRect(charBuffer, 32, Rect(0,0,80,30));
  DrawRect(charBuffer, simpleLine, Rect(11,11,50,10));
  DrawRect(charBuffer, doubleLine, Rect(10,10,50,10));
  charBuffer(11,19) = 0x256A;
  
  for (int32 i = 0; i < 30; i += 1) {
    string line = string(charBuffer.chars.Data, charBuffer.chars.Length,  i * 80 , 80);
    sw.WriteLine(line);
  }
  sw.Close();
}

TEST_F(StreamReaderWriter, Create_UTF8_File)  {
  sp<Text::Encoding> encoding(Text::Encoding::UTF8());

  byte piBytes[]    = { 0x50, 0x69, 0x20,                     0x28,   0xCE, 0xA0,               0x29 };
  byte sigmaBytes[] = { 0x53, 0x69, 0x67, 0x6D, 0x61, 0x20,   0x28,   0xCE, 0xA3,               0x29 };
  byte koalaBytes[] = { 0x4B, 0x6F, 0x61, 0x6C, 0x61, 0x20,   0x28,   0xF0, 0x9F, 0x90, 0xA8,   0x29 };
  byte asciiBytes[] = { 85, 110, 32, 195, 169, 108, 195, 168, 118, 101, 32, 195, 160, 32, 108, 39, 111, 117, 195, 175, 101, 32, 102, 105, 110, 101 };

  Array<byte> raw(0);
  CreateMultiLineBytes(raw, piBytes, encoding);
  CreateMultiLineBytes(raw, sigmaBytes, encoding);
  CreateMultiLineBytes(raw, koalaBytes, encoding);
  CreateMultiLineBytes(raw, asciiBytes, encoding);

  Test_StreamWriter_With_Encoding(raw, encoding );

  string expectedString("Pi ("+Char(928)+")" + Environment::NewLine
    + "Sigma ("+ Char(931) +")" + Environment::NewLine
    + "Koala (" + Char(128040) + ")" + Environment::NewLine
    + "Un " + Char(233) + "l" + Char(232) + "ve "+Char(224)+" l'ou"+Char(239)+"e fine" + Environment::NewLine);

  Test_StreamReader_With_Encoding(expectedString, encoding);
}

TEST_F(StreamReaderWriter, Create_UTF16_File)  {
  sp<Text::Encoding> encoding(Text::Encoding::Unicode());

  //string unicode("Pi (" + Char(928) + ")\nSigma (" + Char(931) + ")\n Koala (" + Char(128040) + ")");
  byte piBytes[]    = { 80, 0, 105, 0, 32, 0, 40, 0, 160, 3, 41, 0 };
  byte sigmaBytes[] = { 83, 0, 105, 0, 103, 0, 109, 0, 97, 0, 32, 0, 40, 0, 163, 3, 41, 0 };
  byte koalaBytes[] = { 75, 0, 111, 0, 97, 0, 108, 0, 97, 0, 32, 0, 40, 0, 61, 216, 40, 220, 41, 0 };
  byte asciiBytes[] = { 85, 0, 110, 0, 32, 0, 233, 0, 108, 0, 232, 0, 118, 0, 101, 0, 32, 0, 224, 0, 
    32, 0, 108, 0, 39, 0, 111, 0, 117, 0, 239, 0, 101, 0, 32, 0, 102, 0, 105, 0, 110, 0, 101, 0 };

  Array<byte> raw(0);
  CreateMultiLineBytes(raw, piBytes, encoding);
  CreateMultiLineBytes(raw, sigmaBytes, encoding);
  CreateMultiLineBytes(raw, koalaBytes, encoding);
  CreateMultiLineBytes(raw, asciiBytes, encoding);

  Test_StreamWriter_With_Encoding(raw, encoding );

  string expectedString("Pi (" + Char(928) + ")" + Environment::NewLine
    + "Sigma (" + Char(931) + ")" + Environment::NewLine
    + "Koala (" + Char(128040) + ")" + Environment::NewLine
    + "Un " + Char(233) + "l" + Char(232) + "ve "+ Char(224) + " l'ou" + Char(239) + "e fine" + Environment::NewLine);

  Test_StreamReader_With_Encoding(expectedString, encoding);
}

TEST_F(StreamReaderWriter, Create_UTF16BE_File)  {
  sp<Text::Encoding> encoding = new Text::UnicodeEncoding(true,true);

  //string unicode("Pi (" + Char(928) + ")\nSigma (" + Char(931) + ")\n Koala (" + Char(128040) + ")");
  byte piBytes[]    = { 0, 80, 0, 105, 0, 32, 0, 40, 3, 160, 0, 41 };
  byte sigmaBytes[] = { 0, 83, 0, 105, 0, 103, 0, 109, 0, 97, 0, 32, 0, 40, 3, 163, 0, 41 };
  byte koalaBytes[] = { 0, 75, 0, 111, 0, 97, 0, 108, 0, 97, 0, 32, 0, 40, 216, 61, 220, 40, 0, 41 };
  byte asciiBytes[] = { 0, 85, 0, 110, 0, 32, 0, 233, 0, 108, 0, 232, 0, 118, 0, 101, 0, 32, 0, 224, 0, 
    32, 0, 108, 0, 39, 0, 111, 0, 117, 0, 239, 0, 101, 0, 32, 0, 102, 0, 105, 0, 110, 0, 101 };

  Array<byte> raw(0);
  CreateMultiLineBytes(raw, piBytes, encoding);
  CreateMultiLineBytes(raw, sigmaBytes, encoding);
  CreateMultiLineBytes(raw, koalaBytes, encoding);
  CreateMultiLineBytes(raw, asciiBytes, encoding);

  Test_StreamWriter_With_Encoding(raw, encoding );
  
  string expectedString("Pi ("+Char(928)+")" + Environment::NewLine
    + "Sigma ("+ Char(931) +")" + Environment::NewLine
    + "Koala (" + Char(128040) + ")" + Environment::NewLine
    + "Un " + Char(233) + "l" + Char(232) + "ve "+Char(224)+" l'ou"+Char(239)+"e fine" + Environment::NewLine);

  Test_StreamReader_With_Encoding(expectedString, encoding);
}

TEST_F(StreamReaderWriter, Create_UTF32_File)  {
  sp<Text::Encoding> encoding = new Text::UTF32Encoding(false,true);

  //string unicode("Pi (" + Char(928) + ")\nSigma (" + Char(931) + ")\n Koala (" + Char(128040) + ")");
  byte piBytes[]    = { 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 0, 160, 3, 0, 0, 41, 0, 0, 0 };
  byte sigmaBytes[] = { 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 0, 163, 3, 0, 0, 41, 0, 0, 0 };
  byte koalaBytes[] = { 75, 0, 0, 0, 111, 0, 0, 0, 97, 0, 0, 0, 108, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 0, 40, 244, 1, 0, 41, 0, 0, 0 };
  byte asciiBytes[] = { 85, 0, 0, 0, 110, 0, 0, 0, 32, 0, 0, 0, 233, 0, 0, 0, 108, 0, 0, 0, 232, 0, 0, 0, 118, 0, 0, 0, 
    101, 0, 0, 0, 32, 0, 0, 0, 224, 0, 0, 0, 32, 0, 0, 0, 108, 0, 0, 0, 39, 0, 0, 0, 111, 0, 0, 0, 117, 0, 0, 0, 239, 0, 0, 0, 
    101, 0, 0, 0, 32, 0, 0, 0, 102, 0, 0, 0, 105, 0, 0, 0, 110, 0, 0, 0, 101, 0, 0, 0 };

  Array<byte> raw(0);
  CreateMultiLineBytes(raw, piBytes, encoding);
  CreateMultiLineBytes(raw, sigmaBytes, encoding);
  CreateMultiLineBytes(raw, koalaBytes, encoding);
  CreateMultiLineBytes(raw, asciiBytes, encoding);

  Test_StreamWriter_With_Encoding(raw, encoding );

  string expectedString("Pi ("+Char(928)+")" + Environment::NewLine
    + "Sigma ("+ Char(931) +")" + Environment::NewLine
    + "Koala (" + Char(128040) + ")" + Environment::NewLine
    + "Un " + Char(233) + "l" + Char(232) + "ve "+Char(224)+" l'ou"+Char(239)+"e fine" + Environment::NewLine);

  Test_StreamReader_With_Encoding(expectedString, encoding);
}

TEST_F(StreamReaderWriter, Create_UTF32BE_File)  {
  sp<Text::Encoding> encoding = new Text::UTF32Encoding(true,true);

  //string unicode("Pi (" + Char(928) + ")\nSigma (" + Char(931) + ")\n Koala (" + Char(128040) + ")");
  byte piBytes[]    = { 0, 0, 0, 80, 0, 0, 0, 105, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 3, 160, 0, 0, 0, 41 };
  byte sigmaBytes[] = { 0, 0, 0, 83, 0, 0, 0, 105, 0, 0, 0, 103, 0, 0, 0, 109, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 3, 163, 0, 0, 0, 41 };
  byte koalaBytes[] = { 0, 0, 0, 75, 0, 0, 0, 111, 0, 0, 0, 97, 0, 0, 0, 108, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, 40, 0, 1, 244, 40, 0, 0, 0, 41 };  
  byte asciiBytes[] = { 0, 0, 0, 85, 0, 0, 0, 110, 0, 0, 0, 32, 0, 0, 0, 233, 0, 0, 0, 108, 0, 0, 0, 232, 0, 0, 0, 118, 
    0, 0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 224, 0, 0, 0, 32, 0, 0, 0, 108, 0, 0, 0, 39, 0, 0, 0, 111, 0, 0, 0, 117, 0, 0, 0, 239, 
    0, 0, 0, 101, 0, 0, 0, 32, 0, 0, 0, 102, 0, 0, 0, 105, 0, 0, 0, 110, 0, 0, 0, 101 };

  Array<byte> raw(0);
  CreateMultiLineBytes(raw, piBytes, encoding);
  CreateMultiLineBytes(raw, sigmaBytes, encoding);
  CreateMultiLineBytes(raw, koalaBytes, encoding);
  CreateMultiLineBytes(raw, asciiBytes, encoding);

  Test_StreamWriter_With_Encoding(raw, encoding );

  string expectedString("Pi ("+Char(928)+")" + Environment::NewLine
    + "Sigma ("+ Char(931) +")" + Environment::NewLine
    + "Koala (" + Char(128040) + ")" + Environment::NewLine
    + "Un " + Char(233) + "l" + Char(232) + "ve "+Char(224)+" l'ou"+Char(239)+"e fine" + Environment::NewLine);

  Test_StreamReader_With_Encoding(expectedString, encoding);
}

TEST_F(StreamReaderWriter, Create_ASCII_File)  {
  sp<Text::Encoding> encoding = new Text::ASCIIEncoding();

  //string unicode("Pi (" + Char(928) + ")\nSigma (" + Char(931) + ")\n Koala (" + Char(128040) + ")");
  byte piBytes[]    = { 80, 105, 32, 40, 63, 41 };
  byte sigmaBytes[] = { 83, 105, 103, 109, 97, 32, 40, 63, 41 };
  byte koalaBytes[] = { 75, 111, 97, 108, 97, 32, 40, 63, 41 };
  byte asciiBytes[] = { 85, 110, 32, 63, 108, 63, 118, 101, 32, 63, 32, 108, 39, 111, 117, 63, 101, 32, 102, 105, 110, 101 };

  Array<byte> raw(0);
  CreateMultiLineBytes(raw, piBytes, encoding);
  CreateMultiLineBytes(raw, sigmaBytes, encoding);
  CreateMultiLineBytes(raw, koalaBytes, encoding);
  CreateMultiLineBytes(raw, asciiBytes, encoding);

  Test_StreamWriter_With_Encoding(raw, encoding );

  string expectedString("Pi (?)" + Environment::NewLine
    + "Sigma (?)" + Environment::NewLine
    + "Koala (?)" + Environment::NewLine
    + "Un ?l?ve ? l'ou?e fine" + Environment::NewLine);

  Test_StreamReader_With_Encoding(expectedString, encoding);
}

TEST_F(StreamReaderWriter, Create_CP437_File)  {
  sp<Text::Encoding> encoding(Text::Encoding::CreateEncoding(437));

  //string unicode("Pi (" + Char(928) + ")\nSigma (" + Char(931) + ")\n Koala (" + Char(128040) + ")");
  byte piBytes[]    = { 80, 105, 32, 40, 227, 41 };
  byte sigmaBytes[] = { 83, 105, 103, 109, 97, 32, 40, 228, 41 };
  byte koalaBytes[] = { 75, 111, 97, 108, 97, 32, 40, 63, 41 };
  byte asciiBytes[] = { 85, 110, 32, 130, 108, 138, 118, 101, 32, 133, 32, 108, 39, 111, 117, 139, 101, 32, 102, 105, 110, 101 };

  Array<byte> raw(0);
  CreateMultiLineBytes(raw, piBytes, encoding);
  CreateMultiLineBytes(raw, sigmaBytes, encoding);
  CreateMultiLineBytes(raw, koalaBytes, encoding);
  CreateMultiLineBytes(raw, asciiBytes, encoding);

  Test_StreamWriter_With_Encoding(raw, encoding );

  string expectedString("Pi ("+Char(0x03c0)+")" + Environment::NewLine
    + "Sigma ("+ Char(931) +")" + Environment::NewLine
    + "Koala (?)" + Environment::NewLine
    + "Un " + Char(233) + "l" + Char(232) + "ve "+Char(224)+" l'ou"+Char(239)+"e fine" + Environment::NewLine);

  Test_StreamReader_With_Encoding(expectedString, encoding);
}

TEST_F(StreamReaderWriter, Create_ISO_8859_1_File)  {
  sp<Text::Encoding> encoding(Text::Encoding::CreateEncoding("iso-8859-1"));

  //string unicode("Pi (" + Char(928) + ")\nSigma (" + Char(931) + ")\n Koala (" + Char(128040) + ")");
  byte piBytes[]    = { 80, 105, 32, 40, 63, 41 };
  byte sigmaBytes[] = { 83, 105, 103, 109, 97, 32, 40, 63, 41 };
  byte koalaBytes[] = { 75, 111, 97, 108, 97, 32, 40, 63, 41 };
  byte asciiBytes[] = { 85, 110, 32, 233, 108, 232, 118, 101, 32, 224, 32, 108, 39, 111, 117, 239, 101, 32, 102, 105, 110, 101 };
            //          U   n     _    é    l    è    v    e   _    à   _    l   '    o    u    ï    e   _    f    i    n    e
  Array<byte> raw(0);
  CreateMultiLineBytes(raw, piBytes, encoding);
  CreateMultiLineBytes(raw, sigmaBytes, encoding);
  CreateMultiLineBytes(raw, koalaBytes, encoding);
  CreateMultiLineBytes(raw, asciiBytes, encoding);

  Test_StreamWriter_With_Encoding(raw, encoding );

  string expectedString("Pi (?)" + Environment::NewLine
    + "Sigma (?)" + Environment::NewLine
    + "Koala (?)" + Environment::NewLine
    + "Un " + Char(233) + "l" + Char(232) + "ve "+Char(224)+" l'ou"+Char(239)+"e fine" + Environment::NewLine);

  Test_StreamReader_With_Encoding(expectedString, encoding);
}

TEST_F(StreamReaderWriter, UTF8Builder)  {
    //                K     o     a     l     a     _       (       .     .     .     .       )
  byte bytes[] = { 0x4B, 0x6F, 0x61, 0x6C, 0x61, 0x20,   0x28,   0xF0, 0x9F, 0x90, 0xA8,   0x29 };

  Text::UTF8Encoding::Decoder decoder;

  int index = 0;
  
  decoder.Add(bytes[index++]); 
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U'K', decoder.CodePoint());

  decoder.Add(bytes[index++]); 
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U'o', decoder.CodePoint());

  decoder.Add(bytes[index++]); 
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U'a', decoder.CodePoint());

  decoder.Add(bytes[index++]); 
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U'l', decoder.CodePoint());
  
  decoder.Add(bytes[index++]);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U'a', decoder.CodePoint());

  decoder.Add(bytes[index++]); 
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U' ', decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U'(', decoder.CodePoint());

  decoder.Add(bytes[index++]); 
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); 
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); 
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); 
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(128040u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U')', decoder.CodePoint());
}

TEST_F(StreamReaderWriter, UTF16Builder)  {
  //                 2       4      6      8      10     12     14       16       18     20
  byte bytes[] = { 75, 0, 111, 0, 97, 0, 108, 0, 97, 0, 32, 0, 40, 0, 61, 216, 40, 220, 41, 0 };

  Text::UnicodeEncoding::Decoder decoder(false);

  int index = 0;
  
  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); //2
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(75u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 4
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(111u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 6
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 8
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(108u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 10
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 12
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(32u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 14
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(40u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 16
  EXPECT_FALSE(decoder.CodePointDefined());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 18
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(128040u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 20
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(41u, decoder.CodePoint());
}

TEST_F(StreamReaderWriter, UTF16Builder_be)  {
    //                 2       4      6      8      10     12     14       16       18     20
  byte bytes[] = { 0, 75, 0, 111, 0, 97, 0, 108, 0, 97, 0, 32, 0, 40, 216, 61, 220, 40, 0, 41 };

  Text::UnicodeEncoding::Decoder decoder(true);

  int index = 0;
  
  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); //2
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(75u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 4
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(111u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 6
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 8
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(108u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 10
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 12
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(32u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 14
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(40u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 16
  EXPECT_FALSE(decoder.CodePointDefined());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 18
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(128040u, decoder.CodePoint());

  decoder.Add(bytes[index++]);
  EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 20
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(41u, decoder.CodePoint());
}

TEST_F(StreamReaderWriter, UTF32Builder)  {
    //                       4             8           12            16           20           24           28             32           36
  byte bytes[] = { 75, 0, 0, 0, 111, 0, 0, 0, 97, 0, 0, 0, 108, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, 40, 0, 0, 0, 40, 244, 1, 0, 41, 0, 0, 0 };

  Text::UTF32Encoding::Decoder decoder(false);

  int index = 0;
  
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 'K'
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(75u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 'o'
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(111u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // a
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // l
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(108u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // a
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // ' '
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(32u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // (
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(40u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // ?
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(128040u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // )
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(41u, decoder.CodePoint());
}

TEST_F(StreamReaderWriter, UTF32Builder_be)  {
    //                       4             8           12            16           20           24           28             32           36
  byte bytes[] = { 0, 0, 0, 75, 0, 0, 0, 111, 0, 0, 0, 97, 0, 0, 0, 108, 0, 0, 0, 97, 0, 0, 0, 32, 0, 0, 0, 40, 0, 1, 244, 40, 0, 0, 0, 41 };  

  Text::UTF32Encoding::Decoder decoder(true);
  int index = 0;
  
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 'K'
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(75u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // 'o'
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(111u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // a
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // l
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(108u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // a
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // ' '
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(32u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // (
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(40u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // ?
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(128040u, decoder.CodePoint());

  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); EXPECT_FALSE(decoder.CodePointDefined());
  decoder.Add(bytes[index++]); // )
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(41u, decoder.CodePoint());
}

TEST_F(StreamReaderWriter, ASCIIBuilder) {
    //                K     o     a     l     a     _       (     ?       )
  byte bytes[] = { 0x4B, 0x6F, 0x61, 0x6C, 0x61, 0x20,   0x28,   63,   0x29 };

  Text::ASCIIEncoding::Decoder decoder;

  int index = 0;
  decoder.Add(bytes[index++]); // 'K'
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(75u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // 'o'
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(111u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // a
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // l
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(108u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // a
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(97u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // ' '
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(32u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // (
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(40u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // ?
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U'?', decoder.CodePoint());

  decoder.Add(bytes[index++]); // )
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(41u, decoder.CodePoint());
}

TEST_F(StreamReaderWriter, CodePage437Builder) {
  byte bytes[] = { 179, 'K', 130, 224 };

  Text::CodePage437Encoding::Decoder decoder;

  int index = 0;
  decoder.Add(bytes[index++]); // |
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(0x2502u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // K
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(U'K', decoder.CodePoint());

  decoder.Add(bytes[index++]); // é
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(0x00E9u, decoder.CodePoint());

  decoder.Add(bytes[index++]); // alpha
  EXPECT_TRUE(decoder.CodePointDefined());
  EXPECT_EQ(0x03B1u, decoder.CodePoint());
}
#ifndef _WIN32_WCE
TEST_F(StreamReaderWriter, CodePageIso_Latin_1_Builder)  {
    //                
  byte bytes[] = { 85, 110, 32, 233, 108, 232, 118, 101, 32, 224, 32, 108, 39, 111, 117, 239, 101, 32, 102, 105, 110, 101 };

  Text::CodePage28591Encoding::Decoder decoder;

  int index = 0;
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(85u,decoder.CodePoint());   // U
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(110u, decoder.CodePoint()); // n
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(32u, decoder.CodePoint());  //
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(233u, decoder.CodePoint()); // é
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(108u, decoder.CodePoint()); // l
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(232u, decoder.CodePoint()); // è
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(118u, decoder.CodePoint()); // v
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(101u, decoder.CodePoint()); // e
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(32u, decoder.CodePoint());  //
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(224u, decoder.CodePoint()); // à
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(32u, decoder.CodePoint());  //
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(108u, decoder.CodePoint()); // l
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(39u, decoder.CodePoint());  // '
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(111u, decoder.CodePoint()); // o
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(117u, decoder.CodePoint()); // u
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(239u, decoder.CodePoint()); // ï
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(101u, decoder.CodePoint()); // e
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(32u, decoder.CodePoint());  //
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(102u, decoder.CodePoint()); // f
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(105u, decoder.CodePoint()); // i
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(110u, decoder.CodePoint()); // n
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(101u, decoder.CodePoint()); // e
}

TEST_F(StreamReaderWriter, CodePageIso_Latin_2_Builder) {
    //                
  byte bytes[] = { 85, 110, 32, 233, 108, 232, 118, 101, 32, 224, 32, 108, 39, 111, 117, 239, 101, 32, 102, 105, 110, 101 };

  Text::CodePage28592Encoding::Decoder decoder;

  int index = 0;
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(85u,decoder.CodePoint());   // U
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(110u, decoder.CodePoint()); // n
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(32u, decoder.CodePoint());  //
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(233u, decoder.CodePoint()); // é
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(108u, decoder.CodePoint()); // l
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(0x010Du, decoder.CodePoint()); // č
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(118u, decoder.CodePoint()); // v
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(101u, decoder.CodePoint()); // e
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(32u, decoder.CodePoint());  //
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(0x0155u, decoder.CodePoint()); // ŕ
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(32u, decoder.CodePoint());  //
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(108u, decoder.CodePoint()); // l
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(39u, decoder.CodePoint());  // '
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(111u, decoder.CodePoint()); // o
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(117u, decoder.CodePoint()); // u
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(0x010Fu, decoder.CodePoint()); // ď
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(101u, decoder.CodePoint()); // e
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(32u, decoder.CodePoint());  //
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(102u, decoder.CodePoint()); // f
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(105u, decoder.CodePoint()); // i
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(110u, decoder.CodePoint()); // n
  decoder.Add(bytes[index++]); EXPECT_TRUE(decoder.CodePointDefined()); EXPECT_EQ(101u, decoder.CodePoint()); // e
}
#endif
