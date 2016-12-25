#if __linux__
#include "DrawingApi.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace __OS;

namespace {
}

Array<System::Drawing::FontFamily> DrawingApi::FontFamily::GetInstalledFontFamilies() {
  System::Array<System::Drawing::FontFamily> families;
  return  families;
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

#endif
