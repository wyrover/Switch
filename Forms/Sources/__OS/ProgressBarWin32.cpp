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

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  static INITCOMMONCONTROLSEX icc;
  icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  icc.dwICC = ICC_PROGRESS_CLASS;
  InitCommonControlsEx(&icc);
  int32 style = WS_VISIBLE | WS_CHILD;
  switch (progressBar.Style) {
  case ProgressBarStyle::Continuous: style |= PBS_SMOOTH; break;
  case ProgressBarStyle::Marquee: style |= PBS_MARQUEE; break;
  }
  int32 exStyle = 0;
  /* Rigth to left
  exStyle |= WS_EX_LAYOUTRTL;
  exStyle &= ~(WS_EX_RTLREADING | WS_EX_RIGHT | WS_EX_LEFTSCROLLBAR);
  */
  HWND handle = CreateWindowEx(exStyle, PROGRESS_CLASS, progressBar.Text().w_str().c_str(), style, progressBar.Bounds().Left, progressBar.Bounds().Top, progressBar.Bounds().Width, progressBar.Bounds().Height, (HWND)progressBar.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.Handle(), PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.Handle(), PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void FormsApi::ProgressBar::SetStyle(const System::Windows::Forms::ProgressBar& progressBar) {
  SetWindowLong((HWND)progressBar.Handle(), GWL_STYLE, GetWindowLong((HWND)progressBar.Handle(), GWL_STYLE) & ~(PBS_MARQUEE | PBS_SMOOTH | PBS_SMOOTHREVERSE));
  switch (progressBar.Style) {
  case ProgressBarStyle::Continuous: SetWindowLong((HWND)progressBar.Handle(), GWL_STYLE, GetWindowLong((HWND)progressBar.Handle(), GWL_STYLE) | PBS_SMOOTH); break;
  case ProgressBarStyle::Marquee: SetWindowLong((HWND)progressBar.Handle(), GWL_STYLE, GetWindowLong((HWND)progressBar.Handle(), GWL_STYLE) | PBS_MARQUEE); break;
  }
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.Handle(), PBM_SETPOS, progressBar.Value(), 0);
}

#endif
