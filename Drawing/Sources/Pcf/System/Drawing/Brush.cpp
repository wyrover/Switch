#include "../../../../Includes/Pcf/System/Drawing/Brush.h"
#include "../../../__OS/DrawingApi.h"

using namespace System;
using namespace System::Drawing;

Brush::~Brush() {
  ReleaseNativeBrush();
}

void Brush::SetNativeBrush(intptr brush) {
  ReleaseNativeBrush();
  this->brush = brush;
}

void Brush::ReleaseNativeBrush() {
  if (this->brush != IntPtr::Zero)
    __OS::DrawingApi::Brush::DeleteBrush(this->brush);
  this->brush = IntPtr::Zero;
}
