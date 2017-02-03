#include "../../../../../Includes/Pcf/System/ArgumentNullException.h"
#include "../../../../../Includes/Pcf/System/ObjectClosedException.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/NetworkStream.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/SocketException.h"
#include "../../../../../Includes/Pcf/System/IO/IOException.h"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;

NetworkStream::NetworkStream( const System::Net::Sockets::Socket& socket,FileAccess access ) {
  if (!socket.Connected || socket.SocketType != SocketType::Stream || !socket.Blocking)
    throw IOException(pcf_current_information);
  
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
    throw ArgumentOutOfRangeException(pcf_current_information);
  if (!this->data->readable)
    throw NotSupportedException(pcf_current_information);
  return this->data->streamSocket.Receive(buffer, offset, count, SocketFlags::None);
}

void NetworkStream::Write( const Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0 || offset >= buffer.Length)
    throw ArgumentOutOfRangeException(pcf_current_information);
  if (!this->data->writeable)
    throw NotSupportedException(pcf_current_information);
  this->data->streamSocket.Send(buffer, offset, count, SocketFlags::None);
}
