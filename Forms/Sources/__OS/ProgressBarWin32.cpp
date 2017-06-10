#if defined(_WIN32) && defined(__use_native_interface__)

#include <windows.h>
#include <Uxtheme.h>
#include <Pcf/Undef.hpp>

#include "FormsApi.hpp"
#include "WindowProcedureWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  static INITCOMMONCONTROLSEX icc;
  icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  icc.dwICC = ICC_PROGRESS_CLASS;
  InitCommonControlsEx(&icc);
  HWND handle = CreateWindowEx(0, PROGRESS_CLASS, progressBar.Text().w_str().c_str(), WS_CHILD, progressBar.Left, progressBar.Top, progressBar.Width, progressBar.Height, (HWND)progressBar.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void FormsApi::ProgressBar::SetStyle(const System::Windows::Forms::ProgressBar& progressBar) {
  SetWindowLong((HWND)progressBar.Handle(), GWL_STYLE, GetWindowLong((HWND)progressBar.Handle(), GWL_STYLE) & ~(PBS_MARQUEE | PBS_SMOOTH | PBS_SMOOTHREVERSE));
  switch (progressBar.Style) {
  case ProgressBarStyle::Continuous: SetWindowLong((HWND)progressBar.Handle(), GWL_STYLE, GetWindowLong((HWND)progressBar.Handle(), GWL_STYLE) | PBS_SMOOTH); break;
  case ProgressBarStyle::Marquee: SetWindowLong((HWND)progressBar.Handle(), GWL_STYLE, GetWindowLong((HWND)progressBar.Handle(), GWL_STYLE) | PBS_MARQUEE); break;
  }
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETPOS, progressBar.Value(), 0);
}

#endif
