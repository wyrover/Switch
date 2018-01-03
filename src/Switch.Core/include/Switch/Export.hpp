/// @file
/// @brief Contains export_ keyword.
#pragma once

/// @todo Remove when CMakelists.txt ready
#define SWITCH_STATIC 1

#if SWITCH_STATIC
#  define export_
#elif WIN32
#  if SWITCH_EXPORTS
#    define export_ __declspec(dllexport)
#  else
#    define export_ __declspec(dllimport)
#  endif
#elif __GNUC__ >= 4 || defined(__clang__)
#  define export_ __attribute__((visibility ("default")))
#else
#  define export_
#endif
