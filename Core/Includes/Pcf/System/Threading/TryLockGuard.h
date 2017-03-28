/// @file
/// @brief Contains Pcf::System::Threading::TryLockGuard class.
#pragma once

#include "../Object.h"
#include "../TimeSpan.h"
#include "TimeOut.h"
#include "../../Types.h"
#include "../../Using.h"

/// @cond
namespace Pcf {
  namespace System {
    namespace Threading {
      class pcf_public TryLockGuard : public object {
      public:
        explicit TryLockGuard(const object& lock);
        TryLockGuard(const object& lock, int32 timeout);
        TryLockGuard(const object& lock, int64 timeout);
        TryLockGuard(const object& lock, const TimeSpan& timeout);
        ~TryLockGuard();
        
        Property<bool, ReadOnly> Result {
          pcf_get {return this->result;}
        };
        
      private:
        TryLockGuard() = delete;
        TryLockGuard(const TryLockGuard&) = delete;
        TryLockGuard& operator =(const TryLockGuard&) = delete;

        const object& lock;
        bool result = false;
      };
    }
  }
}
/// @endcond

using namespace Pcf;
