#include "../../../../Includes/Switch/System/Drawing/RectangleF.hpp"

using namespace System;
using namespace System::Drawing;

property<RectangleF, readonly> RectangleF::Empty {
  [] {return RectangleF();}
};
