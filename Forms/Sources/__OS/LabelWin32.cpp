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
  int32 style = WS_CHILD;
  int32 exStyle = 0;
  HWND handle = CreateWindowEx(exStyle, L"Static", label.Text().w_str().c_str(), style, label.Bounds().Left, label.Bounds().Top, label.Bounds().Width, label.Bounds().Height, (HWND)label.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

#endif
