#include <Pcf/System/Drawing/Point.h>
#include <Pcf/System/Drawing/Size.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class Point : public TestFixture {
  public:
    void Empty() {
      Assert::AreEqual(0, Drawing::Point::Empty().X(), pcf_current_information);
      Assert::AreEqual(0, Drawing::Point::Empty().Y(), pcf_current_information);
    }
    
    void CreateEmpty() {
      Drawing::Point pt;
      Assert::AreEqual(0, pt.X(), pcf_current_information);
      Assert::AreEqual(0, pt.Y(), pcf_current_information);
    }
    
    void CreatePointFromXY() {
      Drawing::Point pt(12, 346);
      Assert::AreEqual(12, pt.X(), pcf_current_information);
      Assert::AreEqual(346, pt.Y(), pcf_current_information);
    }
    
    void CreatePointFromEmptyPoint() {
      Drawing::Point p;
      Drawing::Point pt(p);
      Assert::AreEqual(0, pt.X(), pcf_current_information);
      Assert::AreEqual(0, pt.Y(), pcf_current_information);
    }
    
    void CreatePointFromPoint() {
      Drawing::Point p(123, 456);
      Drawing::Point pt(p);
      Assert::AreEqual(123, pt.X(), pcf_current_information);
      Assert::AreEqual(456, pt.Y(), pcf_current_information);
    }
    
    void CreatePointFromEmptySize() {
      Drawing::Size s;
      Drawing::Point pt(s);
      Assert::AreEqual(0, pt.X(), pcf_current_information);
      Assert::AreEqual(0, pt.Y(), pcf_current_information);
    }
    
    void CreatePointFromSize() {
      Drawing::Size s(123, 456);
      Drawing::Point pt(s);
      Assert::AreEqual(123, pt.X(), pcf_current_information);
      Assert::AreEqual(456, pt.Y(), pcf_current_information);
    }
    
    void EmptyPointIsEmpty() {
      Assert::IsTrue(Drawing::Point::Empty().IsEmpty(), pcf_current_information);
    }
    
    void PointIsEmpty() {
      Assert::IsFalse(Drawing::Point(125, 679).IsEmpty(), pcf_current_information);
    }
    
    void EmptyPointToString() {
      Assert::AreEqual("{X=0,Y=0}", Drawing::Point::Empty().ToString(), pcf_current_information);
    }
    
    void PointToString() {
      Assert::AreEqual("{X=54,Y=987}", Drawing::Point(54, 987).ToString(), pcf_current_information);
    }
    
    void OffsetPoint() {
      Drawing::Point pt(10, 20);
      pt.Offset(Drawing::Point(90, 80));
      Assert::AreEqual(100, pt.X(), pcf_current_information);
      Assert::AreEqual(100, pt.Y(), pcf_current_information);
    }
    
    void OffsetAmount() {
      Drawing::Point pt(10, 20);
      pt.Offset(90, 80);
      Assert::AreEqual(100, pt.X(), pcf_current_information);
      Assert::AreEqual(100, pt.Y(), pcf_current_information);
    }
    
    void AddASize() {
      Assert::AreEqual(100, Drawing::Point::Add(Drawing::Point(54, 987), Drawing::Size(46, 13)).X(), pcf_current_information);
      Assert::AreEqual(1000, Drawing::Point::Add(Drawing::Point(54, 987), Drawing::Size(46, 13)).Y(), pcf_current_information);
    }
    
    void SubtractASize() {
      Assert::AreEqual(50, Drawing::Point::Subtract(Drawing::Point(54, 987), Drawing::Size(4, 87)).X(), pcf_current_information);
      Assert::AreEqual(900, Drawing::Point::Subtract(Drawing::Point(54, 987), Drawing::Size(4, 87)).Y(), pcf_current_information);
    }
  };
  
  pcf_test(Point, Empty)
  pcf_test(Point, CreateEmpty)
  pcf_test(Point, CreatePointFromXY)
  pcf_test(Point, CreatePointFromEmptyPoint)
  pcf_test(Point, CreatePointFromPoint)
  pcf_test(Point, CreatePointFromEmptySize)
  pcf_test(Point, CreatePointFromSize)
  pcf_test(Point, EmptyPointIsEmpty)
  pcf_test(Point, PointIsEmpty)
  pcf_test(Point, EmptyPointToString)
  pcf_test(Point, PointToString)
  pcf_test(Point, OffsetPoint)
  pcf_test(Point, OffsetAmount)
  pcf_test(Point, AddASize)
  pcf_test(Point, SubtractASize)
}
