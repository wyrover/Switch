/// @file
/// @brief Contains __opaque_lock_guard__ class.
#pragma once

#include "System/Object.hpp"

/// @cond
class export_ __opaque_lock_guard__ : public object {
public:
  explicit __opaque_lock_guard__(const object& lock);
  ~__opaque_lock_guard__();

private:
  __opaque_lock_guard__() = delete;
  __opaque_lock_guard__(const __opaque_lock_guard__&) = delete;
  __opaque_lock_guard__& operator=(const __opaque_lock_guard__&) = delete;

  const object& lock;
};
/// @endcond

