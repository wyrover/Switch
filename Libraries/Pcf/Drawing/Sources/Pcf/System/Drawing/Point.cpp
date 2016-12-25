#include <Pcf/System/Convert.h>
#include <Pcf/System/Math.h>
#include "../../../../Includes/Pcf/System/Drawing/Point.h"
#include "../../../../Includes/Pcf/System/Drawing/PointF.h"
#include "../../../../Includes/Pcf/System/Drawing/Size.h"

using namespace System;
using namespace System::Drawing;

const Point Point::Empty;

Point::Point(const Size& sz) {
  this->x = sz.Width();
  this->y = sz.Height();
}

Point Point::Ceiling(const PointF &pt) {
  return Point(Convert::ToInt32(Math::Ceiling(pt.X())), Convert::ToInt32(Math::Ceiling(pt.Y())));
}

bool Point::Equals(const Point& value) const {
  return this->x == value.x && this->y == value.y;
}

bool Point::Equals(const object& obj) const {
  return is<Point>(obj) && Equals((const Point&)obj);
}

Point Point::Add(const Point &pt, const Size & sz) {
  return Point(pt.x + sz.Width(), pt.y + sz.Height());
}

Point Point::Round(const PointF &pt) {
  return Point(Convert::ToInt32(Math::Round(pt.X())), Convert::ToInt32(Math::Round(pt.Y())));
}

Point Point::Truncate(const PointF &pt) {
  return Point(Convert::ToInt32(Math::Truncate(pt.X())), Convert::ToInt32(Math::Truncate(pt.Y())));
}

Point Point::Subtract(const Point &pt, const Size & sz) {
  return Point(pt.x - sz.Width(), pt.y - sz.Height());
}

Point& Point::operator=(const Point& pt) {
  this->x = pt.x;
  this->y = pt.y;
  return *this;
}

Point Point::operator +(const Size & sz) const {
  return Add(*this, sz);
}

Point Point::operator -(const Size & sz) const {
  return Subtract(*this, sz);
}


Point& Point::operator +=(const Size & sz) {
  *this = Add(*this, sz);
  return *this;
}

Point& Point::operator -=(const Size & sz) {
  *this = Subtract(*this, sz);
  return *this;
}
