#include "../../../../Includes/Switch/System/Drawing/SolidBrush.hpp"
#include "../../../__OS/DrawingApi.hpp"

using namespace System;
using namespace System::Drawing;

SolidBrush::SolidBrush(const System::Drawing::Color& color) : color(color) {
  this->SetNativeBrush(__OS::DrawingApi::Brush::CreateSolidBrush(this->color));
}

SolidBrush& SolidBrush::operator=(const SolidBrush& brush) {
  this->color = brush.color;
  this->SetNativeBrush(__OS::DrawingApi::Brush::CreateSolidBrush(this->color));
  return *this;
}
