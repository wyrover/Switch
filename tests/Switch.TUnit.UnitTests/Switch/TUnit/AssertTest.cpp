#include <Switch/System/Version.hpp>
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
      Assert::AreEqual(42, this->value, caller_);
    }

    void AreEqualInt32() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo);
    }

    void AreEqualInt32WithCurrentInformation() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, caller_);
    }

    void AreEqualInt32WithMessage() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message");
    }

    void AreEqualInt32WithMessageAndCurrentInformation() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message", caller_);
    }

    void AreEqualConstCharPointer() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo);
    }

    void AreEqualConstCharPointerWithCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, caller_);
    }

    void AreEqualConstCharPointerWithMessage() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message");
    }

    void AreEqualConstCharPointerWithMessageAndCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message", caller_);
    }

    void AreEqualString() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo);
    }

    void AreEqualStringWithCurrentInformation() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, caller_);
    }

    void AreEqualStringWithMessage() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message");
    }

    void AreEqualStringWithMessageAndCurrentInformation() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message", caller_);
    }

    void AreEqualTimeSpan() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration);
    }

    void AreEqualTimeSpanWithCurrentInformation() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, caller_);
    }

    void AreEqualTimeSpanWithMessage() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, "My message");
    }

    void AreEqualTimeSpanWithMessageAndCurrentInformation() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, "My message", caller_);
    }

    void AreEqualProperty() {
      property_<int32, readonly_> fourtyTwo {
        get_ {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo);
    }

    void AreEqualPropertyWithCurrentInformation() {
      property_<int32, readonly_> fourtyTwo {
        get_ {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, caller_);
    }

    void AreEqualPropertyWithMessage() {
      property_<int32, readonly_> fourtyTwo {
        get_ {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, "My message");
    }

    void AreEqualPropertyWithMessageAndCurrentInformation() {
      property_<int32, readonly_> fourtyTwo {
        get_ {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, "My message", caller_);
    }

    void AreEqualAny() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo);
    }

    void AreEqualAnyWithCurrentInformation() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, caller_);
    }

    void AreEqualAnyWithMessage() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message");
    }

    void AreEqualAnyWithMessageAndCurrentInformation() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message", caller_);
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
      Expect::AreEqual(MyStruct(42), fourtyTwo, caller_);
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
      Assert::AreEqual(MyStruct(42), fourtyTwo, "My message", caller_);
    }

    void AreNotEqual() {
      String string = "Test";
      Assert::AreNotEqual("Tes", string, caller_);
    }

    void AreNotSame() {
      Version ver1(1, 2, 3);
      Version ver2(1, 2, 3);
      Assert::AreNotSame(ver2, ver1, caller_);
    }

    void AreSame() {
      System::DateTime date1 = System::DateTime::Now();
      System::DateTime* date2 = &date1;
      Assert::AreSame(date1, *date2, caller_);
    }

    void DoesNotThrows() {
      const char* string1 = "Not null";
      Assert::DoesNotThrows(delegate_ {System::String string2(string1);}, caller_);
    }

    void Greater() {
      int32 fourtyTwo = 42;
      Assert::Greater(fourtyTwo, 40, caller_);
    }

    void GreaterOrEqual() {
      int32 fourtyTwo = 42;
      Assert::GreaterOrEqual(fourtyTwo, 40, caller_);
      Assert::GreaterOrEqual(fourtyTwo, 42, caller_);
    }

    void IsFalse() {
      bool boolean = false;
      Assert::IsFalse(boolean, caller_);
    }

    void IsNull() {
      System::Object* pointer = null;
      Assert::IsNull(pointer, caller_);
    }

    void IsTrue() {
      bool boolean = true;
      Assert::IsTrue(boolean, caller_);
    }

    void Less() {
      int32 fourtyTwo = 42;
      Assert::Less(fourtyTwo, 44, caller_);
    }

    void LessOrEqual() {
      int32 fourtyTwo = 42;
      Assert::LessOrEqual(fourtyTwo, 44, caller_);
      Assert::LessOrEqual(fourtyTwo, 42, caller_);
    }


    void Throws() {
      const char* string1 = null;
      Assert::Throws<System::ArgumentNullException>(delegate_ {System::String string2(string1);}, caller_);
    }

    void ThrowsAny() {
      System::Array<System::String> array(10);
      Assert::ThrowsAny(delegate_ {array[10];}, caller_);
    }

    void AnyTest() {
      Assert::AreEqual(10, 10, caller_);
    }

  private:
    int32 value;
  };

  AddTest_(AssertTest, AreEqualInternalValue)
  AddTest_(AssertTest, AreEqualInt32)
  AddTest_(AssertTest, AreEqualInt32WithCurrentInformation)
  AddTest_(AssertTest, AreEqualInt32WithMessage)
  AddTest_(AssertTest, AreEqualInt32WithMessageAndCurrentInformation)
  AddTest_(AssertTest, AreEqualConstCharPointer)
  AddTest_(AssertTest, AreEqualConstCharPointerWithCurrentInformation)
  AddTest_(AssertTest, AreEqualConstCharPointerWithMessage)
  AddTest_(AssertTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  AddTest_(AssertTest, AreEqualString)
  AddTest_(AssertTest, AreEqualStringWithCurrentInformation)
  AddTest_(AssertTest, AreEqualStringWithMessage)
  AddTest_(AssertTest, AreEqualStringWithMessageAndCurrentInformation)
  AddTest_(AssertTest, AreEqualTimeSpan)
  AddTest_(AssertTest, AreEqualTimeSpanWithCurrentInformation)
  AddTest_(AssertTest, AreEqualTimeSpanWithMessage)
  AddTest_(AssertTest, AreEqualTimeSpanWithMessageAndCurrentInformation)
  AddTest_(AssertTest, AreEqualProperty)
  AddTest_(AssertTest, AreEqualPropertyWithCurrentInformation)
  AddTest_(AssertTest, AreEqualPropertyWithMessage)
  AddTest_(AssertTest, AreEqualPropertyWithMessageAndCurrentInformation)
  AddTest_(AssertTest, AreEqualAny)
  AddTest_(AssertTest, AreEqualAnyWithCurrentInformation)
  AddTest_(AssertTest, AreEqualAnyWithMessage)
  AddTest_(AssertTest, AreEqualAnyWithMessageAndCurrentInformation)
  AddTest_(AssertTest, AreEqualMyStruct)
  AddTest_(AssertTest, AreEqualMyStructWithCurrentInformation)
  AddTest_(AssertTest, AreEqualMyStructWithMessage)
  AddTest_(AssertTest, AreEqualMyStructWithMessageAndCurrentInformation)
  AddTest_(AssertTest, AreNotEqual)
  AddTest_(AssertTest, AreNotSame)
  AddTest_(AssertTest, AreSame)
  AddTest_(AssertTest, DoesNotThrows)
  AddTest_(AssertTest, Greater)
  AddTest_(AssertTest, GreaterOrEqual)
  AddTest_(AssertTest, IsFalse)
  AddTest_(AssertTest, IsNull)
  AddTest_(AssertTest, IsTrue)
  AddTest_(AssertTest, Less)
  AddTest_(AssertTest, LessOrEqual)
  AddTest_(AssertTest, Throws)
  AddTest_(AssertTest, ThrowsAny)
  AddTest_(AssertTest, AnyTest)
}
