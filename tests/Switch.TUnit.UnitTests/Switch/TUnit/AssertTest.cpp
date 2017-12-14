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
      Assert::AreEqual(42, this->value, _caller);
    }

    void AreEqualInt32() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo);
    }

    void AreEqualInt32WithCurrentInformation() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, _caller);
    }

    void AreEqualInt32WithMessage() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message");
    }

    void AreEqualInt32WithMessageAndCurrentInformation() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message", _caller);
    }

    void AreEqualConstCharPointer() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo);
    }

    void AreEqualConstCharPointerWithCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, _caller);
    }

    void AreEqualConstCharPointerWithMessage() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message");
    }

    void AreEqualConstCharPointerWithMessageAndCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message", _caller);
    }

    void AreEqualString() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo);
    }

    void AreEqualStringWithCurrentInformation() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, _caller);
    }

    void AreEqualStringWithMessage() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message");
    }

    void AreEqualStringWithMessageAndCurrentInformation() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message", _caller);
    }

    void AreEqualTimeSpan() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration);
    }

    void AreEqualTimeSpanWithCurrentInformation() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, _caller);
    }

    void AreEqualTimeSpanWithMessage() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, "My message");
    }

    void AreEqualTimeSpanWithMessageAndCurrentInformation() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, "My message", _caller);
    }

    void AreEqualProperty() {
      _property<int32, _readonly> fourtyTwo {
        _get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo);
    }

    void AreEqualPropertyWithCurrentInformation() {
      _property<int32, _readonly> fourtyTwo {
        _get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, _caller);
    }

    void AreEqualPropertyWithMessage() {
      _property<int32, _readonly> fourtyTwo {
        _get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, "My message");
    }

    void AreEqualPropertyWithMessageAndCurrentInformation() {
      _property<int32, _readonly> fourtyTwo {
        _get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, "My message", _caller);
    }

    void AreEqualAny() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo);
    }

    void AreEqualAnyWithCurrentInformation() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, _caller);
    }

    void AreEqualAnyWithMessage() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message");
    }

    void AreEqualAnyWithMessageAndCurrentInformation() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message", _caller);
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
      Expect::AreEqual(MyStruct(42), fourtyTwo, _caller);
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
      Assert::AreEqual(MyStruct(42), fourtyTwo, "My message", _caller);
    }

    void AreNotEqual() {
      String string = "Test";
      Assert::AreNotEqual("Tes", string, _caller);
    }

    void AreNotSame() {
      Version ver1(1, 2, 3);
      Version ver2(1, 2, 3);
      Assert::AreNotSame(ver2, ver1, _caller);
    }

    void AreSame() {
      System::DateTime date1 = System::DateTime::Now();
      System::DateTime* date2 = &date1;
      Assert::AreSame(date1, *date2, _caller);
    }

    void DoesNotThrows() {
      const char* string1 = "Not null";
      Assert::DoesNotThrows(_delegate {System::String string2(string1);}, _caller);
    }

    void Greater() {
      int32 fourtyTwo = 42;
      Assert::Greater(fourtyTwo, 40, _caller);
    }

    void GreaterOrEqual() {
      int32 fourtyTwo = 42;
      Assert::GreaterOrEqual(fourtyTwo, 40, _caller);
      Assert::GreaterOrEqual(fourtyTwo, 42, _caller);
    }

    void IsFalse() {
      bool boolean = false;
      Assert::IsFalse(boolean, _caller);
    }

    void IsNull() {
      System::Object* pointer = null;
      Assert::IsNull(pointer, _caller);
    }

    void IsTrue() {
      bool boolean = true;
      Assert::IsTrue(boolean, _caller);
    }

    void Less() {
      int32 fourtyTwo = 42;
      Assert::Less(fourtyTwo, 44, _caller);
    }

    void LessOrEqual() {
      int32 fourtyTwo = 42;
      Assert::LessOrEqual(fourtyTwo, 44, _caller);
      Assert::LessOrEqual(fourtyTwo, 42, _caller);
    }


    void Throws() {
      const char* string1 = null;
      Assert::Throws<System::ArgumentNullException>(_delegate {System::String string2(string1);}, _caller);
    }

    void ThrowsAny() {
      System::Array<System::String> array(10);
      Assert::ThrowsAny(_delegate {array[10];}, _caller);
    }

    void AnyTest() {
      Assert::AreEqual(10, 10, _caller);
    }

  private:
    int32 value;
  };

  _AddTest(AssertTest, AreEqualInternalValue)
  _AddTest(AssertTest, AreEqualInt32)
  _AddTest(AssertTest, AreEqualInt32WithCurrentInformation)
  _AddTest(AssertTest, AreEqualInt32WithMessage)
  _AddTest(AssertTest, AreEqualInt32WithMessageAndCurrentInformation)
  _AddTest(AssertTest, AreEqualConstCharPointer)
  _AddTest(AssertTest, AreEqualConstCharPointerWithCurrentInformation)
  _AddTest(AssertTest, AreEqualConstCharPointerWithMessage)
  _AddTest(AssertTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  _AddTest(AssertTest, AreEqualString)
  _AddTest(AssertTest, AreEqualStringWithCurrentInformation)
  _AddTest(AssertTest, AreEqualStringWithMessage)
  _AddTest(AssertTest, AreEqualStringWithMessageAndCurrentInformation)
  _AddTest(AssertTest, AreEqualTimeSpan)
  _AddTest(AssertTest, AreEqualTimeSpanWithCurrentInformation)
  _AddTest(AssertTest, AreEqualTimeSpanWithMessage)
  _AddTest(AssertTest, AreEqualTimeSpanWithMessageAndCurrentInformation)
  _AddTest(AssertTest, AreEqualProperty)
  _AddTest(AssertTest, AreEqualPropertyWithCurrentInformation)
  _AddTest(AssertTest, AreEqualPropertyWithMessage)
  _AddTest(AssertTest, AreEqualPropertyWithMessageAndCurrentInformation)
  _AddTest(AssertTest, AreEqualAny)
  _AddTest(AssertTest, AreEqualAnyWithCurrentInformation)
  _AddTest(AssertTest, AreEqualAnyWithMessage)
  _AddTest(AssertTest, AreEqualAnyWithMessageAndCurrentInformation)
  _AddTest(AssertTest, AreEqualMyStruct)
  _AddTest(AssertTest, AreEqualMyStructWithCurrentInformation)
  _AddTest(AssertTest, AreEqualMyStructWithMessage)
  _AddTest(AssertTest, AreEqualMyStructWithMessageAndCurrentInformation)
  _AddTest(AssertTest, AreNotEqual)
  _AddTest(AssertTest, AreNotSame)
  _AddTest(AssertTest, AreSame)
  _AddTest(AssertTest, DoesNotThrows)
  _AddTest(AssertTest, Greater)
  _AddTest(AssertTest, GreaterOrEqual)
  _AddTest(AssertTest, IsFalse)
  _AddTest(AssertTest, IsNull)
  _AddTest(AssertTest, IsTrue)
  _AddTest(AssertTest, Less)
  _AddTest(AssertTest, LessOrEqual)
  _AddTest(AssertTest, Throws)
  _AddTest(AssertTest, ThrowsAny)
  _AddTest(AssertTest, AnyTest)
}
