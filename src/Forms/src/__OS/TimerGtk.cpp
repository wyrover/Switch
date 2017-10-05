#if defined(__linux__)
#include <gtkmm.h>

#include "FormsApi.hpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

namespace{
  struct TimerGtk {
    guint timer = 0;
    delegate<void> tick;
  };

  int TimerPeroc(gpointer timer) {
    ((TimerGtk*)timer)->tick();
    return 1;
  }
}

intptr FormsApi::Timer::Create(int32 interval, delegate<void> tick) {
  TimerGtk* handle = new TimerGtk();
  handle->timer = g_timeout_add(interval, TimerPeroc, (gpointer)handle);
  handle->tick = tick;
  return (intptr)handle;
}

void FormsApi::Timer::Destroy(intptr handle) {
  g_source_remove(((TimerGtk*)handle)->timer);
}

#endif
