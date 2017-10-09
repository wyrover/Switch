#if defined(_WIN32)

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "FormsApi.hpp"
#include "WindowProcedureWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace Native;

extern HINSTANCE __instance;

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  static INITCOMMONCONTROLSEX icc;
  icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  icc.dwICC = ICC_PROGRESS_CLASS;
  InitCommonControlsEx(&icc);
  int style = WS_CHILD;
  switch (progressBar.Style) {
  case ProgressBarStyle::Continuous: style |= PBS_SMOOTH; break;
  case ProgressBarStyle::Marquee: style |= PBS_MARQUEE; break;
  }
  HWND handle = CreateWindowEx(0, PROGRESS_CLASS, progressBar.Text().w_str().c_str(), style, progressBar.Left, progressBar.Top, progressBar.Width, progressBar.Height, (HWND)progressBar.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
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

void FormsApi::ProgressBar::SetMarquee(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETMARQUEE, progressBar.Style == ProgressBarStyle::Marquee ? 1 : 0, progressBar.MarqueeAnimationSpeed);
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETPOS, progressBar.Value(), 0);
}

#endif
