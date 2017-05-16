#if defined(__APPLE__) && defined(__use_native_interface__)
#include "WindowProcedureCocoa.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

@interface CheckBoxCocoa : NSButton
- (IBAction) Click:(id)sender;
@end

@implementation CheckBoxCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(__OS::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr FormsApi::CheckBox::Create(const System::Windows::Forms::CheckBox& checkBox) {
  @autoreleasepool {
    CheckBoxCocoa *handle = [[[CheckBoxCocoa alloc] init] autorelease];
    [[(NSWindow*)checkBox.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:checkBox.Text().c_str()]];
    [handle setButtonType:NSButtonTypeSwitch];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:handle];
    [handle setAction:@selector(Click:)];
    __OS::WindowProcedure::Controls[(intptr)handle] = checkBox;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::CheckBox&>(checkBox).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::CheckBox::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
}

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  [(NSButton*)checkBox.Handle() setState:checkBox.Checked()];
}

#endif
