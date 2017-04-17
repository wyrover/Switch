/// @file
/// @brief Contains Pcf::System::Collections::IDictionary interface.
#pragma once

#include "../../Any.h"
#include "ICollection.h"
#include "Generic/IDictionary.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Represents a nongeneric collection of key/value pairs
      using IDictionary = System::Collections::Generic::IDictionary<Any, Any>;
    }
  }
}

using namespace Pcf;