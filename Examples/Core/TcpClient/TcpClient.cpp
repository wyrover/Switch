#include <Switch/Switch>

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;

namespace Examples {
  class TcpClientExample {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Press Ctrl+C to quit...");
      Thread server(ThreadStart(sw_delegate {
        TcpListener tcpListener(IPAddress::Any, 9050);
        tcpListener.Start();
        StreamReader streamReader(tcpListener.AcceptTcpClient().GetStream());
        while (true) {
          Console::WriteLine(streamReader.ReadLine());
        }
      }));
      server.Start();
      
      Thread client(ThreadStart(sw_delegate {
        StreamWriter streamWriter(TcpClient("127.0.0.1", 9050).GetStream());
        int counter = Random().Next(1, 20000);
        while (true) {
          streamWriter.WriteLine("Counter={0}", counter++);
          streamWriter.Flush();
          Thread::Sleep(250);
        }
      }));
      client.Start();
      
      server.Join();
      client.Join();
    }
  };
}

sw_startup (Examples::TcpClientExample)

// This code example can produce the following output:
//
// Counter=8473
// Counter=8474
// Counter=8475
// Counter=8476
// ...
