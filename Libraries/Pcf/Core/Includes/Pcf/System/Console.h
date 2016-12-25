/// @file
/// @brief Contains Pcf::System::Console class.
#pragma once

#include "../Property.h"
#include "../Types.h"
#include "../SharedPointer.h"
#include "../Static.h"
#include "../UniquePointer.h"
#include "Array.h"
#include "Char.h"
#include "ConsoleCancelEventHandler.h"
#include "ConsoleColor.h"
#include "ConsoleKeyInfo.h"
#include "IO/TextReader.h"
#include "IO/TextWriter.h"
#include "Text/Encoding.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents the standard input, output, and error streams for console applications.
    /// This class cannot be inherited.
    /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the SetIn and SetOut methods.
    /// @include Console.cpp
    /// @include ConsoleOut.cpp
    class Console pcf_static {
    public:
      class StandardInput : public System::IO::TextReader {
      public:
        StandardInput() {}
        StandardInput(const StandardInput& in) { *this = in; }
        StandardInput& operator =(const StandardInput&) { return *this; }
      private:
        int32 Peek() const override {return std::cin.peek();}
        int32 Read() override {return std::cin.get();}
      };
      
      class StandardErrorOutput : public System::IO::TextWriter {
      public:
        StandardErrorOutput() {}
        StandardErrorOutput(const StandardErrorOutput& error) { *this = error; }
        StandardErrorOutput& operator =(const StandardErrorOutput&) { return *this; }
        void Flush() override {std::cerr.flush();}
      private:
        using TextWriter::Write;
        void Write(const System::String& s) override;
      };
      
      class StandardOutput : public System::IO::TextWriter {
      public:
        StandardOutput() {}
        StandardOutput(const StandardOutput& out) { *this = out; }
        StandardOutput& operator =(const StandardOutput&) { return *this; }
        void Flush() override {std::cout.flush();}
      private:
        using TextWriter::Write;
        void Write(const System::String& s) override;
      };

      /// @brief Gets or sets the background color of the console.
      /// @param A ConsoleColor that specifies the background color of the console; that is, the color that appears behind each character.
      static Property<ConsoleColor> BackgroundColor;

      /// @brief Gets or sets the column position of the cursor within the buffer area.
      /// @param The current position, in columns, of the cursor.
      /// @exception ArgumentOutOfRangeException left less than 1 or greater than 80.
      static Property<int32> CursorLeft;

      /// @brief Gets or sets the height of the cursor within a character cell.
      /// @param size The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
      /// @exception ArgumentOutOfRangeException size less than 1 or greater than 100.
      static Property<int32> CursorSize;

      /// @brief Gets or sets the row position of the cursor within the buffer area.
      /// @param int32 The current position, in rows, of the cursor.
      /// @exception ArgumentOutOfRangeException top less than 1 or greater than 25.
      static Property<int32> CursorTop;

      /// @brief Gets or sets a value indicating whether the cursor is visible.
      /// @param true if the cursor is visible; otherwise, false.
      static Property<bool> CursorVisible;

      /// @brief Gets the standard error outpout stream.
      /// @param A TextWriter that represents the standard error output stream.
      static Property<StandardErrorOutput&, ReadOnly> Error;

      /// @brief Gets or sets the foreground color of the console.
      /// @param A ConsoleColor that specifies the foreground color of the console; that is, the color of each character that is displayed.
      static Property<ConsoleColor> ForegroundColor;

      /// @brief Gets the standard input stream.
      /// @param A TextReader that represents the standard input stream.
      static Property<StandardInput&, ReadOnly> In;

      /// @brief Gets or sets the encoding the console uses to read input.
      /// @param The encoding used to read console input.
      static Property<const SharedPointer<System::Text::Encoding>&> InputEncoding;

      /// @brief Gets a value indicating whether a key press is available in the input stream.
      /// @param true if a key press is available; otherwise, false
      /// @remarks The KeyAvailable method is returned immediately; that is, the KeyAvailable method does not block input until a key press is available.
      /// @remarks Use the KeyAvailable method in conjunction with only the ReadKey method, not the Read or ReadLine methods
      static Property<bool, ReadOnly> KeyAvailable;

      /// @brief Gets the standard output stream.
      /// @param A TextWriter that represents the standard output stream.
      static Property<StandardOutput&, ReadOnly> Out;

      /// @brief Gets the encoding the console uses to write output.
      /// @param The encoding used to write console output.
      static Property<const SharedPointer<System::Text::Encoding>&> OutputEncoding;

      /// @brief Gets or sets a value indicating whether the combination of the Control modifier key and C console key (Ctrl+C) is treated as ordinary input or as an interruption that is handled by the operating system.
      /// @param bool true if Ctrl+C is treated as ordinary input; otherwise, false.
      /// @remarks If the value of the TreatControlCAsInput property is false and Ctrl+C is pressed, the pressed keys are not stored in the input buffer and the operating system terminates the currently executing process. This is the default value.
      /// @warning Use this property judiciously because setting it to true has such a dramatic effect. Most users expect Ctrl+C to terminate a console application. If you disable the effect of Ctrl+C, the user must remember to use Ctrl+Break to terminate the application, which is a less familiar key combination.
      static Property<bool> TreatControlCAsInput;

      /// @brief Plays the sound of a beep through the console speaker.
      /// @remarks By default, the beep plays at a frequency of 800 hertz for a duration of 200 milliseconds
      static void Beep();

      /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
      /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
      /// @param duration The duration of the beep measured in milliseconds
      static void Beep(int32 frequency, int32 duration);

      /// @brief Clears the console buffer and corresponding console window of display information.
      /// @remarks pcf_using the Clear method is equivalent invoking the MS-DOS cls command in the command prompt window.
      /// @remarks When the Clear method is called, the cursor automatically scrolls to the top-left corner of the window and the contents of the screen buffer are set to blanks using the current foreground background colors.
      static void Clear();

      /// @brief Reads the next character from the standard input stream.
      /// @return int32 The next character from the input stream, or negative one (-1) if there are currently no more characters to be read
      /// @remarks The Read method blocks its return while you type input characters; it terminates when you press the Enter key.
      /// @remarks Pressing Enter appends a platform-dependent line termination sequence to your input (for example, Windows appends a carriage return-linefeed sequence).
      /// @remarks Subsequent calls to the Read method retrieve your input one character at a time. After the final character is retrieved, Read blocks its return again and the cycle repeats.
      /// @remarks Note that you will not get a property value of -1 unless you perform one of the following actions: simultaneously press the Control modifier key and Z console key (CTRL+Z),
      /// @remarks which signals the end-of-file condition; press an equivalent key that signals the end-of-file condition, such as the F6 function key in Windows; or redirect the input stream to a source,
      /// @remarks such as a text file, that has an actual end-of-file character.
      static int32 Read();

      /// @brief Reads the next line of characters from the standard input stream.
      static String ReadLine();

      /// @brief Obtains the next character or function key pressed by the user. The pressed key is displayed in the console window.
      /// @return ConsoleKeyInfo A ConsoleKeyInfo object that describes the ConsoleKey constant and Unicode character, if any, that correspond to the pressed console key.
      /// The ConsoleKeyInfo object also describes, in a bitwise combination of ConsoleModifiers values, whether one or more SHIFT, ALT, or CTRL modifier keys was pressed simultaneously with the console key.
      static ConsoleKeyInfo ReadKey();

      /// @brief Obtains the next character or function key pressed by the user. The pressed key is optionally displayed in the console window.
      /// @param intercept Determines whether to display the pressed key in the console window. true to not display the pressed key; otherwise, false
      /// @return ConsoleKeyInfo A ConsoleKeyInfo object that describes the ConsoleKey constant and Unicode character, if any, that correspond to the pressed console key.
      /// The ConsoleKeyInfo object also describes, in a bitwise combination of ConsoleModifiers values, whether one or more SHIFT, ALT, or CTRL modifier keys was pressed simultaneously with the console key.
      static ConsoleKeyInfo ReadKey(bool intercept);

      /// @brief Sets the foreground and background console colors to their defaults.
      /// @remarks The foreground and background colors are restored to the colors that existed when the current process began.
      /// @remarks For more information, see the GetForegroundColor() and GetBackgroundColor() properties
      static void ResetColor();

      /// @brief Sets the position of the cursor.
      /// @param left The column position of the cursor (1-80).
      /// @param top The row position of the cursor (1-25).
      /// @exception ArgumentOutOfRangeException left lessa than 1 or greater than 80  - or -  top less than 1 or greater than 25.
      static void SetCursorPosition(int32 left, int32 top);

      /// @brief Writes the specified bool value to the standard output stream.
      /// @param value The value to write
      static void Write(bool value);
      
      /// @brief Writes the specified char value to the standard output stream.
      /// @param value The value to write
      static void Write(char value);
      
      /// @brief Writes the specified char16 value to the standard output stream.
      /// @param value The value to write
      static void Write(char16 value);
      
      /// @brief Writes the specified char32 value to the standard output stream.
      /// @param value The value to write
      static void Write(char32 value);
      
      /// @brief Writes the specified wchar value to the standard output stream.
      /// @param value The value to write
      static void Write(wchar value);

      /// @brief Writes the specified double value to the standard output stream.
      /// @param value The value to write
      static void Write(double value);

      /// @brief Writes the specified int32 value to the standard output stream.
      /// @param value The value to write
      static void Write(int32 value);

      /// @brief Writes the specified int64 value to the standard output stream.
      /// @param value The value to write
      static void Write(int64 value);

      /// @brief Writes the specified object value to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void Write(const object& value);

      /// @brief Writes the specified single value to the standard output stream.
      /// @param value The value to write
      static void Write(float value);

      /// @brief Writes the specified String value to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void Write(const String& value);

      /// @brief Writes the specified Uint32 value to the standard output stream.
      /// @param value The value to write
      static void Write(uint32 value);

      /// @brief Writes the specified UInt64 value to the standard output stream.
      /// @param value The value to write
      static void Write(uint64 value);
      
#if __APPLE__
      /// @brief Writes the specified size value to the standard output stream.
      /// @param value The value to write
      static void Write(size value);
#endif

      /// @brief Writes the specified uint64 value to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void Write(const char value[]);
      
      /// @brief Writes the specified uint64 value to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void Write(const char16 value[]);
      
      /// @brief Writes the specified uint64 value to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void Write(const char32 value[]);
      
      /// @brief Writes the specified uint64 value to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void Write(const wchar value[]);
      
#if __linux__ && _LP64
      static void Write(long long int value);
      static void Write(unsigned long long int value);
#else
      static void Write(long value);
#endif

      static void Write(unsigned char* value);
      
      static void Write(const String& format, const Array< Reference<Object>>& array) {
        Write(String::Format(format,array));
      }

      template<typename T0>
      static void Write(const String& format, const T0& arg0) {
        Write(String::Format(format, arg0));
      }

      template<typename T0, typename T1>
      static void Write(const String& format, const T0& arg0, const T1& arg1) {
        Write(String::Format(format, arg0, arg1));
      }

      template<typename T0, typename T1, typename T2>
      static void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2) {
        Write(String::Format(format,arg0, arg1, arg2));
      }

      template<typename T0, typename T1, typename T2, typename T3>
      static void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3) {
        Write(String::Format(format,arg0, arg1, arg2,arg3));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4>
      static void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4) {
        Write(String::Format(format,arg0, arg1, arg2,arg3,arg4));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
      static void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5) {
        Write(String::Format(format,arg0, arg1, arg2, arg3, arg4, arg5));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
      static void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6) {
        Write(String::Format(format,arg0, arg1, arg2, arg3, arg4, arg5, arg6));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
      static void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7) {
        Write(String::Format(format,arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
      static void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8) {
        Write(String::Format(format,arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
      static void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8, const T9& arg9) {
        Write(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9));
      }

      /// @brief Writes the current line terminator to the standard output stream.
      static void WriteLine();

      /// @brief Writes the specified bool value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(bool value);
      
      /// @brief Writes the specified char value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(char value);
      
      /// @brief Writes the specified char16 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(char16 value);
      
      /// @brief Writes the specified char32 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(char32 value);
      
      /// @brief Writes the specified wchar value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(wchar value);

      /// @brief Writes the specified double value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(double value);

      /// @brief Writes the specified int32 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(int32 value);

      /// @brief Writes the specified int64 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(int64 value);

      /// @brief Writes the specified object value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void WriteLine(const object& value);

      /// @brief Writes the specified single value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(float value);

      /// @brief Writes the specified String value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void WriteLine(const String& value);

      /// @brief Writes the specified uint32 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(uint32 value);

      /// @brief Writes the specified UInt64 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(uint64 value);
      
#if __APPLE__
      /// @brief Writes the specified size value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(size value);
#endif

      /// @brief Writes the specified Format-control String value, followed by the current line terminator, to the standard output stream.
      /// @param format The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void WriteLine(const char value[]);
      
      /// @brief Writes the specified Format-control String value, followed by the current line terminator, to the standard output stream.
      /// @param format The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void WriteLine(const char16 value[]);
      
      /// @brief Writes the specified Format-control String value, followed by the current line terminator, to the standard output stream.
      /// @param format The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void WriteLine(const char32 value[]);
      
      /// @brief Writes the specified Format-control String value, followed by the current line terminator, to the standard output stream.
      /// @param format The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void WriteLine(const wchar value[]);
      
      static void WriteLine(const String& format, const Array< Reference<Object>>& array) {
        WriteLine(String::Format(format,array));
      }

      template<typename T0>
      static void WriteLine(const String& format, const T0& arg0) {
        WriteLine(String::Format(format, arg0));
      }

      template<typename T0, typename T1>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1) {
        WriteLine(String::Format(format, arg0, arg1));
      }

      template<typename T0, typename T1, typename T2>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2) {
        WriteLine(String::Format(format,arg0, arg1, arg2));
      }

      template<typename T0, typename T1, typename T2, typename T3>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3) {
        WriteLine(String::Format(format,arg0, arg1, arg2,arg3));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4) {
        WriteLine(String::Format(format,arg0, arg1, arg2,arg3,arg4));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5) {
        WriteLine(String::Format(format,arg0, arg1, arg2, arg3, arg4, arg5));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6) {
        WriteLine(String::Format(format,arg0, arg1, arg2, arg3, arg4, arg5, arg6));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7) {
        WriteLine(String::Format(format,arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8) {
        WriteLine(String::Format(format,arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));
      }

      template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
      static void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8, const T9& arg9) {
        WriteLine(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9));
      }

      static void SetError(System::IO::TextWriter& error);

      static void SetInt(System::IO::TextReader& in);

      static void SetOut(System::IO::TextWriter& out);

      /// @brief Occurs when the Control modifier key (Ctrl) and either the ConsoleKey.C console key (C) or the Break key are pressed simultaneously (Ctrl+C or Ctrl+Break).
      /// @remarks This event is used in conjunction with System::ConsoleCancelEventHandler and System::ConsoleCancelEventArgs. The CancelKeyPress event enables a console application to intercept the Ctrl+C signal so the event handler can decide whether to continue executing or terminate. For more information about handling events, see Handling and Raising Events.
      /// When the user presses either Ctrl+C or Ctrl+Break, the CancelKeyPress event is fired and the application's ConsoleCancelEventHandler event handler is executed. The event handler is passed a ConsoleCancelEventArgs object that has two useful properties:
      /// * SpecialKey, which allows you to determine whether the handler was invoked as a result of the user pressing Ctrl+C (the property value is ConsoleSpecialKey.ControlC) or Ctrl+Break (the property value is ConsoleSpecialKey.ControlBreak).
      /// * Cancel, which allows you to determine how to your application should respond to the user pressing Ctrl+C or Ctrl+Break. By default, the Cancel property is false, which causes program execution to terminate when the event handler exits. Changing its property to true specifies that the application should continue to execute.
      /// @note If your application has simple requirements, you can use the TreatControlCAsInput property instead of this event. By setting this property to false, you can ensure that your application always exits if the user presses Ctrl+C. By setting it to true, you can ensure that pressing Ctrl+C will not terminate the application.
      static ConsoleCancelEventHandler CancelKeyPress;
    };
  }
}

using namespace Pcf;
