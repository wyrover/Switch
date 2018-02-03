/// @file
/// @brief Contains __opaque_lock_guard__ class.
#pragma once

#include "Export.hpp"

/// @cond
namespace Switch {
  namespace System {
    class Object;
  }
}

class export_ __opaque_lock_guard__ final {
public:
  explicit __opaque_lock_guard__(const Switch::System::Object& lock);
  ~__opaque_lock_guard__();

private:
  __opaque_lock_guard__() = delete;
  __opaque_lock_guard__(const __opaque_lock_guard__&) = delete;
  __opaque_lock_guard__& operator=(const __opaque_lock_guard__&) = delete;

  const Switch::System::Object& lock;
};
/// @endcond

