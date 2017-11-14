#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Character literals");
      Console::WriteLine('H');
      //Console::WriteLine(u8'П'); // C++17 only
      Console::WriteLine(L'ם');
      //Console::WriteLine(u'こ'); // No build on Windows
      //Console::WriteLine(U'🐨'); // No build on Windows
      Console::WriteLine();
      Console::WriteLine("String literals");
      Console::WriteLine("Hello, World!");
      Console::WriteLine(u8"Привет мир! 🐨");
      Console::WriteLine(L"!שלום עולם");
      Console::WriteLine(u"こんにちは世界！");
      Console::WriteLine(U"!مرحبا بالعالم 🐨");
      Console::WriteLine();
      Console::WriteLine(R"(Raw string literals containing unescaped \ and ")");
      Console::WriteLine(R"("Hello \ World!")");
      Console::WriteLine(u8R"("Привет \ мир! 🐨")");
      Console::WriteLine(LR"("!שלום \ עולם")");
      Console::WriteLine(uR"("こんに \ ちは世界！")");
      Console::WriteLine(UR"("!مرحبا \ بالعالم 🐨")");
      Console::WriteLine();
      Console::WriteLine("Combining string literals with Switch _s suffix");
      Console::WriteLine("Hello, World!"_s);
      Console::WriteLine(u8"Привет мир! 🐨"_s);
      Console::WriteLine(L"!שלום עולם"_s);
      Console::WriteLine(u"こんにちは世界！"_s);
      Console::WriteLine(U"!مرحبا بالعالم 🐨"_s);
      Console::WriteLine();
      Console::WriteLine("Combining raw string literals with Switch _s suffix");
      Console::WriteLine(R"("Hello \ World!")"_s);
      Console::WriteLine(u8R"("Привет \ мир! 🐨")"_s);
      Console::WriteLine(LR"("!שלום \ עולם")"_s);
      Console::WriteLine(uR"("こんに \ ちは世界！")"_s);
      Console::WriteLine(UR"("!مرحبا \ بالعالم 🐨")"_s);
      Console::WriteLine();
      Console::WriteLine("String literals with universal character names");
      Console::WriteLine("😀 = \U0001F600 is :-)");
      Console::WriteLine(L"😉 = \U0001F609 is ;-)");
      Console::WriteLine(u8"😇 = \U0001F607 is O:-)");
      Console::WriteLine(u"😃 = \U0001F603 is :-D");
      Console::WriteLine(U"😎 = \U0001F60E is B-)");
    }
  };
}

_startup(Examples::Program);
