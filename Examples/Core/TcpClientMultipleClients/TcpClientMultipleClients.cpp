#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;

namespace Examples {
  class TcpClientExample {
  public:
    class Reader : public object {
    public:
      Reader(const NetworkStream& stream) : stream(stream) {this->readThread.Start();}
      
    private:
      Reader() = delete;
      Reader(const Reader& reader) = delete;
      NetworkStream stream;
      Thread readThread {ThreadStart(_delegate {
        StreamReader streamReader(this->stream);
        while (true) {
          _lock(lock) {
            Console::WriteLine(streamReader.ReadLine());
          }
        }
      })};
      static object lock;
    };

    // The main entry point for the application.
    static void Main() {
      Console::WriteLine("Press Ctrl+C to quit...");
      
      // create server thread
      Thread server(ThreadStart(_delegate {
        TcpListener tcpListener(IPAddress::Any, 9050);
        tcpListener.Start();
        List<refptr<Reader>> readers;
        while(true) {
          // create reader for each client
          readers.Add(ref_new<Reader>(tcpListener.AcceptTcpClient().GetStream()));
        }
      }));
      server.Start();
 
      Random rand;
      
      // Create 10 client threads
      List<Thread> clients;
      for(int i = 0; i < 10; i++) {
        clients.Add(Thread(ThreadStart(_delegate {
          StreamWriter streamWriter(TcpClient("127.0.0.1", 9050).GetStream());
          int counter = 1;
          while (true) {
            streamWriter.WriteLine("ThreadId = {0}, Counter = {1}", Thread::CurrentThread().ManagedThreadId, counter++);
            streamWriter.Flush();
            Thread::Sleep(rand.Next(90, 100));
          }
        })));
        clients[clients.Count-1].Start();
      }

      Thread::Sleep(Timeout::Infinite);
    }
  };
}

object Examples::TcpClientExample::Reader::lock;


startup (Examples::TcpClientExample)

// This code example can produce the following output:
//
// ThreadId = 4, Counter = 1
// ThreadId = 4, Counter = 2
// ThreadId = 4, Counter = 3
// ThreadId = 4, Counter = 4
// ThreadId = 7, Counter = 1
// ThreadId = 7, Counter = 2
// ThreadId = 7, Counter = 3
// ThreadId = 11, Counter = 1
// ThreadId = 11, Counter = 2
// ThreadId = 11, Counter = 3
// ThreadId = 11, Counter = 4
// ThreadId = 11, Counter = 5
// ThreadId = 12, Counter = 1
// ThreadId = 12, Counter = 2
// ThreadId = 12, Counter = 3
// ThreadId = 12, Counter = 4
// ThreadId = 12, Counter = 5
// ...
