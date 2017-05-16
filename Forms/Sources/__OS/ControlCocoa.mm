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

@interface ControlCocoa : NSControl
- (IBAction) Click:(id)sender;
@end

@implementation ControlCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(__OS::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  System::Drawing::Rectangle bounds = __OS::WindowProcedure::GetBounds(control);
  ControlCocoa *handle = [[[ControlCocoa alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
  [[(NSWindow*)control.Parent()().Handle() contentView] addSubview: handle];
  
  [handle setStringValue:[NSString stringWithUTF8String:control.Text().c_str()]];
  [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [handle setWantsLayer:YES];
  [handle setTarget:handle];
  [handle setAction:@selector(Click:)];
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
  System::Drawing::Point pointToClient = point - control.Location();
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent() != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToClient -= workControl().Location();
  }
  
  if (workControl().Parent != null)
    pointToClient -= workControl().Parent()().Location();
  
  return pointToClient;
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToScreen = point + control.Location();
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToScreen += workControl().Location();
  }
  
  if (workControl().Parent != null)
    pointToScreen += workControl().Parent()().Location();
  
  return pointToScreen;
}

void FormsApi::Control::SetBackColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  if (control) {
    if (is<System::Windows::Forms::Form>(control)) {
      ((NSWindow*)control().Handle()).backgroundColor = CocoaApi::FromColor(control().BackColor);
    } else if (is<System::Windows::Forms::Label>(control)) {
      ((NSTextField*)control().Handle()).backgroundColor = CocoaApi::FromColor(control().BackColor);
    } else if (is<System::Windows::Forms::Panel>(control)) {
      ((NSScrollView*)control().Handle()).backgroundColor = CocoaApi::FromColor(control().BackColor);
    } else {
      [(NSControl*)control().Handle() setWantsLayer:YES];
      ((NSControl*)control().Handle()).layer.backgroundColor = CocoaApi::FromColor(control().BackColor).CGColor;
    }
    
  }
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control)) {
    ((NSWindow*)control.Handle()).backgroundColor = CocoaApi::FromColor(control.BackColor);
  } else if (is<System::Windows::Forms::Label>(control)) {
    ((NSTextField*)control.Handle()).backgroundColor = CocoaApi::FromColor(control.BackColor);
  } else if (is<System::Windows::Forms::Panel>(control)) {
    ((NSScrollView*)control.Handle()).backgroundColor = CocoaApi::FromColor(control.BackColor);
  } else {
    [(NSControl*)control.Handle() setWantsLayer:YES];
    ((NSControl*)control.Handle()).layer.backgroundColor = CocoaApi::FromColor(control.BackColor).CGColor;
  }
}

void FormsApi::Control::SetClientSize(System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Form>(control)) {
      [(NSWindow*)control.Handle() setContentSize:NSMakeSize(control.ClientSize().Width(), control.ClientSize().Height())];
      control.Size = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width, ((NSControl*)control.Handle()).frame.size.height);
    } else  if (is<System::Windows::Forms::Button>(control)) {
      [(NSButton*)control.Handle() setFrameSize:NSMakeSize(control.ClientSize().Width + 12, control.ClientSize().Height + 11)];
      control.Size = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width -12, ((NSControl*)control.Handle()).frame.size.height - 11);
    } else {
      [(NSControl*)control.Handle() setFrameSize:NSMakeSize(control.ClientSize().Width(), control.ClientSize().Height())];
      control.Size = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width, ((NSControl*)control.Handle()).frame.size.height);
    }
  }
}

bool FormsApi::Control::SetFocus(const System::Windows::Forms::Control& control) {
  return true;
}

void FormsApi::Control::SetForeColor(intptr hdc) {
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = CocoaApi::GetBounds(control);
    if (is<System::Windows::Forms::Button>(control))
      [(NSControl*)control.Handle() setFrameOrigin:NSMakePoint(bounds.X()-6, bounds.Y()-6)];
    else
      [(NSControl*)control.Handle() setFrameOrigin:NSMakePoint(bounds.X(), bounds.Y())];
  }
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetSize(System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Form>(control)) {
      ((NSWindow*)control.Handle()).frame.size = NSMakeSize(control.Width, control.Height);
      control.ClientSize = System::Drawing::Size(((NSWindow*)control.Handle()).contentLayoutRect.size.width, ((NSWindow*)control.Handle()).contentLayoutRect.size.height);
    } else if (is<System::Windows::Forms::Button>(control)) {
      [(NSButton*)control.Handle() setFrameSize:NSMakeSize(control.Width() + 12, control.Height() + 11)];
      control.ClientSize = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width -12, ((NSControl*)control.Handle()).frame.size.height - 11);
    } else {
      [(NSControl*)control.Handle() setFrameSize:NSMakeSize(control.Width(), control.Height())];
      control.ClientSize = System::Drawing::Size(((NSControl*)control.Handle()).frame.size.width, ((NSControl*)control.Handle()).frame.size.height);
    }
  }
}

void FormsApi::Control::SetTabStop(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (is<System::Windows::Forms::Button>(control))
      [(NSButton*)control.Handle()  setTitle:[NSString stringWithUTF8String:control.Text().c_str()]];
    else if (is<System::Windows::Forms::Form>(control))
      [(NSWindow*)control.Handle()  setTitle:[NSString stringWithUTF8String:control.Text().c_str()]];
    else if (!is<System::Windows::Forms::Panel>(control) && !is<System::Windows::Forms::ProgressBar>(control))
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

#endif
