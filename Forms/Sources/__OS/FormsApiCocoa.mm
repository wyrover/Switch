#if __APPLE__
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

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  static bool messageLoopRunning = false;
  constexpr int32 screenHeight = 1050;
  System::Collections::Generic::Dictionary<intptr, Reference<Control>> controls;
  System::Drawing::Point mouseDownLocation;
  
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
  
  int32 GetCaptionHeight(const System::Windows::Forms::Control& control) {
    return !is<Form>(control) || as<Form>(control).FormBorderStyle == FormBorderStyle::None ? 0 : FormsApi::SystemInformation::GetCaptionHeight();
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
  
  System::Drawing::Rectangle GetBounds(const System::Windows::Forms::Control& control) {
    if (is<System::Windows::Forms::Form>(control))
      return GetBounds(as<System::Windows::Forms::Form>(control));
    return System::Drawing::Rectangle(control.Bounds().X, control.Parent()().Bounds().Height - control.Bounds().Height - control.Bounds().Y - GetCaptionHeight(control.Parent()()), control.Bounds().Width, control.Bounds().Height);
  }
  
  Message NSEventToMessage(NSEvent* event) {
    static System::Collections::Generic::Dictionary<int32, int32> events {
      {NSEventTypeLeftMouseDown, WM_LBUTTONDOWN},
      {NSEventTypeLeftMouseUp, WM_LBUTTONUP},
      {NSEventTypeRightMouseDown, WM_RBUTTONDOWN},
      {NSEventTypeRightMouseUp, WM_RBUTTONUP},
      {NSEventTypeMouseMoved, WM_MOUSEMOVE},
      //{NSEventTypeLeftMouseDragged, WM_...},
      //{NSEventTypeRightMouseDragged, WM_...},
      {NSEventTypeMouseEntered, WM_MOUSEENTER},
      {NSEventTypeMouseExited, WM_MOUSELEAVE},
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
      {NSEventTypeOtherMouseDown, WM_MBUTTONDOWN},
      {NSEventTypeOtherMouseUp, WM_MBUTTONUP},
      //{NSEventTypeOtherMouseDragged, WM_...},
    };
    int32 msg;
    if (events.ContainsKey([event type]))
      msg = events[[event type]];
    else
    msg = 0x40000 + [event type];
    intptr hwnd = (intptr)[event window];
    
    if  (hwnd != 0) {
      System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - GetCaptionHeight(controls[hwnd]()));
      for (auto control : controls) {
        if (control.Key != hwnd && control.Value()().Bounds().Contains(location)) {
          hwnd = control.Key;
          mouseDownLocation = location - control.Value()().Location();
          break;
        }
      }
    }
    
    return Message::Create(hwnd, msg, 0, mouseDownLocation.X() & 0x0000FFFF + ((mouseDownLocation.Y() & 0xFFFF0000) << 16), 0, (intptr)event);
  }
  
  int32 GetMessage(Message& message) {
    int32 result = 0;
    @autoreleasepool {
      NSEvent *event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate dateWithTimeIntervalSinceNow:Double::MaxValue] inMode:NSDefaultRunLoopMode dequeue:YES];
      
      if (event != nil) {
        message = NSEventToMessage(event);
        result = 1;
      } else
        System::Diagnostics::Debug::WriteLine("??? What's appened !");
    }
    return result;
  }
  
  int32 PeekMessage(Message& message) {
    @autoreleasepool {
      NSEvent *event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate dateWithTimeIntervalSinceNow:0.0] inMode:NSDefaultRunLoopMode dequeue:YES];
      
      if (event != nil && [event window] != nil) {
        message = NSEventToMessage(event);
        return 1;
      }
    }
    return 0;
  }
  
  void TranslateMessage(Message& message) {
  }
  
  void DispatchMessage(Message& message) {
    for (auto control : controls) {
      if (control.Key == message.HWnd())
        const_cast<Control&>(control.Value()()).WndProc(message);
    }
    NSEvent* event = (NSEvent*)message.Handle();
    [NSApp sendEvent:event];
  }
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  Environment::Exit(0);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  @autoreleasepool {
    [NSApplication sharedApplication];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    NSMenu* menubar = [NSMenu new];
    NSMenuItem* appMenuItem = [NSMenuItem new];
    [menubar addItem:appMenuItem];
    [NSApp setMainMenu:menubar];
    NSMenu* appMenu = [NSMenu new];
    NSString* appName = [[NSProcessInfo processInfo] processName];
    NSString* quitTitle = [@"Quit " stringByAppendingString:appName];
    NSMenuItem* quitMenuItem = [[NSMenuItem alloc] initWithTitle:quitTitle action:@selector(terminate:) keyEquivalent:@"q"];
    [appMenu addItem:quitMenuItem];
    [appMenuItem setSubmenu:appMenu];
    //[NSApp run];
  }
  messageLoopRunning = true;
  while (messageLoopRunning) {
    Message msg;
    int32 result = idle.IsEmpty() ? GetMessage(msg) : PeekMessage(msg);
    while (result != 0) {
      TranslateMessage(msg);
      DispatchMessage(msg);
      if (msg.Msg == WM_QUIT) {
        messageLoopRunning = false;
        break;
      }
      result = idle.IsEmpty() ? GetMessage(msg) : PeekMessage(msg);
      if (idle.IsEmpty() && !result)
        messageLoopRunning = false;
    }
    idle(object(), EventArgs());
  }
}

void FormsApi::Application::RegisterClasses() {
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
    int result = [alert runModal];
    if (result == NSAlertFirstButtonReturn)
      return DialogResult::Abort;
    if (result == NSAlertSecondButtonReturn)
      return DialogResult::Retry;
    return DialogResult::Ignore;
  }
  
  DialogResult MessageBoxShowModalYesNoCancel(NSAlert *alert) {
    int result = [alert runModal];
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
  static SortedDictionary<MessageBoxIcon, NSAlertStyle>  messageBoxIcon = {{MessageBoxIcon::None, NSAlertStyleWarning}, {MessageBoxIcon::Asterisk, NSAlertStyleInformational}, {MessageBoxIcon::Error, NSAlertStyleCritical}, {MessageBoxIcon::Exclamation, NSAlertStyleCritical}, {MessageBoxIcon::Hand, NSAlertStyleInformational}, {MessageBoxIcon::Information, NSAlertStyleInformational}, {MessageBoxIcon::Question, NSAlertStyleInformational}, {MessageBoxIcon::Stop, NSAlertStyleCritical}, {MessageBoxIcon::Warning, NSAlertStyleCritical}};
  static SortedDictionary<MessageBoxButtons, delegate<DialogResult, NSAlert*>> showModal = {{MessageBoxButtons::OK, MessageBoxShowModalOK}, {MessageBoxButtons::OKCancel, MessageBoxShowModalOKCancel}, {MessageBoxButtons::AbortRetryIgnore, MessageBoxShowModalAbortRetryIgnore}, {MessageBoxButtons::YesNoCancel, MessageBoxShowModalYesNoCancel}, {MessageBoxButtons::YesNo, MessageBoxShowModalYesNo}, {MessageBoxButtons::RetryCancel, MessageBoxShowModalRetryCancel}};
  @autoreleasepool {
    NSAlert *alert = [[NSAlert alloc] init];
    addButtons[buttons](alert);
    [alert setMessageText:[NSString stringWithUTF8String:caption.c_str()]];
    [alert setInformativeText:[NSString stringWithUTF8String:message.c_str()]];
    [alert setAlertStyle:messageBoxIcon[icon]];
    if (displayHelpButton)
      [alert setShowsHelp:YES];
    return showModal[buttons](alert);
  }
}

void FormsApi::Application::UnregisterClasses() {
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
}

@interface NSControlResponder : NSObject
- (IBAction) ControlClick:(id)sender;
@end

@implementation NSControlResponder
- (IBAction) ControlClick:(id)sender {
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(controls[(intptr)sender]()).WndProc(event);
}
@end

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = GetBounds(button);
    NSButton *handle = [[[NSButton alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)button.data->parent().data->handle contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:button.data->text.c_str()]];
    [handle setButtonType:NSMomentaryPushInButton];
    [handle setBezelStyle:bounds.Height == button.DefaultSize().Height ? NSBezelStyleRounded : NSBezelStyleRegularSquare];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    controls[(intptr)handle] = button;
    return (intptr)handle;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = GetBounds(checkBox);
    NSButton *handle = [[[NSButton alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)checkBox.data->parent().data->handle contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:checkBox.data->text.c_str()]];
    [handle setButtonType:NSButtonTypeSwitch];
    [handle setBezelStyle:NSBezelStyleRegularSquare];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    controls[(intptr)handle] = checkBox;
    return (intptr)handle;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  System::Drawing::Rectangle bounds = GetBounds(control);
  NSControl *handle = [[[NSControl alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
  [[(NSWindow*)control.data->parent().data->handle contentView] addSubview: handle];
  
  [handle setStringValue:[NSString stringWithUTF8String:control.data->text.c_str()]];
  [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [handle setTarget:[NSControlResponder alloc]];
  [handle setAction:@selector(ControlClick:)];
  controls[(intptr)handle] = control;
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = GetBounds(form);
    NSWindow* handle = [[NSWindow alloc] init];
    
    [handle setStyleMask: FormToNSWindowStyleMask(form)];
    [handle setFrame:NSMakeRect(0, 0, bounds.Width(), bounds.Height()) display:YES];
    [handle setFrameTopLeftPoint:NSMakePoint(bounds.X(), bounds.Y())];
    
    [handle setTitle:[NSString stringWithUTF8String:form.data->text.c_str()]];
    [handle makeKeyAndOrderFront:nil];
    [NSApp activateIgnoringOtherApps:YES];
    controls[(intptr)handle] = form;
    return (intptr)handle;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& label) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = GetBounds(label);
    NSTextField* handle;
    handle = [[NSTextField alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())];
    [[(NSWindow*)label.data->parent().data->handle contentView] addSubview: handle];

    [handle setStringValue:[NSString stringWithUTF8String:label.data->text.c_str()]];
    [handle setBezeled:NO];
    [handle setDrawsBackground:NO];
    [handle setEditable:NO];
    [handle setSelectable:NO];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    controls[(intptr)handle] = label;
    return (intptr)handle;
  }
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& radioButton) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = GetBounds(radioButton);
    NSButton *handle = [[[NSButton alloc] initWithFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height())] autorelease];
    [[(NSWindow*)radioButton.data->parent().data->handle contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:radioButton.data->text.c_str()]];
    [handle setButtonType:NSButtonTypeRadio];
    [handle setBezelStyle:NSBezelStyleRegularSquare];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:[NSControlResponder alloc]];
    [handle setAction:@selector(ControlClick:)];
    controls[(intptr)handle] = radioButton;
    return (intptr)handle;
  }
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  controls.Remove(control.Handle);
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const InvalidateEventArgs& e) {
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return System::Drawing::Point();
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return System::Drawing::Point();
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  @autoreleasepool {
    if (control.data->handle) {
      System::Drawing::Rectangle bounds = GetBounds(control);
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

int32 FormsApi::SystemInformation::GetActiveWindowTrackingDelay() {
  return 0;
}

ArrangeDirection FormsApi::SystemInformation::GetArrangeDirection() {
  return ArrangeDirection::Left;
}

ArrangeStartingPosition FormsApi::SystemInformation::GetArrangeStartingPosition() {
  return ArrangeStartingPosition::Hide;
}

BootMode FormsApi::SystemInformation::GetBootMode() {
  return BootMode::Normal;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorder3DSize() {
  return System::Drawing::Size(0, 0);
}

int32 FormsApi::SystemInformation::GetBorderMultiplierFactor() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorderSize() {
  return System::Drawing::Size(0, 0);
}

System::Drawing::Size FormsApi::SystemInformation::GetCaptionButtonSize() {
  return System::Drawing::Size(16, 16);
}

int32 FormsApi::SystemInformation::GetCaptionHeight() {
  return 23;
}

int32 FormsApi::SystemInformation::GetCaretBlinkTime() {
  return 530;
}

int32 FormsApi::SystemInformation::GetCaretWidth() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetCursorSize() {
  return System::Drawing::Size(32, 32);
}

bool FormsApi::SystemInformation::GetDbcsEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetDebugOS() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetDoubleClickSize() {
  return System::Drawing::Size(4, 4);
}

int32 FormsApi::SystemInformation::GetDoubleClickTime() {
  return 500;
}

bool FormsApi::SystemInformation::GetDragFullWindows() {
  return true;
}

System::Drawing::Size FormsApi::SystemInformation::GetDragSize() {
  return System::Drawing::Size(4, 4);
}

System::Drawing::Size FormsApi::SystemInformation::GetFixedFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

int32 FormsApi::SystemInformation::GetFontSmoothingContrast() {
  return 1200;
}

int32 FormsApi::SystemInformation::GetFontSmoothingType() {
  return 2;
}

System::Drawing::Size FormsApi::SystemInformation::GetFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetHighContrast() {
  return false;
}

int32 FormsApi::SystemInformation::GetHorizontalFocusThickness() {
  return 1;
}

int32 FormsApi::SystemInformation::GetHorizontalResizeBorderThickness() {
  return 4;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarHeight() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetIconHorizontalSpacing() {
  return 75;
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSize() {
  return System::Drawing::Size(64, 64);
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSpacingSize() {
  return System::Drawing::Size(75, 75);
}

int32 FormsApi::SystemInformation::GetIconVerticalSpacing() {
  return 75;
}

bool FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsDropShadowEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsFlatMenuEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsFontSmoothingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsHotTrackingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsKeyboardPreferred() {
  return false;
}

bool FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuFadeEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsSelectionFadeEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsSnapToDefaultEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsTitleBarGradientEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsToolTipAnimationEnabled() {
  return false;
}

int32 FormsApi::SystemInformation::GetKanjiWindowHeight() {
  return 0;
}

int32 FormsApi::SystemInformation::GetKeyboardDelay() {
  return 1;
}

int32 FormsApi::SystemInformation::GetKeyboardSpeed() {
  return 31;
}

System::Drawing::Size FormsApi::SystemInformation::GetMaxWindowTrackSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetMenuAccessKeysUnderlined() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuBarButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuCheckSize() {
  return System::Drawing::Size(15, 15);
}

Font FormsApi::SystemInformation::GetMenuFont() {
  return Font::FromLogFont((intptr)0);
}

int32 FormsApi::SystemInformation::GetMenuHeight() {
  return 23;
}

#endif
