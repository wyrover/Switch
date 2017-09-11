#include <Switch/Switch>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;

namespace Examples {
  class UdpClientExample {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Press Ctrl+C to quit...");
      Thread server(ThreadStart(_delegate {
        UdpClient udpClient(IPEndPoint(IPAddress::Any, 8082));
        while (true) {
          Array<byte> receiveBytes(256);
          IPEndPoint incomingInformationEndpoint;
          udpClient.Receive(receiveBytes, incomingInformationEndpoint);
          Console::WriteLine(Encoding::UTF8()->GetString(receiveBytes));
        }
      }));
      server.Start();
      
      Thread client(ThreadStart(_delegate {
        UdpClient udpClient;
        int counter = Random().Next(1, 20000);
        while (true) {
          udpClient.Send(Encoding::UTF8()->GetBytes(string::Format("Counter={0}", counter++)), "127.0.0.1", 8082);
          Thread::Sleep(250);
        }
      }));
      client.Start();
      
      server.Join();
      client.Join();
    }
  };
}

_startup (Examples::UdpClientExample)

// This code example can produce the following output:
//
// Counter=13975
// Counter=13976
// Counter=13977
// Counter=13978
// ...
