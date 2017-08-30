#include <Switch/System/Uri.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/Expect.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class AssertTest : public TestFixture {
  protected:
    AssertTest() {}
    
    void SetUp() override {
      value = 42;
    }
    
    void TearDown() override {
      value = 0;
    }
    
    void AreEqualInternalValue() {
      Assert::AreEqual(42, this->value, sw_current_information);
    }
    
    void AreEqualInt32() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualInt32WithCurrentInformation() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, sw_current_information);
    }
    
    void AreEqualInt32WithMessage() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualInt32WithMessageAndCurrentInformation() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message", sw_current_information);
    }
    
    void AreEqualConstCharPointer() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualConstCharPointerWithCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, sw_current_information);
    }
    
    void AreEqualConstCharPointerWithMessage() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualConstCharPointerWithMessageAndCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message", sw_current_information);
    }
    
    void AreEqualString() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualStringWithCurrentInformation() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, sw_current_information);
    }
    
    void AreEqualStringWithMessage() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualStringWithMessageAndCurrentInformation() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message", sw_current_information);
    }
    
    void AreEqualTimeSpan() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration);
    }
    
    void AreEqualTimeSpanWithCurrentInformation() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, sw_current_information);
    }
    
    void AreEqualTimeSpanWithMessage() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, "My message");
    }
    
    void AreEqualTimeSpanWithMessageAndCurrentInformation() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, "My message", sw_current_information);
    }
    
    void AreEqualProperty() {
      Property<int32, ReadOnly> fourtyTwo {
        sw_get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualPropertyWithCurrentInformation() {
      Property<int32, ReadOnly> fourtyTwo {
        sw_get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, sw_current_information);
    }
    
    void AreEqualPropertyWithMessage() {
      Property<int32, ReadOnly> fourtyTwo {
        sw_get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualPropertyWithMessageAndCurrentInformation() {
      Property<int32, ReadOnly> fourtyTwo {
        sw_get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, "My message", sw_current_information);
    }
    
    void AreEqualAny() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualAnyWithCurrentInformation() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, sw_current_information);
    }
    
    void AreEqualAnyWithMessage() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualAnyWithMessageAndCurrentInformation() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message", sw_current_information);
    }
    
    void AreEqualMyStruct() {
      struct MyStruct {
        MyStruct() = delete;
        MyStruct(const MyStruct&) = delete;
        MyStruct& operator=(const MyStruct&) = delete;
        MyStruct(int32 value) : value(value) {}
        int32 value = 0;
        bool operator==(const MyStruct& ms) const {return this->value == ms.value;}
        bool operator!=(const MyStruct& ms) const {return !this->operator==(ms);}
      };
      MyStruct fourtyTwo(42);
      Assert::AreEqual(MyStruct(42), fourtyTwo);
    }
    
    void AreEqualMyStructWithCurrentInformation() {
      struct MyStruct {
        MyStruct(int32 value) : value(value) {}
        int32 value = 0;
        bool operator==(const MyStruct& ms) const {return this->value == ms.value;}
        bool operator!=(const MyStruct& ms) const {return !this->operator==(ms);}
      };
      MyStruct fourtyTwo(42);
      Expect::AreEqual(MyStruct(42), fourtyTwo, sw_current_information);
    }
    
    void AreEqualMyStructWithMessage() {
      struct MyStruct {
        MyStruct(int32 value) : value(value) {}
        int32 value = 0;
        bool operator==(const MyStruct& ms) const {return this->value == ms.value;}
        bool operator!=(const MyStruct& ms) const {return !this->operator==(ms);}
      };
      MyStruct fourtyTwo(42);
      Assert::AreEqual(MyStruct(42), fourtyTwo, "My message");
    }
    
    void AreEqualMyStructWithMessageAndCurrentInformation() {
      struct MyStruct {
        MyStruct(int32 value)  : value(value) {}
        int32 value = 0;
        bool operator==(const MyStruct& ms) const {return this->value == ms.value;}
        bool operator!=(const MyStruct& ms) const {return !this->operator==(ms);}
      };
      MyStruct fourtyTwo(42);
      Assert::AreEqual(MyStruct(42), fourtyTwo, "My message", sw_current_information);
    }
    
    void AreNotEqual() {
      String string = "Test";
      Assert::AreNotEqual("Tes", string, sw_current_information);
    }
    
    void AreNotSame() {
      Uri uri1("http://www.contoso.com/index.htm?date=today");
      Uri uri2("http://www.contoso.com/index.htm?date=today");
      Assert::AreNotSame(uri2, uri1, sw_current_information);
    }
    
    void AreSame() {
      System::DateTime date1 = System::DateTime::Now;
      System::DateTime* date2 = &date1;
      Assert::AreSame(date1, *date2, sw_current_information);
    }
    
    void DoesNotThrows() {
      const char* string1 = "Not null";
      Assert::DoesNotThrows(sw_delegate {System::String string2(string1);}, sw_current_information);
    }
    
    void Greater() {
      int32 fourtyTwo = 42;
      Assert::Greater(fourtyTwo, 40, sw_current_information);
    }
    
    void GreaterOrEqual() {
      int32 fourtyTwo = 42;
      Assert::GreaterOrEqual(fourtyTwo, 40, sw_current_information);
      Assert::GreaterOrEqual(fourtyTwo, 42, sw_current_information);
    }
    
    void IsFalse() {
      bool boolean = false;
      Assert::IsFalse(boolean, sw_current_information);
    }
    
    void IsNull() {
      System::Object* pointer = null;
      Assert::IsNull(pointer, sw_current_information);
    }
    
    void IsTrue() {
      bool boolean = true;
      Assert::IsTrue(boolean, sw_current_information);
    }
    
    void Less() {
      int32 fourtyTwo = 42;
      Assert::Less(fourtyTwo, 44, sw_current_information);
    }
    
    void LessOrEqual() {
      int32 fourtyTwo = 42;
      Assert::LessOrEqual(fourtyTwo, 44, sw_current_information);
      Assert::LessOrEqual(fourtyTwo, 42, sw_current_information);
    }
    
    
    void Throws() {
      const char* string1 = null;
      Assert::Throws<System::ArgumentNullException>(sw_delegate {System::String string2(string1);}, sw_current_information);
    }
    
    void ThrowsAny() {
      System::Array<System::String> array(10);
      Assert::ThrowsAny(sw_delegate {array[10];}, sw_current_information);
    }

    void AnyTest() {
      Assert::AreEqual(10, 10, sw_current_information);
    }

  private:
    int32 value;
  };
  
  sw_test(AssertTest, AreEqualInternalValue)
  sw_test(AssertTest, AreEqualInt32)
  sw_test(AssertTest, AreEqualInt32WithCurrentInformation)
  sw_test(AssertTest, AreEqualInt32WithMessage)
  sw_test(AssertTest, AreEqualInt32WithMessageAndCurrentInformation)
  sw_test(AssertTest, AreEqualConstCharPointer)
  sw_test(AssertTest, AreEqualConstCharPointerWithCurrentInformation)
  sw_test(AssertTest, AreEqualConstCharPointerWithMessage)
  sw_test(AssertTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  sw_test(AssertTest, AreEqualString)
  sw_test(AssertTest, AreEqualStringWithCurrentInformation)
  sw_test(AssertTest, AreEqualStringWithMessage)
  sw_test(AssertTest, AreEqualStringWithMessageAndCurrentInformation)
  sw_test(AssertTest, AreEqualTimeSpan)
  sw_test(AssertTest, AreEqualTimeSpanWithCurrentInformation)
  sw_test(AssertTest, AreEqualTimeSpanWithMessage)
  sw_test(AssertTest, AreEqualTimeSpanWithMessageAndCurrentInformation)
  sw_test(AssertTest, AreEqualProperty)
  sw_test(AssertTest, AreEqualPropertyWithCurrentInformation)
  sw_test(AssertTest, AreEqualPropertyWithMessage)
  sw_test(AssertTest, AreEqualPropertyWithMessageAndCurrentInformation)
  sw_test(AssertTest, AreEqualAny)
  sw_test(AssertTest, AreEqualAnyWithCurrentInformation)
  sw_test(AssertTest, AreEqualAnyWithMessage)
  sw_test(AssertTest, AreEqualAnyWithMessageAndCurrentInformation)
  sw_test(AssertTest, AreEqualMyStruct)
  sw_test(AssertTest, AreEqualMyStructWithCurrentInformation)
  sw_test(AssertTest, AreEqualMyStructWithMessage)
  sw_test(AssertTest, AreEqualMyStructWithMessageAndCurrentInformation)
  sw_test(AssertTest, AreNotEqual)
  sw_test(AssertTest, AreNotSame)
  sw_test(AssertTest, AreSame)
  sw_test(AssertTest, DoesNotThrows)
  sw_test(AssertTest, Greater)
  sw_test(AssertTest, GreaterOrEqual)
  sw_test(AssertTest, IsFalse)
  sw_test(AssertTest, IsNull)
  sw_test(AssertTest, IsTrue)
  sw_test(AssertTest, Less)
  sw_test(AssertTest, LessOrEqual)
  sw_test(AssertTest, Throws)
  sw_test(AssertTest, ThrowsAny)
  sw_ignore_test(AssertTest, AnyTest)
}
