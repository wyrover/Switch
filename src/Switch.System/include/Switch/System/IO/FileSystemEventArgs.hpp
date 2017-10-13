/// @file
/// @brief Contains Switch::System::IO::FileSystemEventArgs class.
#pragma once

#include <Switch/As.hpp>
#include <Switch/System/EventArgs.hpp>
#include "WatcherChangeTypes.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Provides data for the directory events: Changed, Created, Deleted.
      /// @par Library
      /// Switch.System
      class _export FileSystemEventArgs : public EventArgs {
      public:
        FileSystemEventArgs(WatcherChangeTypes changeType, const string directory, const string name) : changeType(changeType), directory(directory), name(name) {}
        
        /// @cond
        FileSystemEventArgs(const FileSystemEventArgs& fsea) : changeType(fsea.changeType), directory(fsea.directory), name(fsea.name) {}
        FileSystemEventArgs& operator=(const FileSystemEventArgs& fsea) {
          this->changeType = fsea.changeType;
          this->directory = fsea.directory;
          this->name = fsea.name;
          return *this;
        }
        /// @endcond
        
        _property<WatcherChangeTypes, _readonly> ChangeType {
          _get {return this->changeType;}
        };
        
        _property<string, _readonly> Directory {
          _get {return this->directory;}
        };
        
        _property<string, _readonly> Name {
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
