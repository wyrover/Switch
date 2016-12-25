#if _WIN32

#include <conio.h>
#pragma warning(push)
#pragma warning(disable:4201)
#include <windows.h>
#pragma warning(pop)

#include "../Console.h"

#include "../../../../Includes/Pcf/Types.h"

using namespace Os;

void Console::Beep(int32 frequency, int32 duration) {
  ::Beep(frequency, duration);
}

void Console::Clrscr() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&bufferInfo);

  const COORD coord = {0, 0};
  DWORD nbCharsWritten = 0;
  FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bufferInfo.wAttributes, bufferInfo.dwSize.X * bufferInfo.dwSize.Y, coord, &nbCharsWritten);
  FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', bufferInfo.dwSize.X * bufferInfo.dwSize.Y, coord, &nbCharsWritten);    
  Gotoxy(1, 1);
}

int32 Console::GetBackgroundColor() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  return (bufferInfo.wAttributes & 0x00F0) >> 4;
}

int32 Console::GetCursorSize() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  return cursorInfo.dwSize;
}

bool Console::GetCursorVisible() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  return cursorInfo.bVisible != FALSE;
}

int32 Console::GetForegroundColor() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  return bufferInfo.wAttributes & 0x000F;
}

void Console::Gotoxy(int32 x, int32 y) {
  COORD coord = {static_cast<SHORT>(--x), static_cast<SHORT>(--y)};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool Console::KeyAvailable() {
  return _kbhit() != 0;
}

void Console::ReadKey(int32& keyChar, int32& keyCode, bool& alt, bool& shift, bool& ctrl) {
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

void Console::SetBackgroundColor(int32 color) {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

  bufferInfo.wAttributes &= 0xFF0F;
  bufferInfo.wAttributes |= color << 4;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bufferInfo.wAttributes);
}

void Console::SetCursorSize(int32 size) {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

  cursorInfo.dwSize = size;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Console::SetCursorVisible(bool visible) {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  
  cursorInfo.bVisible = visible;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Console::SetEchoVisible(bool visible) {
  // Only for Linux terminal...
}

void Console::SetForegroundColor(int32 color) {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

  bufferInfo.wAttributes &= 0xFFF0;
  bufferInfo.wAttributes |= color;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bufferInfo.wAttributes);
}

void Console::Wherexy(int32& x, int32& y) {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  x = ++bufferInfo.dwCursorPosition.X;
  y = ++bufferInfo.dwCursorPosition.Y;
}

void Console::GetBufferSize(int32& w, int32& h) {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  w = bufferInfo.dwSize.X;
  h = bufferInfo.dwSize.Y;
}

int32 Console::GetInputCodePage() {
  return GetConsoleCP();
}

int32 Console::GetOutputCodePage() {
  return GetConsoleOutputCP();
}

bool Console::SetInputCodePage(int32 codePage) {
  return SetConsoleCP(codePage) == TRUE;
}

bool Console::SetOutputCodePage(int32 codePage) {
  return SetConsoleOutputCP(codePage) == TRUE;
}

#endif
