#if defined(__APPLE__) && defined(__use_native_interface__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

#include <Pcf/System/Double.h>
#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include "FormsApi.h"
#include "WindowMessage.h"
#include "WindowMessageKey.h"

namespace __OS {
  class WindowProcedure pcf_static {
  public:
    using ControlDictionary = System::Collections::Generic::SortedDictionary<intptr, ref<System::Windows::Forms::Control>>;
    
    static ControlDictionary Controls;
    
    static void WndProc(NSEvent* event) {
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
      static System::Collections::Generic::SortedDictionary<int32, delegate<void, NSEvent*, System::Windows::Forms::Control&>> events = {
        {NSEventTypeMouseEntered, WindowProcedure::MouseEnterEvent},
        {NSEventTypeMouseExited, WindowProcedure::MouseLeaveEvent},
        {NSEventTypeLeftMouseDown, WindowProcedure::LeftMouseDownEvent},
        {NSEventTypeLeftMouseUp, WindowProcedure::LeftMouseUpEvent},
        {NSEventTypeRightMouseDown, WindowProcedure::RightMouseDownEvent},
        {NSEventTypeRightMouseUp, WindowProcedure::RightMouseUpEvent},
        {NSEventTypeMouseMoved, WindowProcedure::MouseMoveEvent},
        {NSEventTypeOtherMouseDown, WindowProcedure::OtherMouseDownEvent},
        {NSEventTypeOtherMouseUp, WindowProcedure::OtherMouseUpEvent}
      };
      @autoreleasepool {
        if (events.ContainsKey([event type]) && Controls.ContainsKey((intptr)[event window])) {
          events[[event type]](event, Controls[(intptr)[event window]]);
        } else {
          [NSApp sendEvent:event];
        }
      }
    }
    
    static int32 GetMouseButtonState(NSEvent* event) {
      int32 state = 0;
      
      if ([event buttonNumber] == 1)
        state &= MK_LBUTTON;
      if ([event buttonNumber] == 2)
        state &= MK_MBUTTON;
      if ([event buttonNumber] == 3)
        state &= MK_RBUTTON;
      
      return state;
    }

  private:
    static int32 GetCaptionHeight(const System::Windows::Forms::Control& control) {
      return !is<System::Windows::Forms::Form>(control) || as<System::Windows::Forms::Form>(control).FormBorderStyle == System::Windows::Forms::FormBorderStyle::None ? 0 : FormsApi::SystemInformation::GetCaptionHeight();
    }

    static int32 GetMouseXCoordinateRelativeToClientArea(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - GetCaptionHeight(control));
      return location.X;
    }
    
    static int32 GetMouseYCoordinateRelativeToClientArea(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - GetCaptionHeight(control));
      return location.Y;
    }
    
    static void MouseEnterEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MOUSEENTER, notUsed, notUsed, 0, (intptr)event);
      hover = true;
      return control.WndProc(message);
    }
    
    static void MouseLeaveEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MOUSELEAVE, notUsed, notUsed, 0, (intptr)event);
      hover = false;
      return control.WndProc(message);
    }
    
    static void LeftMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_LBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    static void LeftMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_LBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    static void OtherMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    static void OtherMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    static void RightMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_RBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    static void RightMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_RBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    static void MouseMoveEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      if (hover) {
        System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MOUSEHOVER, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
        control.WndProc(message);
      }
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MOUSEMOVE, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      return control.WndProc(message);
    }
    
    static bool messageLoopRunning ;
    static const int32 notUsed = 0;
    static bool hover;
  };
}

#endif
