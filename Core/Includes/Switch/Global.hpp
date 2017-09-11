/// @file
/// @brief Contains Switch::namof kayword.
#pragma once

#include "System/String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The #_global contextual keyword, when it comes before the :: operator, refers to the global namespace, which is the default namespace for any C# program and is otherwise unnamed. For more information, see How to: Use the Global Namespace Alias.
  /// @par Examples
  /// The following example shows how to use the global contextual keyword to specify that the class TestApp is defined in the global namespace:
  /// @code
  /// class TestClass : public _global::TestApp { }
  /// @endcode
  /// @ingroup Keywords
  #define _global
}

using namespace Switch;
