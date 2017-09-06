#include "../../../../../Includes/Switch/System/Windows/Forms/SystemInformation.hpp"
#include "../../../../__OS/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

property<int32, readonly> SystemInformation::ActiveWindowTrackingDelay {
  [] {return FormsApi::SystemInformation::GetActiveWindowTrackingDelay();}
};

property<System::Windows::Forms::ArrangeDirection, readonly> SystemInformation::ArrangeDirection{
  [] {return FormsApi::SystemInformation::GetArrangeDirection(); }
};

property<System::Windows::Forms::ArrangeStartingPosition, readonly> SystemInformation::ArrangeStartingPosition{
  [] {return FormsApi::SystemInformation::GetArrangeStartingPosition(); }
};

property<System::Windows::Forms::BootMode, readonly> SystemInformation::BootMode{
  [] {return FormsApi::SystemInformation::GetBootMode(); }
};

property<System::Drawing::Size, readonly> SystemInformation::Border3DSize{
  [] {return FormsApi::SystemInformation::GetBorder3DSize(); }
};

property<int32, readonly> SystemInformation::BorderMultiplierFactor{
  [] {return FormsApi::SystemInformation::GetBorderMultiplierFactor(); }
};

property<System::Drawing::Size, readonly> SystemInformation::BorderSize{
  [] {return FormsApi::SystemInformation::GetBorderSize(); }
};

property<System::Drawing::Size, readonly> SystemInformation::CaptionButtonSize{
  [] {return FormsApi::SystemInformation::GetCaptionButtonSize(); }
};

property<int32, readonly> SystemInformation::CaptionHeight {
  [] {return FormsApi::SystemInformation::GetCaptionHeight();}
};

property<int32, readonly> SystemInformation::CaretBlinkTime{
  [] {return FormsApi::SystemInformation::GetCaretBlinkTime(); }
};

property<int32, readonly> SystemInformation::CaretWidth{
  [] {return FormsApi::SystemInformation::GetCaretWidth(); }
};

property<string, readonly> SystemInformation::ComputerName{
  [] {return Environment::MachineName(); }
};

property<System::Drawing::Size, readonly> SystemInformation::CursorSize{
  [] {return FormsApi::SystemInformation::GetCursorSize(); }
};

property<bool, readonly> SystemInformation::DbcsEnabled{
  [] {return FormsApi::SystemInformation::GetDbcsEnabled(); }
};

property<bool, readonly> SystemInformation::DebugOS{
  [] {return FormsApi::SystemInformation::GetDebugOS(); }
};

property<System::Drawing::Size, readonly> SystemInformation::DoubleClickSize{
  [] {return FormsApi::SystemInformation::GetDoubleClickSize(); }
};

property<int32, readonly> SystemInformation::DoubleClickTime{
  [] {return FormsApi::SystemInformation::GetDoubleClickTime(); }
};

property<bool, readonly> SystemInformation::DragFullWindows{
  [] {return FormsApi::SystemInformation::GetDragFullWindows(); }
};

property<System::Drawing::Size, readonly> SystemInformation::DragSize{
  [] {return FormsApi::SystemInformation::GetDragSize(); }
};

property<System::Drawing::Size, readonly> SystemInformation::FixedFrameBorderSize{
  [] {return FormsApi::SystemInformation::GetFixedFrameBorderSize(); }
};

property<int32, readonly> SystemInformation::FontSmoothingContrast{
  [] {return FormsApi::SystemInformation::GetFontSmoothingContrast(); }
};

property<int32, readonly> SystemInformation::FontSmoothingType{
  [] {return FormsApi::SystemInformation::GetFontSmoothingType(); }
};

property<System::Drawing::Size, readonly> SystemInformation::FrameBorderSize{
  [] {return FormsApi::SystemInformation::GetFrameBorderSize(); }
};

property<bool, readonly> SystemInformation::HighContrast{
  [] {return FormsApi::SystemInformation::GetHighContrast(); }
};

property<int32, readonly> SystemInformation::HorizontalFocusThickness{
  [] {return FormsApi::SystemInformation::GetHorizontalFocusThickness(); }
};

property<int32, readonly> SystemInformation::HorizontalResizeBorderThickness{
  [] {return FormsApi::SystemInformation::GetHorizontalResizeBorderThickness(); }
};

property<int32, readonly> SystemInformation::HorizontalScrollBarArrowWidth{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth(); }
};

property<int32, readonly> SystemInformation::HorizontalScrollBarHeight{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarHeight(); }
};

property<int32, readonly> SystemInformation::HorizontalScrollBarThumbWidth{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth(); }
};

property<int32, readonly> SystemInformation::IconHorizontalSpacing{
  [] {return FormsApi::SystemInformation::GetIconHorizontalSpacing(); }
};

property<System::Drawing::Size, readonly> SystemInformation::IconSize{
  [] {return FormsApi::SystemInformation::GetIconSize(); }
};

property<System::Drawing::Size, readonly> SystemInformation::IconSpacingSize{
  [] {return FormsApi::SystemInformation::GetIconSpacingSize(); }
};

property<int32, readonly> SystemInformation::IconVerticalSpacing{
  [] {return FormsApi::SystemInformation::GetIconVerticalSpacing(); }
};

property<bool, readonly> SystemInformation::IsActiveWindowTrackingEnabled{
  [] {return FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled(); }
};

property<bool, readonly> SystemInformation::IsComboBoxAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled(); }
};

property<bool, readonly> SystemInformation::IsDropShadowEnabled{
  [] {return FormsApi::SystemInformation::GetIsDropShadowEnabled(); }
};

property<bool, readonly> SystemInformation::IsFlatMenuEnabled{
  [] {return FormsApi::SystemInformation::GetIsFlatMenuEnabled(); }
};

property<bool, readonly> SystemInformation::IsFontSmoothingEnabled{
  [] {return FormsApi::SystemInformation::GetIsFontSmoothingEnabled(); }
};

property<bool, readonly> SystemInformation::IsHotTrackingEnabled{
  [] {return FormsApi::SystemInformation::GetIsHotTrackingEnabled(); }
};

property<bool, readonly> SystemInformation::IsIconTitleWrappingEnabled{
  [] {return FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled(); }
};

property<bool, readonly> SystemInformation::IsKeyboardPreferred{
  [] {return FormsApi::SystemInformation::GetIsKeyboardPreferred(); }
};

property<bool, readonly> SystemInformation::IsListBoxSmoothScrollingEnabled{
  [] {return FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled(); }
};

property<bool, readonly> SystemInformation::IsMenuAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsMenuAnimationEnabled(); }
};

property<bool, readonly> SystemInformation::IsMenuFadeEnabled{
  [] {return FormsApi::SystemInformation::GetIsMenuFadeEnabled(); }
};

property<bool, readonly> SystemInformation::IsMinimizeRestoreAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled(); }
};

property<bool, readonly> SystemInformation::IsSelectionFadeEnabled{
  [] {return FormsApi::SystemInformation::GetIsSelectionFadeEnabled(); }
};

property<bool, readonly> SystemInformation::IsSnapToDefaultEnabled{
  [] {return FormsApi::SystemInformation::GetIsSnapToDefaultEnabled(); }
};

property<bool, readonly> SystemInformation::IsTitleBarGradientEnabled{
  [] {return FormsApi::SystemInformation::GetIsTitleBarGradientEnabled(); }
};

property<bool, readonly> SystemInformation::IsToolTipAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsToolTipAnimationEnabled(); }
};

property<int32, readonly> SystemInformation::KanjiWindowHeight{
  [] {return FormsApi::SystemInformation::GetKanjiWindowHeight(); }
};

property<int32, readonly> SystemInformation::KeyboardDelay{
  [] {return FormsApi::SystemInformation::GetKeyboardDelay(); }
};

property<int32, readonly> SystemInformation::KeyboardSpeed{
  [] {return FormsApi::SystemInformation::GetKeyboardSpeed(); }
};

property<System::Drawing::Size, readonly> SystemInformation::MaxWindowTrackSize{
  [] {return FormsApi::SystemInformation::GetMaxWindowTrackSize(); }
};

property<bool, readonly> SystemInformation::MenuAccessKeysUnderlined{
  [] {return FormsApi::SystemInformation::GetMenuAccessKeysUnderlined(); }
};

property<System::Drawing::Size, readonly> SystemInformation::MenuBarButtonSize{
  [] {return FormsApi::SystemInformation::GetMenuBarButtonSize(); }
};

property<System::Drawing::Size, readonly> SystemInformation::MenuButtonSize{
  [] {return FormsApi::SystemInformation::GetMenuButtonSize(); }
};

property<System::Drawing::Size, readonly> SystemInformation::MenuCheckSize{
  [] {return FormsApi::SystemInformation::GetMenuCheckSize(); }
};

property<System::Drawing::Font, readonly> SystemInformation::MenuFont{
  [] {return FormsApi::SystemInformation::GetMenuFont(); }
};

property<int32, readonly> SystemInformation::MenuHeight{
  [] {return FormsApi::SystemInformation::GetMenuHeight(); }
};

