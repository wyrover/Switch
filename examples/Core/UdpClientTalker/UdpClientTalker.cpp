#include <Switch/Switch>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;

namespace Examples {
  class UdpClientTalker {
  public:
    // The main entry point for the application.
    static void Main() {
      IPEndPoint sendingEndPoint(IPAddress::Loopback, 8082);
      UdpClient talker;
      
      Console::WriteLine("Press Ctrl+C to quit...");
      int count = Random().Next(1, 20000);
      while (true) {
        string textToSend = string::Format("{{\"id\": \"{0}\"}}", count++);
        
        try {
          Console::WriteLine("Sending broadcast {0} to {1}", textToSend, sendingEndPoint);
          talker.Send(Encoding::UTF8()->GetBytes(textToSend), sendingEndPoint);
          Thread::Sleep(250);
        } catch (const Exception& e) {
          Console::WriteLine(e.Message);
        }
      }
    }
  };
}

_startup (Examples::UdpClientTalker)

// This code example can produce the following output:
//
// Press Ctrl+C to quit...
// Sending broadcast {"id": "4915"} to 127.0.0.1:8082
// Sending broadcast {"id": "4916"} to 127.0.0.1:8082
// Sending broadcast {"id": "4917"} to 127.0.0.1:8082
// Sending broadcast {"id": "4918"} to 127.0.0.1:8082
