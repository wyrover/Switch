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
  int32 style = WS_CHILD | WS_TABSTOP | (checkBox.AutoCheck ? BS_AUTOCHECKBOX : BS_CHECKBOX);
  int32 exStyle = 0;
  HWND handle = CreateWindowEx(exStyle, L"Button", checkBox.Text().w_str().c_str(), style, checkBox.Bounds().Left, checkBox.Bounds().Top, checkBox.Bounds().Width, checkBox.Bounds().Height, (HWND)checkBox.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void FormsApi::CheckBox::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
  SetWindowLong((HWND)checkBox.Handle(), GWL_STYLE, GetWindowLong((HWND)checkBox.Handle(), GWL_STYLE) & ~(BS_CHECKBOX | BS_AUTOCHECKBOX));
  SetWindowLong((HWND)checkBox.Handle(), GWL_STYLE, GetWindowLong((HWND)checkBox.Handle(), GWL_STYLE) | (checkBox.AutoCheck ? BS_AUTOCHECKBOX : BS_CHECKBOX));
}

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  PostMessage((HWND)checkBox.Handle(), BM_SETCHECK, checkBox.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

#endif
