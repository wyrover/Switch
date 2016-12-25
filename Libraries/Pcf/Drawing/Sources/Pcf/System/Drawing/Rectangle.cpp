#include "../../../../Includes/Pcf/System/Drawing/Rectangle.h"

using namespace System;
using namespace System::Drawing;

Property<Rectangle, ReadOnly> Rectangle::Empty {
  [] {return Rectangle();}
};
