#if __linux__
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/NotImplementedException.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  static bool messageLoopRunning = false;
  
  int32 GetMessage(Message& message) {
    throw NotImplementedException(pcf_current_information);
  }
  
  int32 PeekMessage(Message& message) {
    throw NotImplementedException(pcf_current_information);
  }
  
  void TranslateMessage(Message& message) {
    throw NotImplementedException(pcf_current_information);
  }
  
  void DispatchMessage(const Message& message) {
    throw NotImplementedException(pcf_current_information);
  }
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  Environment::Exit(0);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  messageLoopRunning = true;
  while (messageLoopRunning) {
    Message msg;
    int32 result = idle.IsEmpty() ? GetMessage(msg) : PeekMessage(msg);
    while (result != 0) {
      TranslateMessage(msg);
      DispatchMessage(msg);
      if (msg.Msg == WM_QUIT) {
        messageLoopRunning = false;
        break;
      }
      result = idle.IsEmpty() ? GetMessage(msg) : PeekMessage(msg);
      if (idle.IsEmpty() && !result)
        messageLoopRunning = false;
    }
    idle(object(), EventArgs());
  }
}

void FormsApi::Application::RegisterClasses() {
  throw NotImplementedException(pcf_current_information);
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return DialogResult::None;
}

void FormsApi::Application::UnregisterClasses() {
  throw NotImplementedException(pcf_current_information);
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
  throw NotImplementedException(pcf_current_information);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  throw NotImplementedException(pcf_current_information);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  throw NotImplementedException(pcf_current_information);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  throw NotImplementedException(pcf_current_information);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  throw NotImplementedException(pcf_current_information);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& label) {
  throw NotImplementedException(pcf_current_information);
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& radioButton) {
  throw NotImplementedException(pcf_current_information);
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
  throw NotImplementedException(pcf_current_information);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  throw NotImplementedException(pcf_current_information);
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return IntPtr::Zero;
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  throw NotImplementedException(pcf_current_information);
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  throw NotImplementedException(pcf_current_information);
}

void FormsApi::Control::SetBackColor(intptr hdc, const System::Drawing::Color& color) {
}

void FormsApi::Control::SetForeColor(intptr hdc, const System::Drawing::Color& color) {
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  throw NotImplementedException(pcf_current_information);
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
  throw NotImplementedException(pcf_current_information);
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  throw NotImplementedException(pcf_current_information);
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  throw NotImplementedException(pcf_current_information);
}

int32 FormsApi::SystemInformation::GetActiveWindowTrackingDelay() {
  return 0;
}

ArrangeDirection FormsApi::SystemInformation::GetArrangeDirection() {
  return ArrangeDirection::Left;
}

ArrangeStartingPosition FormsApi::SystemInformation::GetArrangeStartingPosition() {
  return ArrangeStartingPosition::Hide;
}

BootMode FormsApi::SystemInformation::GetBootMode() {
  return BootMode::Normal;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorder3DSize() {
  return System::Drawing::Size(0, 0);
}

int32 FormsApi::SystemInformation::GetBorderMultiplierFactor() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorderSize() {
  return System::Drawing::Size(0, 0);
}

System::Drawing::Size FormsApi::SystemInformation::GetCaptionButtonSize() {
  return System::Drawing::Size(16, 16);
}

int32 FormsApi::SystemInformation::GetCaptionHeight() {
  return 23;
}

int32 FormsApi::SystemInformation::GetCaretBlinkTime() {
  return 530;
}

int32 FormsApi::SystemInformation::GetCaretWidth() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetCursorSize() {
  return System::Drawing::Size(32, 32);
}

bool FormsApi::SystemInformation::GetDbcsEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetDebugOS() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetDoubleClickSize() {
  return System::Drawing::Size(4, 4);
}

int32 FormsApi::SystemInformation::GetDoubleClickTime() {
  return 500;
}

bool FormsApi::SystemInformation::GetDragFullWindows() {
  return true;
}

System::Drawing::Size FormsApi::SystemInformation::GetDragSize() {
  return System::Drawing::Size(4, 4);
}

System::Drawing::Size FormsApi::SystemInformation::GetFixedFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

int32 FormsApi::SystemInformation::GetFontSmoothingContrast() {
  return 1200;
}

int32 FormsApi::SystemInformation::GetFontSmoothingType() {
  return 2;
}

System::Drawing::Size FormsApi::SystemInformation::GetFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetHighContrast() {
  return false;
}

int32 FormsApi::SystemInformation::GetHorizontalFocusThickness() {
  return 1;
}

int32 FormsApi::SystemInformation::GetHorizontalResizeBorderThickness() {
  return 4;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarHeight() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetIconHorizontalSpacing() {
  return 75;
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSize() {
  return System::Drawing::Size(64, 64);
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSpacingSize() {
  return System::Drawing::Size(75, 75);
}

int32 FormsApi::SystemInformation::GetIconVerticalSpacing() {
  return 75;
}

bool FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsDropShadowEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsFlatMenuEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsFontSmoothingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsHotTrackingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsKeyboardPreferred() {
  return false;
}

bool FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuFadeEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsSelectionFadeEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsSnapToDefaultEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsTitleBarGradientEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsToolTipAnimationEnabled() {
  return false;
}

int32 FormsApi::SystemInformation::GetKanjiWindowHeight() {
  return 0;
}

int32 FormsApi::SystemInformation::GetKeyboardDelay() {
  return 1;
}

int32 FormsApi::SystemInformation::GetKeyboardSpeed() {
  return 31;
}

System::Drawing::Size FormsApi::SystemInformation::GetMaxWindowTrackSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetMenuAccessKeysUnderlined() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuBarButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuCheckSize() {
  return System::Drawing::Size(15, 15);
}

Font FormsApi::SystemInformation::GetMenuFont() {
  return Font::FromLogFont((intptr)0);
}

int32 FormsApi::SystemInformation::GetMenuHeight() {
  return 23;
}

#endif
