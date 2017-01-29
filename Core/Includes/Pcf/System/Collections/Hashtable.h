/// @file
/// @brief Contains Pcf::System::Collections::Hashtable class.
#pragma once

#include "../../Any.h"
#include "Generic/Dictionary.h"
#include "DictionaryEntry.h"
#include "IDictionary.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Represents a collection of key/value pairs that are organized based on the hash code of the key.
      using Hashtable = System::Collections::Generic::Dictionary<Any, Any>;
    }
  }
}

using namespace Pcf;
