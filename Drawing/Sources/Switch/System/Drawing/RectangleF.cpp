#include "../../../../Includes/Switch/System/Drawing/RectangleF.hpp"

using namespace System;
using namespace System::Drawing;

Property<RectangleF, ReadOnly> RectangleF::Empty {
  [] {return RectangleF();}
};
