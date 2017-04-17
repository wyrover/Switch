/// @file
/// @brief Contains Pcf::System::Windows::Forms::Keys enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        enum class Keys {
          None = 0,
          LButton = 1,
          RButton = 2,
          Cancel = 3,
          MButton = 4,
          XButton1 = 5,
          XButton2 = 6,
          Back = 8,
          Tab = 9,
          LineFeed = 10,
          Clear = 12,
          Return = 13,
          Enter = 13,
          ShiftKey = 16,
          ControlKey = 17,
          Menu = 18,
          Pause = 19,
          CapsLock = 20,
          Capital = 20,
          KanaMode = 21,
          HanguelMode = 21,
          HangulMode = 21,
          JunjaMode = 23,
          FinalMode = 24,
          KanjiMode = 25,
          HanjaMode = 25,
          Escape = 27,
          IMEConvert = 28,
          IMENonconvert = 29,
          IMEAceept = 30,
          IMEModeChange = 31,
          Space = 32,
          PageUp = 33,
          Prior = 33,
          PageDown = 34,
          Next = 34,
          End = 35,
          Home = 36,
          Left = 37,
          Up = 38,
          Right = 39,
          Down = 40,
          Select = 41,
          Print = 42,
          Execute = 43,
          PrintScreen = 44,
          Snapshot = 44,
          Insert = 45,
          Delete = 46,
          Help = 47,
          D0 = 48,
          D1 = 49,
          D2 = 50,
          D3 = 51,
          D4 = 52,
          D5 = 53,
          D6 = 54,
          D7 = 55,
          D8 = 56,
          D9 = 57,
          A = 65,
          B = 66,
          C = 67,
          D = 68,
          E = 69,
          F = 70,
          G = 71,
          H = 72,
          I = 73,
          J = 74,
          K = 75,
          L = 76,
          M = 77,
          N = 78,
          O = 79,
          P = 80,
          Q = 81,
          R = 82,
          S = 83,
          T = 84,
          U = 85,
          V = 86,
          W = 87,
          X = 88,
          Y = 89,
          Z = 90,
          LWin = 91,
          RWin = 92,
          Apps = 93,
          NumPad0 = 96,
          NumPad1 = 97,
          NumPad2 = 98,
          NumPad3 = 99,
          NumPad4 = 100,
          NumPad5 = 101,
          NumPad6 = 102,
          NumPad7 = 103,
          NumPad8 = 104,
          NumPad9 = 105,
          Multiply = 106,
          Add = 107,
          Separator = 108,
          Subtract = 109,
          Decimal = 110,
          Divide = 111,
          F1 = 112,
          F2 = 113,
          F3 = 114,
          F4 = 115,
          F5 = 116,
          F6 = 117,
          F7 = 118,
          F8 = 119,
          F9 = 120,
          F10 = 121,
          F11 = 122,
          F12 = 123,
          F13 = 124,
          F14 = 125,
          F15 = 126,
          F16 = 127,
          F17 = 128,
          F18 = 129,
          F19 = 130,
          F20 = 131,
          F21 = 132,
          F22 = 133,
          F23 = 134,
          F24 = 135,
          NumLock = 144,
          Scroll = 145,
          LShiftKey = 160,
          RShiftKey = 161,
          LControlKey = 162,
          RControlKey = 163,
          LMenu = 164,
          RMenu = 165,
          BrowserBack = 166,
          BrowserForward = 167,
          BrowserRefresh = 168,
          BrowserStop = 169,
          BrowserSearch = 170,
          BrowserFavorites = 171,
          BrowserHome = 172,
          VolumeMute = 173,
          VolumeDown = 174,
          VolumeUp = 175,
          MediaNextTrack = 176,
          MediaPreviousTrack = 177,
          MediaStop = 178,
          MediaPlayPause = 179,
          LaunchMail = 180,
          SelectMedia = 181,
          LaunchApplication1 = 182,
          LaunchApplication2 = 183,
          OemSemicolon = 186,
          Oemplus = 187,
          Oemcomma = 188,
          OemMinus = 189,
          OemPeriod = 190,
          OemQuestion = 191,
          Oemtilde = 192,
          OemOpenBrackets = 219,
          OemPipe = 220,
          OemCloseBrackets = 221,
          OemQuotes = 222,
          Oem8 = 223,
          OemBackslash = 226,
          ProcessKey = 229,
          Attn = 246,
          Crsel = 247,
          Exsel = 248,
          EraseEof = 249,
          Play = 250,
          Zoom = 251,
          NoName = 252,
          Pa1 = 253,
          OemClear = 254,
          KeyCode = 65535,
          Shift = 65536,
          Control = 131072,
          Alt = 262144,
          Command = 524288,
          Modifiers = -65536,
          IMEAccept = 30,
          Oem1 = 186,
          Oem102 = 226,
          Oem2 = 191,
          Oem3 = 192,
          Oem4 = 219,
          Oem5 = 220,
          Oem6 = 221,
          Oem7 = 222,
          Packet = 231,
          Sleep = 95,
          CommandKey = 255,
          LCommandKey = 256,
          RCommandKey = 257,
        };
        
        /// @cond
        inline Keys& operator +=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) + static_cast<int32>(rhs)); return lhs;}
        inline Keys& operator -=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) - static_cast<int32>(rhs)); return lhs;}
        inline Keys& operator &=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) & static_cast<int32>(rhs)); return lhs;}
        inline Keys& operator |=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) | static_cast<int32>(rhs)); return lhs;}
        inline Keys& operator ^=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) ^ static_cast<int32>(rhs)); return lhs;}
        inline Keys operator +(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) + static_cast<int32>(rhs));}
        inline Keys operator -(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) - static_cast<int32>(rhs));}
        inline Keys operator ~(Keys rhs) { return static_cast<Keys>(~ static_cast<int32>(rhs));}
        inline Keys operator &(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) & static_cast<int32>(rhs));}
        inline Keys operator |(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) | static_cast<int32>(rhs));}
        inline Keys operator ^(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) ^ static_cast<int32>(rhs));}
        /// @endcond
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::Keys> : public TrueType {};

template<>
class EnumToStrings<System::Windows::Forms::Keys> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::Keys::None, "None"}, {(int64)System::Windows::Forms::Keys::LButton, "LButton"}, {(int64)System::Windows::Forms::Keys::RButton, "RButton"}, {(int64)System::Windows::Forms::Keys::Cancel, "Cancel"}, {(int64)System::Windows::Forms::Keys::MButton, "None"}, {(int64)System::Windows::Forms::Keys::XButton1, "XButton1"}, {(int64)System::Windows::Forms::Keys::XButton2, "XButton2"}, {(int64)System::Windows::Forms::Keys::Back, "Back"}, {(int64)System::Windows::Forms::Keys::Tab, "Tab"}, {(int64)System::Windows::Forms::Keys::LineFeed, "LineFeed"}, {(int64)System::Windows::Forms::Keys::Clear, "Clear"}, {(int64)System::Windows::Forms::Keys::Return, "Return"}, /*{(int64)System::Windows::Forms::Keys::Enter, "Enter"},*/ {(int64)System::Windows::Forms::Keys::ShiftKey, "ShiftKey"}, {(int64)System::Windows::Forms::Keys::ControlKey, "ControlKey"}, {(int64)System::Windows::Forms::Keys::Menu, "Menu"}, {(int64)System::Windows::Forms::Keys::Pause, "Pause"}, {(int64)System::Windows::Forms::Keys::CapsLock, "CapsLock"}, /*{(int64)System::Windows::Forms::Keys::Capital, "Capital"},*/ {(int64)System::Windows::Forms::Keys::KanaMode, "KanaMode"}, /*{(int64)System::Windows::Forms::Keys::HanguelMode, "HanguelMode"}, {(int64)System::Windows::Forms::Keys::HangulMode, "HangulMode"},*/ {(int64)System::Windows::Forms::Keys::JunjaMode, "JunjaMode"}, {(int64)System::Windows::Forms::Keys::FinalMode, "FinalMode"}, {(int64)System::Windows::Forms::Keys::KanjiMode, "KanjiMode"}, /*{(int64)System::Windows::Forms::Keys::HanjaMode, "HanjaMode"},*/ {(int64)System::Windows::Forms::Keys::Escape, "Escape"}, {(int64)System::Windows::Forms::Keys::IMEConvert, "IMEConvert"}, {(int64)System::Windows::Forms::Keys::IMENonconvert, "IMENonconvert"}, {(int64)System::Windows::Forms::Keys::IMEModeChange, "IMEModeChange"}, {(int64)System::Windows::Forms::Keys::Space, "Space"}, {(int64)System::Windows::Forms::Keys::PageUp, "PageUp"}, /*{(int64)System::Windows::Forms::Keys::Prior, "Prior"},*/ {(int64)System::Windows::Forms::Keys::PageDown, "PageDown"}, /*{(int64)System::Windows::Forms::Keys::Next, "Next"},*/ {(int64)System::Windows::Forms::Keys::End, "End"}, {(int64)System::Windows::Forms::Keys::Home, "Home"}, {(int64)System::Windows::Forms::Keys::Left, "Left"}, {(int64)System::Windows::Forms::Keys::Up, "Up"}, {(int64)System::Windows::Forms::Keys::Right, "Right"}, {(int64)System::Windows::Forms::Keys::Down, "Down"}, {(int64)System::Windows::Forms::Keys::Select, "Select"}, {(int64)System::Windows::Forms::Keys::Print, "Print"}, {(int64)System::Windows::Forms::Keys::Execute, "Execute"}, {(int64)System::Windows::Forms::Keys::PrintScreen, "PrintScreen"}, /*{(int64)System::Windows::Forms::Keys::Snapshot, "Snapshot"},*/ {(int64)System::Windows::Forms::Keys::Insert, "Insert"}, {(int64)System::Windows::Forms::Keys::Delete, "Delete"}, {(int64)System::Windows::Forms::Keys::Help, "Help"}, {(int64)System::Windows::Forms::Keys::D0, "D0"}, {(int64)System::Windows::Forms::Keys::D1, "D1"}, {(int64)System::Windows::Forms::Keys::D2, "D2"}, {(int64)System::Windows::Forms::Keys::D3, "D3"}, {(int64)System::Windows::Forms::Keys::D4, "D4"}, {(int64)System::Windows::Forms::Keys::D5, "D5"}, {(int64)System::Windows::Forms::Keys::D6, "D6"}, {(int64)System::Windows::Forms::Keys::D7, "D7"}, {(int64)System::Windows::Forms::Keys::D8, "D8"}, {(int64)System::Windows::Forms::Keys::D9, "D9"}, {(int64)System::Windows::Forms::Keys::A, "A"}, {(int64)System::Windows::Forms::Keys::B, "B"}, {(int64)System::Windows::Forms::Keys::C, "C"}, {(int64)System::Windows::Forms::Keys::D, "D"}, {(int64)System::Windows::Forms::Keys::E, "E"}, {(int64)System::Windows::Forms::Keys::F, "F"}, {(int64)System::Windows::Forms::Keys::G, "G"}, {(int64)System::Windows::Forms::Keys::H, "H"}, {(int64)System::Windows::Forms::Keys::I, "I"}, {(int64)System::Windows::Forms::Keys::J, "J"}, {(int64)System::Windows::Forms::Keys::K, "K"}, {(int64)System::Windows::Forms::Keys::L, "L"}, {(int64)System::Windows::Forms::Keys::M, "M"}, {(int64)System::Windows::Forms::Keys::N, "N"}, {(int64)System::Windows::Forms::Keys::O, "O"}, {(int64)System::Windows::Forms::Keys::P, "P"}, {(int64)System::Windows::Forms::Keys::Q, "Q"}, {(int64)System::Windows::Forms::Keys::R, "R"}, {(int64)System::Windows::Forms::Keys::S, "S"}, {(int64)System::Windows::Forms::Keys::T, "T"}, {(int64)System::Windows::Forms::Keys::U, "U"}, {(int64)System::Windows::Forms::Keys::V, "V"}, {(int64)System::Windows::Forms::Keys::W, "W"}, {(int64)System::Windows::Forms::Keys::X, "X"}, {(int64)System::Windows::Forms::Keys::Y, "Y"}, {(int64)System::Windows::Forms::Keys::Z, "Z"}, {(int64)System::Windows::Forms::Keys::LWin, "LWin"}, {(int64)System::Windows::Forms::Keys::RWin, "RWin"}, {(int64)System::Windows::Forms::Keys::Apps, "Apps"}, {(int64)System::Windows::Forms::Keys::NumPad0, "NumPad0"}, {(int64)System::Windows::Forms::Keys::NumPad1, "NumPad1"}, {(int64)System::Windows::Forms::Keys::NumPad2, "NumPad2"}, {(int64)System::Windows::Forms::Keys::NumPad3, "NumPad3"}, {(int64)System::Windows::Forms::Keys::NumPad4, "NumPad4"}, {(int64)System::Windows::Forms::Keys::NumPad5, "NumPad5"}, {(int64)System::Windows::Forms::Keys::NumPad6, "NumPad6"}, {(int64)System::Windows::Forms::Keys::NumPad7, "NumPad7"}, {(int64)System::Windows::Forms::Keys::NumPad8, "NumPad8"}, {(int64)System::Windows::Forms::Keys::NumPad9, "NumPad9"}, {(int64)System::Windows::Forms::Keys::Multiply, "Multiply"}, {(int64)System::Windows::Forms::Keys::Add, "Add"}, {(int64)System::Windows::Forms::Keys::Separator, "Separator"}, {(int64)System::Windows::Forms::Keys::Subtract, "Subtract"}, {(int64)System::Windows::Forms::Keys::Decimal, "Decimal"}, {(int64)System::Windows::Forms::Keys::Divide, "Divide"}, {(int64)System::Windows::Forms::Keys::F1, "F1"}, {(int64)System::Windows::Forms::Keys::F2, "F2"}, {(int64)System::Windows::Forms::Keys::F3, "F3"}, {(int64)System::Windows::Forms::Keys::F4, "F4"}, {(int64)System::Windows::Forms::Keys::F5, "F5"}, {(int64)System::Windows::Forms::Keys::F6, "F6"}, {(int64)System::Windows::Forms::Keys::F7, "F7"}, {(int64)System::Windows::Forms::Keys::F8, "F8"}, {(int64)System::Windows::Forms::Keys::F9, "F9"}, {(int64)System::Windows::Forms::Keys::F10, "F10"}, {(int64)System::Windows::Forms::Keys::F11, "F11"}, {(int64)System::Windows::Forms::Keys::F12, "F12"}, {(int64)System::Windows::Forms::Keys::F13, "F13"}, {(int64)System::Windows::Forms::Keys::F14, "F14"}, {(int64)System::Windows::Forms::Keys::F15, "F15"}, {(int64)System::Windows::Forms::Keys::F16, "F16"}, {(int64)System::Windows::Forms::Keys::F17, "F17"}, {(int64)System::Windows::Forms::Keys::F18, "F18"}, {(int64)System::Windows::Forms::Keys::F19, "F19"}, {(int64)System::Windows::Forms::Keys::F20, "F20"}, {(int64)System::Windows::Forms::Keys::F21, "F21"}, {(int64)System::Windows::Forms::Keys::F22, "F22"}, {(int64)System::Windows::Forms::Keys::F23, "F23"}, {(int64)System::Windows::Forms::Keys::F24, "F24"}, {(int64)System::Windows::Forms::Keys::NumLock, "NumLock"}, {(int64)System::Windows::Forms::Keys::Scroll, "Scroll"}, {(int64)System::Windows::Forms::Keys::LShiftKey, "LShiftKey"}, {(int64)System::Windows::Forms::Keys::RShiftKey, "RShiftKey"}, {(int64)System::Windows::Forms::Keys::LControlKey, "LControlKey"}, {(int64)System::Windows::Forms::Keys::RControlKey, "RControlKey"}, {(int64)System::Windows::Forms::Keys::LMenu, "LMenu"}, {(int64)System::Windows::Forms::Keys::RMenu, "RMenu"}, {(int64)System::Windows::Forms::Keys::BrowserBack, "BrowserBack"}, {(int64)System::Windows::Forms::Keys::BrowserFavorites, "BrowserFavorites"}, {(int64)System::Windows::Forms::Keys::BrowserForward, "BrowserForward"}, {(int64)System::Windows::Forms::Keys::BrowserHome, "BrowserHome"}, {(int64)System::Windows::Forms::Keys::BrowserRefresh, "BrowserRefresh"}, {(int64)System::Windows::Forms::Keys::BrowserSearch, "BrowserSearch"}, {(int64)System::Windows::Forms::Keys::BrowserStop, "BrowserStop"}, {(int64)System::Windows::Forms::Keys::VolumeDown, "VolumeDown"}, {(int64)System::Windows::Forms::Keys::VolumeMute, "VolumeMute"}, {(int64)System::Windows::Forms::Keys::VolumeUp, "VolumeUp"}, {(int64)System::Windows::Forms::Keys::MediaNextTrack, "MediaNextTrack"}, {(int64)System::Windows::Forms::Keys::MediaPlayPause, "MediaPlayPause"}, {(int64)System::Windows::Forms::Keys::MediaPreviousTrack, "MediaPreviousTrack"}, {(int64)System::Windows::Forms::Keys::MediaStop, "MediaStop"}, {(int64)System::Windows::Forms::Keys::LaunchMail, "LaunchMail"}, {(int64)System::Windows::Forms::Keys::SelectMedia, "SelectMedia"}, {(int64)System::Windows::Forms::Keys::LaunchApplication1, "LaunchApplication1"}, {(int64)System::Windows::Forms::Keys::LaunchApplication2, "LaunchApplication2"}, {(int64)System::Windows::Forms::Keys::Oemplus, "Oemplus"}, {(int64)System::Windows::Forms::Keys::Oemcomma, "Oemcomma"}, {(int64)System::Windows::Forms::Keys::OemMinus, "OemMinus"}, {(int64)System::Windows::Forms::Keys::OemPeriod, "OemPeriod"}, {(int64)System::Windows::Forms::Keys::OemQuestion, "OemQuestion"}, {(int64)System::Windows::Forms::Keys::Oemtilde, "Oemtilde"}, {(int64)System::Windows::Forms::Keys::OemOpenBrackets, "OemOpenBrackets"}, {(int64)System::Windows::Forms::Keys::OemPipe, "OemPipe"}, {(int64)System::Windows::Forms::Keys::OemCloseBrackets, "OemCloseBrackets"}, {(int64)System::Windows::Forms::Keys::OemQuotes, "OemQuotes"}, {(int64)System::Windows::Forms::Keys::Oem8, "Oem8"}, {(int64)System::Windows::Forms::Keys::OemBackslash, "OemBackslash"}, {(int64)System::Windows::Forms::Keys::ProcessKey, "ProcessKey"}, {(int64)System::Windows::Forms::Keys::Attn, "Attn"}, {(int64)System::Windows::Forms::Keys::Crsel, "Crsel"}, {(int64)System::Windows::Forms::Keys::Exsel, "Exsel"}, {(int64)System::Windows::Forms::Keys::EraseEof, "EraseEof"}, {(int64)System::Windows::Forms::Keys::Play, "Play"}, {(int64)System::Windows::Forms::Keys::Zoom, "Zoom"}, {(int64)System::Windows::Forms::Keys::NoName, "NoName"}, {(int64)System::Windows::Forms::Keys::Pa1, "Pa1"}, {(int64)System::Windows::Forms::Keys::OemClear, "OemClear"}, {(int64)System::Windows::Forms::Keys::KeyCode, "KeyCode"}, {(int64)System::Windows::Forms::Keys::Shift, "Shift"}, {(int64)System::Windows::Forms::Keys::Control, "Control"}, {(int64)System::Windows::Forms::Keys::Alt, "Alt"}, {(int64)System::Windows::Forms::Keys::Command, "Command"}, {(int64)System::Windows::Forms::Keys::Modifiers, "Modifiers"}, {(int64)System::Windows::Forms::Keys::IMEAccept, "IMEAccept"}, {(int64)System::Windows::Forms::Keys::Oem1, "Oem1"}, /*{(int64)System::Windows::Forms::Keys::Oem102, "Oem102"}, {(int64)System::Windows::Forms::Keys::Oem2, "Oem2"}, {(int64)System::Windows::Forms::Keys::Oem3, "Oem3"}, {(int64)System::Windows::Forms::Keys::Oem4, "Oem4"}, {(int64)System::Windows::Forms::Keys::Oem5, "Oem5"}, {(int64)System::Windows::Forms::Keys::Oem6, "Oem6"}, {(int64)System::Windows::Forms::Keys::Oem7, "Oem7"},*/ {(int64)System::Windows::Forms::Keys::Packet, "Packet"}, {(int64)System::Windows::Forms::Keys::Sleep, "Sleep"}, {(int64)System::Windows::Forms::Keys::CommandKey, "CommandKey"}, {(int64)System::Windows::Forms::Keys::LCommandKey, "LCommandKey"}, {(int64)System::Windows::Forms::Keys::RCommandKey, "RCommandKey"}};
    flags = true;
  }
};
/// @endcond