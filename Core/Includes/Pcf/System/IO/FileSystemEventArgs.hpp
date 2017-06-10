/// @file
/// @brief Contains Pcf::System::IO::FileSystemEventArgs class.
#pragma once

#include "../../As.hpp"
#include "../EventArgs.hpp"
#include "WatcherChangeTypes.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      class pcf_public FileSystemEventArgs : public EventArgs {
      public:
        FileSystemEventArgs(WatcherChangeTypes changeType, const string directory, const string name) : changeType(changeType), directory(directory), name(name) {}
        
        /// @cond
        FileSystemEventArgs(const FileSystemEventArgs& fsea) : changeType(fsea.changeType), directory(fsea.directory), name(fsea.name) {}
        FileSystemEventArgs& operator =(const FileSystemEventArgs& fsea) {
          this->changeType = fsea.changeType;
          this->directory = fsea.directory;
          this->name = fsea.name;
          return *this;
        }
        /// @endcond
        
        Property<WatcherChangeTypes, ReadOnly> ChangeType {
          pcf_get {return this->changeType;}
        };
        
        Property<string, ReadOnly> Directory {
          pcf_get {return this->directory;}
        };
        
        Property<string, ReadOnly> Name {
          pcf_get {return this->name;}
        };
        
      private:
        WatcherChangeTypes changeType;
        string directory;
        string name;
      };
    }
  }
}
