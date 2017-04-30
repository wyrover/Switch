#if defined(_WIN32) && defined(__use_native_interface__)

#include "FormsApi.h"
#include "WindowProcedureWin32.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace __OS;

LRESULT CALLBACK WindowProcedure::WndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam) {
  Message message = Message::Create((intptr)hwnd, msg, wParam, lParam, 0);
  ref<Control> control = Control::FromHandle(message.HWnd);
  if (control != null)
    control().WndProc(message);
  return message.Result;
}

SortedDictionary<intptr, WNDPROC> WindowProcedure::DefWindowProcs;

#endif
