#if _WIN32
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>

#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/NotImplementedException.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "FormsApi.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

extern int main(int argc, char* argv[]);
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;

namespace {
  Drawing::Rectangle GetFormBounds(const System::Windows::Forms::Form& form);
  LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

  HINSTANCE __instance;
  HINSTANCE __prevInstance;
  LPSTR __commandLine;
  int __cmdShow;
  System::Collections::Generic::Dictionary<intptr, WNDPROC> defWindowProcs;

  intptr CreateControl(const Control& control, const string& name, int32 windowStyle, HWND parent) {
    Drawing::Rectangle bounds = control.Bounds;
    if (is<Form>(control))
      Drawing::Rectangle bounds = GetFormBounds(as<Form>(control));
    HWND handle = CreateWindowEx(0, name == "Form" || name == "Panel" ? WC_DIALOG :  name.w_str().c_str(), control.Text().w_str().c_str(), windowStyle, bounds.Left, bounds.Top, bounds.Width, bounds.Height, parent, (HMENU)NULL, __instance, (LPVOID)NULL);
    if (handle == 0) {
      string str = string::Format("FormApi::Create(\"{0}\") failed with code {1}", name, GetLastError());
      throw InvalidOperationException(str, pcf_current_information);
    }
    defWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WndProc);
    return (intptr)handle;
  }

  Drawing::Rectangle GetFormBounds(const System::Windows::Forms::Form& form) {
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
    Reference<Control> control = Control::FromHandle(message.HWnd);
    if (control != null)
      control().WndProc(message);
    return message.Result;
  }

  inline COLORREF ColorToRgb(const Color& color) {
    return RGB(color.R, color.G, color.B);
  }
}

INT WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR commandLine, INT cmdShow) {
  __instance = instance;
  __prevInstance = prevInstance;
  __commandLine = commandLine;
  __cmdShow = cmdShow;
  return main(__argc, __argv);
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  PostQuitMessage(0);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  // MessagelLoop without idle...
  /*
  MSG msg;
  bool messageLoopRunning = true;
  while (GetMessage(&msg, NULL, 0, 0) != 0) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  messageLoopRunning = false;
  */

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
    idle(object(), EventArgs());
  }
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

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
  CloseWindow((HWND)form.data->handle);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  return CreateControl(button, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, (HWND)button.Parent()().data->handle);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  return CreateControl(checkBox, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, (HWND)checkBox.Parent()().data->handle);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  return CreateControl(control, L"Control", WS_VISIBLE | WS_CHILD, (HWND)control.Parent()().data->handle);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  return CreateControl(form, L"Form", WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_GROUP, (HWND)NULL);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& label) {
  return CreateControl(label, L"Static", WS_VISIBLE | WS_CHILD, (HWND)label.Parent()().data->handle);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& radioButton) {
  return CreateControl(radioButton, L"Button", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, (HWND)radioButton.Parent()().data->handle);
}

//intptr FormsApi::Control::Create(const System::Windows::Forms::Panel& panel) {
//  return CreateControl(panel, L"Panel", WS_VISIBLE | WS_CHILD | WS_BORDER, (HWND)control.Parent()().data->handle);
//}

void FormsApi::Control::DefWndProc(Message& message) {
  if (defWindowProcs.ContainsKey(message.HWnd()))
    message.Result = defWindowProcs[message.HWnd()]((HWND)message.HWnd(), message.Msg, message.WParam, message.LParam);
  else
    message.Result = DefWindowProc((HWND)message.HWnd(), message.Msg, message.WParam, message.LParam);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.data->handle) {
    intptr handle = control.data->handle;
    defWindowProcs.Remove(handle);
    DestroyWindow((HWND)handle);
  }
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return (intptr)WindowFromDC((HDC)hdc);
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {
  if (!control.data->handle)
    return;
  if (invalidateChildren)
    RedrawWindow((HWND)control.data->handle, null, null, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
  else
    InvalidateRect((HWND)control.data->handle, null, true);
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {
  if (!control.data->handle)
    return;
  RECT invalidateRect {rect.Left, rect.Top, rect.Right, rect.Bottom};
  if (invalidateChildren)
    RedrawWindow((HWND)control.data->handle, &invalidateRect, null, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
  else
    InvalidateRect((HWND)control.data->handle, &invalidateRect, true);
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  POINT location{point.X, point.Y};
  ScreenToClient((HWND)control.data->handle, &location);
  return System::Drawing::Point(location.x, location.y);
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  POINT location{point.X, point.Y};
  ClientToScreen((HWND)control.data->handle, &location);
  return System::Drawing::Point(location.x, location.y);
}

void FormsApi::Control::SetBackColor(intptr hdc, const System::Drawing::Color& color) {
  SetBkColor((HDC)hdc, ColorToRgb(color));
}

void FormsApi::Control::SetForeColor(intptr hdc, const System::Drawing::Color& color) {
  SetTextColor((HDC)hdc, ColorToRgb(color));
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  HDC hdc = GetDC((HWND)control.data->handle);
  SetBackColor((intptr)hdc, control.BackColor);
  ReleaseDC((HWND)control.data->handle, hdc);
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  HDC hdc = GetDC((HWND)control.data->handle);
  SetForeColor((intptr)hdc, control.ForeColor);
  ReleaseDC((HWND)control.data->handle, hdc);
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  if (control.data->handle)
    SetWindowPos((HWND)control.data->handle, NULL, control.Location().X, control.Location().Y, control.Size().Width, control.Size().Height, SWP_NOSIZE);
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
  if (control.data->handle)
    SetWindowPos((HWND)control.data->handle, NULL, control.Location().X, control.Location().Y, control.Size().Width, control.Size().Height, SWP_NOMOVE);
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  if (control.data->handle)
    //SetWindowTextA((HWND)control.data->handle, control.data->text.c_str());
    SetWindowText((HWND)control.data->handle, control.data->text.w_str().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  if (control.data->handle)
    ShowWindow((HWND)control.data->handle, control.Visible ? SW_SHOW : SW_HIDE);
}

int32 FormsApi::SystemInformation::GetActiveWindowTrackingDelay() {
  int32 value;
  SystemParametersInfo(SPI_GETACTIVEWNDTRKTIMEOUT, 0, &value, 0);
  return value;
}

ArrangeDirection FormsApi::SystemInformation::GetArrangeDirection() {
  return (ArrangeDirection)(GetSystemMetrics(SM_ARRANGE) & int32(ArrangeDirection::Down | ArrangeDirection::Left | ArrangeDirection::Right | ArrangeDirection::Up));
}

ArrangeStartingPosition FormsApi::SystemInformation::GetArrangeStartingPosition() {
  return (ArrangeStartingPosition)(GetSystemMetrics(SM_ARRANGE) & int32(ArrangeStartingPosition::BottomLeft | ArrangeStartingPosition::BottomRight | ArrangeStartingPosition::Hide | ArrangeStartingPosition::TopLeft | ArrangeStartingPosition::TopRight));
}

BootMode FormsApi::SystemInformation::GetBootMode() {
  return (BootMode)GetSystemMetrics(SM_CLEANBOOT);
}

Size FormsApi::SystemInformation::GetBorder3DSize() {
  return Size(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE));
}

int32 FormsApi::SystemInformation::GetBorderMultiplierFactor() {
  int32 value;
  SystemParametersInfo(SPI_GETBORDER, 0, &value, 0);
  return value;
}

Size FormsApi::SystemInformation::GetBorderSize() {
  return Size(GetSystemMetrics(SM_CXBORDER), GetSystemMetrics(SM_CYBORDER));
}

Size FormsApi::SystemInformation::GetCaptionButtonSize() {
  return Size(GetSystemMetrics(SM_CXSIZE), GetSystemMetrics(SM_CYSIZE));
}

int32 FormsApi::SystemInformation::GetCaptionHeight() {
  return GetSystemMetrics(SM_CYCAPTION);
}

int32 FormsApi::SystemInformation::GetCaretBlinkTime() {
  return ::GetCaretBlinkTime();
}

int32 FormsApi::SystemInformation::GetCaretWidth() {
  int32 value;
  SystemParametersInfo(SPI_GETCARETWIDTH, 0, &value, 0);
  return value;
}

Size FormsApi::SystemInformation::GetCursorSize() {
  return Size(GetSystemMetrics(SM_CXCURSOR), GetSystemMetrics(SM_CYCURSOR));
}

bool FormsApi::SystemInformation::GetDbcsEnabled() {
  return GetSystemMetrics(SM_DBCSENABLED) != 0;
}

bool FormsApi::SystemInformation::GetDebugOS() {
  return GetSystemMetrics(SM_DEBUG) != 0;
}

Size FormsApi::SystemInformation::GetDoubleClickSize() {
  return Size(GetSystemMetrics(SM_CXDOUBLECLK), GetSystemMetrics(SM_CYDOUBLECLK));
}

int32 FormsApi::SystemInformation::GetDoubleClickTime() {
  return ::GetDoubleClickTime();
}

bool FormsApi::SystemInformation::GetDragFullWindows() {
  int32 value;
  SystemParametersInfo(SPI_GETDRAGFULLWINDOWS, 0, &value, 0);
  return value != 0;
}

Size FormsApi::SystemInformation::GetDragSize() {
  return Size(GetSystemMetrics(SM_CXDRAG), GetSystemMetrics(SM_CYDRAG));
}

Size FormsApi::SystemInformation::GetFixedFrameBorderSize() {
  return Size(GetSystemMetrics(SM_CXFIXEDFRAME), GetSystemMetrics(SM_CYFIXEDFRAME));
}

int32 FormsApi::SystemInformation::GetFontSmoothingContrast() {
  int32 value;
  SystemParametersInfo(SPI_GETFONTSMOOTHINGCONTRAST, 0, &value, 0);
  return value;
}

int32 FormsApi::SystemInformation::GetFontSmoothingType() {
  int32 value;
  SystemParametersInfo(SPI_GETFONTSMOOTHINGTYPE, 0, &value, 0);
  return value;
}

Size FormsApi::SystemInformation::GetFrameBorderSize() {
  return Size(GetSystemMetrics(SM_CXFRAME), GetSystemMetrics(SM_CYFRAME));
}

bool FormsApi::SystemInformation::GetHighContrast() {
  HIGHCONTRAST value{sizeof(HIGHCONTRAST), 0, NULL};
  SystemParametersInfo(SPI_GETDRAGFULLWINDOWS, sizeof(value), &value, 0);
  return (value.dwFlags & HCF_HIGHCONTRASTON) == HCF_HIGHCONTRASTON;
}

int32 FormsApi::SystemInformation::GetHorizontalFocusThickness() {
  return GetSystemMetrics(SM_CXFOCUSBORDER);
}

int32 FormsApi::SystemInformation::GetHorizontalResizeBorderThickness() {
  return GetSystemMetrics(SM_CXSIZEFRAME);
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth() {
  return GetSystemMetrics(SM_CXHSCROLL);
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarHeight() {
  return GetSystemMetrics(SM_CYHSCROLL);
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth() {
  return GetSystemMetrics(SM_CXHTHUMB);
}

int32 FormsApi::SystemInformation::GetIconHorizontalSpacing() {
  int32 value;
  SystemParametersInfo(SPI_ICONHORIZONTALSPACING, 0, &value, 0);
  return value;
}

Size FormsApi::SystemInformation::GetIconSize() {
  return Size(GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON));
}

Size FormsApi::SystemInformation::GetIconSpacingSize() {
  return Size(GetSystemMetrics(SM_CXICONSPACING), GetSystemMetrics(SM_CYICONSPACING));
}

int32 FormsApi::SystemInformation::GetIconVerticalSpacing() {
  int32 value;
  SystemParametersInfo(SPI_ICONVERTICALSPACING, 0, &value, 0);
  return value;
}

bool FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETACTIVEWINDOWTRACKING, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETCOMBOBOXANIMATION, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsDropShadowEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETDROPSHADOW, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsFlatMenuEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETFLATMENU, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsFontSmoothingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETFONTSMOOTHING, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsHotTrackingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETHOTTRACKING, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETICONTITLEWRAP, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsKeyboardPreferred() {
  int32 value;
  SystemParametersInfo(SPI_GETKEYBOARDPREF, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETLISTBOXSMOOTHSCROLLING, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsMenuAnimationEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETMENUANIMATION, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsMenuFadeEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETMENUFADE, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETANIMATION, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsSelectionFadeEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETSELECTIONFADE, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsSnapToDefaultEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETSNAPTODEFBUTTON, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsTitleBarGradientEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETGRADIENTCAPTIONS, 0, &value, 0);
  return value != 0;
}

bool FormsApi::SystemInformation::GetIsToolTipAnimationEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETTOOLTIPANIMATION, 0, &value, 0);
  return value != 0;
}

int32 FormsApi::SystemInformation::GetKanjiWindowHeight() {
  return GetSystemMetrics(SM_CYKANJIWINDOW);
}

int32 FormsApi::SystemInformation::GetKeyboardDelay() {
  int32 value;
  SystemParametersInfo(SPI_GETKEYBOARDDELAY, 0, &value, 0);
  return value;
}

int32 FormsApi::SystemInformation::GetKeyboardSpeed() {
  int32 value;
  SystemParametersInfo(SPI_GETKEYBOARDSPEED, 0, &value, 0);
  return value;
}

Size FormsApi::SystemInformation::GetMaxWindowTrackSize() {
  return Size(GetSystemMetrics(SM_CXMAXTRACK), GetSystemMetrics(SM_CYMAXTRACK));
}

bool FormsApi::SystemInformation::GetMenuAccessKeysUnderlined() {
  int32 value;
  SystemParametersInfo(SPI_GETKEYBOARDCUES, 0, &value, 0);
  return value != 0;
}

Size FormsApi::SystemInformation::GetMenuBarButtonSize() {
  NONCLIENTMETRICS value;
  value.cbSize = sizeof(value);
  SystemParametersInfo(SPI_GETNONCLIENTMETRICS, value.cbSize, &value, 0);
  return Size(value.iMenuWidth, value.iMenuHeight);
}

Size FormsApi::SystemInformation::GetMenuButtonSize() {
  return Size(GetSystemMetrics(SM_CXMENUSIZE), GetSystemMetrics(SM_CYMENUSIZE));
}

Size FormsApi::SystemInformation::GetMenuCheckSize() {
  return Size(GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK));
}

Font FormsApi::SystemInformation::GetMenuFont() {
  NONCLIENTMETRICS value;
  value.cbSize = sizeof(value);
  SystemParametersInfo(SPI_GETNONCLIENTMETRICS, value.cbSize, &value, 0);
  return Font::FromLogFont((intptr)&value.lfMenuFont);
}

int32 FormsApi::SystemInformation::GetMenuHeight() {
  return GetSystemMetrics(SM_CYMENU);
}

#endif
