#include <Switch/System/Version.hpp>
#include <Switch/TUnit/Expect.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace TUnit;

namespace SwitchUnitTests {
  class ExpectTest : public TestFixture {
  protected:
    ExpectTest() {}

    void SetUp() override {
      value = 42;
    }

    void TearDown() override {
      value = 0;
    }

    void AreEqualInternalValue() {
      Expect::AreEqual(42, this->value, caller_);
    }

    void AreEqualInt32() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo);
    }

    void AreEqualInt32WithCurrentInformation() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, caller_);
    }

    void AreEqualInt32WithMessage() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, "My message");
    }

    void AreEqualInt32WithMessageAndCurrentInformation() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, "My message", caller_);
    }

    void AreEqualConstCharPointer() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo);
    }

    void AreEqualConstCharPointerWithCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, caller_);
    }

    void AreEqualConstCharPointerWithMessage() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message");
    }

    void AreEqualConstCharPointerWithMessageAndCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message", caller_);
    }

    void AreEqualString() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo);
    }

    void AreEqualStringWithCurrentInformation() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, caller_);
    }

    void AreEqualStringWithMessage() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message");
    }

    void AreEqualStringWithMessageAndCurrentInformation() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message", caller_);
    }

    void AreNotEqual() {
      System::String string = "Test";
      Expect::AreNotEqual("Tes", string, caller_);
    }

    void AreNotSame() {
      System::Version ver1(1, 2, 3);
      System::Version ver2(1, 2, 3);
      Expect::AreNotSame(ver1, ver2, caller_);
    }

    void AreSame() {
      System::DateTime date1 = System::DateTime::Now();
      System::DateTime* date2 = &date1;
      Expect::AreSame(date1, *date2, caller_);
    }

    void DoesNotThrows() {
      const char* string1 = "Not null";
      Expect::DoesNotThrows(delegate_ {System::String string2(string1);}, caller_);
    }

    void Greater() {
      int32 fourtyTwo = 42;
      Expect::Greater(fourtyTwo, 40, caller_);
    }

    void GreaterOrEqual() {
      int32 fourtyTwo = 42;
      Expect::GreaterOrEqual(fourtyTwo, 40, caller_);
      Expect::GreaterOrEqual(fourtyTwo, 42, caller_);
    }

    void IsFalse() {
      bool boolean = false;
      Expect::IsFalse(boolean, caller_);
    }

    void IsNull() {
      System::Object* pointer = null;
      Expect::IsNull(pointer, caller_);
    }

    void IsTrue() {
      bool boolean = true;
      Expect::IsTrue(boolean, caller_);
    }

    void Less() {
      int32 fourtyTwo = 42;
      Expect::Less(fourtyTwo, 44, caller_);
    }

    void LessOrEqual() {
      int32 fourtyTwo = 42;
      Expect::LessOrEqual(fourtyTwo, 44, caller_);
      Expect::LessOrEqual(fourtyTwo, 42, caller_);
    }

    void Throws() {
      const char* string1 = null;
      Expect::Throws<System::ArgumentNullException>(delegate_ {System::String string2(string1);}, caller_);
    }

    void ThrowsAny() {
      System::Array<System::String> array(10);
      Expect::ThrowsAny(delegate_ {array[10];}, caller_);
    }

    void AnyTest() {
      Expect::AreEqual(10, 10, caller_);
    }

  private:
    int32 value;
  };

  AddTest_(ExpectTest, AreEqualInternalValue)
  AddTest_(ExpectTest, AreEqualInt32)
  AddTest_(ExpectTest, AreEqualInt32WithCurrentInformation)
  AddTest_(ExpectTest, AreEqualInt32WithMessage)
  AddTest_(ExpectTest, AreEqualInt32WithMessageAndCurrentInformation)
  AddTest_(ExpectTest, AreEqualConstCharPointer)
  AddTest_(ExpectTest, AreEqualConstCharPointerWithCurrentInformation)
  AddTest_(ExpectTest, AreEqualConstCharPointerWithMessage)
  AddTest_(ExpectTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  AddTest_(ExpectTest, AreEqualString)
  AddTest_(ExpectTest, AreEqualStringWithCurrentInformation)
  AddTest_(ExpectTest, AreEqualStringWithMessage)
  AddTest_(ExpectTest, AreEqualStringWithMessageAndCurrentInformation)
  AddTest_(ExpectTest, AreNotEqual)
  AddTest_(ExpectTest, AreNotSame)
  AddTest_(ExpectTest, AreSame)
  AddTest_(ExpectTest, DoesNotThrows)
  AddTest_(ExpectTest, Greater)
  AddTest_(ExpectTest, GreaterOrEqual)
  AddTest_(ExpectTest, IsFalse)
  AddTest_(ExpectTest, IsNull)
  AddTest_(ExpectTest, IsTrue)
  AddTest_(ExpectTest, Less)
  AddTest_(ExpectTest, LessOrEqual)
  AddTest_(ExpectTest, Throws)
  AddTest_(ExpectTest, ThrowsAny)
  AddTest_(ExpectTest, AnyTest)
}
