#pragma once

#include "../../../Includes/Pcf/Types.h"

/// @cond
namespace Pcf {
  namespace Os {
    /// @brief Represents a Os object that provides the access console API.
    /// This class cannot be inherited.
    /// Internal used only.
    class Console final {
    public:
      /// @brief Generates simple tones on the speaker. The function is synchronous; it performs an alertable wait and does not return control to its caller until the sound finishes.
      /// Internal used only.
      /// @param freq The frequency of the sound, in hertz. This parameter must be in the range 37 through 32,767 (0x25 through 0x7FFF)
      /// @param dur The duration of the sound, in milliseconds.
      static void Beep(int32 freq, int32 dur);

      /// @brief Clear console output (like cls command) and set cursor at position 1 in vertical and 1 in horizontal.
      /// Internal used only.
      static void Clrscr();

      /// @brief Gets the background color of the console.
      /// Internal used only.
      /// @return int32 A Console Color that specifies the background color of the console; that is, the color of each character that is displayed. The default is 0 (Black)
      /// @remarks Table of color values in decimal :
      /// | Value | Color        |
      /// |-------|--------------|
      /// | 0     | Black        |
      /// | 1     | Dark Blue    |
      /// | 2     | Dark Green   |
      /// | 3     | Dark Cyan    |
      /// | 4     | Dark Red     |
      /// | 5     | Dark Magenta |
      /// | 6     | Dark Yellow  |
      /// | 7     | Gray         |
      /// | 8     | Dark Gray    |
      /// | 9     | Blue         |
      /// | 10    | Green        |
      /// | 11    | Cyan         |
      /// | 12    | Red          |
      /// | 13    | Magenta      |
      /// | 14    | Yellow       |
      /// | 15    | White        |
      static int32 GetBackgroundColor();

      /// @brief Gets the height of the cursor within a character cell.
      /// Internal used only.
      /// @return int32 The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
      static int32 GetCursorSize();

      /// @brief Gets a value indicating whether the cursor is visible.
      /// Internal used only.
      /// @return bool true if the cursor is visible; otherwise, false.
      static bool GetCursorVisible();

      /// @brief Gets the foreground color of the console.
      /// Internal used only.
      /// @return int32 A Console Color that specifies the foreground color of the console; that is, the color that appears behind each character. The default is 7 (Gray)
      /// @remarks Table of color values in decimal :
      /// | Value | Color        |
      /// |-------|--------------|
      /// | 0     | Black        |
      /// | 1     | Dark Blue    |
      /// | 2     | Dark Green   |
      /// | 3     | Dark Cyan    |
      /// | 4     | Dark Red     |
      /// | 5     | Dark Magenta |
      /// | 6     | Dark Yellow  |
      /// | 7     | Gray         |
      /// | 8     | Dark Gray    |
      /// | 9     | Blue         |
      /// | 10    | Green        |
      /// | 11    | Cyan         |
      /// | 12    | Red          |
      /// | 13    | Magenta      |
      /// | 14    | Yellow       |
      /// | 15    | White        |
      static int32 GetForegroundColor();

      /// @brief Set console cursor to a specific position.
      /// Internal used only.
      /// @param x horizontal position (1-80)
      /// @param y vertical position (1-25)
      static void Gotoxy(int32 x, int32 y);

      /// @brief Checks the console for keyboard input.
      /// Internal used only.
      /// @return bool  return true if a key has been pressed. Otherwise, it returns false
      static bool KeyAvailable();

      /// @brief Gets a character from the console without echo.
      /// Internal used only.
      /// @param keyChar int32 to get the character of key pressed
      /// @param keyCode int32 to get the KeyCode of the keyboard
      /// @param alt bool to get if modifier Alt Key is pressed
      /// @param shift bool to get if modifier Shift Key is pressed
      /// @param ctrl bool to get if modifier Ctrl Key is pressed
      static void ReadKey(int32& keyChar, int32& keyCode, bool& alt, bool& shift, bool& ctrl);

      /// @brief Sets the background color of the console.
      /// Internal used only.
      /// @param color A Console Color that specifies the background color of the console; that is, the color that appears behind each character.
      /// @remarks Table of color values in decimal :
      /// | Value | Color        |
      /// |-------|--------------|
      /// | 0     | Black        |
      /// | 1     | Dark Blue    |
      /// | 2     | Dark Green   |
      /// | 3     | Dark Cyan    |
      /// | 4     | Dark Red     |
      /// | 5     | Dark Magenta |
      /// | 6     | Dark Yellow  |
      /// | 7     | Gray         |
      /// | 8     | Dark Gray    |
      /// | 9     | Blue         |
      /// | 10    | Green        |
      /// | 11    | Cyan         |
      /// | 12    | Red          |
      /// | 13    | Magenta      |
      /// | 14    | Yellow       |
      /// | 15    | White        |
      static void SetBackgroundColor(int32 color);

      /// @brief Sets the height of the cursor within a character cell.
      /// Internal used only.
      /// @param size The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
      static void SetCursorSize(int32 size);

      /// @brief Sets a value indicating whether the cursor is visible.
      /// @param visible true if the cursor is visible; otherwise, false.
      static void SetCursorVisible(bool visible);
      
      static void SetEchoVisible(bool visible);
      
      /// @brief Sets the foreground color of the console.
      /// Internal used only.
      /// @param color A Console Color that specifies the foreground color of the console; that is, the color of each character that is displayed.
      /// @remarks Table of color values in decimal :
      /// | Value | Color        |
      /// |-------|--------------|
      /// | 0     | Black        |
      /// | 1     | Dark Blue    |
      /// | 2     | Dark Green   |
      /// | 3     | Dark Cyan    |
      /// | 4     | Dark Red     |
      /// | 5     | Dark Magenta |
      /// | 6     | Dark Yellow  |
      /// | 7     | Gray         |
      /// | 8     | Dark Gray    |
      /// | 9     | Blue         |
      /// | 10    | Green        |
      /// | 11    | Cyan         |
      /// | 12    | Red          |
      /// | 13    | Magenta      |
      /// | 14    | Yellow       |
      /// | 15    | White        |
      static void SetForegroundColor(int32 color);

      /// @brief Get console cursor position.
      /// Internal used only.
      /// @param x Get horizontal position
      /// @param y Get vertical position
      static void Wherexy(int32& x, int32& y);

      /// @brief Get console buffer size.
      /// Internal used only.
      /// @param w Get width
      /// @param h Get height
      static void GetBufferSize(int32& w, int32& yh);

      static int32 GetInputCodePage();
      
      static int32 GetOutputCodePage();

      static bool SetInputCodePage(int32 codePage);

      static bool SetOutputCodePage(int32 codePage);

      private:
      Console() = delete;
    };
  }
}

using namespace Pcf;
/// @endcond
