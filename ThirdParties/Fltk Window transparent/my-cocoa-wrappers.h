#ifndef MY_COCOA_WRAPPERS_H
#define MY_COCOA_WRAPPERS_H

#include <FL/x.H>
#include <FL/Fl_Window.H>

#if __APPLE__
void Cocoa_setWindowTransparency(Fl_Window *w, double alpha);
#endif

#endif