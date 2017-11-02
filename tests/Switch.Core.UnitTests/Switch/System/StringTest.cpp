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
      TUnit::Assert::AreEqual("Test", string("Test"), _caller);
    }
    
    void StringCreatedWithConstChar16PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(u"Test"), _caller);
    }
    
    void StringCreatedWithConstChar32PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(U"Test"), _caller);
    }
    
    void StringCreatedWithConstWCharPointerConstructor() {
      TUnit::Assert::AreEqual(U"Test", string(L"Test"), _caller);
    }

    void StringCreatedWithConstRawCharPointerConstructor() {
      TUnit::Assert::AreEqual("Test \\ 1", string(R"(Test \ 1)"), _caller);
    }
    
    void StringCreatedWithConstRawChar16PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(uR"(Test \ 1)"), _caller);
    }
    
    void StringCreatedWithConstRawChar32PointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(UR"(Test \ 1)"), _caller);
    }
    
    void StringCreatedWithConstRawWCharPointerConstructor() {
      TUnit::Assert::AreEqual(U"Test \\ 1", string(LR"(Test \ 1)"), _caller);
    }
    
    void StringCreatedWithCopyConstructor() {
      TUnit::Assert::AreEqual("Test1", string(string("Test1")), _caller);
    }
    
    void StringCreatedWithConstCharPointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string(static_cast<const char*>(null));}, _caller);
    }
    
    void StringCreatedWithConstChar16PointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string(static_cast<const char16*>(null));}, _caller);
    }
    
    void StringCreatedWithConstChar32PointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string(static_cast<const char32*>(null));}, _caller);
    }
    
    void StringCreatedWithConstWCharPointerNull() {
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string(static_cast<const wchar*>(null));}, _caller);
    }
    
    void StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string("strTest1", -1, 0);}, _caller);
    }
    
    void StringCreatedWithConstCharPointerAndNegativeCountConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string("strTest1", 0, -1);}, _caller);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string("strTest1", 10, 2);}, _caller);
    }
    
    void StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string("strTest1", 0, 10);}, _caller);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor() {
      TUnit::Assert::AreEqual("", string("strTest1", 0, 0), _caller);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor() {
      TUnit::Assert::AreEqual("strTest1", string("strTest1", 0, 8), _caller);
    }
    
    void StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor() {
      TUnit::Assert::AreEqual("Test", string("strTest1", 3, 4), _caller);
    }
    
    void StringCreatedWithConstCharPointerAndCountInsideLengthConstructor() {
      TUnit::Assert::AreEqual("str", string("strTest1", 3), _caller);
    }
    
    void StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor() {
      TUnit::Assert::AreEqual("strTest1", string("strTest1", 8), _caller);
    }
    
    void StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor() {
      TUnit::Assert::AreEqual("str", string("str", 8), _caller);
    }
    
    void StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor() {
      TUnit::Assert::AreEqual("", string("", 8), _caller);
    }

    void StringCreatedByAssignment() {
      String s = "This is a string created by assignment.";
      TUnit::Assert::AreEqual("This is a string created by assignment.", s, _caller);
    }

    void StringCreatedByAssignmentWithBackslash() {
      String s = "The path is C:\\PublicDocuments\\Report1.doc";
      TUnit::Assert::AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s, _caller);
    }

    void StringCreatedByAssignmentWithVerbatimBackslash() {
      String s = R"(The path is C:\PublicDocuments\Report1.doc)";
      TUnit::Assert::AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s, _caller);
    }

    void StringCreatedByConstructorWithChars() {
      Array<char> chars = { 'w', 'o', 'r', 'd' };
      String s(chars);
      TUnit::Assert::AreEqual("word", s, _caller);
    }

    void StringCreatedByConstructorWith32bitsChars() {
      Array<char32> chars = { 'w', 'o', 'r', 'd' };
      String s(chars);
      TUnit::Assert::AreEqual("word", s, _caller);
    }

    void CreateAStringThatConsistsOfACharacterRepeated20Times() {
      String s('C', 20);
      TUnit::Assert::AreEqual("CCCCCCCCCCCCCCCCCCCC", s, _caller);
    }

    void StringCreatedByConstructorWithPointerOnSBytes() {
      sbyte bytes[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x00 };
      string s(bytes);
      TUnit::Assert::AreEqual("ABCDE", s, _caller);
    }
    
    void StringCreatedByAssignmentWithUnicodeStringLiteral() {
      string s = U"こんにちは世界!";
      TUnit::Assert::AreEqual(U"こんにちは世界!", s, _caller);
    }
    
    void SubscriptOperatorWithChar() {
      Array<char> chars = {'T', 'e', 's', 't'};
      string s = "Test";
      for (int i = 0; i < chars.Length; i++)
        TUnit::Assert::AreEqual(chars[i], static_cast<char>(s[i]), _caller);
    }
    
    void SubscriptOperatorWithChar32() {
      Array<char32> chars = {U'こ', U'ん', U'に', U'ち', U'は', U'世', U'界', U'!'};
      string s = U"こんにちは世界!";
      int i = 0;
      for (char32 c : chars)
        TUnit::Assert::AreEqual(c, s[i++], _caller);
      TUnit::Assert::AreEqual(chars.Length, i, _caller);
    }
    
    void OperatorLitteralChar() {
      TUnit::Assert::AreEqual("Switch::System::String", _typeof("Test"_S).ToString(), _caller);
    }
    
    void OperatorLitteralChar16() {
      TUnit::Assert::AreEqual("Switch::System::String", _typeof(u"Test"_S).ToString(), _caller);
    }
    
    void OperatorLitteralChar32() {
      TUnit::Assert::AreEqual("Switch::System::String", _typeof(U"Test"_S).ToString(), _caller);
    }
    
    void OperatorLitteralWChar() {
      TUnit::Assert::AreEqual("Switch::System::String", _typeof(L"Test"_S).ToString(), _caller);
    }
    
    void OperatorAddConstCharPointer() {
      TUnit::Assert::AreEqual("string A string B", string("string A ") + "string B", _caller);
    }
    
    void OperatorAddBoolean() {
      TUnit::Assert::AreEqual("string A False", string("string A ") + false, _caller);
    }
    
    void OperatorAddBooleanObject() {
      TUnit::Assert::AreEqual("string A True", string("string A ") + Boolean(true), _caller);
    }
    
    void OperatorAddByte() {
      TUnit::Assert::AreEqual("string A 18", string("string A ") + static_cast<byte>(18), _caller);
    }
    
    void OperatorAddByteObject() {
      TUnit::Assert::AreEqual("string A 15", string("string A ") + Byte(15), _caller);
    }
    
    void OperatorAddChar() {
      TUnit::Assert::AreEqual("string A a", string("string A ") + 'a', _caller);
    }
    
    void OperatorAddChar16() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + u'd', _caller);
    }
    
    void OperatorAddChar32() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + U'd', _caller);
    }
    
    void OperatorAddWChar() {
      TUnit::Assert::AreEqual("string A d", string("string A ") + L'd', _caller);
    }
    
    void OperatorAddCharObject() {
      TUnit::Assert::AreEqual("string A G", string("string A ") + Char('G'), _caller);
    }
    
    void OperatorAddDouble() {
      TUnit::Assert::AreEqual("string A -0.987678", string("string A ") + -0.987678, _caller);
    }
    
    void OperatorAddDoubleObject() {
      TUnit::Assert::AreEqual("string A -0.987678", string("string A ") + Double(-0.987678), _caller);
    }
    
    void OperatorAddInt16() {
      TUnit::Assert::AreEqual("string A -32768", string("string A ") + Int16::MinValue, _caller);
    }
    
    void OperatorAddInt16Object() {
      TUnit::Assert::AreEqual("string A 32767", string("string A ") + Int16(Int16::MaxValue), _caller);
    }
    
    void OperatorAddInt32() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<int32>(42), _caller);
    }
    
    void OperatorAddInt32Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + Int32(5467), _caller);
    }
    
    void OperatorAddInt64() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<int64>(42), _caller);
    }
    
    void OperatorAddInt64Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + Int64(5467), _caller);
    }
    
    void OperatorAddSByte() {
      TUnit::Assert::AreEqual("string A -2", string("string A ") + static_cast<sbyte>(-2), _caller);
    }
    
    void OperatorAddSByteObject() {
      TUnit::Assert::AreEqual("string A 15", string("string A ") + SByte(15), _caller);
    }
    
    void OperatorAddUInt16() {
      TUnit::Assert::AreEqual("string A 0", string("string A ") + UInt16::MinValue, _caller);
    }
    
    void OperatorAddUInt16Object() {
      TUnit::Assert::AreEqual("string A 6345", string("string A ") + UInt16(6345), _caller);
    }
    
    void OperatorAddUInt32() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<uint32>(42), _caller);
    }
    
    void OperatorAddUInt32Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + UInt32(5467), _caller);
    }
    
    void OperatorAddUInt64() {
      TUnit::Assert::AreEqual("string A 42", string("string A ") + static_cast<uint64>(42), _caller);
    }
    
    void OperatorAddUInt64Object() {
      TUnit::Assert::AreEqual("string A 5467", string("string A ") + UInt64(5467), _caller);
    }
    
    void OperatorAddSingle() {
      TUnit::Assert::AreEqual("string A 0.0654", string("string A ") + 0.0654f, _caller);
    }
    
    void OperatorAddSingleObject() {
      TUnit::Assert::AreEqual("string A 0.0654", string("string A ") + Single(0.0654f), _caller);
    }
    
    void OperatorAddDateTimeObject() {
      TUnit::Assert::AreEqual("string A 01/01/1970 00:00:00", string("string A ") + DateTime(1970, 1, 1, 0, 0, 0), _caller);
    }
    
    void CompareEmptyStrings() {
      TUnit::Assert::IsTrue(string::Compare("", "") ==  0, _caller);
    }
    
    void CompareEmptyStringWithStringEmpty() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty) ==  0, _caller);
    }
    
    void CompareEmptyStringWithAnyString() {
      TUnit::Assert::IsTrue(string::Compare("", "string To Compare") < 0, _caller);
    }
    
    void CompareAnyStringWithEmptyString() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "") > 0, _caller);
    }
    
    void CompareSameStrings() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Compare") == 0, _caller);
    }
    
    void CompareGreaterString() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Comp") > 0, _caller);
    }
    
    void CompareLessString() {
      TUnit::Assert::IsTrue(string::Compare("string To Comp", "string To Compare") < 0, _caller);
    }
    
    void CompareIndex() {
      TUnit::Assert::IsTrue(string::Compare("Char To Compare", 4, "string To Compare", 6, 11) == 0, _caller);
    }
    
    void CompareEmptyStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", "", true) == 0, _caller);
    }
    
    void CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty, true) ==  0, _caller);
    }
    
    void CompareEmptyStringWithAnyStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("", "string To compare", true) < 0, _caller);
    }
    
    void CompareAnyStringWithEmptyStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string To compare", "", true) > 0, _caller);
    }
    
    void CompareSameStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", true) == 0, _caller);
    }
    
    void CompareGreaterStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", true) > 0, _caller);
    }
    
    void CompareLessStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", true) < 0, _caller);
    }
    
    void CompareDifferentCaseStringsWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", true) == 0, _caller);
    }
    
    void CompareGreaterDifferentCaseStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", true) > 0, _caller);
    }
    
    void CompareLessDifferentCaseStringWithIgnoreCaseTrue() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", true) < 0, _caller);
    }
    
    void CompareEmptyStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", "", false) == 0, _caller);
    }
    
    void CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", String::Empty, false) ==  0, _caller);
    }
    
    void CompareEmptyStringWithAnyStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("", "string To Compare",false) < 0, _caller);
    }
    
    void CompareAnyStringWithEmptyStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "",false) > 0, _caller);
    }
    
    void CompareSameStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Compare",false) == 0, _caller);
    }
    
    void CompareGreaterStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Compare", "string To Comp",false) > 0, _caller);
    }
    
    void CompareLessStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string To Comp", "string To Compare",false) < 0, _caller);
    }
    
    void CompareDifferentCaseStringsWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Compare", false) > 0, _caller);
    }
    
    void CompareGreaterDifferentCaseStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to compare", "string To Comp", false) > 0, _caller);
    }
    
    void CompareLessDifferentCaseStringWithIgnoreCaseFalse() {
      TUnit::Assert::IsTrue(string::Compare("string to comp", "string To Compare", false) > 0, _caller);
    }
    
    void CompareIndexIgnoreCase() {
      TUnit::Assert::IsTrue(string::Compare("Char to compare", 4, "string To Compare", 6, 11,true) == 0, _caller);
      TUnit::Assert::IsTrue(string::Compare("Char to compare", 4, "string To Compare", 6, 11,true) == 0, _caller);
      TUnit::Assert::IsTrue(string::Compare("Char to Compare", 4, "string TO Compare", 6, 11, false) > 0, _caller);
      TUnit::Assert::IsTrue(string::Compare("Char To Compare", 4, "string To Compare", 6, 11,false) == 0, _caller);
    }
    
    void Concat() {
      TUnit::Assert::AreEqual(Object().ToString(), string::Concat(Object()), _caller);
      TUnit::Assert::AreEqual(Object().ToString() + Object().ToString() + Object().ToString(), string::Concat<>(Array<Object> {Object(), Object(), Object()}), _caller);
      TUnit::Assert::AreEqual(Object().ToString() + Object().ToString(), string::Concat(Object(), Object()), _caller);
      TUnit::Assert::AreEqual( Object().ToString() + Object().ToString() + Object().ToString(), string::Concat(Object(), Object(), Object()),_caller);
      
      TUnit::Assert::AreEqual("264", string::Concat(UInt32(264)), _caller);
      TUnit::Assert::AreEqual("True", string::Concat(Boolean(true)), _caller);
      TUnit::Assert::AreEqual("string to concatenate", string::Concat(string("string to concatenate")), _caller);
      
      TUnit::Assert::AreEqual("264128", string::Concat(UInt32(264), UInt32(128)), _caller);
      TUnit::Assert::AreEqual("TrueFalse", string::Concat(Boolean(true), Boolean(false)), _caller);
      TUnit::Assert::AreEqual("string Astring B", string::Concat("string A", "string B"), _caller);
      TUnit::Assert::AreEqual("264128378", string::Concat(UInt32(264), UInt32(128), UInt32(378)), _caller);
      TUnit::Assert::AreEqual("TrueFalseTrue", string::Concat(Boolean(true), Boolean(false), Boolean(true)), _caller);
      TUnit::Assert::AreEqual("string Astring Bstring C", string::Concat("string A", "string B", "string C"), _caller);
      TUnit::Assert::AreEqual("string Astring Bstring Cstring D", string::Concat("string A", "string B", "string C", "string D"), _caller);
    }
    
    void ConcatArray() {
      TUnit::Assert::AreEqual("264128378842", string::Concat<>(Array<Int32> {264, 128, 378, 842}), _caller);
      TUnit::Assert::AreEqual("TrueFalseTrue", string::Concat<>(Array<Boolean> {true, false, true}), _caller);
      TUnit::Assert::AreEqual("string To Concat", string::Concat<>(Array<string> {"string ", "To ", "Concat"}), _caller);
    }
    
    void EndsWith() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith("beast"), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith("Beast"), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith("Beast", false), _caller);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith("Beast", true), _caller);
    }
    
    void EndsWithChar32() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith('t'), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('T'), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('s'), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.EndsWith('T', false), _caller);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.EndsWith('T', true), _caller);
    }
    
    void StartsWith() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith("This"), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith("this"), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith("this", false), _caller);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith("this", true), _caller);
    }
    
    void StartsWithChar32() {
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('T'), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('t'), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('h'), _caller);
      TUnit::Assert::IsFalse("This is the beast of the beast"_S.StartsWith('t', false), _caller);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('t', true), _caller);
      TUnit::Assert::IsTrue("This is the beast of the beast"_S.StartsWith('T', true), _caller);
    }
    
    void GetEnumeratorOnString() {
      string str = "This is a test for enumerator";
      string output;
      System::Collections::Generic::Enumerator<char32> enumerator = str.GetEnumerator();
      while (enumerator.MoveNext())
        output += enumerator.Current;
      TUnit::Assert::AreEqual("This is a test for enumerator", output, _caller);
    }
    
    void ForeachOnString() {
      string str = "This is a test for foreach";
      string output;
      for (char32 item : str)
        output += item;
      TUnit::Assert::AreEqual("This is a test for foreach", output, _caller);
    }
    
    void IteratorOnString() {
      string str = "This is a test for iterator";
      string output;
      for (string::const_iterator iterator = str.cbegin(); iterator != str.cend(); ++iterator)
        output += *iterator;
      TUnit::Assert::AreEqual("This is a test for iterator", output, _caller);
    }
    
    void ForOnString() {
      string str = "This is a test for for";
      string output;
      for (int32 index = 0; index < str.Length; ++index)
        output += str[index];
      TUnit::Assert::AreEqual("This is a test for for", output, _caller);
    }
    
    void GetHashCode() {
      TUnit::Assert::AreNotEqual("A"_S.GetHashCode(), "B"_S.GetHashCode(), _caller);
      TUnit::Assert::AreEqual("ABCD"_S.GetHashCode(),"ABCD"_S.GetHashCode(), _caller);
      TUnit::Assert::AreNotEqual("ABCD"_S.GetHashCode(), "ABCE"_S.GetHashCode(), _caller);
      TUnit::Assert::AreEqual("ABCDE"_S.GetHashCode(), "ABCDE"_S.GetHashCode(), _caller);
      TUnit::Assert::AreNotEqual("My string"_S.GetHashCode(), "My Strinh"_S.GetHashCode(), _caller);
      TUnit::Assert::AreNotEqual("My string"_S.GetHashCode(), "My Gtrins"_S.GetHashCode(), _caller);
      TUnit::Assert::AreEqual("another string"_S.GetHashCode(), "another string"_S.GetHashCode(), _caller);
      
      refptr<string> clone;
      string testClone("Test Clone");
      clone = as<string>(testClone.Clone());
      TUnit::Assert::AreEqual(testClone.GetHashCode(),clone->GetHashCode(), _caller);
    }
    
    void IsNullOrEmptyOnEmptyString() {
      TUnit::Assert::IsTrue(string::IsNullOrEmpty(""_S), _caller);
    }
    
    void IsNullOrEmptyOnNonEmptyString() {
      TUnit::Assert::IsFalse(string::IsNullOrEmpty("Not Empty"_S), _caller);
    }
    
    void IsNullOrEmptyOnStringEmpty() {
      TUnit::Assert::IsTrue(string::IsNullOrEmpty(string::Empty), _caller);
    }
    
    void IndexOf() {
      TUnit::Assert::AreEqual(2, "This is the beast of the beast"_S.IndexOf('i'), _caller);
      TUnit::Assert::AreEqual(5, "This is the beast of the beast"_S.IndexOf('i', 3), _caller);
      TUnit::Assert::AreEqual(5, "This is the beast of the beast"_S.IndexOf('i', 3, 3), _caller);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf('i', 3, 2), _caller);
      TUnit::Assert::AreEqual(29, "This is the beast of the beast"_S.IndexOf('t', 29), _caller);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf('t', 30), _caller);
      
      TUnit::Assert::AreEqual(8, "This is the beast of the beast"_S.IndexOf("the"), _caller);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.IndexOf("the", 19), _caller);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.IndexOf("the", 19, 5), _caller);
      
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.IndexOf("the", 18, 3), _caller);
    }
    
    void IndexOfExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.IndexOf('i', 31);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.IndexOf('i', 26,5);}, _caller);
      
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.IndexOf("the", 31);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.IndexOf("the", 26,5);}, _caller);
    }
    
    void IndexOfAny() {
      Array<char32> separators = {'.', ',', ':','_'};
      
      TUnit::Assert::AreEqual(4,  "This, is : separator."_S.IndexOfAny(separators), _caller);
      TUnit::Assert::AreEqual(9,  "This, is : separator."_S.IndexOfAny(separators, 5), _caller);
      TUnit::Assert::AreEqual(9,  "This, is : separator."_S.IndexOfAny(separators, 5, 5), _caller);
      TUnit::Assert::AreEqual(-1, "This, is : separator."_S.IndexOfAny(separators, 5, 4), _caller);
      
      String xxxx_ = "xxxx_";
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 0, 5), _caller);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 1, 4), _caller);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 2, 3), _caller);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 3, 2), _caller);
      TUnit::Assert::AreEqual(4, xxxx_.IndexOfAny(separators, 4, 1), _caller);
      TUnit::Assert::AreEqual(-1, xxxx_.IndexOfAny(separators, 5, 0), _caller);
    }
    
    void IndexOfAnyExceptions() {
      Array<char32> separators = {'.', ',', ':','_'};
      
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This, is : separator."_S.IndexOfAny(separators, 22);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This, is : separator."_S.IndexOfAny(separators, 18,5);}, _caller);
      
      String xxxx_ = String("xxxx_");
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, -1,3);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 0,-1);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 2,-1);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 0,6);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 1,5);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 2,4);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 3,3);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 4,2);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {xxxx_.IndexOfAny(separators, 5,1);}, _caller);
    }
    
    void Join() {
      Array<string> array = {"123", "a text", "ok"};
      TUnit::Assert::AreEqual("123, a text, ok", string::Join(", ", array, 0, 3), _caller);
    }
    
    void JoinN() {
      string join[] = {"blue", "red", "green", "yellow"};
      TUnit::Assert::AreEqual("blue, red, green, yellow", string::Join(", ", join, 4), _caller);
      TUnit::Assert::AreEqual("red, green", string::Join(", ", join, 4, 1, 2), _caller);
    }
    
    void JoinNExceptions() {
      string join[] = {"blue", "red", "green", "yellow"};
      TUnit::Assert::Throws<ArgumentNullException>(_delegate {string::Join(", ", null, 4);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string::Join(", ", join, 4,4,2);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {string::Join(", ", join, 4,1,4);}, _caller);
    }
    
    void LastIndexOf() {
      TUnit::Assert::AreEqual(26, "This is the beast of the beast"_S.LastIndexOf('e'), _caller);
      TUnit::Assert::AreEqual(26, "This is the beast of the beast"_S.LastIndexOf('e', 3), _caller);
      TUnit::Assert::AreEqual(13, "This is the beast of the beast"_S.LastIndexOf('e', 11, 3), _caller);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf('e', 11, 2), _caller);
      
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the"), _caller);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the", 19), _caller);
      TUnit::Assert::AreEqual(21, "This is the beast of the beast"_S.LastIndexOf("the", 19, 5), _caller);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf("the", 19, 4), _caller);
      TUnit::Assert::AreEqual(8, "This is the beast of the beast"_S.LastIndexOf("the", 5, 6), _caller);
      TUnit::Assert::AreEqual(-1, "This is the beast of the beast"_S.LastIndexOf("the", 5, 5), _caller);
    }
    
    void LastIndexOfExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.LastIndexOf('e', 31);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.LastIndexOf('e', 29,2);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.LastIndexOf("the", 31);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This is the beast of the beast"_S.LastIndexOf("the", 29, 2);}, _caller);
    }
    
    void LastIndexOfAny() {
      char32 nativeSeparator[] = {'.', ',', ':'};
      TUnit::Assert::AreEqual(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3)), _caller);
      TUnit::Assert::AreEqual(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5), _caller);
      TUnit::Assert::AreEqual(9, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 5), _caller);
      TUnit::Assert::AreEqual(-1, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 4), _caller);
    }
    
    void LastIndexOfAnyException() {
      char32 nativeSeparator[] = {'.', ',', ':'};
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 22);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 18,5);}, _caller);
    }
    
    void PadLeft() {
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(13), _caller);
      TUnit::Assert::AreEqual(" string To Pad", "string To Pad"_S.PadLeft(14), _caller);
      TUnit::Assert::AreEqual("  string To Pad", "string To Pad"_S.PadLeft(15), _caller);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(12, '*'), _caller);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadLeft(13, '*'), _caller);
      TUnit::Assert::AreEqual("*string To Pad", "string To Pad"_S.PadLeft(14, '*'), _caller);
      TUnit::Assert::AreEqual("**string To Pad", "string To Pad"_S.PadLeft(15, '*'), _caller);
    }
    
    void PadRight() {
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(13), _caller);
      TUnit::Assert::AreEqual("string To Pad ", "string To Pad"_S.PadRight(14), _caller);
      TUnit::Assert::AreEqual("string To Pad  ", "string To Pad"_S.PadRight(15), _caller);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(12, '*'), _caller);
      TUnit::Assert::AreEqual("string To Pad", "string To Pad"_S.PadRight(13, '*'), _caller);
      TUnit::Assert::AreEqual("string To Pad*", "string To Pad"_S.PadRight(14, '*'), _caller);
      TUnit::Assert::AreEqual("string To Pad**", "string To Pad"_S.PadRight(15, '*'), _caller);
    }
    
    void Remove() {
      TUnit::Assert::AreEqual("", "abc123ABC"_S.Remove(0),_caller);
      TUnit::Assert::AreEqual("abc", "abc123ABC"_S.Remove(3), _caller);
      TUnit::Assert::AreEqual("abcABC", "abc123ABC"_S.Remove(3, 3), _caller);
      TUnit::Assert::AreEqual("abc", "abc123ABC"_S.Remove(3, 6), _caller);
      TUnit::Assert::AreEqual("abc123ABC", "abc123ABC"_S.Remove(9), _caller);
    }
    
    void RemoveExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"abc123ABC"_S.Remove(10);}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"abc123ABC"_S.Remove(8,2);}, _caller);
    }

    void Insert() {
      TUnit::Assert::AreEqual("abc", ""_S.Insert(0,"abc"));
      TUnit::Assert::AreEqual("abc123ABC", "abcABC"_S.Insert(3,"123"));
      TUnit::Assert::AreEqual("abc123", "abc"_S.Insert(3,"123"));
    }
    void InsertExceptions() {
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"ok"_S.Insert(-1,"abc");}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {""_S.Insert(1,"abc");}, _caller);
      TUnit::Assert::Throws<ArgumentOutOfRangeException>(_delegate {"abc"_S.Insert(4,"123");}, _caller);
    }
    
    void Replace() {
      TUnit::Assert::AreEqual("This*is*the*beast*of*the*beast", "This is the beast of the beast"_S.Replace(' ', '*'), _caller);
      TUnit::Assert::AreEqual("This is thE bEast of thE bEast", "This is the beast of the beast"_S.Replace('e', 'E'), _caller);
      TUnit::Assert::AreEqual("Thare are the beast of the beast", "This is the beast of the beast"_S.Replace("is", "are"), _caller);
      TUnit::Assert::AreEqual("Th  the beast of the beast", "This is the beast of the beast"_S.Replace("is", ""), _caller);
      TUnit::Assert::AreEqual("This text has\\_unescaped\\_\\_underscores !", "This text has_unescaped__underscores !"_S.Replace("_", "\\_"), _caller);
    }
    
    void Split() {
      TUnit::Assert::AreEqual(Array<string> {}, ""_S.Split({'+', '-', '='}), _caller);
      TUnit::Assert::AreEqual(Array<string> {"a"}, "a"_S.Split({'+', '-', '='}), _caller);
      TUnit::Assert::AreEqual(Array<string> {"100", "42", "142"}, "100+42=142"_S.Split({'+', '-', '='}), _caller);
      TUnit::Assert::AreEqual(Array<string> {"100+42=142"}, "100+42=142"_S.Split({'%', '*'}), _caller);
      TUnit::Assert::AreEqual(Array<string> {"100+42=142"}, "100+42=142"_S.Split({}), _caller);
      TUnit::Assert::AreEqual(Array<string> {"a", "b", "c"}, "a,b,c"_S.Split(','), _caller);
      TUnit::Assert::AreEqual(Array<string> {"a", "", "", "b", "", "c"}, "a,,,b,,c"_S.Split(','), _caller);
    }
    
    void SplitCount() {
      TUnit::Assert::AreEqual(Array<string> {"42", " 12, 19"}, "42, 12, 19"_S.Split({',', ' '}, 2), _caller);
      TUnit::Assert::AreEqual(Array<string> {"42", "", "12", ".19"}, "42..12..19"_S.Split({'.'}, 4), _caller);
      TUnit::Assert::AreEqual(Array<string> {"Banana"}, "Banana"_S.Split({','}, 2), _caller);
      TUnit::Assert::AreEqual(Array<string> {"Darb\nSmarba "}, "Darb\nSmarba "_S.Split({}, 1), _caller);
    }
    
    void SplitWithStringSplitOptionRemoveEmptyEntries() {
      TUnit::Assert::AreEqual(Array<string> {"a", "b", "c"}, "a,,,b,,c"_S.Split(',', StringSplitOptions::RemoveEmptyEntries), _caller);
    }
  
    void SplitWithStringSplitOptioNone() {
      TUnit::Assert::AreEqual(Array<string> {"a", "", "", "b", "", "c"}, "a,,,b,,c"_S.Split(',', StringSplitOptions::None), _caller);
    }
    
    void ToUpper() {
      TUnit::Assert::AreEqual("STRING TO UPPER OR TO LOWER", "string To Upper or To Lower"_S.ToUpper(), _caller);
    }
    
    void ToLower() {
      TUnit::Assert::AreEqual("string to upper or to lower", "string To Upper or To Lower"_S.ToLower(), _caller);
    }
    
    void TrimStart() {
      TUnit::Assert::AreEqual("string To Trim", "string To Trim"_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual("string To Trim", "xxxstring To Trim"_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual("string To Trim", "xxstring To Trim"_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual("string To Trim", "xstring To Trim"_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual("", ""_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual("", "x"_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual("", "xx"_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual("", "xxx"_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual(" x", "xx x"_S.TrimStart('x'), _caller);
      TUnit::Assert::AreEqual("string To Trim Start", "          string To Trim Start"_S.TrimStart(' '), _caller);
      TUnit::Assert::AreEqual("          string To Trim Start", "          string To Trim Start"_S.TrimStart('d'), _caller);
    }
    
    void TrimSartMultiple() {
      Array<char32> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
      
      TUnit::Assert::AreEqual("abcdef1357924680", "2468013579abcdef1357924680"_S.TrimStart(numbers), _caller);
      TUnit::Assert::AreEqual("", ""_S.TrimStart(numbers), _caller);
      TUnit::Assert::AreEqual("", "24680135791357924680"_S.TrimStart(numbers), _caller);
    }

  };

  _add_test(StringTest, StringCreatedWithDefaultConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerConstructor)
  _add_test(StringTest, StringCreatedWithConstChar16PointerConstructor)
  _add_test(StringTest, StringCreatedWithConstChar32PointerConstructor)
  _add_test(StringTest, StringCreatedWithConstWCharPointerConstructor)
  _add_test(StringTest, StringCreatedWithConstRawCharPointerConstructor)
  _add_test(StringTest, StringCreatedWithConstRawChar16PointerConstructor)
  _add_test(StringTest, StringCreatedWithConstRawChar32PointerConstructor)
  _add_test(StringTest, StringCreatedWithConstRawWCharPointerConstructor)
  _add_test(StringTest, StringCreatedWithCopyConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerNull)
  _add_test(StringTest, StringCreatedWithConstChar16PointerNull)
  _add_test(StringTest, StringCreatedWithConstChar32PointerNull)
  _add_test(StringTest, StringCreatedWithConstWCharPointerNull)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndNegativeCountConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndCountInsideLengthConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor)
  _add_test(StringTest, StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor)
  _add_test(StringTest, StringCreatedByAssignment)
  _add_test(StringTest, StringCreatedByAssignmentWithBackslash)
  _add_test(StringTest, StringCreatedByAssignmentWithVerbatimBackslash)
  _add_test(StringTest, StringCreatedByConstructorWithChars)
  _add_test(StringTest, StringCreatedByConstructorWith32bitsChars)
  _add_test(StringTest, CreateAStringThatConsistsOfACharacterRepeated20Times)
  _add_test(StringTest, StringCreatedByConstructorWithPointerOnSBytes)
  _add_test(StringTest, StringCreatedByAssignmentWithUnicodeStringLiteral)
  _add_test(StringTest, SubscriptOperatorWithChar)
  _add_test(StringTest, SubscriptOperatorWithChar32)
  _add_test(StringTest, OperatorLitteralChar)
  _add_test(StringTest, OperatorLitteralChar16)
  _add_test(StringTest, OperatorLitteralChar32)
  _add_test(StringTest, OperatorLitteralWChar)
  _add_test(StringTest, OperatorAddConstCharPointer)
  _add_test(StringTest, OperatorAddBoolean)
  _add_test(StringTest, OperatorAddByte)
  _add_test(StringTest, OperatorAddByteObject)
  _add_test(StringTest, OperatorAddChar)
  _add_test(StringTest, OperatorAddChar16)
  _add_test(StringTest, OperatorAddChar32)
  _add_test(StringTest, OperatorAddWChar)
  _add_test(StringTest, OperatorAddCharObject)
  _add_test(StringTest, OperatorAddDouble)
  _add_test(StringTest, OperatorAddDoubleObject)
  _add_test(StringTest, OperatorAddInt16)
  _add_test(StringTest, OperatorAddInt16Object)
  _add_test(StringTest, OperatorAddInt32)
  _add_test(StringTest, OperatorAddInt32Object)
  _add_test(StringTest, OperatorAddInt64)
  _add_test(StringTest, OperatorAddInt64Object)
  _add_test(StringTest, OperatorAddSByte)
  _add_test(StringTest, OperatorAddSByteObject)
  _add_test(StringTest, OperatorAddSingle)
  _add_test(StringTest, OperatorAddSingleObject)
  _add_test(StringTest, OperatorAddDateTimeObject)
  _add_test(StringTest, CompareEmptyStrings)
  _add_test(StringTest, CompareEmptyStringWithStringEmpty)
  _add_test(StringTest, CompareEmptyStringWithAnyString)
  _add_test(StringTest, CompareAnyStringWithEmptyString)
  _add_test(StringTest, CompareSameStrings)
  _add_test(StringTest, CompareGreaterString)
  _add_test(StringTest, CompareLessString)
  _add_test(StringTest, CompareIndex)
  _add_test(StringTest, CompareEmptyStringsWithIgnoreCaseTrue)
  _add_test(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue)
  _add_test(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseTrue)
  _add_test(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseTrue)
  _add_test(StringTest, CompareSameStringsWithIgnoreCaseTrue)
  _add_test(StringTest, CompareGreaterStringWithIgnoreCaseTrue)
  _add_test(StringTest, CompareLessStringWithIgnoreCaseTrue)
  _add_test(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseTrue)
  _add_test(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseTrue)
  _add_test(StringTest, CompareEmptyStringsWithIgnoreCaseFalse)
  _add_test(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse)
  _add_test(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseFalse)
  _add_test(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseFalse)
  _add_test(StringTest, CompareSameStringsWithIgnoreCaseFalse)
  _add_test(StringTest, CompareGreaterStringWithIgnoreCaseFalse)
  _add_test(StringTest, CompareLessStringWithIgnoreCaseFalse)
  _add_test(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseFalse)
  _add_test(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseFalse)
  _add_test(StringTest, CompareIndexIgnoreCase)
  _add_test(StringTest, Concat)
  _add_test(StringTest, ConcatArray)
  _add_test(StringTest, EndsWith)
  _add_test(StringTest, EndsWithChar32)
  _add_test(StringTest, StartsWith)
  _add_test(StringTest, StartsWithChar32)
  _add_test(StringTest, GetEnumeratorOnString)
  _add_test(StringTest, ForeachOnString)
  _add_test(StringTest, IteratorOnString)
  _add_test(StringTest, ForOnString)
  _add_test(StringTest, GetHashCode)
  _add_test(StringTest, IsNullOrEmptyOnEmptyString)
  _add_test(StringTest, IsNullOrEmptyOnNonEmptyString)
  _add_test(StringTest, IsNullOrEmptyOnStringEmpty)
  _add_test(StringTest, IndexOf)
  _add_test(StringTest, IndexOfExceptions)
  _add_test(StringTest, IndexOfAny)
  _add_test(StringTest, IndexOfAnyExceptions)
  _add_test(StringTest, Join)
  _add_test(StringTest, JoinN)
  _add_test(StringTest, JoinNExceptions)
  _add_test(StringTest, LastIndexOf)
  _add_test(StringTest, LastIndexOfExceptions)
  _add_test(StringTest, LastIndexOfAny)
  _add_test(StringTest, LastIndexOfAnyException)
  _add_test(StringTest, PadLeft)
  _add_test(StringTest, PadRight)
  _add_test(StringTest, Remove)
  _add_test(StringTest, RemoveExceptions)
  _add_test(StringTest, Insert)
  _add_test(StringTest, InsertExceptions)
  _add_test(StringTest, Replace)
  _add_test(StringTest, Split)
  _add_test(StringTest, SplitCount)
  _add_test(StringTest, SplitWithStringSplitOptionRemoveEmptyEntries)
  _add_test(StringTest, SplitWithStringSplitOptioNone)
  _add_test(StringTest, ToUpper)
  _add_test(StringTest, ToLower)
  _add_test(StringTest, TrimStart)
}
