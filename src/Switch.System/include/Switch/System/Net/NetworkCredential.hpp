/// @file
/// @brief Contains Switch::System::Net::NetworkCredential class.
#pragma once

#include <Switch/Types.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Provides credentials for password-based authentication schemes such as basic, digest, NTLM, and Kerberos authentication.
      /// @par Library
      /// Switch.System
      class _export NetworkCredential : public Object {
      public:
        NetworkCredential() {}

        NetworkCredential(const String& userName, const String& password): userName(userName), password(password) {}
        /// @cond
        NetworkCredential(const NetworkCredential& networkCredential) : userName(networkCredential.userName), password(networkCredential.password) {}
        NetworkCredential& operator=(const NetworkCredential& networkCredential) {
          this->userName = networkCredential.userName;
          this->password = networkCredential.password;
          return *this;
        }
        /// @endcond

        _property<const string&> UserName {
          _get->const string& {return this->userName;},
          _set {this->userName = value;}
        };
        
        _property<const string&> Password {
          _get->const string& {return this->password;},
          _set {this->password = value;}
        };

      private:
        String userName;
        String password;
      };
    }
  }
}

using namespace Switch;
