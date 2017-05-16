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

intptr FormsApi::CheckBox::Create(const System::Windows::Forms::CheckBox& checkBox) {
  HWND handle = CreateWindowEx(0, WC_BUTTON, checkBox.Text().w_str().c_str(), WS_CHILD | BS_CHECKBOX, checkBox.Left, checkBox.Top, checkBox.Width, checkBox.Height, (HWND)checkBox.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void FormsApi::CheckBox::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
}

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  SendMessage((HWND)checkBox.Handle(), BM_SETCHECK, checkBox.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

#endif
