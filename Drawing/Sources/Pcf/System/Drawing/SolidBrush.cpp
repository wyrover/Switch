#include "../../../../Includes/Pcf/System/Drawing/SolidBrush.h"
#include "../../../__OS/DrawingApi.h"

using namespace System;
using namespace System::Drawing;

SolidBrush::SolidBrush(const System::Drawing::Color& color) : color(color) {
  this->SetNativeBrush(__OS::DrawingApi::Brush::CreateSolidBrush(this->color));
}
