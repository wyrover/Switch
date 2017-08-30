/// @file
/// @brief Contains #pcf_using keyword.
#pragma once

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The specified expression is cleared automaticaly when the scope is ended.
  /// @par Examples
  /// @code
  /// // sr is released automatically after the end cosure }.
  /// pcf_using(refptr<StreamReader> sr = pcf_new<StreamReader>(path)) {
  ///   Console::WriteLine(sr->ReadToEnd());
  /// }
  /// @endcode
  /// @ingroup Switch
  #define pcf_using(expression)\
  for (bool __pcf_using__ = true; __pcf_using__; __pcf_using__ = false)\
    for (expression; __pcf_using__; __pcf_using__ = false)
}

using namespace Switch;
