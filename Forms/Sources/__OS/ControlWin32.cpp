#if defined(_WIN32) && defined(__use_native_interface__)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"
#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/System/NotImplementedException.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

namespace __OS {
  class WindowProcedure {
  public:
    static System::Collections::Generic::Dictionary<intptr, WNDPROC> DefWindowProcs;
    static LRESULT CALLBACK WndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam);
  };
}

LRESULT CALLBACK WindowProcedure::WndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam) {
  Message message = Message::Create((intptr)hwnd, msg, wParam, lParam, 0);
  ref<Control> control = Control::FromHandle(message.HWnd);
  if (control != null)
    control().WndProc(message);
  return message.Result;
}

Dictionary<intptr, WNDPROC> WindowProcedure::DefWindowProcs;

namespace {
  inline COLORREF ColorToRgb(const Color& color) {
	  return RGB(color.R, color.G, color.B);
  }

  intptr CreateControl(const Control& control, const string& name, int32 windowStyle, HWND parent) {
    Drawing::Rectangle bounds = control.Bounds;
    HWND handle = CreateWindowEx(0, name == "Form" || name == "Panel" ? WC_DIALOG : name.w_str().c_str(), control.Text().w_str().c_str(), windowStyle, bounds.Left, bounds.Top, bounds.Width, bounds.Height, parent, (HMENU)0, __instance, (LPVOID)NULL);
    if (handle == 0) {
      string str = string::Format("FormApi::Create(\"{0}\") failed with code {1}", name, GetLastError());
      System::Diagnostics::Debug::WriteLine(str);
      throw InvalidOperationException(str, pcf_current_information);
    }

    WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
    return (intptr)handle;
  }
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
  CloseWindow((HWND)form.Handle());
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& control) {
  static Form emptyForm;
  return CreateControl(control, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, (control.Parent != null && control.Parent()().IsHandleCreated) ? (HWND)control.Parent()().Handle() : (HWND)emptyForm.Handle());
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& control) {
  static Form emptyForm;
  return CreateControl(control, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, (control.Parent != null && control.Parent()().IsHandleCreated) ? (HWND)control.Parent()().Handle() : (HWND)emptyForm.Handle());
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  static Form emptyForm;
  return CreateControl(control, L"Control", WS_VISIBLE | WS_CHILD, (control.Parent != null && control.Parent()().IsHandleCreated) ? (HWND)control.Parent()().Handle() : (HWND)emptyForm.Handle());
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& control) {
  int32 style = WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_GROUP;
  int32 exStyle = 0;
  Drawing::Rectangle bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT);
  switch (control.StartPosition) {
  case FormStartPosition::Manual: bounds = control.Bounds; break;
  case FormStartPosition::WindowsDefaultBounds: bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT); break;
  case FormStartPosition::WindowsDefaultLocation: bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, control.Width, control.Height); break;
  }
  HWND handle = CreateWindowEx(exStyle, WC_DIALOG, control.Text().w_str().c_str(), style, bounds.Left, bounds.Top, bounds.Width, bounds.Height, NULL, (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& control) {
  static Form emptyForm;
  return CreateControl(control, L"Static", WS_VISIBLE | WS_CHILD, (control.Parent != null && control.Parent()().IsHandleCreated) ? (HWND)control.Parent()().Handle() : (HWND)emptyForm.Handle());
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Panel& control) {
  int32 style = WS_VISIBLE | WS_CHILD;
  if (control.BorderStyle == BorderStyle::FixedSingle)
    style |= WS_BORDER;
  if (control.HScroll)
    style |= WS_HSCROLL;
  if (control.VScroll)
    style |= WS_VSCROLL;
  int32 exStyle = WS_EX_CONTROLPARENT;
  if (control.BorderStyle == BorderStyle::Fixed3D)
    exStyle |= WS_EX_CLIENTEDGE;

  HWND handle = CreateWindowEx(exStyle, WC_DIALOG, control.Text().w_str().c_str(), style, control.Bounds().Left, control.Bounds().Top, control.Bounds().Width, control.Bounds().Height, (HWND)FormsApi::Control::GetParentHandleOrDefault(control), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::ProgressBar& control) {
  static INITCOMMONCONTROLSEX icc;
  icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  icc.dwICC = ICC_PROGRESS_CLASS;
  InitCommonControlsEx(&icc);
  static Form emptyForm;
  return CreateControl(control, PROGRESS_CLASS, WS_VISIBLE | WS_CHILD | PBS_SMOOTH, (control.Parent != null && control.Parent()().IsHandleCreated) ? (HWND)control.Parent()().Handle() : (HWND)emptyForm.Handle());
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& control) {
  static Form emptyForm;
  return CreateControl(control, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, (control.Parent != null && control.Parent()().IsHandleCreated) ? (HWND)control.Parent()().Handle() : (HWND)emptyForm.Handle());
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

void FormsApi::Control::SetBackColor(intptr hdc, const System::Drawing::Color& color) {
  SetBkColor((HDC)hdc, ColorToRgb(color));
  SetBkMode((HDC)hdc, TRANSPARENT);
}

void FormsApi::Control::SetForeColor(intptr hdc, const System::Drawing::Color& color) {
  SetTextColor((HDC)hdc, ColorToRgb(color));
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  HDC hdc = GetDC((HWND)control.Handle());
  SetBackColor((intptr)hdc, control.BackColor);
  ReleaseDC((HWND)control.Handle(), hdc);
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  HDC hdc = GetDC((HWND)control.Handle());
  SetForeColor((intptr)hdc, control.ForeColor);
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
