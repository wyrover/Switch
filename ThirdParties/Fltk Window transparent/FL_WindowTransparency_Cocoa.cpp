#include "Fl_WindowTransparency.h"
#include "my-cocoa-wrappers.h"

#ifdef __APPLE__

void setWindowTransparency(Fl_Window *my_fltk_window, bool is_transparent) {
  Cocoa_setWindowTransparency(my_fltk_window, is_transparent ? 0.75 : 1.0);
}

#endif