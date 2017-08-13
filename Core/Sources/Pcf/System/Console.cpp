#include <cstdio>
#include <cstring>
#include <cwchar>
#include <iostream>

#include "../../../Includes/Pcf/System/IO/IOException.hpp"
#include "../../../Includes/Pcf/System/Buffer.hpp"
#include "../../../Includes/Pcf/System/Console.hpp"
#include "../../../Includes/Pcf/System/Environment.hpp"
#include "../../../Includes/Pcf/System/Text/UTF8Encoding.hpp"
#include "../../__OS/CoreApi.hpp"

namespace {
  // This hack is necessary in windows because std::cout does not work properly with Utf8 and unicode code page
  // Moreover std::cout on Windows is very slow.
  // printf work correctly...
  std::ostream& operator<<(std::ostream& output, const char* value) {
    printf("%s", value);
    return output;
  }
  
  refptr<System::Text::Encoding> inputEncoding = pcf_new<System::Text::UTF8Encoding>(false);
  refptr<System::Text::Encoding> outputEncoding = pcf_new<System::Text::UTF8Encoding>(false);

  bool treatControlCAsInput = false;
}

using namespace System;

void Console::StandardErrorOutput::Write(const System::String& s) {
  if (outputEncoding->GetCodePage() == 65001) // Utf8
    std::cerr << (const char*)s.Data();
  else if (outputEncoding->IsSingleByte()) // Ascii
    std::cerr << s.ToCCharArray(outputEncoding->GetCodePage()).Data();
  else if (outputEncoding->GetCodePage() == 1200) { // Unicode
    System::Array<byte> bytes = outputEncoding->GetBytes(s);
    System::Array<char16> str(bytes.Length + 1);
    Buffer::BlockCopy(bytes, 0, str, 0, bytes.Length);
    str[bytes.Length] = 0;
    std::wcerr << str.Data();
  } else { // Utf32
    System::Array<byte> bytes = outputEncoding->GetBytes(s);
    System::Array<char32> str(bytes.Length + 1);
    Buffer::BlockCopy(bytes, 0, str, 0, bytes.Length);
    str[bytes.Length] = 0;
    std::wcerr << str.Data();
  }
}

void Console::StandardOutput::Write(const System::String& s) {
  if (outputEncoding->GetCodePage() == 65001) // Utf8
    std::cout << (const char*)s.Data();
  else if (outputEncoding->IsSingleByte()) // Ascii
    std::cout << s.ToCCharArray(outputEncoding->GetCodePage()).Data();
  else if (outputEncoding->GetCodePage() == 1200) { // Unicode
    int32 length = outputEncoding->GetByteCount(s);
    System::Array<char16> str(length + 1);
    outputEncoding->GetBytes(s, (byte*)str.Data(), length);
    str[length] = 0;
    std::wcout << str.Data();
  } else { // Utf32
    int32 length = outputEncoding->GetByteCount(s);
    System::Array<char32> str(length + 1);
    outputEncoding->GetBytes(s, (byte*)str.Data(), length);
    str[length] = 0;
    std::wcout << str.Data();
  }
}

namespace {
  Console::StandardInput sin;
  Console::StandardErrorOutput serror;
  Console::StandardOutput sout;
  System::IO::TextReader* defaultIn = &sin;
  System::IO::TextWriter* defaultError = &serror;
  System::IO::TextWriter* defaultOut = &sout;
  System::IO::TextReader* in = &sin;
  System::IO::TextWriter* error = &serror;
  System::IO::TextWriter* out = &sout;
}

Property<ConsoleColor> Console::BackgroundColor {
  [] {return __OS::CoreApi::Console::GetBackgroundColor();},
  [](ConsoleColor value) {
    if (!Enum<ConsoleColor>::IsDefined(value))
      throw ArgumentException(pcf_current_information);
    if (!__OS::CoreApi::Console::SetBackgroundColor(value))
      throw System::IO::IOException(pcf_current_information);
  }
};

Property<int32> Console::BufferHeight{
  [] {return __OS::CoreApi::Console::GetBufferHeight(); },
  [](int32 value) {
    __OS::CoreApi::Console::SetBufferHeight(value);
  }
};

Property<int32> Console::BufferWidth{
  [] {return __OS::CoreApi::Console::GetBufferWidth(); },
  [](int32 value) {
    __OS::CoreApi::Console::SetBufferWidth(value);
  }
};

Property<bool, ReadOnly> Console::CapsLock {
  [] {return __OS::CoreApi::Console::GetCapsLock();}
};

Property<int32> Console::CursorLeft {
  [] {return __OS::CoreApi::Console::GetCursorTop();},
  [](int32 value) {
    if (value < 0 || value >= __OS::CoreApi::Console::GetWindowWidth())
      throw ArgumentOutOfRangeException(pcf_current_information);
      
    __OS::CoreApi::Console::SetCursorLeft(value);
  }
};

Property<int32> Console::CursorSize {
  [] {return __OS::CoreApi::Console::GetCursorSize();},
  [](int32 value) {
    if (value < 1 || value > 100)
      throw ArgumentOutOfRangeException(pcf_current_information);
      
    __OS::CoreApi::Console::SetCursorSize(value);
  }
};

Property<int32> Console::CursorTop {
  [] {return __OS::CoreApi::Console::GetCursorTop();},
  [](int32 value) {
    if (value < 0 || value >= __OS::CoreApi::Console::GetBufferHeight())
      throw ArgumentOutOfRangeException(pcf_current_information);
      
    __OS::CoreApi::Console::SetCursorTop(value);
  }
};

Property<bool> Console::CursorVisible {
  [] {return __OS::CoreApi::Console::GetCursorVisible();},
  [](bool value) {__OS::CoreApi::Console::SetCursorVisible(value);}
};

Property<Console::StandardErrorOutput&, ReadOnly> Console::Error {
  []()->Console::StandardErrorOutput& {
    static StandardErrorOutput e;
    return e;
  }
};

Property<ConsoleColor> Console::ForegroundColor {
  [] {return __OS::CoreApi::Console::GetForegroundColor();},
  [](ConsoleColor value) {
    if (!Enum<ConsoleColor>::IsDefined(value))
      throw ArgumentException(pcf_current_information);
    __OS::CoreApi::Console::SetForegroundColor(value);
  }
};

Property<Console::StandardInput&, ReadOnly> Console::In {
  []()->Console::StandardInput& {
    static StandardInput i;
    return i;
  }
};

Property<const refptr<System::Text::Encoding>&> Console::InputEncoding {
  []()->const refptr<System::Text::Encoding>& {return inputEncoding;},
  [](const refptr<System::Text::Encoding>& value) {
    inputEncoding = value;
    __OS::CoreApi::Console::SetInputCodePage(inputEncoding->GetCodePage());
  }
};

Property<bool, ReadOnly> Console::IsErrorRedirected{
  [] {return error != defaultError; }
};

Property<bool, ReadOnly> Console::IsInputRedirected{
  [] {return in != defaultIn; }
};

Property<bool, ReadOnly> Console::IsOutputRedirected{
  [] {return out != defaultOut; }
};

Property<bool, ReadOnly> Console::KeyAvailable {
  [] {
    Console::__f();
    return __OS::CoreApi::Console::KeyAvailable();}
};

Property<int32, ReadOnly> Console::LargestWindowHeight{
  [] {return __OS::CoreApi::Console::GetLargestWindowHeight(); }
};

Property<int32, ReadOnly> Console::LargestWindowWidth{
  [] {return __OS::CoreApi::Console::GetLargestWindowWidth(); }
};

Property<bool, ReadOnly> Console::NumberLock{
  [] {return __OS::CoreApi::Console::GetNumberLock(); }
};

Property<Console::StandardOutput&, ReadOnly> Console::Out {
  []()->Console::StandardOutput& {
    static StandardOutput o;
    return o;
  }
};

Property<const refptr<System::Text::Encoding>&> Console::OutputEncoding {
  []()->const refptr<System::Text::Encoding>& {return outputEncoding;},
  [](const refptr<System::Text::Encoding>& value) {
    outputEncoding = value;
    __OS::CoreApi::Console::SetOutputCodePage(outputEncoding->GetCodePage());
  }
};

Property<string> Console::Title {
  [] {return __OS::CoreApi::Console::GetTitle(); },
  [](const string& value) {__OS::CoreApi::Console::SetTitle(value);}
};

Property<bool> Console::TreatControlCAsInput {
  [] {return treatControlCAsInput;},
  [](bool value) {treatControlCAsInput = value;}
};

Property<int32> Console::WindowHeight {
  []{return __OS::CoreApi::Console::GetWindowHeight(); },
  [](int32 value) {
    __OS::CoreApi::Console::SetWindowHeight(value);
  }
};

Property<int32> Console::WindowLeft {
  []{return __OS::CoreApi::Console::GetWindowLeft(); },
  [](int32 value) {
    __OS::CoreApi::Console::SetWindowLeft(value);
  }
};

Property<int32> Console::WindowTop {
  []{return __OS::CoreApi::Console::GetWindowTop(); },
  [](int32 value) {
    __OS::CoreApi::Console::SetWindowTop(value);
  }
};

Property<int32> Console::WindowWidth {
  [] {return __OS::CoreApi::Console::GetWindowWidth(); },
  [](int32 value) {
    __OS::CoreApi::Console::SetWindowWidth(value);
  }
};

ConsoleCancelEventHandler Console::CancelKeyPress;

void Console::Beep() {
  Beep(800, 200);
}

void Console::Beep(int32 frequency, int32 duration) {
  if (frequency < 37 || frequency > 32767 || duration <= 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  __OS::CoreApi::Console::Beep(frequency, duration);
}

void Console::Clear() {
  __OS::CoreApi::Console::Clrscr();
}

void Console::MoveBufferArea(int32 sourceLeft, int32 sourceTop, int32 sourceWidth, int32 sourceHeight, int32 targetLeft, int32 targetTop, char32 sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor) {
  
}


int32 Console::Read() {
  out->Flush();
  return in->Read();
}

struct AutoEchoVisible {
  AutoEchoVisible() {__OS::CoreApi::Console::SetEchoVisible(true);}
  ~AutoEchoVisible() {__OS::CoreApi::Console::SetEchoVisible(false);}
};

String Console::ReadLine() {
  AutoEchoVisible autoEchoVisible;
  out->Flush();
  return in->ReadLine();
}

ConsoleKeyInfo Console::ReadKey() {
  return ReadKey(false);
}

ConsoleKeyInfo Console::ReadKey(bool intercept) {
  int32 KeyChar = 0;
  int32 KeyCode = 0;
  bool alt = false;
  bool shift = false;
  bool ctrl = false;
  ConsoleKeyInfo keyInfo;
  
  out->Flush();
  __OS::CoreApi::Console::ReadKey(KeyChar, KeyCode, alt, shift, ctrl);
  keyInfo = ConsoleKeyInfo(KeyChar, (ConsoleKey)KeyCode, shift, alt, ctrl);

  if (intercept == false)
    Write(Char(keyInfo.KeyChar()));
  
  return keyInfo;
}

void Console::ResetColor() {
  __OS::CoreApi::Console::ResetColor();
}

void Console::SetError(System::IO::TextWriter& e) { error = &e; }

void Console::SetInt(System::IO::TextReader& i) { in = &i; }

void Console::SetOut(System::IO::TextWriter& o) { out = &o; }


void Console::Write(bool value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char16 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(wchar value) {
  Write(string::Format("{0}", value));
}

void Console::Write(double value) {
  Write(string::Format("{0}", value));
}

void Console::Write(int32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(int64 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const object& value) {
  Write(string::Format("{0}", value.ToString()));
}

void Console::Write(float value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const String& value) {
  pcf_lock(*out)
    out->Write(value);
}

void Console::Write(uint32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(uint64 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char16 value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char32 value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const wchar value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(llong value) {
  Write(String::Format("{0}", value));
}

void Console::Write(ullong value) {
  Write(String::Format("{0}", value));
}

void Console::Write(unsigned char* value) {
  Write(String::Format("{0}", value));
}

void Console::WriteLine() {
  Write(string::Format("{0}", Environment::NewLine));
}

void Console::WriteLine(bool value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(char value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(char16 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(char32 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(wchar value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(double value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(int32 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(int64 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const object& value) {
  Write(string::Format("{0}{1}", value.ToString(), Environment::NewLine));
}

void Console::WriteLine(float value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const String& value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(uint32 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(uint64 value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(llong value) {
  Write(String::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(ullong value) {
  Write(String::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const char value[]) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const char16 value[]) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const char32 value[]) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::WriteLine(const wchar value[]) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}

void Console::__f() {
  out->Flush();
}
