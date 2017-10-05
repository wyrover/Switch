#include "../../../../../Includes/Switch/System/Windows/Forms/SystemInformation.hpp"
#include "../../../../__OS/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

_property<int32, _readonly> SystemInformation::ActiveWindowTrackingDelay {
  [] {return FormsApi::SystemInformation::GetActiveWindowTrackingDelay();}
};

_property<System::Windows::Forms::ArrangeDirection, _readonly> SystemInformation::ArrangeDirection{
  [] {return FormsApi::SystemInformation::GetArrangeDirection(); }
};

_property<System::Windows::Forms::ArrangeStartingPosition, _readonly> SystemInformation::ArrangeStartingPosition{
  [] {return FormsApi::SystemInformation::GetArrangeStartingPosition(); }
};

_property<System::Windows::Forms::BootMode, _readonly> SystemInformation::BootMode{
  [] {return FormsApi::SystemInformation::GetBootMode(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::Border3DSize{
  [] {return FormsApi::SystemInformation::GetBorder3DSize(); }
};

_property<int32, _readonly> SystemInformation::BorderMultiplierFactor{
  [] {return FormsApi::SystemInformation::GetBorderMultiplierFactor(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::BorderSize{
  [] {return FormsApi::SystemInformation::GetBorderSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::CaptionButtonSize{
  [] {return FormsApi::SystemInformation::GetCaptionButtonSize(); }
};

_property<int32, _readonly> SystemInformation::CaptionHeight {
  [] {return FormsApi::SystemInformation::GetCaptionHeight();}
};

_property<int32, _readonly> SystemInformation::CaretBlinkTime{
  [] {return FormsApi::SystemInformation::GetCaretBlinkTime(); }
};

_property<int32, _readonly> SystemInformation::CaretWidth{
  [] {return FormsApi::SystemInformation::GetCaretWidth(); }
};

_property<string, _readonly> SystemInformation::ComputerName{
  [] {return Environment::MachineName(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::CursorSize{
  [] {return FormsApi::SystemInformation::GetCursorSize(); }
};

_property<bool, _readonly> SystemInformation::DbcsEnabled{
  [] {return FormsApi::SystemInformation::GetDbcsEnabled(); }
};

_property<bool, _readonly> SystemInformation::DebugOS{
  [] {return FormsApi::SystemInformation::GetDebugOS(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::DoubleClickSize{
  [] {return FormsApi::SystemInformation::GetDoubleClickSize(); }
};

_property<int32, _readonly> SystemInformation::DoubleClickTime{
  [] {return FormsApi::SystemInformation::GetDoubleClickTime(); }
};

_property<bool, _readonly> SystemInformation::DragFullWindows{
  [] {return FormsApi::SystemInformation::GetDragFullWindows(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::DragSize{
  [] {return FormsApi::SystemInformation::GetDragSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::FixedFrameBorderSize{
  [] {return FormsApi::SystemInformation::GetFixedFrameBorderSize(); }
};

_property<int32, _readonly> SystemInformation::FontSmoothingContrast{
  [] {return FormsApi::SystemInformation::GetFontSmoothingContrast(); }
};

_property<int32, _readonly> SystemInformation::FontSmoothingType{
  [] {return FormsApi::SystemInformation::GetFontSmoothingType(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::FrameBorderSize{
  [] {return FormsApi::SystemInformation::GetFrameBorderSize(); }
};

_property<bool, _readonly> SystemInformation::HighContrast{
  [] {return FormsApi::SystemInformation::GetHighContrast(); }
};

_property<int32, _readonly> SystemInformation::HorizontalFocusThickness{
  [] {return FormsApi::SystemInformation::GetHorizontalFocusThickness(); }
};

_property<int32, _readonly> SystemInformation::HorizontalResizeBorderThickness{
  [] {return FormsApi::SystemInformation::GetHorizontalResizeBorderThickness(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarArrowWidth{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarHeight{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarHeight(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarThumbWidth{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth(); }
};

_property<int32, _readonly> SystemInformation::IconHorizontalSpacing{
  [] {return FormsApi::SystemInformation::GetIconHorizontalSpacing(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::IconSize{
  [] {return FormsApi::SystemInformation::GetIconSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::IconSpacingSize{
  [] {return FormsApi::SystemInformation::GetIconSpacingSize(); }
};

_property<int32, _readonly> SystemInformation::IconVerticalSpacing{
  [] {return FormsApi::SystemInformation::GetIconVerticalSpacing(); }
};

_property<bool, _readonly> SystemInformation::IsActiveWindowTrackingEnabled{
  [] {return FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsComboBoxAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsDropShadowEnabled{
  [] {return FormsApi::SystemInformation::GetIsDropShadowEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsFlatMenuEnabled{
  [] {return FormsApi::SystemInformation::GetIsFlatMenuEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsFontSmoothingEnabled{
  [] {return FormsApi::SystemInformation::GetIsFontSmoothingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsHotTrackingEnabled{
  [] {return FormsApi::SystemInformation::GetIsHotTrackingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsIconTitleWrappingEnabled{
  [] {return FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsKeyboardPreferred{
  [] {return FormsApi::SystemInformation::GetIsKeyboardPreferred(); }
};

_property<bool, _readonly> SystemInformation::IsListBoxSmoothScrollingEnabled{
  [] {return FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMenuAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsMenuAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMenuFadeEnabled{
  [] {return FormsApi::SystemInformation::GetIsMenuFadeEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMinimizeRestoreAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsSelectionFadeEnabled{
  [] {return FormsApi::SystemInformation::GetIsSelectionFadeEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsSnapToDefaultEnabled{
  [] {return FormsApi::SystemInformation::GetIsSnapToDefaultEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsTitleBarGradientEnabled{
  [] {return FormsApi::SystemInformation::GetIsTitleBarGradientEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsToolTipAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsToolTipAnimationEnabled(); }
};

_property<int32, _readonly> SystemInformation::KanjiWindowHeight{
  [] {return FormsApi::SystemInformation::GetKanjiWindowHeight(); }
};

_property<int32, _readonly> SystemInformation::KeyboardDelay{
  [] {return FormsApi::SystemInformation::GetKeyboardDelay(); }
};

_property<int32, _readonly> SystemInformation::KeyboardSpeed{
  [] {return FormsApi::SystemInformation::GetKeyboardSpeed(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MaxWindowTrackSize{
  [] {return FormsApi::SystemInformation::GetMaxWindowTrackSize(); }
};

_property<bool, _readonly> SystemInformation::MenuAccessKeysUnderlined{
  [] {return FormsApi::SystemInformation::GetMenuAccessKeysUnderlined(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuBarButtonSize{
  [] {return FormsApi::SystemInformation::GetMenuBarButtonSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuButtonSize{
  [] {return FormsApi::SystemInformation::GetMenuButtonSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuCheckSize{
  [] {return FormsApi::SystemInformation::GetMenuCheckSize(); }
};

_property<System::Drawing::Font, _readonly> SystemInformation::MenuFont{
  [] {return FormsApi::SystemInformation::GetMenuFont(); }
};

_property<int32, _readonly> SystemInformation::MenuHeight{
  [] {return FormsApi::SystemInformation::GetMenuHeight(); }
};

