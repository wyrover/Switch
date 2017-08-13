/// @file
/// @brief Contains Pcf::Move <> operator.
#pragma once

#include <utility>
#include "Allocator.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief Represent an interface class.
  template< class T >
  inline constexpr typename std::remove_reference<T>::type&& Move(T&& t) {return std::move(t);}
}

using namespace Pcf;
