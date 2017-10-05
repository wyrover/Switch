#include "../../../../include/Switch/System/Drawing/Rectangle.hpp"

using namespace System;
using namespace System::Drawing;

_property<Rectangle, _readonly> Rectangle::Empty {
  [] {return Rectangle();}
};
