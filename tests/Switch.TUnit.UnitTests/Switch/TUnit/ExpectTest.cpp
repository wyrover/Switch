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
      Expect::AreEqual(42, this->value, _caller);
    }
    
    void AreEqualInt32() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualInt32WithCurrentInformation() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, _caller);
    }
    
    void AreEqualInt32WithMessage() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualInt32WithMessageAndCurrentInformation() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, "My message", _caller);
    }
    
    void AreEqualConstCharPointer() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualConstCharPointerWithCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, _caller);
    }
    
    void AreEqualConstCharPointerWithMessage() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualConstCharPointerWithMessageAndCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message", _caller);
    }
    
    void AreEqualString() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualStringWithCurrentInformation() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, _caller);
    }
    
    void AreEqualStringWithMessage() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualStringWithMessageAndCurrentInformation() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message", _caller);
    }

    void AreNotEqual() {
      System::String string = "Test";
      Expect::AreNotEqual("Tes", string, _caller);
    }

    void AreNotSame() {
      System::Version ver1(1, 2, 3);
      System::Version ver2(1, 2, 3);
      Expect::AreNotSame(ver1, ver2, _caller);
    }

    void AreSame() {
      System::DateTime date1 = System::DateTime::Now();
      System::DateTime* date2 = &date1;
      Expect::AreSame(date1, *date2, _caller);
    }

    void DoesNotThrows() {
      const char* string1 = "Not null";
      Expect::DoesNotThrows(_delegate {System::String string2(string1);}, _caller);
    }

    void Greater() {
      int32 fourtyTwo = 42;
      Expect::Greater(fourtyTwo, 40, _caller);
    }

    void GreaterOrEqual() {
      int32 fourtyTwo = 42;
      Expect::GreaterOrEqual(fourtyTwo, 40, _caller);
      Expect::GreaterOrEqual(fourtyTwo, 42, _caller);
    }

    void IsFalse() {
      bool boolean = false;
      Expect::IsFalse(boolean, _caller);
    }

    void IsNull() {
      System::Object* pointer = null;
      Expect::IsNull(pointer, _caller);
    }

    void IsTrue() {
      bool boolean = true;
      Expect::IsTrue(boolean, _caller);
    }

    void Less() {
      int32 fourtyTwo = 42;
      Expect::Less(fourtyTwo, 44, _caller);
    }

    void LessOrEqual() {
      int32 fourtyTwo = 42;
      Expect::LessOrEqual(fourtyTwo, 44, _caller);
      Expect::LessOrEqual(fourtyTwo, 42, _caller);
    }

    void Throws() {
      const char* string1 = null;
      Expect::Throws<System::ArgumentNullException>(_delegate {System::String string2(string1);}, _caller);
    }

    void ThrowsAny() {
      System::Array<System::String> array(10);
      Expect::ThrowsAny(_delegate {array[10];}, _caller);
    }

    void AnyTest() {
      Expect::AreEqual(10, 10, _caller);
    }

  private:
    int32 value;
  };

  _add_test (ExpectTest, AreEqualInternalValue)
  _add_test (ExpectTest, AreEqualInt32)
  _add_test (ExpectTest, AreEqualInt32WithCurrentInformation)
  _add_test (ExpectTest, AreEqualInt32WithMessage)
  _add_test (ExpectTest, AreEqualInt32WithMessageAndCurrentInformation)
  _add_test (ExpectTest, AreEqualConstCharPointer)
  _add_test (ExpectTest, AreEqualConstCharPointerWithCurrentInformation)
  _add_test (ExpectTest, AreEqualConstCharPointerWithMessage)
  _add_test (ExpectTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  _add_test (ExpectTest, AreEqualString)
  _add_test (ExpectTest, AreEqualStringWithCurrentInformation)
  _add_test (ExpectTest, AreEqualStringWithMessage)
  _add_test (ExpectTest, AreEqualStringWithMessageAndCurrentInformation)
  _add_test (ExpectTest, AreNotEqual)
  _add_test (ExpectTest, AreNotSame)
  _add_test (ExpectTest, AreSame)
  _add_test (ExpectTest, DoesNotThrows)
  _add_test (ExpectTest, Greater)
  _add_test (ExpectTest, GreaterOrEqual)
  _add_test (ExpectTest, IsFalse)
  _add_test (ExpectTest, IsNull)
  _add_test (ExpectTest, IsTrue)
  _add_test (ExpectTest, Less)
  _add_test (ExpectTest, LessOrEqual)
  _add_test (ExpectTest, Throws)
  _add_test (ExpectTest, ThrowsAny)
  _add_test (ExpectTest, AnyTest)
}
