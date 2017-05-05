#include "../../../../../Includes/Pcf/System/Windows/Forms/Timer.h"

using namespace System;
using namespace System::Windows::Forms;

void Timer::SetEnabled(bool enabled) {
  this->enabled = enabled;
  
  if (this->enabled == true) {
  } else if (Fl::has_timeout(&Timer::TimerTick, this) != 0) {
  }
}

void Timer::SetInterval(int32 interval) {
  if (interval < 1)
    throw ArgumentOutOfRangeException(pcf_current_information);
  this->interval = interval;
}

void Timer::TimerTick(void* timer) {
  reinterpret_cast<Timer*>(timer)->Tick(*reinterpret_cast<Timer*>(timer), System::EventArgs());
  if (reinterpret_cast<Timer*>(timer)->enabled == true)
    Fl::repeat_timeout((double)reinterpret_cast<Timer*>(timer)->interval / 1000, &Timer::TimerTick, timer);
}
