#if defined(__APPLE__)
#include "FormsApi.hpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

namespace{
  static System::Collections::Generic::SortedDictionary<intptr, delegate<void>> ticks;
}

intptr FormsApi::Timer::Create(int32 interval, delegate<void> tick) {
  intptr handle = 0;
  ticks[handle] = tick;
  return (intptr)handle;
}

void FormsApi::Timer::Destroy(intptr handle) {
  ticks.Remove(handle);
}

#endif
