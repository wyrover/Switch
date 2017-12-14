#include <Switch/System/Drawing/Rectangle.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(RectangleTest, Empty) {
    ASSERT_EQ(0, Rectangle::Empty().X());
    ASSERT_EQ(0, Rectangle::Empty().Y());
    ASSERT_EQ(0, Rectangle::Empty().Width());
    ASSERT_EQ(0, Rectangle::Empty().Height());
  }

  TEST(RectangleTest, CreateEmpty) {
    Drawing::Rectangle rect;
    ASSERT_EQ(0, rect.X());
    ASSERT_EQ(0, rect.Y());
    ASSERT_EQ(0, rect.Width());
    ASSERT_EQ(0, rect.Height());
  }

  TEST(RectangleTest, CreateRectangleFromXYWidthHeight) {
    Drawing::Rectangle rect(12, 346, 244, 578);
    ASSERT_EQ(12, rect.X());
    ASSERT_EQ(346, rect.Y());
    ASSERT_EQ(244, rect.Width());
    ASSERT_EQ(578, rect.Height());
  }

  TEST(RectangleTest, CreateRectangleFromEmptyRectangle) {
    Drawing::Rectangle r;
    Drawing::Rectangle rect(r);
    ASSERT_EQ(0, rect.X());
    ASSERT_EQ(0, rect.Y());
    ASSERT_EQ(0, rect.Width());
    ASSERT_EQ(0, rect.Height());
  }

  TEST(RectangleTest, CreateRectangleFromRectangle) {
    Drawing::Rectangle r(123, 456, 244, 578);
    Drawing::Rectangle rect(r);
    ASSERT_EQ(123, rect.X());
    ASSERT_EQ(456, rect.Y());
    ASSERT_EQ(244, rect.Width());
    ASSERT_EQ(578, rect.Height());
  }

  TEST(RectangleTest, CreateRectangleFromEmptyPointAndEmtpySize) {
    Drawing::Point p;
    Drawing::Size s;
    Drawing::Rectangle rect(p, s);
    ASSERT_EQ(0, rect.X());
    ASSERT_EQ(0, rect.Y());
    ASSERT_EQ(0, rect.Width());
    ASSERT_EQ(0, rect.Height());
  }

  TEST(RectangleTest, CreateRectangleFromPointAndSize) {
    Drawing::Point p(123, 456);
    Drawing::Point s(244, 578);
    Drawing::Rectangle rect(p, s);
    ASSERT_EQ(123, rect.X());
    ASSERT_EQ(456, rect.Y());
    ASSERT_EQ(244, rect.Width());
    ASSERT_EQ(578, rect.Height());
  }

  TEST(RectangleTest, EmptyRectangleIsEmpty) {
    ASSERT_TRUE(Rectangle::Empty().IsEmpty());
  }

  TEST(RectangleTest, RectangleIsEmpty) {
    ASSERT_FALSE(Drawing::Rectangle(125, 679, 244, 567).IsEmpty());
  }

  TEST(RectangleTest, EmptyRectangleToString) {
    ASSERT_EQ("{X=0,Y=0,Width=0,Height=0}", Rectangle::Empty().ToString());
  }

  TEST(RectangleTest, RectangleToString) {
    ASSERT_EQ("{X=10,Y=24,Width=54,Height=987}", Drawing::Rectangle(10, 24, 54, 987).ToString());
  }

  TEST(RectangleTest, FromLTRB) {
    Drawing::Rectangle rect = Rectangle::FromLTRB(10, 20, 100, 50);
    ASSERT_EQ(10, rect.X());
    ASSERT_EQ(20, rect.Y());
    ASSERT_EQ(90, rect.Width());
    ASSERT_EQ(30, rect.Height());
  }

  TEST(RectangleTest, GetLeftTopRightBottom) {
    Drawing::Rectangle rect(10, 20, 100, 50);

    ASSERT_EQ(rect.Y(), rect.Top());
    ASSERT_EQ(rect.X(), rect.Left());
    ASSERT_EQ(rect.X() + rect.Width(), rect.Right());
    ASSERT_EQ(rect.Y() + rect.Height(), rect.Bottom());

    ASSERT_EQ(10, rect.X());
    ASSERT_EQ(20, rect.Y());
    ASSERT_EQ(100, rect.Width());
    ASSERT_EQ(50, rect.Height());

    ASSERT_EQ(10, rect.Left());
    ASSERT_EQ(20, rect.Top());
    ASSERT_EQ(110, rect.Right());
    ASSERT_EQ(70, rect.Bottom());
  }

  TEST(RectangleTest, RectangleInflateFromXY) {
    Drawing::Rectangle rect(100, 100, 300, 200);

    rect.Inflate(50, 20);

    ASSERT_EQ(50, rect.X());
    ASSERT_EQ(80, rect.Y());
    ASSERT_EQ(400, rect.Width());
    ASSERT_EQ(240, rect.Height());

    Drawing::Rectangle rect2 = Rectangle::Inflate(rect, 50, 20);

    ASSERT_EQ(0, rect2.X());
    ASSERT_EQ(60, rect2.Y());
    ASSERT_EQ(500, rect2.Width());
    ASSERT_EQ(280, rect2.Height());
  }

  TEST(RectangleTest, RectangleInflateFromSize) {
    Drawing::Rectangle rect(100, 100, 300, 200);

    rect.Inflate(Drawing::Size(50, 20));

    ASSERT_EQ(50, rect.X());
    ASSERT_EQ(80, rect.Y());
    ASSERT_EQ(400, rect.Width());
    ASSERT_EQ(240, rect.Height());
  }

  TEST(RectangleTest, Intersect) {
    Drawing::Rectangle rectangle1(50, 50, 200, 100);
    Drawing::Rectangle rectangle2(70, 20, 100, 200);
    Drawing::Rectangle rectangle3 = Rectangle::Intersect(rectangle1, rectangle2);
    ASSERT_TRUE(rectangle3.IsEmpty());
  }
}

