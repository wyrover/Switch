/// @file
/// @brief Contains Pcf::System::Diagnostics::TraceEventType class.
#pragma once

#include "../Enum.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Identifies the type of event that has caused the trace.
      /// @see Trace
      enum class TraceEventType {
        /// @brief Fatal error or application crash.
        Critical,
        /// @brief Recoverable error.
        Error,
        /// @brief Informational message.
        Information,
        /// @brief Resumption of a logical operation.
        Resume,
        /// @brief Starting of a logical operation.
        Start,
        /// @brief Stopping of a logical operation.
        Stop,
        /// @brief Suspension of a logical operation.
        Suspend,
        /// @brief Changing of correlation identity.
        Transfer,
        /// @brief Debugging trace.
        Verbose,
        /// @brief Warning Noncritical problem.
        Warning
      };
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Diagnostics::TraceEventType> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Diagnostics::TraceEventType::Critical, "Critical"}, {(int64)System::Diagnostics::TraceEventType::Error, "Error"}, {(int64)System::Diagnostics::TraceEventType::Information, "Information"}, {(int64)System::Diagnostics::TraceEventType::Resume, "Resume"}, {(int64)System::Diagnostics::TraceEventType::Start, "Start"}, {(int64)System::Diagnostics::TraceEventType::Stop, "Stop"}, {(int64)System::Diagnostics::TraceEventType::Suspend, "Suspend"}, {(int64)System::Diagnostics::TraceEventType::Transfer, "Transfer"}, {(int64)System::Diagnostics::TraceEventType::Verbose, "Verbose"}, {(int64)System::Diagnostics::TraceEventType::Warning, "Warning"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
