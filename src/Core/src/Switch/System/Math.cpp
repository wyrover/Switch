#include <cmath>
#include <cstdio>

#include "../../../include/Switch/System/Math.hpp"

using namespace System;

_property<double, _readonly> Math::E {
  [] {return 2.7182818284590452354;}
};

_property<double, _readonly> Math::PI {
  [] {return 3.14159265358979323846;}
};

double Math::Acos(double value) {
  return acos(value);
}

double Math::Asin(double value) {
  return asin(value);
}

double Math::Atan(double value) {
  return atan(value);
}

double Math::Atan2(double y, double x) {
  return Double::IsInfinity(y) && Double::IsInfinity(x) ? Double::NaN : atan2(y, x);
}

double Math::Ceiling(double value) {
  return ceil(value);
}

double Math::Cos(double value) {
  return cos(value);
}

double Math::Cosh(double value) {
  return cosh(value);
}

double Math::Exp(double value) {
  return exp(value);
}

double Math::Floor(double value) {
  return floor(value);
}

double Math::Log(double value) {
  return log(value);
}

double Math::Log10(double value) {
  return log10(value);
}

double Math::Pow(double x, double y) {
  return pow(x, y);
}

double Math::Sin(double value) {
  return sin(value);
}

double Math::Sinh(double value) {
  return sinh(value);
}

double Math::Sqrt(double value) {
  return sqrt(value);
}

double Math::Tan(double value) {
  return tan(value);
}

double Math::Tanh(double value) {
  return tanh(value);
}
