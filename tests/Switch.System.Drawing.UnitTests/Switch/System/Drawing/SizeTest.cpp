#include <Switch/System/Drawing/Size.hpp>
#include <Switch/System/Drawing/Point.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(SizeTest, Empty) {
    ASSERT_EQ(0, Drawing::Size::Empty().Width());
    ASSERT_EQ(0, Drawing::Size::Empty().Height());
  }
  
  TEST(SizeTest, CreateEmpty) {
    Drawing::Size sz;
    ASSERT_EQ(0, sz.Width());
    ASSERT_EQ(0, sz.Height());
  }
  
  TEST(SizeTest, CreateSizeFromWidthHeight) {
    Drawing::Size sz(12, 346);
    ASSERT_EQ(12, sz.Width());
    ASSERT_EQ(346, sz.Height());
  }
  
  TEST(SizeTest, CreateSizeFromEmptySize) {
    Drawing::Size s;
    Drawing::Size sz(s);
    ASSERT_EQ(0, sz.Width());
    ASSERT_EQ(0, sz.Height());
  }
  
  TEST(SizeTest, CreateSizeFromSize) {
    Drawing::Size s(123, 456);
    Drawing::Size sz(s);
    ASSERT_EQ(123, sz.Width());
    ASSERT_EQ(456, sz.Height());
  }
  
  TEST(SizeTest, CreateSizeFromEmptyPoint) {
    Drawing::Point p;
    Drawing::Size sz(p);
    ASSERT_EQ(0, sz.Width());
    ASSERT_EQ(0, sz.Height());
  }
  
  TEST(SizeTest, CreateSizeFromPoint) {
    Drawing::Point p(123, 456);
    Drawing::Size sz(p);
    ASSERT_EQ(123, sz.Width());
    ASSERT_EQ(456, sz.Height());
  }
  
  TEST(SizeTest, EmptySizeIsEmpty) {
    ASSERT_TRUE(Drawing::Size::Empty().IsEmpty());
  }
  
  TEST(SizeTest, SizeIsEmpty) {
    ASSERT_FALSE(Drawing::Size(125, 679).IsEmpty());
  }
  
  TEST(SizeTest, EmptySizeToString) {
    ASSERT_EQ("{Width=0, Height=0}", Drawing::Size::Empty().ToString());
  }
  
  TEST(SizeTest, SizeToString) {
    ASSERT_EQ("{Width=54, Height=987}", Drawing::Size(54, 987).ToString());
  }
  
  TEST(SizeTest, AddASize) {
    ASSERT_EQ(100, Drawing::Size::Add(Drawing::Size(54, 987), Drawing::Size(46, 13)).Width());
    ASSERT_EQ(1000, Drawing::Size::Add(Drawing::Size(54, 987), Drawing::Size(46, 13)).Height());
  }
  
  TEST(SizeTest, SubtractASize) {
    ASSERT_EQ(50, Drawing::Size::Subtract(Drawing::Size(54, 987), Drawing::Size(4, 87)).Width());
    ASSERT_EQ(900, Drawing::Size::Subtract(Drawing::Size(54, 987), Drawing::Size(4, 87)).Height());
  }
}

