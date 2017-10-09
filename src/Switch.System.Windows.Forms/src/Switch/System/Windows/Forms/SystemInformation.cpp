#include "../../../../../include/Switch/System/Windows/Forms/SystemInformation.hpp"
#include "../../../../Native/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

_property<int32, _readonly> SystemInformation::ActiveWindowTrackingDelay {
  [] {return Native::FormsApi::SystemInformation::GetActiveWindowTrackingDelay();}
};

_property<System::Windows::Forms::ArrangeDirection, _readonly> SystemInformation::ArrangeDirection{
  [] {return Native::FormsApi::SystemInformation::GetArrangeDirection(); }
};

_property<System::Windows::Forms::ArrangeStartingPosition, _readonly> SystemInformation::ArrangeStartingPosition{
  [] {return Native::FormsApi::SystemInformation::GetArrangeStartingPosition(); }
};

_property<System::Windows::Forms::BootMode, _readonly> SystemInformation::BootMode{
  [] {return Native::FormsApi::SystemInformation::GetBootMode(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::Border3DSize{
  [] {return Native::FormsApi::SystemInformation::GetBorder3DSize(); }
};

_property<int32, _readonly> SystemInformation::BorderMultiplierFactor{
  [] {return Native::FormsApi::SystemInformation::GetBorderMultiplierFactor(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::BorderSize{
  [] {return Native::FormsApi::SystemInformation::GetBorderSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::CaptionButtonSize{
  [] {return Native::FormsApi::SystemInformation::GetCaptionButtonSize(); }
};

_property<int32, _readonly> SystemInformation::CaptionHeight {
  [] {return Native::FormsApi::SystemInformation::GetCaptionHeight();}
};

_property<int32, _readonly> SystemInformation::CaretBlinkTime{
  [] {return Native::FormsApi::SystemInformation::GetCaretBlinkTime(); }
};

_property<int32, _readonly> SystemInformation::CaretWidth{
  [] {return Native::FormsApi::SystemInformation::GetCaretWidth(); }
};

_property<string, _readonly> SystemInformation::ComputerName{
  [] {return Environment::MachineName(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::CursorSize{
  [] {return Native::FormsApi::SystemInformation::GetCursorSize(); }
};

_property<bool, _readonly> SystemInformation::DbcsEnabled{
  [] {return Native::FormsApi::SystemInformation::GetDbcsEnabled(); }
};

_property<bool, _readonly> SystemInformation::DebugOS{
  [] {return Native::FormsApi::SystemInformation::GetDebugOS(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::DoubleClickSize{
  [] {return Native::FormsApi::SystemInformation::GetDoubleClickSize(); }
};

_property<int32, _readonly> SystemInformation::DoubleClickTime{
  [] {return Native::FormsApi::SystemInformation::GetDoubleClickTime(); }
};

_property<bool, _readonly> SystemInformation::DragFullWindows{
  [] {return Native::FormsApi::SystemInformation::GetDragFullWindows(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::DragSize{
  [] {return Native::FormsApi::SystemInformation::GetDragSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::FixedFrameBorderSize{
  [] {return Native::FormsApi::SystemInformation::GetFixedFrameBorderSize(); }
};

_property<int32, _readonly> SystemInformation::FontSmoothingContrast{
  [] {return Native::FormsApi::SystemInformation::GetFontSmoothingContrast(); }
};

_property<int32, _readonly> SystemInformation::FontSmoothingType{
  [] {return Native::FormsApi::SystemInformation::GetFontSmoothingType(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::FrameBorderSize{
  [] {return Native::FormsApi::SystemInformation::GetFrameBorderSize(); }
};

_property<bool, _readonly> SystemInformation::HighContrast{
  [] {return Native::FormsApi::SystemInformation::GetHighContrast(); }
};

_property<int32, _readonly> SystemInformation::HorizontalFocusThickness{
  [] {return Native::FormsApi::SystemInformation::GetHorizontalFocusThickness(); }
};

_property<int32, _readonly> SystemInformation::HorizontalResizeBorderThickness{
  [] {return Native::FormsApi::SystemInformation::GetHorizontalResizeBorderThickness(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarArrowWidth{
  [] {return Native::FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarHeight{
  [] {return Native::FormsApi::SystemInformation::GetHorizontalScrollBarHeight(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarThumbWidth{
  [] {return Native::FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth(); }
};

_property<int32, _readonly> SystemInformation::IconHorizontalSpacing{
  [] {return Native::FormsApi::SystemInformation::GetIconHorizontalSpacing(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::IconSize{
  [] {return Native::FormsApi::SystemInformation::GetIconSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::IconSpacingSize{
  [] {return Native::FormsApi::SystemInformation::GetIconSpacingSize(); }
};

_property<int32, _readonly> SystemInformation::IconVerticalSpacing{
  [] {return Native::FormsApi::SystemInformation::GetIconVerticalSpacing(); }
};

_property<bool, _readonly> SystemInformation::IsActiveWindowTrackingEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsComboBoxAnimationEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsDropShadowEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsDropShadowEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsFlatMenuEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsFlatMenuEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsFontSmoothingEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsFontSmoothingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsHotTrackingEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsHotTrackingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsIconTitleWrappingEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsKeyboardPreferred{
  [] {return Native::FormsApi::SystemInformation::GetIsKeyboardPreferred(); }
};

_property<bool, _readonly> SystemInformation::IsListBoxSmoothScrollingEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMenuAnimationEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsMenuAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMenuFadeEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsMenuFadeEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMinimizeRestoreAnimationEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsSelectionFadeEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsSelectionFadeEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsSnapToDefaultEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsSnapToDefaultEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsTitleBarGradientEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsTitleBarGradientEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsToolTipAnimationEnabled{
  [] {return Native::FormsApi::SystemInformation::GetIsToolTipAnimationEnabled(); }
};

_property<int32, _readonly> SystemInformation::KanjiWindowHeight{
  [] {return Native::FormsApi::SystemInformation::GetKanjiWindowHeight(); }
};

_property<int32, _readonly> SystemInformation::KeyboardDelay{
  [] {return Native::FormsApi::SystemInformation::GetKeyboardDelay(); }
};

_property<int32, _readonly> SystemInformation::KeyboardSpeed{
  [] {return Native::FormsApi::SystemInformation::GetKeyboardSpeed(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MaxWindowTrackSize{
  [] {return Native::FormsApi::SystemInformation::GetMaxWindowTrackSize(); }
};

_property<bool, _readonly> SystemInformation::MenuAccessKeysUnderlined{
  [] {return Native::FormsApi::SystemInformation::GetMenuAccessKeysUnderlined(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuBarButtonSize{
  [] {return Native::FormsApi::SystemInformation::GetMenuBarButtonSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuButtonSize{
  [] {return Native::FormsApi::SystemInformation::GetMenuButtonSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuCheckSize{
  [] {return Native::FormsApi::SystemInformation::GetMenuCheckSize(); }
};

_property<System::Drawing::Font, _readonly> SystemInformation::MenuFont{
  [] {return Native::FormsApi::SystemInformation::GetMenuFont(); }
};

_property<int32, _readonly> SystemInformation::MenuHeight{
  [] {return Native::FormsApi::SystemInformation::GetMenuHeight(); }
};

