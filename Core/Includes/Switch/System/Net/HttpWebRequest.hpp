/// @file
/// @brief Contains Switch::System::Net::HttpWebRequest class.
#pragma once

#include "WebRequest.hpp"
#include "HttpWebResponse.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      class _public HttpWebRequest: public System::Net::WebRequest {
      public:
        ~HttpWebRequest();

        property<bool> AllowAutoRedirect {
          _get {return this->GetAllowAutoRedirect();},
          _set {this->SetAllowAutoRedirect(value);}
        };

        property<const string&> ContentType {
          _get->const string& {return this->GetContentType();},
          _set {this->SetContentType(value);}
        };
        
        WebResponse& GetResponse() override;
        
        WebRequest::WebRequestStream GetRequestStream() override;
        
      protected:
        HttpWebRequest(const string& uri);
        HttpWebRequest(const System::Uri& uri);
        HttpWebRequest(const HttpWebRequest&) = delete;
        HttpWebRequest& operator =(const HttpWebRequest&) = delete;

        void Finished(int32 error) override;
        WebResponse& GetInternalResponse() override;

        System::Net::HttpWebResponse httpWebResponse;
        bool allowAutoRedirect = true;
        String contentType;
        intptr header = IntPtr::Zero;
        
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

using namespace Switch;
