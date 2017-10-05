#include "../../../../include/Switch/System/Drawing/RectangleF.hpp"

using namespace System;
using namespace System::Drawing;

_property<RectangleF, _readonly> RectangleF::Empty {
  [] {return RectangleF();}
};
