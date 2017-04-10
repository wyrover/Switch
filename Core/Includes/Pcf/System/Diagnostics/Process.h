/// @file
/// @brief Contains Pcf::System::Diagnostics::Process class.
#pragma once

#include "../../Property.h"
#include "../../Types.h"
#include "../../UniquePointer.h"
#include "../Object.h"
#include "../ObjectClosedException.h"
#include "../String.h"
#include "../IO/StreamReader.h"
#include "ProcessStartInfo.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides access to local and remote processes and enables you to start and stop local system processes.
      class pcf_public Process : public Object {
        refptr<IO::Stream> GetStandardOutput() const;
      public:
        /// @cond
        Process() {}
        Process(const Process& process) : data(process.data) {}
        Process& operator=(const Process& process) {this->data = process.data; return *this;}
        virtual ~Process();
        /// @endcond
        
        Property<int32, ReadOnly> ExitCode {
          pcf_get {return this->data->exitCode;}
        };
        
        Property<int32, ReadOnly> Id {
          pcf_get {return *((int32*)&this->data->handle);}
        };
        
        Property<string, ReadOnly> ProcessName {
          pcf_get {return this->GetName();}
        };
        
        Property<string, ReadOnly> Path {
          pcf_get {return this->GetPath();}
        };
        
        Property<ProcessStartInfo&> StartInfo {
          pcf_get->ProcessStartInfo& {return this->data->startInfo;},
          pcf_set {this->data->startInfo = value;}
        };
        
        Property<System::IO::StreamReader, ReadOnly> StandardOutput {
          pcf_get {return this->GetStreamReader();}
        };
        
        void Close();
        
        void Kill();
        
        static Process GetCurrentProcess();
        
        static Array<Process> GetProcesses();
        
        static Process Start(const String& fileName);
        
        static Process Start(const String& fileName, const String& argument);
        
        static Process Start(const ProcessStartInfo& startInfo);
        
        String ToString() const noexcept override {return string::Format("{0} ({1})", this->GetType(), this->ProcessName);};
        
        void WaitForExit();
        
      private:
        Process(intptr handle) {this->data->handle = handle;}
        int32 GetId();
        string GetName();
        string GetPath();
        System::IO::StreamReader GetStreamReader();
        
        struct ProcessData {
          int32 exitCode = 0;
          intptr handle = 0;
          refptr<System::IO::Stream> outputStream;
          ProcessStartInfo startInfo;
        };
        refptr<ProcessData> data = refptr<ProcessData>::Create();
      };
    }
  }
}

using namespace Pcf;
