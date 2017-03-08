#if __APPLE__
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/ArgumentException.h>
#include "DrawingApi.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

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
  return (intptr)null;
}

void DrawingApi::Brush::DeleteBrush(intptr handle) {
}

System::Array<System::Drawing::FontFamily> __OS::DrawingApi::FontFamily::GetInstalledFontFamilies() {
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

System::Drawing::FontFamily __OS::DrawingApi::FontFamily::GetFontFamilyFromName(const string& name) {
  if ([[NSFontManager sharedFontManager] availableMembersOfFontFamily:[NSString stringWithUTF8String:name.c_str()]] == nil)
    throw ArgumentException(pcf_current_information);
  LogFont* logFont = new LogFont();
  logFont->lfFaceName = name;
  return System::Drawing::FontFamily((intptr)logFont);
}

string __OS::DrawingApi::FontFamily::GetName(intptr handle) {
  if (handle == 0) return "";
  return ((LogFont*)handle)->lfFaceName;
}

bool __OS::DrawingApi::FontFamily::IsStyleAvailable(intptr handle, System::Drawing::FontStyle style) {
  if (handle == 0) return false;
  
  /*
   if ((style & FontStyle::Italic) == FontStyle::Italic && result->lfItalic == 0) return false;
   if ((style & FontStyle::Underline) == FontStyle::Underline && result->lfUnderline == 0) return false;
   if ((style & FontStyle::Strikeout) == FontStyle::Strikeout && result->lfStrikeOut == 0) return false;
   */
  return true;
}

void __OS::DrawingApi::FontFamily::ReleaseResource(intptr handle) {
  if (handle != 0)
    delete (LogFont*)handle;
}

#endif
