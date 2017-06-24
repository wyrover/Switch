#if defined(__APPLE__)
#include "WindowProcedureCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

@interface LabelCocoa : NSTextField
- (IBAction) Click:(id)sender;
@end

@implementation LabelCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(__OS::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr FormsApi::Label::Create(const System::Windows::Forms::Label& label) {
  @autoreleasepool {
    LabelCocoa* handle = [[LabelCocoa alloc] init];
    [[(NSWindow*)label.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setStringValue:[NSString stringWithUTF8String:label.Text().c_str()]];
    [handle setBezeled:NO];
    [handle setDrawsBackground:NO];
    [handle setEditable:NO];
    [handle setSelectable:NO];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    handle.drawsBackground = TRUE;
    //handle.backgroundColor = CocoaApi::FromColor(label.BackColor);
    //handle.textColor = CocoaApi::FromColor(label.ForeColor);
    
    [handle setTarget:handle];
    [handle setAction:@selector(Click:)];
    __OS::WindowProcedure::Controls[(intptr)handle] = label;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Label&>(label).WndProc(message);
    return (intptr)handle;
  }
}

#endif
