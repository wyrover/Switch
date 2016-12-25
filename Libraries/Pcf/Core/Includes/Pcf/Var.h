/// @file
/// @brief Contains #pcf_var keyword.
#pragma once

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief Variables that are declared at method scope can have an implicit type pcf_var. An implicitly typed local variable is strongly typed just as if you had declared the type yourself, but the compiler determines the type. The following two declarations of i are functionally equivalent:
  /// @code
  /// pcf_var i = 10; // implicitly typed
  /// int i = 10; //explicitly typed
  /// @endcode
  /// @section sectionExample Example
  /// The following example show hot to use pcf_var
  /// @include Var.cpp
  /// @ingroup Pcf
  #define pcf_var \
  auto
}

using namespace Pcf;
