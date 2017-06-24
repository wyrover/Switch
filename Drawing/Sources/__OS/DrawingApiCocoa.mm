#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include <Pcf/System/Diagnostics/Debug.hpp>
#include <Pcf/System/ArgumentException.hpp>
#include "DrawingApi.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace __OS;

namespace {
  struct LogFont : public object {
    int32 lfHeight;
    int32 lfWidth;
    int32 lfEscapement;
    int32 lfOrientation;
    int32 lfWeight;
    byte lfItalic;
    byte lfUnderline;
    byte lfStrikeOut;
    byte lfCharSet;
    byte lfOutPrecision;
    byte lfClipPrecision;
    byte lfQuality;
    byte lfPitchAndFamily;
    string lfFaceName;
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

System::Array<System::Drawing::FontFamily> DrawingApi::FontFamily::GetInstalledFontFamilies() {
  NSArray* fonts = [[[NSFontManager sharedFontManager] availableFontFamilies] sortedArrayUsingSelector:@selector(localizedCaseInsensitiveCompare:)];
  List<System::Drawing::FontFamily> families;
  for (NSString *item in fonts) {
    //NSFont* font = [[NSFontManager sharedFontManager] fontWithFamily:item traits:NSItalicFontMask|NSBoldFontMask weight:0 size:12];
    LogFont* logFont = new LogFont();
    logFont->lfFaceName = [item UTF8String];
    families.Add(System::Drawing::FontFamily((intptr)logFont));
  }
  return families.ToArray();
}

System::Drawing::FontFamily DrawingApi::FontFamily::GetFontFamilyFromName(const string& name) {
  if ([[NSFontManager sharedFontManager] availableMembersOfFontFamily:[NSString stringWithUTF8String:name.c_str()]] == nil)
    throw ArgumentException(pcf_current_information);
  LogFont* logFont = new LogFont();
  logFont->lfFaceName = name;
  return System::Drawing::FontFamily((intptr)logFont);
}

string DrawingApi::FontFamily::GetName(intptr handle) {
  if (handle == 0) return "";
  return ((LogFont*)handle)->lfFaceName;
}

bool DrawingApi::FontFamily::IsStyleAvailable(intptr handle, System::Drawing::FontStyle style) {
  if (handle == 0) return false;
  
  /*
   if ((style & FontStyle::Italic) == FontStyle::Italic && result->lfItalic == 0) return false;
   if ((style & FontStyle::Underline) == FontStyle::Underline && result->lfUnderline == 0) return false;
   if ((style & FontStyle::Strikeout) == FontStyle::Strikeout && result->lfStrikeOut == 0) return false;
   */
  return true;
}

void DrawingApi::FontFamily::ReleaseResource(intptr handle) {
  if (handle != 0)
    delete (LogFont*)handle;
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
