#include <Switch/System/String.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

TEST(String, Format) {
  EXPECT_EQ("0", 
    String::Format("{0}","0"));
  EXPECT_EQ("0, 1", 
    String::Format("{0}, {1}","0", "1"));
  EXPECT_EQ("0, 1, 2", 
    String::Format("{0}, {1}, {2}","0", "1", "2"));
  EXPECT_EQ("0, 1, 2, 3", 
    String::Format("{0}, {1}, {2}, {3}","0", "1", "2", "3"));
  EXPECT_EQ("0, 1, 2, 3, 4", 
    String::Format("{0}, {1}, {2}, {3}, {4}","0", "1", "2", "3", "4"));
  EXPECT_EQ("0, 1, 2, 3, 4, 5", 
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}","0", "1", "2", "3", "4", "5"));
  EXPECT_EQ("0, 1, 2, 3, 4, 5, 6", 
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}","0", "1", "2", "3", "4", "5", "6"));
  EXPECT_EQ("0, 1, 2, 3, 4, 5, 6, 7", 
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}","0", "1", "2", "3", "4", "5", "6", "7"));
  EXPECT_EQ("0, 1, 2, 3, 4, 5, 6, 7, 8", 
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}","0", "1", "2", "3", "4", "5", "6", "7", "8"));
  EXPECT_EQ("0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}","0", "1", "2", "3", "4", "5", "6", "7", "8", "9"));
}

TEST(String, Format_BraceMismatch) {
  EXPECT_THROW(String::Format("{"), FormatException);
  EXPECT_THROW(String::Format("}"), FormatException);
  EXPECT_THROW(String::Format("{{}"), FormatException);
  EXPECT_THROW(String::Format("}{"), FormatException);
  EXPECT_THROW(String::Format("{}"), FormatException);

  EXPECT_THROW(String::Format("{{0}", 5), FormatException);
  EXPECT_THROW(String::Format("}{0}", 5), FormatException);
  EXPECT_THROW(String::Format("{{}{0}",5), FormatException);
  EXPECT_THROW(String::Format("}{{0}",5), FormatException);
  EXPECT_THROW(String::Format("{}{0}",5), FormatException);

  EXPECT_THROW(String::Format("{0}{{1}", 5, "string"), FormatException);
  EXPECT_THROW(String::Format("}{0}{1}", 5, String("string")), FormatException);
  EXPECT_THROW(String::Format("{{}{0}{1}","string", 12), FormatException);
  EXPECT_THROW(String::Format("}{{0}{1}","string", true), FormatException);
  EXPECT_THROW(String::Format("{}{0{1}}",5, 12u), FormatException);
}

TEST(String, Format_ConsoleBraceMismatch) {
  try {
    Console::SetOut(System::IO::TextWriter::Null);

    Console::WriteLine("{");
    Console::WriteLine("}");
    Console::WriteLine("{{}");
    Console::WriteLine("}{");
    Console::WriteLine("{}");

    EXPECT_THROW(Console::WriteLine("{{0}", 5), FormatException);
    EXPECT_THROW(Console::WriteLine("}{0}", 5), FormatException);
    EXPECT_THROW(Console::WriteLine("{{}{0}",5), FormatException);
    EXPECT_THROW(Console::WriteLine("}{{0}",5), FormatException);
    EXPECT_THROW(Console::WriteLine("{}{0}",5), FormatException);

    EXPECT_THROW(Console::WriteLine("{0}{{1}", 5, "string"), FormatException);
    EXPECT_THROW(Console::WriteLine("}{0}{1}", 5, String("string")), FormatException);
    EXPECT_THROW(Console::WriteLine("{{}{0}{1}","string", 12), FormatException);
    EXPECT_THROW(Console::WriteLine("}{{0}{1}","string", true), FormatException);
    EXPECT_THROW(Console::WriteLine("{}{0{1}}",5, 12u), FormatException);

    Console::SetOut(Console::Out);
  } catch(Exception& x) {
    Console::SetOut(Console::Out);
    Console::WriteLine(x.ToString());
  }
}

TEST(String, Format_ToString) {
  EXPECT_EQ("123", Byte(123).ToString());
  EXPECT_EQ("123", SByte(123).ToString());
  EXPECT_EQ("123", Int16(123).ToString());
  EXPECT_EQ("123", UInt16(123).ToString());
  EXPECT_EQ("123", Int32(123).ToString());
  EXPECT_EQ("123", UInt32(123).ToString());
  EXPECT_EQ("123", Int64(123).ToString());
  EXPECT_EQ("123", UInt64(123).ToString());
  EXPECT_EQ("123", String("123").ToString());
  EXPECT_EQ("123", Double(123.0).ToString());
  EXPECT_EQ("123", Single(123.0f).ToString());
  EXPECT_EQ("a", Char('a').ToString());
}

TEST(String, Format_CustomFormatting) {
/*  EXPECT_EQ("minus 15", String::Format("{0:#;minus #}", -15));
  EXPECT_EQ("zero", String::Format("{0:#;minus #;zero}", 0));
  EXPECT_EQ("+447 900 123 456", String::Format("{0:+### ### ### ###}", 447900123456));
  EXPECT_EQ("89-5871-2551", String::Format("{0:##-####-####}", 8958712551));
  EXPECT_EQ("00015", String::Format("{0:00000}", 15));
  EXPECT_EQ("-00015", String::Format("{0:00000}", -15));
  EXPECT_EQ("-", String::Format("{0:-}", 123456));
  EXPECT_EQ("a123456", String::Format("{0:a#}", 123456));
  EXPECT_EQ("a123456", String::Format("{0:a##}", 123456));
  EXPECT_EQ("a1", String::Format("{0:a#}", 1));
  EXPECT_EQ("a1", String::Format("{0:a##}", 1));
  EXPECT_EQ("a1", String::Format("{0:a##.#}", 1));
  EXPECT_EQ("a01.0", String::Format("{0:a0#.0}", 1));
  EXPECT_EQ("a12.0", String::Format("{0:a0#.0}", 12));
  EXPECT_EQ("ab1", String::Format("{0:a##b#}", 1));
  EXPECT_EQ("a00b1", String::Format("{0:a0#b0}", 1));
  EXPECT_EQ("a01b2", String::Format("{0:a0#b0}", 12));
  EXPECT_EQ("a1b2", String::Format("{0:a##b0}", 12));
  EXPECT_EQ("a12b3", String::Format("{0:a##b0}", 123));
  EXPECT_EQ("a1b23", String::Format("{0:a##b##}", 123));
  EXPECT_EQ("1", String::Format("{0:#0}", 1));
  EXPECT_EQ("01", String::Format("{0:0#}", 1));
  EXPECT_EQ("001", String::Format("{0:00#}", 1));
  EXPECT_EQ("012", String::Format("{0:00#}", 12));
  EXPECT_EQ("12", String::Format("{0:#0#}", 12));
  EXPECT_EQ("00012", String::Format("{0:#0####}", 12));
  EXPECT_EQ("00012", String::Format("{0:#00000}", 12));
  EXPECT_EQ("-00012", String::Format("{0:#00000}", -12));
  EXPECT_EQ("-00012", String::Format("{0:#0####}", -12));
  EXPECT_EQ("035", String::Format("{0:000}", 35.1));
  EXPECT_EQ("036", String::Format("{0:000}", 35.7));
  EXPECT_EQ("135", String::Format("{0:000}", 135.1));
  EXPECT_EQ("136", String::Format("{0:000}", 135.8));
  EXPECT_EQ("2", String::Format("{0:0}", 1.8));
  EXPECT_EQ("", String::Format("{0:#}", 0));
  EXPECT_EQ("", String::Format("{0:##}", 0));
  EXPECT_EQ(".5", String::Format("{0:##.#}", 0.5));
  EXPECT_EQ("X", String::Format("{0:X;B}", 5));
  EXPECT_EQ("B", String::Format("{0:X;B}", -5));

  EXPECT_THROW(String::Format("{0:a}", 123456), FormatException);*/
}

TEST(String, Format_FormatIndexes) {
  String str = ("tiens");
  Int32 i = 2;
  Double d = 1.0;
  EXPECT_THROW(String::Format("{0} {1} vaut mieux que {2} tu l'auras"), FormatException);
  EXPECT_THROW(String::Format("{0} {1} vaut mieux que {2} tu l'auras",d), FormatException);
  EXPECT_THROW(String::Format("{0} {1} vaut mieux que {2} tu l'auras", d, str), FormatException);
  EXPECT_EQ("1 tiens vaut mieux que 2 tu l'auras", String::Format("{0} {1} vaut mieux que {2} tu l'auras", d, str, i));
}

TEST(String, Format_Align) {
  EXPECT_EQ(String::Format("[{0,-4}]",51),     "[51  ]");
  EXPECT_EQ(String::Format("[{0,4}]",42),      "[  42]");
  EXPECT_EQ(String::Format("[{0,0}]",5),       "[5]");
  EXPECT_EQ(String::Format("[{0,1}]",5),       "[5]");
  EXPECT_EQ(String::Format("[{0,-1}]",5),      "[5]");
  EXPECT_EQ(String::Format("[{0,-6}]","left"), "[left  ]");
  EXPECT_EQ(String::Format("[{0,6}]","right"), "[ right]");

  EXPECT_EQ(String::Format("[{0,3}]","very long string"), "[very long string]");
  EXPECT_EQ(String::Format("[{0,-6}]","very long string"), "[very long string]");
  
  EXPECT_EQ(String::Format("[{0,3}]","four"), "[four]");
  EXPECT_EQ(String::Format("[{0,4}]","four"), "[four]");
  EXPECT_EQ(String::Format("[{0,5}]","four"), "[ four]");

  EXPECT_EQ(String::Format("[{0}]", Char('a')), "[a]");
}

TEST(String, Format_NoFormat) {
  EXPECT_EQ("125", String::Format("{0:}", 125));
}

TEST(String, Format_Unicode_Litteral) {
  EXPECT_EQ(String(0x1,1), String::Format("{u1}"));
  EXPECT_EQ(String(0x12,1), String::Format("{u12}"));
  EXPECT_EQ(String(0xA12,1), String::Format("{uA12}"));
  EXPECT_EQ(String(0x2FFFF,1), String::Format("{u2FFFF}"));
  EXPECT_EQ(String(0x00BB,1), String::Format("{uBB}"));
  EXPECT_EQ(String(0x00BB,1), String::Format("{u0BB}"));
  EXPECT_EQ(String(0x00BB,1), String::Format("{u00BB}"));
}

TEST(String, Format_Unicode_Litteral_Exception) {
  EXPECT_THROW(String::Format("{u}"),FormatException);
  EXPECT_THROW(String::Format("{u }"),FormatException);
}

TEST(String, Format_char32) {
  char32 c = '/';
  EXPECT_EQ("/", String::Format("{0}", c));
  EXPECT_EQ("%", String::Format("{0}", char32('%')));
}

TEST(String, Format_Pointer) {
  int32* null_ptr = null;
  int32* ptr = (int32*)0xFFFF;

  EXPECT_EQ("0", String::Format("{0}", null_ptr));
  EXPECT_EQ("65535", String::Format("{0}", ptr));
  EXPECT_EQ("FFFF", String::Format("{0:X}", ptr));
  EXPECT_EQ("0000ffff", String::Format("{0:x8}", ptr));
  EXPECT_EQ("ffff        ", String::Format("{0,-12:x}", ptr));
  EXPECT_EQ("    0000ffff", String::Format("{0,12:x8}", ptr));
  int32* ptr2 = (int32*)0xFFFFFFFF;
  EXPECT_EQ("FFFFFFFF", String::Format("{0:X}", ptr2));
}

/*

Custom Format String Test Generator

using System;
using System::Collections::Generic;
using System::Linq;
using System::Text;
using System::Threading::Tasks;
using System::Globalization;
using System::Windows::Forms;

namespace Tests {
  class Program {

    static List<String> okTests = new List<String>();
    static List<String> nokTests = new List<String>();

    [STAThread]
    static void Main(string[] args) {

      Build("{0:#;minus #}", -15);
      Build("{0:#;minus #;zero}", 0);
      Build("{0:+### ### ### ###}", 447900123456);
      Build("{0:##-####-####}", 8958712551);
      Build("{0:00000}", 15);
      Build("{0:00000}", -15);
      Build("{0:-}", 123456);
      Build("{0:a}", 123456);
      Build("{0:a#}", 123456);
      Build("{0:a##}", 123456);
      Build("{0:a#}", 1);
      Build("{0:a##}", 1);
      Build("{0:a##.#}", 1);
      Build("{0:a0#.0}", 1);
      Build("{0:a0#.0}", 12);
      Build("{0:a##b#}", 1);
      Build("{0:a0#b0}", 1);
      Build("{0:a0#b0}", 12);
      Build("{0:a##b0}", 12);
      Build("{0:a##b0}", 123);
      Build("{0:a##b##}", 123);
      Build("{0:#0}", 1);
      Build("{0:0#}", 1);
      Build("{0:00#}", 1);
      Build("{0:00#}", 12);
      Build("{0:#0#}", 12);
      Build("{0:#0####}", 12);
      Build("{0:#00000}", 12);
      Build("{0:#00000}", -12);
      Build("{0:#0####}", -12);

      Build("{0:000}", 35.1);
      Build("{0:000}", 35.7);
      Build("{0:000}", 135.1);
      Build("{0:000}", 135.8);
      Build("{0:0}", 1.8);

      Build("{0:#}", 0);
      Build("{0:##}", 0);
      Build("{0:##.#}", 0.5);
      
      Build("{0:X;B}", 5);
      Build("{0:X;B}", -5);


      String output = "";

      for (String s : okTests)
        output = output + (output==""?"":"\n") + s;
      output = output + (output == "" ? "" : "\n");
      for (String s : nokTests)
        output = output + (output == "" ? "" : "\n") + s;

      Console.WriteLine(output);
      Clipboard.SetText(output);

      Console.ReadKey();
    }

    static void Build<T>(string fmt, T value) {
      CultureInfo provider = System::Globalization::CultureInfo.CreateSpecificCulture("en-US");

      try {
        String s = String.Format(provider, "  EXPECT_EQ(\"{0}\", String::Format(\"{1}\", {2}));",
          String.Format(provider,fmt, value),
          fmt,
          String.Format(provider, "{0}", value));
        okTests.Add(s);
      } catch (FormatException) {
        String s = String.Format(provider, "  EXPECT_THROW(String::Format(\"{0}\", {1}), FormatException);",
          fmt,
          String.Format(provider,"{0}",value));
        nokTests.Add(s);
      }
    }
  }
}
*/
