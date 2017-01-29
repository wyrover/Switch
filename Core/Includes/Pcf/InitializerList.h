/// @file
/// @brief Contains Pcf::InitializerList <T> class.
#pragma once

#include <initializer_list>

namespace Pcf {
  template<typename T>
  using InitializerList = std::initializer_list<T>;
}

using namespace Pcf;
