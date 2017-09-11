/// @file
/// @brief Contains Switch::System::Net::HttpWebResponse class.
#pragma once

#include "HttpStatusCode.hpp"
#include "WebResponse.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      class _export HttpWebResponse : public System::Net::WebResponse {
      public:
        virtual ~HttpWebResponse();

        property<System::Net::HttpStatusCode, readonly> StatusCode {
          _get {return this->GetStatusCode();}
        };
        
        property<string, readonly> StatusDescription {
          _get {return this->GetStatusDescription();}
        };
        
        WebResponse::WebResponseStream GetResponseStream() override;
        
      protected:
        HttpWebResponse();
        
      private:
        friend class HttpWebRequest;

        System::Net::HttpStatusCode GetStatusCode() const;
        const String GetStatusDescription() const;
      };
    }
  }
}

using namespace Switch;
