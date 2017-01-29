#include "TestUtils.h"
#include <Pcf/System/Net/Sockets/NetworkStream.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace TUnit;

namespace {
  TEST(NetworkStream, Default_Constructor) {
    Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket.Connect(IPEndPoint(IPAddress(74, 125, 136, 94), 80)); // www.google.be , loopback and port do not work on MacOs...
    NetworkStream networkStream(socket);
  }
  
  TEST(NetworkStream, Default_Constructor_With_Own_Socket) {
    Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket.Connect(IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    NetworkStream networkStream(socket, true);
  }
  
  TEST(NetworkStream, Default_Constructor_With_FileAccess_Read) {
    Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket.Connect(IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    System::IO::FileAccess access(System::IO::FileAccess::Read);
    NetworkStream networkStream(socket, access);
    EXPECT_EQ(networkStream.CanRead(), true);
    EXPECT_EQ(networkStream.CanWrite(), false);
  }
  
  TEST(NetworkStream, Default_Constructor_With_FileAccess_Write) {
    Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket.Connect(IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    System::IO::FileAccess access(System::IO::FileAccess::Write);
    NetworkStream networkStream(socket, access);
    EXPECT_EQ(networkStream.CanRead(), false);
    EXPECT_EQ(networkStream.CanWrite(), true);
  }
  
  TEST(NetworkStream, Default_Constructor_With_File_Access_ReadWrite) {
    Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket.Connect(IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    System::IO::FileAccess access(System::IO::FileAccess::ReadWrite);
    NetworkStream networkStream(socket, access);
    EXPECT_EQ(networkStream.CanRead(), true);
    EXPECT_EQ(networkStream.CanWrite(), true);
  }
  
  TEST(NetworkStream, Default_Constructor_With_File_Access_ReadWrite_With_Seek) {
    Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket.Connect(IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    System::IO::FileAccess access(System::IO::FileAccess::ReadWrite);
    NetworkStream networkStream(socket, access);
    EXPECT_EQ(networkStream.CanSeek(), false);
  }
  
  TEST(NetworkStream, Default_Constructor_With_File_Access_ReadWrite_With_Timeout) {
    Socket socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket.Connect(IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    System::IO::FileAccess access(System::IO::FileAccess::ReadWrite);
    NetworkStream networkStream(socket, access);
    EXPECT_EQ(networkStream.CanTimeout(),  true);
  }
  
}
