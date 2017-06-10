/// @file
/// @brief Contains Pcf::System::ConsoleKey enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum ConsoleKey
    /// @brief Specifies the standard keys on a console.
    /// @see Console
    enum class ConsoleKey {
      /// @brief The BACKSPACE key.
      Backspace = 8,
      /// @brief The TAB key.
      Tab = 9,
      /// @brief The CLEAR key.
      Clear = 12,
      /// @brief The ENTER key.
      Enter = 13,
      /// @brief The PAUSE key.
      Pause = 19,
      /// @brief The CapsLock key.
      CapsLock = 20,
      /// @brief The ESC (ESCAPE) key.
      Escape = 27,
      /// @brief The SPACEBAR key.
      Spacebar = 32,
      /// @brief The PAGE UP key.
      PageUp = 33,
      /// @brief The PAGE DOWN key.
      PageDown = 34,
      /// @brief The END key.
      End = 35,
      /// @brief The HOME key.
      Home = 36,
      /// @brief The LEFT ARROW key.
      LeftArrow = 37,
      /// @brief The UP ARROW key.
      UpArrow = 38,
      /// @brief The RIGHT ARROW key.
      RightArrow = 39,
      /// @brief The DOWN ARROW key.
      DownArrow = 40,
      /// @brief The SELECT key.
      Select = 41,
      /// @brief The PRINT key.
      Print = 42,
      /// @brief The EXECUTE key.
      Execute = 43,
      /// @brief The PRINT SCREEN key.
      PrintScreen = 44,
      /// @brief The INS (INSERT) key.
      Insert = 45,
      /// @brief The DEL (DELETE) key.
      Delete = 46,
      /// @brief The HELP key.
      Help = 47,
      /// @brief The 0 key.
      D0 = 48,
      /// @brief The 1 key.
      D1 = 49,
      /// @brief The 2 key.
      D2 = 50,
      /// @brief The 3 key.
      D3 = 51,
      /// @brief The 4 key.
      D4 = 52,
      /// @brief The 5 key.
      D5 = 53,
      /// @brief The 6 key.
      D6 = 54,
      /// @brief The 7 key.
      D7 = 55,
      /// @brief The 8 key.
      D8 = 56,
      /// @brief The 9 key.
      D9 = 57,
      /// @brief The A key.
      A = 65,
      /// @brief The B key.
      B = 66,
      /// @brief The C key.
      C = 67,
      /// @brief The D key.
      D = 68,
      /// @brief The E key.
      E = 69,
      /// @brief The F key.
      F = 70,
      /// @brief The G key.
      G = 71,
      /// @brief The H key.
      H = 72,
      /// @brief The I key.
      I = 73,
      /// @brief The J key.
      J = 74,
      /// @brief The K key.
      K = 75,
      /// @brief The L key.
      L = 76,
      /// @brief The M key.
      M = 77,
      /// @brief The N key.
      N = 78,
      /// @brief The O key.
      O = 79,
      /// @brief The P key.
      P = 80,
      /// @brief The Q key.
      Q = 81,
      /// @brief The R key.
      R = 82,
      /// @brief The S key.
      S = 83,
      /// @brief The T key.
      T = 84,
      /// @brief The U key.
      U = 85,
      /// @brief The V key.
      V = 86,
      /// @brief The W key.
      W = 87,
      /// @brief The X key.
      X = 88,
      /// @brief The Y key.
      Y = 89,
      /// @brief The Z key.
      Z = 90,
      /// @brief The left Windows logo key (Microsoft Natural Keyboard).
      LeftWindows = 91,
      /// @brief The right Windows logo key (Microsoft Natural Keyboard).
      RightWindows = 92,
      /// @brief The Application key (Microsoft Natural Keyboard).
      Applications = 93,
      /// @brief The Computer Sleep key.
      Sleep = 95,
      /// @brief The 0 key on the numeric keypad.
      NumPad0 = 96,
      /// @brief The 1 key on the numeric keypad.
      NumPad1 = 97,
      /// @brief The 2 key on the numeric keypad.
      NumPad2 = 98,
      /// @brief The 3 key on the numeric keypad.
      NumPad3 = 99,
      /// @brief The 4 key on the numeric keypad.
      NumPad4 = 100,
      /// @brief The 5 key on the numeric keypad.
      NumPad5 = 101,
      /// @brief The 6 key on the numeric keypad.
      NumPad6 = 102,
      /// @brief The 7 key on the numeric keypad.
      NumPad7 = 103,
      /// @brief The 8 key on the numeric keypad.
      NumPad8 = 104,
      /// @brief The 9 key on the numeric keypad.
      NumPad9 = 105,
      /// @brief The Multiply key.
      Multiply = 106,
      /// @brief The Add key.
      Add = 107,
      /// @brief The Separator key.
      Separator = 108,
      /// @brief The Subtract key.
      Subtract = 109,
      /// @brief The Decimal key.
      Decimal = 110,
      /// @brief The Divide key.
      Divide = 111,
      /// @brief The F1 key.
      F1 = 112,
      /// @brief The F2 key.
      F2 = 113,
      /// @brief The F3 key.
      F3 = 114,
      /// @brief The F4 key.
      F4 = 115,
      /// @brief The F5 key.
      F5 = 116,
      /// @brief The F6 key.
      F6 = 117,
      /// @brief The F7 key.
      F7 = 118,
      /// @brief The F8 key.
      F8 = 119,
      /// @brief The F9 key.
      F9 = 120,
      /// @brief The F10 key.
      F10 = 121,
      /// @brief The F11 key.
      F11 = 122,
      /// @brief The F12 key.
      F12 = 123,
      /// @brief The F13 key.
      F13 = 124,
      /// @brief The F14 key.
      F14 = 125,
      /// @brief The F15 key.
      F15 = 126,
      /// @brief The F16 key.
      F16 = 127,
      /// @brief The F17 key.
      F17 = 128,
      /// @brief The F18 key.
      F18 = 129,
      /// @brief The F19 key.
      F19 = 130,
      /// @brief The F20 key.
      F20 = 131,
      /// @brief The F21 key.
      F21 = 132,
      /// @brief The F22 key.
      F22 = 133,
      /// @brief The F23 key.
      F23 = 134,
      /// @brief The F24 key.
      F24 = 135,
      /// @brief The Browser Back key (Windows 2000 or later).
      BrowserBack = 166,
      /// @brief The Browser Forward key (Windows 2000 or later).
      BrowserForward = 167,
      /// @brief The Browser Refresh key (Windows 2000 or later).
      BrowserRefresh = 168,
      /// @brief The Browser Stop key (Windows 2000 or later).
      BrowserStop = 169,
      /// @brief The Browser Search key (Windows 2000 or later).
      BrowserSearch = 170,
      /// @brief The Browser Favorite key (Windows 2000 or later).
      BrowserFavorites = 171,
      /// @brief The Browser Home key (Windows 2000 or later).
      BrowserHome = 172,
      /// @brief The Volume Mute key (Microsoft Natural Keyboard, Windows 2000 or later).
      VolumeMute = 173,
      /// @brief The Volume Down key (Microsoft Natural Keyboard, Windows 2000 or later).
      VolumeDown = 174,
      /// @brief The Volume Up key (Microsoft Natural Keyboard, Windows 2000 or later).
      VolumeUp = 175,
      /// @brief The Media Next Track key (Microsoft Natural Keyboard, Windows 2000 or later).
      MediaNext = 176,
      /// @brief The Media Previous Track key (Microsoft Natural Keyboard, Windows 2000 or later).
      MediaPrevious = 177,
      /// @brief The Media Stop key (Microsoft Natural Keyboard, Windows 2000 or later).
      MediaStop = 178,
      /// @brief The Media Play/Pause key (Microsoft Natural Keyboard, Windows 2000 or later).
      MediaPlay = 179,
      /// @brief The Start Mail key (Microsoft Natural Keyboard, Windows 2000 or later).
      LaunchMail = 180,
      /// @brief The Select Media key (Microsoft Natural Keyboard, Windows 2000 or later).
      LaunchMediaSelect = 181,
      /// @brief The Start Application 1 key (Microsoft Natural Keyboard, Windows 2000 or later).
      LaunchApp1 = 182,
      /// @brief The Start Application 2 key (Microsoft Natural Keyboard, Windows 2000 or later).
      LaunchApp2 = 183,
      /// @brief The OEM 1 key (OEM specific).
      Oem1 = 186,
      /// @brief The OEM Plus key on any country/region keyboard (Windows 2000 or later).
      OemPlus = 187,
      /// @brief The OEM Comma key on any country/region keyboard (Windows 2000 or later).
      OemComma = 188,
      /// @brief The OEM Minus key on any country/region keyboard (Windows 2000 or later).
      OemMinus = 189,
      /// @brief The OEM Period key on any country/region keyboard (Windows 2000 or later).
      OemPeriod = 190,
      /// @brief The OEM 2 key (OEM specific).
      Oem2 = 191,
      /// @brief The OEM " key (OEM specific).
      Oem3 = 192,
      /// @brief The OEM 4 key (OEM specific).
      Oem4 = 219,
      /// @brief The OEM 5 key (OEM specific).
      Oem5 = 220,
      /// @brief The OEM 6 key (OEM specific).
      Oem6 = 221,
      /// @brief The OEM 7 key (OEM specific).
      Oem7 = 222,
      /// @brief The OEM 8 key (OEM specific).
      Oem8 = 223,
      /// @brief The OEM 102 key (OEM specific).
      Oem102 = 226,
      /// @brief The IME PROCESS key.
      Process = 229,
      /// @brief The PACKET key (used to pass Unicode characters with keystrokes).
      Packet = 231,
      /// @brief The ATTN key.
      Attention = 246,
      /// @brief The CRSEL (CURSOR SELECT) key.
      CrSel = 247,
      /// @brief The EXSEL (EXTEND SELECTION) key.
      ExSel = 248,
      /// @brief The ERASE EOF key.
      EraseEndOfFile = 249,
      /// @brief The Play key.
      Play = 250,
      /// @brief The ZOOM key.
      Zoom = 251,
      /// @brief A constant reserved for future use.
      NoName = 252,
      /// @brief The PA1 key.
      Pa1 = 253,
      /// @brief The CLEAR key (OEM specific).
      OemClear = 254
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::ConsoleKey> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::ConsoleKey::Backspace, "Backspace"}, {(int64)System::ConsoleKey::Tab, "Tab"}, {(int64)System::ConsoleKey::Clear, "Clear"}, {(int64)System::ConsoleKey::Enter, "Enter"}, {(int64)System::ConsoleKey::Pause, "Pause"}, {(int64)System::ConsoleKey::CapsLock, "CapsLock"}, {(int64)System::ConsoleKey::Escape, "Escape"}, {(int64)System::ConsoleKey::Spacebar, "Spacebar"}, {(int64)System::ConsoleKey::PageUp, "PageUp"}, {(int64)System::ConsoleKey::PageDown, "PageDown"}, {(int64)System::ConsoleKey::End, "End"}, {(int64)System::ConsoleKey::Home, "Home"}, {(int64)System::ConsoleKey::LeftArrow, "LeftArrow"}, {(int64)System::ConsoleKey::UpArrow, "UpArrow"}, {(int64)System::ConsoleKey::RightArrow, "RightArrow"}, {(int64)System::ConsoleKey::DownArrow, "DownArrow"}, {(int64)System::ConsoleKey::Select, "Select"}, {(int64)System::ConsoleKey::Print, "Print"}, {(int64)System::ConsoleKey::Execute, "Execute"}, {(int64)System::ConsoleKey::PrintScreen, "PrintScreen"}, {(int64)System::ConsoleKey::Insert, "Insert"}, {(int64)System::ConsoleKey::Delete, "Delete"}, {(int64)System::ConsoleKey::Help, "Help"}, {(int64)System::ConsoleKey::D0, "D0"}, {(int64)System::ConsoleKey::D1, "D1"}, {(int64)System::ConsoleKey::D2, "D2"}, {(int64)System::ConsoleKey::D3, "D3"}, {(int64)System::ConsoleKey::D4, "D4"}, {(int64)System::ConsoleKey::D5, "D5"}, {(int64)System::ConsoleKey::D6, "D6"}, {(int64)System::ConsoleKey::D7, "D7"}, {(int64)System::ConsoleKey::D8, "D8"}, {(int64)System::ConsoleKey::D9, "D9"}, {(int64)System::ConsoleKey::A, "A"}, {(int64)System::ConsoleKey::B, "B"}, {(int64)System::ConsoleKey::C, "C"}, {(int64)System::ConsoleKey::D, "D"}, {(int64)System::ConsoleKey::E, "E"}, {(int64)System::ConsoleKey::F, "F"}, {(int64)System::ConsoleKey::G, "G"}, {(int64)System::ConsoleKey::H, "H"}, {(int64)System::ConsoleKey::I, "I"}, {(int64)System::ConsoleKey::J, "J"}, {(int64)System::ConsoleKey::K, "K"}, {(int64)System::ConsoleKey::L, "L"}, {(int64)System::ConsoleKey::M, "M"}, {(int64)System::ConsoleKey::N, "N"}, {(int64)System::ConsoleKey::O, "O"}, {(int64)System::ConsoleKey::P, "P"}, {(int64)System::ConsoleKey::Q, "Q"}, {(int64)System::ConsoleKey::R, "R"}, {(int64)System::ConsoleKey::S, "S"}, {(int64)System::ConsoleKey::T, "T"}, {(int64)System::ConsoleKey::U, "U"}, {(int64)System::ConsoleKey::V, "V"}, {(int64)System::ConsoleKey::W, "W"}, {(int64)System::ConsoleKey::X, "X"}, {(int64)System::ConsoleKey::Y, "Y"}, {(int64)System::ConsoleKey::Z, "Z"}, {(int64)System::ConsoleKey::LeftWindows, "LeftWindows"}, {(int64)System::ConsoleKey::RightWindows, "RightWindows"}, {(int64)System::ConsoleKey::Applications, "Applications"}, {(int64)System::ConsoleKey::Sleep, "Sleep"}, {(int64)System::ConsoleKey::NumPad0, "NumPad0"}, {(int64)System::ConsoleKey::NumPad1, "NumPad1"}, {(int64)System::ConsoleKey::NumPad2, "NumPad2"}, {(int64)System::ConsoleKey::NumPad3, "NumPad3"}, {(int64)System::ConsoleKey::NumPad4, "NumPad4"}, {(int64)System::ConsoleKey::NumPad5, "NumPad5"}, {(int64)System::ConsoleKey::NumPad6, "NumPad6"}, {(int64)System::ConsoleKey::NumPad7, "NumPad7"}, {(int64)System::ConsoleKey::NumPad8, "NumPad8"}, {(int64)System::ConsoleKey::NumPad9, "NumPad9"}, {(int64)System::ConsoleKey::Multiply, "Multiply"}, {(int64)System::ConsoleKey::Add, "Add"}, {(int64)System::ConsoleKey::Separator, "Separator"}, {(int64)System::ConsoleKey::Subtract, "Subtract"}, {(int64)System::ConsoleKey::Decimal, "Decimal"}, {(int64)System::ConsoleKey::Divide, "Divide"}, {(int64)System::ConsoleKey::F1, "F1"}, {(int64)System::ConsoleKey::F2, "F2"}, {(int64)System::ConsoleKey::F3, "F3"}, {(int64)System::ConsoleKey::F4, "F4"}, {(int64)System::ConsoleKey::F5, "F5"}, {(int64)System::ConsoleKey::F6, "F6"}, {(int64)System::ConsoleKey::F7, "F7"}, {(int64)System::ConsoleKey::F8, "F8"}, {(int64)System::ConsoleKey::F9, "F9"}, {(int64)System::ConsoleKey::F10, "F10"}, {(int64)System::ConsoleKey::F11, "F11"}, {(int64)System::ConsoleKey::F12, "F12"}, {(int64)System::ConsoleKey::F13, "F13"}, {(int64)System::ConsoleKey::F14, "F14"}, {(int64)System::ConsoleKey::F15, "F15"}, {(int64)System::ConsoleKey::F16, "F16"}, {(int64)System::ConsoleKey::F17, "F17"}, {(int64)System::ConsoleKey::F18, "F18"}, {(int64)System::ConsoleKey::F19, "F19"}, {(int64)System::ConsoleKey::F20, "F20"}, {(int64)System::ConsoleKey::F21, "F21"}, {(int64)System::ConsoleKey::F22, "F22"}, {(int64)System::ConsoleKey::F23, "F23"}, {(int64)System::ConsoleKey::F24, "F24"}, {(int64)System::ConsoleKey::BrowserBack, "BrowserBack"}, {(int64)System::ConsoleKey::BrowserForward, "BrowserForward"}, {(int64)System::ConsoleKey::BrowserRefresh, "BrowserRefresh"}, {(int64)System::ConsoleKey::BrowserStop, "BrowserStop"}, {(int64)System::ConsoleKey::BrowserSearch, "BrowserSearch"}, {(int64)System::ConsoleKey::BrowserFavorites, "BrowserFavorite"}, {(int64)System::ConsoleKey::BrowserHome, "BrowserHome"}, {(int64)System::ConsoleKey::VolumeMute, "VolumeMute"}, {(int64)System::ConsoleKey::VolumeDown, "VolumeDown"}, {(int64)System::ConsoleKey::VolumeUp, "VolumeUp"}, {(int64)System::ConsoleKey::MediaNext, "MediaNext"}, {(int64)System::ConsoleKey::MediaPrevious, "MediaPrevious"}, {(int64)System::ConsoleKey::MediaStop, "MediaStop"}, {(int64)System::ConsoleKey::MediaPlay, "MediaPlay"}, {(int64)System::ConsoleKey::LaunchMail, "LaunchMail"}, {(int64)System::ConsoleKey::LaunchMediaSelect, "LaunchMediaSelect"}, {(int64)System::ConsoleKey::LaunchApp1, "LaunchApp1"}, {(int64)System::ConsoleKey::LaunchApp2, "LaunchApp2"}, {(int64)System::ConsoleKey::Oem1, "Oem1"}, {(int64)System::ConsoleKey::OemPlus, "OemPlus"}, {(int64)System::ConsoleKey::OemComma, "OemComma"}, {(int64)System::ConsoleKey::OemMinus, "OemMinus"}, {(int64)System::ConsoleKey::OemPeriod, "OemPeriod"}, {(int64)System::ConsoleKey::Oem2, "Oem2"}, {(int64)System::ConsoleKey::Oem3, "Oem3"}, {(int64)System::ConsoleKey::Oem4, "Oem4"}, {(int64)System::ConsoleKey::Oem5, "Oem5"}, {(int64)System::ConsoleKey::Oem6, "Oem6"}, {(int64)System::ConsoleKey::Oem7, "Oem7"}, {(int64)System::ConsoleKey::Oem8, "Oem8"}, {(int64)System::ConsoleKey::Oem102, "Oem102"}, {(int64)System::ConsoleKey::Process, "Process"}, {(int64)System::ConsoleKey::Packet, "Packet"}, {(int64)System::ConsoleKey::Attention, "Attention"}, {(int64)System::ConsoleKey::CrSel, "CrSel"}, {(int64)System::ConsoleKey::ExSel, "ExSel"}, {(int64)System::ConsoleKey::EraseEndOfFile, "EraseEndOfFile"}, {(int64)System::ConsoleKey::Play, "Play"}, {(int64)System::ConsoleKey::Zoom, "Zoom"}, {(int64)System::ConsoleKey::NoName, "NoName"}, {(int64)System::ConsoleKey::Pa1, "Pa1"}, {(int64)System::ConsoleKey::OemClear, "OemClear"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
