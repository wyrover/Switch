#if defined(_WIN32) && defined(__use_native_interface__)

#include <Windows.h>
#include <Uxtheme.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"
#include "WindowProcedureWin32.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

intptr FormsApi::Panel::Create(const System::Windows::Forms::Panel& panel) {
  int32 style = WS_VISIBLE | WS_CHILD;
  if (panel.BorderStyle == BorderStyle::FixedSingle)
    style |= WS_BORDER;
  if (panel.HScroll)
    style |= WS_HSCROLL;
  if (panel.VScroll)
    style |= WS_VSCROLL;
  int32 exStyle = WS_EX_CONTROLPARENT;
  if (panel.BorderStyle == BorderStyle::Fixed3D)
    exStyle |= WS_EX_CLIENTEDGE;

  HWND handle = CreateWindowEx(exStyle, WC_DIALOG, panel.Text().w_str().c_str(), style, panel.Bounds().Left, panel.Bounds().Top, panel.Bounds().Width, panel.Bounds().Height, (HWND)FormsApi::Control::GetParentHandleOrDefault(panel), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  SetWindowLong((HWND)panel.Handle(), GWL_STYLE, GetWindowLong((HWND)panel.Handle(), GWL_STYLE) & ~WS_BORDER);
  SetWindowLong((HWND)panel.Handle(), GWL_EXSTYLE, GetWindowLong((HWND)panel.Handle(), GWL_EXSTYLE) & ~WS_EX_CLIENTEDGE);
  switch (panel.BorderStyle) {
  case BorderStyle::FixedSingle: SetWindowLong((HWND)panel.Handle(), GWL_STYLE, GetWindowLong((HWND)panel.Handle(), GWL_STYLE) | WS_BORDER); break;
  case BorderStyle::Fixed3D: SetWindowLong((HWND)panel.Handle(), GWL_EXSTYLE, GetWindowLong((HWND)panel.Handle(), GWL_EXSTYLE) | WS_EX_CLIENTEDGE); break;
  }
}

#endif
