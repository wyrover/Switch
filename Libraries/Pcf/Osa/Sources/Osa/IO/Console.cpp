#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>

#if _WIN32
#  pragma warning(push)
#  pragma warning(disable:4201)
#  if !_WIN32_WCE
#    include <conio.h>
#  endif
#  include <windows.h>
#  pragma warning(pop)
#else
#  include <fcntl.h>
#  include <termios.h>
#  include <unistd.h>
#  include <sys/ioctl.h>
#endif

#include "../../../Includes/Osa/IO/Console.h"
#include "../../../Includes/Osa/Types/int32.h"
#include "../../../Includes/Osa/Types/uint16.h"
#include "../../../Includes/Osa/Types/sbyte.h"

#if _WIN32
void Pcf::Osa::IO::Console::Beep(int32 frequency, int32 duration) {
  ::Beep(frequency, duration);
}

void Pcf::Osa::IO::Console::Clrscr() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE) ,&bufferInfo);
  
  const COORD coord = {0, 0};
  DWORD nbCharsWritten = 0;
  FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bufferInfo.wAttributes, bufferInfo.dwSize.X * bufferInfo.dwSize.Y, coord, &nbCharsWritten);
  FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', bufferInfo.dwSize.X * bufferInfo.dwSize.Y, coord, &nbCharsWritten);
  Gotoxy(1, 1);
}

Pcf::Osa::IO::ConsoleColor Pcf::Osa::IO::Console::GetBackgroundColor() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  
  return Pcf::Osa::IO::ConsoleColor((bufferInfo.wAttributes & 0x00F0) >> 4);
}

int32 Pcf::Osa::IO::Console::GetCursorSize() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  
  return cursorInfo.dwSize;
}

bool Pcf::Osa::IO::Console::GetCursorVisible() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  
  return cursorInfo.bVisible != FALSE;
}

Pcf::Osa::IO::ConsoleColor Pcf::Osa::IO::Console::GetForegroundColor() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  
  return Pcf::Osa::IO::ConsoleColor(bufferInfo.wAttributes & 0x000F);
}

void Pcf::Osa::IO::Console::Gotoxy(int32 x, int32 y) {
  COORD coord = {static_cast<int16_t>(--x), static_cast<int16_t>(--y)};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool Pcf::Osa::IO::Console::KeyAvailable() {
  return _kbhit() != 0;
}

int32 Pcf::Osa::IO::Console::Write(const std::string& value) {
  int32 nbCharWrites = fputs(value.c_str(), stdout);
  fflush(stdout);
  return nbCharWrites;
}

void Pcf::Osa::IO::Console::ReadKey(char* keyChar, int32* keyCode, bool* alt, bool* shift, bool* ctrl) {
  INPUT_RECORD inputRecord;
  do {
    DWORD nbEventsRead = 0;
    ReadConsoleInput( GetStdHandle(STD_INPUT_HANDLE), &inputRecord, 1, &nbEventsRead);
  } while (!(inputRecord.EventType == KEY_EVENT && (inputRecord.Event.KeyEvent.bKeyDown == 1 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x10 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x11 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x12)));
  
  *keyChar = inputRecord.Event.KeyEvent.uChar.AsciiChar;
  *keyCode = inputRecord.Event.KeyEvent.wVirtualKeyCode;
  *alt = (inputRecord.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED) == LEFT_ALT_PRESSED || (inputRecord.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED) == RIGHT_ALT_PRESSED;
  *shift = (inputRecord.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED) == SHIFT_PRESSED;
  *ctrl = (inputRecord.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED) == LEFT_CTRL_PRESSED || (inputRecord.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED) == RIGHT_CTRL_PRESSED;
}

void Pcf::Osa::IO::Console::SetBackgroundColor(Pcf::Osa::IO::ConsoleColor color) {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  
  bufferInfo.wAttributes &= 0xFF0F;
  bufferInfo.wAttributes |= (uint16)color << 4;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bufferInfo.wAttributes);
}

void Pcf::Osa::IO::Console::SetCursorSize(int32 size) {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  
  cursorInfo.dwSize = size;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Pcf::Osa::IO::Console::SetCursorVisible(bool visible) {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  
  cursorInfo.bVisible = visible;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Pcf::Osa::IO::Console::SetForegroundColor(Pcf::Osa::IO::ConsoleColor color) {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  
  bufferInfo.wAttributes &= 0xFFF0;
  bufferInfo.wAttributes |= (uint16)color;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bufferInfo.wAttributes);
}

void Pcf::Osa::IO::Console::Wherexy(int32* x, int32* y) {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  *x = ++bufferInfo.dwCursorPosition.X;
  *y = ++bufferInfo.dwCursorPosition.Y;
}

#else

#ifndef KIOCSOUND
static const int32 KIOCSOUND = 0x4B2F;
#endif

namespace {
  static Pcf::Osa::IO::ConsoleColor backColor = (Pcf::Osa::IO::ConsoleColor)16;
  static Pcf::Osa::IO::ConsoleColor foreColor = (Pcf::Osa::IO::ConsoleColor)16;
  static bool cursorVisible = true;
  
  class Keyboard {
  public:
    Keyboard() : peekCharacter(-1) {
      tcgetattr(0, &this->initialSettings);
      this->newSettings = this->initialSettings;
      this->newSettings.c_lflag &= ~(ICANON | ECHO| ISIG);
      this->newSettings.c_cc[VMIN] = 1;
      this->newSettings.c_cc[VTIME] = 0;
      tcsetattr(0, TCSANOW, &this->newSettings);
    }
    
    ~Keyboard() {tcsetattr(0, TCSANOW, &this->initialSettings);}
    
    int32 Getch() {
      sbyte character = -1;
      if (this->peekCharacter != -1 || read(0, &character, 1) != 1)
        std::swap(this->peekCharacter, character);
      return character;
    }
    
    bool KeyAvailable() {
      if (this->peekCharacter != -1)
        return true;
      
      this->newSettings.c_cc[VMIN] = 0;
      tcsetattr(0, TCSANOW, &this->newSettings);
      
      this->peekCharacter = static_cast<sbyte>(Getch());
      
      this->newSettings.c_cc[VMIN] = 1;
      tcsetattr(0, TCSANOW, &this->newSettings);
      
      return this->peekCharacter != -1;
    }
    
  private:
    termios initialSettings;
    termios newSettings;
    sbyte peekCharacter;
  };
  
  static std::string ColorToEscapeBackColorStr(Pcf::Osa::IO::ConsoleColor color) {
    switch (color) {
      case Pcf::Osa::IO::ConsoleColor::Black : return "\033[1m\033[40m";
      case Pcf::Osa::IO::ConsoleColor::DarkBlue : return "\033[1m\033[44m";
      case Pcf::Osa::IO::ConsoleColor::DarkGreen : return "\033[1m\033[42m";
      case Pcf::Osa::IO::ConsoleColor::DarkCyan : return "\033[1m\033[46m";
      case Pcf::Osa::IO::ConsoleColor::DarkRed : return "\033[1m\033[41m";
      case Pcf::Osa::IO::ConsoleColor::DarkMagenta : return "\033[1m\033[45m";
      case Pcf::Osa::IO::ConsoleColor::DarkYellow : return "\033[1m\033[43m";
      case Pcf::Osa::IO::ConsoleColor::Gray : return "\033[1m\033[47m";
      case Pcf::Osa::IO::ConsoleColor::DarkGray : return "\033[1m\033[40m";
      case Pcf::Osa::IO::ConsoleColor::Blue : return "\033[1m\033[44m";
      case Pcf::Osa::IO::ConsoleColor::Green : return "\033[1m\033[42m";
      case Pcf::Osa::IO::ConsoleColor::Cyan : return "\033[1m\033[46m";
      case Pcf::Osa::IO::ConsoleColor::Red : return "\033[1m\033[41m";
      case Pcf::Osa::IO::ConsoleColor::Magenta : return "\033[1m\033[45m";
      case Pcf::Osa::IO::ConsoleColor::Yellow : return "\033[1m\033[43m";
      case Pcf::Osa::IO::ConsoleColor::White : return "\033[1m\033[47m";
      default : return "\033[1m\033[49m";
    }
  }
  
  std::string ColorToEscapeForeColorStr(Pcf::Osa::IO::ConsoleColor color) {
    switch (color) {
      case Pcf::Osa::IO::ConsoleColor::Black : return "\033[0m\033[30m";
      case Pcf::Osa::IO::ConsoleColor::DarkBlue : return "\033[0m\033[34m";
      case Pcf::Osa::IO::ConsoleColor::DarkGreen : return "\033[0m\033[32m";
      case Pcf::Osa::IO::ConsoleColor::DarkCyan : return "\033[0m\033[36m";
      case Pcf::Osa::IO::ConsoleColor::DarkRed : return "\033[0m\033[31m";
      case Pcf::Osa::IO::ConsoleColor::DarkMagenta : return "\033[0m\033[35m";
      case Pcf::Osa::IO::ConsoleColor::DarkYellow : return "\033[0m\033[33m";
      case Pcf::Osa::IO::ConsoleColor::Gray : return "\033[0m\033[37m";
      case Pcf::Osa::IO::ConsoleColor::DarkGray : return "\033[1m\033[30m";
      case Pcf::Osa::IO::ConsoleColor::Blue : return "\033[1m\033[34m";
      case Pcf::Osa::IO::ConsoleColor::Green : return "\033[1m\033[32m";
      case Pcf::Osa::IO::ConsoleColor::Cyan : return "\033[1m\033[36m";
      case Pcf::Osa::IO::ConsoleColor::Red : return "\033[1m\033[31m";
      case Pcf::Osa::IO::ConsoleColor::Magenta : return "\033[1m\033[35m";
      case Pcf::Osa::IO::ConsoleColor::Yellow : return "\033[1m\033[33m";
      case Pcf::Osa::IO::ConsoleColor::White : return "\033[1m\033[37m";
      default : return "\033[1m\033[39m";
    }
  }
}

void Pcf::Osa::IO::Console::Beep(int32 frequency, int32 duration) {
  int32 fd = open("/dev/console", O_WRONLY);
  ioctl(fd, KIOCSOUND, (int32)(1193180/frequency));
  std::this_thread::sleep_for(std::chrono::milliseconds(duration));
  ioctl(fd, KIOCSOUND, 0);
  close(fd);
}

void Pcf::Osa::IO::Console::Clrscr() {
  printf("\033[H\033[2J");
}

Pcf::Osa::IO::ConsoleColor Pcf::Osa::IO::Console::GetBackgroundColor() {
  return backColor;
}

int32 Pcf::Osa::IO::Console::GetCursorSize() {
  return 100;
}

bool Pcf::Osa::IO::Console::GetCursorVisible() {
  return cursorVisible;
}

Pcf::Osa::IO::ConsoleColor Pcf::Osa::IO::Console::GetForegroundColor() {
  return foreColor;
}

void Pcf::Osa::IO::Console::Gotoxy(int32 x, int32 y) {
  printf("\033[%d;%df", y, x);
}

bool Pcf::Osa::IO::Console::KeyAvailable() {
  Keyboard keyb;
  return keyb.KeyAvailable() != 0;
}

int32 Pcf::Osa::IO::Console::Write(const std::string& value) {
  return fputs(value.c_str(), stdout);
}

void Pcf::Osa::IO::Console::ReadKey(char* keyChar, int32* keyCode, bool* alt, bool* shift, bool* ctrl) {
  Keyboard keyb;
  int32 key = 0;
  
  //flush to terminal before reading key
  fflush(stdout);
  
  key = keyb.Getch();
  
  if (key != 0) {
    *keyChar = (char)key;
    *keyCode = toupper((char)key);
  } else {
    key = keyb.Getch();
    *keyChar = 0;
    *keyCode = key;
  }
  *alt = false;
  *shift = false;
  *ctrl = false;
}

void Pcf::Osa::IO::Console::SetBackgroundColor(Pcf::Osa::IO::ConsoleColor color) {
  backColor = color;
  printf("%s", ColorToEscapeForeColorStr(foreColor).c_str());
  printf("%s", ColorToEscapeBackColorStr(backColor).c_str());
}

void Pcf::Osa::IO::Console::SetCursorSize(int32 size) {
  
}

void Pcf::Osa::IO::Console::SetCursorVisible(bool visible) {
  cursorVisible = visible;
  if (visible)
    printf("\033[?25h");
  else
    printf("\033[?25l");
}

void Pcf::Osa::IO::Console::SetForegroundColor(Pcf::Osa::IO::ConsoleColor color) {
  foreColor = color;
  printf("%s", ColorToEscapeForeColorStr(foreColor).c_str());
  printf("%s", ColorToEscapeBackColorStr(backColor).c_str());
}

void Pcf::Osa::IO::Console::Wherexy(int32* x, int32* y) {
  Keyboard keyb;

  printf("\033[6n");
  fflush(stdout);
  keyb.Getch();
  keyb.Getch();

  char str[256] = {0};
  int32_t i = 0;
  for (i = 0; (str[i] = (char)keyb.Getch()) != ';'; i++);
  str[i] = 0;
  *y = atoi(str);

  for (i = 0; (str[i] = (char)keyb.Getch()) != 'R'; i++);
  str[i] = 0;
  *x = atoi(str);
}
#endif