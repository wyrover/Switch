#if defined(__linux__) && defined(__use_native_interface__)
#include "DrawingApi.h"

#include <gtkmm.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace __OS;

namespace {
}

intptr DrawingApi::Brush::CreateSolidBrush(const Color& color) {
  return IntPtr::Zero;
}

void DrawingApi::Brush::DeleteBrush(intptr handle) {
}

intptr DrawingApi::Pen::CreatePen(const System::Drawing::Drawing2D::DashStyle& dashStyle, int32 width, const Color& color) {
  return IntPtr::Zero;
}

void DrawingApi::Pen::DeletePen(intptr handle) {
}

Array<System::Drawing::FontFamily> DrawingApi::FontFamily::GetInstalledFontFamilies() {
  System::Array<System::Drawing::FontFamily> families;
  return families;
}

System::Drawing::FontFamily DrawingApi::FontFamily::GetFontFamilyFromName(const string& name) {
  throw ArgumentException(pcf_current_information);
}

string DrawingApi::FontFamily::GetName(intptr handle) {
  return "<not implemented>";
}

bool DrawingApi::FontFamily::IsStyleAvailable(intptr handle, FontStyle style) {
  if (handle == 0) return false;

  /*
  if ((style & FontStyle::Italic) == FontStyle::Italic && result->lfItalic == 0) return false;
  if ((style & FontStyle::Underline) == FontStyle::Underline && result->lfUnderline == 0) return false;
  if ((style & FontStyle::Strikeout) == FontStyle::Strikeout && result->lfStrikeOut == 0) return false;
  */
  return true;
}

void DrawingApi::FontFamily::ReleaseResource(intptr handle) {
}

intptr DrawingApi::Gdi::GetDeviceContext(intptr hwnd) {
  return hwnd;
}

/*
 intptr DrawingApi::Gdi::BeginPaint(intptr hwnd, System::Drawing::Rectangle& clipRectangle) {
 return IntPtr::Zero;
 }
 
 void DrawingApi::Gdi::EndPaint(intptr hwnd, intptr hdc) {
 }*/

void DrawingApi::Gdi::ReleaseDeviceContext(intptr hwnd, intptr hdc) {
}

System::Drawing::Rectangle DrawingApi::Gdi::GetClipRectangleFromHdc(intptr hdc) {
  return {};
}

System::Drawing::Rectangle DrawingApi::Gdi::GetClipRectangleFromHwnd(intptr hwnd) {
  return {};
}

void DrawingApi::Gdi::DrawRectangle(intptr handle, const System::Drawing::Pen& pen, int32 x, int32 y, int32 w, int32 h) {
}

void DrawingApi::Gdi::FillPie(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
}

void DrawingApi::Gdi::FillRectangle(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h) {
}

#endif
