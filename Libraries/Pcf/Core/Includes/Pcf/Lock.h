/// @file
/// @brief Contains #pcf_lock keyword.
#pragma once

#include "System/Threading/LockGuard.h"

namespace Pcf {
  /// @brief The pcf_lock keyword can be used to ensure that a block of code runs to completion without interruption by other threads.
  /// This is accomplished by obtaining a mutual-exclusion lock for a given object for the duration of the code block.
  /// @param object The object on which to acquire the lock.
  /// @see System::Threading::Monitor
  /// The following code example shows how to use lock keyword.
  /// @include ArrayGetSyncRoot.cpp
  /// @ingroup Pcf
  #define pcf_lock(object)\
  pcf_using (System::Threading::LockGuard __pcf_lock_guard__(object))
}

using namespace Pcf;
