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
  HWND handle = CreateWindowEx(WS_EX_CONTROLPARENT, WC_DIALOG, panel.Text().w_str().c_str(), WS_CHILD, panel.Left, panel.Top, panel.Width, panel.Height, (HWND)panel.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  SetWindowLongPtr((HWND)panel.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)panel.Handle(), GWL_STYLE) & ~WS_BORDER);
  SetWindowLongPtr((HWND)panel.Handle(), GWL_EXSTYLE, GetWindowLongPtr((HWND)panel.Handle(), GWL_EXSTYLE) & ~WS_EX_CLIENTEDGE);
  switch (panel.BorderStyle) {
  case BorderStyle::FixedSingle: SetWindowLongPtr((HWND)panel.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)panel.Handle(), GWL_STYLE) | WS_BORDER); break;
  case BorderStyle::Fixed3D: SetWindowLongPtr((HWND)panel.Handle(), GWL_EXSTYLE, GetWindowLongPtr((HWND)panel.Handle(), GWL_EXSTYLE) | WS_EX_CLIENTEDGE); break;
  }
  SetWindowPos((HWND)panel.Handle(), NULL, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
}

#endif
