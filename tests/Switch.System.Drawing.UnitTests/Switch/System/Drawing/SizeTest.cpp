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
      Assert::AreEqual(0, Drawing::Size::Empty().Width(), _caller);
      Assert::AreEqual(0, Drawing::Size::Empty().Height(), _caller);
    }
    
    void CreateEmpty() {
      Drawing::Size sz;
      Assert::AreEqual(0, sz.Width(), _caller);
      Assert::AreEqual(0, sz.Height(), _caller);
    }
    
    void CreateSizeFromWidthHeight() {
      Drawing::Size sz(12, 346);
      Assert::AreEqual(12, sz.Width(), _caller);
      Assert::AreEqual(346, sz.Height(), _caller);
    }
    
    void CreateSizeFromEmptySize() {
      Drawing::Size s;
      Drawing::Size sz(s);
      Assert::AreEqual(0, sz.Width(), _caller);
      Assert::AreEqual(0, sz.Height(), _caller);
    }
    
    void CreateSizeFromSize() {
      Drawing::Size s(123, 456);
      Drawing::Size sz(s);
      Assert::AreEqual(123, sz.Width(), _caller);
      Assert::AreEqual(456, sz.Height(), _caller);
    }
    
    void CreateSizeFromEmptyPoint() {
      Drawing::Point p;
      Drawing::Size sz(p);
      Assert::AreEqual(0, sz.Width(), _caller);
      Assert::AreEqual(0, sz.Height(), _caller);
    }
    
    void CreateSizeFromPoint() {
      Drawing::Point p(123, 456);
      Drawing::Size sz(p);
      Assert::AreEqual(123, sz.Width(), _caller);
      Assert::AreEqual(456, sz.Height(), _caller);
    }
    
    void EmptySizeIsEmpty() {
      Assert::IsTrue(Drawing::Size::Empty().IsEmpty(), _caller);
    }
    
    void SizeIsEmpty() {
      Assert::IsFalse(Drawing::Size(125, 679).IsEmpty(), _caller);
    }
    
    void EmptySizeToString() {
      Assert::AreEqual("{Width=0, Height=0}", Drawing::Size::Empty().ToString(), _caller);
    }
    
    void SizeToString() {
      Assert::AreEqual("{Width=54, Height=987}", Drawing::Size(54, 987).ToString(), _caller);
    }
    
    void AddASize() {
      Assert::AreEqual(100, Drawing::Size::Add(Drawing::Size(54, 987), Drawing::Size(46, 13)).Width(), _caller);
      Assert::AreEqual(1000, Drawing::Size::Add(Drawing::Size(54, 987), Drawing::Size(46, 13)).Height(), _caller);
    }
    
    void SubtractASize() {
      Assert::AreEqual(50, Drawing::Size::Subtract(Drawing::Size(54, 987), Drawing::Size(4, 87)).Width(), _caller);
      Assert::AreEqual(900, Drawing::Size::Subtract(Drawing::Size(54, 987), Drawing::Size(4, 87)).Height(), _caller);
    }
  };
  
  _add_test (Size, Empty)
  _add_test (Size, CreateEmpty)
  _add_test (Size, CreateSizeFromWidthHeight)
  _add_test (Size, CreateSizeFromEmptySize)
  _add_test (Size, CreateSizeFromSize)
  _add_test (Size, CreateSizeFromEmptyPoint)
  _add_test (Size, CreateSizeFromPoint)
  _add_test (Size, EmptySizeIsEmpty)
  _add_test (Size, SizeIsEmpty)
  _add_test (Size, EmptySizeToString)
  _add_test (Size, SizeToString)
  _add_test (Size, AddASize)
  _add_test (Size, SubtractASize)
}
