/// @file
/// @brief Contains Pcf::System::Threading::Timeout class.
#pragma once

#include "../../Property.h"
#include "../../Static.h"
#include "../../Types.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Contains a constant used to specify an infinite amount of time. This class cannot be inherited.
      class Timeout pcf_static {
      public:
        /// @brief A constant used to specify an infinite waiting period. This field is constant.
        /// @remarks The value of this constant is -1. For threading methods that accept a timeout parameter, such as Thread::Sleep(int32) and Thread::Join(int32), this value is used to suppress timeout behavior.
        static Property<int32, ReadOnly> Infinite;
      };
    }
  }
}

using namespace Pcf;
