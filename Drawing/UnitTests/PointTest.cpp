#include <Switch/System/Drawing/Point.hpp>
#include <Switch/System/Drawing/Size.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class Point : public TestFixture {
  public:
    void Empty() {
      Assert::AreEqual(0, Drawing::Point::Empty().X(), _current_information);
      Assert::AreEqual(0, Drawing::Point::Empty().Y(), _current_information);
    }
    
    void CreateEmpty() {
      Drawing::Point pt;
      Assert::AreEqual(0, pt.X(), _current_information);
      Assert::AreEqual(0, pt.Y(), _current_information);
    }
    
    void CreatePointFromXY() {
      Drawing::Point pt(12, 346);
      Assert::AreEqual(12, pt.X(), _current_information);
      Assert::AreEqual(346, pt.Y(), _current_information);
    }
    
    void CreatePointFromEmptyPoint() {
      Drawing::Point p;
      Drawing::Point pt(p);
      Assert::AreEqual(0, pt.X(), _current_information);
      Assert::AreEqual(0, pt.Y(), _current_information);
    }
    
    void CreatePointFromPoint() {
      Drawing::Point p(123, 456);
      Drawing::Point pt(p);
      Assert::AreEqual(123, pt.X(), _current_information);
      Assert::AreEqual(456, pt.Y(), _current_information);
    }
    
    void CreatePointFromEmptySize() {
      Drawing::Size s;
      Drawing::Point pt(s);
      Assert::AreEqual(0, pt.X(), _current_information);
      Assert::AreEqual(0, pt.Y(), _current_information);
    }
    
    void CreatePointFromSize() {
      Drawing::Size s(123, 456);
      Drawing::Point pt(s);
      Assert::AreEqual(123, pt.X(), _current_information);
      Assert::AreEqual(456, pt.Y(), _current_information);
    }
    
    void EmptyPointIsEmpty() {
      Assert::IsTrue(Drawing::Point::Empty().IsEmpty(), _current_information);
    }
    
    void PointIsEmpty() {
      Assert::IsFalse(Drawing::Point(125, 679).IsEmpty(), _current_information);
    }
    
    void EmptyPointToString() {
      Assert::AreEqual("{X=0,Y=0}", Drawing::Point::Empty().ToString(), _current_information);
    }
    
    void PointToString() {
      Assert::AreEqual("{X=54,Y=987}", Drawing::Point(54, 987).ToString(), _current_information);
    }
    
    void OffsetPoint() {
      Drawing::Point pt(10, 20);
      pt.Offset(Drawing::Point(90, 80));
      Assert::AreEqual(100, pt.X(), _current_information);
      Assert::AreEqual(100, pt.Y(), _current_information);
    }
    
    void OffsetAmount() {
      Drawing::Point pt(10, 20);
      pt.Offset(90, 80);
      Assert::AreEqual(100, pt.X(), _current_information);
      Assert::AreEqual(100, pt.Y(), _current_information);
    }
    
    void AddASize() {
      Assert::AreEqual(100, Drawing::Point::Add(Drawing::Point(54, 987), Drawing::Size(46, 13)).X(), _current_information);
      Assert::AreEqual(1000, Drawing::Point::Add(Drawing::Point(54, 987), Drawing::Size(46, 13)).Y(), _current_information);
    }
    
    void SubtractASize() {
      Assert::AreEqual(50, Drawing::Point::Subtract(Drawing::Point(54, 987), Drawing::Size(4, 87)).X(), _current_information);
      Assert::AreEqual(900, Drawing::Point::Subtract(Drawing::Point(54, 987), Drawing::Size(4, 87)).Y(), _current_information);
    }
  };
  
  _test(Point, Empty)
  _test(Point, CreateEmpty)
  _test(Point, CreatePointFromXY)
  _test(Point, CreatePointFromEmptyPoint)
  _test(Point, CreatePointFromPoint)
  _test(Point, CreatePointFromEmptySize)
  _test(Point, CreatePointFromSize)
  _test(Point, EmptyPointIsEmpty)
  _test(Point, PointIsEmpty)
  _test(Point, EmptyPointToString)
  _test(Point, PointToString)
  _test(Point, OffsetPoint)
  _test(Point, OffsetAmount)
  _test(Point, AddASize)
  _test(Point, SubtractASize)
}
