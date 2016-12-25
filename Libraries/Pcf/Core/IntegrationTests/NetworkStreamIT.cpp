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
    Socket* socket = new Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket->Connect(new IPEndPoint(IPAddress(74, 125, 136, 94), 80)); // www.google.be , loopback and port do not work on MacOs...
    Sp<NetworkStream> networkStream;
    networkStream = Sp<NetworkStream>::Create(socket);
  }
  
  TEST(NetworkStream, Default_Constructor_With_Own_Socket) {
    Socket* socket = new Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket->Connect(new IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    Sp<NetworkStream> networkStream;
    networkStream = Sp<NetworkStream>::Create(socket,true);
  }
  
  TEST(NetworkStream, Default_Constructor_With_FileAccess_Read) {
    Socket* socket = new Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket->Connect(new IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    Sp<NetworkStream> networkStream;
    System::IO::FileAccess  Access(System::IO::FileAccess::Read);
    networkStream = Sp<NetworkStream>::Create(socket,Access);
    EXPECT_EQ(networkStream->CanRead(), true);
    EXPECT_EQ(networkStream->CanWrite(), false);
  }
  
  TEST(NetworkStream, Default_Constructor_With_FileAccess_Write) {
    Socket* socket = new Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket->Connect(new IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    Sp<NetworkStream> networkStream;
    System::IO::FileAccess  Access(System::IO::FileAccess::Write);
    networkStream = Sp<NetworkStream>::Create(socket,Access);
    EXPECT_EQ(networkStream->CanRead(),  false);
    EXPECT_EQ(networkStream->CanWrite(), true);
  }
  
  TEST(NetworkStream, Default_Constructor_With_File_Access_ReadWrite) {
    Socket* socket = new Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket->Connect(new IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    Sp<NetworkStream> networkStream;
    System::IO::FileAccess  Access(System::IO::FileAccess::ReadWrite);
    networkStream = Sp<NetworkStream>::Create(socket,Access);
    EXPECT_EQ(networkStream->CanRead(),  true);
    EXPECT_EQ(networkStream->CanWrite(), true);
  }
  
  TEST(NetworkStream, Default_Constructor_With_File_Access_ReadWrite_With_Seek) {
    Socket* socket = new Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket->Connect(new IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    Sp<NetworkStream> networkStream;
    System::IO::FileAccess Access(System::IO::FileAccess::ReadWrite);
    networkStream = Sp<NetworkStream>::Create(socket,Access);
    EXPECT_EQ(networkStream->CanSeek(),  false);
  }
  
  TEST(NetworkStream, Default_Constructor_With_File_Access_ReadWrite_With_Timeout) {
    Socket* socket = new Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
    socket->Connect(new IPEndPoint(IPAddress(74, 125, 136, 94), 80));
    Sp<NetworkStream> networkStream;
    System::IO::FileAccess  Access(System::IO::FileAccess::ReadWrite);
    networkStream = Sp<NetworkStream>::Create(socket,Access);
    EXPECT_EQ(networkStream->CanTimeout(),  true);
  }
  
}