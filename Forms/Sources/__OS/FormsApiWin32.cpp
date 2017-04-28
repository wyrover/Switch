#if defined(_WIN32) && defined(__use_native_interface__)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"
#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/NotImplementedException.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

extern int main(int argc, char* argv[]);
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;

namespace {
  Drawing::Rectangle GetFormBounds(const Form& form);
  LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

  HINSTANCE __instance;
  Dictionary<intptr, WNDPROC> defWindowProcs;

  inline COLORREF ColorToRgb(const Color& color) {
	  return RGB(color.R, color.G, color.B);
  }

  intptr CreateControl(const Control& control, const string& name, int32 windowStyle, int32 id, HWND parent) {
    Drawing::Rectangle bounds = control.Bounds;
    if (is<Form>(control))
      Drawing::Rectangle bounds = GetFormBounds(as<Form>(control));
    HWND handle = CreateWindowEx(0, name == "Form" || name == "Panel" ? WC_DIALOG : name.w_str().c_str(), control.Text().w_str().c_str(), windowStyle, bounds.Left, bounds.Top, bounds.Width, bounds.Height, parent, (HMENU)id, __instance, (LPVOID)NULL);
    if (handle == 0) {
      string str = string::Format("FormApi::Create(\"{0}\") failed with code {1}", name, GetLastError());
      throw InvalidOperationException(str, pcf_current_information);
    }

    defWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WndProc);
    RedrawWindow(handle, null, null, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
    return (intptr)handle;
  }

  intptr CreateControl(const Control& control, const string& name, int32 windowStyle, HWND parent) {
    return CreateControl(control, name, windowStyle, 0, parent);
  }

  Drawing::Rectangle GetFormBounds(const Form& form) {
    switch (form.StartPosition) {
    case FormStartPosition::Manual: return Drawing::Rectangle(form.Bounds);
    case FormStartPosition::WindowsDefaultBounds: return Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT);
    case FormStartPosition::WindowsDefaultLocation: return Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, form.Width, form.Height);
    }
    return Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT);
  }

  void SetWindowTheme(intptr handle) {
    if (!FormsApi::Application::HasVisualStylesEnabled())
      SetWindowTheme((HWND)handle, L"", L"");
  }

  void RegisterClassControl() {
    WNDCLASSEX wndClass;
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_GLOBALCLASS;
    wndClass.lpfnWndProc = DefWindowProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = __instance;
    wndClass.hIcon = NULL;
    wndClass.hCursor = NULL;
    wndClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = L"Control";
    wndClass.hIconSm = NULL;

    if (RegisterClassEx(&wndClass) == NULL)
      throw InvalidOperationException(string::Format("FormsApi::Application::RegisterClasses(\"Control\") failed with code = {0}", GetLastError()), pcf_current_information);
  }

  LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    Message message = Message::Create((intptr)hwnd, msg, wParam, lParam, 0);
    ref<Control> control = Control::FromHandle(message.HWnd);
    if (control != null)
      control().WndProc(message);
    return message.Result;
  }
}

INT WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR commandLine, INT cmdShow) {
  __instance = instance;
  return main(__argc, __argv);
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::AddForm(const Form& form) {
}

void FormsApi::Application::Exit() {
  PostQuitMessage(0);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  bool messageLoopRunning = true;
  while (messageLoopRunning) {
    MSG msg;
    int32 result = idle.IsEmpty() ? GetMessage(&msg, NULL, 0, 0) : PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
    while (result != 0) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      if (msg.message == WM_QUIT) {
        messageLoopRunning = false;
        break;
      }
      result = idle.IsEmpty() ? GetMessage(&msg, NULL, 0, 0) : PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
      if (idle.IsEmpty() && !result)
        messageLoopRunning = false;
    }
    idle(object(), EventArgs::Empty);
  }
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
  ::MessageBeep((uint32)type);
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return (DialogResult)MessageBox(GetActiveWindow(), message.w_str().c_str(), caption.w_str().c_str(), (uint32)buttons + (uint32)icon + (uint32)defaultButton + (uint32)options + (displayHelpButton ? 0x00004000L : 0));
}

void FormsApi::Application::Start() {
  RegisterClassControl();
}

void FormsApi::Application::Stop() {
  UnregisterClass(L"Control", NULL);
}

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  PostMessage((HWND)checkBox.handle, BM_SETCHECK, checkBox.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
  CloseWindow((HWND)form.handle);
}

void FormsApi::Control::Create(System::Windows::Forms::Button& control) {
  static Form emptyForm;
  control.handle = CreateControl(control, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, (control.Parent != null && control.Parent()().handle != IntPtr::Zero) ? (HWND)control.Parent()().handle : (HWND)emptyForm.Handle());
}

void FormsApi::Control::Create(System::Windows::Forms::CheckBox& control) {
  static Form emptyForm;
  control.handle = CreateControl(control, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, (control.Parent != null && control.Parent()().handle != IntPtr::Zero) ? (HWND)control.Parent()().handle : (HWND)emptyForm.Handle());
}

void FormsApi::Control::Create(System::Windows::Forms::Control& control) {
  static Form emptyForm;
  control.handle = CreateControl(control, L"Control", WS_VISIBLE | WS_CHILD, (control.Parent != null && control.Parent()().handle != IntPtr::Zero) ? (HWND)control.Parent()().handle : (HWND)emptyForm.Handle());
}

void FormsApi::Control::Create(System::Windows::Forms::Form& control) {
  control.handle = CreateControl(control, L"Form", WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_GROUP, (control.Parent != null && control.Parent()().handle != IntPtr::Zero) ? (HWND)control.Parent()().handle : NULL);
}

void FormsApi::Control::Create(System::Windows::Forms::Label& control) {
  static Form emptyForm;
  control.handle = CreateControl(control, L"Static", WS_VISIBLE | WS_CHILD, (control.Parent != null && control.Parent()().handle != IntPtr::Zero) ? (HWND)control.Parent()().handle : (HWND)emptyForm.Handle());
  PostMessage((HWND)control.parent().handle, WM_CTLCOLORSTATIC, 0, control.handle);
}

void FormsApi::Control::Create(System::Windows::Forms::Panel& control) {
  static Form emptyForm;
  control.handle = CreateControl(control, L"Panel", WS_VISIBLE | WS_CHILD | WS_BORDER, (control.Parent != null && control.Parent()().handle != IntPtr::Zero) ? (HWND)control.Parent()().handle : (HWND)emptyForm.Handle());
}

void FormsApi::Control::Create(System::Windows::Forms::ProgressBar& control) {
  static Form emptyForm;
  control.handle = CreateControl(control, PROGRESS_CLASS, WS_VISIBLE | WS_CHILD | PBS_SMOOTH, (control.Parent != null && control.Parent()().handle != IntPtr::Zero) ? (HWND)control.Parent()().handle : (HWND)emptyForm.Handle());
}

void FormsApi::Control::Create(System::Windows::Forms::RadioButton& control) {
  static Form emptyForm;
  control.handle = CreateControl(control, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, (control.Parent != null && control.Parent()().handle != IntPtr::Zero) ? (HWND)control.Parent()().handle : (HWND)emptyForm.Handle());
}

void FormsApi::Control::DefWndProc(Message& message) {
  if (defWindowProcs.ContainsKey(message.HWnd()))
    message.Result = defWindowProcs[message.HWnd()]((HWND)message.HWnd(), message.Msg, message.WParam, message.LParam);
  else
    message.Result = DefWindowProc((HWND)message.HWnd(), message.Msg, message.WParam, message.LParam);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.handle) {
    intptr handle = control.handle;
    defWindowProcs.Remove(handle);
    DestroyWindow((HWND)handle);
  }
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return (intptr)WindowFromDC((HDC)hdc);
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {
  if (invalidateChildren)
    RedrawWindow((HWND)control.handle, null, null, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
  else
    InvalidateRect((HWND)control.handle, null, true);
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {
  RECT invalidateRect {rect.Left, rect.Top, rect.Right, rect.Bottom};
  if (invalidateChildren)
    RedrawWindow((HWND)control.handle, &invalidateRect, null, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
  else
    InvalidateRect((HWND)control.handle, &invalidateRect, true);
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  POINT location{point.X, point.Y};
  ScreenToClient((HWND)control.handle, &location);
  return System::Drawing::Point(location.x, location.y);
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  POINT location{point.X, point.Y};
  ClientToScreen((HWND)control.handle, &location);
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
  HDC hdc = GetDC((HWND)control.handle);
  SetBackColor((intptr)hdc, control.BackColor);
  ReleaseDC((HWND)control.handle, hdc);
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  HDC hdc = GetDC((HWND)control.handle);
  SetForeColor((intptr)hdc, control.ForeColor);
  ReleaseDC((HWND)control.handle, hdc);
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  SetWindowPos((HWND)control.handle, NULL, control.Location().X, control.Location().Y, control.Size().Width, control.Size().Height, SWP_NOSIZE);
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
  ::SetParent((HWND)control.handle, (HWND)control.parent().handle);
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
  SetWindowPos((HWND)control.handle, NULL, control.Location().X, control.Location().Y, control.Size().Width, control.Size().Height, SWP_NOMOVE);
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  SetWindowText((HWND)control.handle, control.text.w_str().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  ShowWindow((HWND)control.handle, control.Visible ? SW_SHOW : SW_HIDE);
}

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  if (panel.BorderStyle == BorderStyle::FixedSingle)
    SetWindowLong((HWND)panel.handle, GWL_STYLE, GetWindowLong((HWND)panel.handle, GWL_STYLE) | WS_BORDER);
  else {
    SetWindowLong((HWND)panel.handle, GWL_STYLE, GetWindowLong((HWND)panel.handle, GWL_STYLE) & ~WS_BORDER);
    if (panel.BorderStyle == BorderStyle::Fixed3D)
      SetWindowLong((HWND)panel.handle, GWL_EXSTYLE, GetWindowLong((HWND)panel.handle, GWL_EXSTYLE) | WS_EX_CLIENTEDGE);
  }
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.handle, PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.handle, PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.handle, PBM_SETPOS, progressBar.Value(), 0);
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  PostMessage((HWND)radioButton.handle, BM_SETCHECK, radioButton.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

#endif
