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

  _test(ExpectTest, AreEqualInternalValue)
  _test(ExpectTest, AreEqualInt32)
  _test(ExpectTest, AreEqualInt32WithCurrentInformation)
  _test(ExpectTest, AreEqualInt32WithMessage)
  _test(ExpectTest, AreEqualInt32WithMessageAndCurrentInformation)
  _test(ExpectTest, AreEqualConstCharPointer)
  _test(ExpectTest, AreEqualConstCharPointerWithCurrentInformation)
  _test(ExpectTest, AreEqualConstCharPointerWithMessage)
  _test(ExpectTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  _test(ExpectTest, AreEqualString)
  _test(ExpectTest, AreEqualStringWithCurrentInformation)
  _test(ExpectTest, AreEqualStringWithMessage)
  _test(ExpectTest, AreEqualStringWithMessageAndCurrentInformation)
  _test(ExpectTest, AreNotEqual)
  _test(ExpectTest, AreNotSame)
  _test(ExpectTest, AreSame)
  _test(ExpectTest, DoesNotThrows)
  _test(ExpectTest, Greater)
  _test(ExpectTest, GreaterOrEqual)
  _test(ExpectTest, IsFalse)
  _test(ExpectTest, IsNull)
  _test(ExpectTest, IsTrue)
  _test(ExpectTest, Less)
  _test(ExpectTest, LessOrEqual)
  _test(ExpectTest, Throws)
  _test(ExpectTest, ThrowsAny)
  _test(ExpectTest, AnyTest)
}
