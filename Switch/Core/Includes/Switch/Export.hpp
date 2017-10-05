/// @file
/// @brief Contains _export keyword.
#pragma once

/// @todo Remove when CMakelists.txt ready
#define SWITCH_STATIC 1

#if SWITCH_STATIC
#  define _export
#elif WIN32
#  if SWITCH_EXPORTS
#    define _export __declspec(dllexport)
#  else  
#    define _export __declspec(dllimport)
#  endif
#elif __GNUC__ >= 4 || defined(__clang__)
#  define _export __attribute__((visibility ("default")))
#else
#  define _export
#endif
