/// Prerequisites:
///   1. Install node.js and npm
///   2. npm install ws
/// To run,
///   node ClientWebSocketServer.js

#include <Switch/Switch>

using namespace System;

namespace Examples {
  class ClientWebSocket {
  public:
    /// @brief The main entry point for the application.
    static void Main() {
      // Create ClientWebSocket and connect to the server
      System::Net::WebSockets::ClientWebSocket clientWebSocket;
      clientWebSocket.Connect("ws://localhost:8126/foo");
      
      // Create receiver thread for client web socket
      System::Threading::Thread receiver(System::Threading::ThreadStart(sw_delegate {
        string message;
        do {
          /// Client web socket receive
          ArraySegment<byte> bytes = clientWebSocket.Receive();
          
          /// Convert UTF8 bytes to string
          message = System::Text::Encoding::UTF8()->GetString(bytes);
          
          Console::WriteLine(">>> {0}", message);
        } while (message != "world");
      }));
      receiver.Start();
      
      // Sending "goodbye" string on ClientWebSocket
      Array<byte> bytes = System::Text::Encoding::UTF8()->GetBytes(string("goodbye"));
      clientWebSocket.Send(bytes, System::Net::WebSockets::WebSocketMessageType::Text, true);
      
      // Sending "hello" string on ClientWebSocket
      bytes = System::Text::Encoding::UTF8()->GetBytes(string("hello"));
      clientWebSocket.Send(bytes, System::Net::WebSockets::WebSocketMessageType::Text, true);
      
      // Wait receiver thread
      receiver.Join();
    }
  };
}

sw_startup (Examples::ClientWebSocket)
