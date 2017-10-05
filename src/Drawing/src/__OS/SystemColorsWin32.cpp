#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>

#include "DrawingApi.hpp"

using namespace System;
using namespace __OS;

namespace {
  inline int32 GetSystemColor(int32 index) {
    DWORD color = GetSysColor(index);
    return (int32(0xFF) << 24) + (int32(GetRValue(color)) << 16) + (int32(GetGValue(color)) << 8) + int32(GetBValue(color));
  }
}

int32 DrawingApi::SystemColors::GetActiveBorder() {
  return GetSystemColor(COLOR_ACTIVEBORDER);
}

int32 DrawingApi::SystemColors::GetActiveCaption() {
  return GetSystemColor(COLOR_ACTIVECAPTION);
}

int32 DrawingApi::SystemColors::GetActiveCaptionText() {
  return GetSystemColor(COLOR_CAPTIONTEXT);
}

int32 DrawingApi::SystemColors::GetAppWorkspace() {
  return GetSystemColor(COLOR_APPWORKSPACE);
}

int32 DrawingApi::SystemColors::GetButtonFace() {
  return GetSystemColor(COLOR_BTNFACE);
}

int32 DrawingApi::SystemColors::GetButtonHighlight() {
  return GetSystemColor(COLOR_BTNHIGHLIGHT);
}

int32 DrawingApi::SystemColors::GetButtonShadow() {
  return GetSystemColor(COLOR_BTNSHADOW);
}

int32 DrawingApi::SystemColors::GetControl() {
  return GetSystemColor(COLOR_BTNFACE);
}

int32 DrawingApi::SystemColors::GetControlDark() {
  return GetSystemColor(COLOR_BTNSHADOW);
}

int32 DrawingApi::SystemColors::GetControlDarkDark() {
  return GetSystemColor(COLOR_3DDKSHADOW);
}

int32 DrawingApi::SystemColors::GetControlLight() {
  return GetSystemColor(COLOR_3DLIGHT);
}

int32 DrawingApi::SystemColors::GetControlLightLight() {
  return GetSystemColor(COLOR_BTNHIGHLIGHT);
}

int32 DrawingApi::SystemColors::GetControlText() {
  return GetSystemColor(COLOR_BTNTEXT);
}

int32 DrawingApi::SystemColors::GetDesktop() {
  return GetSystemColor(COLOR_DESKTOP);
}

int32 DrawingApi::SystemColors::GetGradientActiveCaption() {
  return GetSystemColor(COLOR_GRADIENTACTIVECAPTION);
}

int32 DrawingApi::SystemColors::GetGradientInactiveCaption() {
  return GetSystemColor(COLOR_GRADIENTINACTIVECAPTION);
}

int32 DrawingApi::SystemColors::GetGrayText() {
  return GetSystemColor(COLOR_GRAYTEXT);
}

int32 DrawingApi::SystemColors::GetHighlight() {
  return GetSystemColor(COLOR_HIGHLIGHT);
}

int32 DrawingApi::SystemColors::GetHighlightText() {
  return GetSystemColor(COLOR_HIGHLIGHTTEXT);
}

int32 DrawingApi::SystemColors::GetHotTrack() {
  return GetSystemColor(COLOR_HOTLIGHT);
}

int32 DrawingApi::SystemColors::GetInactiveBorder() {
  return GetSystemColor(COLOR_INACTIVEBORDER);
}

int32 DrawingApi::SystemColors::GetInactiveCaption() {
  return GetSystemColor(COLOR_INACTIVECAPTION);
}

int32 DrawingApi::SystemColors::GetInactiveCaptionText() {
  return GetSystemColor(COLOR_INACTIVECAPTIONTEXT);
}

int32 DrawingApi::SystemColors::GetInfo() {
  return GetSystemColor(COLOR_INFOBK);
}

int32 DrawingApi::SystemColors::GetInfoText() {
  return GetSystemColor(COLOR_INFOTEXT);
}

int32 DrawingApi::SystemColors::GetMenu() {
  return GetSystemColor(COLOR_MENU);
}

int32 DrawingApi::SystemColors::GetMenuBar() {
  return GetSystemColor(COLOR_MENUBAR);
}

int32 DrawingApi::SystemColors::GetMenuHighlight() {
  return GetSystemColor(COLOR_MENUHILIGHT);
}

int32 DrawingApi::SystemColors::GetMenuText() {
  return GetSystemColor(COLOR_MENUTEXT);
}

int32 DrawingApi::SystemColors::GetScrollBar() {
  return GetSystemColor(COLOR_SCROLLBAR);
}

int32 DrawingApi::SystemColors::GetWindow() {
  return GetSystemColor(COLOR_WINDOW);
}

int32 DrawingApi::SystemColors::GetWindowFrame() {
  return GetSystemColor(COLOR_WINDOWFRAME);
}

int32 DrawingApi::SystemColors::GetWindowText() {
  return GetSystemColor(COLOR_WINDOWTEXT);
}

#endif
