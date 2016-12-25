#pragma once

#include <string>

#include "../Enum.h"
#include "../Types/int32.h"

namespace Pcf {
  namespace Osa {
    namespace IO {
      enum class ConsoleColor {
        Black,
        DarkBlue,
        DarkGreen,
        DarkCyan,
        DarkRed,
        DarkMagenta,
        DarkYellow,
        Gray,
        DarkGray,
        Blue,
        Green,
        Cyan,
        Red,
        Magenta,
        Yellow,
        White
      };
      
      /// @brief Represents a Os object that provides the access console API.
      /// @remarks This class cannot be inherited.
      class Console {

      public:
        /// @brief Generates simple tones on the speaker. The function is synchronous; it performs an alertable wait and does not return control to its caller until the sound finishes.
        /// @param frequency The frequency of the sound, in hertz. This parameter must be in the range 37 through 32,767 (0x25 through 0x7FFF)
        /// @param duration The duration of the sound, in milliseconds.
        static void Beep(int32 frequency, int32 duration);

        /// @brief Clear console output (like cls command) and set cursor at position 1 in vertical and 1 in horizontal.
        static void Clrscr();

        /// @brief Gets the background color of the console.
        /// @return uint16_t A Console Color that specifies the background color of the console; that is, the color of each character that is displayed. The default is 0 (Black)
        static ConsoleColor GetBackgroundColor();

        /// @brief Gets the height of the cursor within a character cell.
        /// @return int32 The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
        static int32 GetCursorSize();

        /// @brief Gets a value indicating whether the cursor is visible.
        /// @return bool true if the cursor is visible; otherwise, false.
        static bool GetCursorVisible();

        /// @brief Gets the foreground color of the console.
        /// @return uint16_t A Console Color that specifies the foreground color of the console; that is, the color that appears behind each character. The default is 7 (Gray)
        static ConsoleColor GetForegroundColor();

        /// @brief Set console cursor to a specific position.
        /// @param x horizontal position (1-80)
        /// @param y vertical position (1-25)
        static void Gotoxy(int32 x, int32 y);

        /// @brief Checks the console for keyboard input.
        /// @return bool  return true if a key has been pressed. Otherwise, it returns false
        static bool KeyAvailable();

        /// @brief Print a string to the standard output stream.
        /// @param value String to print.
        /// @return int32 Returns the number of characters printed, or a negative value if an error occurs.
        static int32 Write(const std::string& value);

        /// @brief Gets a character from the console without echo.
        /// @param keyChar char pointer to get the character of key pressed
        /// @param keyCode int32 pointer to get the KeyCode of the keyboard
        /// @param alt bool pointer to get if modifier Alt Key is pressed
        /// @param shift bool pointer to get if modifier Shift Key is pressed
        /// @param ctrl bool pointer to get if modifier Ctrl Key is pressed
        static void ReadKey(char* keyChar, int32* keyCode, bool* alt, bool* shift, bool* ctrl);

        /// @brief Sets the background color of the console.
        /// @param color A Console Color that specifies the background color of the console; that is, the color that appears behind each character.
        static void SetBackgroundColor(ConsoleColor color);

        /// @brief Sets the height of the cursor within a character cell.
        /// @param size The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
        static void SetCursorSize(int32 size);

        /// @brief Sets a value indicating whether the cursor is visible.
        /// @param visible true if the cursor is visible; otherwise, false.
        static void SetCursorVisible(bool visible);
        
        /// @brief Sets the foreground color of the console.
        /// @param color A Console Color that specifies the foreground color of the console; that is, the color of each character that is displayed.
        static void SetForegroundColor(ConsoleColor color);

        /// @brief Get console cursor position.
        /// @param x Pointer on uint32_t to get horizontal position (1-80)
        /// @param y Pointer on uint32_t to get vertical position (1-25)
        static void Wherexy(int32* x, int32* y);

      private:
        Console() {}
      };
    }
  }
}

using namespace Pcf;
