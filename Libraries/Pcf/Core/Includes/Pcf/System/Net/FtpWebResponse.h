/// @file
/// @brief Contains Pcf::System::Net::FtpWebResponse class.
#pragma once

#include "FtpStatusCode.h"
#include "WebResponse.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      class pcf_public FtpWebResponse : public System::Net::WebResponse {
      public:
        Property<System::Net::FtpStatusCode, ReadOnly> StatusCode {
          pcf_get {return this->GetStatusCode();}
        };
        
        Property<string, ReadOnly> StatusDescription {
          pcf_get {return this->GetStatusDescription();}
        };
        
        WebResponse::WebResponseStream GetResponseStream() override;

      protected:
        FtpWebResponse();
        
      private:
        friend class FtpWebRequest;

        System::Net::FtpStatusCode GetStatusCode() const;
        const String GetStatusDescription() const;
      };
    }
  }
}

using namespace Pcf;
