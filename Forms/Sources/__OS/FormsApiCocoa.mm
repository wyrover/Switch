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
    
    static System::Drawing::Rectangle GetBounds(const System::Windows::Forms::Control& control) {
      if (is<System::Windows::Forms::Form>(control))
        return GetBounds(as<System::Windows::Forms::Form>(control));
      return System::Drawing::Rectangle(control.Bounds().X, control.Parent()().Bounds().Height - control.Bounds().Height - control.Bounds().Y - GetCaptionHeight(control.Parent()()), control.Bounds().Width, control.Bounds().Height);
    }
    
    static Drawing::Rectangle GetBounds(const System::Windows::Forms::Form& form) {
      switch (form.StartPosition) {
        case FormStartPosition::CenterParent: return Drawing::Rectangle(0, screenHeight - form.Bounds().Y, form.Width, form.Height);
        case FormStartPosition::CenterScreen: return Drawing::Rectangle(0, screenHeight, form.Width, form.Height);
        case FormStartPosition::Manual: return Drawing::Rectangle(form.Bounds().X, screenHeight - form.Bounds().Y, form.Bounds().Width, form.Bounds().Height);
        case FormStartPosition::WindowsDefaultBounds: return Drawing::Rectangle(0, screenHeight, 300, 300);
        case FormStartPosition::WindowsDefaultLocation: return Drawing::Rectangle(0, screenHeight, form.Width, form.Height);
      }
      return Drawing::Rectangle(0, screenHeight - 300, 300, 300);
    }
    
    static int32 GetCaptionHeight(const System::Windows::Forms::Control& control) {
      return !is<Form>(control) || as<Form>(control).FormBorderStyle == FormBorderStyle::None ? 0 : FormsApi::SystemInformation::GetCaptionHeight();
    }
    
  private:
    static const int32 screenHeight = 1050; // TO DO : Get Screen height...
  };
}

@interface NSControlResponder : NSObject
- (IBAction) ControlClick:(id)sender;
- (IBAction) FormClose:(id)sender;
@end

@implementation NSControlResponder
- (IBAction) ControlClick:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(__OS::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}

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
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(form);
    NSWindow* handle = [[NSWindow alloc] init];
    
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

intptr FormsApi::Label::Create(const System::Windows::Forms::Label& label) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(label);
    NSTextField* handle;
    handle = [[NSTextField alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())];
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
    
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    __OS::WindowProcedure::Controls[(intptr)handle] = label;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Label&>(label).WndProc(message);
    return (intptr)handle;
  }
}

intptr FormsApi::Panel::Create(const System::Windows::Forms::Panel& panel) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(panel);
    NSScrollView* handle = [[[NSScrollView alloc]  initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)panel.Parent()().Handle() contentView] addSubview: handle];
   
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    //handle.color = CocoaApi::FromColor(panel.ForeColor);
    __OS::WindowProcedure::Controls[(intptr)handle] = panel;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Panel&>(panel).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  switch (panel.BorderStyle) {
    case BorderStyle::None : [(NSScrollView*)panel.Handle() setBorderType:NSNoBorder]; break;
    case BorderStyle::FixedSingle : [(NSScrollView*)panel.Handle() setBorderType:NSLineBorder]; break;
    case BorderStyle::Fixed3D : [(NSScrollView*)panel.Handle() setBorderType:NSBezelBorder]; break;
  }
}

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(progressBar);
    NSProgressIndicator* handle = [[[NSProgressIndicator alloc]  initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)progressBar.Parent()().Handle() contentView] addSubview: handle];

    __OS::WindowProcedure::Controls[(intptr)handle] = progressBar;
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setIndeterminate:false];
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::ProgressBar&>(progressBar).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setMaxValue:progressBar.Maximum()];
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setMinValue:progressBar.Minimum()];
}

void FormsApi::ProgressBar::SetStyle(const System::Windows::Forms::ProgressBar& progressBar) {
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setDoubleValue:progressBar.Value()];
}

intptr FormsApi::RadioButton::Create(const System::Windows::Forms::RadioButton& radioButton) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(radioButton);
    NSButton *handle = [[[NSButton alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)radioButton.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:radioButton.Text().c_str()]];
    [handle setButtonType:NSButtonTypeRadio];
    [handle setBezelStyle:NSBezelStyleRegularSquare];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    __OS::WindowProcedure::Controls[(intptr)handle] = radioButton;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::RadioButton&>(radioButton).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::RadioButton::SetAutoCheck(const System::Windows::Forms::RadioButton& radioButton) {
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  [(NSButton*)radioButton.Handle() setState:radioButton.Checked()];
}

#endif
