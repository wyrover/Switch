#include "../../../../../include/Switch/System/Windows/Forms/SystemInformation.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

_property<int32, _readonly> SystemInformation::ActiveWindowTrackingDelay {
  [] {return Native::SystemInformationApi::GetActiveWindowTrackingDelay();}
};

_property<System::Windows::Forms::ArrangeDirection, _readonly> SystemInformation::ArrangeDirection{
  [] {return Native::SystemInformationApi::GetArrangeDirection(); }
};

_property<System::Windows::Forms::ArrangeStartingPosition, _readonly> SystemInformation::ArrangeStartingPosition{
  [] {return Native::SystemInformationApi::GetArrangeStartingPosition(); }
};

_property<System::Windows::Forms::BootMode, _readonly> SystemInformation::BootMode{
  [] {return Native::SystemInformationApi::GetBootMode(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::Border3DSize{
  [] {return Native::SystemInformationApi::GetBorder3DSize(); }
};

_property<int32, _readonly> SystemInformation::BorderMultiplierFactor{
  [] {return Native::SystemInformationApi::GetBorderMultiplierFactor(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::BorderSize{
  [] {return Native::SystemInformationApi::GetBorderSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::CaptionButtonSize{
  [] {return Native::SystemInformationApi::GetCaptionButtonSize(); }
};

_property<int32, _readonly> SystemInformation::CaptionHeight {
  [] {return Native::SystemInformationApi::GetCaptionHeight();}
};

_property<int32, _readonly> SystemInformation::CaretBlinkTime{
  [] {return Native::SystemInformationApi::GetCaretBlinkTime(); }
};

_property<int32, _readonly> SystemInformation::CaretWidth{
  [] {return Native::SystemInformationApi::GetCaretWidth(); }
};

_property<string, _readonly> SystemInformation::ComputerName{
  [] {return Environment::MachineName(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::CursorSize{
  [] {return Native::SystemInformationApi::GetCursorSize(); }
};

_property<bool, _readonly> SystemInformation::DbcsEnabled{
  [] {return Native::SystemInformationApi::GetDbcsEnabled(); }
};

_property<bool, _readonly> SystemInformation::DebugOS{
  [] {return Native::SystemInformationApi::GetDebugOS(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::DoubleClickSize{
  [] {return Native::SystemInformationApi::GetDoubleClickSize(); }
};

_property<int32, _readonly> SystemInformation::DoubleClickTime{
  [] {return Native::SystemInformationApi::GetDoubleClickTime(); }
};

_property<bool, _readonly> SystemInformation::DragFullWindows{
  [] {return Native::SystemInformationApi::GetDragFullWindows(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::DragSize{
  [] {return Native::SystemInformationApi::GetDragSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::FixedFrameBorderSize{
  [] {return Native::SystemInformationApi::GetFixedFrameBorderSize(); }
};

_property<int32, _readonly> SystemInformation::FontSmoothingContrast{
  [] {return Native::SystemInformationApi::GetFontSmoothingContrast(); }
};

_property<int32, _readonly> SystemInformation::FontSmoothingType{
  [] {return Native::SystemInformationApi::GetFontSmoothingType(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::FrameBorderSize{
  [] {return Native::SystemInformationApi::GetFrameBorderSize(); }
};

_property<bool, _readonly> SystemInformation::HighContrast{
  [] {return Native::SystemInformationApi::GetHighContrast(); }
};

_property<int32, _readonly> SystemInformation::HorizontalFocusThickness{
  [] {return Native::SystemInformationApi::GetHorizontalFocusThickness(); }
};

_property<int32, _readonly> SystemInformation::HorizontalResizeBorderThickness{
  [] {return Native::SystemInformationApi::GetHorizontalResizeBorderThickness(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarArrowWidth{
  [] {return Native::SystemInformationApi::GetHorizontalScrollBarArrowWidth(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarHeight{
  [] {return Native::SystemInformationApi::GetHorizontalScrollBarHeight(); }
};

_property<int32, _readonly> SystemInformation::HorizontalScrollBarThumbWidth{
  [] {return Native::SystemInformationApi::GetHorizontalScrollBarThumbWidth(); }
};

_property<int32, _readonly> SystemInformation::IconHorizontalSpacing{
  [] {return Native::SystemInformationApi::GetIconHorizontalSpacing(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::IconSize{
  [] {return Native::SystemInformationApi::GetIconSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::IconSpacingSize{
  [] {return Native::SystemInformationApi::GetIconSpacingSize(); }
};

_property<int32, _readonly> SystemInformation::IconVerticalSpacing{
  [] {return Native::SystemInformationApi::GetIconVerticalSpacing(); }
};

_property<bool, _readonly> SystemInformation::IsActiveWindowTrackingEnabled{
  [] {return Native::SystemInformationApi::GetIsActiveWindowTrackingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsComboBoxAnimationEnabled{
  [] {return Native::SystemInformationApi::GetIsComboBoxAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsDropShadowEnabled{
  [] {return Native::SystemInformationApi::GetIsDropShadowEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsFlatMenuEnabled{
  [] {return Native::SystemInformationApi::GetIsFlatMenuEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsFontSmoothingEnabled{
  [] {return Native::SystemInformationApi::GetIsFontSmoothingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsHotTrackingEnabled{
  [] {return Native::SystemInformationApi::GetIsHotTrackingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsIconTitleWrappingEnabled{
  [] {return Native::SystemInformationApi::GetIsIconTitleWrappingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsKeyboardPreferred{
  [] {return Native::SystemInformationApi::GetIsKeyboardPreferred(); }
};

_property<bool, _readonly> SystemInformation::IsListBoxSmoothScrollingEnabled{
  [] {return Native::SystemInformationApi::GetIsListBoxSmoothScrollingEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMenuAnimationEnabled{
  [] {return Native::SystemInformationApi::GetIsMenuAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMenuFadeEnabled{
  [] {return Native::SystemInformationApi::GetIsMenuFadeEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsMinimizeRestoreAnimationEnabled{
  [] {return Native::SystemInformationApi::GetIsMinimizeRestoreAnimationEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsSelectionFadeEnabled{
  [] {return Native::SystemInformationApi::GetIsSelectionFadeEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsSnapToDefaultEnabled{
  [] {return Native::SystemInformationApi::GetIsSnapToDefaultEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsTitleBarGradientEnabled{
  [] {return Native::SystemInformationApi::GetIsTitleBarGradientEnabled(); }
};

_property<bool, _readonly> SystemInformation::IsToolTipAnimationEnabled{
  [] {return Native::SystemInformationApi::GetIsToolTipAnimationEnabled(); }
};

_property<int32, _readonly> SystemInformation::KanjiWindowHeight{
  [] {return Native::SystemInformationApi::GetKanjiWindowHeight(); }
};

_property<int32, _readonly> SystemInformation::KeyboardDelay{
  [] {return Native::SystemInformationApi::GetKeyboardDelay(); }
};

_property<int32, _readonly> SystemInformation::KeyboardSpeed{
  [] {return Native::SystemInformationApi::GetKeyboardSpeed(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MaxWindowTrackSize{
  [] {return Native::SystemInformationApi::GetMaxWindowTrackSize(); }
};

_property<bool, _readonly> SystemInformation::MenuAccessKeysUnderlined{
  [] {return Native::SystemInformationApi::GetMenuAccessKeysUnderlined(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuBarButtonSize{
  [] {return Native::SystemInformationApi::GetMenuBarButtonSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuButtonSize{
  [] {return Native::SystemInformationApi::GetMenuButtonSize(); }
};

_property<System::Drawing::Size, _readonly> SystemInformation::MenuCheckSize{
  [] {return Native::SystemInformationApi::GetMenuCheckSize(); }
};

_property<System::Drawing::Font, _readonly> SystemInformation::MenuFont{
  [] {return Native::SystemInformationApi::GetMenuFont(); }
};

_property<int32, _readonly> SystemInformation::MenuHeight{
  [] {return Native::SystemInformationApi::GetMenuHeight(); }
};

