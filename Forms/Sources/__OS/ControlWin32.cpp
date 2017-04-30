#if defined(_WIN32) && defined(__use_native_interface__)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"
#include "WindowProcedureWin32.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

namespace {
  inline COLORREF ColorToRgb(const Color& color) {
	  return RGB(color.R, color.G, color.B);
  }
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
  CloseWindow((HWND)form.Handle());
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  int32 style = WS_VISIBLE | WS_CHILD;
  int32 exStyle = 0;
  HWND handle = CreateWindowEx(exStyle, L"Control", control.Text().w_str().c_str(), style, control.Bounds().Left, control.Bounds().Top, control.Bounds().Width, control.Bounds().Height, (HWND)FormsApi::Control::GetParentHandleOrDefault(control), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

void FormsApi::Control::DefWndProc(Message& message) {
  if (WindowProcedure::DefWindowProcs.ContainsKey(message.HWnd()))
    message.Result = WindowProcedure::DefWindowProcs[message.HWnd()]((HWND)message.HWnd(), message.Msg, message.WParam, message.LParam);
  else
    message.Result = DefWindowProc((HWND)message.HWnd(), message.Msg, message.WParam, message.LParam);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.Handle()) {
    intptr handle = control.Handle();
    WindowProcedure::DefWindowProcs.Remove(handle);
    DestroyWindow((HWND)handle);
  }
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return (intptr)WindowFromDC((HDC)hdc);
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {
  if (invalidateChildren)
    RedrawWindow((HWND)control.Handle(), null, null, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
  else
    InvalidateRect((HWND)control.Handle(), null, true);
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {
  RECT invalidateRect {rect.Left, rect.Top, rect.Right, rect.Bottom};
  if (invalidateChildren)
    RedrawWindow((HWND)control.Handle(), &invalidateRect, null, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
  else
    InvalidateRect((HWND)control.Handle(), &invalidateRect, true);
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  POINT location{point.X, point.Y};
  ScreenToClient((HWND)control.Handle(), &location);
  return System::Drawing::Point(location.x, location.y);
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  POINT location{point.X, point.Y};
  ClientToScreen((HWND)control.Handle(), &location);
  return System::Drawing::Point(location.x, location.y);
}

void FormsApi::Control::SetBackColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle((intptr)WindowFromDC((HDC)hdc));
  if (control != null) {
    System::Diagnostics::Debug::WriteLine("{0} = {1}", control().Name, control().BackColor);
    if (control().BackColor == Color::Transparent)
      SetBkMode((HDC)hdc, TRANSPARENT);
    else
      SetBkColor((HDC)hdc, ColorToRgb(control().BackColor));
    SetTextColor((HDC)hdc, ColorToRgb(control().ForeColor));
  }
}

void FormsApi::Control::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle((intptr)WindowFromDC((HDC)hdc));
  if (control != null) {
    if (control().BackColor == Color::Transparent)
      SetBkMode((HDC)hdc, TRANSPARENT);
    else
      SetBkColor((HDC)hdc, ColorToRgb(control().BackColor));
    SetTextColor((HDC)hdc, ColorToRgb(control().ForeColor));
  }
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  HDC hdc = GetDC((HWND)control.Handle());
  ref<System::Windows::Forms::Control> form = control;
  while (form().Parent() != null)
    form = form().Parent();
  SendMessage((HWND)form().Handle(), WM_ERASEBKGND, (WPARAM)hdc, 0);
  ReleaseDC((HWND)control.Handle(), hdc);
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  HDC hdc = GetDC((HWND)control.Handle());
  ref<System::Windows::Forms::Control> form = control;
  while (form().Parent() != null)
    form = form().Parent();
  SendMessage((HWND)form().Handle(), WM_ERASEBKGND, (WPARAM)hdc, 0);
  ReleaseDC((HWND)control.Handle(), hdc);
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  SetWindowPos((HWND)control.Handle(), NULL, control.Location().X, control.Location().Y, control.Size().Width, control.Size().Height, SWP_NOSIZE);
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
  ::SetParent((HWND)control.Handle(), (HWND)control.Parent()().Handle());
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
  SetWindowPos((HWND)control.Handle(), NULL, control.Location().X, control.Location().Y, control.Size().Width, control.Size().Height, SWP_NOMOVE);
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  SetWindowText((HWND)control.Handle(), control.Text().w_str().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  ShowWindow((HWND)control.Handle(), control.Visible ? SW_SHOW : SW_HIDE);
}

#endif
