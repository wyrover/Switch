/// @file
/// @brief Contains Pcf::System::Net::NetworkCredential class.
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
      class NetworkCredential : public Object {
      public:
        NetworkCredential() {}

        NetworkCredential(const String& userName, const String& password): userName(userName), password(password) {}
        /// @cond
        NetworkCredential(const NetworkCredential& networkCredential) : userName(networkCredential.userName), password(networkCredential.password) {}
        NetworkCredential& operator =(const NetworkCredential& networkCredential) {
          this->userName = networkCredential.userName;
          this->password = networkCredential.password;
          return *this;
        }
        /// @endcond

        Property<const string&> UserName {
          pcf_get->const string& {return this->userName;},
          pcf_set {this->userName = value;}
        };
        
        Property<const string&> Password {
          pcf_get->const string& {return this->password;},
          pcf_set {this->password = value;}
        };

      private:
        String userName;
        String password;
      };
    }
  }
}

using namespace Pcf;
