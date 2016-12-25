#include <Pcf/Pcf>

using namespace System;

int main(int argc, char* argv[]) {
  Console::Write(String("System::Console and System::String:") + Environment::NewLine);
  Console::Write(String("This is a test in english") + Environment::NewLine);
  Console::Write(String("?れ??日本??テスト??。") + Environment::NewLine);
  Console::WriteLine();
}

// This code produces the following output:
//
// System::Console and System::String:
// This is a test in english
// ?れ??日本??テスト??。
//
