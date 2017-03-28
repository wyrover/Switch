/// @file
/// @brief Contains Pcf::System::Collections::ICollection interface.
#pragma once

#include "../../Any.h"
#include "IEnumerable.h"
#include "Generic/ICollection.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Defines size, enumerators, and synchronization methods for all non-generic collections.
      using ICollection = System::Collections::Generic::ICollection<Any>;
    }
  }
}

using namespace Pcf;
