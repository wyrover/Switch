/// @file
/// @brief Contains Pcf::System::Net::WebRequestMethods class.
#pragma once

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
      class WebRequestMethods {
      public:
        WebRequestMethods() = delete;

        class Ftp {
        public:
          Ftp() = delete;
          static const String UploadFile;
          static const String DownloadFile;
          static const String ListDirectory;
          static const String ListDirectoryDetails;
          static const String MakeDirectory;

        private:
        };

        class Http : public Object {
        public:
          Http() = delete;
          static const String Get;
          static const String Head;
          static const String Post;
          static const String Put;
          static const String Delete;
          static const String Trace;
          static const String Options;
        };
      };
    }
  }
}

using namespace Pcf;
