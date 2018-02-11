#include "../../include/Switch/Types.hpp"

using HINSTANCE = struct HINSTANCE__ {int unused;}*;
core_export_ HINSTANCE __instance = null;
core_export_ int __commandShow = 10; // SW_SHOWDEFAULT;

#if !defined (WIN32)
int __argc = 0;
char** __argv = null;
#endif