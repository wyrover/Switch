#include <Switch/Switch>

using namespace System;

int main(int argc, char* argv[]) {
  // Must be call only once otherwise SetCommandLineArgs throw an InvalidOperationException exception
  Environment::SetCommandLineArgs(argv, argc);

  // Write arguments to the console output
  for (string arg : Environment::GetCommandLineArgs())
    Console::WriteLine(arg);

  return 42;
}

// This code produces the following output if One Two "Three Four" Five are entered on command line:
//
// /!---OMITTED---!/Main5
// One
// Two
// Three Four
// Five
