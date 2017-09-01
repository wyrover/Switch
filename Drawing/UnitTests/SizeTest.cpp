#include <Switch/System/Drawing/Size.hpp>
#include <Switch/System/Drawing/Point.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class Size : public TestFixture {
  public:
    void Empty() {
      Assert::AreEqual(0, Drawing::Size::Empty().Width(), _current_information);
      Assert::AreEqual(0, Drawing::Size::Empty().Height(), _current_information);
    }
    
    void CreateEmpty() {
      Drawing::Size sz;
      Assert::AreEqual(0, sz.Width(), _current_information);
      Assert::AreEqual(0, sz.Height(), _current_information);
    }
    
    void CreateSizeFromWidthHeight() {
      Drawing::Size sz(12, 346);
      Assert::AreEqual(12, sz.Width(), _current_information);
      Assert::AreEqual(346, sz.Height(), _current_information);
    }
    
    void CreateSizeFromEmptySize() {
      Drawing::Size s;
      Drawing::Size sz(s);
      Assert::AreEqual(0, sz.Width(), _current_information);
      Assert::AreEqual(0, sz.Height(), _current_information);
    }
    
    void CreateSizeFromSize() {
      Drawing::Size s(123, 456);
      Drawing::Size sz(s);
      Assert::AreEqual(123, sz.Width(), _current_information);
      Assert::AreEqual(456, sz.Height(), _current_information);
    }
    
    void CreateSizeFromEmptyPoint() {
      Drawing::Point p;
      Drawing::Size sz(p);
      Assert::AreEqual(0, sz.Width(), _current_information);
      Assert::AreEqual(0, sz.Height(), _current_information);
    }
    
    void CreateSizeFromPoint() {
      Drawing::Point p(123, 456);
      Drawing::Size sz(p);
      Assert::AreEqual(123, sz.Width(), _current_information);
      Assert::AreEqual(456, sz.Height(), _current_information);
    }
    
    void EmptySizeIsEmpty() {
      Assert::IsTrue(Drawing::Size::Empty().IsEmpty(), _current_information);
    }
    
    void SizeIsEmpty() {
      Assert::IsFalse(Drawing::Size(125, 679).IsEmpty(), _current_information);
    }
    
    void EmptySizeToString() {
      Assert::AreEqual("{Width=0, Height=0}", Drawing::Size::Empty().ToString(), _current_information);
    }
    
    void SizeToString() {
      Assert::AreEqual("{Width=54, Height=987}", Drawing::Size(54, 987).ToString(), _current_information);
    }
    
    void AddASize() {
      Assert::AreEqual(100, Drawing::Size::Add(Drawing::Size(54, 987), Drawing::Size(46, 13)).Width(), _current_information);
      Assert::AreEqual(1000, Drawing::Size::Add(Drawing::Size(54, 987), Drawing::Size(46, 13)).Height(), _current_information);
    }
    
    void SubtractASize() {
      Assert::AreEqual(50, Drawing::Size::Subtract(Drawing::Size(54, 987), Drawing::Size(4, 87)).Width(), _current_information);
      Assert::AreEqual(900, Drawing::Size::Subtract(Drawing::Size(54, 987), Drawing::Size(4, 87)).Height(), _current_information);
    }
  };
  
  _test(Size, Empty)
  _test(Size, CreateEmpty)
  _test(Size, CreateSizeFromWidthHeight)
  _test(Size, CreateSizeFromEmptySize)
  _test(Size, CreateSizeFromSize)
  _test(Size, CreateSizeFromEmptyPoint)
  _test(Size, CreateSizeFromPoint)
  _test(Size, EmptySizeIsEmpty)
  _test(Size, SizeIsEmpty)
  _test(Size, EmptySizeToString)
  _test(Size, SizeToString)
  _test(Size, AddASize)
  _test(Size, SubtractASize)
}
