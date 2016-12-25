/// @file
/// @brief Contains #pcf_using keyword.
#pragma once

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The specified expression is cleared automaticaly when the scope is ended.
  /// @code
  /// // sr is released automatically after the end cosure }.
  /// pcf_using(SharedPointer<StreamReader> sr = SharedPointer<StreamReader>::Create(path)) {
  ///   Console::WriteLine(sr->ReadToEnd());
  /// }
  /// @endcode
  /// @ingroup Pcf
  #define pcf_using(expression)\
  for (bool __pcf_using__ = true; __pcf_using__; __pcf_using__ = false)\
    for (expression; __pcf_using__; __pcf_using__ = false)
}

using namespace Pcf;
