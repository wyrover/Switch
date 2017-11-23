#include <Switch/System/String.hpp>
#include <Switch/System/Console.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

TEST(StringTest, Format) {
  ASSERT_EQ("0",
    String::Format("{0}", "0"));
  ASSERT_EQ("0, 1",
    String::Format("{0}, {1}", "0", "1"));
  ASSERT_EQ("0, 1, 2",
    String::Format("{0}, {1}, {2}", "0", "1", "2"));
  ASSERT_EQ("0, 1, 2, 3",
    String::Format("{0}, {1}, {2}, {3}", "0", "1", "2", "3"));
  ASSERT_EQ("0, 1, 2, 3, 4",
    String::Format("{0}, {1}, {2}, {3}, {4}", "0", "1", "2", "3", "4"));
  ASSERT_EQ("0, 1, 2, 3, 4, 5",
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}", "0", "1", "2", "3", "4", "5"));
  ASSERT_EQ("0, 1, 2, 3, 4, 5, 6",
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}", "0", "1", "2", "3", "4", "5", "6"));
  ASSERT_EQ("0, 1, 2, 3, 4, 5, 6, 7",
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}", "0", "1", "2", "3", "4", "5", "6", "7"));
  ASSERT_EQ("0, 1, 2, 3, 4, 5, 6, 7, 8",
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}", "0", "1", "2", "3", "4", "5", "6", "7", "8"));
  ASSERT_EQ("0, 1, 2, 3, 4, 5, 6, 7, 8, 9",
    String::Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"));
}

TEST(StringTest, Format_BraceMismatch) {
  ASSERT_THROW(String::Format("{"), FormatException);
  ASSERT_THROW(String::Format("}"), FormatException);
  ASSERT_THROW(String::Format("{{}"), FormatException);
  ASSERT_THROW(String::Format("}{"), FormatException);
  ASSERT_THROW(String::Format("{}"), FormatException);
  
  ASSERT_THROW(String::Format("{{0}", 5), FormatException);
  ASSERT_THROW(String::Format("}{0}", 5), FormatException);
  ASSERT_THROW(String::Format("{{}{0}", 5), FormatException);
  ASSERT_THROW(String::Format("}{{0}", 5), FormatException);
  ASSERT_THROW(String::Format("{}{0}", 5), FormatException);
  
  ASSERT_THROW(String::Format("{0}{{1}", 5, "string"), FormatException);
  ASSERT_THROW(String::Format("}{0}{1}", 5, String("string")), FormatException);
  ASSERT_THROW(String::Format("{{}{0}{1}", "string", 12), FormatException);
  ASSERT_THROW(String::Format("}{{0}{1}", "string", true), FormatException);
  ASSERT_THROW(String::Format("{}{0{1}}", 5, 12u), FormatException);
}

TEST(StringTest, Format_ConsoleBraceMismatch) {
  try {
    Console::SetOut(System::IO::TextWriter::Null());
    
    Console::WriteLine("{");
    Console::WriteLine("}");
    Console::WriteLine("{{}");
    Console::WriteLine("}{");
    Console::WriteLine("{}");
    
    ASSERT_THROW(Console::WriteLine("{{0}", 5), FormatException);
    ASSERT_THROW(Console::WriteLine("}{0}", 5), FormatException);
    ASSERT_THROW(Console::WriteLine("{{}{0}", 5), FormatException);
    ASSERT_THROW(Console::WriteLine("}{{0}", 5), FormatException);
    ASSERT_THROW(Console::WriteLine("{}{0}", 5), FormatException);
    
    ASSERT_THROW(Console::WriteLine("{0}{{1}", 5, "string"), FormatException);
    ASSERT_THROW(Console::WriteLine("}{0}{1}", 5, String("string")), FormatException);
    ASSERT_THROW(Console::WriteLine("{{}{0}{1}", "string", 12), FormatException);
    ASSERT_THROW(Console::WriteLine("}{{0}{1}", "string", true), FormatException);
    ASSERT_THROW(Console::WriteLine("{}{0{1}}", 5, 12u), FormatException);
    
    Console::SetOut(Console::Out);
  } catch (Exception& x) {
    Console::SetOut(Console::Out);
    Console::WriteLine(x.ToString());
  }
}

TEST(StringTest, Format_ToString) {
  ASSERT_EQ("123", Byte(123).ToString());
  ASSERT_EQ("123", SByte(123).ToString());
  ASSERT_EQ("123", Int16(123).ToString());
  ASSERT_EQ("123", UInt16(123).ToString());
  ASSERT_EQ("123", Int32(123).ToString());
  ASSERT_EQ("123", UInt32(123).ToString());
  ASSERT_EQ("123", Int64(123).ToString());
  ASSERT_EQ("123", UInt64(123).ToString());
  ASSERT_EQ("123", String("123").ToString());
  ASSERT_EQ("123", Double(123.0).ToString());
  ASSERT_EQ("123", Single(123.0f).ToString());
  ASSERT_EQ("a", Char('a').ToString());
}

TEST(StringTest, Format_CustomFormatting) {
  /*  ASSERT_EQ("minus 15", String::Format("{0:#;minus #}", -15));
    ASSERT_EQ("zero", String::Format("{0:#;minus #;zero}", 0));
    ASSERT_EQ("+447 900 123 456", String::Format("{0:+### ### ### ###}", 447900123456));
    ASSERT_EQ("89-5871-2551", String::Format("{0:##-####-####}", 8958712551));
    ASSERT_EQ("00015", String::Format("{0:00000}", 15));
    ASSERT_EQ("-00015", String::Format("{0:00000}", -15));
    ASSERT_EQ("-", String::Format("{0:-}", 123456));
    ASSERT_EQ("a123456", String::Format("{0:a#}", 123456));
    ASSERT_EQ("a123456", String::Format("{0:a##}", 123456));
    ASSERT_EQ("a1", String::Format("{0:a#}", 1));
    ASSERT_EQ("a1", String::Format("{0:a##}", 1));
    ASSERT_EQ("a1", String::Format("{0:a##.#}", 1));
    ASSERT_EQ("a01.0", String::Format("{0:a0#.0}", 1));
    ASSERT_EQ("a12.0", String::Format("{0:a0#.0}", 12));
    ASSERT_EQ("ab1", String::Format("{0:a##b#}", 1));
    ASSERT_EQ("a00b1", String::Format("{0:a0#b0}", 1));
    ASSERT_EQ("a01b2", String::Format("{0:a0#b0}", 12));
    ASSERT_EQ("a1b2", String::Format("{0:a##b0}", 12));
    ASSERT_EQ("a12b3", String::Format("{0:a##b0}", 123));
    ASSERT_EQ("a1b23", String::Format("{0:a##b##}", 123));
    ASSERT_EQ("1", String::Format("{0:#0}", 1));
    ASSERT_EQ("01", String::Format("{0:0#}", 1));
    ASSERT_EQ("001", String::Format("{0:00#}", 1));
    ASSERT_EQ("012", String::Format("{0:00#}", 12));
    ASSERT_EQ("12", String::Format("{0:#0#}", 12));
    ASSERT_EQ("00012", String::Format("{0:#0####}", 12));
    ASSERT_EQ("00012", String::Format("{0:#00000}", 12));
    ASSERT_EQ("-00012", String::Format("{0:#00000}", -12));
    ASSERT_EQ("-00012", String::Format("{0:#0####}", -12));
    ASSERT_EQ("035", String::Format("{0:000}", 35.1));
    ASSERT_EQ("036", String::Format("{0:000}", 35.7));
    ASSERT_EQ("135", String::Format("{0:000}", 135.1));
    ASSERT_EQ("136", String::Format("{0:000}", 135.8));
    ASSERT_EQ("2", String::Format("{0:0}", 1.8));
    ASSERT_EQ("", String::Format("{0:#}", 0));
    ASSERT_EQ("", String::Format("{0:##}", 0));
    ASSERT_EQ(".5", String::Format("{0:##.#}", 0.5));
    ASSERT_EQ("X", String::Format("{0:X;B}", 5));
    ASSERT_EQ("B", String::Format("{0:X;B}", -5));
  
    ASSERT_THROW(String::Format("{0:a}", 123456), FormatException);*/
}

TEST(StringTest, Format_FormatIndexes) {
  String str = ("tiens");
  Int32 i = 2;
  Double d = 1.0;
  ASSERT_THROW(String::Format("{0} {1} vaut mieux que {2} tu l'auras"), FormatException);
  ASSERT_THROW(String::Format("{0} {1} vaut mieux que {2} tu l'auras", d), FormatException);
  ASSERT_THROW(String::Format("{0} {1} vaut mieux que {2} tu l'auras", d, str), FormatException);
  ASSERT_EQ("1 tiens vaut mieux que 2 tu l'auras", String::Format("{0} {1} vaut mieux que {2} tu l'auras", d, str, i));
}

TEST(StringTest, Format_Align) {
  ASSERT_EQ(String::Format("[{0,-4}]", 51),     "[51  ]");
  ASSERT_EQ(String::Format("[{0,4}]", 42),      "[  42]");
  ASSERT_EQ(String::Format("[{0,0}]", 5),       "[5]");
  ASSERT_EQ(String::Format("[{0,1}]", 5),       "[5]");
  ASSERT_EQ(String::Format("[{0,-1}]", 5),      "[5]");
  ASSERT_EQ(String::Format("[{0,-6}]", "left"), "[left  ]");
  ASSERT_EQ(String::Format("[{0,6}]", "right"), "[ right]");
  
  ASSERT_EQ(String::Format("[{0,3}]", "very long string"), "[very long string]");
  ASSERT_EQ(String::Format("[{0,-6}]", "very long string"), "[very long string]");
  
  ASSERT_EQ(String::Format("[{0,3}]", "four"), "[four]");
  ASSERT_EQ(String::Format("[{0,4}]", "four"), "[four]");
  ASSERT_EQ(String::Format("[{0,5}]", "four"), "[ four]");
  
  ASSERT_EQ(String::Format("[{0}]", Char('a')), "[a]");
}

TEST(StringTest, Format_NoFormat) {
  ASSERT_EQ("125", String::Format("{0:}", 125));
}

TEST(StringTest, Format_Unicode_Litteral) {
  ASSERT_EQ(String(0x1, 1), String::Format("{u1}"));
  ASSERT_EQ(String(0x12, 1), String::Format("{u12}"));
  ASSERT_EQ(String(0xA12, 1), String::Format("{uA12}"));
  ASSERT_EQ(String(0x2FFFF, 1), String::Format("{u2FFFF}"));
  ASSERT_EQ(String(0x00BB, 1), String::Format("{uBB}"));
  ASSERT_EQ(String(0x00BB, 1), String::Format("{u0BB}"));
  ASSERT_EQ(String(0x00BB, 1), String::Format("{u00BB}"));
}

TEST(StringTest, Format_Unicode_Litteral_Exception) {
  ASSERT_THROW(String::Format("{u}"), FormatException);
  ASSERT_THROW(String::Format("{u }"), FormatException);
}

TEST(StringTest, Format_char32) {
  char32 c = '/';
  ASSERT_EQ("/", String::Format("{0}", c));
  ASSERT_EQ("%", String::Format("{0}", char32('%')));
}

TEST(StringTest, Format_Pointer) {
  int32* null_ptr = null;
  int32* ptr = (int32*)0xFFFF;
  
  ASSERT_EQ("0", String::Format("{0}", null_ptr));
  ASSERT_EQ("65535", String::Format("{0}", ptr));
  ASSERT_EQ("FFFF", String::Format("{0:X}", ptr));
  ASSERT_EQ("0000ffff", String::Format("{0:x8}", ptr));
  ASSERT_EQ("ffff        ", String::Format("{0,-12:x}", ptr));
  ASSERT_EQ("    0000ffff", String::Format("{0,12:x8}", ptr));
  int32* ptr2 = (int32*)0x0FFFFFFF;
  ASSERT_EQ("FFFFFFF", String::Format("{0:X}", ptr2));
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
        String s = String.Format(provider, "  ASSERT_EQ(\"{0}\", String::Format(\"{1}\", {2}));",
          String.Format(provider,fmt, value),
          fmt,
          String.Format(provider, "{0}", value));
        okTests.Add(s);
      } catch (FormatException) {
        String s = String.Format(provider, "  ASSERT_THROW(String::Format(\"{0}\", {1}), FormatException);",
          fmt,
          String.Format(provider,"{0}",value));
        nokTests.Add(s);
      }
    }
  }
}
*/
