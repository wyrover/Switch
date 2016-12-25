/// @file
/// @brief Contains Pcf::System::Net::WebRequestMethods class.
#pragma once

#include "../../Static.h"
#include "../../Types.h"
#include "../Object.h"
#include "../String.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Container class for WebRequestMethods.Ftp, WebRequestMethods.File, and WebRequestMethods.Http classes. This class cannot be inherited
      class WebRequestMethods pcf_static {
      public:
        class File pcf_static {
        public:
          /// @brief Represents the FILE GET protocol method that is used to retrieve a file from a specified location.
          /// @return string
          static Property<string, ReadOnly> DownloadFile;
          
          /// @brief Represents the FILE PUT protocol method that is used to copy a file to a specified location.
          /// @return string
          static Property<string, ReadOnly> UploadFile;
        };
        
        /// @brief Represents the types of FTP protocol methods that can be used with an FTP request. This class cannot be inherited.
        class Ftp pcf_static {
        public:
          /// @brief
          /// @return string
          static Property<string, ReadOnly> UploadFile;

          /// @brief
          /// @return string
          static Property<string, ReadOnly> DownloadFile;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> ListDirectory;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> ListDirectoryDetails;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> MakeDirectory;
        };

        /// @brief Represents the types of HTTP protocol methods that can be used with an HTTP request.
        class Http pcf_static {
        public:
          /// @brief
          /// @return string
          static Property<string, ReadOnly> Get;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> Head;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> Post;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> Put;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> Delete;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> Trace;
          
          /// @brief
          /// @return string
          static Property<string, ReadOnly> Options;
        };
      };
    }
  }
}

using namespace Pcf;
