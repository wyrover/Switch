#include <Switch/Switch>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

namespace Examples {
  class UdpClientListener {
  public:
    // The main entry point for the application.
    static void Main() {
      IPEndPoint waitingEndpoint(IPAddress::Any, 8082);
      UdpClient listener(waitingEndpoint);
      
      Console::WriteLine("Waiting for broadcast. Press Ctrl+C to quit...");
      while (true) {
        Array<byte> receiveBytes(256);
        IPEndPoint incomingInformationEndpoint(0, 0);
        
        try {
          listener.Receive(receiveBytes, incomingInformationEndpoint);
          Console::WriteLine("Received broadcast {0} from {1}", Encoding::UTF8()->GetString(receiveBytes), waitingEndpoint);
        } catch (const Exception& e) {
          Console::WriteLine(e.Message);
        }
      }
    }
  };
}

_startup(Examples::UdpClientListener)

// This code example can produce the following output:
//
// Waiting for broadcast. Press Ctrl+C to quit...
// Received broadcast {"id" : "4915"} from 0.0.0.0:8082
// Received broadcast {"id" : "4916"} from 0.0.0.0:8082
// Received broadcast {"id" : "4917"} from 0.0.0.0:8082
// Received broadcast {"id" : "4918"} from 0.0.0.0:8082
