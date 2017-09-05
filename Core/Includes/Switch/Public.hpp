/// @file
/// @brief Contains Switch::char16, Switch::int32, ... types.
#pragma once

/// @todo Remove when CMakelists.txt ready
#define SWITCH_STATIC 1

#if SWITCH_STATIC
#  define _public
#elif WIN32
#  if SWITCH_EXPORTS
#    define _public __declspec(dllexport)   
#  else  
#    define _public __declspec(dllimport)   
#  endif
#elif __GNUC__ >= 4 || defined(__clang__)
#  define _public __attribute__((visibility ("default")))
#else
#  define _public
#endif
