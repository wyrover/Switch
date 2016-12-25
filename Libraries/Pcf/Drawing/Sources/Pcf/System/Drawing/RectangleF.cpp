#include "../../../../Includes/Pcf/System/Drawing/RectangleF.h"

using namespace System;
using namespace System::Drawing;

Property<RectangleF, ReadOnly> RectangleF::Empty {
  [] {return RectangleF();}
};
