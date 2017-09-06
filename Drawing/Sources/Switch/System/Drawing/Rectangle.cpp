#include "../../../../Includes/Switch/System/Drawing/Rectangle.hpp"

using namespace System;
using namespace System::Drawing;

property<Rectangle, readonly> Rectangle::Empty {
  [] {return Rectangle();}
};
