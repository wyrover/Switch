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
    
    static NSColor* FromColor(const System::Drawing::Color& color) {
      return [NSColor colorWithCalibratedRed:as<float>(color.R()) / 0xFF green:as<float>(color.G()) / 0xFF blue:as<float>(color.B()) / 0xFF alpha:as<float>(color.A()) / 0xFF];
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

intptr FormsApi::CheckBox::Create(const System::Windows::Forms::CheckBox& checkBox) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(checkBox);
    NSButton *handle = [[[NSButton alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)checkBox.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:checkBox.Text().c_str()]];
    [handle setButtonType:NSButtonTypeSwitch];
    [handle setBezelStyle:NSBezelStyleRegularSquare];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
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

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
  [(NSWindow*)form.Handle() close];
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  System::Drawing::Rectangle bounds = CocoaApi::GetBounds(control);
  NSControl *handle = [[[NSControl alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
  [[(NSWindow*)control.Parent()().Handle() contentView] addSubview: handle];
  
  [handle setStringValue:[NSString stringWithUTF8String:control.Text().c_str()]];
  [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [handle setWantsLayer:YES];
  [handle setTarget:[NSControlResponder alloc]];
  [handle setAction:@selector(ControlClick:)];
  __OS::WindowProcedure::Controls[(intptr)handle] = control;
  Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
  const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
  return (intptr)handle;
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
  @autoreleasepool {
    NSEvent* event = (NSEvent*)message.Handle();
    if (event.type == NSEventTypeKeyUp)
      [[NSApp keyWindow] sendEvent:event];
    else
      [NSApp sendEvent:event];
  }
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  __OS::WindowProcedure::Controls.Remove(control.Handle);
  Message message = Message::Create(control.Handle, WM_DESTROY, 0, 0, 0, IntPtr::Zero);
  const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return System::Drawing::Point();
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return System::Drawing::Point();
}

void FormsApi::Control::SetBackColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  [(NSControl*)hdc setWantsLayer:YES];
  ((NSControl*)hdc).layer.backgroundColor = CocoaApi::FromColor(control().BackColor()).CGColor;
}

void FormsApi::Control::SetForeColor(intptr hdc) {
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control)) {
    ((NSWindow*)control.Handle()).backgroundColor = CocoaApi::FromColor(control.BackColor);
  } else {
    [(NSControl*)control.Handle() setWantsLayer:YES];
    ((NSControl*)control.Handle()).layer.backgroundColor = CocoaApi::FromColor(control.BackColor).CGColor;
  }
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(control);
    [(NSControl*)control.Handle() setFrameOrigin:NSMakePoint(bounds.X(), bounds.Y())];
  }
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Form>(control)) {
      System::Drawing::Rectangle bounds = CocoaApi::GetBounds(control);
      [(NSWindow*)control.Handle() setFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height()) display:YES];
      [(NSWindow*)control.Handle() setFrameTopLeftPoint:NSMakePoint(bounds.X(), bounds.Y())];
    } else {
      [(NSControl*)control.Handle() setFrameSize:NSMakeSize(control.Width(), control.Height())];
      if (is<System::Windows::Forms::Button>(control))
        [(NSButton*)control.Handle() setBezelStyle: control.Height() == 25 ? NSBezelStyleRounded : NSBezelStyleRegularSquare];
    }
  }
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Button>(control))
      [(NSButton*)control.Handle()  setTitle:[NSString stringWithUTF8String:control.Text().c_str()]];
    else if (is<System::Windows::Forms::Form>(control))
      [(NSWindow*)control.Handle()  setTitle:[NSString stringWithUTF8String:control.Text().c_str()]];
    else
      [(NSControl*)control.Handle()  setStringValue:[NSString stringWithUTF8String:control.Text().c_str()]];
  }
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Form>(control)) {
      if (control.Visible ) {
        [(NSWindow*)control.Handle() makeKeyAndOrderFront:NSApp];
        [NSApp activateIgnoringOtherApps:YES];
      } else {
        [(NSWindow*)control.Handle() orderOut:nil];
      }
    } else
      [(NSControl*)control.Handle() setHidden:control.Visible ? NO : YES];
  }
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
    handle.backgroundColor = CocoaApi::FromColor(label.BackColor);
    handle.textColor = CocoaApi::FromColor(label.ForeColor);
    
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
    NSScrollView* handle = [[NSScrollView alloc] init];
    [[(NSWindow*)panel.Parent()().Handle() contentView] addSubview: handle];
   
    //[handle setStyleMask: CocoaApi::FormToNSWindowStyleMask(NSPanel)];
    [handle setFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())];
    //[handle setFrameTopLeftPoint:NSMakePoint(bounds.X(), bounds.Y())];

    switch (panel.BorderStyle) {
      case BorderStyle::None : [handle setBorderType:NSNoBorder]; break;
      case BorderStyle::FixedSingle : [handle setBorderType:NSLineBorder]; break;
      case BorderStyle::Fixed3D : [handle setBorderType:NSBezelBorder]; break;
    }
    [handle setBorderType:NSBezelBorder];
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
    NSProgressIndicator* handle = [[NSProgressIndicator alloc] init];
    [[(NSWindow*)progressBar.Parent()().Handle() contentView] addSubview: handle];
    [handle setFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())];
    [NSApp activateIgnoringOtherApps:YES];
    __OS::WindowProcedure::Controls[(intptr)handle] = progressBar;
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
