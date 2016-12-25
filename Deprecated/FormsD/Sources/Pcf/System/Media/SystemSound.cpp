#include <FL/Fltk.h>
#include "../../../../Includes/Pcf/System/Media/SystemSound.h"

using namespace System::Media;

#ifdef __APPLE__
extern "C" void NSBeep(void);
#endif

void SystemSound::Play() const {
#ifdef _WIN32
  switch (this->handle) {
    case asterisk : MessageBeep(MB_ICONASTERISK); break;
    case beep : MessageBeep(0xFFFFFFFF); break;
    case exclamation : MessageBeep(MB_ICONEXCLAMATION); break;
    case hand : MessageBeep(MB_ICONHAND); break;
    case question : MessageBeep(MB_ICONQUESTION); break;
    default : MessageBeep(0xFFFFFFFF); break;
  }
#elif __APPLE__
  switch (this->handle) {
    case asterisk : NSBeep(); break;
    case beep : NSBeep(); break;
    case exclamation : NSBeep(); break;
    case hand : NSBeep(); break;
    case question : NSBeep(); break;
    default : NSBeep(); break;
  }
#else
  if (!fl_display)
    fl_open_display();
  
  switch (this->handle) {
    case asterisk : XBell(fl_display, 100); break;
    case beep : XBell(fl_display, 50); break;
    case exclamation : XBell(fl_display, 100); break;
    case hand : XBell(fl_display, 100); break;
    case question : XBell(fl_display, 100); break;
    default : XBell(fl_display, 50); break;
  }
#endif // WIN32
}