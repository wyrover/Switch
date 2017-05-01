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
  int32 style = WS_TABSTOP | WS_VISIBLE | WS_CHILD;
  if (radioButton.AutoCheck)
    style |= BS_AUTORADIOBUTTON;
  else
    style |= BS_RADIOBUTTON;
  int32 exStyle = 0;
  HWND handle = CreateWindowEx(exStyle, L"Button", radioButton.Text().w_str().c_str(), style, radioButton.Bounds().Left, radioButton.Bounds().Top, radioButton.Bounds().Width, radioButton.Bounds().Height, (HWND)FormsApi::Control::GetParentHandleOrDefault(radioButton), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void FormsApi::RadioButton::SetAutoCheck(const System::Windows::Forms::RadioButton& radioButton) {
  SetWindowLong((HWND)radioButton.Handle(), GWL_STYLE, GetWindowLong((HWND)radioButton.Handle(), GWL_STYLE) & ~BS_RADIOBUTTON);
  SetWindowLong((HWND)radioButton.Handle(), GWL_STYLE, GetWindowLong((HWND)radioButton.Handle(), GWL_STYLE) & ~BS_AUTORADIOBUTTON);
  if (radioButton.AutoCheck)
    SetWindowLong((HWND)radioButton.Handle(), GWL_STYLE, GetWindowLong((HWND)radioButton.Handle(), GWL_STYLE) | BS_AUTORADIOBUTTON);
  else
    SetWindowLong((HWND)radioButton.Handle(), GWL_STYLE, GetWindowLong((HWND)radioButton.Handle(), GWL_STYLE) | BS_RADIOBUTTON);
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  PostMessage((HWND)radioButton.Handle(), BM_SETCHECK, radioButton.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

#endif
