/// @file
/// @brief Contains Switch::System::Collections::Queue class.
#pragma once

#include "../../Any.hpp"
#include "Generic/Queue.hpp"
#include "IList.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Represents a first-in, first-out collection of objects.
      using Queue = Generic::Queue<Any>;
    }
  }
}

using namespace Switch;
