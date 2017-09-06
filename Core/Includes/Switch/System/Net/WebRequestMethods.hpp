/// @file
/// @brief Contains Switch::System::Net::WebRequestMethods class.
#pragma once

#include "../../Static.hpp"
#include "../../Types.hpp"
#include "../Object.hpp"
#include "../String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Container class for WebRequestMethods.Ftp, WebRequestMethods.File, and WebRequestMethods.Http classes. This class cannot be inherited
      class _public WebRequestMethods _static {
      public:
        class File _static {
        public:
          /// @brief Represents the FILE GET protocol method that is used to retrieve a file from a specified location.
          /// @return string
          static property<string, readonly> DownloadFile;
          
          /// @brief Represents the FILE PUT protocol method that is used to copy a file to a specified location.
          /// @return string
          static property<string, readonly> UploadFile;
        };
        
        /// @brief Represents the types of FTP protocol methods that can be used with an FTP request. This class cannot be inherited.
        class Ftp _static {
        public:
          /// @brief
          /// @return string
          static property<string, readonly> UploadFile;

          /// @brief
          /// @return string
          static property<string, readonly> DownloadFile;
          
          /// @brief
          /// @return string
          static property<string, readonly> ListDirectory;
          
          /// @brief
          /// @return string
          static property<string, readonly> ListDirectoryDetails;
          
          /// @brief
          /// @return string
          static property<string, readonly> MakeDirectory;
        };

        /// @brief Represents the types of HTTP protocol methods that can be used with an HTTP request.
        class Http _static {
        public:
          /// @brief
          /// @return string
          static property<string, readonly> Get;
          
          /// @brief
          /// @return string
          static property<string, readonly> Head;
          
          /// @brief
          /// @return string
          static property<string, readonly> Post;
          
          /// @brief
          /// @return string
          static property<string, readonly> Put;
          
          /// @brief
          /// @return string
          static property<string, readonly> Delete;
          
          /// @brief
          /// @return string
          static property<string, readonly> Trace;
          
          /// @brief
          /// @return string
          static property<string, readonly> Options;
        };
      };
    }
  }
}

using namespace Switch;
