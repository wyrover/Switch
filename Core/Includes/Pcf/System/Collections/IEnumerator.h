/// @file
/// @brief Contains Pcf::System::Collections::IEnumerator interface.
#pragma once

#include "../../Any.h"
#include "Generic/IEnumerator.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Supports a simple iteration over a non-generic collection.
      using IEnumerator = System::Collections::Generic::IEnumerator<Any>;

      using Enumerator = System::Collections::Generic::Enumerator<Any>;
    }
  }
}

using namespace Pcf;
