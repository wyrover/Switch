#if defined(_WIN32) && defined(__use_native_interface__)

#include <Windows.hpp>
#include <Windowsx.hpp>
#include <Uxtheme.hpp>
#include <Pcf/Undef.hpp>

#include "FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

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
