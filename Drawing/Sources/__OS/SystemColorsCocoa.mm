#if defined(__APPLE__) && defined(__use_native_interface__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "DrawingApi.h"

using namespace System;
using namespace __OS;

namespace {
  System::Drawing::Color ToColor(NSColor* color) {
   const CGFloat* components = CGColorGetComponents(color.CGColor);
    return System::Drawing::Color::FromArgb(CGColorGetAlpha(color.CGColor) * 0xFF, components[0] * 0xFF, components[1] * 0xFF, components[2] * 0xFF);
  }
}

int32 DrawingApi::SystemColors::GetActiveBorder() {
  return (int32)0xFFB4B4B4;
}

int32 DrawingApi::SystemColors::GetActiveCaption() {
  return (int32)0xFF99B4D1;
}

int32 DrawingApi::SystemColors::GetActiveCaptionText() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetAppWorkspace() {
  return ToColor(NSColor.underPageBackgroundColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetControl() {
  @autoreleasepool {
    NSColor* color = [[NSColor selectedControlColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
    //return ToColor(NSColor.controlColor).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetControlDark() {
  return ToColor(NSColor.controlShadowColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlDarkDark() {
  return ToColor(NSColor.controlDarkShadowColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlLight() {
  return ToColor(NSColor.controlHighlightColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlLightLight() {
  return ToColor(NSColor.controlLightHighlightColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlText() {
  return ToColor(NSColor.controlTextColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetDesktop() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetGrayText() {
  return (int32)0xFF6D6D6D;
}

int32 DrawingApi::SystemColors::GetHighLight() {
  return (int32)0xFF3399FF;
}

int32 DrawingApi::SystemColors::GetHighLightText() {
  return (int32)0xFFFFFFFF;
}

int32 DrawingApi::SystemColors::GetHotTrack() {
  return (int32)0xFF0066CC;
}

int32 DrawingApi::SystemColors::GetInactiveBorder() {
  return (int32)0xFFF4F7FC;
}

int32 DrawingApi::SystemColors::GetInactiveCaption() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetInactiveCaptionText() {
  return (int32)0xFF434E54;
}

int32 DrawingApi::SystemColors::GetInfo() {
  return (int32)0xFFFFFFE1;
}

int32 DrawingApi::SystemColors::GetInfoText() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetMenu() {
  return (int32)0xFFF0F0F0;
}

int32 DrawingApi::SystemColors::GetMenuText() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetScrollBar() {
  return ToColor(NSColor.scrollBarColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetWindow() {
  return ToColor(NSColor.windowBackgroundColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetWindowFrame() {
  return ToColor(NSColor.windowFrameColor).ToArgb();
}

int32 DrawingApi::SystemColors::GetWindowText() {
  return ToColor(NSColor.windowFrameTextColor).ToArgb();
}

#endif
