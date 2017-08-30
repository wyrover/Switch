#include "../../../../../Includes/Switch/System/ArgumentNullException.hpp"
#include "../../../../../Includes/Switch/System/ObjectClosedException.hpp"
#include "../../../../../Includes/Switch/System/Net/Sockets/NetworkStream.hpp"
#include "../../../../../Includes/Switch/System/Net/Sockets/SocketException.hpp"
#include "../../../../../Includes/Switch/System/IO/IOException.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;

NetworkStream::NetworkStream( const System::Net::Sockets::Socket& socket,FileAccess access ) {
  if (!socket.Connected || socket.SocketType != SocketType::Stream || !socket.Blocking)
    throw IOException(sw_current_information);
  
  this->data->streamSocket = socket;
  switch (access) {
    case FileAccess::Read: this->data->readable = true; break;
    case FileAccess::Write: this->data->writeable = true; break;
    case FileAccess::ReadWrite: this->data->readable = this->data->writeable = true; break;
  }
}

NetworkStream::~NetworkStream() {
  if (this->data.IsUnique())
	  Close();
}

void NetworkStream::Close() {
  this->data->readable = false;
  this->data->writeable = false;
	Stream::Close();
  this->data->streamSocket = Socket();
}

int32 NetworkStream::Read(Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0 || offset >= buffer.Length)
    throw ArgumentOutOfRangeException(sw_current_information);
  if (!this->data->readable)
    throw NotSupportedException(sw_current_information);
  return this->data->streamSocket.Receive(buffer, offset, count, SocketFlags::None);
}

void NetworkStream::Write( const Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0 || offset >= buffer.Length)
    throw ArgumentOutOfRangeException(sw_current_information);
  if (!this->data->writeable)
    throw NotSupportedException(sw_current_information);
  this->data->streamSocket.Send(buffer, offset, count, SocketFlags::None);
}
