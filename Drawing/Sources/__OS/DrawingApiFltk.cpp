#if !defined(__use_native_interface__)
#include "DrawingApi.h"

#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace __OS;

namespace {
  static System::Collections::Generic::SortedDictionary<System::Drawing::Drawing2D::DashStyle, int32> dashStyle = {{System::Drawing::Drawing2D::DashStyle::Custom, FL_SOLID}, {System::Drawing::Drawing2D::DashStyle::Dash, FL_DASH}, {System::Drawing::Drawing2D::DashStyle::DashDot, FL_DASHDOT}, {System::Drawing::Drawing2D::DashStyle::DashDotDot, FL_DASHDOTDOT}, {System::Drawing::Drawing2D::DashStyle::Dot, FL_DOT}, {System::Drawing::Drawing2D::DashStyle::Solid, FL_SOLID}};
  
  static Fl_Color FromColor(const System::Drawing::Color& color) {
    return fl_rgb_color(static_cast<byte>(color.R()), static_cast<byte>(color.G()), static_cast<byte>(color.B()));
  }
}

namespace __OS {
  class IWidget pcf_interface {
  public:
    virtual const Fl_Widget& ToWidget() const = 0;
    virtual Fl_Widget& ToWidget() = 0;
  };
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
  return System::Drawing::Rectangle(0, 0, ((IWidget*)hdc)->ToWidget().w(), ((IWidget*)hdc)->ToWidget().h());
}

System::Drawing::Rectangle DrawingApi::Gdi::GetClipRectangleFromHwnd(intptr hwnd) {
  return System::Drawing::Rectangle(0, 0, ((IWidget*)hwnd)->ToWidget().w(), ((IWidget*)hwnd)->ToWidget().h());
}

void DrawingApi::Gdi::DrawRectangle(intptr handle, const System::Drawing::Pen& pen, int32 x, int32 y, int32 w, int32 h) {
  fl_color(FromColor(pen.Color));
  fl_line_style(dashStyle[pen.DashStyle()], pen.Width());
  fl_rect(x, y, w, h);
  fl_color(((IWidget*)handle)->ToWidget().color());
  fl_line_style(dashStyle[System::Drawing::Drawing2D::DashStyle::Solid], 1);
}

void DrawingApi::Gdi::FillPie(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
}

void DrawingApi::Gdi::FillRectangle(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h) {
}

#endif
