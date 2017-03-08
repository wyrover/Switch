#pragma once

#include <Pcf/Static.h>
#include <Pcf/System/Array.h>

#include "../../Includes/Pcf/System/Drawing/Brush.h"
#include "../../Includes/Pcf/System/Drawing/Color.h"
#include "../../Includes/Pcf/System/Drawing/FontFamily.h"
#include "../../Includes/Pcf/System/Drawing/Rectangle.h"

namespace __OS {
  class DrawingApi pcf_static {
  public:
    class Brush pcf_static {
    public:
      static intptr CreateSolidBrush(const System::Drawing::Color& color);
      static void DeleteBrush(intptr handle);
    };

    class FontFamily pcf_static {
    public:
      static System::Array<System::Drawing::FontFamily> GetInstalledFontFamilies();
      static System::Drawing::FontFamily GetFontFamilyFromName(const string& name);
      static string GetName(intptr handle);
      static bool IsStyleAvailable(intptr handle, System::Drawing::FontStyle style);
      static void ReleaseResource(intptr handle);
    };

    class Gdi pcf_static {
    public:
      static intptr GetDeviceContext(intptr hwd);
      static intptr BeginPaint(intptr hwd, System::Drawing::Rectangle& rectangle);
      static void EndPaint(intptr hwd, const System::Drawing::Rectangle& rectangle);
      static void FillRectangle(intptr hdc, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h);
    };
  };
}
