/// @file
/// @brief Contains Switch::System::Net::WebSockets::WebSocket class.
#pragma once

#include <Switch/Abstract.hpp>
#include <Switch/System/TimeSpan.hpp>
#include "WebSocketCloseStatus.hpp"
#include "WebSocketMessageType.hpp"
#include "WebSocketState.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::WebSockets namespace provides a managed implementation of the WebSocket interface for developers.
      namespace WebSockets {
        /// @brief The WebSocket class allows applications to send and receive data after the WebSocket upgrade has completed.
        /// @par Library
        /// Switch.System
        class _export WebSocket _abstract {
        protected:
          /// @brief Creates an instance of the WebSocket class.
          WebSocket() {}
          
        public:
          /// @brief Indicates the reason why the remote endpoint initiated the close handshake.
          /// @property value Returns WebSocketCloseStatus.
          _property<WebSocketCloseStatus, _readonly> CloseStatus {
            _get {return this->GetCloseStatus();}
          };
          
          /// @brief Allows the remote endpoint to describe the reason why the connection was closed.
          _property<string, _readonly> CloseStatusDescription {
            _get {return this->GetCloseStatusDescription();}
          };
          
          /// @brief Gets the default WebSocket protocol keep-alive interval in milliseconds.
          /// @property The default WebSocket protocol keep-alive interval in milliseconds. The typical value for this interval is 30 seconds.
          static _property<TimeSpan, _readonly> DefaultKeepAliveInterval;
          
          /// @brief Allows the remote endpoint to describe the reason why the connection was closed.
          _property<WebSocketState, _readonly> State {
            _get {return this->GetState();}
          };
          
          /// @brief The subprotocol that was negotiated during the opening handshake.
          _property<string, _readonly> SubProtocol {
            _get {return this->GetSubProtocol();}
          };
          
          /// @brief Aborts the WebSocket connection and cancels any pending IO operations.
          virtual void Abort() = 0;
          
        protected:
          /// @brief Indicates the reason why the remote endpoint initiated the close handshake.
          /// @return WebSocketCloseStatus.
          virtual WebSocketCloseStatus GetCloseStatus() const = 0;
          
          /// @brief Allows the remote endpoint to describe the reason why the connection was closed.
          /// @return The remote endpoint to describe the reason why the connection was closed.
          virtual string GetCloseStatusDescription() const = 0;
          
          /// @brief Gets the default WebSocket protocol keep-alive interval in milliseconds.
          /// @return the current state of the WebSocket connection.
          virtual WebSocketState GetState() const = 0;

          /// @brief The subprotocol that was negotiated during the opening handshake.
          virtual string GetSubProtocol() const = 0;
        };
      }
    }
  }
}

using namespace Switch;
