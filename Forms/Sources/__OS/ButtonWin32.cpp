#if defined(_WIN32) && defined(__use_native_interface__)

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

intptr FormsApi::Button::Create(const System::Windows::Forms::Button& button) {
  HWND handle = CreateWindowEx(0, WC_BUTTON, button.Text().w_str().c_str(), WS_CHILD | BS_PUSHBUTTON, button.Left, button.Top, button.Width, button.Height, (HWND)button.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void FormsApi::Button::SetIsDefault(const System::Windows::Forms::Button& button) {
  SetWindowLong((HWND)button.Handle(), GWL_STYLE, GetWindowLong((HWND)button.Handle(), GWL_STYLE) | (button.IsDefault ? BS_DEFPUSHBUTTON : BS_PUSHBUTTON));
  SetWindowLong((HWND)button.Handle(), GWL_STYLE, GetWindowLong((HWND)button.Handle(), GWL_STYLE) & (button.IsDefault ? ~BS_PUSHBUTTON : ~BS_DEFPUSHBUTTON));
}

#endif
