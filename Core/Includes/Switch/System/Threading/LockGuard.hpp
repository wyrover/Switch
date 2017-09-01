/// @file
/// @brief Contains Switch::System::Threading::LockGuard class.
#pragma once

#include "../Object.hpp"

namespace Switch {
  namespace System {
    namespace Threading {
      /// @cond
      class _public LockGuard : public object {
      public:
        explicit LockGuard(const object& lock);
        ~LockGuard();
        
      private:
        LockGuard() = delete;
        LockGuard(const LockGuard&) = delete;
        LockGuard& operator =(const LockGuard&) = delete;

        const object& lock;
      };
      /// @endcond
    }
  }
}

using namespace Switch;
