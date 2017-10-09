﻿#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>

#include "FormsApi.hpp"

extern int main(int argc, char* argv[]);
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
HINSTANCE __instance;

int CALLBACK WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR commandLine, int cmdShow) {
  __instance = instance;
  return main(__argc, __argv);
}

#endif