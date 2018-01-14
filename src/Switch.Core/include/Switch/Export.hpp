/// @file
/// @brief Contains export_ keyword.
#pragma once

#if defined(SWITCH_STATIC_LIBRARIES)
#  define export_
#elif defined(WIN32)
#  if defined(SWITCH_EXPORT)
#    define export_ __declspec(dllexport)
#  else
#    define export_ __declspec(dllimport)
#  endif
#elif __GNUC__ >= 4 || defined(__clang__)
#  if defined(SWITCH_EXPORT)
#    define export_ __attribute__((visibility ("default")))
#  else
#    define export_
#  endif
#else
#  define export_
#endif
