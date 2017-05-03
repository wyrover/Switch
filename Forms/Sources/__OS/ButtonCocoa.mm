#if defined(__APPLE__) && defined(__use_native_interface__)
#include "WindowProcedureCocoa.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  class CocoaApi pcf_static {
  public:
    static System::Drawing::Rectangle GetControlBounds(const System::Windows::Forms::Control& control) {
      int32 captionHeight = !is<System::Windows::Forms::Form>(control.Parent()()) || as<System::Windows::Forms::Form>(control.Parent()()).FormBorderStyle == FormBorderStyle::None ? 0 : FormsApi::SystemInformation::GetCaptionHeight();
      return System::Drawing::Rectangle(control.Bounds().X, control.Parent()().Bounds().Height - control.Bounds().Height - control.Bounds().Y - captionHeight, control.Bounds().Width, control.Bounds().Height);
    }
  };
}

@interface NSButtonControlResponder : NSButton
- (IBAction) Click:(id)sender;
@end

@implementation NSButtonControlResponder
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(__OS::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

@interface ButtonCocoa : NSButton
@end

@implementation ButtonCocoa

@end

intptr FormsApi::Button::Create(const System::Windows::Forms::Button& button) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetControlBounds(button);
    ButtonCocoa *handle = [[[ButtonCocoa alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)button.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:button.Text().c_str()]];
    [handle setButtonType:NSButtonTypeMomentaryPushIn];
    [handle setBezelStyle:bounds.Height == 25 ? NSBezelStyleRounded : NSBezelStyleRegularSquare];
    [handle setTarget:[NSButtonControlResponder alloc]];
    [handle setAction:@selector(Click:)];
    __OS::WindowProcedure::Controls[(intptr)handle] = button;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Button&>(button).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::Button::SetIsDefault(const System::Windows::Forms::Button& button) {
  
}

#endif
