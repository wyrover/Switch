#include "Fl_WindowTransparency.h"

#ifdef __linux__

void setWindowTransparency(Fl_Window *my_fltk_window, bool is_transparent) {
  Atom atom = XInternAtom(fl_display, "_NET_WM_WINDOW_OPACITY", False);
  uint32_t opacity = is_transparent ? 0xC0000000 : 0xFFFFFFFF;
  XChangeProperty(fl_display, fl_xid(my_fltk_window), atom, XA_CARDINAL, 32, PropModeReplace, (unsigned char *)&opacity, 1);
}

#endif