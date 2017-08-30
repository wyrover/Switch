/// @file
/// @brief Contains Switch::System::Diagnostics::TraceSource class.
#pragma once

#include "../../Types.hpp"
#include "../Object.hpp"
#include "../String.hpp"
#include "TraceEventType.hpp"
#include "Trace.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides a set of methods and properties that enable applications to trace the execution of code and associate trace messages with their source.
      class pcf_public TraceSource :  public Object {
      public:
        TraceSource() {}

        TraceSource(const String& name) {this->data->name = name;}

        /// @cond
        ~TraceSource() {}
        /// @endcond

        Property<TraceListenerCollection&> Listeners {
          pcf_get->TraceListenerCollection& {return this->data->listeners;},
          pcf_set {this->data->listeners = value;}
        };

        Property<string> Name {
          pcf_get {return this->data->name;},
          pcf_set {this->data->name = value;}
        };

        /// @brief Writes trace data to the trace listeners in the Listeners collection using the specified event type, event identifier, and trace data.
        void TraceData(const TraceEventType& traceEventType, int32 id, const object& data);

        /// @brief Writes trace data to the trace listeners in the Listeners collection using the specified event type, event identifier, and trace data array.
        void TraceData(const TraceEventType& traceEventType, int32 id, const Array<refptr<object>>& data);

        /// @brief Writes a trace event message to the trace listeners in the Listeners collection using the specified event type and event identifier.
        void TraceEvent(const TraceEventType& traceEventType, int32 id);

        /// @brief Writes a trace event message to the trace listeners in the Listeners collection using the specified event type, event identifier, and message.
        void TraceEvent(const TraceEventType& traceEventType, int32 id, const String& message);

        /// @brief Writes an information message to the trace listeners in the Listeners collection using the specified message.
        void TraceInformation(const String& message) {this->TraceEvent(TraceEventType(TraceEventType::Information), 0, message);}

      private:
        struct TraceSourceData {
          TraceListenerCollection listeners;
          String name;
        };
        refptr<TraceSourceData> data {new TraceSourceData()};
      };
    }
  }
}

using namespace Switch;
