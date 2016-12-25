/// @file
/// @brief Contains Pcf::System::Net::HttpWebRequest class.
#pragma once

#include "WebRequest.h"
#include "HttpWebResponse.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      class HttpWebRequest: public System::Net::WebRequest {
      public:
        ~HttpWebRequest();

        Property<bool> AllowAutoRedirect {
          pcf_get {return this->GetAllowAutoRedirect();},
          pcf_set {this->SetAllowAutoRedirect(value);}
        };

        Property<const string&> ContentType {
          pcf_get->const string& {return this->GetContentType();},
          pcf_set {this->SetContentType(value);}
        };
        
        WebResponse& GetResponse();
        
        SharedPointer<System::IO::Stream> GetRequestStream();
        
      protected:
        HttpWebRequest(const string& uri);
        HttpWebRequest(const System::Uri& uri);
        HttpWebRequest(const HttpWebRequest&) = delete;
        HttpWebRequest& operator =(const HttpWebRequest&) = delete;

        void Finished(int32 error);
        WebResponse& GetInternalResponse();

        System::Net::HttpWebResponse httpWebResponse;
        bool allowAutoRedirect = true;
        String contentType;
        void* header = null;
        
      private:
        friend class System::Net::WebRequest;
        friend class System::Net::HttpWebResponse;
        
        bool GetAllowAutoRedirect() const;
        void SetAllowAutoRedirect(bool autoRedirect);
        const String& GetContentType() const;
        void SetContentType(const String& contentType);
      };
    }
  }
}

using namespace Pcf;
