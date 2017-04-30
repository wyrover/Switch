#if defined(_WIN32) && defined(__use_native_interface__)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"
#include "WindowProcedureWin32.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

intptr FormsApi::Form::Create(const System::Windows::Forms::Form& form) {
  int32 style = WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_GROUP;
  if (form.HScroll)
    style |= WS_HSCROLL;
  if (form.VScroll)
    style |= WS_VSCROLL;
  int32 exStyle = 0;
  System::Drawing::Rectangle bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT);
  switch (form.StartPosition) {
  case FormStartPosition::Manual: bounds = form.Bounds; break;
  case FormStartPosition::WindowsDefaultBounds: bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT); break;
  case FormStartPosition::WindowsDefaultLocation: bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, form.Width, form.Height); break;
  }
  HWND handle = CreateWindowEx(exStyle, WC_DIALOG, form.Text().w_str().c_str(), style, bounds.Left, bounds.Top, bounds.Width, bounds.Height, NULL, (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

#endif
