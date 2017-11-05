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
      Assert::AreEqual(0, Drawing::Point::Empty().X(), _caller);
      Assert::AreEqual(0, Drawing::Point::Empty().Y(), _caller);
    }
    
    void CreateEmpty() {
      Drawing::Point pt;
      Assert::AreEqual(0, pt.X(), _caller);
      Assert::AreEqual(0, pt.Y(), _caller);
    }
    
    void CreatePointFromXY() {
      Drawing::Point pt(12, 346);
      Assert::AreEqual(12, pt.X(), _caller);
      Assert::AreEqual(346, pt.Y(), _caller);
    }
    
    void CreatePointFromEmptyPoint() {
      Drawing::Point p;
      Drawing::Point pt(p);
      Assert::AreEqual(0, pt.X(), _caller);
      Assert::AreEqual(0, pt.Y(), _caller);
    }
    
    void CreatePointFromPoint() {
      Drawing::Point p(123, 456);
      Drawing::Point pt(p);
      Assert::AreEqual(123, pt.X(), _caller);
      Assert::AreEqual(456, pt.Y(), _caller);
    }
    
    void CreatePointFromEmptySize() {
      Drawing::Size s;
      Drawing::Point pt(s);
      Assert::AreEqual(0, pt.X(), _caller);
      Assert::AreEqual(0, pt.Y(), _caller);
    }
    
    void CreatePointFromSize() {
      Drawing::Size s(123, 456);
      Drawing::Point pt(s);
      Assert::AreEqual(123, pt.X(), _caller);
      Assert::AreEqual(456, pt.Y(), _caller);
    }
    
    void EmptyPointIsEmpty() {
      Assert::IsTrue(Drawing::Point::Empty().IsEmpty(), _caller);
    }
    
    void PointIsEmpty() {
      Assert::IsFalse(Drawing::Point(125, 679).IsEmpty(), _caller);
    }
    
    void EmptyPointToString() {
      Assert::AreEqual("{X=0,Y=0}", Drawing::Point::Empty().ToString(), _caller);
    }
    
    void PointToString() {
      Assert::AreEqual("{X=54,Y=987}", Drawing::Point(54, 987).ToString(), _caller);
    }
    
    void OffsetPoint() {
      Drawing::Point pt(10, 20);
      pt.Offset(Drawing::Point(90, 80));
      Assert::AreEqual(100, pt.X(), _caller);
      Assert::AreEqual(100, pt.Y(), _caller);
    }
    
    void OffsetAmount() {
      Drawing::Point pt(10, 20);
      pt.Offset(90, 80);
      Assert::AreEqual(100, pt.X(), _caller);
      Assert::AreEqual(100, pt.Y(), _caller);
    }
    
    void AddASize() {
      Assert::AreEqual(100, Drawing::Point::Add(Drawing::Point(54, 987), Drawing::Size(46, 13)).X(), _caller);
      Assert::AreEqual(1000, Drawing::Point::Add(Drawing::Point(54, 987), Drawing::Size(46, 13)).Y(), _caller);
    }
    
    void SubtractASize() {
      Assert::AreEqual(50, Drawing::Point::Subtract(Drawing::Point(54, 987), Drawing::Size(4, 87)).X(), _caller);
      Assert::AreEqual(900, Drawing::Point::Subtract(Drawing::Point(54, 987), Drawing::Size(4, 87)).Y(), _caller);
    }
  };
  
  _AddTest(Point, Empty)
  _AddTest(Point, CreateEmpty)
  _AddTest(Point, CreatePointFromXY)
  _AddTest(Point, CreatePointFromEmptyPoint)
  _AddTest(Point, CreatePointFromPoint)
  _AddTest(Point, CreatePointFromEmptySize)
  _AddTest(Point, CreatePointFromSize)
  _AddTest(Point, EmptyPointIsEmpty)
  _AddTest(Point, PointIsEmpty)
  _AddTest(Point, EmptyPointToString)
  _AddTest(Point, PointToString)
  _AddTest(Point, OffsetPoint)
  _AddTest(Point, OffsetAmount)
  _AddTest(Point, AddASize)
  _AddTest(Point, SubtractASize)
}
