/// @file
/// @brief Contains Switch::System::Diagnostics::TraceOptions enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Specifies trace data options to be written to the trace output.
      /// @remarks This enumeration is used by trace listeners to determine which options, or elements, should be included in the trace output. Trace listeners store the trace options in the TraceOutputOptions property.
      enum class TraceOptions {
        /// @brief Do not write any elements.
        None = 0,
        /// @brief Write the logical operation stack, which is represented by the return value of the CorrelationManager.LogicalOperationStack property.
        LogicalOperationStack = 0b1,
        /// @brief Write the date and time.
        DateTime = 0b10,
        /// @brief Write the timestamp, which is represented by the return value of the GetTimestamp method.
        Timestamp = 0b100,
        /// @brief Write the process identity, which is represented by the return value of the Process.Id property.
        ProcessId = 0b1000,
        /// @brief Write the thread identity, which is represented by the return value of the Thread.ManagedThreadId property for the current thread.
        ThreadId = 0b10000,
        /// @brief Write the call stack, which is represented by the return value of the Environment.StackTrace property.
        Callstack = 0b100000
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Diagnostics::TraceOptions> : public TrueType {};

template<>
class EnumToStrings<System::Diagnostics::TraceOptions> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Diagnostics::TraceOptions::None, "None"}, {(int64)System::Diagnostics::TraceOptions::LogicalOperationStack, "LogicalOperationStack"}, {(int64)System::Diagnostics::TraceOptions::DateTime, "DateTime"}, {(int64)System::Diagnostics::TraceOptions::Timestamp, "Timestamp"}, {(int64)System::Diagnostics::TraceOptions::ProcessId, "ProcessId"}, {(int64)System::Diagnostics::TraceOptions::ThreadId, "ThreadId"}, {(int64)System::Diagnostics::TraceOptions::Callstack, "Callstack"}};
    flags = true;
  }
};
/// @endcond

using namespace Switch;
