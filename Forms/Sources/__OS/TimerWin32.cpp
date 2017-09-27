#if defined(_WIN32)

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "FormsApi.hpp"
#include "WindowProcedureWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

namespace{
  static System::Collections::Generic::SortedDictionary<intptr, delegate<void>> ticks;
  void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
    ticks[idEvent]();
  }
}

intptr FormsApi::Timer::Create(int32 interval, delegate<void> tick) {
  intptr handle = (intptr)SetTimer(null, 0, interval, TimerProc);
  ticks[handle] = tick;
  return (intptr)handle;
}

void FormsApi::Timer::Destroy(intptr handle) {
  ticks.Remove(handle);
  KillTimer(null, handle);
}

#endif
