/// @file
/// @brief Contains Switch::char16, Switch::int32, ... types.
#pragma once

/// @todo Remove when CMakelists.txt ready
#define PCF_STATIC 1

#if PCF_STATIC
#  define pcf_public
#elif WIN32
#  if PCF_EXPORTS  
#    define pcf_public __declspec(dllexport)   
#  else  
#    define pcf_public __declspec(dllimport)   
#  endif
#elif __GNUC__ >= 4 || defined(__clang__)
#  define pcf_public __attribute__((visibility ("default")))
#else
#  define pcf_public
#endif
