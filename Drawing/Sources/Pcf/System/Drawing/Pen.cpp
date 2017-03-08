#include "../../../../Includes/Pcf/System/Drawing/Pen.h"
#include "../../../__OS/DrawingApi.h"

using namespace System;
using namespace System::Drawing;

void Pen::CreatePen() {
  this->pen = __OS::DrawingApi::Pen::CreatePen(this->dashStyle, as<int32>(this->width), as<SolidBrush>(this->brush)().Color);
}

void Pen::DeletePen() {
  __OS::DrawingApi::Pen::DeletePen(this->pen);
}