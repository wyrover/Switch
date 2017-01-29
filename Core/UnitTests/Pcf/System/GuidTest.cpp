#include <Pcf/System/Guid.h>
#include <Pcf/System/Collections/Generic/SortedSet.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace PcfUnitTests {
  class GuidTest : public TestFixture {
  protected:
    void CreateGuid() {
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid().ToString(), pcf_current_information);
    }
    
    void CreateGuidFromNativeByteArray() {
      const byte nativeByteGuid[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
      Assert::AreEqual("01020304-0506-0708-090a-0b0c0d0e0f10", Guid(nativeByteGuid).ToString(), pcf_current_information);
    }
    
    void CreateGuidFromByteArray() {
      Assert::AreEqual("10203040-5060-7080-90a0-b0c0d0e0f001", Guid(Array<byte> {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01}).ToString(), pcf_current_information);
    }
    
    void Constructor() {
      const byte nativeByteRest[]  = {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
      Assert::AreEqual("01020304-0506-0708-090a-0b0c0d0e0f10", Guid(0x01020304, 0x0506, 0x0708, nativeByteRest).ToString(), pcf_current_information);

      Assert::AreEqual("10203040-5060-7080-90a0-b0c0d0e0f001", Guid(0x10203040, 0x5060, 0x7080, Array<byte> {0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01}).ToString(), pcf_current_information);
      
      Assert::AreEqual("01020304-0506-0708-090a-0b0c0d0e0f10", Guid(int32(0x01020304), int16(0x0506), int16(0x0708), 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10).ToString(), pcf_current_information);
      Assert::AreEqual("10203040-5060-7080-90a0-b0c0d0e0f001", Guid(uint32(0x10203040), uint16(0x5060), uint16(0x7080), 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01).ToString(), pcf_current_information);
    }
    
    void Constructor2() {
      Guid guid = Guid::NewGuid();
      Assert::Greater(guid.CompareTo(Guid::Empty), 0, pcf_current_information);
      Assert::Less(Guid::Empty.CompareTo(guid), 0, pcf_current_information);
      
      Assert::AreEqual(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01).CompareTo(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)), 0, pcf_current_information);
      Assert::Less(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01).CompareTo(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02)), 0, pcf_current_information);
      Assert::Greater(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02).CompareTo(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)), 0, pcf_current_information);
    }
    
    void Equals() {
      Guid guid = Guid::NewGuid();
      Guid guid2 = Guid::NewGuid();
      Assert::IsFalse(guid.Equals(Guid::Empty), pcf_current_information);
      Assert::IsFalse(guid.Equals(guid2), pcf_current_information);
    }
    
    void NewGuid() {
      SortedSet<Guid> guids;
      for (int32 i = 0; i < 1'000; i++) {
        Guid guid = Guid::NewGuid();
        Assert::IsFalse(guids.Contains(guid), pcf_current_information);
        guids.Add(guid);
      }
    }
    
    void ToString() {
      Assert::Throws<FormatException>(pcf_delegate {Guid::Empty.ToString("A");}, pcf_current_information);
      Assert::Throws<FormatException>(pcf_delegate {Guid::Empty.ToString("ND");}, pcf_current_information);
      
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid::Empty.ToString(), pcf_current_information);
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid::Empty.ToString(""), pcf_current_information);
      Assert::AreEqual("00000000000000000000000000000000", Guid::Empty.ToString("N"), pcf_current_information);
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid::Empty.ToString("D"), pcf_current_information);
      Assert::AreEqual("{00000000-0000-0000-0000-000000000000}", Guid::Empty.ToString("B"), pcf_current_information);
      Assert::AreEqual("(00000000-0000-0000-0000-000000000000)", Guid::Empty.ToString("P"), pcf_current_information);
      Assert::AreEqual("{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}", Guid::Empty.ToString("X"), pcf_current_information);
      Assert::AreEqual("00000000000000000000000000000000", Guid::Empty.ToString("n"), pcf_current_information);
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid::Empty.ToString("d"), pcf_current_information);
      Assert::AreEqual("{00000000-0000-0000-0000-000000000000}", Guid::Empty.ToString("b"), pcf_current_information);
      Assert::AreEqual("(00000000-0000-0000-0000-000000000000)", Guid::Empty.ToString("p"), pcf_current_information);
      Assert::AreEqual("{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}", Guid::Empty.ToString("x"), pcf_current_information);
    }
    
    void CompareTo() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::Less(guid1.CompareTo(guid2), 0, pcf_current_information);
      Assert::Greater(guid2.CompareTo(guid1), 0, pcf_current_information);
    }
    
    void LessThanOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 < guid2, pcf_current_information);
      Assert::IsFalse(guid2 < guid1, pcf_current_information);
    }
    
    void LessEqualOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 <= guid2, pcf_current_information);
      Assert::IsTrue(guid1 <= guid3, pcf_current_information);
      Assert::IsFalse(guid2 <= guid1, pcf_current_information);
    }
    
    void GreateThanOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 > guid2, pcf_current_information);
      Assert::IsFalse(guid2 > guid1, pcf_current_information);
    }
    
    void GreaterEqualOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 >= guid2, pcf_current_information);
      Assert::IsTrue(guid1 >= guid3, pcf_current_information);
      Assert::IsFalse(guid2 >= guid1, pcf_current_information);
    }
    
    void EqualOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::IsFalse(guid1 == guid2, pcf_current_information);
      Assert::IsTrue(guid1 == guid3, pcf_current_information);
    }
    
    void DifferentOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 != guid2, pcf_current_information);
      Assert::IsFalse(guid1 != guid3, pcf_current_information);
    }
  };
  
  pcf_test(GuidTest, CreateGuid)
  pcf_test(GuidTest, CreateGuidFromNativeByteArray)
  pcf_test(GuidTest, CreateGuidFromByteArray)
  pcf_test(GuidTest, Constructor)
  pcf_test(GuidTest, Constructor2)
  pcf_test(GuidTest, Equals)
  pcf_test(GuidTest, NewGuid)
  pcf_test(GuidTest, ToString)
  pcf_test(GuidTest, CompareTo)
  pcf_test(GuidTest, LessThanOperator)
  pcf_test(GuidTest, LessEqualOperator)
  pcf_test(GuidTest, GreateThanOperator)
  pcf_test(GuidTest, GreaterEqualOperator)
  pcf_test(GuidTest, EqualOperator)
  pcf_test(GuidTest, DifferentOperator)
}
