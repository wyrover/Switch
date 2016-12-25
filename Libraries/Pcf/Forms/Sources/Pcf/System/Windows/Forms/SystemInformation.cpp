#include "../../../../../Includes/Pcf/System/Windows/Forms/SystemInformation.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

Property<int32, ReadOnly> SystemInformation::ActiveWindowTrackingDelay {
  [] {return FormsApi::SystemInformation::GetActiveWindowTrackingDelay();}
};

Property<System::Windows::Forms::ArrangeDirection, ReadOnly> SystemInformation::ArrangeDirection{
  [] {return FormsApi::SystemInformation::GetArrangeDirection(); }
};

Property<System::Windows::Forms::ArrangeStartingPosition, ReadOnly> SystemInformation::ArrangeStartingPosition{
  [] {return FormsApi::SystemInformation::GetArrangeStartingPosition(); }
};

Property<System::Windows::Forms::BootMode, ReadOnly> SystemInformation::BootMode{
  [] {return FormsApi::SystemInformation::GetBootMode(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::Border3DSize{
  [] {return FormsApi::SystemInformation::GetBorder3DSize(); }
};

Property<int32, ReadOnly> SystemInformation::BorderMultiplierFactor{
  [] {return FormsApi::SystemInformation::GetBorderMultiplierFactor(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::BorderSize{
  [] {return FormsApi::SystemInformation::GetBorderSize(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::CaptionButtonSize{
  [] {return FormsApi::SystemInformation::GetCaptionButtonSize(); }
};

Property<int32, ReadOnly> SystemInformation::CaptionHeight {
  [] {return FormsApi::SystemInformation::GetCaptionHeight();}
};

Property<int32, ReadOnly> SystemInformation::CaretBlinkTime{
  [] {return FormsApi::SystemInformation::GetCaretBlinkTime(); }
};

Property<int32, ReadOnly> SystemInformation::CaretWidth{
  [] {return FormsApi::SystemInformation::GetCaretWidth(); }
};

Property<string, ReadOnly> SystemInformation::ComputerName{
  [] {return Environment::MachineName(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::CursorSize{
  [] {return FormsApi::SystemInformation::GetCursorSize(); }
};

Property<bool, ReadOnly> SystemInformation::DbcsEnabled{
  [] {return FormsApi::SystemInformation::GetDbcsEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::DebugOS{
  [] {return FormsApi::SystemInformation::GetDebugOS(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::DoubleClickSize{
  [] {return FormsApi::SystemInformation::GetDoubleClickSize(); }
};

Property<int32, ReadOnly> SystemInformation::DoubleClickTime{
  [] {return FormsApi::SystemInformation::GetDoubleClickTime(); }
};

Property<bool, ReadOnly> SystemInformation::DragFullWindows{
  [] {return FormsApi::SystemInformation::GetDragFullWindows(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::DragSize{
  [] {return FormsApi::SystemInformation::GetDragSize(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::FixedFrameBorderSize{
  [] {return FormsApi::SystemInformation::GetFixedFrameBorderSize(); }
};

Property<int32, ReadOnly> SystemInformation::FontSmoothingContrast{
  [] {return FormsApi::SystemInformation::GetFontSmoothingContrast(); }
};

Property<int32, ReadOnly> SystemInformation::FontSmoothingType{
  [] {return FormsApi::SystemInformation::GetFontSmoothingType(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::FrameBorderSize{
  [] {return FormsApi::SystemInformation::GetFrameBorderSize(); }
};

Property<bool, ReadOnly> SystemInformation::HighContrast{
  [] {return FormsApi::SystemInformation::GetHighContrast(); }
};

Property<int32, ReadOnly> SystemInformation::HorizontalFocusThickness{
  [] {return FormsApi::SystemInformation::GetHorizontalFocusThickness(); }
};

Property<int32, ReadOnly> SystemInformation::HorizontalResizeBorderThickness{
  [] {return FormsApi::SystemInformation::GetHorizontalResizeBorderThickness(); }
};

Property<int32, ReadOnly> SystemInformation::HorizontalScrollBarArrowWidth{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth(); }
};

Property<int32, ReadOnly> SystemInformation::HorizontalScrollBarHeight{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarHeight(); }
};

Property<int32, ReadOnly> SystemInformation::HorizontalScrollBarThumbWidth{
  [] {return FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth(); }
};

Property<int32, ReadOnly> SystemInformation::IconHorizontalSpacing{
  [] {return FormsApi::SystemInformation::GetIconHorizontalSpacing(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::IconSize{
  [] {return FormsApi::SystemInformation::GetIconSize(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::IconSpacingSize{
  [] {return FormsApi::SystemInformation::GetIconSpacingSize(); }
};

Property<int32, ReadOnly> SystemInformation::IconVerticalSpacing{
  [] {return FormsApi::SystemInformation::GetIconVerticalSpacing(); }
};

Property<bool, ReadOnly> SystemInformation::IsActiveWindowTrackingEnabled{
  [] {return FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsComboBoxAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsDropShadowEnabled{
  [] {return FormsApi::SystemInformation::GetIsDropShadowEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsFlatMenuEnabled{
  [] {return FormsApi::SystemInformation::GetIsFlatMenuEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsFontSmoothingEnabled{
  [] {return FormsApi::SystemInformation::GetIsFontSmoothingEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsHotTrackingEnabled{
  [] {return FormsApi::SystemInformation::GetIsHotTrackingEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsIconTitleWrappingEnabled{
  [] {return FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsKeyboardPreferred{
  [] {return FormsApi::SystemInformation::GetIsKeyboardPreferred(); }
};

Property<bool, ReadOnly> SystemInformation::IsListBoxSmoothScrollingEnabled{
  [] {return FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsMenuAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsMenuAnimationEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsMenuFadeEnabled{
  [] {return FormsApi::SystemInformation::GetIsMenuFadeEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsMinimizeRestoreAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsSelectionFadeEnabled{
  [] {return FormsApi::SystemInformation::GetIsSelectionFadeEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsSnapToDefaultEnabled{
  [] {return FormsApi::SystemInformation::GetIsSnapToDefaultEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsTitleBarGradientEnabled{
  [] {return FormsApi::SystemInformation::GetIsTitleBarGradientEnabled(); }
};

Property<bool, ReadOnly> SystemInformation::IsToolTipAnimationEnabled{
  [] {return FormsApi::SystemInformation::GetIsToolTipAnimationEnabled(); }
};

Property<int32, ReadOnly> SystemInformation::KanjiWindowHeight{
  [] {return FormsApi::SystemInformation::GetKanjiWindowHeight(); }
};

Property<int32, ReadOnly> SystemInformation::KeyboardDelay{
  [] {return FormsApi::SystemInformation::GetKeyboardDelay(); }
};

Property<int32, ReadOnly> SystemInformation::KeyboardSpeed{
  [] {return FormsApi::SystemInformation::GetKeyboardSpeed(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::MaxWindowTrackSize{
  [] {return FormsApi::SystemInformation::GetMaxWindowTrackSize(); }
};

Property<bool, ReadOnly> SystemInformation::MenuAccessKeysUnderlined{
  [] {return FormsApi::SystemInformation::GetMenuAccessKeysUnderlined(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::MenuBarButtonSize{
  [] {return FormsApi::SystemInformation::GetMenuBarButtonSize(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::MenuButtonSize{
  [] {return FormsApi::SystemInformation::GetMenuButtonSize(); }
};

Property<System::Drawing::Size, ReadOnly> SystemInformation::MenuCheckSize{
  [] {return FormsApi::SystemInformation::GetMenuCheckSize(); }
};

Property<System::Drawing::Font, ReadOnly> SystemInformation::MenuFont{
  [] {return FormsApi::SystemInformation::GetMenuFont(); }
};

Property<int32, ReadOnly> SystemInformation::MenuHeight{
  [] {return FormsApi::SystemInformation::GetMenuHeight(); }
};

