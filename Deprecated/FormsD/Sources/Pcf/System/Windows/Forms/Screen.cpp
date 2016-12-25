#include <FL/Fltk.h>
#include "../../../../../Includes/Pcf/System/Windows/Forms/Screen.h"

using namespace System;
using namespace System::Windows::FormsD;

Property<System::Array<System::Windows::FormsD::Screen>, ReadOnly> System::Windows::FormsD::Screen::AllScreens {
  [] {return __AllScreens__();}
};

System::Array<System::Windows::FormsD::Screen> System::Windows::FormsD::Screen::__AllScreens__() {
  System::Array<System::Windows::FormsD::Screen> screens(Fl::screen_count());

  for(int32 i = 0; i < screens.Length(); i++) {
    screens[i].bitsPerPixel = 32;
    int32 x = 0, y = 0, width = 0, height = 0;
    Fl::screen_xywh(x, y, width, height, i);
    screens[i].bounds = System::Drawing::Rectangle(x, y, width, height);
    screens[i].deviceName = string::Format("\\\\.\\DISPLAY{0}", i + 1);
    screens[i].primary = i == 0;
    Fl::screen_work_area(x, y, width, height, i);
    screens[i].workingArea = System::Drawing::Rectangle(x, y, width, height);
  }

  return screens;
}

