#if defined(__APPLE__) && defined(__use_native_interface__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/System/Console.h>
#include <Pcf/System/Convert.h>
#include <Pcf/System/NotImplementedException.h>
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/Collections/Generic/Dictionary.h>
#include <Pcf/System/Collections/Generic/Queue.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "FormsApi.h"
#include "WindowMessageKey.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  class CocoaApi {
  public:
    using ControlDictionary = System::Collections::Generic::Dictionary<intptr, Ref<Control>>;
    CocoaApi() {
      this->CreateAppication();
      this->CreateMenuBar();
    }
    
    Property<ControlDictionary&> Controls {
      pcf_get->ControlDictionary& {return this->controls;},
      pcf_set {this->controls = value;}
    };
    
    NSWindowStyleMask FormToNSWindowStyleMask(const Form& form) {
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
    
    NSColor* FromColor(const System::Drawing::Color& color) {
      return [NSColor colorWithCalibratedRed:as<float>(color.R()) / 0xFF green:as<float>(color.G()) / 0xFF blue:as<float>(color.B()) / 0xFF alpha:as<float>(color.A()) / 0xF];
      //return [NSColor colorWithCalibratedRed:as<float>(color.R()) / 0xFF green:as<float>(color.G()) / 0xFF blue:as<float>(color.B()) / 0xFF alpha:1.0];
    }
    
    System::Drawing::Rectangle GetBounds(const System::Windows::Forms::Control& control) {
      if (is<System::Windows::Forms::Form>(control))
        return this->GetBounds(as<System::Windows::Forms::Form>(control));
      return System::Drawing::Rectangle(control.Bounds().X, control.Parent()().Bounds().Height - control.Bounds().Height - control.Bounds().Y - GetCaptionHeight(control.Parent()()), control.Bounds().Width, control.Bounds().Height);
    }
    
    Drawing::Rectangle GetBounds(const System::Windows::Forms::Form& form) {
      switch (form.StartPosition) {
        case FormStartPosition::CenterParent: return Drawing::Rectangle(0, screenHeight - form.Bounds().Y, form.Width, form.Height);
        case FormStartPosition::CenterScreen: return Drawing::Rectangle(0, screenHeight, form.Width, form.Height);
        case FormStartPosition::Manual: return Drawing::Rectangle(form.Bounds().X, screenHeight - form.Bounds().Y, form.Bounds().Width, form.Bounds().Height);
        case FormStartPosition::WindowsDefaultBounds: return Drawing::Rectangle(0, screenHeight, 300, 300);
        case FormStartPosition::WindowsDefaultLocation: return Drawing::Rectangle(0, screenHeight, form.Width, form.Height);
      }
      return Drawing::Rectangle(0, screenHeight - 300, 300, 300);
    }
    
    int32 GetCaptionHeight(const System::Windows::Forms::Control& control) {
      return !is<Form>(control) || as<Form>(control).FormBorderStyle == FormBorderStyle::None ? 0 : FormsApi::SystemInformation::GetCaptionHeight();
    }
    
    int32 GetMouseButtonState(NSEvent* event) {
      int32 state = 0;
      
      if ([event buttonNumber] == 1)
        state &= MK_LBUTTON;
      if ([event buttonNumber] == 2)
        state &= MK_MBUTTON;
      if ([event buttonNumber] == 3)
        state &= MK_RBUTTON;
      
      return state;
    }
    
    int32 GetMouseXCoordinateRelativeToClientArea(NSEvent* event, Control& control) {
      System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - GetCaptionHeight(control));
      return location.X;
    }
    
    int32 GetMouseYCoordinateRelativeToClientArea(NSEvent* event, Control& control) {
      System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - GetCaptionHeight(control));
      return location.Y;
    }

    void MessageLoop(EventHandler idle) {
      @autoreleasepool {
        this->messageLoopRunning = true;
        while (messageLoopRunning) {
          NSEvent* event = idle.IsEmpty() ? this->GetMessage() : this->PeekMessage();
          if (event != nil) {
            DispatchMessage(event);
          } else
            idle(object(), EventArgs());
        }
      }
    }
    
  private:
    void CreateAppication() {
      @autoreleasepool {
        [NSApplication sharedApplication];
        [NSApp finishLaunching];
        this->IgnoreMessages();
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
      }
    }

    void CreateMenuBar() {
      static BOOL donethat = NO;
      if (donethat) return;
      donethat = YES;
      NSMenu *mainmenu, *services = nil, *appleMenu;
      NSMenuItem *menuItem;
      NSString *title;
      
      NSString *nsappname = [[[NSBundle mainBundle] performSelector:@selector(localizedInfoDictionary)] objectForKey:@"CFBundleName"];
      if (nsappname == nil)
        nsappname = [[NSProcessInfo processInfo] processName];
      appleMenu = [[NSMenu alloc] initWithTitle:@""];
      /* Add menu items */
      title = [NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"About %@"],nil), nsappname];
      //menuItem = [appleMenu addItemWithTitle:title action:@selector(showPanel) keyEquivalent:@""];
      //FLaboutItemTarget *about = [[FLaboutItemTarget alloc] init];
      //[menuItem setTarget:about];
      [appleMenu addItem:[NSMenuItem separatorItem]];
      // Print front window
      title = NSLocalizedString([NSString stringWithUTF8String:"Print Front Window"], nil);
      if ([title length] > 0) {
        menuItem = [appleMenu addItemWithTitle:title action:@selector(printPanel) keyEquivalent:@""];
        //[menuItem setTarget:about];
        [menuItem setEnabled:YES];
        [appleMenu addItem:[NSMenuItem separatorItem]];
      }
      // Services Menu
      services = [[NSMenu alloc] initWithTitle:@""];
      menuItem = [appleMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Services"], nil) action:nil keyEquivalent:@""];
      [appleMenu setSubmenu:services forItem:menuItem];
      [appleMenu addItem:[NSMenuItem separatorItem]];
      // Hide AppName
      title = [NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"Hide %@"],nil), nsappname];
      [appleMenu addItemWithTitle:title action:@selector(hide:) keyEquivalent:@"h"];
      // Hide Others
      menuItem = [appleMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Hide Others"] , nil) action:@selector(hideOtherApplications:) keyEquivalent:@"h"];
      [menuItem setKeyEquivalentModifierMask:(NSEventModifierFlagOption|NSEventModifierFlagCommand)];
      // Show All
      [appleMenu addItemWithTitle:NSLocalizedString([NSString stringWithUTF8String:"Show All"] , nil) action:@selector(unhideAllApplications:) keyEquivalent:@""];
      [appleMenu addItem:[NSMenuItem separatorItem]];
      // Quit AppName
      title = [NSString stringWithFormat:NSLocalizedString([NSString stringWithUTF8String:"Quit %@"] , nil), nsappname];
      menuItem = [appleMenu addItemWithTitle:title action:@selector(terminate:) keyEquivalent:@"q"];
      //[menuItem setTarget:about];
      
      /* Put menu into the menubar */
      menuItem = [[NSMenuItem alloc] initWithTitle:@"" action:nil keyEquivalent:@""];
      [menuItem setSubmenu:appleMenu];
      mainmenu = [[NSMenu alloc] initWithTitle:@""];
      [mainmenu addItem:menuItem];
      [NSApp setMainMenu:mainmenu];
      if (services) {
        [NSApp setServicesMenu:services];
        [services release];
      }
      [mainmenu release];
      [appleMenu release];
      [menuItem release];
    }
    
    void DispatchMessage(NSEvent* event) {
      /*
       //{NSEventTypeLeftMouseDragged, WM_...},
       //{NSEventTypeRightMouseDragged, WM_...},
       {NSEventTypeKeyDown, WM_KEYDOWN},
       {NSEventTypeKeyUp, WM_KEYUP},
       //{NSEventTypeFlagsChanged, WM_...},
       //{NSEventTypeAppKitDefined, WM_...},
       //{NSEventTypeSystemDefined, WM_...},
       //{NSEventTypeApplicationDefined, WM_...},
       //{NSEventTypePeriodic, WM_...},
       {NSEventTypeCursorUpdate, WM_SETCURSOR},
       {NSEventTypeScrollWheel, WM_MOUSEWHEEL},
       //{NSEventTypeTabletPoint, WM_...},
       //{NSEventTypeTabletProximity, WM_...},
       //{NSEventTypeOtherMouseDragged, WM_...},
       */
      static System::Collections::Generic::SortedDictionary<int32, delegate<void, NSEvent*, Control&>> events = {
        {NSEventTypeMouseEntered, {*this, &CocoaApi::MouseEnterEvent}},
        {NSEventTypeMouseExited, {*this, &CocoaApi::MouseLeaveEvent}},
        {NSEventTypeLeftMouseDown, {*this, &CocoaApi::LeftMouseDownEvent}},
        {NSEventTypeLeftMouseUp, {*this, &CocoaApi::LeftMouseUpEvent}},
        {NSEventTypeRightMouseDown, {*this, &CocoaApi::RightMouseDownEvent}},
        {NSEventTypeRightMouseUp, {*this, &CocoaApi::RightMouseUpEvent}},
        {NSEventTypeMouseMoved, {*this, &CocoaApi::MouseMoveEvent}},
        {NSEventTypeOtherMouseDown, {*this, &CocoaApi::OtherMouseDownEvent}},
        {NSEventTypeOtherMouseUp, {*this, &CocoaApi::OtherMouseUpEvent}}
      };
      @autoreleasepool {
        if (events.ContainsKey([event type]) && controls.ContainsKey((intptr)[event window])) {
          events[[event type]](event, this->controls[(intptr)[event window]]);
        } else {
          [NSApp sendEvent:event];
        }
      }
    }
    
    NSEvent* GetMessage() const {
      @autoreleasepool {
        return [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate dateWithTimeIntervalSinceNow:Double::MaxValue] inMode:NSDefaultRunLoopMode dequeue:YES];
      }
    }
    
    void IgnoreMessages() const {
      @autoreleasepool {
        NSEvent *ignoredEvent;
        do
          ignoredEvent = [NSApp nextEventMatchingMask:(NSEventMaskAny & ~NSEventMaskSystemDefined) untilDate:[NSDate dateWithTimeIntervalSinceNow:0] inMode:NSDefaultRunLoopMode dequeue:YES];
        while (ignoredEvent);
      }
    }
    
    NSEvent* PeekMessage() const {
      @autoreleasepool {
        return [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate dateWithTimeIntervalSinceNow:0.0] inMode:NSDefaultRunLoopMode dequeue:YES];
      }
    }
    
    void MouseEnterEvent(NSEvent* event, Control& control) {
      Message message = Message::Create((intptr)event.window, WM_MOUSEENTER, notUsed, notUsed, 0, (intptr)event);
      hover = true;
      return control.WndProc(message);
    }
    
    void MouseLeaveEvent(NSEvent* event, Control& control) {
      Message message = Message::Create((intptr)event.window, WM_MOUSELEAVE, notUsed, notUsed, 0, (intptr)event);
      hover = false;
      return control.WndProc(message);
    }
    
    void LeftMouseDownEvent(NSEvent* event, Control& control) {
      Message message = Message::Create((intptr)event.window, WM_LBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    void LeftMouseUpEvent(NSEvent* event, Control& control) {
      Message message = Message::Create((intptr)event.window, WM_LBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    void OtherMouseUpEvent(NSEvent* event, Control& control) {
      Message message = Message::Create((intptr)event.window, WM_MBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    void OtherMouseDownEvent(NSEvent* event, Control& control) {
      Message message = Message::Create((intptr)event.window, WM_MBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    void RightMouseDownEvent(NSEvent* event, Control& control) {
      Message message = Message::Create((intptr)event.window, WM_RBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    void RightMouseUpEvent(NSEvent* event, Control& control) {
      Message message = Message::Create((intptr)event.window, WM_RBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    void MouseMoveEvent(NSEvent* event, Control& control) {
      if (hover) {
        Message message = Message::Create((intptr)event.window, WM_MOUSEHOVER, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
        control.WndProc(message);
      }
      Message message = Message::Create((intptr)event.window, WM_MOUSEMOVE, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }

    bool messageLoopRunning = false;
    static const int32 notUsed = 0;
    ControlDictionary controls;
    bool hover = false;
    int32 screenHeight = 1050; // TO DO : Get Screen height...
  };
  
  UniquePointer<CocoaApi> cocoaApi;
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::AddForm(const System::Windows::Forms::Form& form) {
}

void FormsApi::Application::Exit() {
  Environment::Exit(0);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  cocoaApi().MessageLoop(idle);
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
  @autoreleasepool {
    System::Collections::Generic::SortedDictionary<MessageBoxIcon, string> beep = {{(MessageBoxIcon)0, "Funk"}, {MessageBoxIcon::Error, "Sosumi"}, {MessageBoxIcon::Question, "Purr"}, {MessageBoxIcon::Warning, "Hero"}, {MessageBoxIcon::Information, "Glass"}, {(MessageBoxIcon)0xFFFFFFFF, "Funk"}};
    [[NSSound soundNamed:[NSString stringWithUTF8String:beep[type].c_str()]] play];
  }
}

namespace {
  void MessageBoxAddButtonsOK(NSAlert *alert) {
    [alert addButtonWithTitle:@"OK"];
  }
  
  void MessageBoxAddButtonsOKCancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"OK"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  void MessageBoxAddButtonsAbortRetryIgnore(NSAlert *alert) {
    [alert addButtonWithTitle:@"Abort"];
    [alert addButtonWithTitle:@"Retry"];
    [alert addButtonWithTitle:@"Ignore"];
  }
  
  void MessageBoxAddButtonsYesNoCancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"Yes"];
    [alert addButtonWithTitle:@"No"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  void MessageBoxAddButtonsYesNo(NSAlert *alert) {
    [alert addButtonWithTitle:@"Yes"];
    [alert addButtonWithTitle:@"No"];
  }
  
  void MessageBoxAddButtonsRetryCancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"Retry"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  DialogResult MessageBoxShowModalOK(NSAlert *alert) {
    [alert runModal];
    return DialogResult::OK;
  }
  
  DialogResult MessageBoxShowModalOKCancel(NSAlert *alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::OK : DialogResult::Cancel;
  }
  
  DialogResult MessageBoxShowModalAbortRetryIgnore(NSAlert *alert) {
    NSModalResponse result = [alert runModal];
    if (result == NSAlertFirstButtonReturn)
      return DialogResult::Abort;
    if (result == NSAlertSecondButtonReturn)
      return DialogResult::Retry;
    return DialogResult::Ignore;
  }
  
  DialogResult MessageBoxShowModalYesNoCancel(NSAlert *alert) {
    NSModalResponse result = [alert runModal];
    if (result == NSAlertFirstButtonReturn)
      return DialogResult::Yes;
    if (result == NSAlertSecondButtonReturn)
      return DialogResult::No;
    return DialogResult::Cancel;
  }
  
  DialogResult MessageBoxShowModalYesNo(NSAlert *alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::Yes : DialogResult::No;
  }
  
  DialogResult MessageBoxShowModalRetryCancel(NSAlert *alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? DialogResult::Retry : DialogResult::Cancel;
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static SortedDictionary<MessageBoxButtons, delegate<void, NSAlert*>> addButtons = {{MessageBoxButtons::OK, MessageBoxAddButtonsOK}, {MessageBoxButtons::OKCancel, MessageBoxAddButtonsOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxAddButtonsAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxAddButtonsYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxAddButtonsYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxAddButtonsRetryCancel}};
  static SortedDictionary<MessageBoxIcon, NSAlertStyle>  messageBoxIcon = {{MessageBoxIcon::None, NSAlertStyleWarning}, {MessageBoxIcon::Exclamation, NSAlertStyleCritical}, {MessageBoxIcon::Information, NSAlertStyleInformational}, {MessageBoxIcon::Question, NSAlertStyleInformational}, {MessageBoxIcon::Stop, NSAlertStyleCritical}};
  static SortedDictionary<MessageBoxButtons, delegate<DialogResult, NSAlert*>> showModal = {{MessageBoxButtons::OK, MessageBoxShowModalOK}, {MessageBoxButtons::OKCancel, MessageBoxShowModalOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxShowModalAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxShowModalYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxShowModalYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxShowModalRetryCancel}};
  @autoreleasepool {
    NSAlert *alert = [[NSAlert alloc] init];
    addButtons[buttons](alert);
    [alert setMessageText:[NSString stringWithUTF8String:caption.c_str()]];
    [alert setInformativeText:[NSString stringWithUTF8String:message.c_str()]];
    [alert setAlertStyle:messageBoxIcon[icon]];
    if (displayHelpButton)
      [alert setShowsHelp:YES];
    DialogResult result = showModal[buttons](alert);
    NSEvent *ignoredEvent;
    do
      ignoredEvent = [NSApp nextEventMatchingMask:(NSEventMaskAny & ~NSEventMaskSystemDefined) untilDate:[NSDate dateWithTimeIntervalSinceNow:0] inMode:NSDefaultRunLoopMode dequeue:YES];
    while (ignoredEvent);
    return result;
  }
}

void FormsApi::Application::Start() {
  cocoaApi = UniquePointer<CocoaApi>::Create();
}

void FormsApi::Application::Stop() {
  cocoaApi = null;
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
  [(NSWindow*)form.data->handle close];
}

@interface NSControlResponder : NSObject
- (IBAction) ControlClick:(id)sender;
- (IBAction) FormClose:(id)sender;
@end

@implementation NSControlResponder
- (IBAction) ControlClick:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(cocoaApi().Controls()[(intptr)sender]()).WndProc(event);
}

- (IBAction) FormClose:(id)sender {
  Message event = Message::Create((intptr)sender, WM_CLOSE, 0, 0, 0, 0);
  const_cast<Control&>(cocoaApi().Controls()[(intptr)sender]()).WndProc(event);
}
@end

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = cocoaApi().GetBounds(button);
    NSButton *handle = [[[NSButton alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)button.data->parent().data->handle contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:button.data->text.c_str()]];
    [handle setButtonType:NSMomentaryPushInButton];
    [handle setBezelStyle:bounds.Height == button.DefaultSize().Height ? NSBezelStyleRounded : NSBezelStyleRegularSquare];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    //[handle setWantsLayer:YES];
    handle.layer.backgroundColor = cocoaApi().FromColor(button.BackColor).CGColor;
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    cocoaApi().Controls()[(intptr)handle] = button;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Button&>(button).WndProc(message);
    return (intptr)handle;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = cocoaApi().GetBounds(checkBox);
    NSButton *handle = [[[NSButton alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)checkBox.data->parent().data->handle contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:checkBox.data->text.c_str()]];
    [handle setButtonType:NSButtonTypeSwitch];
    [handle setBezelStyle:NSBezelStyleRegularSquare];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setWantsLayer:YES];
    handle.layer.backgroundColor = cocoaApi().FromColor(checkBox.BackColor).CGColor;
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    cocoaApi().Controls()[(intptr)handle] = checkBox;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::CheckBox&>(checkBox).WndProc(message);
    return (intptr)handle;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  System::Drawing::Rectangle bounds = cocoaApi().GetBounds(control);
  NSControl *handle = [[[NSControl alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
  [[(NSWindow*)control.data->parent().data->handle contentView] addSubview: handle];
  
  [handle setStringValue:[NSString stringWithUTF8String:control.data->text.c_str()]];
  [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [handle setWantsLayer:YES];
  handle.layer.backgroundColor = cocoaApi().FromColor(control.BackColor).CGColor;
  [handle setTarget:[NSControlResponder alloc]];
  [handle setAction:@selector(ControlClick:)];
  cocoaApi().Controls()[(intptr)handle] = control;
  Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
  const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = cocoaApi().GetBounds(form);
    NSWindow* handle = [[NSWindow alloc] init];
    
    [handle setStyleMask: cocoaApi().FormToNSWindowStyleMask(form)];
    [handle setFrame:NSMakeRect(0, 0, bounds.Width(), bounds.Height()) display:YES];
    [handle setFrameTopLeftPoint:NSMakePoint(bounds.X(), bounds.Y())];
    
    [handle setTitle:[NSString stringWithUTF8String:form.data->text.c_str()]];
    [handle makeKeyAndOrderFront:nil];
    [NSApp activateIgnoringOtherApps:YES];
    handle.backgroundColor = cocoaApi().FromColor(form.BackColor);
    //handle.color = cocoaApi().FromColor(form.ForeColor);
    cocoaApi().Controls()[(intptr)handle] = form;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Form&>(form).WndProc(message);
    return (intptr)handle;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& label) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = cocoaApi().GetBounds(label);
    NSTextField* handle;
    handle = [[NSTextField alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())];
    [[(NSWindow*)label.data->parent().data->handle contentView] addSubview: handle];

    [handle setStringValue:[NSString stringWithUTF8String:label.data->text.c_str()]];
    [handle setBezeled:NO];
    [handle setDrawsBackground:NO];
    [handle setEditable:NO];
    [handle setSelectable:NO];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    //[handle setWantsLayer:YES];
    //handle.layer.backgroundColor = cocoaApi().FromColor(label.BackColor).CGColor;
    handle.drawsBackground = TRUE;
    handle.backgroundColor = cocoaApi().FromColor(label.BackColor);
    handle.textColor = cocoaApi().FromColor(label.ForeColor);
    
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    cocoaApi().Controls()[(intptr)handle] = label;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Label&>(label).WndProc(message);
    return (intptr)handle;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& radioButton) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = cocoaApi().GetBounds(radioButton);
    NSButton *handle = [[[NSButton alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)radioButton.data->parent().data->handle contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:radioButton.data->text.c_str()]];
    [handle setButtonType:NSButtonTypeRadio];
    [handle setBezelStyle:NSBezelStyleRegularSquare];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setWantsLayer:YES];
    handle.layer.backgroundColor = cocoaApi().FromColor(radioButton.BackColor).CGColor;
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    cocoaApi().Controls()[(intptr)handle] = radioButton;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::RadioButton&>(radioButton).WndProc(message);
    return (intptr)handle;
  }
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
  cocoaApi().Controls().Remove(control.Handle);
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

void FormsApi::Control::SetBackColor(intptr hdc, const System::Drawing::Color& color) {
  [(NSControl*)hdc setWantsLayer:YES];
  ((NSControl*)hdc).layer.backgroundColor = cocoaApi().FromColor(color).CGColor;
}

void FormsApi::Control::SetForeColor(intptr hdc, const System::Drawing::Color& color) {
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero) {
    [(NSControl*)control.data->handle setWantsLayer:YES];
    ((NSControl*)control.data->handle).layer.backgroundColor = cocoaApi().FromColor(control.BackColor).CGColor;
  }
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (control.data->handle) {
      System::Drawing::Rectangle bounds = cocoaApi().GetBounds(control);
      [(NSControl*)control.data->handle setFrameOrigin:NSMakePoint(bounds.X(), bounds.Y())];
    }
  }
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (control.data->handle) {
      [(NSControl*)control.data->handle setFrameSize:NSMakeSize(control.Width(), control.Height())];
      if (is<System::Windows::Forms::Button>(control))
        [(NSButton*)control.data->handle setBezelStyle: control.Height() == control.DefaultSize().Height ? NSBezelStyleRounded : NSBezelStyleRegularSquare];
    }
  }
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (control.data->handle) {
      if (is<System::Windows::Forms::Button>(control))
        [(NSButton*)control.data->handle  setTitle:[NSString stringWithUTF8String:control.data->text.c_str()]];
      else if (is<System::Windows::Forms::Form>(control))
        [(NSWindow*)control.data->handle  setTitle:[NSString stringWithUTF8String:control.data->text.c_str()]];
      else
        [(NSControl*)control.data->handle  setStringValue:[NSString stringWithUTF8String:control.data->text.c_str()]];
    }
  }
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (!control.data->handle) {
      if (is<Form>(control)) {
        if (control.data->visible ) {
          [(NSWindow*)control.data->handle makeKeyAndOrderFront:NSApp];
          [NSApp activateIgnoringOtherApps:YES];
        } else {
          [(NSWindow*)control.data->handle orderOut:nil];
        }
      return;
      }
    
      [(NSControl*)control.data->handle setHidden:control.data->visible ? NO : YES];
    }
  }
}

#endif
