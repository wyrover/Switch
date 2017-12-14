#include <Switch/System/String.hpp>
#include <gtest/gtest.h>
#include <Switch/LiteralOperatorConverter.hpp>

using namespace System;

namespace SwitchUnitTests {
  TEST(StringTest, StringCreatedWithDefaultConstructor) {
    ASSERT_EQ("", string());
  }

  TEST(StringTest, StringCreatedWithConstCharPointerConstructor) {
    ASSERT_EQ("Test", string("Test"));
  }

  TEST(StringTest, StringCreatedWithConstChar16PointerConstructor) {
    ASSERT_EQ(U"Test", string(u"Test"));
  }

  TEST(StringTest, StringCreatedWithConstChar32PointerConstructor) {
    ASSERT_EQ(U"Test", string(U"Test"));
  }

  TEST(StringTest, StringCreatedWithConstWCharPointerConstructor) {
    ASSERT_EQ(U"Test", string(L"Test"));
  }

  TEST(StringTest, StringCreatedWithConstRawCharPointerConstructor) {
    ASSERT_EQ("Test \\ 1", string(R"(Test \ 1)"));
  }

  TEST(StringTest, StringCreatedWithConstRawChar16PointerConstructor) {
    ASSERT_EQ(U"Test \\ 1", string(uR"(Test \ 1)"));
  }

  TEST(StringTest, StringCreatedWithConstRawChar32PointerConstructor) {
    ASSERT_EQ(U"Test \\ 1", string(UR"(Test \ 1)"));
  }

  TEST(StringTest, StringCreatedWithConstRawWCharPointerConstructor) {
    ASSERT_EQ(U"Test \\ 1", string(LR"(Test \ 1)"));
  }

  TEST(StringTest, StringCreatedWithCopyConstructor) {
    ASSERT_EQ("Test1", string(string("Test1")));
  }

  TEST(StringTest, StringCreatedWithConstCharPointerNull) {
    ASSERT_THROW(string(static_cast<const char*>(null)), ArgumentNullException);
  }

  TEST(StringTest, StringCreatedWithConstChar16PointerNull) {
    ASSERT_THROW(string(static_cast<const char16*>(null)), ArgumentNullException);
  }

  TEST(StringTest, StringCreatedWithConstChar32PointerNull) {
    ASSERT_THROW(string(static_cast<const char32*>(null)), ArgumentNullException);
  }

  TEST(StringTest, StringCreatedWithConstWCharPointerNull) {
    ASSERT_THROW(string(static_cast<const wchar*>(null)), ArgumentNullException);
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndNegativeStartIndexConstructor) {
    ASSERT_THROW(string("strTest1", -1, 0), ArgumentOutOfRangeException);
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndNegativeCountConstructor) {
    ASSERT_THROW(string("strTest1", 0, -1), ArgumentOutOfRangeException);
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndStartIndexGreaterThenLengthConstructor) {
    ASSERT_THROW(string("strTest1", 10, 2), ArgumentOutOfRangeException);
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndCountGraterThenLengthConstructor) {
    ASSERT_THROW(string("strTest1", 0, 10), ArgumentOutOfRangeException);
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountEqualsZeroConstructor) {
    ASSERT_EQ("", string("strTest1", 0, 0));
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndStartIndexEqualsZeroAndCountEqualLengthConstructor) {
    ASSERT_EQ("strTest1", string("strTest1", 0, 8));
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndStartIndexAndCountInsideLengthConstructor) {
    ASSERT_EQ("Test", string("strTest1", 3, 4));
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndCountInsideLengthConstructor) {
    ASSERT_EQ("str", string("strTest1", 3));
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndCountEqualsLengthConstructor) {
    ASSERT_EQ("strTest1", string("strTest1", 8));
  }

  TEST(StringTest, StringCreatedWithConstCharPointerAndCountGreaterLengthConstructor) {
    ASSERT_EQ("str", string("str", 8));
  }

  TEST(StringTest, StringCreatedWithConstCharPointerEmptyAndCountGreaterLengthConstructor) {
    ASSERT_EQ("", string("", 8));
  }

  TEST(StringTest, StringCreatedByAssignment) {
    String s = "This is a string created by assignment.";
    ASSERT_EQ("This is a string created by assignment.", s);
  }

  TEST(StringTest, StringCreatedByAssignmentWithBackslash) {
    String s = "The path is C:\\PublicDocuments\\Report1.doc";
    ASSERT_EQ("The path is C:\\PublicDocuments\\Report1.doc", s);
  }

  TEST(StringTest, StringCreatedByAssignmentWithVerbatimBackslash) {
    String s = R"(The path is C:\PublicDocuments\Report1.doc)";
    ASSERT_EQ("The path is C:\\PublicDocuments\\Report1.doc", s);
  }

  TEST(StringTest, StringCreatedByConstructorWithChars) {
    Array<char> chars = { 'w', 'o', 'r', 'd' };
    String s(chars);
    ASSERT_EQ("word", s);
  }

  TEST(StringTest, StringCreatedByConstructorWith32bitsChars) {
    Array<char32> chars = { 'w', 'o', 'r', 'd' };
    String s(chars);
    ASSERT_EQ("word", s);
  }

  TEST(StringTest, CreateAStringThatConsistsOfACharacterRepeated20Times) {
    String s('C', 20);
    ASSERT_EQ("CCCCCCCCCCCCCCCCCCCC", s);
  }

  TEST(StringTest, StringCreatedByConstructorWithPointerOnSBytes) {
    sbyte bytes[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x00 };
    string s(bytes);
    ASSERT_EQ("ABCDE", s);
  }

  #if defined(_WIN32)
#pragma warning(push)
#pragma warning(disable:4566)
  #endif
  TEST(StringTest, StringCreatedByAssignmentWithUnicodeStringLiteral) {
    string s = U"こんにちは世界!";
    ASSERT_EQ(U"こんにちは世界!", s);
  }
  #if defined(_WIN32)
#pragma warning(pop)
  #endif

  TEST(StringTest, SubscriptOperatorWithChar) {
    Array<char> chars = {'T', 'e', 's', 't'};
    string s = "Test";
    for (int i = 0; i < chars.Length; i++)
      ASSERT_EQ(chars[i], static_cast<char>(s[i]));
  }

  TEST(StringTest, SubscriptOperatorWithChar32) {
    Array<char32> chars = {U'こ', U'ん', U'に', U'ち', U'は', U'世', U'界', U'!'};
    string s = U"こんにちは世界!";
    int i = 0;
    for (char32 c : chars)
      ASSERT_EQ(c, s[i++]);
    ASSERT_EQ(chars.Length, i);
  }

  TEST(StringTest, OperatorLitteralChar) {
    ASSERT_EQ("Switch::System::String", _typeof("Test"_S).ToString());
  }

  TEST(StringTest, OperatorLitteralChar16) {
    ASSERT_EQ("Switch::System::String", _typeof(u"Test"_S).ToString());
  }

  TEST(StringTest, OperatorLitteralChar32) {
    ASSERT_EQ("Switch::System::String", _typeof(U"Test"_S).ToString());
  }

  TEST(StringTest, OperatorLitteralWChar) {
    ASSERT_EQ("Switch::System::String", _typeof(L"Test"_S).ToString());
  }

  TEST(StringTest, OperatorAddConstCharPointer) {
    ASSERT_EQ("string A string B", string("string A ") + "string B");
  }

  TEST(StringTest, OperatorAddBoolean) {
    ASSERT_EQ("string A False", string("string A ") + false);
  }

  TEST(StringTest, OperatorAddBooleanObject) {
    ASSERT_EQ("string A True", string("string A ") + Boolean(true));
  }

  TEST(StringTest, OperatorAddByte) {
    ASSERT_EQ("string A 18", string("string A ") + static_cast<byte>(18));
  }

  TEST(StringTest, OperatorAddByteObject) {
    ASSERT_EQ("string A 15", string("string A ") + Byte(15));
  }

  TEST(StringTest, OperatorAddChar) {
    ASSERT_EQ("string A a", string("string A ") + 'a');
  }

  TEST(StringTest, OperatorAddChar16) {
    ASSERT_EQ("string A d", string("string A ") + u'd');
  }

  TEST(StringTest, OperatorAddChar32) {
    ASSERT_EQ("string A d", string("string A ") + U'd');
  }

  TEST(StringTest, OperatorAddWChar) {
    ASSERT_EQ("string A d", string("string A ") + L'd');
  }

  TEST(StringTest, OperatorAddCharObject) {
    ASSERT_EQ("string A G", string("string A ") + Char('G'));
  }

  TEST(StringTest, OperatorAddDouble) {
    ASSERT_EQ("string A -0.987678", string("string A ") + -0.987678);
  }

  TEST(StringTest, OperatorAddDoubleObject) {
    ASSERT_EQ("string A -0.987678", string("string A ") + Double(-0.987678));
  }

  TEST(StringTest, OperatorAddInt16) {
    ASSERT_EQ("string A -32768", string("string A ") + Int16::MinValue);
  }

  TEST(StringTest, OperatorAddInt16Object) {
    ASSERT_EQ("string A 32767", string("string A ") + Int16(Int16::MaxValue));
  }

  TEST(StringTest, OperatorAddInt32) {
    ASSERT_EQ("string A 42", string("string A ") + static_cast<int32>(42));
  }

  TEST(StringTest, OperatorAddInt32Object) {
    ASSERT_EQ("string A 5467", string("string A ") + Int32(5467));
  }

  TEST(StringTest, OperatorAddInt64) {
    ASSERT_EQ("string A 42", string("string A ") + static_cast<int64>(42));
  }

  TEST(StringTest, OperatorAddInt64Object) {
    ASSERT_EQ("string A 5467", string("string A ") + Int64(5467));
  }

  TEST(StringTest, OperatorAddSByte) {
    ASSERT_EQ("string A -2", string("string A ") + static_cast<sbyte>(-2));
  }

  TEST(StringTest, OperatorAddSByteObject) {
    ASSERT_EQ("string A 15", string("string A ") + SByte(15));
  }

  TEST(StringTest, OperatorAddUInt16) {
    ASSERT_EQ("string A 0", string("string A ") + UInt16::MinValue);
  }

  TEST(StringTest, OperatorAddUInt16Object) {
    ASSERT_EQ("string A 6345", string("string A ") + UInt16(6345));
  }

  TEST(StringTest, OperatorAddUInt32) {
    ASSERT_EQ("string A 42", string("string A ") + static_cast<uint32>(42));
  }

  TEST(StringTest, OperatorAddUInt32Object) {
    ASSERT_EQ("string A 5467", string("string A ") + UInt32(5467));
  }

  TEST(StringTest, OperatorAddUInt64) {
    ASSERT_EQ("string A 42", string("string A ") + static_cast<uint64>(42));
  }

  TEST(StringTest, OperatorAddUInt64Object) {
    ASSERT_EQ("string A 5467", string("string A ") + UInt64(5467));
  }

  TEST(StringTest, OperatorAddSingle) {
    ASSERT_EQ("string A 0.0654", string("string A ") + 0.0654f);
  }

  TEST(StringTest, OperatorAddSingleObject) {
    ASSERT_EQ("string A 0.0654", string("string A ") + Single(0.0654f));
  }

  TEST(StringTest, OperatorAddDateTimeObject) {
    ASSERT_EQ("string A 01/01/1970 00:00:00", string("string A ") + DateTime(1970, 1, 1, 0, 0, 0));
  }

  TEST(StringTest, CompareEmptyStrings) {
    ASSERT_TRUE(string::Compare("", "") ==  0);
  }

  TEST(StringTest, CompareEmptyStringWithStringEmpty) {
    ASSERT_TRUE(string::Compare("", String::Empty) ==  0);
  }

  TEST(StringTest, CompareEmptyStringWithAnyString) {
    ASSERT_TRUE(string::Compare("", "string To Compare") < 0);
  }

  TEST(StringTest, CompareAnyStringWithEmptyString) {
    ASSERT_TRUE(string::Compare("string To Compare", "") > 0);
  }

  TEST(StringTest, CompareSameStrings) {
    ASSERT_TRUE(string::Compare("string To Compare", "string To Compare") == 0);
  }

  TEST(StringTest, CompareGreaterString) {
    ASSERT_TRUE(string::Compare("string To Compare", "string To Comp") > 0);
  }

  TEST(StringTest, CompareLessString) {
    ASSERT_TRUE(string::Compare("string To Comp", "string To Compare") < 0);
  }

  TEST(StringTest, CompareIndex) {
    ASSERT_TRUE(string::Compare("Char To Compare", 4, "string To Compare", 6, 11) == 0);
  }

  TEST(StringTest, CompareEmptyStringsWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("", "", true) == 0);
  }

  TEST(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("", String::Empty, true) ==  0);
  }

  TEST(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("", "string To compare", true) < 0);
  }

  TEST(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("string To compare", "", true) > 0);
  }

  TEST(StringTest, CompareSameStringsWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("string to compare", "string To Compare", true) == 0);
  }

  TEST(StringTest, CompareGreaterStringWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("string to compare", "string To Comp", true) > 0);
  }

  TEST(StringTest, CompareLessStringWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("string to comp", "string To Compare", true) < 0);
  }

  TEST(StringTest, CompareDifferentCaseStringsWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("string to compare", "string To Compare", true) == 0);
  }

  TEST(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("string to compare", "string To Comp", true) > 0);
  }

  TEST(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseTrue) {
    ASSERT_TRUE(string::Compare("string to comp", "string To Compare", true) < 0);
  }

  TEST(StringTest, CompareEmptyStringsWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("", "", false) == 0);
  }

  TEST(StringTest, CompareEmptyStringWithStringEmptyWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("", String::Empty, false) ==  0);
  }

  TEST(StringTest, CompareEmptyStringWithAnyStringWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("", "string To Compare", false) < 0);
  }

  TEST(StringTest, CompareAnyStringWithEmptyStringWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("string To Compare", "", false) > 0);
  }

  TEST(StringTest, CompareSameStringsWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("string To Compare", "string To Compare", false) == 0);
  }

  TEST(StringTest, CompareGreaterStringWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("string To Compare", "string To Comp", false) > 0);
  }

  TEST(StringTest, CompareLessStringWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("string To Comp", "string To Compare", false) < 0);
  }

  TEST(StringTest, CompareDifferentCaseStringsWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("string to compare", "string To Compare", false) > 0);
  }

  TEST(StringTest, CompareGreaterDifferentCaseStringWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("string to compare", "string To Comp", false) > 0);
  }

  TEST(StringTest, CompareLessDifferentCaseStringWithIgnoreCaseFalse) {
    ASSERT_TRUE(string::Compare("string to comp", "string To Compare", false) > 0);
  }

  TEST(StringTest, CompareIndexIgnoreCase) {
    ASSERT_TRUE(string::Compare("Char to compare", 4, "string To Compare", 6, 11, true) == 0);
    ASSERT_TRUE(string::Compare("Char to compare", 4, "string To Compare", 6, 11, true) == 0);
    ASSERT_TRUE(string::Compare("Char to Compare", 4, "string TO Compare", 6, 11, false) > 0);
    ASSERT_TRUE(string::Compare("Char To Compare", 4, "string To Compare", 6, 11, false) == 0);
  }

  TEST(StringTest, Concat) {
    ASSERT_EQ(Object().ToString(), string::Concat(Object()));
    ASSERT_EQ(Object().ToString() + Object().ToString() + Object().ToString(), string::Concat<>(Array<Object> {Object(), Object(), Object()}));
    ASSERT_EQ(Object().ToString() + Object().ToString(), string::Concat(Object(), Object()));
    ASSERT_EQ(Object().ToString() + Object().ToString() + Object().ToString(), string::Concat(Object(), Object(), Object()));

    ASSERT_EQ("264", string::Concat(UInt32(264)));
    ASSERT_EQ("True", string::Concat(Boolean(true)));
    ASSERT_EQ("string to concatenate", string::Concat(string("string to concatenate")));

    ASSERT_EQ("264128", string::Concat(UInt32(264), UInt32(128)));
    ASSERT_EQ("TrueFalse", string::Concat(Boolean(true), Boolean(false)));
    ASSERT_EQ("string Astring B", string::Concat("string A", "string B"));
    ASSERT_EQ("264128378", string::Concat(UInt32(264), UInt32(128), UInt32(378)));
    ASSERT_EQ("TrueFalseTrue", string::Concat(Boolean(true), Boolean(false), Boolean(true)));
    ASSERT_EQ("string Astring Bstring C", string::Concat("string A", "string B", "string C"));
    ASSERT_EQ("string Astring Bstring Cstring D", string::Concat("string A", "string B", "string C", "string D"));
  }

  TEST(StringTest, ConcatArray) {
    ASSERT_EQ("264128378842", string::Concat<>(Array<Int32> {264, 128, 378, 842}));
    ASSERT_EQ("TrueFalseTrue", string::Concat<>(Array<Boolean> {true, false, true}));
    ASSERT_EQ("string To Concat", string::Concat<>(Array<string> {"string ", "To ", "Concat"}));
  }

  TEST(StringTest, EndsWith) {
    ASSERT_TRUE("This is the beast of the beast"_S.EndsWith("beast"));
    ASSERT_FALSE("This is the beast of the beast"_S.EndsWith("Beast"));
    ASSERT_FALSE("This is the beast of the beast"_S.EndsWith("Beast", false));
    ASSERT_TRUE("This is the beast of the beast"_S.EndsWith("Beast", true));
  }

  TEST(StringTest, EndsWithChar32) {
    ASSERT_TRUE("This is the beast of the beast"_S.EndsWith('t'));
    ASSERT_FALSE("This is the beast of the beast"_S.EndsWith('T'));
    ASSERT_FALSE("This is the beast of the beast"_S.EndsWith('s'));
    ASSERT_FALSE("This is the beast of the beast"_S.EndsWith('T', false));
    ASSERT_TRUE("This is the beast of the beast"_S.EndsWith('T', true));
  }

  TEST(StringTest, StartsWith) {
    ASSERT_TRUE("This is the beast of the beast"_S.StartsWith("This"));
    ASSERT_FALSE("This is the beast of the beast"_S.StartsWith("this"));
    ASSERT_FALSE("This is the beast of the beast"_S.StartsWith("this", false));
    ASSERT_TRUE("This is the beast of the beast"_S.StartsWith("this", true));
  }

  TEST(StringTest, StartsWithChar32) {
    ASSERT_TRUE("This is the beast of the beast"_S.StartsWith('T'));
    ASSERT_FALSE("This is the beast of the beast"_S.StartsWith('t'));
    ASSERT_FALSE("This is the beast of the beast"_S.StartsWith('h'));
    ASSERT_FALSE("This is the beast of the beast"_S.StartsWith('t', false));
    ASSERT_TRUE("This is the beast of the beast"_S.StartsWith('t', true));
    ASSERT_TRUE("This is the beast of the beast"_S.StartsWith('T', true));
  }

  TEST(StringTest, GetEnumeratorOnString) {
    string str = "This is a test for enumerator";
    string output;
    System::Collections::Generic::Enumerator<char32> enumerator = str.GetEnumerator();
    while (enumerator.MoveNext())
      output += enumerator.Current;
    ASSERT_EQ("This is a test for enumerator", output);
  }

  TEST(StringTest, ForeachOnString) {
    string str = "This is a test for foreach";
    string output;
    for (char32 item : str)
      output += item;
    ASSERT_EQ("This is a test for foreach", output);
  }

  TEST(StringTest, IteratorOnString) {
    string str = "This is a test for iterator";
    string output;
    for (string::const_iterator iterator = str.cbegin(); iterator != str.cend(); ++iterator)
      output += *iterator;
    ASSERT_EQ("This is a test for iterator", output);
  }

  TEST(StringTest, ForOnString) {
    string str = "This is a test for for";
    string output;
    for (int32 index = 0; index < str.Length; ++index)
      output += str[index];
    ASSERT_EQ("This is a test for for", output);
  }

  TEST(StringTest, GetHashCode) {
    ASSERT_NE("A"_S.GetHashCode(), "B"_S.GetHashCode());
    ASSERT_EQ("ABCD"_S.GetHashCode(), "ABCD"_S.GetHashCode());
    ASSERT_NE("ABCD"_S.GetHashCode(), "ABCE"_S.GetHashCode());
    ASSERT_EQ("ABCDE"_S.GetHashCode(), "ABCDE"_S.GetHashCode());
    ASSERT_NE("My string"_S.GetHashCode(), "My Strinh"_S.GetHashCode());
    ASSERT_NE("My string"_S.GetHashCode(), "My Gtrins"_S.GetHashCode());
    ASSERT_EQ("another string"_S.GetHashCode(), "another string"_S.GetHashCode());

    refptr<string> clone;
    string testClone("Test Clone");
    clone = as<string>(testClone.Clone());
    ASSERT_EQ(testClone.GetHashCode(), clone->GetHashCode());
  }

  TEST(StringTest, IsNullOrEmptyOnEmptyString) {
    ASSERT_TRUE(string::IsNullOrEmpty(""_S));
  }

  TEST(StringTest, IsNullOrEmptyOnNonEmptyString) {
    ASSERT_FALSE(string::IsNullOrEmpty("Not Empty"_S));
  }

  TEST(StringTest, IsNullOrEmptyOnStringEmpty) {
    ASSERT_TRUE(string::IsNullOrEmpty(string::Empty));
  }

  TEST(StringTest, IndexOf) {
    ASSERT_EQ(2, "This is the beast of the beast"_S.IndexOf('i'));
    ASSERT_EQ(5, "This is the beast of the beast"_S.IndexOf('i', 3));
    ASSERT_EQ(5, "This is the beast of the beast"_S.IndexOf('i', 3, 3));
    ASSERT_EQ(-1, "This is the beast of the beast"_S.IndexOf('i', 3, 2));
    ASSERT_EQ(29, "This is the beast of the beast"_S.IndexOf('t', 29));
    ASSERT_EQ(-1, "This is the beast of the beast"_S.IndexOf('t', 30));

    ASSERT_EQ(8, "This is the beast of the beast"_S.IndexOf("the"));
    ASSERT_EQ(21, "This is the beast of the beast"_S.IndexOf("the", 19));
    ASSERT_EQ(21, "This is the beast of the beast"_S.IndexOf("the", 19, 5));

    ASSERT_EQ(-1, "This is the beast of the beast"_S.IndexOf("the", 18, 3));
  }

  TEST(StringTest, IndexOfExceptions) {
    ASSERT_THROW("This is the beast of the beast"_S.IndexOf('i', 31), ArgumentOutOfRangeException);
    ASSERT_THROW("This is the beast of the beast"_S.IndexOf('i', 26, 5), ArgumentOutOfRangeException);

    ASSERT_THROW("This is the beast of the beast"_S.IndexOf("the", 31), ArgumentOutOfRangeException);
    ASSERT_THROW("This is the beast of the beast"_S.IndexOf("the", 26, 5), ArgumentOutOfRangeException);
  }

  TEST(StringTest, IndexOfAny) {
    Array<char32> separators = {'.', ',', ':', '_'};

    ASSERT_EQ(4,  "This, is : separator."_S.IndexOfAny(separators));
    ASSERT_EQ(9,  "This, is : separator."_S.IndexOfAny(separators, 5));
    ASSERT_EQ(9,  "This, is : separator."_S.IndexOfAny(separators, 5, 5));
    ASSERT_EQ(-1, "This, is : separator."_S.IndexOfAny(separators, 5, 4));

    String xxxx_ = "xxxx_";
    ASSERT_EQ(4, xxxx_.IndexOfAny(separators, 0, 5));
    ASSERT_EQ(4, xxxx_.IndexOfAny(separators, 1, 4));
    ASSERT_EQ(4, xxxx_.IndexOfAny(separators, 2, 3));
    ASSERT_EQ(4, xxxx_.IndexOfAny(separators, 3, 2));
    ASSERT_EQ(4, xxxx_.IndexOfAny(separators, 4, 1));
    ASSERT_EQ(-1, xxxx_.IndexOfAny(separators, 5, 0));
  }

  TEST(StringTest, IndexOfAnyExceptions) {
    Array<char32> separators = {'.', ',', ':', '_'};

    ASSERT_THROW("This, is : separator."_S.IndexOfAny(separators, 22), ArgumentOutOfRangeException);
    ASSERT_THROW("This, is : separator."_S.IndexOfAny(separators, 18, 5), ArgumentOutOfRangeException);

    String xxxx_ = String("xxxx_");
    ASSERT_THROW(xxxx_.IndexOfAny(separators, -1, 3), ArgumentOutOfRangeException);
    ASSERT_THROW(xxxx_.IndexOfAny(separators, 2, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(xxxx_.IndexOfAny(separators, 0, 6), ArgumentOutOfRangeException);
    ASSERT_THROW(xxxx_.IndexOfAny(separators, 1, 5), ArgumentOutOfRangeException);
    ASSERT_THROW(xxxx_.IndexOfAny(separators, 2, 4), ArgumentOutOfRangeException);
    ASSERT_THROW(xxxx_.IndexOfAny(separators, 3, 3), ArgumentOutOfRangeException);
    ASSERT_THROW(xxxx_.IndexOfAny(separators, 4, 2), ArgumentOutOfRangeException);
    ASSERT_THROW(xxxx_.IndexOfAny(separators, 5, 1), ArgumentOutOfRangeException);
  }

  TEST(StringTest, Join) {
    Array<string> array = {"123", "a text", "ok"};
    ASSERT_EQ("123, a text, ok", string::Join(", ", array, 0, 3));
  }

  TEST(StringTest, JoinN) {
    string join[] = {"blue", "red", "green", "yellow"};
    ASSERT_EQ("blue, red, green, yellow", string::Join(", ", join, 4));
    ASSERT_EQ("red, green", string::Join(", ", join, 4, 1, 2));
  }

  TEST(StringTest, JoinNExceptions) {
    string join[] = {"blue", "red", "green", "yellow"};
    ASSERT_THROW(string::Join(", ", null, 4), ArgumentNullException);
    ASSERT_THROW(string::Join(", ", join, 4, 4, 2), ArgumentOutOfRangeException);
    ASSERT_THROW(string::Join(", ", join, 4, 1, 4), ArgumentOutOfRangeException);
  }

  TEST(StringTest, LastIndexOf) {
    ASSERT_EQ(26, "This is the beast of the beast"_S.LastIndexOf('e'));
    ASSERT_EQ(26, "This is the beast of the beast"_S.LastIndexOf('e', 3));
    ASSERT_EQ(13, "This is the beast of the beast"_S.LastIndexOf('e', 11, 3));
    ASSERT_EQ(-1, "This is the beast of the beast"_S.LastIndexOf('e', 11, 2));

    ASSERT_EQ(21, "This is the beast of the beast"_S.LastIndexOf("the"));
    ASSERT_EQ(21, "This is the beast of the beast"_S.LastIndexOf("the", 19));
    ASSERT_EQ(21, "This is the beast of the beast"_S.LastIndexOf("the", 19, 5));
    ASSERT_EQ(-1, "This is the beast of the beast"_S.LastIndexOf("the", 19, 4));
    ASSERT_EQ(8, "This is the beast of the beast"_S.LastIndexOf("the", 5, 6));
    ASSERT_EQ(-1, "This is the beast of the beast"_S.LastIndexOf("the", 5, 5));
  }

  TEST(StringTest, LastIndexOfExceptions) {
    ASSERT_THROW("This is the beast of the beast"_S.LastIndexOf('e', 31), ArgumentOutOfRangeException);
    ASSERT_THROW("This is the beast of the beast"_S.LastIndexOf('e', 29, 2), ArgumentOutOfRangeException);
    ASSERT_THROW("This is the beast of the beast"_S.LastIndexOf("the", 31), ArgumentOutOfRangeException);
    ASSERT_THROW("This is the beast of the beast"_S.LastIndexOf("the", 29, 2), ArgumentOutOfRangeException);
  }

  TEST(StringTest, LastIndexOfAny) {
    char32 nativeSeparator[] = {'.', ',', ':'};
    ASSERT_EQ(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3)));
    ASSERT_EQ(20, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5));
    ASSERT_EQ(9, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 5));
    ASSERT_EQ(-1, "This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 5, 4));
  }

  TEST(StringTest, LastIndexOfAnyException) {
    char32 nativeSeparator[] = {'.', ',', ':'};
    ASSERT_THROW("This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 22), ArgumentOutOfRangeException);
    ASSERT_THROW("This, is : separator."_S.LastIndexOfAny(Array<char32>(nativeSeparator, 3), 18, 5), ArgumentOutOfRangeException);
  }

  TEST(StringTest, PadLeft) {
    ASSERT_EQ("string To Pad", "string To Pad"_S.PadLeft(13));
    ASSERT_EQ(" string To Pad", "string To Pad"_S.PadLeft(14));
    ASSERT_EQ("  string To Pad", "string To Pad"_S.PadLeft(15));
    ASSERT_EQ("string To Pad", "string To Pad"_S.PadLeft(12, '*'));
    ASSERT_EQ("string To Pad", "string To Pad"_S.PadLeft(13, '*'));
    ASSERT_EQ("*string To Pad", "string To Pad"_S.PadLeft(14, '*'));
    ASSERT_EQ("**string To Pad", "string To Pad"_S.PadLeft(15, '*'));
  }

  TEST(StringTest, PadRight) {
    ASSERT_EQ("string To Pad", "string To Pad"_S.PadRight(13));
    ASSERT_EQ("string To Pad ", "string To Pad"_S.PadRight(14));
    ASSERT_EQ("string To Pad  ", "string To Pad"_S.PadRight(15));
    ASSERT_EQ("string To Pad", "string To Pad"_S.PadRight(12, '*'));
    ASSERT_EQ("string To Pad", "string To Pad"_S.PadRight(13, '*'));
    ASSERT_EQ("string To Pad*", "string To Pad"_S.PadRight(14, '*'));
    ASSERT_EQ("string To Pad**", "string To Pad"_S.PadRight(15, '*'));
  }

  TEST(StringTest, Remove) {
    ASSERT_EQ("", "abc123ABC"_S.Remove(0));
    ASSERT_EQ("abc", "abc123ABC"_S.Remove(3));
    ASSERT_EQ("abcABC", "abc123ABC"_S.Remove(3, 3));
    ASSERT_EQ("abc", "abc123ABC"_S.Remove(3, 6));
    ASSERT_EQ("abc123ABC", "abc123ABC"_S.Remove(9));
  }

  TEST(StringTest, RemoveExceptions) {
    ASSERT_THROW("abc123ABC"_S.Remove(10), ArgumentOutOfRangeException);
    ASSERT_THROW("abc123ABC"_S.Remove(8, 2), ArgumentOutOfRangeException);
  }

  TEST(StringTest, Insert) {
    ASSERT_EQ("abc", ""_S.Insert(0, "abc"));
    ASSERT_EQ("abc123ABC", "abcABC"_S.Insert(3, "123"));
    ASSERT_EQ("abc123", "abc"_S.Insert(3, "123"));
  }
  TEST(StringTest, InsertExceptions) {
    ASSERT_THROW("ok"_S.Insert(-1, "abc"), ArgumentOutOfRangeException);
    ASSERT_THROW(""_S.Insert(1, "abc"), ArgumentOutOfRangeException);
    ASSERT_THROW("abc"_S.Insert(4, "123"), ArgumentOutOfRangeException);
  }

  TEST(StringTest, Replace) {
    ASSERT_EQ("This*is*the*beast*of*the*beast", "This is the beast of the beast"_S.Replace(' ', '*'));
    ASSERT_EQ("This is thE bEast of thE bEast", "This is the beast of the beast"_S.Replace('e', 'E'));
    ASSERT_EQ("Thare are the beast of the beast", "This is the beast of the beast"_S.Replace("is", "are"));
    ASSERT_EQ("Th  the beast of the beast", "This is the beast of the beast"_S.Replace("is", ""));
    ASSERT_EQ("This text has\\_unescaped\\_\\_underscores !", "This text has_unescaped__underscores !"_S.Replace("_", "\\_"));
  }

  TEST(StringTest, Split) {
    ASSERT_EQ(Array<string> {}, ""_S.Split({'+', '-', '='}));
    ASSERT_EQ(Array<string> {"a"}, "a"_S.Split({'+', '-', '='}));
    ASSERT_EQ((Array<string> {"100", "42", "142"}), "100+42=142"_S.Split({'+', '-', '='}));
    ASSERT_EQ(Array<string> {"100+42=142"}, "100+42=142"_S.Split({'%', '*'}));
    ASSERT_EQ(Array<string> {"100+42=142"}, "100+42=142"_S.Split({}));
    ASSERT_EQ((Array<string> {"a", "b", "c"}), "a,b,c"_S.Split(','));
    ASSERT_EQ((Array<string> {"a", "", "", "b", "", "c"}), "a,,,b,,c"_S.Split(','));
  }

  TEST(StringTest, SplitCount) {
    ASSERT_EQ((Array<string> {"42", " 12, 19"}), "42, 12, 19"_S.Split({',', ' '}, 2));
    ASSERT_EQ((Array<string> {"42", "", "12", ".19"}), "42..12..19"_S.Split({'.'}, 4));
    ASSERT_EQ(Array<string> {"Banana"}, "Banana"_S.Split({','}, 2));
    ASSERT_EQ(Array<string> {"Darb\nSmarba "}, "Darb\nSmarba "_S.Split({}, 1));
  }

  TEST(StringTest, SplitWithStringSplitOptionRemoveEmptyEntries) {
    ASSERT_EQ((Array<string> {"a", "b", "c"}), "a,,,b,,c"_S.Split(',', StringSplitOptions::RemoveEmptyEntries));
  }

  TEST(StringTest, SplitWithStringSplitOptioNone) {
    ASSERT_EQ((Array<string> {"a", "", "", "b", "", "c"}), "a,,,b,,c"_S.Split(',', StringSplitOptions::None));
  }

  TEST(StringTest, ToUpper) {
    ASSERT_EQ("STRING TO UPPER OR TO LOWER", "string To Upper or To Lower"_S.ToUpper());
  }

  TEST(StringTest, ToLower) {
    ASSERT_EQ("string to upper or to lower", "string To Upper or To Lower"_S.ToLower());
  }

  TEST(StringTest, TrimStart) {
    ASSERT_EQ("string To Trim", "string To Trim"_S.TrimStart('x'));
    ASSERT_EQ("string To Trim", "xxxstring To Trim"_S.TrimStart('x'));
    ASSERT_EQ("string To Trim", "xxstring To Trim"_S.TrimStart('x'));
    ASSERT_EQ("string To Trim", "xstring To Trim"_S.TrimStart('x'));
    ASSERT_EQ("", ""_S.TrimStart('x'));
    ASSERT_EQ("", "x"_S.TrimStart('x'));
    ASSERT_EQ("", "xx"_S.TrimStart('x'));
    ASSERT_EQ("", "xxx"_S.TrimStart('x'));
    ASSERT_EQ(" x", "xx x"_S.TrimStart('x'));
    ASSERT_EQ("string To Trim Start", "          string To Trim Start"_S.TrimStart(' '));
    ASSERT_EQ("          string To Trim Start", "          string To Trim Start"_S.TrimStart('d'));
  }

  TEST(StringTest, TrimSartMultiple) {
    Array<char32> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    ASSERT_EQ("abcdef1357924680", "2468013579abcdef1357924680"_S.TrimStart(numbers));
    ASSERT_EQ("", ""_S.TrimStart(numbers));
    ASSERT_EQ("", "24680135791357924680"_S.TrimStart(numbers));
  }
}

