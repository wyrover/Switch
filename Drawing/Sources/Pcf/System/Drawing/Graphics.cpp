#include "../../../../Includes/Pcf/System/Drawing/Graphics.h"
#include "../../../__OS/DrawingApi.h"

using namespace System;
using namespace System::Drawing;

Graphics::~Graphics() {
  if (!this->hwnd) {
    __OS::DrawingApi::Gdi::EndPaint(this->hwnd, this->rectangle);
  }
}

void Graphics::Clear(const Color& color) {
  this->FillRectangle(SolidBrush(color), this->rectangle);
}

void Graphics::DrawArc(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
}

void Graphics::DrawBezier(const Pen& pen, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
}

void Graphics::DrawLine(const Pen& pen, int32 x1, int32 y1, int32 x2, int32 y2) {
}

void Graphics::DrawPie(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
}

void Graphics::DrawRectangle(const Pen& pen, int32 x, int32 y, int32 w, int32 h) {
}

void Graphics::DrawString(const string& str, const Font& font, const Brush& brush, const RectangleF& layoutRectangle, const StringFormat& format) {
}

void Graphics::FillPie(const Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
}

void Graphics::FillRectangle(const Brush& brush, int32 x, int32 y, int32 w, int32 h) {
  __OS::DrawingApi::Gdi::FillRectangle(this->hdc, brush, x, y, w, h);
}

void Graphics::SetColor(const System::Drawing::Color& color) {
}

SizeF Graphics::MeasureString(const string& str, const Font& font) const {
  return SizeF();
}

Graphics Graphics::FromHwndInternal(intptr hwnd) {
  Rectangle rectangle;
  intptr hdc = __OS::DrawingApi::Gdi::BeginPaint(hwnd, rectangle);
  return Graphics(hwnd, hdc, rectangle);
}
