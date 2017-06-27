#if defined(_WIN32)

#include <windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Pcf/Undef.hpp>

#include "FormsApi.hpp"
#include "WindowProcedureWin32.hpp"

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

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  HWND handle = CreateWindowEx(0, WC_DIALOG, control.Text().w_str().c_str(), WS_CHILD, control.Left, control.Top, control.Width, control.Height, (HWND)control.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void FormsApi::Control::DefWndProc(Message& message) {
    message.Result = WindowProcedure::DefWindowProcs[message.HWnd()]((HWND)message.HWnd(), message.Msg, message.WParam, message.LParam);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.Handle()) {
    intptr handle = control.Handle();
    DestroyWindow((HWND)handle);
    WindowProcedure::DefWindowProcs.Remove(handle);
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
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  if (control != null) {
    SetBkMode((HDC)hdc, TRANSPARENT);
    SetBkColor((HDC)hdc, ColorToRgb(control().BackColor));
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

void FormsApi::Control::SetClientSize(System::Windows::Forms::Control& control) {
  RECT rect = { 0, 0, control.ClientSize().Width, control.ClientSize().Height };
  AdjustWindowRectEx(&rect, GetWindowLong((HWND)control.Handle(), GWL_STYLE), false /*menu == null*/, GetWindowLong((HWND)control.Handle(), GWL_EXSTYLE));
  control.Size = System::Drawing::Size(rect.right - rect.left, rect.bottom - rect.top);
}

void FormsApi::Control::SetEnabled(const System::Windows::Forms::Control& control) {
  ::EnableWindow((HWND)control.Handle(), control.Enabled);
}

bool FormsApi::Control::SetFocus(const System::Windows::Forms::Control& control) {
  return ::SetFocus((HWND)control.Handle()) != NULL;
}

void FormsApi::Control::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  if (control != null)
    SetTextColor((HDC)hdc, ColorToRgb(control().ForeColor));
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  SetForeColor((intptr)GetDC((HWND)control.Handle()));
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  SetWindowPos((HWND)control.Handle(), NULL, control.Left, control.Top, control.Width, control.Height, SWP_NOSIZE);
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
  ::SetParent((HWND)control.Handle(), control.Parent() != null ? (HWND)control.Parent()().Handle() : (HWND)0);
}

void FormsApi::Control::SetSize(System::Windows::Forms::Control& control) {
  SetWindowPos((HWND)control.Handle(), NULL, 0, 0, control.Width, control.Height, SWP_NOMOVE);
  RECT rect{ 0, 0, 0, 0 };
  GetClientRect((HWND)control.Handle(), &rect);
  control.ClientSize = System::Drawing::Size(rect.right - rect.left, rect.bottom - rect.top);
}

void FormsApi::Control::SetTabStop(const System::Windows::Forms::Control& control) {
  if (control.TabStop)
    SetWindowLongPtr((HWND)control.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)control.Handle(), GWL_STYLE) | WS_BORDER);
  else
    SetWindowLongPtr((HWND)control.Handle(), GWL_STYLE, GetWindowLongPtr((HWND)control.Handle(), GWL_STYLE) & ~WS_BORDER);
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  SendMessage((HWND)control.Handle(), WM_SETTEXT, 0, (LPARAM)control.Text().w_str().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  ShowWindow((HWND)control.Handle(), control.Visible ? SW_SHOW : SW_HIDE);
}

#endif
