#include "../../include/Switch/Types.hpp"

using HINSTANCE = struct HINSTANCE__ {int unused;}*;
HINSTANCE __instance = null;
int __commandShow = 10; // SW_SHOWDEFAULT;

#if !defined (WIN32)
int __argc = 0;
char** __argv = null;
#endif