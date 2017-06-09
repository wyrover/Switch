#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/fixed.h>
#include <gtkmm/radiobuttongroup.h>
#include <gtkmm/widget.h>
#include <Pcf/System/Diagnostics/Debug.h>
#include "FormsApi.h"

namespace __OS {
  class IWidget pcf_interface {
  public:
    virtual const Gtk::Widget& ToWidget() const = 0;
    virtual Gtk::Widget& ToWidget() = 0;
  };

  class Widget : public IWidget {
  public:
    virtual void BackColor(const System::Drawing::Color& color) {this->ToWidget().override_background_color(FromColor(color));}
    
    virtual const Gtk::Container& Container() const {return as<Gtk::Container>(this->ToWidget());}
    
    virtual Gtk::Container& Container() {return as<Gtk::Container>(this->ToWidget());}
    
    virtual void ForeColor(const System::Drawing::Color& color) {this->ToWidget().override_color(FromColor(color));}

    static Gdk::RGBA FromColor(const System::Drawing::Color& color) {
      Gdk::RGBA result;
      result.set_rgba(as<double>(color.R()) / 255, as<double>(color.G()) / 255, as<double>(color.B()) / 255, as<double>(color.A()) / 255);
      return result;
    }
    
    virtual void Move(int32 x, int32 y) {
      if (is<Gtk::Fixed>(this->ToWidget().get_parent())) {
        as<Gtk::Fixed>(this->ToWidget().get_parent())->child_property_x(this->ToWidget()) = x;
        as<Gtk::Fixed>(this->ToWidget().get_parent())->child_property_y(this->ToWidget()) = y;
      }
    }
    
    Gtk::RadioButtonGroup& RadioButtonGroup() {return this->radioButtonGroup;}
    
    void RegisterEvent() {
      this->ToWidget().signal_event().connect(pcf_delegate(GdkEvent* event)->bool {
        System::Diagnostics::Debug::WriteLine("Event : {0}, Name : {1}", EventToString(event->type), System::Windows::Forms::Control::FromHandle((intptr)this)().Name);
        System::Collections::Generic::SortedDictionary<int32, System::Delegate<int32, GdkEvent&>> events {
          {GDK_BUTTON_PRESS, {*this, &Widget::GdkButtonPress}},
          {GDK_BUTTON_RELEASE, {*this, &Widget::GdkButtonRelease}},
        };
        
        if (events.ContainsKey(event->type)) {
          events[event->type](*event);
          return true;
        }
        return false; //this->ToWidget().event(event);
      });
    }
    
    //void DefWndProc(Message& message) {};
    
    virtual void Show() {return this->ToWidget().show();}

    virtual void Text(const string& text) = 0;
    
    static System::Drawing::Color ToColor(const Gdk::RGBA& color) {
      System::Drawing::Color result = System::Drawing::Color::FromArgb(color.get_alpha() * 255, color.get_red() * 255, color.get_green() * 255, color.get_blue() * 255);
      return result;
    }
    
    const Gtk::Widget& ToWidget() const override {return as<Gtk::Widget>(*this);}
    
    Gtk::Widget& ToWidget() override {return as<Gtk::Widget>(*this);}
    
  private:
    static int32 GetMouseButtonState(GdkEvent& event) {
      int32 state = 0;
      state += (event.button.state) == GDK_CONTROL_MASK ? MK_CONTROL : 0;
      state += event.button.button == 1 ? MK_LBUTTON : 0;
      state += event.button.button == 2 ? MK_MBUTTON : 0;
      state += event.button.button == 3 ? MK_RBUTTON : 0;
      state += event.button.button == 4 ? MK_XBUTTON1 : 0;
      state += event.button.button == 5 ? MK_XBUTTON2 : 0;
      state += (event.button.state) == GDK_SHIFT_MASK ? MK_SHIFT : 0;
      return state;
    }

    int32 WndProc(System::Windows::Forms::Message& message) {
      ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(message.HWnd);
      if (control != null)
        control().WndProc(message);
      return (int32)message.Result();
    }
    
    int32 GdkButtonPress(GdkEvent& event) {
      int32 mouseButton = WM_LBUTTONDOWN;
      if (event.button.button == 2) mouseButton = WM_MBUTTONDOWN;
      if (event.button.button == 3) mouseButton = WM_RBUTTONDOWN;
      if (event.button.button == 4) mouseButton = WM_XBUTTONDOWN;
      if (event.button.button == 5) mouseButton = WM_XBUTTONDOWN;
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)this, mouseButton, GetMouseButtonState(event), ((int32)event.button.y << 16) + event.button.x, 0, (intptr)&event);
      return this->WndProc(message);
      
    }
    
    int32 GdkButtonRelease(GdkEvent& event) {
      int32 mouseButton = WM_LBUTTONUP;
      if (event.button.button == 2) mouseButton = WM_MBUTTONUP;
      if (event.button.button == 3) mouseButton = WM_RBUTTONUP;
      if (event.button.button == 4) mouseButton = WM_XBUTTONUP;
      if (event.button.button == 5) mouseButton = WM_XBUTTONUP;
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)this, mouseButton, GetMouseButtonState(event), ((int32)event.button.y << 16) + event.button.x, 0, (intptr)&event);
      return this->WndProc(message);
    }

    string EventToString(int32 event) {
      static System::Collections::Generic::SortedDictionary<int32, string> events = {{GDK_NOTHING, "GDK_NOTHING"}, {GDK_DELETE, "GDK_DELETE"}, {GDK_DESTROY, "GDK_DESTROY"}, {GDK_EXPOSE, "GDK_EXPOSE"}, {GDK_MOTION_NOTIFY, "GDK_MOTION_NOTIFY"}, {GDK_BUTTON_PRESS, "GDK_BUTTON_PRESS"}, {GDK_2BUTTON_PRESS, "GDK_2BUTTON_PRESS"}, {GDK_3BUTTON_PRESS, "GDK_3BUTTON_PRESS"}, {GDK_BUTTON_RELEASE, "GDK_BUTTON_RELEASE"}, {GDK_KEY_PRESS, "GDK_KEY_PRESS"}, {GDK_KEY_RELEASE, "GDK_KEY_RELEASE"}, {GDK_ENTER_NOTIFY, "GDK_ENTER_NOTIFY"}, {GDK_LEAVE_NOTIFY, "GDK_LEAVE_NOTIFY"}, {GDK_FOCUS_CHANGE, "GDK_FOCUS_CHANGE"}, {GDK_CONFIGURE, "GDK_CONFIGURE"}, {GDK_MAP, "GDK_MAP"}, {GDK_UNMAP, "GDK_UNMAP"}, {GDK_PROPERTY_NOTIFY,	"GDK_PROPERTY_NOTIFY"}, {GDK_SELECTION_CLEAR, "GDK_SELECTION_CLEAR"}, {GDK_SELECTION_REQUEST, "GDK_SELECTION_REQUEST"}, {GDK_SELECTION_NOTIFY, "GDK_SELECTION_NOTIFY"}, {GDK_PROXIMITY_IN, "GDK_PROXIMITY_IN"}, {GDK_PROXIMITY_OUT, "GDK_PROXIMITY_OUT"}, {GDK_DRAG_ENTER, "GDK_DRAG_ENTER"}, {GDK_DRAG_LEAVE, "GDK_DRAG_LEAVE"}, {GDK_DRAG_MOTION, "GDK_DRAG_MOTION"}, {GDK_DRAG_STATUS, "GDK_DRAG_STATUS"}, {GDK_DROP_START, "GDK_DROP_START"}, {GDK_DROP_FINISHED, "GDK_DROP_FINISHED"}, {GDK_CLIENT_EVENT, "GDK_CLIENT_EVENT"}, {GDK_VISIBILITY_NOTIFY, "GDK_VISIBILITY_NOTIFY"}, {GDK_SCROLL, "GDK_SCROLL"}, {GDK_WINDOW_STATE, "GDK_WINDOW_STATE"}, {GDK_SETTING, "GDK_SETTING"}, {GDK_OWNER_CHANGE, "GDK_OWNER_CHANGE"}, {GDK_GRAB_BROKEN, "GDK_GRAB_BROKEN"}, {GDK_DAMAGE, "GDK_DAMAGE"}, {GDK_TOUCH_BEGIN, "GDK_TOUCH_BEGIN"}, {GDK_TOUCH_UPDATE, "GDK_TOUCH_UPDATE"}, {GDK_TOUCH_END, "GDK_TOUCH_END"}, {GDK_TOUCH_CANCEL, "GDK_TOUCH_CANCEL"}, {GDK_TOUCHPAD_SWIPE, "GDK_TOUCHPAD_SWIPE"}, {GDK_TOUCHPAD_PINCH, "GDK_TOUCHPAD_PINCH"}, {GDK_PAD_BUTTON_PRESS, "GDK_PAD_BUTTON_PRESS"}, {GDK_PAD_BUTTON_RELEASE, "GDK_PAD_BUTTON_RELEASE"}, {GDK_PAD_RING, "GDK_PAD_RING"}, {GDK_PAD_STRIP, "GDK_PAD_STRIP"}, {GDK_PAD_GROUP_MODE, "GDK_PAD_GROUP_MODE"}};
      if (!events.ContainsKey(event))
        return "<Unknown>";
      return events[event];
    };
    Gtk::RadioButtonGroup radioButtonGroup;
  };
}
#endif
