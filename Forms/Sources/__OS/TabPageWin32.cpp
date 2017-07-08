#if defined(_WIN32)

#include <windows.h>
#include <Uxtheme.h>
#include <Pcf/Undef.hpp>

#include "FormsApi.hpp"
#include "WindowProcedureWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

intptr FormsApi::TabPage::Create(const System::Windows::Forms::TabPage& tabPage) {
  HWND handle = CreateWindowEx(WS_EX_CONTROLPARENT, WC_DIALOG, tabPage.Text().w_str().c_str(), WS_CHILD, tabPage.Left, tabPage.Top, tabPage.Width, tabPage.Height, (HWND)tabPage.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

#endif
