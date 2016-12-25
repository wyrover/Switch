/// @file
/// @brief Contains Pcf::System::Collections::ArrayList class.
#pragma once

#include "../../Any.h"
#include "Generic/List.h"
#include "IList.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Implements the IList interface using an array whose size is dynamically increased as required.
      /// The following code example shows how to create and initialize an ArrayList and how to print out its values.
      /// @include ArrayList.cpp
      using ArrayList = Generic::List<Any>;
    }
  }
}

using namespace Pcf;
