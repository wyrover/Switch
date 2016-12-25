#include "../../../../../Includes/Pcf/System/NullReferenceException.h"
#include "../../../../../Includes/Pcf/System/OutOfMemoryException.h"
#include "../../../../../Includes/Pcf/System/StackOverflowException.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/TcpClient.h"
#include "../../../../../Includes/Pcf/System/Net/Dns.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/SocketException.h"
#include "../../../../../Includes/Pcf/System/Threading/ThreadInterruptedException.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

TcpClient::TcpClient() : active(false) {
  this->clientSocket = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
	this->clientSocket->SetSocketOption(SocketOptionLevel(SocketOptionLevel::Socket), SocketOptionName(SocketOptionName::ReuseAddress), true);
}

TcpClient::TcpClient(AddressFamily addressFamily) : active(false) {
	if (addressFamily == AddressFamily::InterNetworkV6)
    this->clientSocket = SharedPointer<Socket>::Create(addressFamily, SocketType::Stream, ProtocolType::IPv6);
	else
    this->clientSocket = SharedPointer<Socket>::Create(addressFamily, SocketType::Stream, ProtocolType::Tcp);
	this->clientSocket->SetSocketOption(SocketOptionLevel(SocketOptionLevel::Socket), SocketOptionName(SocketOptionName::ReuseAddress), true);
}

TcpClient::TcpClient(const SharedPointer<IPEndPoint>& endPoint) : active(false) {
	if (SharedPointer<IPEndPoint>::IsNullOrInvalid(endPoint))
		throw ArgumentNullException(pcf_current_information);

  this->clientSocket = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
	this->clientSocket->SetSocketOption(SocketOptionLevel(SocketOptionLevel::Socket), SocketOptionName(SocketOptionName::ReuseAddress), true);
  this->clientSocket->Bind(endPoint.ChangeType<Net::EndPoint>());
}

TcpClient::TcpClient(const string& hostname, int32 port) : active(false) {
  this->clientSocket = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
	this->clientSocket->SetSocketOption(SocketOptionLevel(SocketOptionLevel::Socket), SocketOptionName(SocketOptionName::ReuseAddress), true);
	try {
		Connect(hostname, port);
	} catch (const Threading::ThreadInterruptedException& e) {
    throw e;
	} catch (const StackOverflowException& e) {
    throw e;
	} catch (const OutOfMemoryException& e) {
    throw e;
	} catch (const Exception& e) {
    if (!this->clientSocket.IsNull())
			this->clientSocket->Close();
		throw e;
	}
}

TcpClient::TcpClient(const SharedPointer<Socket>& acceptedSocket) : active(false) {
	if (SharedPointer<Socket>::IsNullOrInvalid(acceptedSocket))
		throw ArgumentNullException(pcf_current_information);

	this->clientSocket = acceptedSocket;
	this->active = true;
}

void TcpClient::Connect(const SharedPointer<IPEndPoint>& endPoint) {
  if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);
	if (SharedPointer<IPEndPoint>::IsNullOrInvalid(endPoint))
		throw NullReferenceException(pcf_current_information);

	// Check for already connected and throw here. This check
	// is not required in the other connect methods as they
	// will throw from WinSock. Here, the situation is more
	// complex since we have to resolve a hostname so it's
	// easier to simply block the request up front.
	//
	if (this->active == true)
		 throw SocketException((int32)SocketError::IsConnected, pcf_current_information);

  this->clientSocket->Connect(endPoint.ChangeType<Net::EndPoint>());
	this->active = true;
}

void TcpClient::Connect(const IPAddress& iPAddress, int32 port) {
  if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);
	this->clientSocket->Connect(iPAddress, port);
	this->active = true;
}

void TcpClient::Connect(const string& hostname, int32 port) {
  if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	if (this->active) 
		throw SocketException((int32)SocketError::IsConnected, pcf_current_information);

	// Use the 1st IPAddress corresponding to the hostname
	this->clientSocket->Connect(Dns::GetHostAddresses(hostname)[0], port);
	this->active = true;
}

bool TcpClient::GetActive() const {
	return this->active;
}

int32 TcpClient::GetAvailable() const {
  if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->Available();
}

SharedPointer<Socket> TcpClient::GetClient() {
	return this->clientSocket;
}

const SharedPointer<Socket> TcpClient::GetClient() const {
	return this->clientSocket;
}

void TcpClient::SetClient(const SharedPointer<Socket>& client)
{
	this->clientSocket = client;
}

bool TcpClient::GetConnected() const {
	if (this->clientSocket.IsNull())
		return false;

	return this->clientSocket->Connected();
}

bool TcpClient::GetExclusiveAddressUse() const {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->ExclusiveAddressUse();
}

void TcpClient::SetExclusiveAddressUse(bool exclusiveAddressUse) {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->SetExclusiveAddressUse(exclusiveAddressUse);
}

void TcpClient::SetLingerState(const LingerOption& lingerOption) {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->SetLingerState(lingerOption);
}

LingerOption TcpClient::GetLingerState() const {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->LingerState();
}

void TcpClient::SetNoDelay(bool noDelay) {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->SetNoDelay(noDelay);
}

bool TcpClient::GetNoDelay() const
{
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->NoDelay();

}
int32 TcpClient::GetReceiveBufferSize() const {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->ReceiveBufferSize();
}

void TcpClient::SetReceiveBufferSize(int32 receiveBufferSize) {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->SetReceiveBufferSize(receiveBufferSize);
}

int32 TcpClient::GetReceiveTimeout() const {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->ReceiveTimeout();
}

void TcpClient::SetReceiveTimeout(int32 receiveTimeout) {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->ReceiveTimeout(receiveTimeout);
}

int32 TcpClient::GetSendBufferSize() const {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->SendBufferSize();
}

void TcpClient::SetSendBufferSize(int32 sendBufferSize) {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->SetSendBufferSize(sendBufferSize);
}

int32 TcpClient::GetSendTimeout() const {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->SendTimeout();
}

void TcpClient::SetSendTimeout(int32 SendTimeout) {
	if (this->clientSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->clientSocket->SetSendTimeout(SendTimeout);
}

SharedPointer<NetworkStream> TcpClient::GetStream() {
  if (this->clientSocket.IsNull())
    throw NullReferenceException(pcf_current_information);

  if (!this->clientSocket->Connected())
 		throw SocketException((int32)SocketError::NotConnected, pcf_current_information);

  if (this->dataStream.IsNull())
    this->dataStream = SharedPointer<NetworkStream>::Create(this->clientSocket, true);

	return this->dataStream;
}

void TcpClient::Close() {
	this->active=false;
	if (!this->clientSocket.IsNull()) {
		if ((this->clientSocket->Handle() != IntPtr::Zero) && (this->clientSocket->Connected()))
			this->clientSocket->Shutdown(SocketShutdown::Both);
		this->clientSocket->Close();
    this->clientSocket.Reset();
	}
  if (!this->dataStream.IsNull()) {
		this->dataStream->Close();
    this->dataStream.Reset();
  }
}

TcpClient::~TcpClient() {
	Close();
}
