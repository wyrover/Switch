#include "../../../../../Includes/Pcf/System/NotImplementedException.h"
#include "../../../../../Includes/Pcf/System/NullPointerException.h"
#include "../../../../../Includes/Pcf/System/NullReferenceException.h"
#include "../../../../../Includes/Pcf/System/ObjectClosedException.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/NetworkStream.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/SocketException.h"
#include "../../../../../Includes/Pcf/System/IO/IOException.h"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;

NetworkStream::NetworkStream( const SharedPointer<System::Net::Sockets::Socket>& socket ) {
	if (SharedPointer<System::Net::Sockets::Socket>::IsNullOrInvalid(socket))
		throw NullReferenceException(pcf_current_information);
  
	InitNetworkStream(socket,FileAccess::ReadWrite);
}

NetworkStream::NetworkStream( const SharedPointer<System::Net::Sockets::Socket>& socket, bool ownsSocket ) {
	if (SharedPointer<System::Net::Sockets::Socket>::IsNullOrInvalid(socket))
		throw NullReferenceException(pcf_current_information);
	InitNetworkStream(socket, FileAccess::ReadWrite);
	this->ownsSocket = ownsSocket;
}

NetworkStream::NetworkStream( const SharedPointer<System::Net::Sockets::Socket>& socket,FileAccess access ) {
	if (SharedPointer<System::Net::Sockets::Socket>::IsNullOrInvalid(socket))
		throw NullReferenceException(pcf_current_information);
	InitNetworkStream(socket, access);
}

NetworkStream::NetworkStream( const SharedPointer<System::Net::Sockets::Socket>& socket,FileAccess access, bool ownsSocket ) {
	if (SharedPointer<System::Net::Sockets::Socket>::IsNullOrInvalid(socket))
		throw NullReferenceException(pcf_current_information);
	InitNetworkStream(socket, access);
	this->ownsSocket = ownsSocket;
}

NetworkStream::~NetworkStream() {
	Dispose(true);
}

void NetworkStream::Close() {
	Stream::Close();
	Dispose(true);
}

bool NetworkStream::GetCanRead() const {
	return this->readable;
}

bool NetworkStream::GetCanSeek()  const {
	return false;
}

bool NetworkStream::GetCanTimeout() const {
	return true;
}

bool NetworkStream::GetCanWrite() const {
	return this->writeable;
}

bool NetworkStream::GetDataAvailable() const {
	if (this->streamSocket.IsNull())
		throw NullReferenceException(pcf_current_information);
	return (this->streamSocket->Available() != 0);
}

int64 NetworkStream::GetLength() const {
	throw NotImplementedException(pcf_current_information);
}
int64 NetworkStream::GetPosition() const {
	throw NotImplementedException(pcf_current_information);
}
void NetworkStream::SetPosition(int64 /*position*/) {
	throw NotImplementedException(pcf_current_information);
}

bool NetworkStream::GetReadable() const {
	return this->readable;
}

void NetworkStream::SetReadable(bool readable) {
	this->readable = readable;
}

int32 NetworkStream::GetReadTimeout() const {
  if (this->streamSocket.IsNull())
		throw NullReferenceException(pcf_current_information);
	return this->streamSocket->ReceiveTimeout();
}

void NetworkStream::SetReadTimeout(int32 ReadTimeout) {
  if (this->streamSocket.IsNull())
		throw NullReferenceException(pcf_current_information);
  this->streamSocket->ReceiveTimeout(ReadTimeout);
}

int32 NetworkStream::GetWriteTimeout() const {
  if (this->streamSocket.IsNull())
		throw NullReferenceException(pcf_current_information);
	return this->streamSocket->SendTimeout();
}

void NetworkStream::SetWriteTimeout(int32 Timeout) {
  if (this->streamSocket.IsNull())
		throw NullReferenceException(pcf_current_information);
	this->streamSocket->SetSendTimeout(Timeout);
}

void NetworkStream::Write( const void* Handle, int32 Count) {
	if (Handle == null)
    throw NullReferenceException(pcf_current_information);
	if (Count < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
	if (!CanWrite())
    throw NotSupportedException(pcf_current_information);
  if (this->streamSocket.IsNull())
    throw NullReferenceException(pcf_current_information);
	this->streamSocket->Send((byte *)Handle,Count);
}

int32 NetworkStream::Read(void* Handle, int32 Count) {
	if (Handle == null)
    throw NullReferenceException(pcf_current_information);
	if (Count < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
	if (!CanWrite())
    throw NotSupportedException(pcf_current_information);
  if (this->streamSocket.IsNull())
    throw NullReferenceException(pcf_current_information);
 	return this->streamSocket->Receive((byte *)Handle, Count);
}

int32 NetworkStream::Read(Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
  if (IsClosed())
    throw IOException(pcf_current_information);
  if (!CanRead())
    throw NotSupportedException(pcf_current_information);

  int32 nbBytesRead = 0;
  if (CanRead()) {
    nbBytesRead = Read((void*)&buffer.Data()[offset], count);
  }

  if (nbBytesRead == -1)
    nbBytesRead = 0;

  return nbBytesRead;
}

void NetworkStream::Write( const Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
  if (IsClosed())
    throw ObjectClosedException(pcf_current_information);
  if (!CanWrite())
    throw NotSupportedException(pcf_current_information);

  if (CanWrite()) {
      Write((void*)&buffer.Data()[offset], count);
  }
}

void NetworkStream::InitNetworkStream(const SharedPointer<System::Net::Sockets::Socket>& socket, FileAccess access) {
	if (SharedPointer<System::Net::Sockets::Socket>::IsNullOrInvalid(socket))
    throw NullPointerException(pcf_current_information);
	if (!socket->Blocking())
    throw NotSupportedException(pcf_current_information);
	if (!socket->Connected())
    throw SocketException((int32)SocketError::IsConnected, pcf_current_information); // not connected
	if (socket->SocketType() != SocketType::Stream)
		throw NotSupportedException(pcf_current_information);  // not stream
  
	this->streamSocket = socket;
	switch (access) {
    case FileAccess::Read:
      this->readable = true;
      break;
    case FileAccess::Write:
      this->writeable = true;
      break;
    case FileAccess::ReadWrite:
    default: // assume FileAccess.ReadWrite
      this->readable = true;
      this->writeable = true;
      break;
	}
}

bool NetworkStream::GetWriteable() const {
	return this->writeable;
}

void NetworkStream::Dispose(bool disposing) {
  if (!this->cleanedUp && disposing) {
    //
    // only resource we need to free is the network stream, since this
    // is based on the client socket, closing the stream will cause us
    // to flush the data to the network, close the stream and (in the
    // NetoworkStream code) close the socket as well.
    //
    this->readable = false;
    this->writeable = false;
    
    if (!this->streamSocket.IsNull()) {
      if (this->ownsSocket) {
        if ((this->streamSocket->Handle() != IntPtr::Zero) && (this->streamSocket->Connected()))
          this->streamSocket->Shutdown(SocketShutdown::Both);
        this->streamSocket->Close();
      }
    }
  }
  this->cleanedUp = true;
}
