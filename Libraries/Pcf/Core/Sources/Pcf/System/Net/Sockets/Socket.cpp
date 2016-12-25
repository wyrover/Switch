#include "../../../../../Includes/Pcf/System/NotImplementedException.h"
#include "../../../../../Includes/Pcf/System/ObjectClosedException.h"
#include "../../../../../Includes/Pcf/System/Net/Dns.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/Socket.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/MulticastOption.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/SocketException.h"
#include "../../../../__OS/CoreApi.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Collections::Generic;

Property<bool, ReadOnly> Socket::OSSupportsIPv4 {
  [] {return __OS::CoreApi::Socket::GetOSSupportsIPv4();}
};

Property<bool, ReadOnly> Socket::OSSupportsIPv6 {
  [] {return __OS::CoreApi::Socket::GetOSSupportsIPv6();}
};

Socket::Socket(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType) {
  this->data->addressFamily = addressFamily;
  this->data->protocolType = protocolType;
  this->data->socketType = socketType;
  
  if (__OS::CoreApi::Socket::Open(this->data->addressFamily, this->data->socketType, this->data->protocolType, &this->data->socket) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
}

Socket::Socket(intptr socket) {
  this->data->socket = socket;
}

Socket::~Socket() {
  if (this->data.IsUnique())
    Close();
}

Socket Socket::Accept() {
  if (this->data->socket == 0)
    throw ObjectClosedException(pcf_current_information);
  if (this->data->bound == false || this->data->listening == false)
    throw InvalidOperationException(pcf_current_information);
 
  SocketAddress socketAddress(this->data->addressFamily);
  intptr socketHandle = 0;
  if (__OS::CoreApi::Socket::Accept(this->data->socket, (byte*)socketAddress.bytes.Data(), socketAddress.Size, &socketHandle) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
  
  Socket socketNewlyCreated(socketHandle);
  socketNewlyCreated.data->addressFamily = this->data->addressFamily;
  socketNewlyCreated.data->socketType = this->data->socketType;
  socketNewlyCreated.data->protocolType = this->data->protocolType;
  socketNewlyCreated.data->localEndPoint = IPEndPoint(0, 0).Create(socketAddress);
	socketNewlyCreated.data->connected = true;
  this->data->connected = true;
  return socketNewlyCreated;
}

void Socket::InnerBind() {
  SocketAddress socketAddress = this->data->localEndPoint->Serialize();
  if (__OS::CoreApi::Socket::Bind(this->data->socket, (byte*)socketAddress.bytes.Data(), socketAddress.Size()) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);

  this->data->bound = true;
}

void Socket::Close() {
  this->data->connected = false;
  this->data->bound = false;
  this->data->listening = false;
  if (this->data->socket != IntPtr::Zero()) {
    __OS::CoreApi::Socket::Close(this->data->socket);
    this->data->socket = IntPtr::Zero();
  }
}

void Socket::InnerConnect() {
  SocketAddress socketAddress = this->data->remoteEndPoint->Serialize();
  if (__OS::CoreApi::Socket::Connect(this->data->socket, (byte*)socketAddress.bytes.Data(), socketAddress.Size) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);

  this->data->connected = true;
}

void Socket::Connect(const IPAddress& address, int32 port) {
  Connect(IPEndPoint(address, port));
}

void Socket::Connect(const Array<IPAddress>& addresses, int32 port) {
  for (IPAddress ipAddress : addresses) {
    if (Connected == false)
      Connect(ipAddress, port);
  }
}

void Socket::Connect(const string &host, int32 port) {
  Connect(Dns::GetHostAddresses(host), port);
}

void Socket::Disconnect(bool reuseSocket) {
  if (this->data->connected == false)
    throw ObjectClosedException(pcf_current_information);

  if (__OS::CoreApi::Socket::Connect(this->data->socket, null, 0) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);

  this->data->connected = false;
  this->data->bound = false;

  if (reuseSocket == false)
    Close();
}

SocketInformation Socket::DuplicateAndClose(int32 targetProcessId) {
  throw NotImplementedException(pcf_current_information);
}

int32 Socket::GetAvailable() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  int32 nbrBytesAvailable = 0;
  __OS::CoreApi::Socket::GetAvailable(this->data->socket, &nbrBytesAvailable);
  return nbrBytesAvailable;
}

bool Socket::GetBlocking() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return !this->data->nonBlocking;
}

bool Socket::GetDontFragment() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::DontFragment).ChangeType<Int32>().ToObject() == 1;
}

bool Socket::GetDualMode() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::IPv6Only).ChangeType<Int32>().ToObject() == 0;
}

bool Socket::GetEnableBroadcast() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Broadcast).ChangeType<Int32>().ToObject() == 1;
}

bool Socket::GetExclusiveAddressUse() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ExclusiveAddressUse).ChangeType<Int32>().ToObject() == 1;
}

LingerOption Socket::GetLingerState() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return LingerOption(GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Linger).ChangeType<LingerOption>().ToObject());
}

const EndPoint& Socket::GetLocalEndPoint() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return *this->data->localEndPoint;
}

bool Socket::GetMulticastLoopback() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::IP, SocketOptionName::MulticastLoopback).ChangeType<Int32>().ToObject() == 1;
}

bool Socket::GetNoDelay() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Tcp, SocketOptionName::NoDelay).ChangeType<Int32>().ToObject() == 1;
}

int32 Socket::GetReceiveBufferSize() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer).ChangeType<Int32>().ToObject();
}

int32 Socket::GetReceiveTimeout() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout).ChangeType<Int32>().ToObject();
}

const EndPoint& Socket::GetRemoteEndPoint() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return *this->data->remoteEndPoint;
}

int32 Socket::GetSendBufferSize() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer).ChangeType<Int32>().ToObject();
}

int32 Socket::GetSendTimeout() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout).ChangeType<Int32>().ToObject();
}

UniquePointer<object> Socket::GetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName) const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);

  if (socketOptionName == SocketOptionName::MaxConnections)
    throw SocketException((int32)SocketError::ProtocolOption, pcf_current_information);
  
  if (socketOptionName == SocketOptionName::Linger) {
    /// @todo
    //retValue = new LingerOption(false, 0);
    throw NotImplementedException(pcf_current_information);
  }
  
  if (socketOptionName == SocketOptionName::AddMembership || socketOptionName == SocketOptionName::DropMembership) {
    /// @todo
    //retValue = new MulticastOption(IPAddress());
    throw NotImplementedException(pcf_current_information);
  }

  int32 socketOption = 0;
  int32 size = sizeof(int32);
  if (__OS::CoreApi::Socket::GetSocketOption(this->data->socket, socketOptionLevel, socketOptionName, &socketOption, &size) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
  return new Int32(socketOption);
}

int32 Socket::GetTtl() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout).ChangeType<Int32>().ToObject();
}

int32 Socket::IOControl(System::Net::Sockets::IOControlCode /*ioControlCode*/, const Array<byte>& /*optionInValue*/, Array<byte>& /*optionOutValue*/) {
  throw NotImplementedException(pcf_current_information);
}

void Socket::Listen(int32 backlog) {
  if (this->data->bound == false)
    throw SocketException((int32)SocketError::NotConnected, pcf_current_information);
  
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  if (backlog > (int32)SocketOptionName::MaxConnections || backlog < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);

  __OS::CoreApi::Socket::Listen(this->data->socket, backlog);

  this->data->listening = true;
}

bool Socket::Poll(int32 microseconds, SelectMode mode) {
  int32 status = __OS::CoreApi::Socket::Poll(this->data->socket, microseconds, (int32)mode);

  if (status < 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
  
  return (status > 0);
}

int32 Socket::Receive(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags) {
  SocketError errorCode = SocketError::Success;
  int32 numberOfBytesReceived = this->Receive(buffer, offset, size, socketFlags, errorCode);
  if (errorCode != SocketError::Success)
    throw SocketException((int32)errorCode, pcf_current_information);
  return numberOfBytesReceived;
}

int32 Socket::Receive(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, SocketError& errorCode) {
  if (offset < 0 || size < 0 || offset + size > buffer.Length)
    throw IndexOutOfRangeException(pcf_current_information);
  if (this->data->socket == 0)
    throw ObjectClosedException(pcf_current_information);
  
  int32 numberOfBytesReceived = __OS::CoreApi::Socket::Receive(this->data->socket, (byte*)&buffer.Data()[offset], size, (int32)socketFlags);
  errorCode = numberOfBytesReceived == -1 ? (SocketError)__OS::CoreApi::Socket::GetLastError() : SocketError::Success;
  return numberOfBytesReceived;
}

int32 Socket::ReceiveFrom(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, IPEndPoint& endPoint) {
  if (offset < 0 || size < 0 || offset + size > buffer.Length)
    throw IndexOutOfRangeException(pcf_current_information);
  if (this->data->socket == 0)
    throw ObjectClosedException(pcf_current_information);

  SocketAddress socketAddress(this->data->addressFamily);
  int32 numberOfBytesReceived = __OS::CoreApi::Socket::ReceiveFrom(this->data->socket, (byte*)&buffer.Data()[offset], size, (int32)socketFlags, (byte*)socketAddress.bytes.Data(), socketAddress.Size);
  if (numberOfBytesReceived == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
  endPoint = endPoint.Create(socketAddress).ChangeType<IPEndPoint>().ToObject();

  return numberOfBytesReceived;
}

int32 Socket::Select(IList<Socket>& checkRead, IList<Socket>& checkWrite, IList<Socket>& checkError, int32 microseconds) {
  if (checkRead.Count == 0 && checkWrite.Count == 0 && checkError.Count == 0)
    throw ArgumentNullException(pcf_current_information);
  
  int32 nbCheckRead = checkRead.Count;
  UniquePointer<intptr[]> checkReadHandles(new intptr[nbCheckRead]);
  for (int32 i = 0; i < nbCheckRead; i++)
    checkReadHandles[i] = checkRead[i].data->socket;
  
  int32 nbCheckWrite = checkWrite.Count;
  UniquePointer<intptr[]> checkWriteHandles(new intptr[nbCheckWrite]);
  for (int32 i = 0; i < nbCheckWrite; i++)
    checkWriteHandles[i] = checkWrite[i].data->socket;
  
  int32 nbCheckError = checkError.Count;
  UniquePointer<intptr[]> checkErrorHandles(new intptr[nbCheckError]);
  for (int32 i = 0; i < nbCheckError; i++)
    checkErrorHandles[i] = checkError[i].data->socket;
  
  int32 status = __OS::CoreApi::Socket::Select(checkReadHandles.ToPointer(), nbCheckRead, checkWriteHandles.ToPointer(), nbCheckWrite, checkErrorHandles.ToPointer(), nbCheckError, microseconds);
  
  if (status < 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
  
  // List the null sockets
  List<Socket> readToRemove;
  for (int32 i = 0; i < nbCheckRead; i++)
    if (checkReadHandles[i] == 0)
      readToRemove.Add(checkRead[i]);
  
  // Remove the null sockets
  for (Socket item : readToRemove)
    if (checkRead.Contains(item))
      checkRead.Remove(item);
  
  // List the null sockets
  List<Socket> writeToRemove;
  for (int32 i = 0; i < nbCheckWrite; i++)
    if (checkWriteHandles[i] == 0)
      writeToRemove.Add(checkWrite[i]);
  
  // Remove the null sockets
  for (Socket item : writeToRemove)
    if (checkWrite.Contains(item))
      checkWrite.Remove(item);
  
  // List the null sockets
  List<Socket> errorToRemove;
  for (int32 i = 0; i < nbCheckError; i++)
    if (checkErrorHandles[i] == 0)
      errorToRemove.Add(checkError[i]);
  
  // Remove the null sockets
  for (Socket item : errorToRemove)
    if (checkError.Contains(item))
      checkError.Remove(item);
  
  return status;
}

int32 Socket::Send(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags) {
  SocketError errorCode = SocketError::Success;
  int32 numberOfBytesSended = this->Send(buffer, offset, size, socketFlags, errorCode);
  if (errorCode != SocketError::Success)
    throw SocketException((int32)errorCode, pcf_current_information);
  return numberOfBytesSended;
}

int32 Socket::Send(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, SocketError& errorCode) {
  if (offset < 0 || size < 0 || offset + size > buffer.Length)
    throw IndexOutOfRangeException(pcf_current_information);
  if (this->data->socket == 0)
    throw ObjectClosedException(pcf_current_information);
  
  int32 numberOfBytesSended = __OS::CoreApi::Socket::Send(this->data->socket, (byte*)&buffer.Data()[offset], size, (int32)socketFlags);
  errorCode = numberOfBytesSended == -1 ? (SocketError)__OS::CoreApi::Socket::GetLastError() : SocketError::Success;
  return numberOfBytesSended;
}

int32 Socket::SendTo(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, const IPEndPoint& endPoint) {
  if (offset < 0 || size < 0 || offset + size > buffer.Length)
    throw IndexOutOfRangeException(pcf_current_information);
  if (this->data->socket == 0)
    throw ObjectClosedException(pcf_current_information);

  SocketAddress socketAddress = endPoint.Serialize();
  int32 numberOfBytesSended = __OS::CoreApi::Socket::SendTo(this->data->socket, (byte*)&buffer.Data()[offset], size, (int32)socketFlags, (byte*)socketAddress.bytes.Data(), socketAddress.Size);
  if (numberOfBytesSended == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
  return numberOfBytesSended;
}

void Socket::SetBlocking(bool blocking) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  if (__OS::CoreApi::Socket::SetBlocking(this->data->socket, blocking) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);

  this->data->nonBlocking = !blocking;
}

void Socket::SetDontFragment(bool dontFragment) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::DontFragment, dontFragment);
}

void Socket::SetDualMode(bool dualMode) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::IPv6Only, !dualMode);
}

void Socket::SetEnableBroadcast(bool enableBroadcast) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Broadcast, enableBroadcast);
}

void Socket::SetExclusiveAddressUse(bool exclusiveAddressUse) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ExclusiveAddressUse, exclusiveAddressUse);
}

void Socket::SetLingerState(const LingerOption &lingerOption) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ExclusiveAddressUse, lingerOption);
}

void Socket::SetMulticastLoopback(bool multicastLoopback) {
  SetSocketOption(SocketOptionLevel::IP, SocketOptionName::MulticastLoopback, multicastLoopback);
}

void Socket::SetNoDelay(bool noDelay) {
  SetSocketOption(SocketOptionLevel::Tcp, SocketOptionName::NoDelay, noDelay);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, bool optionValue) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  int32 option = 0;
  if (optionValue)
    option = 0xFFFFFFFF;

  if (__OS::CoreApi::Socket::SetSocketOption(this->data->socket, socketOptionLevel, socketOptionName, (int32 *)&option, sizeof(option)) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const Array<byte>& optionValue) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  if (__OS::CoreApi::Socket::SetSocketOption(this->data->socket, socketOptionLevel, socketOptionName, (byte*)optionValue.Data(), optionValue.Length) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, int32 optionValue) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  if (__OS::CoreApi::Socket::SetSocketOption(this->data->socket, socketOptionLevel, socketOptionName, (byte *)&optionValue, sizeof(optionValue)) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const object& optionValue) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(pcf_current_information);
  
  if (is<MulticastOption>(optionValue)) {
    /// @todo
    // Array<byte> optionValue;
    // SetSocketOption(socketOptionLevel, socketOptionName, optionValue);
    throw NotImplementedException(pcf_current_information);
  } else if (is<LingerOption>(optionValue)) {
    /// @todo
    // Array<byte> optionValue;
    // SetSocketOption(socketOptionLevel, socketOptionName, optionValue);
    throw NotImplementedException(pcf_current_information);
  } else
    throw NotImplementedException(pcf_current_information);
}

void Socket::SetReceiveBufferSize(int32 bufferSize) {
  if (bufferSize < 0)
    throw IndexOutOfRangeException(pcf_current_information);
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer, bufferSize);
}

void Socket::SetReceiveTimeout(int32 timeout) {
  if (timeout < -1)
    throw IndexOutOfRangeException(pcf_current_information);
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout, timeout);
}

void Socket::SetSendBufferSize(int32 bufferSize) {
  if (bufferSize < 0)
    throw IndexOutOfRangeException(pcf_current_information);
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer, bufferSize);
}

void Socket::SetSendTimeout(int32 timeout) {
  if (timeout < -1)
    throw IndexOutOfRangeException(pcf_current_information);
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout, timeout);
}

void Socket::SetTtl(int32 ttl) {
  if (this->data->addressFamily != System::Net::Sockets::AddressFamily::InterNetwork && this->data->addressFamily != System::Net::Sockets::AddressFamily::InterNetworkV6)
    throw NotSupportedException(pcf_current_information);
  if (ttl < 0)
    throw IndexOutOfRangeException(pcf_current_information);
  SetSocketOption(SocketOptionLevel::IP, SocketOptionName::IpTimeToLive, ttl);
}

void Socket::Shutdown(SocketShutdown how) {
  if (this->data->socket == 0)
    throw ObjectClosedException(pcf_current_information);
  if (__OS::CoreApi::Socket::Shutdown(this->data->socket, Enum<SocketShutdown>::ToInt32(how)) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), pcf_current_information);
}
