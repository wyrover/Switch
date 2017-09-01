#include <Switch/System/Drawing/Rectangle.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Drawing;
using namespace TUnit;

namespace SwitchUnitTests {
  class RectangleTest : public TestFixture {
  public:
    void Empty() {
      Assert::AreEqual(0, Rectangle::Empty().X(), _current_information);
      Assert::AreEqual(0, Rectangle::Empty().Y(), _current_information);
      Assert::AreEqual(0, Rectangle::Empty().Width(), _current_information);
      Assert::AreEqual(0, Rectangle::Empty().Height(), _current_information);
    }
    
    void CreateEmpty() {
      Drawing::Rectangle rect;
      Assert::AreEqual(0, rect.X(), _current_information);
      Assert::AreEqual(0, rect.Y(), _current_information);
      Assert::AreEqual(0, rect.Width(), _current_information);
      Assert::AreEqual(0, rect.Height(), _current_information);
    }
    
    void CreateRectangleFromXYWidthHeight() {
      Drawing::Rectangle rect(12, 346, 244, 578);
      Assert::AreEqual(12, rect.X(), _current_information);
      Assert::AreEqual(346, rect.Y(), _current_information);
      Assert::AreEqual(244, rect.Width(), _current_information);
      Assert::AreEqual(578, rect.Height(), _current_information);
    }
    
    void CreateRectangleFromEmptyRectangle() {
      Drawing::Rectangle r;
      Drawing::Rectangle rect(r);
      Assert::AreEqual(0, rect.X(), _current_information);
      Assert::AreEqual(0, rect.Y(), _current_information);
      Assert::AreEqual(0, rect.Width(), _current_information);
      Assert::AreEqual(0, rect.Height(), _current_information);
    }
    
    void CreateRectangleFromRectangle() {
      Drawing::Rectangle r(123, 456, 244, 578);
      Drawing::Rectangle rect(r);
      Assert::AreEqual(123, rect.X(), _current_information);
      Assert::AreEqual(456, rect.Y(), _current_information);
      Assert::AreEqual(244, rect.Width(), _current_information);
      Assert::AreEqual(578, rect.Height(), _current_information);
    }
    
    void CreateRectangleFromEmptyPointAndEmtpySize() {
      Drawing::Point p;
      Drawing::Size s;
      Drawing::Rectangle rect(p, s);
      Assert::AreEqual(0, rect.X(), _current_information);
      Assert::AreEqual(0, rect.Y(), _current_information);
      Assert::AreEqual(0, rect.Width(), _current_information);
      Assert::AreEqual(0, rect.Height(), _current_information);
    }
    
    void CreateRectangleFromPointAndSize() {
      Drawing::Point p(123, 456);
      Drawing::Point s(244, 578);
      Drawing::Rectangle rect(p, s);
      Assert::AreEqual(123, rect.X(), _current_information);
      Assert::AreEqual(456, rect.Y(), _current_information);
      Assert::AreEqual(244, rect.Width(), _current_information);
      Assert::AreEqual(578, rect.Height(), _current_information);
    }
    
    void EmptyRectangleIsEmpty() {
      Assert::IsTrue(Rectangle::Empty().IsEmpty(), _current_information);
    }
    
    void RectangleIsEmpty() {
      Assert::IsFalse(Drawing::Rectangle(125, 679, 244, 567).IsEmpty(), _current_information);
    }
    
    void EmptyRectangleToString() {
      Assert::AreEqual("{X=0,Y=0,Width=0,Height=0}", Rectangle::Empty().ToString(), _current_information);
    }
    
    void RectangleToString() {
      Assert::AreEqual("{X=10,Y=24,Width=54,Height=987}", Drawing::Rectangle(10, 24, 54, 987).ToString(), _current_information);
    }
    
    void FromLTRB() {
      Drawing::Rectangle rect = Rectangle::FromLTRB(10, 20, 100, 50);
      Assert::AreEqual(10, rect.X(), _current_information);
      Assert::AreEqual(20, rect.Y(), _current_information);
      Assert::AreEqual(90, rect.Width(), _current_information);
      Assert::AreEqual(30, rect.Height(), _current_information);
    }
    
    void GetLeftTopRightBottom() {
      Drawing::Rectangle rect(10, 20, 100, 50);

      Assert::AreEqual(rect.Y(), rect.Top(), _current_information);
      Assert::AreEqual(rect.X(), rect.Left(), _current_information);
      Assert::AreEqual(rect.X() + rect.Width(), rect.Right(), _current_information);
      Assert::AreEqual(rect.Y() + rect.Height(), rect.Bottom(), _current_information);
      
      Assert::AreEqual(10, rect.X(), _current_information);
      Assert::AreEqual(20, rect.Y(), _current_information);
      Assert::AreEqual(100, rect.Width(), _current_information);
      Assert::AreEqual(50, rect.Height(), _current_information);
      
      Assert::AreEqual(10, rect.Left(), _current_information);
      Assert::AreEqual(20, rect.Top(), _current_information);
      Assert::AreEqual(110, rect.Right(), _current_information);
      Assert::AreEqual(70, rect.Bottom(), _current_information);
    }
    
    void RectangleInflateFromXY() {
      Drawing::Rectangle rect(100, 100, 300, 200);
      
      rect.Inflate(50, 20);
      
      Assert::AreEqual(50, rect.X(), _current_information);
      Assert::AreEqual(80, rect.Y(), _current_information);
      Assert::AreEqual(400, rect.Width(), _current_information);
      Assert::AreEqual(240, rect.Height(), _current_information);

      Drawing::Rectangle rect2 = Rectangle::Inflate(rect, 50, 20);
      
      Assert::AreEqual(0, rect2.X(), _current_information);
      Assert::AreEqual(60, rect2.Y(), _current_information);
      Assert::AreEqual(500, rect2.Width(), _current_information);
      Assert::AreEqual(280, rect2.Height(), _current_information);
    }
    
    void RectangleInflateFromSize() {
      Drawing::Rectangle rect(100, 100, 300, 200);
      
      rect.Inflate(Drawing::Size(50, 20));
      
      Assert::AreEqual(50, rect.X(), _current_information);
      Assert::AreEqual(80, rect.Y(), _current_information);
      Assert::AreEqual(400, rect.Width(), _current_information);
      Assert::AreEqual(240, rect.Height(), _current_information);
    }
    
    void Intersect() {
      Drawing::Rectangle rectangle1(50, 50, 200, 100);
      Drawing::Rectangle rectangle2(70, 20, 100, 200);
      Drawing::Rectangle rectangle3 = Rectangle::Intersect(rectangle1, rectangle2);
      Assert::IsTrue(rectangle3.IsEmpty());
    }
  };
  
  _test(RectangleTest, Empty)
  _test(RectangleTest, CreateEmpty)
  _test(RectangleTest, CreateRectangleFromXYWidthHeight)
  _test(RectangleTest, CreateRectangleFromEmptyRectangle)
  _test(RectangleTest, CreateRectangleFromRectangle)
  _test(RectangleTest, CreateRectangleFromEmptyPointAndEmtpySize)
  _test(RectangleTest, CreateRectangleFromPointAndSize)
  _test(RectangleTest, EmptyRectangleIsEmpty)
  _test(RectangleTest, RectangleIsEmpty)
  _test(RectangleTest, EmptyRectangleToString)
  _test(RectangleTest, RectangleToString)
  _test(RectangleTest, FromLTRB)
  _test(RectangleTest, GetLeftTopRightBottom)
  _test(RectangleTest, RectangleInflateFromXY)
  _test(RectangleTest, RectangleInflateFromSize)
  _test(RectangleTest, Intersect)
}
