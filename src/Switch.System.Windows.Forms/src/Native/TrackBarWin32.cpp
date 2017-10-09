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

intptr FormsApi::TrackBar::Create(const System::Windows::Forms::TrackBar& trackBar) {
  static INITCOMMONCONTROLSEX icc;
  icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  icc.dwICC = ICC_PROGRESS_CLASS;
  InitCommonControlsEx(&icc);
  int32 style = WS_CHILD;
  if (trackBar.Orientation == Orientation::Horizontal) style |= TBS_HORZ;
  else style |= TBS_VERT;
  switch (trackBar.Style) {
  case TickStyle::None: style |= TBS_NOTICKS; break;
  case TickStyle::TopLeft:
    if (trackBar.Orientation == Orientation::Horizontal) style |= TBS_AUTOTICKS | TBS_TOP;
    else style |= TBS_AUTOTICKS | TBS_LEFT;
    break;
  case TickStyle::BottomRight:
    if (trackBar.Orientation == Orientation::Horizontal) style |= TBS_AUTOTICKS | TBS_BOTTOM;
    else style |= TBS_AUTOTICKS | TBS_RIGHT;
    break;
  case TickStyle::Both: style |= TBS_AUTOTICKS | TBS_BOTH; break;
  }
  HWND handle = CreateWindowEx(0, TRACKBAR_CLASS, trackBar.Text().w_str().c_str(), style, trackBar.Left, trackBar.Top, trackBar.Width, trackBar.Height, (HWND)trackBar.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void FormsApi::TrackBar::SetLargeChange(const System::Windows::Forms::TrackBar& trackBar) {
  SendMessage((HWND)trackBar.Handle(), TBM_SETPAGESIZE, 0, trackBar.LargeChange());
}

void FormsApi::TrackBar::SetMaximum(const System::Windows::Forms::TrackBar& trackBar) {
  SendMessage((HWND)trackBar.Handle(), TBM_SETRANGEMAX, 1, trackBar.Maximum());
}

void FormsApi::TrackBar::SetMinimum(const System::Windows::Forms::TrackBar& trackBar) {
  SendMessage((HWND)trackBar.Handle(), TBM_SETRANGEMIN, 1, trackBar.Minimum());
}

void FormsApi::TrackBar::SetOrientation(const System::Windows::Forms::TrackBar& trackBar) {
  // if handle created recreate handle...
}

void FormsApi::TrackBar::SetSmallChange(const System::Windows::Forms::TrackBar& trackBar) {
  SendMessage((HWND)trackBar.Handle(), TBM_SETLINESIZE, 0, trackBar.SmallChange());
}

void FormsApi::TrackBar::SetTickFrequency(const System::Windows::Forms::TrackBar& trackBar) {
  SendMessage((HWND)trackBar.Handle(), TBM_SETTICFREQ, trackBar.TickFrequency(), 0);
}

void FormsApi::TrackBar::SetTickStyle(const System::Windows::Forms::TrackBar& trackBar) {
  // if handle created recreate handle...
}

int32 FormsApi::TrackBar::GetValue(const System::Windows::Forms::TrackBar& trackBar) {
  return SendMessage((HWND)trackBar.Handle(), TBM_GETPOS, 0, 0);
}

void FormsApi::TrackBar::SetValue(const System::Windows::Forms::TrackBar& trackBar) {
  SendMessage((HWND)trackBar.Handle(), TBM_SETPOS, trackBar.Value(), 0);
}

#endif
