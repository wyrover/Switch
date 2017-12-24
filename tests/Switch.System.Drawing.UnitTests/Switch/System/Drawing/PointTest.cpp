#include <Switch/System/Drawing/Point.hpp>
#include <Switch/System/Drawing/Size.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(PointTest, Empty) {
    ASSERT_EQ(0, Drawing::Point::Empty().X());
    ASSERT_EQ(0, Drawing::Point::Empty().Y());
  }

  TEST(PointTest, CreateEmpty) {
    Drawing::Point pt;
    ASSERT_EQ(0, pt.X());
    ASSERT_EQ(0, pt.Y());
  }

  TEST(PointTest, CreatePointFromXY) {
    Drawing::Point pt(12, 346);
    ASSERT_EQ(12, pt.X());
    ASSERT_EQ(346, pt.Y());
  }

  TEST(PointTest, CreatePointFromEmptyPoint) {
    Drawing::Point p;
    Drawing::Point pt(p);
    ASSERT_EQ(0, pt.X());
    ASSERT_EQ(0, pt.Y());
  }

  TEST(PointTest, CreatePointFromPoint) {
    Drawing::Point p(123, 456);
    Drawing::Point pt(p);
    ASSERT_EQ(123, pt.X());
    ASSERT_EQ(456, pt.Y());
  }

  TEST(PointTest, CreatePointFromEmptySize) {
    Drawing::Size s;
    Drawing::Point pt(s);
    ASSERT_EQ(0, pt.X());
    ASSERT_EQ(0, pt.Y());
  }

  TEST(PointTest, CreatePointFromSize) {
    Drawing::Size s(123, 456);
    Drawing::Point pt(s);
    ASSERT_EQ(123, pt.X());
    ASSERT_EQ(456, pt.Y());
  }

  TEST(PointTest, EmptyPointIsEmpty) {
    ASSERT_TRUE(Drawing::Point::Empty().IsEmpty());
  }

  TEST(PointTest, PointIsEmpty) {
    ASSERT_FALSE(Drawing::Point(125, 679).IsEmpty());
  }

  TEST(PointTest, EmptyPointToString) {
    ASSERT_EQ("{X=0,Y=0}", Drawing::Point::Empty().ToString());
  }

  TEST(PointTest, PointToString) {
    ASSERT_EQ("{X=54,Y=987}", Drawing::Point(54, 987).ToString());
  }

  TEST(PointTest, OffsetPoint) {
    Drawing::Point pt(10, 20);
    pt.Offset(Drawing::Point(90, 80));
    ASSERT_EQ(100, pt.X());
    ASSERT_EQ(100, pt.Y());
  }

  TEST(PointTest, OffsetAmount) {
    Drawing::Point pt(10, 20);
    pt.Offset(90, 80);
    ASSERT_EQ(100, pt.X());
    ASSERT_EQ(100, pt.Y());
  }

  TEST(PointTest, AddASize) {
    ASSERT_EQ(100, Drawing::Point::Add(Drawing::Point(54, 987), Drawing::Size(46, 13)).X());
    ASSERT_EQ(1000, Drawing::Point::Add(Drawing::Point(54, 987), Drawing::Size(46, 13)).Y());
  }

  TEST(PointTest, SubtractASize) {
    ASSERT_EQ(50, Drawing::Point::Subtract(Drawing::Point(54, 987), Drawing::Size(4, 87)).X());
    ASSERT_EQ(900, Drawing::Point::Subtract(Drawing::Point(54, 987), Drawing::Size(4, 87)).Y());
  }

  TEST(PointTest, GetHashCode) {
    ASSERT_EQ(10 ^ 100, Drawing::Point(10, 100).GetHashCode());
  }
}

