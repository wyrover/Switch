#if _WIN32
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

  inline COLORREF ColorToRgb(const Color& color) {
    return RGB(color.R, color.G, color.B);
  }
}

intptr DrawingApi::Brush::CreateSolidBrush(const Color& color) {
  return (intptr)::CreateSolidBrush(ColorToRgb(color));
}

void DrawingApi::Brush::DeleteBrush(intptr handle) {
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

#endif
