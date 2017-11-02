#include <Switch/System/Guid.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace SwitchUnitTests {
  class GuidTest : public TestFixture {
  protected:
    void CreateGuid() {
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid().ToString(), _caller);
    }
    
    void CreateGuidFromNativeByteArray() {
      const byte nativeByteGuid[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
      Assert::AreEqual("01020304-0506-0708-090a-0b0c0d0e0f10", Guid(nativeByteGuid).ToString(), _caller);
    }
    
    void CreateGuidFromByteArray() {
      Assert::AreEqual("10203040-5060-7080-90a0-b0c0d0e0f001", Guid(Array<byte> {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01}).ToString(), _caller);
    }
    
    void Constructor() {
      const byte nativeByteRest[]  = {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
      Assert::AreEqual("01020304-0506-0708-090a-0b0c0d0e0f10", Guid(0x01020304, 0x0506, 0x0708, nativeByteRest).ToString(), _caller);

      Assert::AreEqual("10203040-5060-7080-90a0-b0c0d0e0f001", Guid(0x10203040, 0x5060, 0x7080, Array<byte> {0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01}).ToString(), _caller);
      
      Assert::AreEqual("01020304-0506-0708-090a-0b0c0d0e0f10", Guid(int32(0x01020304), int16(0x0506), int16(0x0708), 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10).ToString(), _caller);
      Assert::AreEqual("10203040-5060-7080-90a0-b0c0d0e0f001", Guid(uint32(0x10203040), uint16(0x5060), uint16(0x7080), 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01).ToString(), _caller);
    }
    
    void Constructor2() {
      Guid guid = Guid::NewGuid();
      Assert::Greater(guid.CompareTo(Guid::Empty()), 0, _caller);
      Assert::Less(Guid::Empty().CompareTo(guid), 0, _caller);
      
      Assert::AreEqual(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01).CompareTo(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)), 0, _caller);
      Assert::Less(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01).CompareTo(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02)), 0, _caller);
      Assert::Greater(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02).CompareTo(Guid(Int32(0x00000000), Int16(0x0000), Int16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)), 0, _caller);
    }
    
    void Equals() {
      Guid guid = Guid::NewGuid();
      Guid guid2 = Guid::NewGuid();
      Assert::IsFalse(guid.Equals(Guid::Empty()), _caller);
      Assert::IsFalse(guid.Equals(guid2), _caller);
    }
    
    void NewGuid() {
      Dictionary<Guid, Guid> guids;
      for (int32 i = 0; i < 1'000; i++) {
        Guid guid = Guid::NewGuid();
        Assert::IsFalse(guids.ContainsKey(guid), _caller);
        guids.Add(guid, guid);
      }
    }
    
    void ToString() {
      Assert::Throws<FormatException>(_delegate {Guid::Empty().ToString("A");}, _caller);
      Assert::Throws<FormatException>(_delegate {Guid::Empty().ToString("ND");}, _caller);
      
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid::Empty().ToString(), _caller);
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid::Empty().ToString(""), _caller);
      Assert::AreEqual("00000000000000000000000000000000", Guid::Empty().ToString("N"), _caller);
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid::Empty().ToString("D"), _caller);
      Assert::AreEqual("{00000000-0000-0000-0000-000000000000}", Guid::Empty().ToString("B"), _caller);
      Assert::AreEqual("(00000000-0000-0000-0000-000000000000)", Guid::Empty().ToString("P"), _caller);
      Assert::AreEqual("{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}", Guid::Empty().ToString("X"), _caller);
      Assert::AreEqual("00000000000000000000000000000000", Guid::Empty().ToString("n"), _caller);
      Assert::AreEqual("00000000-0000-0000-0000-000000000000", Guid::Empty().ToString("d"), _caller);
      Assert::AreEqual("{00000000-0000-0000-0000-000000000000}", Guid::Empty().ToString("b"), _caller);
      Assert::AreEqual("(00000000-0000-0000-0000-000000000000)", Guid::Empty().ToString("p"), _caller);
      Assert::AreEqual("{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}", Guid::Empty().ToString("x"), _caller);
    }
    
    void CompareTo() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::Less(guid1.CompareTo(guid2), 0, _caller);
      Assert::Greater(guid2.CompareTo(guid1), 0, _caller);
    }
    
    void LessThanOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 < guid2, _caller);
      Assert::IsFalse(guid2 < guid1, _caller);
    }
    
    void LessEqualOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 <= guid2, _caller);
      Assert::IsTrue(guid1 <= guid3, _caller);
      Assert::IsFalse(guid2 <= guid1, _caller);
    }
    
    void GreateThanOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 > guid2, _caller);
      Assert::IsFalse(guid2 > guid1, _caller);
    }
    
    void GreaterEqualOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 >= guid2, _caller);
      Assert::IsTrue(guid1 >= guid3, _caller);
      Assert::IsFalse(guid2 >= guid1, _caller);
    }
    
    void EqualOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::IsFalse(guid1 == guid2, _caller);
      Assert::IsTrue(guid1 == guid3, _caller);
    }
    
    void DifferentOperator() {
      Guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      Guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      Guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      Assert::IsTrue(guid1 != guid2, _caller);
      Assert::IsFalse(guid1 != guid3, _caller);
    }
  };
  
  _add_test(GuidTest, CreateGuid)
  _add_test(GuidTest, CreateGuidFromNativeByteArray)
  _add_test(GuidTest, CreateGuidFromByteArray)
  _add_test(GuidTest, Constructor)
  _add_test(GuidTest, Constructor2)
  _add_test(GuidTest, Equals)
  _add_test(GuidTest, NewGuid)
  _add_test(GuidTest, ToString)
  _add_test(GuidTest, CompareTo)
  _add_test(GuidTest, LessThanOperator)
  _add_test(GuidTest, LessEqualOperator)
  _add_test(GuidTest, GreateThanOperator)
  _add_test(GuidTest, GreaterEqualOperator)
  _add_test(GuidTest, EqualOperator)
  _add_test(GuidTest, DifferentOperator)
}
