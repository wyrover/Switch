/// @file
/// @brief Contains Pcf::System::Net::FtpWebRequest class.
#pragma once

#include "../TimeoutException.h"
#include "WebRequest.h"
#include "FtpWebResponse.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      class pcf_public FtpWebRequest: public System::Net::WebRequest {
      public:
        Property<bool> UseBinary {
          pcf_get {return this->GetUseBinary();},
          pcf_set {this->SetUseBinary(value);}
        };
        
        WebResponse& GetResponse() override;

        WebRequest::WebRequestStream GetRequestStream() override;
        
      protected:
        FtpWebRequest(const string& uri);
        FtpWebRequest(const System::Uri& uri);
        FtpWebRequest(const FtpWebRequest& ftpWebRequest) = delete;
        FtpWebRequest operator =(const FtpWebRequest& ftpWebRequest) = delete;

        WebResponse& GetInternalResponse() override;
        void Finished(int32 error) override;

        System::Net::FtpWebResponse ftpWebResponse;

      private:
        friend class System::Net::WebRequest;
        friend class System::Net::FtpWebResponse;
        
        bool GetUseBinary();
        void SetUseBinary(bool useBinary);

        bool useBinary = false;

        void ProcessMakeDirectory();
        void ProcessListDirectory();
        void ProcessListDirectoryDetails();
      };
    }
  }
}

using namespace Pcf;
