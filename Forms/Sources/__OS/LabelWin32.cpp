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

intptr FormsApi::Label::Create(const System::Windows::Forms::Label& label) {
  HWND handle = CreateWindowEx(0, WC_STATIC, label.Text().w_str().c_str(), WS_CHILD, label.Left, label.Top, label.Width, label.Height, (HWND)label.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

#endif
