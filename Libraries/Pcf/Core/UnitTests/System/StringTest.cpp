#include <Pcf/System/String.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>
#include <Pcf/LiteralOperatorConverter.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class StringTest : public TestFixture {
  protected:
    void SetUp() override {}

    void TearDown() override {}

    void StringCreatedWithDefaultConstructor() {
      TUnit::Assert::AreEqual("", string());
    }
    
    void StringCreatedWithConstCharPointerConstructor() {
      TUnit::Assert::AreEqual("Test", string("Test"), pcf_current_information);
    }
    
    void StringCreatedWithConstChar16PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(u"Test"), pcf_current_information);
    }
    
    void StringCreatedWithConstChar32PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(U"Test"), pcf_current_information);
    }
    
    void StringCreatedWithConstWCharPointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(L"Test"), pcf_current_information);
    }

    void StringCreatedWithConstRawCharPointerConstructor() {
      TUnit::Assert::AreEqual("Test \\ 1", string(R"(Test \ 1)"), pcf_current_information);
    }
    
    void StringCreatedWithConstRawChar16PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(uR"(Test \ 1)"), pcf_current_information);
    }
    
    void StringCreatedWithConstRawChar32PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(UR"(Test \ 1)"), pcf_current_information);
    }
    
    void StringCreatedWithConstRawWCharPointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(LR"(Test \ 1)"), pcf_current_information);
    }
    
    void StringCreatedWithCopyConstructor() {
      TUnit::Assert::AreEqual("Test1", string(string("Test1")), pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(pcf_delegate {string(static_cast<const char*>(null));}, pcf_current_information);
    }
    
    void StringCreatedWithConstChar16PointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(pcf_delegate {string(static_cast<const char16*>(null));}, pcf_current_information);
    }
    
    void StringCreatedWithConstChar32PointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(pcf_delegate {string(static_cast<const char32*>(null));}, pcf_current_information);
    }
    
    void StringCreatedWithConstWCharPointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(pcf_delegate {string(static_cast<const wchar_t*>(null));}, pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {string("strTest1", -1, 0);}, pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndNegativeCountConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {string("strTest1", 0, -1);}, pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {string("strTest1", 10, 2);}, pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {string("strTest1", 0, 10);}, pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor() {
      TUnit::Assert::AreEqual("", string("strTest1", 0, 0), pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor() {
      TUnit::Assert::AreEqual("strTest1", string("strTest1", 0, 8), pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor() {
      TUnit::Assert::AreEqual("Test", string("strTest1", 3, 4), pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountInsideLengthConstructor() {
      TUnit::Assert::AreEqual("str", string("strTest1", 3), pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor() {
      TUnit::Assert::AreEqual("strTest1", string("strTest1", 8), pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor() {
      TUnit::Assert::AreEqual("str", string("str", 8), pcf_current_information);
    }
    
    void StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor() {
      TUnit::Assert::AreEqual("", string("", 8), pcf_current_information);
    }

    void StringCreatedByAssignment() {
      String s = "This is a string created by assignment.";
      TUnit::Assert::AreEqual("This is a string created by assignment.", s, pcf_current_information);
    }

    void StringCreatedByAssignmentWithBackslash() {
      String s = "The path is C:\\PublicDocuments\\Report1.doc";
      TUnit::Assert::AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s, pcf_current_information);
    }

    void StringCreatedByAssignmentWithVerbatimBackslash() {
      String s = R"(The path is C:\PublicDocuments\Report1.doc)";
      TUnit::Assert::AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s, pcf_current_information);
    }

    void StringCreatedByConstructorWithChars() {
      Array<char> chars = { 'w', 'o', 'r', 'd' };
      String s(chars);
      TUnit::Assert::AreEqual("word", s, pcf_current_information);
    }

    void StringCreatedByConstructorWith32bitsChars() {
      Array<char32> chars = { 'w', 'o', 'r', 'd' };
      String s(chars);
      TUnit::Assert::AreEqual("word", s, pcf_current_information);
    }

    void CreateAStringThatConsistsOfACharacterRepeated20Times() {
      String s('C', 20);
      TUnit::Assert::AreEqual("CCCCCCCCCCCCCCCCCCCC", s, pcf_current_information);
    }

    void StringCreatedByConstructorWithPointerOnSBytes() {
      sbyte bytes[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x00 };
      string s(bytes);
      TUnit::Assert::AreEqual("ABCDE", s, pcf_current_information);
    }
    
    void StringCreatedByAssignmentWithUnicodeStringLiteral() {
      string s = U"こんにちは世界!";
      TUnit::Assert::AreEqual(U"こんにちは世界!", s, pcf_current_information);
    }
    
    void SubscriptOperatorWithChar() {
      Array<char> chars = {'T', 'e', 's', 't'};
      string s = "Test";
      for (int i = 0; i < chars.Length; i++)
        TUnit::Assert::AreEqual(chars[i], static_cast<char>(s[i]), pcf_current_information);
    }
    
    void SubscriptOperatorWithChar32() {
      Array<char32> chars = {U'こ', U'ん', U'に', U'ち', U'は', U'世', U'界', U'!'};
      string s = U"こんにちは世界!";
      int i = 0;
      for (char32 c : chars)
        TUnit::Assert::AreEqual(c, s[i++], pcf_current_information);
      TUnit::Assert::AreEqual(chars.Length, i, pcf_current_information);
    }
    
    void OperatorLitteralChar() {
      TUnit::Assert::AreEqual("Pcf::System::String", typeof("Test"_S).ToString(), pcf_current_information);
    }
    
    void OperatorLitteralChar16() {
      TUnit::Assert::AreEqual("Pcf::System::String", typeof(u"Test"_S).ToString(), pcf_current_information);
    }
    
    void OperatorLitteralChar32() {
      TUnit::Assert::AreEqual("Pcf::System::String", typeof(U"Test"_S).ToString(), pcf_current_information);
    }
    
    void OperatorLitteralWChar() {
      TUnit::Assert::AreEqual("Pcf::System::String", typeof(L"Test"_S).ToString(), pcf_current_information);
    }
    
    void OperatorAddConstCharPointer() {
      TUnit::Assert::AreEqual("string A string B", string("string A ") + "string B", pcf_current_information);
    }
    
    void OperatorAddBoolean() {
      TUnit::Assert::AreEqual("string A False", string("string A ") + false, pcf_current_information);
    }
    
    void OperatorAddBooleanObject() {
      TUnit::Assert::AreEqual("string A True", string("string A ") + Boolean(true), pcf_current_information);
    }
    
    void OperatorAddByte() {
      TUnit::Assert::AreEqual("string A 18", string("string A ") + static_cast<byte>(18), pcf_current_information);
    }
    
    void OperatorAddByteObject() {
      TUnit::Assert::AreEqual("string A 15", string("string A ") + Byte(15), pcf_current_information);
    }
    
    void OperatorAddChar() {
      TUnit::Assert::AreEqual("string A a", string("string A ") + 'a', pcf_current_information);
    }
    
    void OperatorAddChar16() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + u'd', pcf_current_information);
    }
    
    void OperatorAddChar32() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + U'd', pcf_current_information);
    }
    
    void OperatorAddWChar() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + L'd', pcf_current_information);
    }
    
    void OperatorAddCharObject() {
      TUnit::Assert::AreEqual("string A G", string("string A ") + Char('G'), pcf_current_information);
    }
    
    void OperatorAddDouble() {
      TUnit::Assert::AreEqual("string A -0.987678", string("string A ") + -0.987678, pcf_current_information);
    }
    
    void OperatorAddDoubleObject() {
      TUnit::Assert::AreEqual("string A -0.987678", string("string A ") + Double(-0.987678), pcf_current_information);
    }
    
    void OperatorAddInt16() {
      TUnit::Assert::AreEqual("string A -32768", string("string A ") + Int16::MinValue, pcf_current_information);
    }
    
    void OperatorAddInt16Object() {
      TUnit::Assert::AreEqual("string A 32767", string("string A ") + Int16(Int16::MaxValue), pcf_current_information);
    }
    
    void OperatorAddInt32() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<int32>(42), pcf_current_information);
    }
    
    void OperatorAddInt32Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + Int32(5467), pcf_current_information);
    }
    
    void OperatorAddInt64() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<int64>(42), pcf_current_information);
    }
    
    void OperatorAddInt64Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + Int64(5467), pcf_current_information);
    }
    
    void OperatorAddSByte() {
      TUnit::Assert::AreEqual("string A -2", string("string A ") + static_cast<sbyte>(-2), pcf_current_information);
    }
    
    void OperatorAddSByteObject() {
      TUnit::Assert::AreEqual("string A 15", string("string A ") + SByte(15), pcf_current_information);
    }
    
    void OperatorAddUInt16() {
      TUnit::Assert::AreEqual("string A 0", string("string A ") + UInt16::MinValue, pcf_current_information);
    }
    
    void OperatorAddUInt16Object() {
      TUnit::Assert::AreEqual("string A 6345", string("string A ") + UInt16(6345), pcf_current_information);
    }
    
    void OperatorAddUInt32() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<uint32>(42), pcf_current_information);
    }
    
    void OperatorAddUInt32Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + UInt32(5467), pcf_current_information);
    }
    
    void OperatorAddUInt64() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<uint64>(42), pcf_current_information);
    }
    
    void OperatorAddUInt64Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + UInt64(5467), pcf_current_information);
    }
    
    void OperatorAddSingle() {
      TUnit::Assert::AreEqual("string A 0.0654", string("string A ") + 0.0654f, pcf_current_information);
    }
    
    void OperatorAddSingleObject() {
      TUnit::Assert::AreEqual("string A 0.0654", string("string A ") + Single(0.0654f), pcf_current_information);
    }
    
    void OperatorAddDateTimeObject() {
      TUnit::Assert::AreEqual("string A 01/01/1970 00:00:00", string("string A ") + DateTime(1970, 1, 1, 0, 0, 0), pcf_current_information);
    }
    
    void CompareEmptyStrings() {
      TUnit::Assert::IsTrue(string::Compare("", "") ==  0, pcf_current_information);
    }
    
    void CompareEmptyStringWithStringEmpty() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty) ==  0, pcf_current_information);
    }
    
    void CompareEmptyStringWithAnyString() {
      TUnit::Assert::IsTrue(string::Compare("", "string To Compare") < 0, pcf_current_information);
    }
    
    void CompareAnyStringWithEmptyString() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "") > 0, pcf_current_information);
    }
    
    void CompareSameStrings() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Compare") == 0, pcf_current_information);
    }
    
    void CompareGreaterString() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Comp") > 0, pcf_current_information);
    }
    
    void CompareLessString() {
      TUnit::Assert::IsTrue(string::Compare("string To Comp", "string To Compare") < 0, pcf_current_information);
    }
    
    void CompareIndex() {
      TUnit::Assert::IsTrue(string::Compare("Char To Compare", 4, "string To Compare", 6, 11) == 0, pcf_current_information);
    }
    
    void CompareEmptyStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", "", true) == 0, pcf_current_information);
    }
    
    void CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty, true) ==  0, pcf_current_information);
    }
    
    void CompareEmptyStringWithAnyStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", "string To compare", true) < 0, pcf_current_information);
    }
    
    void CompareAnyStringWithEmptyStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string To compare", "", true) > 0, pcf_current_information);
    }
    
    void CompareSameStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", true) == 0, pcf_current_information);
    }
    
    void CompareGreaterStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", true) > 0, pcf_current_information);
    }
    
    void CompareLessStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", true) < 0, pcf_current_information);
    }
    
    void CompareDifferentCaseStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", true) == 0, pcf_current_information);
    }
    
    void CompareGreaterDifferentCaseStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", true) > 0, pcf_current_information);
    }
    
    void CompareLessDifferentCaseStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", true) < 0, pcf_current_information);
    }
    
    void CompareEmptyStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", "", false) == 0, pcf_current_information);
    }
    
    void CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty, false) ==  0, pcf_current_information);
    }
    
    void CompareEmptyStringWithAnyStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", "string To Compare",false) < 0, pcf_current_information);
    }
    
    void CompareAnyStringWithEmptyStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "",false) > 0, pcf_current_information);
    }
    
    void CompareSameStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Compare",false) == 0, pcf_current_information);
    }
    
    void CompareGreaterStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Comp",false) > 0, pcf_current_information);
    }
    
    void CompareLessStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Comp", "string To Compare",false) < 0, pcf_current_information);
    }
    
    void CompareDifferentCaseStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", false) > 0, pcf_current_information);
    }
    
    void CompareGreaterDifferentCaseStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", false) > 0, pcf_current_information);
    }
    
    void CompareLessDifferentCaseStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", false) > 0, pcf_current_information);
    }
    
    void CompareIndexIgnoreCase() {
      TUnit::Assert::IsTrue(string::Compare("Char to compare", 4, "string To Compare", 6, 11,true) == 0, pcf_current_information);
      TUnit::Assert::IsTrue(string::Compare("Char to compare", 4, "string To Compare", 6, 11,true) == 0, pcf_current_information);
      TUnit::Assert::IsTrue(string::Compare("Char to Compare", 4, "string TO Compare", 6, 11, false) > 0, pcf_current_information);
      TUnit::Assert::IsTrue(string::Compare("Char To Compare", 4, "string To Compare", 6, 11,false) == 0, pcf_current_information);
    }
    
    void Concat() {
      TUnit::Assert::AreEqual(Object().ToString(), string::Concat(Object()), pcf_current_information);
      TUnit::Assert::AreEqual(Object().ToString() + Object().ToString() + Object().ToString(), string::Concat<>(Array<Object> {Object(), Object(), Object()}), pcf_current_information);
      TUnit::Assert::AreEqual(Object().ToString() + Object().ToString(), string::Concat(Object(), Object()), pcf_current_information);
      TUnit::Assert::AreEqual( Object().ToString() + Object().ToString() + Object().ToString(), string::Concat(Object(), Object(), Object()),pcf_current_information);
      
      TUnit::Assert::AreEqual("264", string::Concat(UInt32(264)), pcf_current_information);
      TUnit::Assert::AreEqual("True", string::Concat(Boolean(true)), pcf_current_information);
      TUnit::Assert::AreEqual("string to concatenate", string::Concat(string("string to concatenate")), pcf_current_information);
      
      TUnit::Assert::AreEqual("264128", string::Concat(UInt32(264), UInt32(128)), pcf_current_information);
      TUnit::Assert::AreEqual("TrueFalse", string::Concat(Boolean(true), Boolean(false)), pcf_current_information);
      TUnit::Assert::AreEqual("string Astring B", string::Concat("string A", "string B"), pcf_current_information);
      TUnit::Assert::AreEqual("264128378", string::Concat(UInt32(264), UInt32(128), UInt32(378)), pcf_current_information);
      TUnit::Assert::AreEqual("TrueFalseTrue", string::Concat(Boolean(true), Boolean(false), Boolean(true)), pcf_current_information);
      TUnit::Assert::AreEqual("string Astring Bstring C", string::Concat("string A", "string B", "string C"), pcf_current_information);
      TUnit::Assert::AreEqual("string Astring Bstring Cstring D", string::Concat("string A", "string B", "string C", "string D"), pcf_current_information);
    }
    
    void ConcatArray() {
      TUnit::Assert::AreEqual("264128378842", string::Concat<>(Array<Int32> {264, 128, 378, 842}), pcf_current_information);
      TUnit::Assert::AreEqual("TrueFalseTrue", string::Concat<>(Array<Boolean> {true, false, true}), pcf_current_information);
      TUnit::Assert::AreEqual("string To Concat", string::Concat<>(Array<string> {"string ", "To ", "Concat"}), pcf_current_information);
    }
    
    void EndsWith() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith("beast"), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith("Beast"), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith("Beast", false), pcf_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith("Beast", true), pcf_current_information);
    }
    
    void EndsWithChar32() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith('t'), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('T'), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('s'), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('T', false), pcf_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith('T', true), pcf_current_information);
    }
    
    void StartsWith() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith("This"), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith("this"), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith("this", false), pcf_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith("this", true), pcf_current_information);
    }
    
    void StartsWithChar32() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('T'), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('t'), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('h'), pcf_current_information);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('t', false), pcf_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('t', true), pcf_current_information);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('T', true), pcf_current_information);
    }
    
    void GetEnumeratorOnString() {
      string str = "This is a test for enumerator";
      string output;
      System::Collections::Generic::Enumerator<char32> enumerator = str.GetEnumerator();
      while (enumerator.MoveNext())
        output += enumerator.Current;
      TUnit::Assert::AreEqual("This is a test for enumerator", output, pcf_current_information);
    }
    
    void ForeachOnString() {
      string str = "This is a test for foreach";
      string output;
      for (char32 item : str)
        output += item;
      TUnit::Assert::AreEqual("This is a test for foreach", output, pcf_current_information);
    }
    
    void IteratorOnString() {
      string str = "This is a test for iterator";
      string output;
      for (string::const_iterator iterator = str.cbegin(); iterator != str.cend(); ++iterator)
        output += *iterator;
      TUnit::Assert::AreEqual("This is a test for iterator", output, pcf_current_information);
    }
    
    void ForOnString() {
      string str = "This is a test for for";
      string output;
      for (int32 index = 0; index < str.Length; ++index)
        output += str[index];
      TUnit::Assert::AreEqual("This is a test for for", output, pcf_current_information);
    }
    
    void GetHashCode() {
      TUnit::Assert::AreNotEqual("A"_S.GetHashCode(), "B"_S.GetHashCode(), pcf_current_information);
      TUnit::Assert::AreEqual("ABCD"_S.GetHashCode(),"ABCD"_S.GetHashCode(), pcf_current_information);
      TUnit::Assert::AreNotEqual("ABCD"_S.GetHashCode(), "ABCE"_S.GetHashCode(), pcf_current_information);
      TUnit::Assert::AreEqual("ABCDE"_S.GetHashCode(), "ABCDE"_S.GetHashCode(), pcf_current_information);
      TUnit::Assert::AreNotEqual("My string"_S.GetHashCode(), "My Strinh"_S.GetHashCode(), pcf_current_information);
      TUnit::Assert::AreNotEqual("My string"_S.GetHashCode(), "My Gtrins"_S.GetHashCode(), pcf_current_information);
      TUnit::Assert::AreEqual("another string"_S.GetHashCode(), "another string"_S.GetHashCode(), pcf_current_information);
      
      UniquePointer<string> clone;
      string testClone("Test Clone");
      clone = as<string>(testClone.Clone());
      TUnit::Assert::AreEqual(testClone.GetHashCode(),clone->GetHashCode(), pcf_current_information);
    }
    
    void IsNullOrEmptyOnEmptyString() {
      TUnit::Assert::IsTrue(string::IsNullOrEmpty(""_S), pcf_current_information);
    }
    
    void IsNullOrEmptyOnNonEmptyString() {
      TUnit::Assert::IsFalse(string::IsNullOrEmpty("Not Empty"_S), pcf_current_information);
    }
    
    void IsNullOrEmptyOnStringEmpty() {
      TUnit::Assert::IsTrue(string::IsNullOrEmpty(string::Empty), pcf_current_information);
    }
    
    void IndexOf() {
      TUnit::Assert::AreEqual(2, "This is the beast of the beast"_S.IndexOf('i'), pcf_current_information);
      TUnit::Assert::AreEqual(5, "This is the beast of the beast"_S.IndexOf('i', 3), pcf_current_information);
      TUnit::Assert::AreEqual(5, "This is the beast of the beast"_S.IndexOf('i', 3, 3), pcf_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf('i', 3, 2), pcf_current_information);
      TUnit::Assert::AreEqual(29, "This is the beast of the beast"_S.IndexOf('t', 29), pcf_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf('t', 30), pcf_current_information);
      
      TUnit::Assert::AreEqual(8, "This is the beast of the beast"_S.IndexOf("the"), pcf_current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.IndexOf("the", 19), pcf_current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.IndexOf("the", 19, 5), pcf_current_information);
      
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf("the", 18, 3), pcf_current_information);
    }
    
    void IndexOfExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This is the beast of the beast"_S.IndexOf('i', 31);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This is the beast of the beast"_S.IndexOf('i', 26,5);}, pcf_current_information);
      
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This is the beast of the beast"_S.IndexOf("the", 31);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This is the beast of the beast"_S.IndexOf("the", 26,5);}, pcf_current_information);
    }
    
    void IndexOfAny() {
      Array<char32> separators = {'.', ',', ':','_'};
      
      TUnit::Assert::AreEqual(4,  "This, is : separator."_S.IndexOfAny(separators), pcf_current_information);
      TUnit::Assert::AreEqual(9,  "This, is : separator."_S.IndexOfAny(separators, 5), pcf_current_information);
      TUnit::Assert::AreEqual(9,  "This, is : separator."_S.IndexOfAny(separators, 5, 5), pcf_current_information);
      TUnit::Assert::AreEqual(-1, "This, is : separator."_S.IndexOfAny(separators, 5, 4), pcf_current_information);
      
      String xxxx_ = "xxxx_";
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 0, 5), pcf_current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 1, 4), pcf_current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 2, 3), pcf_current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 3, 2), pcf_current_information);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 4, 1), pcf_current_information);
      TUnit::Assert::AreEqual(-1, xxxx_.IndexOfAny(separators, 5, 0), pcf_current_information);
    }
    
    void IndexOfAnyExceptions() {
      Array<char32> separators = {'.', ',', ':','_'};
      
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This, is : separator."_S.IndexOfAny(separators, 22);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This, is : separator."_S.IndexOfAny(separators, 18,5);}, pcf_current_information);
      
      String xxxx_ = String("xxxx_");
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, -1,3);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, 0,-1);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, 2,-1);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, 0,6);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, 1,5);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, 2,4);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, 3,3);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, 4,2);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {xxxx_.IndexOfAny(separators, 5,1);}, pcf_current_information);
    }
    
    void Join() {
      Array<string> array = {"123", "a text", "ok"};
      TUnit::Assert::AreEqual("123, a text, ok", string::Join(", ", array, 0, 3), pcf_current_information);
    }
    
    void JoinN() {
      string join[] = {"blue", "red", "green", "yellow"};
      TUnit::Assert::AreEqual("blue, red, green, yellow", string::Join(", ", join, 4), pcf_current_information);
      TUnit::Assert::AreEqual("red, green", string::Join(", ", join, 4, 1, 2), pcf_current_information);
    }
    
    void JoinNExceptions() {
      string join[] = {"blue", "red", "green", "yellow"};
      TUnit::Assert::Throws<ArgumentNullException>(pcf_delegate {string::Join(", ", null, 4);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {string::Join(", ", join, 4,4,2);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {string::Join(", ", join, 4,1,4);}, pcf_current_information);
    }
    
    void LastIndexOf() {
      TUnit::Assert::AreEqual(26, "This is the beast of the beast"_S.LastIndexOf('e'), pcf_current_information);
      TUnit::Assert::AreEqual(26, "This is the beast of the beast"_S.LastIndexOf('e', 3), pcf_current_information);
      TUnit::Assert::AreEqual(13, "This is the beast of the beast"_S.LastIndexOf('e', 11, 3), pcf_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf('e', 11, 2), pcf_current_information);
      
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the"), pcf_current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the", 19), pcf_current_information);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the", 19, 5), pcf_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf("the", 19, 4), pcf_current_information);
      TUnit::Assert::AreEqual(8, "This is the beast of the beast"_S.LastIndexOf("the", 5, 6), pcf_current_information);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf("the", 5, 5), pcf_current_information);
    }
    
    void LastIndexOfExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This is the beast of the beast"_S.LastIndexOf('e', 31);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This is the beast of the beast"_S.LastIndexOf('e', 29,2);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This is the beast of the beast"_S.LastIndexOf("the", 31);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This is the beast of the beast"_S.LastIndexOf("the", 29, 2);}, pcf_current_information);
    }
    
    void LastIndexOfAny() {
      char32 nativeSeparator[] = {'.', ',', ':'};
      TUnit::Assert::AreEqual(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3)), pcf_current_information);
      TUnit::Assert::AreEqual(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5), pcf_current_information);
      TUnit::Assert::AreEqual(9, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 5), pcf_current_information);
      TUnit::Assert::AreEqual(-1, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 4), pcf_current_information);
    }
    
    void LastIndexOfAnyException() {
      char32 nativeSeparator[] = {'.', ',', ':'};
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 22);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 18,5);}, pcf_current_information);
    }
    
    void PadLeft() {
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(13), pcf_current_information);
      TUnit::Assert::AreEqual(" string To Pad", "string To Pad"_S.PadLeft(14), pcf_current_information);
      TUnit::Assert::AreEqual("  string To Pad", "string To Pad"_S.PadLeft(15), pcf_current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(12, '*'), pcf_current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(13, '*'), pcf_current_information);
      TUnit::Assert::AreEqual("*string To Pad", "string To Pad"_S.PadLeft(14, '*'), pcf_current_information);
      TUnit::Assert::AreEqual("**string To Pad", "string To Pad"_S.PadLeft(15, '*'), pcf_current_information);
    }
    
    void PadRight() {
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(13), pcf_current_information);
      TUnit::Assert::AreEqual("string To Pad ", "string To Pad"_S.PadRight(14), pcf_current_information);
      TUnit::Assert::AreEqual("string To Pad  ", "string To Pad"_S.PadRight(15), pcf_current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(12, '*'), pcf_current_information);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(13, '*'), pcf_current_information);
      TUnit::Assert::AreEqual("string To Pad*", "string To Pad"_S.PadRight(14, '*'), pcf_current_information);
      TUnit::Assert::AreEqual("string To Pad**", "string To Pad"_S.PadRight(15, '*'), pcf_current_information);
    }
    
    void Remove() {
      TUnit::Assert::AreEqual("", "abc123ABC"_S.Remove(0),pcf_current_information);
      TUnit::Assert::AreEqual("abc", "abc123ABC"_S.Remove(3), pcf_current_information);
      TUnit::Assert::AreEqual("abcABC", "abc123ABC"_S.Remove(3, 3), pcf_current_information);
      TUnit::Assert::AreEqual("abc", "abc123ABC"_S.Remove(3, 6), pcf_current_information);
      TUnit::Assert::AreEqual("abc123ABC", "abc123ABC"_S.Remove(9), pcf_current_information);
    }
    
    void RemoveExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"abc123ABC"_S.Remove(10);}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"abc123ABC"_S.Remove(8,2);}, pcf_current_information);
    }

    void Insert() {
      TUnit::Assert::AreEqual("abc", ""_S.Insert(0,"abc"));
      TUnit::Assert::AreEqual("abc123ABC", "abcABC"_S.Insert(3,"123"));
      TUnit::Assert::AreEqual("abc123", "abc"_S.Insert(3,"123"));
    }
    void InsertExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"ok"_S.Insert(-1,"abc");}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {""_S.Insert(1,"abc");}, pcf_current_information);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {"abc"_S.Insert(4,"123");}, pcf_current_information);
    }
    
    void Replace() {
      TUnit::Assert::AreEqual("This*is*the*beast*of*the*beast", "This is the beast of the beast"_S.Replace(' ', '*'), pcf_current_information);
      TUnit::Assert::AreEqual("This is thE bEast of thE bEast", "This is the beast of the beast"_S.Replace('e', 'E'), pcf_current_information);
      TUnit::Assert::AreEqual("Thare are the beast of the beast", "This is the beast of the beast"_S.Replace("is", "are"), pcf_current_information);
      TUnit::Assert::AreEqual("Th  the beast of the beast", "This is the beast of the beast"_S.Replace("is", ""), pcf_current_information);
      TUnit::Assert::AreEqual("This text has\\_unescaped\\_\\_underscores !", "This text has_unescaped__underscores !"_S.Replace("_", "\\_"), pcf_current_information);
    }
    
    void Split() {
      TUnit::Assert::AreEqual(Array<string> {}, ""_S.Split({'+', '-', '='}), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"a"}, "a"_S.Split({'+', '-', '='}), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"100", "42", "142"}, "100+42=142"_S.Split({'+', '-', '='}), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"100+42=142"}, "100+42=142"_S.Split({'%', '*'}), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"100+42=142"}, "100+42=142"_S.Split({}), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"a", "b", "c"}, "a,b,c"_S.Split(','), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"a", "", "", "b", "", "c"}, "a,,,b,,c"_S.Split(','), pcf_current_information);
    }
    
    void SplitCount() {
      TUnit::Assert::AreEqual(Array<string> {"42", " 12, 19"}, "42, 12, 19"_S.Split({',', ' '}, 2), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"42", "", "12", ".19"}, "42..12..19"_S.Split({'.'}, 4), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"Banana"}, "Banana"_S.Split({','}, 2), pcf_current_information);
      TUnit::Assert::AreEqual(Array<string> {"Darb\nSmarba "}, "Darb\nSmarba "_S.Split({}, 1), pcf_current_information);
    }
    
    void SplitWithStringSplitOptionRemoveEmptyEntries() {
      TUnit::Assert::AreEqual(Array<string> {"a", "b", "c"}, "a,,,b,,c"_S.Split(',', StringSplitOptions::RemoveEmptyEntries), pcf_current_information);
    }
  
    void SplitWithStringSplitOptioNone() {
      TUnit::Assert::AreEqual(Array<string> {"a", "", "", "b", "", "c"}, "a,,,b,,c"_S.Split(',', StringSplitOptions::None), pcf_current_information);
    }
    
    void ToUpper() {
      TUnit::Assert::AreEqual("STRING TO UPPER OR TO LOWER", "string To Upper or To Lower"_S.ToUpper(), pcf_current_information);
    }
    
    void ToLower() {
      TUnit::Assert::AreEqual("string to upper or to lower", "string To Upper or To Lower"_S.ToLower(), pcf_current_information);
    }
    
    void TrimStart() {
      TUnit::Assert::AreEqual("string To Trim", "string To Trim"_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual("string To Trim", "xxxstring To Trim"_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual("string To Trim", "xxstring To Trim"_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual("string To Trim", "xstring To Trim"_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual("", ""_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual("", "x"_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual("", "xx"_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual("", "xxx"_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual(" x", "xx x"_S.TrimStart('x'), pcf_current_information);
      TUnit::Assert::AreEqual("string To Trim Start", "          string To Trim Start"_S.TrimStart(' '), pcf_current_information);
      TUnit::Assert::AreEqual("          string To Trim Start", "          string To Trim Start"_S.TrimStart('d'), pcf_current_information);
    }
    
    void TrimSartMultiple() {
      Array<char32> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
      
      TUnit::Assert::AreEqual("abcdef1357924680", "2468013579abcdef1357924680"_S.TrimStart(numbers), pcf_current_information);
      TUnit::Assert::AreEqual("", ""_S.TrimStart(numbers), pcf_current_information);
      TUnit::Assert::AreEqual("", "24680135791357924680"_S.TrimStart(numbers), pcf_current_information);
    }

  };

  pcf_test(StringTest, StringCreatedWithDefaultConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerConstructor);
  pcf_test(StringTest, StringCreatedWithConstChar16PointerConstructor);
  pcf_test(StringTest, StringCreatedWithConstChar32PointerConstructor);
  pcf_test(StringTest, StringCreatedWithConstWCharPointerConstructor);
  pcf_test(StringTest, StringCreatedWithConstRawCharPointerConstructor);
  pcf_test(StringTest, StringCreatedWithConstRawChar16PointerConstructor);
  pcf_test(StringTest, StringCreatedWithConstRawChar32PointerConstructor);
  pcf_test(StringTest, StringCreatedWithConstRawWCharPointerConstructor);
  pcf_test(StringTest, StringCreatedWithCopyConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerNull);
  pcf_test(StringTest, StringCreatedWithConstChar16PointerNull);
  pcf_test(StringTest, StringCreatedWithConstChar32PointerNull);
  pcf_test(StringTest, StringCreatedWithConstWCharPointerNull);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndNegativeCountConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndCountInsideLengthConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor);
  pcf_test(StringTest, StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor);
  pcf_test(StringTest, StringCreatedByAssignment);
  pcf_test(StringTest, StringCreatedByAssignmentWithBackslash);
  pcf_test(StringTest, StringCreatedByAssignmentWithVerbatimBackslash);
  pcf_test(StringTest, StringCreatedByConstructorWithChars);
  pcf_test(StringTest, StringCreatedByConstructorWith32bitsChars);
  pcf_test(StringTest, CreateAStringThatConsistsOfACharacterRepeated20Times);
  pcf_test(StringTest, StringCreatedByConstructorWithPointerOnSBytes);
  pcf_test(StringTest, StringCreatedByAssignmentWithUnicodeStringLiteral);
  pcf_test(StringTest, SubscriptOperatorWithChar);
  pcf_test(StringTest, SubscriptOperatorWithChar32);
  pcf_test(StringTest, OperatorLitteralChar);
  pcf_test(StringTest, OperatorLitteralChar16);
  pcf_test(StringTest, OperatorLitteralChar32);
  pcf_test(StringTest, OperatorLitteralWChar);
  pcf_test(StringTest, OperatorAddConstCharPointer);
  pcf_test(StringTest, OperatorAddBoolean);
  pcf_test(StringTest, OperatorAddByte);
  pcf_test(StringTest, OperatorAddByteObject);
  pcf_test(StringTest, OperatorAddChar);
  pcf_test(StringTest, OperatorAddChar16);
  pcf_test(StringTest, OperatorAddChar32);
  pcf_test(StringTest, OperatorAddWChar);
  pcf_test(StringTest, OperatorAddCharObject);
  pcf_test(StringTest, OperatorAddDouble);
  pcf_test(StringTest, OperatorAddDoubleObject);
  pcf_test(StringTest, OperatorAddInt16);
  pcf_test(StringTest, OperatorAddInt16Object);
  pcf_test(StringTest, OperatorAddInt32);
  pcf_test(StringTest, OperatorAddInt32Object);
  pcf_test(StringTest, OperatorAddInt64);
  pcf_test(StringTest, OperatorAddInt64Object);
  pcf_test(StringTest, OperatorAddSByte);
  pcf_test(StringTest, OperatorAddSByteObject);
  pcf_test(StringTest, OperatorAddSingle);
  pcf_test(StringTest, OperatorAddSingleObject);
  pcf_test(StringTest, OperatorAddDateTimeObject);
  pcf_test(StringTest, CompareEmptyStrings);
  pcf_test(StringTest, CompareEmptyStringWithStringEmpty);
  pcf_test(StringTest, CompareEmptyStringWithAnyString);
  pcf_test(StringTest, CompareAnyStringWithEmptyString);
  pcf_test(StringTest, CompareSameStrings);
  pcf_test(StringTest, CompareGreaterString);
  pcf_test(StringTest, CompareLessString);
  pcf_test(StringTest, CompareIndex);
  pcf_test(StringTest, CompareEmptyStringsWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareSameStringsWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareGreaterStringWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareLessStringWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseTrue);
  pcf_test(StringTest, CompareEmptyStringsWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareSameStringsWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareGreaterStringWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareLessStringWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseFalse);
  pcf_test(StringTest, CompareIndexIgnoreCase);
  pcf_test(StringTest, Concat);
  pcf_test(StringTest, ConcatArray);
  pcf_test(StringTest, EndsWith);
  pcf_test(StringTest, EndsWithChar32);
  pcf_test(StringTest, StartsWith);
  pcf_test(StringTest, StartsWithChar32);
  pcf_test(StringTest, GetEnumeratorOnString);
  pcf_test(StringTest, ForeachOnString);
  pcf_test(StringTest, IteratorOnString);
  pcf_test(StringTest, ForOnString);
  pcf_test(StringTest, GetHashCode);
  pcf_test(StringTest, IsNullOrEmptyOnEmptyString);
  pcf_test(StringTest, IsNullOrEmptyOnNonEmptyString);
  pcf_test(StringTest, IsNullOrEmptyOnStringEmpty);
  pcf_test(StringTest, IndexOf);
  pcf_test(StringTest, IndexOfExceptions);
  pcf_test(StringTest, IndexOfAny);
  pcf_test(StringTest, IndexOfAnyExceptions);
  pcf_test(StringTest, Join);
  pcf_test(StringTest, JoinN);
  pcf_test(StringTest, JoinNExceptions);
  pcf_test(StringTest, LastIndexOf);
  pcf_test(StringTest, LastIndexOfExceptions);
  pcf_test(StringTest, LastIndexOfAny);
  pcf_test(StringTest, LastIndexOfAnyException);
  pcf_test(StringTest, PadLeft);
  pcf_test(StringTest, PadRight);
  pcf_test(StringTest, Remove);
  pcf_test(StringTest, RemoveExceptions);
  pcf_test(StringTest, Insert);
  pcf_test(StringTest, InsertExceptions);
  pcf_test(StringTest, Replace);
  pcf_test(StringTest, Split);
  pcf_test(StringTest, SplitCount);
  pcf_test(StringTest, SplitWithStringSplitOptionRemoveEmptyEntries);
  pcf_test(StringTest, SplitWithStringSplitOptioNone);
  pcf_test(StringTest, ToUpper);
  pcf_test(StringTest, ToLower);
  pcf_test(StringTest, TrimStart);
}
