#include <csignal>
#include <cstdio>
#include <cstring>
#include <cwchar>
#include <iostream>

#include "../../../Includes/Pcf/System/Console.h"
#include "../../../Includes/Pcf/System/Environment.h"
#include "../Os/Console.h"
#include "../../../Includes/Pcf/System/Text/UTF8Encoding.h"

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4459)
#endif

namespace {
  class ConsoleChangeCodePage {
  public:
    ConsoleChangeCodePage() {
      this->previousInputCodePage = Os::Console::GetInputCodePage();
      Os::Console::SetInputCodePage(65001);
      this->previousOutputCodePage = Os::Console::GetOutputCodePage();
      Os::Console::SetOutputCodePage(65001);
    }

    ~ConsoleChangeCodePage() {
      Os::Console::SetInputCodePage(previousInputCodePage);
      Os::Console::SetOutputCodePage(previousOutputCodePage);
    }

  private:
    int32 previousInputCodePage;
    int32 previousOutputCodePage;
  };

  class ConsoleInterceptSignals {
  public:
    ConsoleInterceptSignals() {
      for(auto signal : signalKeys)
        ::signal(signal.Key, ConsoleInterceptSignals::SignalHandler);
    }
    
    ~ConsoleInterceptSignals() {
      for(auto signal : signalKeys)
        ::signal(signal.Key, SIG_DFL);
    }
    
    static void SignalHandler(int32 signal) {
      ::signal(signal, ConsoleInterceptSignals::SignalHandler);
      System::ConsoleCancelEventArgs consoleCancel = System::ConsoleCancelEventArgs(false, signalKeys[signal]);
      System::Console::CancelKeyPress(Reference<object>::Null(), consoleCancel);
      if (consoleCancel.Cancel == false) 
        exit(-1);
    }
    
    static const System::Collections::Generic::SortedDictionary<int32, System::ConsoleSpecialKey> signalKeys;
  };
  
#if _WIN32
  // This is hack is necessary in windows because std::cout does not work properly with Utf8 and unicode code page
  // Moreover std::cout on Windows is very slow.
  // printf work correctly...
  std::ostream& operator<<(std::ostream& output, const char* value) {
    printf(value);
    return output;
  }
#endif
  
  SharedPointer<System::Text::Encoding> inputEncoding = SharedPointer<System::Text::Encoding>::Create<System::Text::UTF8Encoding>(false);
  SharedPointer<System::Text::Encoding> outputEncoding = SharedPointer<System::Text::Encoding>::Create<System::Text::UTF8Encoding>(false);

  System::ConsoleColor __backgroundColor = static_cast<System::ConsoleColor>(Os::Console::GetBackgroundColor());
  System::ConsoleColor __foregroundColor = static_cast<System::ConsoleColor>(Os::Console::GetForegroundColor());
  bool treatControlCAsInput = false;
  
}

static ConsoleChangeCodePage consoleChangeCodePage;

#if _WIN32
const System::Collections::Generic::SortedDictionary<int32, System::ConsoleSpecialKey> ConsoleInterceptSignals::signalKeys {
  {SIGBREAK, System::ConsoleSpecialKey::ControlBreak},
  {SIGINT, System::ConsoleSpecialKey::ControlC}
};
#else
const System::Collections::Generic::SortedDictionary<int32, System::ConsoleSpecialKey> ConsoleInterceptSignals::signalKeys {
  {SIGQUIT, System::ConsoleSpecialKey::ControlBackslash},
  {SIGTSTP, System::ConsoleSpecialKey::ControlZ},
  {SIGINT, System::ConsoleSpecialKey::ControlC}
};
#endif

static ConsoleInterceptSignals consoleInterceptSignals;

using namespace System;

void Console::StandardErrorOutput::Write(const System::String& s) {
  if (outputEncoding->GetCodePage() == 65001) // Utf8
    std::cerr << (const char*)s.Data();
  else if (outputEncoding->IsSingleByte()) // Ascii
    std::cerr << s.ToCCharArray(outputEncoding->GetCodePage()).Data();
  else if (outputEncoding->GetCodePage() == 1200) { // Unicode
    System::Array<byte> bytes = outputEncoding->GetBytes(s);
    UniquePointer<char16[]> str = UniquePointer<char16[]>::Create(bytes.Length + 1);
    memcpy(str.ToPointer(), bytes.Data, bytes.Length);
    str[bytes.Length] = 0;
    std::wcerr << str.ToPointer();
  } else { // Utf32
    System::Array<byte> bytes = outputEncoding->GetBytes(s);
    UniquePointer<char32[]> str = UniquePointer<char32[]>::Create(bytes.Length + 1);
    memcpy(str.ToPointer(), bytes.Data, bytes.Length);
    str[bytes.Length] = 0;
    std::wcerr << str.ToPointer();
  }
}

void Console::StandardOutput::Write(const System::String& s) {
  if (outputEncoding->GetCodePage() == 65001) // Utf8
    std::cout << (const char*)s.Data();
  else if (outputEncoding->IsSingleByte()) // Ascii
    std::cout << s.ToCCharArray(outputEncoding->GetCodePage()).Data();
  else if (outputEncoding->GetCodePage() == 1200) { // Unicode
    int32 length = outputEncoding->GetByteCount(s);
    UniquePointer<char16[]> str = UniquePointer<char16[]>::Create(length + 1);
    outputEncoding->GetBytes(s, (byte*)str.ToPointer(), length);
    str[length] = 0;
    std::wcout << str.ToPointer();
  } else { // Utf32
    int32 length = outputEncoding->GetByteCount(s);
    UniquePointer<char32[]> str = UniquePointer<char32[]>::Create(length + 1);
    outputEncoding->GetBytes(s, (byte*)str.ToPointer(), length);
    str[length] = 0;
    std::wcout << str.ToPointer();
  }
}

namespace {
  Console::StandardInput sin;
  Console::StandardErrorOutput serror;
  Console::StandardOutput sout;
  System::IO::TextReader* in = &sin;
  System::IO::TextWriter* error = &serror;
  System::IO::TextWriter* out = &sout;
};

Property<ConsoleColor> Console::BackgroundColor {
  []()->ConsoleColor {return static_cast<ConsoleColor>(Os::Console::GetBackgroundColor());},
  [](ConsoleColor value) {
    Pcf::Os::Console::SetBackgroundColor(static_cast<int32>(value));
  }
};

Property<int32> Console::CursorLeft {
  [] {
    int32 left, top;
    Pcf::Os::Console::Wherexy(left, top);
    return left;
  },
  [](int32 value) {
    if (value < 1 || value > 80)
      throw ArgumentOutOfRangeException(pcf_current_information);
      
    int32 left, top;
    Pcf::Os::Console::Wherexy(left, top);
    Pcf::Os::Console::Gotoxy(value, top);
  }
};

Property<int32> Console::CursorSize {
  [] {return Pcf::Os::Console::GetCursorSize();},
  [](int32 value) {
    if (value < 1 || value > 100)
      throw ArgumentOutOfRangeException(pcf_current_information);
      
    Pcf::Os::Console::SetCursorSize(value);
  }
};

Property<int32> Console::CursorTop {
  [] {
    int32 left, top;
    Pcf::Os::Console::Wherexy(left, top);
    return top;
  },
  [](int32 value) {
    if (value < 1 || value > 25)
      throw ArgumentOutOfRangeException(pcf_current_information);
      
    int32 left, top;
    Pcf::Os::Console::Wherexy(left, top);
    Pcf::Os::Console::Gotoxy(left, value);
  }
};

Property<bool> Console::CursorVisible {
  [] {return Pcf::Os::Console::GetCursorVisible();},
  [](bool value) {Pcf::Os::Console::SetCursorVisible(value);}
};

Property<Console::StandardErrorOutput&, ReadOnly> Console::Error {
  []()->Console::StandardErrorOutput& {
    static StandardErrorOutput error;
    return error;
  }
};

Property<ConsoleColor> Console::ForegroundColor {
  [] {return static_cast<ConsoleColor>(Os::Console::GetForegroundColor());},
  [](ConsoleColor value) {
    Pcf::Os::Console::SetForegroundColor(static_cast<int32>(value));
  }
};

Property<Console::StandardInput&, ReadOnly> Console::In {
  []()->Console::StandardInput& {
    static StandardInput in;
    return in;
  }
};

Property<const SharedPointer<System::Text::Encoding>&> Console::InputEncoding {
  []()->const SharedPointer<System::Text::Encoding>& {return inputEncoding;},
  [](const SharedPointer<System::Text::Encoding>& value) {
    inputEncoding = value;
    Pcf::Os::Console::SetInputCodePage(inputEncoding->GetCodePage());
  }
};

Property<bool, ReadOnly> Console::KeyAvailable {
  [] {return Pcf::Os::Console::KeyAvailable();}
};

Property<Console::StandardOutput&, ReadOnly> Console::Out {
  []()->Console::StandardOutput& {
    static StandardOutput out;
    return out;
  }
};

Property<const SharedPointer<System::Text::Encoding>&> Console::OutputEncoding {
  []()->const SharedPointer<System::Text::Encoding>& {return outputEncoding;},
  [](const SharedPointer<System::Text::Encoding>& value) {
    outputEncoding = value;
    Pcf::Os::Console::SetOutputCodePage(outputEncoding->GetCodePage());
  }
};

Property<bool> Console::TreatControlCAsInput {
  [] {return treatControlCAsInput;},
  [](bool value) {treatControlCAsInput = value;}
};

ConsoleCancelEventHandler Console::CancelKeyPress;

void Console::Beep() {
  Beep(800, 200);
}

void Console::Beep(int32 frequency, int32 duration) {
  if (frequency < 37 || frequency > 32767 || duration <= 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  Pcf::Os::Console::Beep(frequency, duration);
}

void Console::Clear() {
  Pcf::Os::Console::Clrscr();
}

int32 Console::Read() {
  out->Flush();
  return in->Read();
}

struct AutoEchoVisible {
  AutoEchoVisible() {Os::Console::SetEchoVisible(true);}
  ~AutoEchoVisible() {Os::Console::SetEchoVisible(false);}
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
  Pcf::Os::Console::ReadKey(KeyChar, KeyCode, alt, shift, ctrl);
  keyInfo = ConsoleKeyInfo(KeyChar, (ConsoleKey)KeyCode, shift, alt, ctrl);

  if (intercept == false)
    Write(Char(keyInfo.KeyChar()));
  
  return keyInfo;
}

void Console::ResetColor() {
  Pcf::Os::Console::SetForegroundColor(static_cast<uint16>(::__foregroundColor));
  Pcf::Os::Console::SetBackgroundColor(static_cast<uint16>(::__backgroundColor));
}

void Console::SetCursorPosition(int32 left, int32 top) {
  int32 width = 0;
  int32 height = 0;
  Pcf::Os::Console::GetBufferSize(width, height);
  if (left < 1 || left > width || top < 1 || top > height)
    throw ArgumentOutOfRangeException(pcf_current_information);

  Pcf::Os::Console::Gotoxy(left, top);
}

void Console::SetError(System::IO::TextWriter& error) { ::error = &error; }

void Console::SetInt(System::IO::TextReader& in) { ::in = &in; }

void Console::SetOut(System::IO::TextWriter& out) { ::out = &out; }


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

#if __APPLE__
void Console::Write(size value) {
  Write(string::Format("{0}", value));
}
#endif

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

#if __linux__ && _LP64
void Console::Write(long long int value) {
  Write(String::Format("{0}", value));
}

void Console::Write(unsigned long long int value) {
  Write(String::Format("{0}", value));
}

#else
void Console::Write(long value) {
  Write(String::Format("{0}", value));
}
#endif

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

#if __APPLE__
void Console::WriteLine(size value) {
  Write(string::Format("{0}{1}", value, Environment::NewLine));
}
#endif

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

#if _WIN32
#pragma warning(pop)
#endif

