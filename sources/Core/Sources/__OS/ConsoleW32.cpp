#if defined(_WIN32)

#include <csignal>
#include <conio.h>
#include <windows.h>
#include "../../Includes/Switch/Undef.hpp"

#include "CoreApi.hpp"

using namespace System;

namespace {
  static ConsoleColor backColor = __OS::CoreApi::Console::GetBackgroundColor();
  static ConsoleColor foreColor = __OS::CoreApi::Console::GetForegroundColor();
}

void __OS::CoreApi::Console::Beep(int32 frequency, int32 duration) {
  ::Beep(frequency, duration);
}

void __OS::CoreApi::Console::Clrscr() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);

  const COORD coord = {0, 0};
  DWORD nbCharsWritten = 0;
  FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  SetCursorLeft(0);
  SetCursorTop(0);
}

ConsoleColor __OS::CoreApi::Console::GetBackgroundColor() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  return ConsoleColor((bufferInfo.wAttributes & 0x00F0) >> 4);
}

int32 __OS::CoreApi::Console::GetBufferHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwSize.Y;
}

int32 __OS::CoreApi::Console::GetBufferWidth() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwSize.X;
}

bool __OS::CoreApi::Console::GetCapsLock() {
  return (GetKeyState(VK_CAPITAL) & 0x0001) == 0x0001;
}

int32 __OS::CoreApi::Console::GetCursorLeft() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwCursorPosition.X;
}

int32 __OS::CoreApi::Console::GetCursorSize() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  return cursorInfo.dwSize;
}

int32 __OS::CoreApi::Console::GetCursorTop() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwCursorPosition.Y;
}

bool __OS::CoreApi::Console::GetCursorVisible() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  return cursorInfo.bVisible != FALSE;
}

ConsoleColor __OS::CoreApi::Console::GetForegroundColor() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  return ConsoleColor(bufferInfo.wAttributes & 0x000F);
}

int32 __OS::CoreApi::Console::GetInputCodePage() {
  return GetConsoleCP();
}

int32 __OS::CoreApi::Console::GetLargestWindowHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwMaximumWindowSize.Y;
}

int32 __OS::CoreApi::Console::GetLargestWindowWidth() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwMaximumWindowSize.X;
}

bool __OS::CoreApi::Console::GetNumberLock() {
  return (GetKeyState(VK_NUMLOCK) & 0x0001) == 0x0001;
}

int32 __OS::CoreApi::Console::GetOutputCodePage() {
  return GetConsoleOutputCP();
}

System::Collections::Generic::SortedDictionary<int32, System::ConsoleSpecialKey> __OS::CoreApi::Console::GetSignalKeys() {
  return {{SIGBREAK, System::ConsoleSpecialKey::ControlBreak}, {SIGINT, System::ConsoleSpecialKey::ControlC}};
}

string __OS::CoreApi::Console::GetTitle() {
  return "";
}

int32 __OS::CoreApi::Console::GetWindowHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int32 __OS::CoreApi::Console::GetWindowLeft() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Left;
}

int32 __OS::CoreApi::Console::GetWindowTop() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Top;
}

int32 __OS::CoreApi::Console::GetWindowWidth() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

bool __OS::CoreApi::Console::KeyAvailable() {
  return _kbhit() != 0;
}

void __OS::CoreApi::Console::ReadKey(int32& keyChar, int32& keyCode, bool& alt, bool& shift, bool& ctrl) {
  INPUT_RECORD inputRecord;
  do {
    DWORD nbEventsRead = 0;
    ReadConsoleInput( GetStdHandle(STD_INPUT_HANDLE), &inputRecord, 1, &nbEventsRead);
  } while (!(inputRecord.EventType == KEY_EVENT && (inputRecord.Event.KeyEvent.bKeyDown == 1 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x10 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x11 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x12)));

  keyChar = inputRecord.Event.KeyEvent.uChar.AsciiChar;
  keyCode = inputRecord.Event.KeyEvent.wVirtualKeyCode;
  alt = (inputRecord.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED) == LEFT_ALT_PRESSED || (inputRecord.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED) == RIGHT_ALT_PRESSED;
  shift = (inputRecord.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED) == SHIFT_PRESSED;
  ctrl = (inputRecord.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED) == LEFT_CTRL_PRESSED || (inputRecord.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED) == RIGHT_CTRL_PRESSED;
}

bool __OS::CoreApi::Console::ResetColor() {
  return SetBackgroundColor(backColor) && SetForegroundColor(foreColor);
}

bool __OS::CoreApi::Console::SetBackgroundColor(ConsoleColor color) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  csbi.wAttributes &= 0xFF0F;
  csbi.wAttributes |= (int32)color << 4;
  return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes) == TRUE;
}

bool __OS::CoreApi::Console::SetBufferHeight(int32 height) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.Y = height;
  return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize) == TRUE;
}

bool __OS::CoreApi::Console::SetBufferWidth(int32 width) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.X = width;
  return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize) == TRUE;
}

bool __OS::CoreApi::Console::SetCursorLeft(int32 left) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwCursorPosition.X = left;
  return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwCursorPosition) == TRUE;
}

bool __OS::CoreApi::Console::SetCursorTop(int32 top) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwCursorPosition.Y = top;
  return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwCursorPosition) == TRUE;
}

void __OS::CoreApi::Console::SetCursorSize(int32 size) {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

  cci.dwSize = size;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void __OS::CoreApi::Console::SetCursorVisible(bool visible) {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  
  cci.bVisible = visible;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void __OS::CoreApi::Console::SetEchoVisible(bool visible) {
  // Only for Linux terminal...
}

bool __OS::CoreApi::Console::SetForegroundColor(ConsoleColor color) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  csbi.wAttributes &= 0xFFF0;
  csbi.wAttributes |= (int32)color;
  return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes) == TRUE;
}

bool __OS::CoreApi::Console::SetInputCodePage(int32 codePage) {
  return SetConsoleCP(codePage) == TRUE;
}

bool __OS::CoreApi::Console::SetOutputCodePage(int32 codePage) {
  return SetConsoleOutputCP(codePage) == TRUE;
}

bool __OS::CoreApi::Console::SetTitle(const string& title) {
  return true;
}

bool __OS::CoreApi::Console::SetWindowHeight(int32 height) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Bottom = csbi.srWindow.Top + height - 1;
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

bool __OS::CoreApi::Console::SetWindowLeft(int32 left) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Left = left;
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

bool __OS::CoreApi::Console::SetWindowTop(int32 top) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Top = top;
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

bool __OS::CoreApi::Console::SetWindowWidth(int32 width) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Right = csbi.srWindow.Left + width - 1;
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

#endif
