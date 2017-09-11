/// @file
/// @brief Contains Switch::System::IO::FileSystemEventArgs class.
#pragma once

#include "../../As.hpp"
#include "../EventArgs.hpp"
#include "WatcherChangeTypes.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      class _export FileSystemEventArgs : public EventArgs {
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
        
        property<WatcherChangeTypes, readonly> ChangeType {
          _get {return this->changeType;}
        };
        
        property<string, readonly> Directory {
          _get {return this->directory;}
        };
        
        property<string, readonly> Name {
          _get {return this->name;}
        };
        
      private:
        WatcherChangeTypes changeType;
        string directory;
        string name;
      };
    }
  }
}
