#if defined(_WIN32) && defined(__use_native_interface__)

#include <Windows.h>
#include <Uxtheme.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  if (panel.BorderStyle == BorderStyle::FixedSingle)
    SetWindowLong((HWND)panel.Handle(), GWL_STYLE, GetWindowLong((HWND)panel.Handle(), GWL_STYLE) | WS_BORDER);
  else {
    SetWindowLong((HWND)panel.Handle(), GWL_STYLE, GetWindowLong((HWND)panel.Handle(), GWL_STYLE) & ~WS_BORDER);
    if (panel.BorderStyle == BorderStyle::Fixed3D)
      SetWindowLong((HWND)panel.Handle(), GWL_EXSTYLE, GetWindowLong((HWND)panel.Handle(), GWL_EXSTYLE) | WS_EX_CLIENTEDGE);
  }
}

#endif
