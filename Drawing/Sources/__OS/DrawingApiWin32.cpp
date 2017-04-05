#ifdef _WIN32
#include <Windows.h>

#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/ArgumentException.h>
#include "DrawingApi.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace __OS;

namespace {
  LOGFONT CreateLOGFONTWithNameAndCharSet(const string& name, int32 charSet) {
    LOGFONT logFont;
    logFont.lfCharSet = charSet;
    wcscpy(logFont.lfFaceName, name.w_str().c_str());
    logFont.lfPitchAndFamily = 0;
    return logFont;
  }

  int CALLBACK EnumFamilyCallback(CONST LOGFONTW* logFont, CONST TEXTMETRICW* textMetric, DWORD fontType, LPARAM logFonts) {
    if ((fontType & TRUETYPE_FONTTYPE) == TRUETYPE_FONTTYPE && logFont->lfFaceName[0] != '@')
      (*(SortedDictionary<string, LOGFONTW*>*)logFonts)[string(logFont->lfFaceName).ToLower()] = new LOGFONT(*logFont);
    return 1;
  }

  int CALLBACK EnumFamilyFromNameCallback(CONST LOGFONTW* logFont, CONST TEXTMETRICW* textMetric, DWORD fontType, LPARAM result) {
    if ((fontType & TRUETYPE_FONTTYPE) == TRUETYPE_FONTTYPE && logFont->lfFaceName[0] != '@' && (*(LOGFONTW**)result) == null)
      (*(LOGFONTW**)result) = new LOGFONT(*logFont);
    return 1;
  }

  inline COLORREF FromColor(const Color& color) {
    return RGB(color.R, color.G, color.B);
  }

  inline Color ToColor(COLORREF color) {
    return Color::FromArgb(255, GetRValue(color), GetGValue(color), GetBValue(color));
  }

  inline RECT FromRectangle(const System::Drawing::Rectangle& rectangle) {
    return { rectangle.Left, rectangle.Top, rectangle.Right, rectangle.Bottom};
  }

  inline System::Drawing::Rectangle ToRectangle(const RECT& rectangle) {
    return { rectangle.left, rectangle.top, rectangle.right - rectangle.left, rectangle.bottom - rectangle.top };
  }
}

intptr DrawingApi::Brush::CreateSolidBrush(const Color& color) {
  return (intptr)::CreateSolidBrush(FromColor(color));
}

void DrawingApi::Brush::DeleteBrush(intptr handle) {
  DeleteObject((HGDIOBJ)handle);
}

intptr DrawingApi::Pen::CreatePen(const System::Drawing::Drawing2D::DashStyle& dashStyle, int32 width, const Color& color) {
  return (intptr)::CreatePen((int32)dashStyle, width, FromColor(color));
}

void DrawingApi::Pen::DeletePen(intptr handle) {
  DeleteObject((HGDIOBJ)handle);
}

Array<System::Drawing::FontFamily> DrawingApi::FontFamily::GetInstalledFontFamilies() {
  HDC hdc = GetDC(NULL);
  LOGFONT logFont = CreateLOGFONTWithNameAndCharSet("", DEFAULT_CHARSET);
  SortedDictionary<string, LOGFONTW*> logFonts;
  EnumFontFamiliesEx(hdc, &logFont, EnumFamilyCallback, (LPARAM)&logFonts, 0);
  ReleaseDC(NULL, hdc);
  System::Array<System::Drawing::FontFamily> families(logFonts.Count);
  int32 index = 0;
  for (auto item : logFonts)
    families[index++] = System::Drawing::FontFamily((intptr)item.Value());
  return  families;
}

System::Drawing::FontFamily DrawingApi::FontFamily::GetFontFamilyFromName(const string& name) {
  HDC hdc = GetDC(NULL);
  LOGFONT logFont = CreateLOGFONTWithNameAndCharSet(name, DEFAULT_CHARSET);
  LOGFONTW* result = null;
  EnumFontFamiliesEx(hdc, &logFont, EnumFamilyFromNameCallback, (LPARAM)&result, 0);
  ReleaseDC(NULL, hdc);
  if (result != null)
    return System::Drawing::FontFamily((intptr)result);
  throw ArgumentException(pcf_current_information);
}

string DrawingApi::FontFamily::GetName(intptr handle) {
  if (handle == 0) return "";
  return ((LOGFONT*)handle)->lfFaceName;
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
  if (handle != 0)
    delete (LOGFONT*)handle;
}

intptr DrawingApi::Gdi::GetDeviceContext(intptr hwnd) {
  return (intptr)GetDC((HWND)hwnd);
}

/*
intptr DrawingApi::Gdi::BeginPaint(intptr hwnd, System::Drawing::Rectangle& clipRectangle) {
  PAINTSTRUCT paintStruct;
  intptr hdc = (intptr)::BeginPaint((HWND)hwnd, &paintStruct);
  clipRectangle = ToRectangle(paintStruct.rcPaint);
  return hdc;
}

void DrawingApi::Gdi::EndPaint(intptr hwnd, intptr hdc) {
  PAINTSTRUCT paintStruct;
  paintStruct.hdc = (HDC)hdc;
  GetClientRect((HWND)hwnd, &paintStruct.rcPaint);
  ::EndPaint((HWND)hwnd, &paintStruct);
}*/

void DrawingApi::Gdi::ReleaseDeviceContext(intptr hwnd, intptr hdc) {
  ReleaseDC((HWND)hwnd, (HDC)hdc);
}

System::Drawing::Rectangle DrawingApi::Gdi::GetClipRectangleFromHdc(intptr hdc) {
  RECT clipRectangle;
  GetClientRect((HWND)WindowFromDC((HDC)hdc), &clipRectangle);
  return ToRectangle(clipRectangle);
}

System::Drawing::Rectangle DrawingApi::Gdi::GetClipRectangleFromHwnd(intptr hwnd) {
  RECT clipRectangle;
  GetClientRect((HWND)hwnd, &clipRectangle);
  return ToRectangle(clipRectangle);
}

void DrawingApi::Gdi::DrawRectangle(intptr handle, const System::Drawing::Pen& pen, int32 x, int32 y, int32 w, int32 h) {
  RECT rect { x, y, x+w, y+h };
  HGDIOBJ oldBrush = SelectObject((HDC)handle, GetStockObject(NULL_BRUSH));
  HGDIOBJ oldPen = SelectObject((HDC)handle, (HGDIOBJ)pen.GetNativePen());
  ::Rectangle((HDC)handle, x, y, x + w, y + h);
  SelectObject((HDC)handle, oldBrush);
  SelectObject((HDC)handle, oldPen);
}


void DrawingApi::Gdi::FillPie(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
  RECT rect { x, y, x+w, y+h };
  Pie((HDC)handle, x,y, w, h, startAngle,sweepAngle, startAngle,sweepAngle);
}

void DrawingApi::Gdi::FillRectangle(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h) {
  RECT rect { x, y, x+w, y+h };
  FillRect((HDC)handle, &rect, (HBRUSH)brush.GetNativeBrush());
}

#endif
