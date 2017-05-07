#if defined(__use_fltk_interface__)
#include "FormsApi.h"

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Window.H>

#include <Pcf/Undef.h>

extern System::Collections::Generic::SortedDictionary<intptr, delegate<int32, int32>> defWindowProcs;

namespace {
  static const int32 defaultTextSize = 12;

  static Fl_Color FromColor(const System::Drawing::Color& color) {
    return fl_rgb_color(as<byte>(color.R()), as<byte>(color.G()), as<byte>(color.B()));
  }

  static System::Windows::Forms::Keys GetKeyCode() {
    using namespace System::Windows::Forms;
    System::Collections::Generic::SortedDictionary<int32, Keys> keys {{FL_BackSpace, Keys::Back}, {FL_Tab, Keys::Tab}, {FL_Iso_Key, Keys::OemBackslash},{FL_Enter, Keys::Enter}, {FL_Pause, Keys::Pause}, {FL_Scroll_Lock, Keys::Scroll}, {FL_Escape, Keys::Escape}, {FL_Kana, Keys::Delete}, {FL_Eisu, Keys::Help}, {FL_Yen, Keys::D0}, {FL_JIS_Underscore, Keys::D1}, {FL_Home, Keys::Home}, {FL_Left, Keys::Left}, {FL_Up, Keys::Up}, {FL_Right, Keys::Right}, {FL_Down, Keys::Down}, {FL_Page_Up, Keys::PageUp}, {FL_Page_Down, Keys::PageDown}, {FL_End, Keys::End}, {FL_Print, Keys::PrintScreen}, {FL_Insert, Keys::Insert}, {FL_Menu, Keys::Menu}, {FL_Help, Keys::Help}, {FL_Num_Lock, Keys::NumLock}, {FL_KP + 0, Keys::NumPad0}, {FL_KP + 1, Keys::NumPad1}, {FL_KP + 2, Keys::NumPad2}, {FL_KP + 3, Keys::NumPad3}, {FL_KP + 4, Keys::NumPad4}, {FL_KP + 5, Keys::NumPad5}, {FL_KP + 6, Keys::NumPad6}, {FL_KP + 7, Keys::NumPad7}, {FL_KP + 8, Keys::NumPad8}, {FL_KP + 9, Keys::NumPad9}, {FL_KP_Enter, Keys::Enter}, {FL_F+1, Keys::F1}, {FL_F+2, Keys::F2}, {FL_F+3, Keys::F3}, {FL_F+4, Keys::F4}, {FL_F+5, Keys::F5}, {FL_F+6, Keys::F6}, {FL_F+7, Keys::F7}, {FL_F+8, Keys::F8}, {FL_F+9, Keys::F9}, {FL_F+10, Keys::F10}, {FL_F+11, Keys::F11}, {FL_F+12, Keys::F12}, {FL_F+13, Keys::F13}, {FL_F+14, Keys::F14}, {FL_F+15, Keys::F15}, {FL_F+16, Keys::F16}, {FL_F+17, Keys::F17}, {FL_F+18, Keys::F18}, {FL_F+19, Keys::F19}, {FL_F+20, Keys::F20}, {FL_F+21, Keys::F21}, {FL_F+22, Keys::F22}, {FL_F+23, Keys::F23}, {FL_F+24, Keys::F24}, {FL_Shift_L, Keys::ShiftKey /*Keys::LShiftKey*/}, {FL_Shift_R, Keys::ShiftKey /*Keys::RShiftKey*/}, {FL_Control_L, Keys::ControlKey /*Keys::LControlKey*/}, {FL_Control_R, Keys::ControlKey /*Keys::RControlKey*/}, {FL_Caps_Lock, Keys::CapsLock}, {FL_Meta_L, Keys::CommandKey /*Keys::LCommandKey*/}, {FL_Meta_R, Keys::CommandKey /*Keys::RCommandKey*/}, {FL_Alt_L, Keys::Alt /*KeysLAlt*/}, {FL_Alt_R, Keys::Alt /*Keys::RAlt*/}, {FL_Delete, Keys::Delete}, {0x0027, Keys::OemQuotes}, {0xFFAA, Keys::Multiply}, {0xFFAB, Keys::Add}, {0xFFAD, Keys::Subtract}, {0xFFAE, Keys::Decimal}, {0xFFAF, Keys::Divide}, {0xFFBD, Keys::Packet}, {0x0029, Keys::OemOpenBrackets}, {0x002C, Keys::Oemcomma}, {0x002D, Keys::OemMinus}, {0x002E, Keys::OemPeriod}, {0x002F, Keys::OemQuestion}, {0x003A, Keys::Oemtilde}, {0x003B, Keys::OemSemicolon}, {0x003C, Keys::OemBackslash}, {0x003D, Keys::Oemplus}, {0x005B, Keys::OemOpenBrackets}, {0x005C, Keys::OemPipe}, {0x005D, Keys::OemCloseBrackets}, {0x0060, Keys::Oemtilde}};

    int32 key = Fl::event_key();
    if (Fl::event_ctrl() && key >= 'a' && key <= 'z')
      key -= 96;
    if (key >= 'a' && key <= 'z')
      key -= 32;

    Keys keyCode = static_cast<Keys>(key);;
    if (keys.ContainsKey(key))
      keyCode = keys[key];

    if (Fl::event_command())
      keyCode |= static_cast<Keys>(0x80000);
    else
      keyCode &= static_cast<Keys>(~0x80000);

    if (Fl::event_alt())
      keyCode |= static_cast<Keys>(0x40000);
    else
      keyCode &= static_cast<Keys>(~0x40000);

    if (Fl::event_ctrl())
      keyCode |= static_cast<Keys>(0x20000);
    else
      keyCode &= static_cast<Keys>(~0x20000);

    if (Fl::event_shift())
      keyCode |= static_cast<Keys>(0x10000);
    else
      keyCode &= static_cast<Keys>(~0x10000);

    return keyCode;
  }

  static int32 GetMouseButtonState() {
    int32 flState = Fl::event_state();
    int32 state = 0;
    state += (flState & FL_CTRL) == FL_CTRL ? MK_CONTROL : 0;
    state += (flState & FL_BUTTON1) == FL_BUTTON1 ? MK_LBUTTON : 0;
    state += (flState & FL_BUTTON2) == FL_BUTTON2 ? MK_MBUTTON : 0;
    state += (flState & FL_BUTTON3) == FL_BUTTON3 ? MK_RBUTTON : 0;
    state += (flState & FL_SHIFT) == FL_SHIFT ? MK_SHIFT : 0;
    return state;
  }

  static int32 GetMouseWheelDelta() {
    static const int32 WHEEL_DELTA = 40;
    return -Fl::event_dy() * WHEEL_DELTA;
  }

  static int32 GetMouseXCoordinate() {
    return Fl::event_x_root();
  }

  static int32 GetMouseYCoordinate() {
    return Fl::event_y_root();
  }

  static int32 GetMouseXCoordinateRelativeToClientArea() {
    return Fl::event_x();
  }

  static int32 GetMouseYCoordinateRelativeToClientArea() {
    return Fl::event_y();
  }
  
  template<typename T, typename TControl>
  T* CreateControl(const TControl& control) {
    System::Drawing::Point offset;
    if (control.Parent() != null && !is<System::Windows::Forms::Form>(control.Parent()))
      offset = control.Parent()().Location;
    T* handle = new T(offset.X + control.Location().X, offset.Y + control.Location().Y, control.Size().Width, control.Size().Height, control.Text().c_str());
    handle->labelsize(defaultTextSize);
    handle->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    defWindowProcs.Add((intptr)handle, {*handle, &T::HandleControl});
    System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, FL_NO_EVENT);
    const_cast<TControl&>(control).WndProc(message);
    return handle;
  }
}

#endif
