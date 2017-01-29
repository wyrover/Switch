#include <Pcf/System/Uri.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/Expect.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
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
      Assert::AreEqual(42, this->value, pcf_current_information);
    }
    
    void AreEqualInt32() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualInt32WithCurrentInformation() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, pcf_current_information);
    }
    
    void AreEqualInt32WithMessage() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualInt32WithMessageAndCurrentInformation() {
      int32 fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message", pcf_current_information);
    }
    
    void AreEqualConstCharPointer() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualConstCharPointerWithCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, pcf_current_information);
    }
    
    void AreEqualConstCharPointerWithMessage() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualConstCharPointerWithMessageAndCurrentInformation() {
      const char* fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message", pcf_current_information);
    }
    
    void AreEqualString() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo);
    }
    
    void AreEqualStringWithCurrentInformation() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, pcf_current_information);
    }
    
    void AreEqualStringWithMessage() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message");
    }
    
    void AreEqualStringWithMessageAndCurrentInformation() {
      string fourtyTwo = "Forty two";
      Assert::AreEqual("Forty two", fourtyTwo, "My message", pcf_current_information);
    }
    
    void AreEqualTimeSpan() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration);
    }
    
    void AreEqualTimeSpanWithCurrentInformation() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, pcf_current_information);
    }
    
    void AreEqualTimeSpanWithMessage() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, "My message");
    }
    
    void AreEqualTimeSpanWithMessageAndCurrentInformation() {
      TimeSpan duration = 42_min;
      Assert::AreEqual(42_min, duration, "My message", pcf_current_information);
    }
    
    void AreEqualProperty() {
      Property<int32, ReadOnly> fourtyTwo {
        pcf_get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualPropertyWithCurrentInformation() {
      Property<int32, ReadOnly> fourtyTwo {
        pcf_get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, pcf_current_information);
    }
    
    void AreEqualPropertyWithMessage() {
      Property<int32, ReadOnly> fourtyTwo {
        pcf_get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualPropertyWithMessageAndCurrentInformation() {
      Property<int32, ReadOnly> fourtyTwo {
        pcf_get {return 42;}
      };
      Assert::AreEqual(42, fourtyTwo, "My message", pcf_current_information);
    }
    
    void AreEqualAny() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo);
    }
    
    void AreEqualAnyWithCurrentInformation() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, pcf_current_information);
    }
    
    void AreEqualAnyWithMessage() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message");
    }
    
    void AreEqualAnyWithMessageAndCurrentInformation() {
      any fourtyTwo = 42;
      Assert::AreEqual(42, fourtyTwo, "My message", pcf_current_information);
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
      Expect::AreEqual(MyStruct(42), fourtyTwo, pcf_current_information);
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
      Assert::AreEqual(MyStruct(42), fourtyTwo, "My message", pcf_current_information);
    }
    
    void AreNotEqual() {
      String string = "Test";
      Assert::AreNotEqual("Tes", string, pcf_current_information);
    }
    
    void AreNotSame() {
      Uri uri1("http://www.contoso.com/index.htm?date=today");
      Uri uri2("http://www.contoso.com/index.htm?date=today");
      Assert::AreNotSame(uri2, uri1, pcf_current_information);
    }
    
    void AreSame() {
      System::DateTime date1 = System::DateTime::Now;
      System::DateTime* date2 = &date1;
      Assert::AreSame(date1, *date2, pcf_current_information);
    }
    
    void DoesNotThrows() {
      const char* string1 = "Not null";
      Assert::DoesNotThrows(pcf_delegate {System::String string2(string1);}, pcf_current_information);
    }
    
    void Greater() {
      int32 fourtyTwo = 42;
      Assert::Greater(fourtyTwo, 40, pcf_current_information);
    }
    
    void GreaterOrEqual() {
      int32 fourtyTwo = 42;
      Assert::GreaterOrEqual(fourtyTwo, 40, pcf_current_information);
      Assert::GreaterOrEqual(fourtyTwo, 42, pcf_current_information);
    }
    
    void IsFalse() {
      bool boolean = false;
      Assert::IsFalse(boolean, pcf_current_information);
    }
    
    void IsNull() {
      System::Object* pointer = null;
      Assert::IsNull(pointer, pcf_current_information);
    }
    
    void IsTrue() {
      bool boolean = true;
      Assert::IsTrue(boolean, pcf_current_information);
    }
    
    void Less() {
      int32 fourtyTwo = 42;
      Assert::Less(fourtyTwo, 44, pcf_current_information);
    }
    
    void LessOrEqual() {
      int32 fourtyTwo = 42;
      Assert::LessOrEqual(fourtyTwo, 44, pcf_current_information);
      Assert::LessOrEqual(fourtyTwo, 42, pcf_current_information);
    }
    
    
    void Throws() {
      const char* string1 = null;
      Assert::Throws<System::ArgumentNullException>(pcf_delegate {System::String string2(string1);}, pcf_current_information);
    }
    
    void ThrowsAny() {
      System::Array<System::String> array(10);
      Assert::ThrowsAny(pcf_delegate {array[10];}, pcf_current_information);
    }

    void AnyTest() {
      Assert::AreEqual(10, 10, pcf_current_information);
    }

  private:
    int32 value;
  };
  
  pcf_test(AssertTest, AreEqualInternalValue)
  pcf_test(AssertTest, AreEqualInt32)
  pcf_test(AssertTest, AreEqualInt32WithCurrentInformation)
  pcf_test(AssertTest, AreEqualInt32WithMessage)
  pcf_test(AssertTest, AreEqualInt32WithMessageAndCurrentInformation)
  pcf_test(AssertTest, AreEqualConstCharPointer)
  pcf_test(AssertTest, AreEqualConstCharPointerWithCurrentInformation)
  pcf_test(AssertTest, AreEqualConstCharPointerWithMessage)
  pcf_test(AssertTest, AreEqualConstCharPointerWithMessageAndCurrentInformation)
  pcf_test(AssertTest, AreEqualString)
  pcf_test(AssertTest, AreEqualStringWithCurrentInformation)
  pcf_test(AssertTest, AreEqualStringWithMessage)
  pcf_test(AssertTest, AreEqualStringWithMessageAndCurrentInformation)
  pcf_test(AssertTest, AreEqualTimeSpan)
  pcf_test(AssertTest, AreEqualTimeSpanWithCurrentInformation)
  pcf_test(AssertTest, AreEqualTimeSpanWithMessage)
  pcf_test(AssertTest, AreEqualTimeSpanWithMessageAndCurrentInformation)
  pcf_test(AssertTest, AreEqualProperty)
  pcf_test(AssertTest, AreEqualPropertyWithCurrentInformation)
  pcf_test(AssertTest, AreEqualPropertyWithMessage)
  pcf_test(AssertTest, AreEqualPropertyWithMessageAndCurrentInformation)
  pcf_test(AssertTest, AreEqualAny)
  pcf_test(AssertTest, AreEqualAnyWithCurrentInformation)
  pcf_test(AssertTest, AreEqualAnyWithMessage)
  pcf_test(AssertTest, AreEqualAnyWithMessageAndCurrentInformation)
  pcf_test(AssertTest, AreEqualMyStruct)
  pcf_test(AssertTest, AreEqualMyStructWithCurrentInformation)
  pcf_test(AssertTest, AreEqualMyStructWithMessage)
  pcf_test(AssertTest, AreEqualMyStructWithMessageAndCurrentInformation)
  pcf_test(AssertTest, AreNotEqual)
  pcf_test(AssertTest, AreNotSame)
  pcf_test(AssertTest, AreSame)
  pcf_test(AssertTest, DoesNotThrows)
  pcf_test(AssertTest, Greater)
  pcf_test(AssertTest, GreaterOrEqual)
  pcf_test(AssertTest, IsFalse)
  pcf_test(AssertTest, IsNull)
  pcf_test(AssertTest, IsTrue)
  pcf_test(AssertTest, Less)
  pcf_test(AssertTest, LessOrEqual)
  pcf_test(AssertTest, Throws)
  pcf_test(AssertTest, ThrowsAny)
  pcf_ignore_test(AssertTest, AnyTest)
}
