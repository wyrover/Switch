/// @file
/// @brief Contains Switch::char16, Switch::int32, ... types.
#pragma once

/// @todo Remove when CMakelists.txt ready
#define PCF_STATIC 1

#if PCF_STATIC
#  define sw_public
#elif WIN32
#  if PCF_EXPORTS  
#    define sw_public __declspec(dllexport)   
#  else  
#    define sw_public __declspec(dllimport)   
#  endif
#elif __GNUC__ >= 4 || defined(__clang__)
#  define sw_public __attribute__((visibility ("default")))
#else
#  define sw_public
#endif
