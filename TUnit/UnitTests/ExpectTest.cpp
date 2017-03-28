#include <Pcf/System/Uri.h>
#include <Pcf/TUnit/Expect.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace TUnit;

namespace PcfUnitTests {
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
      Expect::AreEqual(42, this->value, pcf_current_information);
    }
    
    void AreEqualInt32() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualInt32WithCurrentInformation() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, pcf_current_information);
    }
    
    void AreEqualInt32WithMessage() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualInt32WithMessageAndCurrentInformation() {
      int32 fourtyTwo = 42;
      Expect::AreEqual(42, fourtyTwo, "My message", pcf_current_information);
    }
    
    void AreEqualConstCharPointer() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualConstCharPointerWithCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, pcf_current_information);
    }
    
    void AreEqualConstCharPointerWithMessage() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualConstCharPointerWithMessageAndCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message", pcf_current_information);
    }
    
    void AreEqualString() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualStringWithCurrentInformation() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, pcf_current_information);
    }
    
    void AreEqualStringWithMessage() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualStringWithMessageAndCurrentInformation() {
      string fourtyTwo = "Forty two";
      Expect::AreEqual("Forty two", fourtyTwo, "My message", pcf_current_information);
    }

    void AreNotEqual() {
      System::String string = "Test";
      Expect::AreNotEqual("Tes", string, pcf_current_information);
    }

    void AreNotSame() {
      System::Uri uri1("http://www.contoso.com/index.htm?date=today");
      System::Uri uri2("http://www.contoso.com/index.htm?date=today");
      Expect::AreNotSame(uri1, uri2, pcf_current_information);
    }

    void AreSame() {
      System::DateTime date1 = System::DateTime::Now;
      System::DateTime* date2 = &date1;
      Expect::AreSame(date1, *date2, pcf_current_information);
    }

    void DoesNotThrows() {
      const char* string1 = "Not null";
      Expect::DoesNotThrows(pcf_delegate {System::String string2(string1);}, pcf_current_information);
    }

    void Greater() {
      int32 fourtyTwo = 42;
      Expect::Greater(fourtyTwo, 40, pcf_current_information);
    }

    void GreaterOrEqual() {
      int32 fourtyTwo = 42;
      Expect::GreaterOrEqual(fourtyTwo, 40, pcf_current_information);
      Expect::GreaterOrEqual(fourtyTwo, 42, pcf_current_information);
    }

    void IsFalse() {
      bool boolean = false;
      Expect::IsFalse(boolean, pcf_current_information);
    }

    void IsNull() {
      System::Object* pointer = null;
      Expect::IsNull(pointer, pcf_current_information);
    }

    void IsTrue() {
      bool boolean = true;
      Expect::IsTrue(boolean, pcf_current_information);
    }

    void Less() {
      int32 fourtyTwo = 42;
      Expect::Less(fourtyTwo, 44, pcf_current_information);
    }

    void LessOrEqual() {
      int32 fourtyTwo = 42;
      Expect::LessOrEqual(fourtyTwo, 44, pcf_current_information);
      Expect::LessOrEqual(fourtyTwo, 42, pcf_current_information);
    }

    void Throws() {
      const char* string1 = null;
      Expect::Throws<System::ArgumentNullException>(pcf_delegate {System::String string2(string1);}, pcf_current_information);
    }

    void ThrowsAny() {
      System::Array<System::String> array(10);
      Expect::ThrowsAny(pcf_delegate {array[10];}, pcf_current_information);
    }

    void AnyTest() {
      Expect::AreEqual(10, 10, pcf_current_information);
    }

  private:
    int32 value;
  };

  pcf_test(ExpectTest, AreEqualInternalValue)
  pcf_test(ExpectTest, AreEqualInt32)
  pcf_test(ExpectTest, AreEqualInt32WithCurrentInformation)
  pcf_test(ExpectTest, AreEqualInt32WithMessage)
  pcf_test(ExpectTest, AreEqualInt32WithMessageAndCurrentInformation)
  pcf_test(ExpectTest, AreEqualConstCharPointer)
  pcf_test(ExpectTest, AreEqualConstCharPointerWithCurrentInformation)
  pcf_test(ExpectTest, AreEqualConstCharPointerWithMessage)
  pcf_test(ExpectTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  pcf_test(ExpectTest, AreEqualString)
  pcf_test(ExpectTest, AreEqualStringWithCurrentInformation)
  pcf_test(ExpectTest, AreEqualStringWithMessage)
  pcf_test(ExpectTest, AreEqualStringWithMessageAndCurrentInformation)
  pcf_test(ExpectTest, AreNotEqual)
  pcf_test(ExpectTest, AreNotSame)
  pcf_test(ExpectTest, AreSame)
  pcf_test(ExpectTest, DoesNotThrows)
  pcf_test(ExpectTest, Greater)
  pcf_test(ExpectTest, GreaterOrEqual)
  pcf_test(ExpectTest, IsFalse)
  pcf_test(ExpectTest, IsNull)
  pcf_test(ExpectTest, IsTrue)
  pcf_test(ExpectTest, Less)
  pcf_test(ExpectTest, LessOrEqual)
  pcf_test(ExpectTest, Throws)
  pcf_test(ExpectTest, ThrowsAny)
  pcf_ignore_test(ExpectTest, AnyTest)
}
