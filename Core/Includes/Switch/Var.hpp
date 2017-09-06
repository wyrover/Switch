/// @file
/// @brief Contains #_var keyword.
#pragma once

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Variables that are declared at method scope can have an implicit type _var. An implicitly typed local variable is strongly typed just as if you had declared the type yourself, but the compiler determines the type. The following two declarations of i are functionally equivalent:
  /// @par Examples
  /// @code
  /// _var i = 10; // implicitly typed
  /// int i = 10; //explicitly typed
  /// @endcode
  /// @par Examples
  /// The following example show hot to use _var
  /// @include Var.cpp
  /// @ingroup Switch
  #define _var \
  auto
}

using namespace Switch;
