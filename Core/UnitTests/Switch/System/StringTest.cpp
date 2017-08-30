#include <Switch/System/String.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>
#include <Switch/LiteralOperatorConverter.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class StringTest : public TestFixture {
  protected:
    void SetUp() override {}

    void TearDown() override {}

    void StringCreatedWithDefaultConstructor() {
      TUnit::Assert::AreEqual("", string());
    }
    
    void StringCreatedWithConstCharPointerConstructor() {
      TUnit::Assert::AreEqual("Test", string("Test"), sw_current_information);
    }
    
    void StringCreatedWithConstChar16PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(u"Test"), sw_current_information);
    }
    
    void StringCreatedWithConstChar32PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(U"Test"), sw_current_information);
    }
    
    void StringCreatedWithConstWCharPointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(L"Test"), sw_current_information);
    }

    void StringCreatedWithConstRawCharPointerConstructor() {
      TUnit::Assert::AreEqual("Test \\ 1", string(R"(Test \ 1)"), sw_current_information);
    }
    
    void StringCreatedWithConstRawChar16PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(uR"(Test \ 1)"), sw_current_information);
    }
    
    void StringCreatedWithConstRawChar32PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(UR"(Test \ 1)"), sw_current_information);
    }
    
    void StringCreatedWithConstRawWCharPointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(LR"(Test \ 1)"), sw_current_information);
    }
    
    void StringCreatedWithCopyConstructor() {
      TUnit::Assert::AreEqual("Test1", string(string("Test1")), sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(sw_delegate {string(static_cast<const char*>(null));}, sw_current_information);
    }
    
    void StringCreatedWithConstChar16PointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(sw_delegate {string(static_cast<const char16*>(null));}, sw_current_information);
    }
    
    void StringCreatedWithConstChar32PointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(sw_delegate {string(static_cast<const char32*>(null));}, sw_current_information);
    }
    
    void StringCreatedWithConstWCharPointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(sw_delegate {string(static_cast<const wchar*>(null));}, sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {string("strTest1", -1, 0);}, sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndNegativeCountConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {string("strTest1", 0, -1);}, sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {string("strTest1", 10, 2);}, sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {string("strTest1", 0, 10);}, sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor() {
      TUnit::Assert::AreEqual("", string("strTest1", 0, 0), sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor() {
      TUnit::Assert::AreEqual("strTest1", string("strTest1", 0, 8), sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor() {
      TUnit::Assert::AreEqual("Test", string("strTest1", 3, 4), sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountInsideLengthConstructor() {
      TUnit::Assert::AreEqual("str", string("strTest1", 3), sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor() {
      TUnit::Assert::AreEqual("strTest1", string("strTest1", 8), sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor() {
      TUnit::Assert::AreEqual("str", string("str", 8), sw_current_information);
    }
    
    void StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor() {
      TUnit::Assert::AreEqual("", string("", 8), sw_current_information);
    }

    void StringCreatedByAssignment() {
      String s = "This is a string created by assignment.";
      TUnit::Assert::AreEqual("This is a string created by assignment.", s, sw_current_information);
    }

    void StringCreatedByAssignmentWithBackslash() {
      String s = "The path is C:\\PublicDocuments\\Report1.doc";
      TUnit::Assert::AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s, sw_current_information);
    }

    void StringCreatedByAssignmentWithVerbatimBackslash() {
      String s = R"(The path is C:\PublicDocuments\Report1.doc)";
      TUnit::Assert::AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s, sw_current_information);
    }

    void StringCreatedByConstructorWithChars() {
      Array<char> chars = { 'w', 'o', 'r', 'd' };
      String s(chars);
      TUnit::Assert::AreEqual("word", s, sw_current_information);
    }

    void StringCreatedByConstructorWith32bitsChars() {
      Array<char32> chars = { 'w', 'o', 'r', 'd' };
      String s(chars);
      TUnit::Assert::AreEqual("word", s, sw_current_information);
    }

    void CreateAStringThatConsistsOfACharacterRepeated20Times() {
      String s('C', 20);
      TUnit::Assert::AreEqual("CCCCCCCCCCCCCCCCCCCC", s, sw_current_information);
    }

    void StringCreatedByConstructorWithPointerOnSBytes() {
      sbyte bytes[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x00 };
      string s(bytes);
      TUnit::Assert::AreEqual("ABCDE", s, sw_current_information);
    }
    
    void StringCreatedByAssignmentWithUnicodeStringLiteral() {
      string s = U"こんにちは世界!";
      TUnit::Assert::AreEqual(U"こんにちは世界!", s, sw_current_information);
    }
    
    void SubscriptOperatorWithChar() {
      Array<char> chars = {'T', 'e', 's', 't'};
      string s = "Test";
      for (int i = 0; i < chars.Length; i++)
        TUnit::Assert::AreEqual(chars[i], static_cast<char>(s[i]), sw_current_information);
    }
    
    void SubscriptOperatorWithChar32() {
      Array<char32> chars = {U'こ', U'ん', U'に', U'ち', U'は', U'世', U'界', U'!'};
      string s = U"こんにちは世界!";
      int i = 0;
      for (char32 c : chars)
        TUnit::Assert::AreEqual(c, s[i++], sw_current_information);
      TUnit::Assert::AreEqual(chars.Length, i, sw_current_information);
    }
    
    void OperatorLitteralChar() {
      TUnit::Assert::AreEqual("Switch::System::String", sw_typeof("Test"_S).ToString(), sw_current_information);
    }
    
    void OperatorLitteralChar16() {
      TUnit::Assert::AreEqual("Switch::System::String", sw_typeof(u"Test"_S).ToString(), sw_current_information);
    }
    
    void OperatorLitteralChar32() {
      TUnit::Assert::AreEqual("Switch::System::String", sw_typeof(U"Test"_S).ToString(), sw_current_information);
    }
    
    void OperatorLitteralWChar() {
      TUnit::Assert::AreEqual("Switch::System::String", sw_typeof(L"Test"_S).ToString(), sw_current_information);
    }
    
    void OperatorAddConstCharPointer() {
      TUnit::Assert::AreEqual("string A string B", string("string A ") + "string B", sw_current_information);
    }
    
    void OperatorAddBoolean() {
      TUnit::Assert::AreEqual("string A False", string("string A ") + false, sw_current_information);
    }
    
    void OperatorAddBooleanObject() {
      TUnit::Assert::AreEqual("string A True", string("string A ") + Boolean(true), sw_current_information);
    }
    
    void OperatorAddByte() {
      TUnit::Assert::AreEqual("string A 18", string("string A ") + static_cast<byte>(18), sw_current_information);
    }
    
    void OperatorAddByteObject() {
      TUnit::Assert::AreEqual("string A 15", string("string A ") + Byte(15), sw_current_information);
    }
    
    void OperatorAddChar() {
      TUnit::Assert::AreEqual("string A a", string("string A ") + 'a', sw_current_information);
    }
    
    void OperatorAddChar16() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + u'd', sw_current_information);
    }
    
    void OperatorAddChar32() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + U'd', sw_current_information);
    }
    
    void OperatorAddWChar() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + L'd', sw_current_information);
    }
    
    void OperatorAddCharObject() {
      TUnit::Assert::AreEqual("string A G", string("string A ") + Char('G'), sw_current_information);
    }
    
    void OperatorAddDouble() {
      TUnit::Assert::AreEqual("string A -0.987678", string("string A ") + -0.987678, sw_current_information);
    }
    
    void OperatorAddDoubleObject() {
      TUnit::Assert::AreEqual("string A -0.987678", string("string A ") + Double(-0.987678), sw_current_information);
    }
    
    void OperatorAddInt16() {
      TUnit::Assert::AreEqual("string A -32768", string("string A ") + Int16::MinValue, sw_current_information);
    }
    
    void OperatorAddInt16Object() {
      TUnit::Assert::AreEqual("string A 32767", string("string A ") + Int16(Int16::MaxValue), sw_current_information);
    }
    
    void OperatorAddInt32() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<int32>(42), sw_current_information);
    }
    
    void OperatorAddInt32Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + Int32(5467), sw_current_information);
    }
    
    void OperatorAddInt64() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<int64>(42), sw_current_information);
    }
    
    void OperatorAddInt64Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + Int64(5467), sw_current_information);
    }
    
    void OperatorAddSByte() {
      TUnit::Assert::AreEqual("string A -2", string("string A ") + static_cast<sbyte>(-2), sw_current_information);
    }
    
    void OperatorAddSByteObject() {
      TUnit::Assert::AreEqual("string A 15", string("string A ") + SByte(15), sw_current_information);
    }
    
    void OperatorAddUInt16() {
      TUnit::Assert::AreEqual("string A 0", string("string A ") + UInt16::MinValue, sw_current_information);
    }
    
    void OperatorAddUInt16Object() {
      TUnit::Assert::AreEqual("string A 6345", string("string A ") + UInt16(6345), sw_current_information);
    }
    
    void OperatorAddUInt32() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<uint32>(42), sw_current_information);
    }
    
    void OperatorAddUInt32Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + UInt32(5467), sw_current_information);
    }
    
    void OperatorAddUInt64() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<uint64>(42), sw_current_information);
    }
    
    void OperatorAddUInt64Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + UInt64(5467), sw_current_information);
    }
    
    void OperatorAddSingle() {
      TUnit::Assert::AreEqual("string A 0.0654", string("string A ") + 0.0654f, sw_current_information);
    }
    
    void OperatorAddSingleObject() {
      TUnit::Assert::AreEqual("string A 0.0654", string("string A ") + Single(0.0654f), sw_current_information);
    }
    
    void OperatorAddDateTimeObject() {
      TUnit::Assert::AreEqual("string A 01/01/1970 00:00:00", string("string A ") + DateTime(1970, 1, 1, 0, 0, 0), sw_current_information);
    }
    
    void CompareEmptyStrings() {
      TUnit::Assert::IsTrue(string::Compare("", "") ==  0, sw_current_information);
    }
    
    void CompareEmptyStringWithStringEmpty() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty) ==  0, sw_current_information);
    }
    
    void CompareEmptyStringWithAnyString() {
      TUnit::Assert::IsTrue(string::Compare("", "string To Compare") < 0, sw_current_information);
    }
    
    void CompareAnyStringWithEmptyString() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "") > 0, sw_current_information);
    }
    
    void CompareSameStrings() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Compare") == 0, sw_current_information);
    }
    
    void CompareGreaterString() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Comp") > 0, sw_current_information);
    }
    
    void CompareLessString() {
      TUnit::Assert::IsTrue(string::Compare("string To Comp", "string To Compare") < 0, sw_current_information);
    }
    
    void CompareIndex() {
      TUnit::Assert::IsTrue(string::Compare("Char To Compare", 4, "string To Compare", 6, 11) == 0, sw_current_information);
    }
    
    void CompareEmptyStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", "", true) == 0, sw_current_information);
    }
    
    void CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty, true) ==  0, sw_current_information);
    }
    
    void CompareEmptyStringWithAnyStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", "string To compare", true) < 0, sw_current_information);
    }
    
    void CompareAnyStringWithEmptyStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string To compare", "", true) > 0, sw_current_information);
    }
    
    void CompareSameStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", true) == 0, sw_current_information);
    }
    
    void CompareGreaterStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", true) > 0, sw_current_information);
    }
    
    void CompareLessStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", true) < 0, sw_current_information);
    }
    
    void CompareDifferentCaseStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", true) == 0, sw_current_information);
    }
    
    void CompareGreaterDifferentCaseStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", true) > 0, sw_current_information);
    }
    
    void CompareLessDifferentCaseStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", true) < 0, sw_current_information);
    }
    
    void CompareEmptyStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", "", false) == 0, sw_current_information);
    }
    
    void CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty, false) ==  0, sw_current_information);
    }
    
    void CompareEmptyStringWithAnyStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", "string To Compare",false) < 0, sw_current_information);
    }
    
    void CompareAnyStringWithEmptyStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "",false) > 0, sw_current_information);
    }
    
    void CompareSameStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Compare",false) == 0, sw_current_information);
    }
    
    void CompareGreaterStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Comp",false) > 0, sw_current_information);
    }
    
    void CompareLessStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Comp", "string To Compare",false) < 0, sw_current_information);
    }
    
    void CompareDifferentCaseStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", false) > 0, sw_current_information);
    }
    
    void CompareGreaterDifferentCaseStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", false) > 0, sw_current_information);
    }
    
    void CompareLessDifferentCaseStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", false) > 0, sw_current_information);
    }
    
    void CompareIndexIgnoreCase() {
      TUnit::Assert::IsTrue(string::Compare("Char to compare", 4, "string To Compare", 6, 11,true) == 0, sw_current_information);
      TUnit::Assert::IsTrue(string::Compare("Char to compare", 4, "string To Compare", 6, 11,true) == 0, sw_current_information);
      TUnit::Assert::IsTrue(string::Compare("Char to Compare", 4, "string TO Compare", 6, 11, false) > 0, sw_current_information);
      TUnit::Assert::IsTrue(string::Compare("Char To Compare", 4, "string To Compare", 6, 11,false) == 0, sw_current_information);
    }
    
    void Concat() {
      TUnit::Assert::AreEqual(Object().ToString(), string::Concat(Object()), sw_current_information);
      TUnit::Assert::AreEqual(Object().ToString() + Object().ToString() + Object().ToString(), string::Concat<>(Array<Object> {Object(), Object(), Object()}), sw_current_information);
      TUnit::Assert::AreEqual(Object().ToString() + Object().ToString(), string::Concat(Object(), Object()), sw_current_information);
      TUnit::Assert::AreEqual( Object().ToString() + Object().ToString() + Object().ToString(), string::Concat(Object(), Object(), Object()),sw_current_information);
      
      TUnit::Assert::AreEqual("264", string::Concat(UInt32(264)), sw_current_information);
      TUnit::Assert::AreEqual("True", string::Concat(Boolean(true)), sw_current_information);
      TUnit::Assert::AreEqual("string to concatenate", string::Concat(string("string to concatenate")), sw_current_information);
      
      TUnit::Assert::AreEqual("264128", string::Concat(UInt32(264), UInt32(128)), sw_current_information);
      TUnit::Assert::AreEqual("TrueFalse", string::Concat(Boolean(true), Boolean(false)), sw_current_information);
      TUnit::Assert::AreEqual("string Astring B", string::Concat("string A", "string B"), sw_current_information);
      TUnit::Assert::AreEqual("264128378", string::Concat(UInt32(264), UInt32(128), UInt32(378)), sw_current_information);
      TUnit::Assert::AreEqual("TrueFalseTrue", string::Concat(Boolean(true), Boolean(false), Boolean(true)), sw_current_information);
      TUnit::Assert::AreEqual("string Astring Bstring C", string::Concat("string A", "string B", "string C"), sw_current_information);
      TUnit::Assert::AreEqual("string Astring Bstring Cstring D", string::Concat("string A", "string B", "string C", "string D"), sw_current_information);
    }
    
    void ConcatArray() {
      TUnit::Assert::AreEqual("264128378842", string::Concat<>(Array<Int32> {264, 128, 378, 842}), sw_current_information);
      TUnit::Assert::AreEqual("TrueFalseTrue", string::Concat<>(Array<Boolean> {true, false, true}), sw_current_information);
      TUnit::Assert::AreEqual("string To Concat", string::Concat<>(Array<string> {"string ", "To ", "Concat"}), sw_current_information);
    }
    
    void EndsWith() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith("beast"), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith("Beast"), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith("Beast", false), sw_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith("Beast", true), sw_current_information);
    }
    
    void EndsWithChar32() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith('t'), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('T'), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('s'), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('T', false), sw_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith('T', true), sw_current_information);
    }
    
    void StartsWith() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith("This"), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith("this"), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith("this", false), sw_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith("this", true), sw_current_information);
    }
    
    void StartsWithChar32() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('T'), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('t'), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('h'), sw_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('t', false), sw_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('t', true), sw_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('T', true), sw_current_information);
    }
    
    void GetEnumeratorOnString() {
      string str = "This is a test for enumerator";
      string output;
      System::Collections::Generic::Enumerator<char32> enumerator = str.GetEnumerator();
      while (enumerator.MoveNext())
        output += enumerator.Current;
      TUnit::Assert::AreEqual("This is a test for enumerator", output, sw_current_information);
    }
    
    void ForeachOnString() {
      string str = "This is a test for foreach";
      string output;
      for (char32 item : str)
        output += item;
      TUnit::Assert::AreEqual("This is a test for foreach", output, sw_current_information);
    }
    
    void IteratorOnString() {
      string str = "This is a test for iterator";
      string output;
      for (string::const_iterator iterator = str.cbegin(); iterator != str.cend(); ++iterator)
        output += *iterator;
      TUnit::Assert::AreEqual("This is a test for iterator", output, sw_current_information);
    }
    
    void ForOnString() {
      string str = "This is a test for for";
      string output;
      for (int32 index = 0; index < str.Length; ++index)
        output += str[index];
      TUnit::Assert::AreEqual("This is a test for for", output, sw_current_information);
    }
    
    void GetHashCode() {
      TUnit::Assert::AreNotEqual("A"_S.GetHashCode(), "B"_S.GetHashCode(), sw_current_information);
      TUnit::Assert::AreEqual("ABCD"_S.GetHashCode(),"ABCD"_S.GetHashCode(), sw_current_information);
      TUnit::Assert::AreNotEqual("ABCD"_S.GetHashCode(), "ABCE"_S.GetHashCode(), sw_current_information);
      TUnit::Assert::AreEqual("ABCDE"_S.GetHashCode(), "ABCDE"_S.GetHashCode(), sw_current_information);
      TUnit::Assert::AreNotEqual("My string"_S.GetHashCode(), "My Strinh"_S.GetHashCode(), sw_current_information);
      TUnit::Assert::AreNotEqual("My string"_S.GetHashCode(), "My Gtrins"_S.GetHashCode(), sw_current_information);
      TUnit::Assert::AreEqual("another string"_S.GetHashCode(), "another string"_S.GetHashCode(), sw_current_information);
      
      refptr<string> clone;
      string testClone("Test Clone");
      clone = as<string>(testClone.Clone());
      TUnit::Assert::AreEqual(testClone.GetHashCode(),clone->GetHashCode(), sw_current_information);
    }
    
    void IsNullOrEmptyOnEmptyString() {
      TUnit::Assert::IsTrue(string::IsNullOrEmpty(""_S), sw_current_information);
    }
    
    void IsNullOrEmptyOnNonEmptyString() {
      TUnit::Assert::IsFalse(string::IsNullOrEmpty("Not Empty"_S), sw_current_information);
    }
    
    void IsNullOrEmptyOnStringEmpty() {
      TUnit::Assert::IsTrue(string::IsNullOrEmpty(string::Empty), sw_current_information);
    }
    
    void IndexOf() {
      TUnit::Assert::AreEqual(2, "This is the beast of the beast"_S.IndexOf('i'), sw_current_information);
      TUnit::Assert::AreEqual(5, "This is the beast of the beast"_S.IndexOf('i', 3), sw_current_information);
      TUnit::Assert::AreEqual(5, "This is the beast of the beast"_S.IndexOf('i', 3, 3), sw_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf('i', 3, 2), sw_current_information);
      TUnit::Assert::AreEqual(29, "This is the beast of the beast"_S.IndexOf('t', 29), sw_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf('t', 30), sw_current_information);
      
      TUnit::Assert::AreEqual(8, "This is the beast of the beast"_S.IndexOf("the"), sw_current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.IndexOf("the", 19), sw_current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.IndexOf("the", 19, 5), sw_current_information);
      
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf("the", 18, 3), sw_current_information);
    }
    
    void IndexOfExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This is the beast of the beast"_S.IndexOf('i', 31);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This is the beast of the beast"_S.IndexOf('i', 26,5);}, sw_current_information);
      
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This is the beast of the beast"_S.IndexOf("the", 31);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This is the beast of the beast"_S.IndexOf("the", 26,5);}, sw_current_information);
    }
    
    void IndexOfAny() {
      Array<char32> separators = {'.', ',', ':','_'};
      
      TUnit::Assert::AreEqual(4,  "This, is : separator."_S.IndexOfAny(separators), sw_current_information);
      TUnit::Assert::AreEqual(9,  "This, is : separator."_S.IndexOfAny(separators, 5), sw_current_information);
      TUnit::Assert::AreEqual(9,  "This, is : separator."_S.IndexOfAny(separators, 5, 5), sw_current_information);
      TUnit::Assert::AreEqual(-1, "This, is : separator."_S.IndexOfAny(separators, 5, 4), sw_current_information);
      
      String xxxx_ = "xxxx_";
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 0, 5), sw_current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 1, 4), sw_current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 2, 3), sw_current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 3, 2), sw_current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 4, 1), sw_current_information);
      TUnit::Assert::AreEqual(-1, xxxx_.IndexOfAny(separators, 5, 0), sw_current_information);
    }
    
    void IndexOfAnyExceptions() {
      Array<char32> separators = {'.', ',', ':','_'};
      
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This, is : separator."_S.IndexOfAny(separators, 22);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This, is : separator."_S.IndexOfAny(separators, 18,5);}, sw_current_information);
      
      String xxxx_ = String("xxxx_");
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, -1,3);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, 0,-1);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, 2,-1);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, 0,6);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, 1,5);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, 2,4);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, 3,3);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, 4,2);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {xxxx_.IndexOfAny(separators, 5,1);}, sw_current_information);
    }
    
    void Join() {
      Array<string> array = {"123", "a text", "ok"};
      TUnit::Assert::AreEqual("123, a text, ok", string::Join(", ", array, 0, 3), sw_current_information);
    }
    
    void JoinN() {
      string join[] = {"blue", "red", "green", "yellow"};
      TUnit::Assert::AreEqual("blue, red, green, yellow", string::Join(", ", join, 4), sw_current_information);
      TUnit::Assert::AreEqual("red, green", string::Join(", ", join, 4, 1, 2), sw_current_information);
    }
    
    void JoinNExceptions() {
      string join[] = {"blue", "red", "green", "yellow"};
      TUnit::Assert::Throws<ArgumentNullException>(sw_delegate {string::Join(", ", null, 4);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {string::Join(", ", join, 4,4,2);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {string::Join(", ", join, 4,1,4);}, sw_current_information);
    }
    
    void LastIndexOf() {
      TUnit::Assert::AreEqual(26, "This is the beast of the beast"_S.LastIndexOf('e'), sw_current_information);
      TUnit::Assert::AreEqual(26, "This is the beast of the beast"_S.LastIndexOf('e', 3), sw_current_information);
      TUnit::Assert::AreEqual(13, "This is the beast of the beast"_S.LastIndexOf('e', 11, 3), sw_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf('e', 11, 2), sw_current_information);
      
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the"), sw_current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the", 19), sw_current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the", 19, 5), sw_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf("the", 19, 4), sw_current_information);
      TUnit::Assert::AreEqual(8, "This is the beast of the beast"_S.LastIndexOf("the", 5, 6), sw_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf("the", 5, 5), sw_current_information);
    }
    
    void LastIndexOfExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This is the beast of the beast"_S.LastIndexOf('e', 31);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This is the beast of the beast"_S.LastIndexOf('e', 29,2);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This is the beast of the beast"_S.LastIndexOf("the", 31);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This is the beast of the beast"_S.LastIndexOf("the", 29, 2);}, sw_current_information);
    }
    
    void LastIndexOfAny() {
      char32 nativeSeparator[] = {'.', ',', ':'};
      TUnit::Assert::AreEqual(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3)), sw_current_information);
      TUnit::Assert::AreEqual(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5), sw_current_information);
      TUnit::Assert::AreEqual(9, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 5), sw_current_information);
      TUnit::Assert::AreEqual(-1, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 4), sw_current_information);
    }
    
    void LastIndexOfAnyException() {
      char32 nativeSeparator[] = {'.', ',', ':'};
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 22);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 18,5);}, sw_current_information);
    }
    
    void PadLeft() {
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(13), sw_current_information);
      TUnit::Assert::AreEqual(" string To Pad", "string To Pad"_S.PadLeft(14), sw_current_information);
      TUnit::Assert::AreEqual("  string To Pad", "string To Pad"_S.PadLeft(15), sw_current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(12, '*'), sw_current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(13, '*'), sw_current_information);
      TUnit::Assert::AreEqual("*string To Pad", "string To Pad"_S.PadLeft(14, '*'), sw_current_information);
      TUnit::Assert::AreEqual("**string To Pad", "string To Pad"_S.PadLeft(15, '*'), sw_current_information);
    }
    
    void PadRight() {
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(13), sw_current_information);
      TUnit::Assert::AreEqual("string To Pad ", "string To Pad"_S.PadRight(14), sw_current_information);
      TUnit::Assert::AreEqual("string To Pad  ", "string To Pad"_S.PadRight(15), sw_current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(12, '*'), sw_current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(13, '*'), sw_current_information);
      TUnit::Assert::AreEqual("string To Pad*", "string To Pad"_S.PadRight(14, '*'), sw_current_information);
      TUnit::Assert::AreEqual("string To Pad**", "string To Pad"_S.PadRight(15, '*'), sw_current_information);
    }
    
    void Remove() {
      TUnit::Assert::AreEqual("", "abc123ABC"_S.Remove(0),sw_current_information);
      TUnit::Assert::AreEqual("abc", "abc123ABC"_S.Remove(3), sw_current_information);
      TUnit::Assert::AreEqual("abcABC", "abc123ABC"_S.Remove(3, 3), sw_current_information);
      TUnit::Assert::AreEqual("abc", "abc123ABC"_S.Remove(3, 6), sw_current_information);
      TUnit::Assert::AreEqual("abc123ABC", "abc123ABC"_S.Remove(9), sw_current_information);
    }
    
    void RemoveExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"abc123ABC"_S.Remove(10);}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"abc123ABC"_S.Remove(8,2);}, sw_current_information);
    }

    void Insert() {
      TUnit::Assert::AreEqual("abc", ""_S.Insert(0,"abc"));
      TUnit::Assert::AreEqual("abc123ABC", "abcABC"_S.Insert(3,"123"));
      TUnit::Assert::AreEqual("abc123", "abc"_S.Insert(3,"123"));
    }
    void InsertExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"ok"_S.Insert(-1,"abc");}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {""_S.Insert(1,"abc");}, sw_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(sw_delegate {"abc"_S.Insert(4,"123");}, sw_current_information);
    }
    
    void Replace() {
      TUnit::Assert::AreEqual("This*is*the*beast*of*the*beast", "This is the beast of the beast"_S.Replace(' ', '*'), sw_current_information);
      TUnit::Assert::AreEqual("This is thE bEast of thE bEast", "This is the beast of the beast"_S.Replace('e', 'E'), sw_current_information);
      TUnit::Assert::AreEqual("Thare are the beast of the beast", "This is the beast of the beast"_S.Replace("is", "are"), sw_current_information);
      TUnit::Assert::AreEqual("Th  the beast of the beast", "This is the beast of the beast"_S.Replace("is", ""), sw_current_information);
      TUnit::Assert::AreEqual("This text has\\_unescaped\\_\\_underscores !", "This text has_unescaped__underscores !"_S.Replace("_", "\\_"), sw_current_information);
    }
    
    void Split() {
      TUnit::Assert::AreEqual(Array<string> {}, ""_S.Split({'+', '-', '='}), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"a"}, "a"_S.Split({'+', '-', '='}), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"100", "42", "142"}, "100+42=142"_S.Split({'+', '-', '='}), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"100+42=142"}, "100+42=142"_S.Split({'%', '*'}), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"100+42=142"}, "100+42=142"_S.Split({}), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"a", "b", "c"}, "a,b,c"_S.Split(','), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"a", "", "", "b", "", "c"}, "a,,,b,,c"_S.Split(','), sw_current_information);
    }
    
    void SplitCount() {
      TUnit::Assert::AreEqual(Array<string> {"42", " 12, 19"}, "42, 12, 19"_S.Split({',', ' '}, 2), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"42", "", "12", ".19"}, "42..12..19"_S.Split({'.'}, 4), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"Banana"}, "Banana"_S.Split({','}, 2), sw_current_information);
      TUnit::Assert::AreEqual(Array<string> {"Darb\nSmarba "}, "Darb\nSmarba "_S.Split({}, 1), sw_current_information);
    }
    
    void SplitWithStringSplitOptionRemoveEmptyEntries() {
      TUnit::Assert::AreEqual(Array<string> {"a", "b", "c"}, "a,,,b,,c"_S.Split(',', StringSplitOptions::RemoveEmptyEntries), sw_current_information);
    }
  
    void SplitWithStringSplitOptioNone() {
      TUnit::Assert::AreEqual(Array<string> {"a", "", "", "b", "", "c"}, "a,,,b,,c"_S.Split(',', StringSplitOptions::None), sw_current_information);
    }
    
    void ToUpper() {
      TUnit::Assert::AreEqual("STRING TO UPPER OR TO LOWER", "string To Upper or To Lower"_S.ToUpper(), sw_current_information);
    }
    
    void ToLower() {
      TUnit::Assert::AreEqual("string to upper or to lower", "string To Upper or To Lower"_S.ToLower(), sw_current_information);
    }
    
    void TrimStart() {
      TUnit::Assert::AreEqual("string To Trim", "string To Trim"_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual("string To Trim", "xxxstring To Trim"_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual("string To Trim", "xxstring To Trim"_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual("string To Trim", "xstring To Trim"_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual("", ""_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual("", "x"_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual("", "xx"_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual("", "xxx"_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual(" x", "xx x"_S.TrimStart('x'), sw_current_information);
      TUnit::Assert::AreEqual("string To Trim Start", "          string To Trim Start"_S.TrimStart(' '), sw_current_information);
      TUnit::Assert::AreEqual("          string To Trim Start", "          string To Trim Start"_S.TrimStart('d'), sw_current_information);
    }
    
    void TrimSartMultiple() {
      Array<char32> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
      
      TUnit::Assert::AreEqual("abcdef1357924680", "2468013579abcdef1357924680"_S.TrimStart(numbers), sw_current_information);
      TUnit::Assert::AreEqual("", ""_S.TrimStart(numbers), sw_current_information);
      TUnit::Assert::AreEqual("", "24680135791357924680"_S.TrimStart(numbers), sw_current_information);
    }

  };

  sw_test(StringTest, StringCreatedWithDefaultConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerConstructor)
  sw_test(StringTest, StringCreatedWithConstChar16PointerConstructor)
  sw_test(StringTest, StringCreatedWithConstChar32PointerConstructor)
  sw_test(StringTest, StringCreatedWithConstWCharPointerConstructor)
  sw_test(StringTest, StringCreatedWithConstRawCharPointerConstructor)
  sw_test(StringTest, StringCreatedWithConstRawChar16PointerConstructor)
  sw_test(StringTest, StringCreatedWithConstRawChar32PointerConstructor)
  sw_test(StringTest, StringCreatedWithConstRawWCharPointerConstructor)
  sw_test(StringTest, StringCreatedWithCopyConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerNull)
  sw_test(StringTest, StringCreatedWithConstChar16PointerNull)
  sw_test(StringTest, StringCreatedWithConstChar32PointerNull)
  sw_test(StringTest, StringCreatedWithConstWCharPointerNull)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndNegativeCountConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndCountInsideLengthConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor)
  sw_test(StringTest, StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor)
  sw_test(StringTest, StringCreatedByAssignment)
  sw_test(StringTest, StringCreatedByAssignmentWithBackslash)
  sw_test(StringTest, StringCreatedByAssignmentWithVerbatimBackslash)
  sw_test(StringTest, StringCreatedByConstructorWithChars)
  sw_test(StringTest, StringCreatedByConstructorWith32bitsChars)
  sw_test(StringTest, CreateAStringThatConsistsOfACharacterRepeated20Times)
  sw_test(StringTest, StringCreatedByConstructorWithPointerOnSBytes)
  sw_test(StringTest, StringCreatedByAssignmentWithUnicodeStringLiteral)
  sw_test(StringTest, SubscriptOperatorWithChar)
  sw_test(StringTest, SubscriptOperatorWithChar32)
  sw_test(StringTest, OperatorLitteralChar)
  sw_test(StringTest, OperatorLitteralChar16)
  sw_test(StringTest, OperatorLitteralChar32)
  sw_test(StringTest, OperatorLitteralWChar)
  sw_test(StringTest, OperatorAddConstCharPointer)
  sw_test(StringTest, OperatorAddBoolean)
  sw_test(StringTest, OperatorAddByte)
  sw_test(StringTest, OperatorAddByteObject)
  sw_test(StringTest, OperatorAddChar)
  sw_test(StringTest, OperatorAddChar16)
  sw_test(StringTest, OperatorAddChar32)
  sw_test(StringTest, OperatorAddWChar)
  sw_test(StringTest, OperatorAddCharObject)
  sw_test(StringTest, OperatorAddDouble)
  sw_test(StringTest, OperatorAddDoubleObject)
  sw_test(StringTest, OperatorAddInt16)
  sw_test(StringTest, OperatorAddInt16Object)
  sw_test(StringTest, OperatorAddInt32)
  sw_test(StringTest, OperatorAddInt32Object)
  sw_test(StringTest, OperatorAddInt64)
  sw_test(StringTest, OperatorAddInt64Object)
  sw_test(StringTest, OperatorAddSByte)
  sw_test(StringTest, OperatorAddSByteObject)
  sw_test(StringTest, OperatorAddSingle)
  sw_test(StringTest, OperatorAddSingleObject)
  sw_test(StringTest, OperatorAddDateTimeObject)
  sw_test(StringTest, CompareEmptyStrings)
  sw_test(StringTest, CompareEmptyStringWithStringEmpty)
  sw_test(StringTest, CompareEmptyStringWithAnyString)
  sw_test(StringTest, CompareAnyStringWithEmptyString)
  sw_test(StringTest, CompareSameStrings)
  sw_test(StringTest, CompareGreaterString)
  sw_test(StringTest, CompareLessString)
  sw_test(StringTest, CompareIndex)
  sw_test(StringTest, CompareEmptyStringsWithIgnoreCaseTrue)
  sw_test(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue)
  sw_test(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseTrue)
  sw_test(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseTrue)
  sw_test(StringTest, CompareSameStringsWithIgnoreCaseTrue)
  sw_test(StringTest, CompareGreaterStringWithIgnoreCaseTrue)
  sw_test(StringTest, CompareLessStringWithIgnoreCaseTrue)
  sw_test(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseTrue)
  sw_test(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseTrue)
  sw_test(StringTest, CompareEmptyStringsWithIgnoreCaseFalse)
  sw_test(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse)
  sw_test(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseFalse)
  sw_test(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseFalse)
  sw_test(StringTest, CompareSameStringsWithIgnoreCaseFalse)
  sw_test(StringTest, CompareGreaterStringWithIgnoreCaseFalse)
  sw_test(StringTest, CompareLessStringWithIgnoreCaseFalse)
  sw_test(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseFalse)
  sw_test(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseFalse)
  sw_test(StringTest, CompareIndexIgnoreCase)
  sw_test(StringTest, Concat)
  sw_test(StringTest, ConcatArray)
  sw_test(StringTest, EndsWith)
  sw_test(StringTest, EndsWithChar32)
  sw_test(StringTest, StartsWith)
  sw_test(StringTest, StartsWithChar32)
  sw_test(StringTest, GetEnumeratorOnString)
  sw_test(StringTest, ForeachOnString)
  sw_test(StringTest, IteratorOnString)
  sw_test(StringTest, ForOnString)
  sw_test(StringTest, GetHashCode)
  sw_test(StringTest, IsNullOrEmptyOnEmptyString)
  sw_test(StringTest, IsNullOrEmptyOnNonEmptyString)
  sw_test(StringTest, IsNullOrEmptyOnStringEmpty)
  sw_test(StringTest, IndexOf)
  sw_test(StringTest, IndexOfExceptions)
  sw_test(StringTest, IndexOfAny)
  sw_test(StringTest, IndexOfAnyExceptions)
  sw_test(StringTest, Join)
  sw_test(StringTest, JoinN)
  sw_test(StringTest, JoinNExceptions)
  sw_test(StringTest, LastIndexOf)
  sw_test(StringTest, LastIndexOfExceptions)
  sw_test(StringTest, LastIndexOfAny)
  sw_test(StringTest, LastIndexOfAnyException)
  sw_test(StringTest, PadLeft)
  sw_test(StringTest, PadRight)
  sw_test(StringTest, Remove)
  sw_test(StringTest, RemoveExceptions)
  sw_test(StringTest, Insert)
  sw_test(StringTest, InsertExceptions)
  sw_test(StringTest, Replace)
  sw_test(StringTest, Split)
  sw_test(StringTest, SplitCount)
  sw_test(StringTest, SplitWithStringSplitOptionRemoveEmptyEntries)
  sw_test(StringTest, SplitWithStringSplitOptioNone)
  sw_test(StringTest, ToUpper)
  sw_test(StringTest, ToLower)
  sw_test(StringTest, TrimStart)
}
