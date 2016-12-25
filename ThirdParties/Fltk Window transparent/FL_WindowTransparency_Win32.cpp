#include "Fl_WindowTransparency.h"

#ifdef WIN32

void setWindowTransparency(Fl_Window *my_fltk_window, bool is_transparent) {
  HWND hwnd = fl_xid(my_fltk_window);
  LONG_PTR exstyle = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
  if (!(exstyle & WS_EX_LAYERED)) {
    SetWindowLongPtr(hwnd, GWL_EXSTYLE, exstyle | WS_EX_LAYERED);
  }
  SetLayeredWindowAttributes(hwnd, 0, is_transparent ? 192 : 255, LWA_ALPHA);
}

#endif