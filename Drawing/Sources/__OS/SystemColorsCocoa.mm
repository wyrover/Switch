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
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetActiveCaption() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetActiveCaptionText() {
  @autoreleasepool {
    NSColor* color = [[NSColor textColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetAppWorkspace() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlBackgroundColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetButtonFace() {
  @autoreleasepool {
    NSColor* color = [[NSColor knobColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetButtonHighlight() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetButtonShadow() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlShadowColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetControl() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetControlDark() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlShadowColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetControlDarkDark() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlDarkShadowColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetControlLight() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetControlLightLight() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlLightHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetControlText() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetDesktop() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetGradientActiveCaption() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetGradientInactiveCaption() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetGrayText() {
  @autoreleasepool {
    NSColor* color = [[NSColor disabledControlTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetHighlight() {
  @autoreleasepool {
    NSColor* color = [[NSColor selectedControlColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetHighlightText() {
  @autoreleasepool {
    NSColor* color = [[NSColor selectedTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetHotTrack() {
  @autoreleasepool {
    NSColor* color = [[NSColor secondarySelectedControlColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetInactiveBorder() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetInactiveCaption() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetInactiveCaptionText() {
  @autoreleasepool {
    NSColor* color = [[NSColor disabledControlTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetInfo() {
  return (int32)0xFFFFFFE1;
}

int32 DrawingApi::SystemColors::GetInfoText() {
  @autoreleasepool {
    NSColor* color = [[NSColor textColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetMenu() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetMenuBar() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetMenuHighlight() {
  @autoreleasepool {
    NSColor* color = [[NSColor selectedMenuItemColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetMenuText() {
  @autoreleasepool {
    NSColor* color = [[NSColor textColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetScrollBar() {
  @autoreleasepool {
    NSColor* color = [[NSColor scrollBarColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetWindow() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetWindowFrame() {
  @autoreleasepool {
    NSColor* color = [[NSColor windowFrameColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 DrawingApi::SystemColors::GetWindowText() {
  @autoreleasepool {
    NSColor* color = [[NSColor windowFrameTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

#endif
