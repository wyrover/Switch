#include <Pcf/System/Drawing/Size.h>
#include <Pcf/System/Drawing/Point.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class Size : public TestFixture {
  public:
    void Empty() {
      Assert::AreEqual(0, Drawing::Size::Empty.Width(), pcf_current_information);
      Assert::AreEqual(0, Drawing::Size::Empty.Height(), pcf_current_information);
    }
    
    void CreateEmpty() {
      Drawing::Size sz;
      Assert::AreEqual(0, sz.Width(), pcf_current_information);
      Assert::AreEqual(0, sz.Height(), pcf_current_information);
    }
    
    void CreateSizeFromWidthHeight() {
      Drawing::Size sz(12, 346);
      Assert::AreEqual(12, sz.Width(), pcf_current_information);
      Assert::AreEqual(346, sz.Height(), pcf_current_information);
    }
    
    void CreateSizeFromEmptySize() {
      Drawing::Size s;
      Drawing::Size sz(s);
      Assert::AreEqual(0, sz.Width(), pcf_current_information);
      Assert::AreEqual(0, sz.Height(), pcf_current_information);
    }
    
    void CreateSizeFromSize() {
      Drawing::Size s(123, 456);
      Drawing::Size sz(s);
      Assert::AreEqual(123, sz.Width(), pcf_current_information);
      Assert::AreEqual(456, sz.Height(), pcf_current_information);
    }
    
    void CreateSizeFromEmptyPoint() {
      Drawing::Point p;
      Drawing::Size sz(p);
      Assert::AreEqual(0, sz.Width(), pcf_current_information);
      Assert::AreEqual(0, sz.Height(), pcf_current_information);
    }
    
    void CreateSizeFromPoint() {
      Drawing::Point p(123, 456);
      Drawing::Size sz(p);
      Assert::AreEqual(123, sz.Width(), pcf_current_information);
      Assert::AreEqual(456, sz.Height(), pcf_current_information);
    }
    
    void EmptySizeIsEmpty() {
      Assert::IsTrue(Drawing::Size::Empty.IsEmpty(), pcf_current_information);
    }
    
    void SizeIsEmpty() {
      Assert::IsFalse(Drawing::Size(125, 679).IsEmpty(), pcf_current_information);
    }
    
    void EmptySizeToString() {
      Assert::AreEqual("{Width=0, Height=0}", Drawing::Size::Empty.ToString(), pcf_current_information);
    }
    
    void SizeToString() {
      Assert::AreEqual("{Width=54, Height=987}", Drawing::Size(54, 987).ToString(), pcf_current_information);
    }
    
    void AddASize() {
      Assert::AreEqual(100, Drawing::Size::Add(Drawing::Size(54, 987), Drawing::Size(46, 13)).Width(), pcf_current_information);
      Assert::AreEqual(1000, Drawing::Size::Add(Drawing::Size(54, 987), Drawing::Size(46, 13)).Height(), pcf_current_information);
    }
    
    void SubtractASize() {
      Assert::AreEqual(50, Drawing::Size::Subtract(Drawing::Size(54, 987), Drawing::Size(4, 87)).Width(), pcf_current_information);
      Assert::AreEqual(900, Drawing::Size::Subtract(Drawing::Size(54, 987), Drawing::Size(4, 87)).Height(), pcf_current_information);
    }
  };
  
  pcf_test(Size, Empty);
  pcf_test(Size, CreateEmpty);
  pcf_test(Size, CreateSizeFromWidthHeight);
  pcf_test(Size, CreateSizeFromEmptySize);
  pcf_test(Size, CreateSizeFromSize);
  pcf_test(Size, CreateSizeFromEmptyPoint);
  pcf_test(Size, CreateSizeFromPoint);
  pcf_test(Size, EmptySizeIsEmpty);
  pcf_test(Size, SizeIsEmpty);
  pcf_test(Size, EmptySizeToString);
  pcf_test(Size, SizeToString);
  pcf_test(Size, AddASize);
  pcf_test(Size, SubtractASize);
}
