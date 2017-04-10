/// @file
/// @brief Contains Pcf::System::Diagnostics::DefaultTraceListener class.
#pragma once

#include "../../Property.h"
#include "../../Types.h"
#include "../IO/StreamWriter.h"
#include "TraceListener.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides the default output methods and behavior for tracing.
      class pcf_public DefaultTraceListener : public TraceListener {
      public:
        DefaultTraceListener() {}
        
        /// @cond
        DefaultTraceListener(const DefaultTraceListener& dtl) : data(dtl.data) { }
        DefaultTraceListener& operator =(const DefaultTraceListener& dtl) {this->data = dtl.data; return *this;}
        ~DefaultTraceListener() {this->Flush();}
        /// @endcond

        void Flush() override {
          if (!this->data->messageLine.IsEmpty())
            this->WriteLine("");
          if (this->data->logWriter != null)
            this->data->logWriter->Flush();
         }
        
        /// @brief When overridden in a derived class, writes the specified msg to the listener you create in the derived class.
        void Write(const String& message) override {
#if defined(DEBUG) || defined(TRACE)
          if (this->NeedIndent == true)
            this->WriteIndent();
          this->data->messageLine += message;
          if (this->data->logWriter != null)
            this->data->logWriter->Write(message);
#endif
        }
        
        /// @brief When overridden in a derived class, writes a msg to the listener you create in the derived class, followed by a line terminator.
        void WriteLine(const String& message) override {
#if defined(DEBUG) || defined(TRACE)
          if (this->NeedIndent == true)
            this->WriteIndent();
          WriteToOutputDebug(string::Format("{0}{1}{2}", this->data->messageLine, message, Environment::NewLine));
          this->data->messageLine = "";
          if (this->data->logWriter != null)
            this->data->logWriter->WriteLine(message);
          this->NeedIndent = true;
#endif
        }
        
        /// @brief Get or Sets the name of a log file to write trace or debug msgs to.
        Property<String> LogFileName {
          pcf_get {return this->data->logFileName;},
          pcf_set {
            this->data->logFileName = value;
            this->data->logWriter = new System::IO::StreamWriter(this->data->logFileName);
          }
        };

      private:
        void WriteToOutputDebug(const string& message);
        struct DefaultTraceListenerData {
          String logFileName;
          refptr<System::IO::StreamWriter> logWriter;
          string messageLine;
        };
        
        refptr<DefaultTraceListenerData> data {new DefaultTraceListenerData()};
      };
    }
  }
}

using namespace Pcf;
