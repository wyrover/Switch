/// @file
/// @brief Contains Switch::System::Diagnostics::Process class.
#pragma once

#include "../../Property.hpp"
#include "../../Types.hpp"
#include "../Object.hpp"
#include "../ObjectClosedException.hpp"
#include "../String.hpp"
#include "../IO/StreamReader.hpp"
#include "ProcessStartInfo.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides access to local and remote processes and enables you to start and stop local system processes.
      class _export Process : public Object {
        refptr<IO::Stream> GetStandardOutput() const;
      public:
        /// @cond
        Process() {}
        Process(const Process& process) : data(process.data) {}
        Process& operator=(const Process& process) {this->data = process.data; return *this;}
        virtual ~Process();
        /// @endcond
        
        _property<int32, _readonly> ExitCode {
          _get {return this->data->exitCode;}
        };
        
        _property<int32, _readonly> Id {
          _get {return *((int32*)&this->data->handle);}
        };
        
        _property<string, _readonly> ProcessName {
          _get {return this->GetName();}
        };
        
        _property<string, _readonly> Path {
          _get {return this->GetPath();}
        };
        
        _property<ProcessStartInfo&> StartInfo {
          _get->ProcessStartInfo& {return this->data->startInfo;},
          _set {this->data->startInfo = value;}
        };
        
        _property<System::IO::StreamReader, _readonly> StandardOutput {
          _get {return this->GetStreamReader();}
        };
        
        void Close();
        
        void Kill();
        
        static Process GetCurrentProcess();
        
        static Array<Process> GetProcesses();
        
        static Process Start(const String& fileName);
        
        static Process Start(const String& fileName, const String& argument);
        
        static Process Start(const ProcessStartInfo& startInfo);
        
        String ToString() const override {return string::Format("{0} ({1})", this->GetType(), this->ProcessName);};
        
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
        refptr<ProcessData> data = ref_new<ProcessData>();
      };
    }
  }
}

using namespace Switch;
