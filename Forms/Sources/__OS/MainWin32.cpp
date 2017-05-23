﻿#if defined(_WIN32) && defined(__use_native_interface__)
#include <Windows.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"

extern int main(int argc, char* argv[]);
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
HINSTANCE __instance;

int CALLBACK WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR commandLine, int cmdShow) {
  __instance = instance;
  return main(__argc, __argv);
}

#endif