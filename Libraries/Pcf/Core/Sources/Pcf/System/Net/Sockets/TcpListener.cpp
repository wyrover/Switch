#include "../../../../../Includes/Pcf/System/ApplicationException.h"
#include "../../../../../Includes/Pcf/System/NullReferenceException.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/TcpListener.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/SocketException.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

TcpListener::TcpListener(SharedPointer<IPEndPoint> ipEndPoint) : active(false), exclusiveAddressUse(false) {
  if (ipEndPoint.IsNull())
		throw ArgumentNullException(pcf_current_information);

	this->serverIPEndPoint = ipEndPoint;

  this->serverSocket = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
	this->serverSocket->SetSocketOption(SocketOptionLevel(SocketOptionLevel::Socket), SocketOptionName(SocketOptionName::ReuseAddress),true);

}

TcpListener::TcpListener(const IPAddress& piPAddress, int32 port) : active(false), exclusiveAddressUse(false) {
	this->serverIPEndPoint = SharedPointer<IPEndPoint>::Create(piPAddress, port);

  this->serverSocket = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
	this->serverSocket->SetSocketOption(SocketOptionLevel(SocketOptionLevel::Socket), SocketOptionName(SocketOptionName::ReuseAddress),true);
}

bool TcpListener::GetActive() const {
	return this->active;
}

SharedPointer<Socket> TcpListener::GetServer() {
	return this->serverSocket;
}

const SharedPointer<Socket> TcpListener::GetServer() const {
	return this->serverSocket;
}

bool TcpListener::GetExclusiveAddressUse() const {
	if (this->serverSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	return this->serverSocket->ExclusiveAddressUse();
}

void TcpListener::SetExclusiveAddressUse(bool exclusiveAddressUse) {
	if (this->serverSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	if (this->active) 
		throw ApplicationException(pcf_current_information); // tcplistener must be stopped
	
	this->serverSocket->SetExclusiveAddressUse(exclusiveAddressUse);
	this->exclusiveAddressUse = exclusiveAddressUse;
}

const SharedPointer<EndPoint> TcpListener::GetLocalEndPoint() const {
	if (this->serverSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	if (this->active) 
		return this->serverSocket->LocalEndPoint();

  return this->serverIPEndPoint.ChangeType<Net::EndPoint>();
}

SharedPointer<EndPoint> TcpListener::GetLocalEndPoint() {
	if (this->serverSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	if (this->active) 
		return this->serverSocket->LocalEndPoint();

  return this->serverIPEndPoint.ChangeType<Net::EndPoint>();
}

UniquePointer<Socket> TcpListener::AcceptSocket() {
	if (this->serverSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	if (!this->active)
		throw InvalidOperationException(pcf_current_information);

	return this->serverSocket->Accept();
}

UniquePointer<TcpClient> TcpListener::AcceptTcpClient() {
	if (this->serverSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	if (!this->active)
		throw InvalidOperationException(pcf_current_information);

	UniquePointer<Socket> pacceptedSocket = this->serverSocket->Accept();
	return new TcpClient(pacceptedSocket);
}

void TcpListener::Start() {
	//Starts listening to network requests.
	Start((int32)SocketOptionName(SocketOptionName::MaxConnections));
}

void TcpListener::Start(int32 backlog) {
	//Starts listening to network requests.
	if (this->serverSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	if (backlog > (int32)SocketOptionName::MaxConnections || backlog < 0) 
		throw ArgumentOutOfRangeException(pcf_current_information);

	// already listening
	if (this->active) 
		return;

  this->serverSocket->Bind(this->serverIPEndPoint.ChangeType<Net::EndPoint>());

	try {
		this->serverSocket->Listen(backlog);
	} catch (const SocketException& e) {
    // When there is an exception unwind previous actions (bind etc)
		Stop();
		throw e;
	}
	this->active = true;
}

void TcpListener::Stop() {
	//       Closes the network connection.
	if (!this->serverSocket.IsNull()) {
		this->serverSocket->Shutdown(SocketShutdown::Both);
		this->serverSocket->Close();
		this->serverSocket.Reset();
	}
	
	this->active = false;

  this->serverSocket = SharedPointer<Socket>::Create(this->serverIPEndPoint->AddressFamily(), SocketType::Stream, ProtocolType::Tcp);
	
	if (this->exclusiveAddressUse) 
		this->serverSocket->SetExclusiveAddressUse(true);
}

bool TcpListener::Pending() {
	if (this->serverSocket.IsNull())
		throw NullReferenceException(pcf_current_information);

	// Determine if there are pending connections
	if (!this->active)
		throw InvalidOperationException(pcf_current_information); // net stopped 

	return this->serverSocket->Poll(0, SelectMode::SelectRead);
}

TcpListener::~TcpListener() {
	if (!this->serverSocket.IsNull()) {
		this->serverSocket->Close();
		this->serverSocket.Reset();
  }
}
