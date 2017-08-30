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

intptr FormsApi::RadioButton::Create(const System::Windows::Forms::RadioButton& radioButton) {
  HWND handle = CreateWindowEx(0, WC_BUTTON, radioButton.Text().w_str().c_str(), WS_CHILD | BS_RADIOBUTTON, radioButton.Left, radioButton.Top, radioButton.Width, radioButton.Height, (HWND)radioButton.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  SendMessage((HWND)radioButton.Handle(), BM_SETCHECK, radioButton.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

void FormsApi::RadioButton::SetGroup(const System::Windows::Forms::RadioButton& radioButton) {
}

#endif
