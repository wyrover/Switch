#import <Cocoa/Cocoa.h>

#include "my-cocoa-wrappers.h"

#ifdef __APPLE__
void Cocoa_setWindowTransparency(Fl_Window *w, double alpha) {
  [fl_xid(w) setAlphaValue:alpha];
}
#endif