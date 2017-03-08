#pragma once

#include <Pcf/Static.h>
#include <Pcf/System/Array.h>

#include "../../Includes/Pcf/System/Drawing/Color.h"
#include "../../Includes/Pcf/System/Drawing/FontFamily.h"

namespace __OS {
  class DrawingApi pcf_static {
  public:
    class Brush pcf_static {
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
    };
  };
}
