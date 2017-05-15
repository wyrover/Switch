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

intptr FormsApi::RadioButton::Create(const System::Windows::Forms::RadioButton& radioButton) {
  HWND handle = CreateWindowEx(0, WC_BUTTON, radioButton.Text().w_str().c_str(), WS_CHILD | BS_RADIOBUTTON, radioButton.Left, radioButton.Top, radioButton.Width, radioButton.Height, (HWND)radioButton.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void FormsApi::RadioButton::SetAutoCheck(const System::Windows::Forms::RadioButton& radioButton) {
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  SendMessage((HWND)radioButton.Handle(), BM_SETCHECK, radioButton.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

#endif
