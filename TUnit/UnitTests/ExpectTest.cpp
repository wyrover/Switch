#include <Switch/System/Uri.hpp>
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
      Expect::AreEqual(42, this->value, sw_current_information);
    }
    
    void AreEqualInt32() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualInt32WithCurrentInformation() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, sw_current_information);
    }
    
    void AreEqualInt32WithMessage() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualInt32WithMessageAndCurrentInformation() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, "My message", sw_current_information);
    }
    
    void AreEqualConstCharPointer() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualConstCharPointerWithCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, sw_current_information);
    }
    
    void AreEqualConstCharPointerWithMessage() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualConstCharPointerWithMessageAndCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message", sw_current_information);
    }
    
    void AreEqualString() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualStringWithCurrentInformation() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, sw_current_information);
    }
    
    void AreEqualStringWithMessage() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualStringWithMessageAndCurrentInformation() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message", sw_current_information);
    }

    void AreNotEqual() {
      System::String string = "Test";
      Expect::AreNotEqual("Tes", string, sw_current_information);
    }

    void AreNotSame() {
      System::Uri uri1("http://www.contoso.com/index.htm?date=today");
      System::Uri uri2("http://www.contoso.com/index.htm?date=today");
      Expect::AreNotSame(uri1, uri2, sw_current_information);
    }

    void AreSame() {
      System::DateTime date1 = System::DateTime::Now;
      System::DateTime* date2 = &date1;
      Expect::AreSame(date1, *date2, sw_current_information);
    }

    void DoesNotThrows() {
      const char* string1 = "Not null";
      Expect::DoesNotThrows(sw_delegate {System::String string2(string1);}, sw_current_information);
    }

    void Greater() {
      int32 fourtyTwo = 42;
      Expect::Greater(fourtyTwo, 40, sw_current_information);
    }

    void GreaterOrEqual() {
      int32 fourtyTwo = 42;
      Expect::GreaterOrEqual(fourtyTwo, 40, sw_current_information);
      Expect::GreaterOrEqual(fourtyTwo, 42, sw_current_information);
    }

    void IsFalse() {
      bool boolean = false;
      Expect::IsFalse(boolean, sw_current_information);
    }

    void IsNull() {
      System::Object* pointer = null;
      Expect::IsNull(pointer, sw_current_information);
    }

    void IsTrue() {
      bool boolean = true;
      Expect::IsTrue(boolean, sw_current_information);
    }

    void Less() {
      int32 fourtyTwo = 42;
      Expect::Less(fourtyTwo, 44, sw_current_information);
    }

    void LessOrEqual() {
      int32 fourtyTwo = 42;
      Expect::LessOrEqual(fourtyTwo, 44, sw_current_information);
      Expect::LessOrEqual(fourtyTwo, 42, sw_current_information);
    }

    void Throws() {
      const char* string1 = null;
      Expect::Throws<System::ArgumentNullException>(sw_delegate {System::String string2(string1);}, sw_current_information);
    }

    void ThrowsAny() {
      System::Array<System::String> array(10);
      Expect::ThrowsAny(sw_delegate {array[10];}, sw_current_information);
    }

    void AnyTest() {
      Expect::AreEqual(10, 10, sw_current_information);
    }

  private:
    int32 value;
  };

  sw_test(ExpectTest, AreEqualInternalValue)
  sw_test(ExpectTest, AreEqualInt32)
  sw_test(ExpectTest, AreEqualInt32WithCurrentInformation)
  sw_test(ExpectTest, AreEqualInt32WithMessage)
  sw_test(ExpectTest, AreEqualInt32WithMessageAndCurrentInformation)
  sw_test(ExpectTest, AreEqualConstCharPointer)
  sw_test(ExpectTest, AreEqualConstCharPointerWithCurrentInformation)
  sw_test(ExpectTest, AreEqualConstCharPointerWithMessage)
  sw_test(ExpectTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  sw_test(ExpectTest, AreEqualString)
  sw_test(ExpectTest, AreEqualStringWithCurrentInformation)
  sw_test(ExpectTest, AreEqualStringWithMessage)
  sw_test(ExpectTest, AreEqualStringWithMessageAndCurrentInformation)
  sw_test(ExpectTest, AreNotEqual)
  sw_test(ExpectTest, AreNotSame)
  sw_test(ExpectTest, AreSame)
  sw_test(ExpectTest, DoesNotThrows)
  sw_test(ExpectTest, Greater)
  sw_test(ExpectTest, GreaterOrEqual)
  sw_test(ExpectTest, IsFalse)
  sw_test(ExpectTest, IsNull)
  sw_test(ExpectTest, IsTrue)
  sw_test(ExpectTest, Less)
  sw_test(ExpectTest, LessOrEqual)
  sw_test(ExpectTest, Throws)
  sw_test(ExpectTest, ThrowsAny)
  sw_ignore_test(ExpectTest, AnyTest)
}
