#include "../../../../Includes/Pcf/System/Drawing/Pen.h"
#include "../../../__OS/DrawingApi.h"

using namespace System;
using namespace System::Drawing;

void Pen::Create() {
  this->Destroy();
  this->pen = __OS::DrawingApi::Pen::CreatePen(this->dashStyle, this->width, as<SolidBrush>(this->brush)().Color);
}

void Pen::Destroy() {
  if (this->pen != IntPtr::Zero)
    __OS::DrawingApi::Pen::DeletePen(this->pen);
  this->pen = IntPtr::Zero;
}