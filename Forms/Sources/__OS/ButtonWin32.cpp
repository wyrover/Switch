#if defined(_WIN32) && defined(__use_native_interface__)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

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
  int32 style = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON;
  int32 exStyle = 0;
  HWND handle = CreateWindowEx(exStyle, L"Button", button.Text().w_str().c_str(), style, button.Bounds().Left, button.Bounds().Top, button.Bounds().Width, button.Bounds().Height, (HWND)FormsApi::Control::GetParentHandleOrDefault(button), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

#endif
