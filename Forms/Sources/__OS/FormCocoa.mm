#if defined(__APPLE__) && defined(__use_native_interface__)
#include "WindowProcedureCocoa.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  class CocoaApi pcf_static {
  public:
    static NSWindowStyleMask FormToNSWindowStyleMask(const Form& form) {
      constexpr int CP_NOCLOSE_BUTTON = 0x200;
      NSWindowStyleMask windowStyleMask = NSWindowStyleMaskBorderless;
      
      if (form.FormBorderStyle != FormBorderStyle::None) {
        windowStyleMask |= NSWindowStyleMaskTitled;
        
        if (form.MaximizeBox && (form.FormBorderStyle == FormBorderStyle::Sizable || form.FormBorderStyle == FormBorderStyle::SizableToolWindow))
          windowStyleMask |= NSWindowStyleMaskResizable;
        
        if (form.MinimizeBox)
          windowStyleMask |= NSWindowStyleMaskMiniaturizable;
        
        if (CP_NOCLOSE_BUTTON /*(form.GetCreateParams().ClassStyle | CP_NOCLOSE_BUTTON) == CP_NOCLOSE_BUTTON*/)
          windowStyleMask |= NSWindowStyleMaskClosable;
      }
      
      return windowStyleMask;
    }
  };
}

@interface FormCocoa : NSWindow
- (IBAction) FormClose:(id)sender;
@end

@implementation FormCocoa
- (IBAction) FormClose:(id)sender {
  Message event = Message::Create((intptr)sender, WM_CLOSE, 0, 0, 0, 0);
  const_cast<Control&>(__OS::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

void FormsApi::Form::Close(const System::Windows::Forms::Form& form) {
  [(NSWindow*)form.Handle() close];
}

intptr FormsApi::Form::Create(const System::Windows::Forms::Form& form) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = __OS::WindowProcedure::GetBounds(form);
    FormCocoa* handle = [[FormCocoa alloc] init];
    
    [handle setStyleMask: CocoaApi::FormToNSWindowStyleMask(form)];
    [handle setFrame:NSMakeRect(0, 0, bounds.Width(), bounds.Height()) display:YES];
    [handle setFrameTopLeftPoint:NSMakePoint(bounds.X(), bounds.Y())];
    
    [handle setTitle:[NSString stringWithUTF8String:form.Text().c_str()]];
    [handle makeKeyAndOrderFront:nil];
    [NSApp activateIgnoringOtherApps:YES];
    //handle.color = CocoaApi::FromColor(form.ForeColor);
    __OS::WindowProcedure::Controls[(intptr)handle] = form;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Form&>(form).WndProc(message);
    return (intptr)handle;
  }
}

#endif
