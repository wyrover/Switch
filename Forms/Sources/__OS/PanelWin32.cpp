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
  int32 style = WS_CHILD | (panel.BorderStyle == BorderStyle::FixedSingle ? WS_BORDER : 0) | (panel.HScroll ? WS_HSCROLL : 0) | (panel.VScroll ? WS_VSCROLL : 0);
  int32 exStyle = WS_EX_CONTROLPARENT | (panel.BorderStyle == BorderStyle::Fixed3D ? WS_EX_CLIENTEDGE : 0);
  HWND handle = CreateWindowEx(exStyle, WC_DIALOG, panel.Text().w_str().c_str(), style, panel.Bounds().Left, panel.Bounds().Top, panel.Bounds().Width, panel.Bounds().Height, (HWND)panel.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
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
