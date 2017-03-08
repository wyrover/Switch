#include "../../../../Includes/Pcf/System/Drawing/Brush.h"
#include "../../../__OS/DrawingApi.h"

using namespace System;
using namespace System::Drawing;

Brush::~Brush() {
  if (this->brush.IsUnique())
    __OS::DrawingApi::Brush::DeleteBrush(this->brush());
}

void Brush::SetNativeBrush(intptr brush) {
  if (this->brush != null)
    __OS::DrawingApi::Brush::DeleteBrush(this->brush());
  this->brush = SharedPointer<intptr>::Create(brush);
}
