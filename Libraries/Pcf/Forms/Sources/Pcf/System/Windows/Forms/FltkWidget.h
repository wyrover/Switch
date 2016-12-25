#pragma once

#include "Fltk.h"
#include <Pcf/System/Convert.h>
#include <Pcf/System/EventArgs.h>
#include <Pcf/System/Collections/Generic/SortedSet.h>
#include <Pcf/System/Drawing/Color.h>
#include <Pcf/System/Text/UTF8Encoding.h>
#include "../../../../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Keys.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/MouseButtons.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Shortcut.h"

namespace Fltk {
  template <typename T>
  class Widget : public System::Windows::Forms::IWidget, public T {
  public:
    Widget() : T(0, 0, 0, 0, "") {this->callback(&__Callback__, this);}
    
    Widget(int width, int height) : T(0, 0, width, height, "") { this->callback(&__Callback__, this); }

    Widget(int width, int height, const char* text) : T(0, 0, width, height, text) { this->callback(&__Callback__, this); }

    Widget(int x, int y, int width, int height) : T(x, y, width, height, "") { this->callback(&__Callback__, this); }

    Widget(int x, int y, int width, int height, const char* text) : T(x, y, width, height, text) { this->callback(&__Callback__, this); }

    Widget(const char* text) : T(0, 0, 0, 0, text) { this->callback(&__Callback__, this); }
    
    void Draw() override {
      T::draw();
    }

    static T& ToWidget(IWidget& widget) {return dynamic_cast<T&>(widget);}
    
    static const T& ToWidget(const IWidget& widget) {return dynamic_cast<const T&>(widget);}

    static Fl_Text_Buffer& ToText(void* text) {return *reinterpret_cast<Fl_Text_Buffer*>(text);}
    
    static const Fl_Text_Buffer& ToText(const void* text) {return *reinterpret_cast<const Fl_Text_Buffer*>(text);}
    
    void FreePosition(bool freePostion) {this->force_position(freePostion);}

  private:
    void draw() override {
      Paint(object(), System::EventArgs());
    }
    
    int handle(int event) override {
      WidgetEventArgs eventArgs(event, T::handle(event) != 0);
      EventHandled(object(), eventArgs);
      return System::Convert::ToInt32(eventArgs.IsHandled);
    }
    
    static void __Callback__(Fl_Widget* widget, void* param) {
      static_cast<Widget<T>*>(param)->Callback(object(), System::EventArgs());
    }
  };
  
  class Helper {
  public:
    static char32 GetKeyChar() {
      using namespace System::Windows::Forms;
      static System::Collections::Generic::SortedSet<Keys> zeroKeys {Keys::Left, Keys::Right, Keys::Up, Keys::Down, Keys::PageUp, Keys::PageDown, Keys::End, Keys::Home, Keys::Insert, Keys::F1, Keys::F2, Keys::F3, Keys::F4, Keys::F5, Keys::F6, Keys::F7, Keys::F8, Keys::F9, Keys::F10, Keys::F11, Keys::F12, Keys::F13, Keys::F14, Keys::F15, Keys::F16, Keys::F17, Keys::F18, Keys::F19, Keys::F20, Keys::F21, Keys::F22, Keys::F23, Keys::F24};
      static System::Collections::Generic::SortedSet<Keys> keys {Keys::Back, Keys::Delete};
      if (Fl::event_alt())
        return 0;
      
      System::Text::UTF8Encoding::Decoder decoder;
      const char* text = null;
      string keyText;

      if (zeroKeys.Contains(GetKeyCode() & (Keys)0xFFFF)) {
        keyText = "\0";
        text = keyText.Data();
      }
      else if (keys.Contains(GetKeyCode())) {
          keyText = string::Format("{0}", (char32)GetKeyCode());
          text = keyText.Data();
      } else {
        text = Fl::event_text();
      }
      int32 length = Fl::event_length();
      
      if (length > 4)
        length = 4;
      
      for (int32 i = 0; i < length; i++) {
        decoder.Add(text[i]);
        if (decoder.CodePointDefined())
          return decoder.CodePoint();
      }
      return 0;
    }
    
    static System::Windows::Forms::Keys GetKeyCode() {
      using namespace System::Windows::Forms;
      System::Collections::Generic::SortedDictionary<int32, Keys> keys {
        {FL_BackSpace, Keys::Back}, {FL_Tab, Keys::Tab}, {FL_Iso_Key, Keys::OemBackslash},{FL_Enter, Keys::Enter}, {FL_Pause, Keys::Pause}, {FL_Scroll_Lock, Keys::Scroll}, {FL_Escape, Keys::Escape},
        {FL_Kana, Keys::Delete}, {FL_Eisu, Keys::Help}, {FL_Yen, Keys::D0}, {FL_JIS_Underscore, Keys::D1}, {FL_Home, Keys::Home}, {FL_Left, Keys::Left}, {FL_Up, Keys::Up}, {FL_Right, Keys::Right},
        {FL_Down, Keys::Down}, {FL_Page_Up, Keys::PageUp}, {FL_Page_Down, Keys::PageDown}, {FL_End, Keys::End}, {FL_Print, Keys::PrintScreen}, {FL_Insert, Keys::Insert}, {FL_Menu, Keys::Menu},
        {FL_Help, Keys::Help}, {FL_Num_Lock, Keys::NumLock}, {FL_KP + 0, Keys::NumPad0}, {FL_KP + 1, Keys::NumPad1}, {FL_KP + 2, Keys::NumPad2}, {FL_KP + 3, Keys::NumPad3}, {FL_KP + 4, Keys::NumPad4},
        {FL_KP + 5, Keys::NumPad5}, {FL_KP + 6, Keys::NumPad6}, {FL_KP + 7, Keys::NumPad7}, {FL_KP + 8, Keys::NumPad8}, {FL_KP + 9, Keys::NumPad9}, {FL_KP_Enter, Keys::Enter}, {FL_F+1, Keys::F1},
        {FL_F+2, Keys::F2}, {FL_F+3, Keys::F3}, {FL_F+4, Keys::F4}, {FL_F+5, Keys::F5}, {FL_F+6, Keys::F6}, {FL_F+7, Keys::F7}, {FL_F+8, Keys::F8}, {FL_F+9, Keys::F9}, {FL_F+10, Keys::F10},
        {FL_F+11, Keys::F11}, {FL_F+12, Keys::F12}, {FL_F+13, Keys::F13}, {FL_F+14, Keys::F14}, {FL_F+15, Keys::F15}, {FL_F+16, Keys::F16}, {FL_F+17, Keys::F17}, {FL_F+18, Keys::F18}, {FL_F+19, Keys::F19},
        {FL_F+20, Keys::F20}, {FL_F+21, Keys::F21}, {FL_F+22, Keys::F22}, {FL_F+23, Keys::F23}, {FL_F+24, Keys::F24}, {FL_Shift_L, Keys::ShiftKey /*Keys::LShiftKey*/}, {FL_Shift_R, Keys::ShiftKey /*Keys::RShiftKey*/},
        {FL_Control_L, Keys::ControlKey /*Keys::LControlKey*/}, {FL_Control_R, Keys::ControlKey /*Keys::RControlKey*/}, {FL_Caps_Lock, Keys::CapsLock},
#if _WIN32
        {FL_Meta_L, Keys::LWin}, {FL_Meta_R, Keys::RWin},
#else
        {FL_Meta_L, Keys::CommandKey /*Keys::LCommandKey*/}, {FL_Meta_R, Keys::CommandKey /*Keys::RCommandKey*/},
#endif
        {FL_Alt_L, Keys::Alt /*KeysLAlt*/}, {FL_Alt_R, Keys::Alt /*Keys::RAlt*/}, {FL_Delete, Keys::Delete}, {0x0027, Keys::OemQuotes}, {0xFFAA, Keys::Multiply}, {0xFFAB, Keys::Add}, {0xFFAD, Keys::Subtract},
        {0xFFAE, Keys::Decimal}, {0xFFAF, Keys::Divide}, {0xFFBD, Keys::Packet}, {0x0029, Keys::OemOpenBrackets}, {0x002C, Keys::Oemcomma}, {0x002D, Keys::OemMinus}, {0x002E, Keys::OemPeriod},
        {0x002F, Keys::OemQuestion}, {0x003A, Keys::Oemtilde}, {0x003B, Keys::OemSemicolon}, {0x003C, Keys::OemBackslash}, {0x003D, Keys::Oemplus}, {0x005B, Keys::OemOpenBrackets}, {0x005C, Keys::OemPipe},
        {0x005D, Keys::OemCloseBrackets}, {0x0060, Keys::Oemtilde}
      };
      
      int32 key = Fl::event_key();
      if (Fl::event_ctrl() && key >= 'a' && key <= 'z')
        key -= 96;
      if (key >= 'a' && key <= 'z')
        key -= 32;
      
      Keys keyCode = static_cast<Keys>(key);;
      if (keys.ContainsKey(key))
        keyCode = keys[key];
      
#if !_WIN32
      if (Fl::event_command())
        keyCode |= static_cast<Keys>(0x80000);
      else
#endif
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
    
    static int32 GetKeyState() {
      using namespace System::Windows::Forms;
      int32 keyState = 0;
      
      if (System::Enum<MouseButtons>(GetMouseButton()).HasFlag(MouseButtons::Left))
        keyState += 1;
      
      if (System::Enum<MouseButtons>(GetMouseButton()).HasFlag(MouseButtons::Right))
        keyState += 2;
      
      if (System::Enum<Keys>((Keys)GetKeyCode()).HasFlag(Keys::Shift))
        keyState += 4;
      
      if (System::Enum<Keys>((Keys)GetKeyCode()).HasFlag(Keys::Control))
        keyState += 8;
      
      if (System::Enum<MouseButtons>(GetMouseButton()).HasFlag(MouseButtons::Middle))
        keyState += 16;
      
      if (System::Enum<Keys>((Keys)GetKeyCode()).HasFlag(Keys::Alt))
        keyState += 32;
      
      if (System::Enum<Keys>((Keys)GetKeyCode()).HasFlag(Keys::Command))
        keyState += 64;
      
      return keyState;
    }
    
    static System::Windows::Forms::MouseButtons GetMouseButton() {
      switch (Fl::event_button()) {
        case FL_LEFT_MOUSE: return System::Windows::Forms::MouseButtons::Left;
        case FL_RIGHT_MOUSE: return System::Windows::Forms::MouseButtons::Right;
        case FL_MIDDLE_MOUSE: return System::Windows::Forms::MouseButtons::Middle;
      }
      return System::Windows::Forms::MouseButtons::Left;
    }
    
    static System::Drawing::Color ToColor(Fl_Color color) {
      return System::Drawing::Color::FromArgb(0xFF000000 + (color>>8));
    }
    
    static Fl_Color ToFlColor(const System::Drawing::Color& color) {
      return fl_rgb_color(static_cast<byte>(color.R()), static_cast<byte>(color.G()), static_cast<byte>(color.B()));
    }

    static int32 ToFlShortcut(System::Windows::Forms::Shortcut shortcut) {
      using namespace System::Windows::Forms;
      System::Collections::Generic::SortedDictionary<System::Enum<System::Windows::Forms::Shortcut>, int32> shortcuts {
        {Shortcut::Alt0, FL_ALT + '0'}, {Shortcut::Alt1, FL_ALT + '1'}, {Shortcut::Alt2, FL_ALT + '2'}, {Shortcut::Alt3, FL_ALT + '3'}, {Shortcut::Alt4, FL_ALT + '4'}, {Shortcut::Alt5, FL_ALT + '5'},
        {Shortcut::Alt6, FL_ALT + '6'}, {Shortcut::Alt7, FL_ALT + '7'}, {Shortcut::Alt8, FL_ALT + '8'}, {Shortcut::Alt9, FL_ALT + '9'}, {Shortcut::AltBksp, FL_ALT + FL_BackSpace},
        {Shortcut::AltDownArrow, FL_ALT + FL_Down}, {Shortcut::AltUpArrow, FL_ALT + FL_Up}, {Shortcut::AltLeftArrow, FL_ALT + FL_Left}, {Shortcut::AltRightArrow, FL_ALT + FL_Right},
        {Shortcut::AltF1, FL_ALT + FL_F + 1}, {Shortcut::AltF2, FL_ALT + FL_F + 2}, {Shortcut::AltF3, FL_ALT + FL_F + 3}, {Shortcut::AltF4, FL_ALT + FL_F + 4}, {Shortcut::AltF5, FL_ALT + FL_F + 5},
        {Shortcut::AltF6, FL_ALT + FL_F + 6}, {Shortcut::AltF7, FL_ALT + FL_F + 7}, {Shortcut::AltF8, FL_ALT + FL_F + 8}, {Shortcut::AltF9, FL_ALT + FL_F + 9}, {Shortcut::AltF10, FL_ALT + FL_F + 10},
        {Shortcut::AltF11, FL_ALT + FL_F + 11}, {Shortcut::AltF12, FL_ALT + FL_F + 12},
        {Shortcut::Cmd0, FL_COMMAND + '0'}, {Shortcut::Cmd1, FL_COMMAND + '1'}, {Shortcut::Cmd2, FL_COMMAND + '2'}, {Shortcut::Cmd3, FL_COMMAND + '3'},
        {Shortcut::Cmd4, FL_COMMAND + '4'}, {Shortcut::Cmd5, FL_COMMAND + '5'}, {Shortcut::Cmd6, FL_COMMAND + '6'}, {Shortcut::Cmd7, FL_COMMAND + '7'}, {Shortcut::Cmd8, FL_COMMAND + '8'},
        {Shortcut::Cmd9, FL_COMMAND + '9'}, {Shortcut::CmdA, FL_COMMAND + 'a'}, {Shortcut::CmdB, FL_COMMAND + 'b'}, {Shortcut::CmdC, FL_COMMAND + 'c'}, {Shortcut::CmdD, FL_COMMAND + 'D'},
        {Shortcut::CmdE, FL_COMMAND + 'e'}, {Shortcut::CmdF, FL_COMMAND + 'f'}, {Shortcut::CmdG, FL_COMMAND + 'g'}, {Shortcut::CmdH, FL_COMMAND + 'h'}, {Shortcut::CmdI, FL_COMMAND + 'i'},
        {Shortcut::CmdJ, FL_COMMAND + 'j'}, {Shortcut::CmdK, FL_COMMAND + 'k'}, {Shortcut::CmdL, FL_COMMAND + 'l'}, {Shortcut::CmdM, FL_COMMAND + 'm'}, {Shortcut::CmdN, FL_COMMAND + 'n'},
        {Shortcut::CmdO, FL_COMMAND + 'o'}, {Shortcut::CmdP, FL_COMMAND + 'p'}, {Shortcut::CmdQ, FL_COMMAND + 'q'}, {Shortcut::CmdR, FL_COMMAND + 'r'}, {Shortcut::CmdS, FL_COMMAND + 's'},
        {Shortcut::CmdT, FL_COMMAND + 't'}, {Shortcut::CmdU, FL_COMMAND + 'u'}, {Shortcut::CmdV, FL_COMMAND + 'v'}, {Shortcut::CmdW, FL_COMMAND + 'w'}, {Shortcut::CmdX, FL_COMMAND + 'x'},
        {Shortcut::CmdY, FL_COMMAND + 'y'}, {Shortcut::CmdZ, FL_COMMAND + 'z'}
      };
      
      if (shortcuts.ContainsKey(shortcut))
        return shortcuts[shortcut];
      
      switch (shortcut) {
        case System::Windows::Forms::Shortcut::CmdF1: return FL_COMMAND + FL_F + 1;
        case System::Windows::Forms::Shortcut::CmdF2: return FL_COMMAND + FL_F + 2;
        case System::Windows::Forms::Shortcut::CmdF3: return FL_COMMAND + FL_F + 3;
        case System::Windows::Forms::Shortcut::CmdF4: return FL_COMMAND + FL_F + 4;
        case System::Windows::Forms::Shortcut::CmdF5: return FL_COMMAND + FL_F + 5;
        case System::Windows::Forms::Shortcut::CmdF6: return FL_COMMAND + FL_F + 6;
        case System::Windows::Forms::Shortcut::CmdF7: return FL_COMMAND + FL_F + 7;
        case System::Windows::Forms::Shortcut::CmdF8: return FL_COMMAND + FL_F + 8;
        case System::Windows::Forms::Shortcut::CmdF9: return FL_COMMAND + FL_F + 9;
        case System::Windows::Forms::Shortcut::CmdF10: return FL_COMMAND + FL_F + 10;
        case System::Windows::Forms::Shortcut::CmdF11: return FL_COMMAND + FL_F + 11;
        case System::Windows::Forms::Shortcut::CmdF12: return FL_COMMAND + FL_F + 12;
          
        case System::Windows::Forms::Shortcut::CmdDel: return FL_COMMAND + FL_Delete;
        case System::Windows::Forms::Shortcut::CmdIns: return FL_COMMAND + FL_Insert;
          
        case System::Windows::Forms::Shortcut::CmdShift0: return FL_COMMAND + FL_SHIFT + '0';
        case System::Windows::Forms::Shortcut::CmdShift1: return FL_COMMAND + FL_SHIFT + '1';
        case System::Windows::Forms::Shortcut::CmdShift2: return FL_COMMAND + FL_SHIFT + '2';
        case System::Windows::Forms::Shortcut::CmdShift3: return FL_COMMAND + FL_SHIFT + '3';
        case System::Windows::Forms::Shortcut::CmdShift4: return FL_COMMAND + FL_SHIFT + '4';
        case System::Windows::Forms::Shortcut::CmdShift5: return FL_COMMAND + FL_SHIFT + '5';
        case System::Windows::Forms::Shortcut::CmdShift6: return FL_COMMAND + FL_SHIFT + '6';
        case System::Windows::Forms::Shortcut::CmdShift7: return FL_COMMAND + FL_SHIFT + '7';
        case System::Windows::Forms::Shortcut::CmdShift8: return FL_COMMAND + FL_SHIFT + '8';
        case System::Windows::Forms::Shortcut::CmdShift9: return FL_COMMAND + FL_SHIFT + '9';
        case System::Windows::Forms::Shortcut::CmdShiftA: return FL_COMMAND + FL_SHIFT + 'a';
        case System::Windows::Forms::Shortcut::CmdShiftB: return FL_COMMAND + FL_SHIFT + 'b';
        case System::Windows::Forms::Shortcut::CmdShiftC: return FL_COMMAND + FL_SHIFT + 'c';
        case System::Windows::Forms::Shortcut::CmdShiftD: return FL_COMMAND + FL_SHIFT + 'd';
        case System::Windows::Forms::Shortcut::CmdShiftE: return FL_COMMAND + FL_SHIFT + 'e';
        case System::Windows::Forms::Shortcut::CmdShiftF: return FL_COMMAND + FL_SHIFT + 'f';
        case System::Windows::Forms::Shortcut::CmdShiftG: return FL_COMMAND + FL_SHIFT + 'g';
        case System::Windows::Forms::Shortcut::CmdShiftH: return FL_COMMAND + FL_SHIFT + 'h';
        case System::Windows::Forms::Shortcut::CmdShiftI: return FL_COMMAND + FL_SHIFT + 'i';
        case System::Windows::Forms::Shortcut::CmdShiftJ: return FL_COMMAND + FL_SHIFT + 'j';
        case System::Windows::Forms::Shortcut::CmdShiftK: return FL_COMMAND + FL_SHIFT + 'k';
        case System::Windows::Forms::Shortcut::CmdShiftL: return FL_COMMAND + FL_SHIFT + 'l';
        case System::Windows::Forms::Shortcut::CmdShiftM: return FL_COMMAND + FL_SHIFT + 'm';
        case System::Windows::Forms::Shortcut::CmdShiftN: return FL_COMMAND + FL_SHIFT + 'n';
        case System::Windows::Forms::Shortcut::CmdShiftO: return FL_COMMAND + FL_SHIFT + 'o';
        case System::Windows::Forms::Shortcut::CmdShiftP: return FL_COMMAND + FL_SHIFT + 'p';
        case System::Windows::Forms::Shortcut::CmdShiftQ: return FL_COMMAND + FL_SHIFT + 'q';
        case System::Windows::Forms::Shortcut::CmdShiftR: return FL_COMMAND + FL_SHIFT + 'r';
        case System::Windows::Forms::Shortcut::CmdShiftS: return FL_COMMAND + FL_SHIFT + 's';
        case System::Windows::Forms::Shortcut::CmdShiftT: return FL_COMMAND + FL_SHIFT + 't';
        case System::Windows::Forms::Shortcut::CmdShiftU: return FL_COMMAND + FL_SHIFT + 'u';
        case System::Windows::Forms::Shortcut::CmdShiftV: return FL_COMMAND + FL_SHIFT + 'v';
        case System::Windows::Forms::Shortcut::CmdShiftW: return FL_COMMAND + FL_SHIFT + 'w';
        case System::Windows::Forms::Shortcut::CmdShiftX: return FL_COMMAND + FL_SHIFT + 'x';
        case System::Windows::Forms::Shortcut::CmdShiftY: return FL_COMMAND + FL_SHIFT + 'y';
        case System::Windows::Forms::Shortcut::CmdShiftZ: return FL_COMMAND + FL_SHIFT + 'z';

        case System::Windows::Forms::Shortcut::CmdShiftF1: return FL_COMMAND + FL_SHIFT + FL_F + 1;
        case System::Windows::Forms::Shortcut::CmdShiftF2: return FL_COMMAND + FL_SHIFT + FL_F + 2;
        case System::Windows::Forms::Shortcut::CmdShiftF3: return FL_COMMAND + FL_SHIFT + FL_F + 3;
        case System::Windows::Forms::Shortcut::CmdShiftF4: return FL_COMMAND + FL_SHIFT + FL_F + 4;
        case System::Windows::Forms::Shortcut::CmdShiftF5: return FL_COMMAND + FL_SHIFT + FL_F + 5;
        case System::Windows::Forms::Shortcut::CmdShiftF6: return FL_COMMAND + FL_SHIFT + FL_F + 6;
        case System::Windows::Forms::Shortcut::CmdShiftF7: return FL_COMMAND + FL_SHIFT + FL_F + 7;
        case System::Windows::Forms::Shortcut::CmdShiftF8: return FL_COMMAND + FL_SHIFT + FL_F + 8;
        case System::Windows::Forms::Shortcut::CmdShiftF9: return FL_COMMAND + FL_SHIFT + FL_F + 9;
        case System::Windows::Forms::Shortcut::CmdShiftF10: return FL_COMMAND + FL_SHIFT + FL_F + 10;
        case System::Windows::Forms::Shortcut::CmdShiftF11: return FL_COMMAND + FL_SHIFT + FL_F + 11;
        case System::Windows::Forms::Shortcut::CmdShiftF12: return FL_COMMAND + FL_SHIFT + FL_F + 12;

        case System::Windows::Forms::Shortcut::Del: return FL_Delete;
        case System::Windows::Forms::Shortcut::Ins: return FL_Insert;

        case System::Windows::Forms::Shortcut::F1: return FL_F + 1;
        case System::Windows::Forms::Shortcut::F10: return FL_F + 10;
        case System::Windows::Forms::Shortcut::F11: return FL_F + 11;
        case System::Windows::Forms::Shortcut::F12: return FL_F + 12;
        case System::Windows::Forms::Shortcut::F2: return FL_F + 2;
        case System::Windows::Forms::Shortcut::F3: return FL_F + 3;
        case System::Windows::Forms::Shortcut::F4: return FL_F + 4;
        case System::Windows::Forms::Shortcut::F5: return FL_F + 5;
        case System::Windows::Forms::Shortcut::F6: return FL_F + 6;
        case System::Windows::Forms::Shortcut::F7: return FL_F + 7;
        case System::Windows::Forms::Shortcut::F8: return FL_F + 8;
        case System::Windows::Forms::Shortcut::F9: return FL_F + 9;

        case System::Windows::Forms::Shortcut::ShiftDel: return FL_SHIFT + FL_Delete;
        case System::Windows::Forms::Shortcut::ShiftIns: return FL_SHIFT + FL_Insert;

        case System::Windows::Forms::Shortcut::ShiftF1: return FL_SHIFT + FL_F + 1;
        case System::Windows::Forms::Shortcut::ShiftF10: return FL_SHIFT + FL_F + 10;
        case System::Windows::Forms::Shortcut::ShiftF11: return FL_SHIFT + FL_F + 11;
        case System::Windows::Forms::Shortcut::ShiftF12: return FL_SHIFT + FL_F + 12;
        case System::Windows::Forms::Shortcut::ShiftF2: return FL_SHIFT + FL_F + 2;
        case System::Windows::Forms::Shortcut::ShiftF3: return FL_SHIFT + FL_F + 3;
        case System::Windows::Forms::Shortcut::ShiftF4: return FL_SHIFT + FL_F + 4;
        case System::Windows::Forms::Shortcut::ShiftF5: return FL_SHIFT + FL_F + 5;
        case System::Windows::Forms::Shortcut::ShiftF6: return FL_SHIFT + FL_F + 6;
        case System::Windows::Forms::Shortcut::ShiftF7: return FL_SHIFT + FL_F + 7;
        case System::Windows::Forms::Shortcut::ShiftF8: return FL_SHIFT + FL_F + 8;
        case System::Windows::Forms::Shortcut::ShiftF9: return FL_SHIFT + FL_F + 9;
        default: break;
      }
      
      int32 key = 0;
      bool isShift = (static_cast<int>(shortcut) & static_cast<int>(Pcf::System::Windows::Forms::Keys::Shift)) == static_cast<int>(Pcf::System::Windows::Forms::Keys::Shift);
      
      if ((static_cast<int>(shortcut) & static_cast<int>(Pcf::System::Windows::Forms::Keys::Alt)) == static_cast<int>(Pcf::System::Windows::Forms::Keys::Alt))
        key += FL_ALT;
      
      if ((static_cast<int>(shortcut) & static_cast<int>(Pcf::System::Windows::Forms::Keys::Command)) == static_cast<int>(Pcf::System::Windows::Forms::Keys::Command))
        key += FL_COMMAND;
      
      if ((static_cast<int>(shortcut) & static_cast<int>(Pcf::System::Windows::Forms::Keys::Control)) == static_cast<int>(Pcf::System::Windows::Forms::Keys::Control))
        key += FL_CONTROL;
      
      if ((static_cast<int>(shortcut) & static_cast<int>(Pcf::System::Windows::Forms::Keys::Shift)) == static_cast<int>(Pcf::System::Windows::Forms::Keys::Shift))
        key += FL_SHIFT;
      
      shortcut = static_cast<System::Windows::Forms::Shortcut>(static_cast<int>(shortcut) & 0xFFFF);
      
      if (! isShift && static_cast<int>(shortcut) >= 'A' && static_cast<int>(shortcut) <= 'Z')
        return key + static_cast<int>(shortcut) + 32;
      
      return key + static_cast<int>(shortcut);
    }
  };
}
