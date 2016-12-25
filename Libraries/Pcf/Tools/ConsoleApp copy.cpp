#include <easywsclient.hpp>
#include <Pcf/Pcf>

using namespace System;

namespace Pcf {
  namespace System {
    template<typename T>
    using ArraySegment=Array<T, 1>;
    
    namespace Net {
      namespace WebSockets {
        /// @brief Represents well known WebSocket close codes as defined in section 11.7 of the WebSocket protocol spec.
        enum class WebSocketCloseStatus {
          /// @brief No error specified.
          Empty = 0,
          /// @brief The connection will be closed by the server because of an error on the server.
          InternalServerError,
          /// @brief (1000) The connection has closed after the request was fulfilled.
          NormalClosure = 1000,
          /// @brief (1001) Indicates an endpoint is being removed. Either the server or client will become unavailable.
          EndpointUnavailable = 1001,
          /// @brief (1002) The client or server is terminating the connection because of a protocol error.
          ProtocolError = 1002,
          /// @brief (1003) The client or server is terminating the connection because it cannot accept the data type it received.
          InvalidMessageType = 1003,
          /// @brief (1004) Reserved for future use.
          MessageTooBig = 1004,
          /// @brief (1007) The client or server is terminating the connection because it has received data inconsistent with the message type.
          InvalidPayloadData = 1007,
          /// @brief (1008) The connection will be closed because an endpoint has received a message that violates its policy.
          PolicyViolation = 1008,
          /// @brief (1010) The client is terminating the connection because it expected the server to negotiate an extension.
          MandatoryExtension = 1010
        };
        
        /// @brief ndicates the message type.
        enum class WebSocketMessageType {
          /// @brief The message is clear text.
          Text,
          /// @brief The message is in binary format.
          Binary,
          /// @brief A receive has completed because a close message was received.
          Closed
        };
        
        /// @brief Defines the different states a WebSockets instance can be in.
        enum class WebSocketState {
          /// @brief Reserved for future use.
          None,
          /// @brief The connection is negotiating the handshake with the remote endpoint.
          Connecting,
          /// @brief The initial state after the HTTP handshake has been completed.
          Open,
          /// @brief A close message was sent to the remote endpoint.
          CloseSent,
          /// @brief A close message was received from the remote endpoint.
          CloseReceive,
          /// @brief Indicates the WebSocket close handshake completed gracefully.
          Closed,
          /// @brief Reserved for future use.
          Aborted
        };
        
        /// @brief The WebSocket class allows applications to send and receive data after the WebSocket upgrade has completed.
        class WebSocket : public Abstract {
        protected:
          /// @brief Creates an instance of the WebSocket class.
          WebSocket() {}
          
        public:
          /// @brief Indicates the reason why the remote endpoint initiated the close handshake.
          /// @property value Returns WebSocketCloseStatus.
          Property<WebSocketCloseStatus, PublicGetterAttribute> CloseStatus {
            [&]() {return this->GetCloseStatus();}
          };
          
          /// @brief Allows the remote endpoint to describe the reason why the connection was closed.
          Property<string, PublicGetterAttribute> CloseStatusDescription {
            [&]() {return this->GetCloseStatusDescription();}
          };
          
          /// @brief Gets the default WebSocket protocol keep-alive interval in milliseconds.
          /// @property The default WebSocket protocol keep-alive interval in milliseconds. The typical value for this interval is 30 seconds.
          static Property<TimeSpan, PublicGetterAttribute> DefaultKeepAliveInterval;
          
          /// @brief Allows the remote endpoint to describe the reason why the connection was closed.
          Property<WebSocketState, PublicGetterAttribute> State {
            [&]() {return this->GetState();}
          };
          
          /// @brief The subprotocol that was negotiated during the opening handshake.
          Property<string, PublicGetterAttribute> SubProtocol {
            [&]() {return this->GetSubProtocol();}
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
        
        /// @brief Provides a client for connecting to WebSocket services.
        class ClientWebSocket : public WebSocket {
        public:
          /// @brief Creates an instance of the ClientWebSocket class.
          ClientWebSocket() {}
          
          ~ClientWebSocket() {
            this->Close(System::Net::WebSockets::WebSocketCloseStatus::NormalClosure);
          }
          
          /// @brief Aborts the WebSocket connection and cancels any pending IO operations.
          void Abort() override {throw NotSupportedException(pcf_current_information);}
          
          void Connect(const string& uri) {
            this->socket = easywsclient::WebSocket::from_url("ws://localhost:8126/foo");
            if (this->socket.IsNull())
              throw InvalidOperationException(pcf_current_information);
            
            //this->socket->poll(DefaultKeepAliveInterval().TotalMilliseconds);
          }
          
          void Close(WebSocketCloseStatus closeStatus) {
            if (!this->socket.IsNull()) {
              this->closeStatus = closeStatus;
              this->socket->close();
            }
          }
          
          ArraySegment<byte> Receive() {
            if (this->socket.IsNull())
              throw InvalidOperationException(pcf_current_information);
            
            string buffer;
            while (buffer.IsEmpty()) {
              this->socket->poll();
              this->socket->dispatch([&](const std::string & message) {
                buffer = message;
              });
            }
            return ArraySegment<byte>(reinterpret_cast<const byte*>(buffer.Data()), buffer.Length);
          }
          
          void Send(const ArraySegment<byte>& buffer, WebSocketMessageType messageType, bool endOfMessage) {
            if (this->socket.IsNull())
              throw InvalidOperationException(pcf_current_information);
            
            switch (messageType) {
              case WebSocketMessageType::Text: this->socket->send(std::string(reinterpret_cast<const char*>(buffer.Data()), buffer.Length)); break;
              case WebSocketMessageType::Binary: this->socket->sendBinary(std::vector<byte>(buffer.Data(), buffer.Data() + buffer.Length)); break;
              default: throw InvalidOperationException(pcf_current_information);
            }
          }
          
        protected:
          WebSocketCloseStatus GetCloseStatus() const override {return this->closeStatus;}
          
          string GetCloseStatusDescription() const override {
            switch (this->closeStatus) {
              case WebSocketCloseStatus::Empty: return "No error specified.";
              case WebSocketCloseStatus::InternalServerError: return "The connection will be closed by the server because of an error on the server.";
              case WebSocketCloseStatus::NormalClosure: return "(1000) The connection has closed after the request was fulfilled.";
              case WebSocketCloseStatus::EndpointUnavailable: return "(1001) Indicates an endpoint is being removed. Either the server or client will become unavailable.";
              case WebSocketCloseStatus::ProtocolError: return "(1002) The client or server is terminating the connection because of a protocol error.";
              case WebSocketCloseStatus::InvalidMessageType: return "(1003) The client or server is terminating the connection because it cannot accept the data type it received.";
              case WebSocketCloseStatus::MessageTooBig: return "(1004) Reserved for future use.";
              case WebSocketCloseStatus::InvalidPayloadData: return "(1007) The client or server is terminating the connection because it has received data inconsistent with the message type.";
              case WebSocketCloseStatus::PolicyViolation: return "(1008) The connection will be closed because an endpoint has received a message that violates its policy.";
              case WebSocketCloseStatus::MandatoryExtension: return "(1010) The client is terminating the connection because it expected the server to negotiate an extension.";
              default : throw InvalidOperationException(pcf_current_information);
            }
          }
          
          WebSocketState GetState() const override {
            if (this->socket.IsNull())
              return WebSocketState::None;
            switch(this->socket->getReadyState()) {
              case easywsclient::WebSocket::CLOSING: return WebSocketState::Closed;
              case easywsclient::WebSocket::CLOSED: return WebSocketState::Closed;
              case easywsclient::WebSocket::CONNECTING: return WebSocketState::Connecting;
              case easywsclient::WebSocket::OPEN: return WebSocketState::Open;
            }
            return WebSocketState::None;
          }

          string GetSubProtocol() const override {return this->subProtocol;}

        private:
          ClientWebSocket(const ClientWebSocket&) = delete;
          ClientWebSocket& operator =(const ClientWebSocket&) = delete;

          WebSocketCloseStatus closeStatus = WebSocketCloseStatus::Empty;
          string subProtocol;
          Up<easywsclient::WebSocket> socket;
        };
      }
    }
  }
}

Property<TimeSpan, PublicGetterAttribute> System::Net::WebSockets::WebSocket::DefaultKeepAliveInterval {
  []() {return TimeSpan(30 * TimeSpan::TicksPerSecond);}
};

using namespace easywsclient;

namespace PcfConsoleApp {
  class Program {
  public:
    /// @brief The main entry point for the application.
    static void Main() {
      //std::cout << "Hello, World!" << std::endl;
      
      System::Net::WebSockets::ClientWebSocket clientWebSocket;
      clientWebSocket.Connect("ws://localhost:8126/foo");
      System::Threading::Thread thread(System::Threading::ThreadStart(delegate {
        string message;
        do {
          message = System::Text::Encoding::UTF8()->GetString(clientWebSocket.Receive());
          Console::WriteLine(">>> {0}", message);
        } while (message != "world");
      }));
      thread.Start();
      
      clientWebSocket.Send(*System::Text::Encoding::UTF8()->GetBytes(string("goodbye")), System::Net::WebSockets::WebSocketMessageType::Text, true);
      clientWebSocket.Send(*System::Text::Encoding::UTF8()->GetBytes(string("hello")), System::Net::WebSockets::WebSocketMessageType::Text, true);
      thread.Join();
    }
  };
}

startup(&PcfConsoleApp::Program::Main)

