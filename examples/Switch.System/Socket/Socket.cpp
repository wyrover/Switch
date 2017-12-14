#include <Switch/Switch>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;

namespace Examples {
  class SocketExample {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Press Ctrl+C to quit...");
      bool terminate = false;
      Thread server(ThreadStart(_delegate {
        Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
        socket.Bind(IPEndPoint(IPAddress::Any, 9050));
        socket.Listen((int)SocketOptionName::MaxConnections);
        Socket socketWithClient = socket.Accept();
        while (!terminate) {
          Array<byte> buffer(256);
          socketWithClient.Receive(buffer);
          Console::WriteLine(Encoding::UTF8()->GetString(buffer));
        }
      }));
      server.Start();

      Thread client(ThreadStart(_delegate {
        Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
        socket.Connect("127.0.0.1", 9050);
        int counter  = Random().Next(1, 20000);
        while (!terminate) {
          socket.Send(Encoding::UTF8()->GetBytes(string::Format("Counter={0}", counter++)));
          Thread::Sleep(250);
        }
      }));
      client.Start();

      Console::ReadKey(true);
      server.Join();
      client.Join();
    }
  };
}

_startup(Examples::SocketExample);

// This code example can produce the following output:
//
// Counter=186
// Counter=187
// Counter=188
// Counter=189
// ...
