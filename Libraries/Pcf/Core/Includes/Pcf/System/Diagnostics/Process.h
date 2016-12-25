/// @file
/// @brief Contains Pcf::System::Diagnostics::Process class.
#pragma once

#include "../../Property.h"
#include "../../Types.h"
#include "../../UniquePointer.h"
#include "../Object.h"
#include "../ObjectClosedException.h"
#include "../String.h"
#include "../IO/Stream.h"
#include "ProcessStartInfo.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides access to local and remote processes and enables you to start and stop local system processes.
      class Process : public Object {
        SharedPointer<IO::Stream> GetStandardOutput() const;
        
      public:
        class ProcessOutputStream : public IO::Stream {
          bool GetCanRead() const override {return true;}
          bool GetCanSeek() const override {return false;}
          bool GetCanWrite() const override {return false;}
          int64 GetLength() const override {return 0;}
          int64 GetPosition() const override {return 0;}
          bool GetIsClosed() const override {return this->isClosed;}
          
        public:
          ProcessOutputStream() {}
          ProcessOutputStream(FILE* stream) : stream(stream), isClosed(stream == null) {}
          
          /// @cond
          ProcessOutputStream(const ProcessOutputStream& pos) : stream(pos.stream), isClosed(pos.isClosed), exitCode(pos.exitCode) {}
          ProcessOutputStream& operator=(const ProcessOutputStream& pos) {
            this->stream = pos.stream;
            this->isClosed = pos.isClosed;
            this->exitCode = pos.exitCode;
            return *this;
          }
          /// @endcond
          
          Property<int32, ReadOnly> ExitCode {
            pcf_get {return this->exitCode;}
          };
          
          void Close() override  {
            this->exitCode = Process::CloseProcess(this->stream);
            this->isClosed = true;
          }
          
          int32 Read(Array<byte>& buffer, int32 offset, int32 count) override {
            if (count < 0 || offset < 0)
              throw ArgumentOutOfRangeException(pcf_current_information);
              if (offset + count > buffer.Length)
                throw ArgumentException(pcf_current_information);
                if (IsClosed())
                  throw ObjectClosedException(pcf_current_information);
                  
                  if (feof(this->stream))
                    return 0;
            
            return static_cast<int32>(fread((char*)&buffer[offset], sizeof(char), count, this->stream));
          }
          
          void Write(const Array<byte>&, int32, int32) override { }
          int64 Seek(int64 , System::IO::SeekOrigin ) override { return 0; };
          
        private:
          FILE* stream;
          bool isClosed;
          int32 exitCode = -1;
        };
        
        /// @cond
        virtual ~Process();
        /// @endcond
        
        static UniquePointer<Process> Start(const String& fileName);
        
        static UniquePointer<Process> Start(const String& fileName, const String& argument);
        
        static UniquePointer<Process> Start(const ProcessStartInfo& startInfo);
        
        Property<int32, ReadOnly> ExitCode {
          pcf_get {return this->outputStream->ExitCode();}
        };
        
        Property<const ProcessOutputStream&, ReadOnly> StandardOutput {
          pcf_get->const ProcessOutputStream& {return *this->outputStream;}
        };
        
        void WaitForExit();
        
      private:
        Process(SharedPointer<ProcessOutputStream> stream) : outputStream(stream) {}
        
        static FILE* OpenProcess(const String& command, const String& mode);
        static int32 CloseProcess(FILE* process);
        
        SharedPointer<ProcessOutputStream> outputStream;
      };
    }
  }
}

using namespace Pcf;
