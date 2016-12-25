#include "../../../../../Includes/Pcf/System/NotImplementedException.h"
#include "../../../../../Includes/Pcf/System/ObjectClosedException.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/Socket.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/MulticastOption.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/SocketException.h"
#include "../../../Os/Socket.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Collections::Generic;

Property<bool, ReadOnly> Socket::OSSupportsIPv4 {
  [] {return Pcf::Os::Socket::GetOSSupportsIPv4();}
};

Property<bool, ReadOnly> Socket::OSSupportsIPv6 {
  [] {return Pcf::Os::Socket::GetOSSupportsIPv6();}
};

Socket::Socket(const SocketInformation& /*socketInformation*/) : socket(null), addressFamily(System::Net::Sockets::AddressFamily::Unspecified), protocolType(System::Net::Sockets::ProtocolType::Unspecified), socketType(System::Net::Sockets::SocketType::Unknown), connected(false), listening(false), nonBlocking(false), bound(false) {
}

Socket::Socket(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType) : socket(null), addressFamily(addressFamily), protocolType(protocolType), socketType(socketType), connected(false), listening(false), nonBlocking(false), bound(false) {
  void* socket = null;
  if (Os::Socket::Open(this->addressFamily, this->socketType, this->protocolType, &socket) != 0)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
  
  this->socket = socket;
}

Socket::Socket(void* socket) : socket(socket), addressFamily(System::Net::Sockets::AddressFamily::Unspecified), protocolType(System::Net::Sockets::ProtocolType::Unspecified), socketType(System::Net::Sockets::SocketType::Unknown), connected(false), listening(false), nonBlocking(false), bound(false) {}

Socket::~Socket() {
  Close();
}

UniquePointer<Socket>  Socket::Accept() {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  if (this->bound == false || this->listening == false)
    throw InvalidOperationException(pcf_current_information);
 
  UniquePointer<byte[]> array(new byte[32]); // SocketAddress::defaultBufferSize
  void* socket = null;

  SocketAddress peerAddr(this->addressFamily);
  int32 arrayLength = peerAddr.Size;
  
  if (Os::Socket::Accept(this->socket, array.ToPointer(), &arrayLength, &socket) != 0)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
  
  UniquePointer<Socket> socketAccepted = new Socket(socket);
  SocketAddress SocketAddress(array.ToPointer(), arrayLength);
  socketAccepted->addressFamily = this->addressFamily;
  socketAccepted->socketType = this->socketType;
  socketAccepted->protocolType = this->protocolType;
  socketAccepted->localEndPoint = IPEndPoint(0, 0).Create(SocketAddress);
	socketAccepted->connected = true;
  this->connected = true;
  return socketAccepted;
}

void Socket::Bind(const SharedPointer<EndPoint>& localEndPoint) {
  if (SharedPointer<EndPoint>::IsNullOrInvalid(localEndPoint))
    throw ArgumentNullException(pcf_current_information);
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  this->localEndPoint = localEndPoint;
  SocketAddress socketAddress = localEndPoint->Serialize();

  if (Pcf::Os::Socket::Bind(this->socket, (byte*)socketAddress.Data(), socketAddress.Size) != 0)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);

  this->bound = true;
}

void Socket::Close() {
  this->connected = false;
  this->bound = false;
  this->listening = false;
  if (this->socket != IntPtr::Zero) {
    Pcf::Os::Socket::Close(this->socket);
    this->socket = IntPtr::Zero;
  }
}

void Socket::Connect(SharedPointer<EndPoint> endPoint) {
  if (SharedPointer<EndPoint>::IsNullOrInvalid(endPoint))
    throw ArgumentNullException(pcf_current_information);
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  if (this->listening == true)
    throw InvalidOperationException(pcf_current_information);
  
  this->remoteEndPoint = endPoint;
  SocketAddress socketAddress = endPoint->Serialize();

  if (Pcf::Os::Socket::Connect(this->socket, (byte*)socketAddress.Data(), socketAddress.Size) != 0)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);

  this->connected = true;
}

void Socket::Connect(const IPAddress& address, int32 port) {
  Connect(new IPEndPoint(address, port));
}

void Socket::Connect(const Array<IPAddress>& addresses, int32 port) {
  for (IPAddress ipAddress : addresses) {
    if (Connected == false)
      Connect(ipAddress, port);
  }
}

void Socket::Disconnect(bool reuseSocket) {
  if (this->connected == false)
    throw ObjectClosedException(pcf_current_information);

  if (Os::Socket::Connect(this->socket, null, 0) != 0)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);

  this->connected = false;
  this->bound = false;

  if (reuseSocket == false)
    Close();
}

SocketInformation Socket::DuplicateAndClose(int32 targetProcessId) {
  throw NotImplementedException(pcf_current_information);
}

int32 Socket::GetAvailable() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  int32 nbrBytesAvailable = 0;
  Pcf::Os::Socket::GetAvailable(this->socket, &nbrBytesAvailable);
  return nbrBytesAvailable;
}

bool Socket::GetBlocking() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return !this->nonBlocking;
}

bool Socket::GetDontFragment() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::DontFragment).ChangeType<Int32>().ToObject() == 1;
}

bool Socket::GetEnableBroadcast() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Broadcast).ChangeType<Int32>().ToObject() == 1;
}

bool Socket::GetExclusiveAddressUse() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ExclusiveAddressUse).ChangeType<Int32>().ToObject() == 1;
}

LingerOption Socket::GetLingerState() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return LingerOption(GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Linger).ChangeType<LingerOption>().ToObject());
}

SharedPointer<EndPoint> Socket::GetLocalEndPoint() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return this->localEndPoint;
}

bool Socket::GetMulticastLoopback() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::IP, SocketOptionName::MulticastLoopback).ChangeType<Int32>().ToObject() == 1;
}

bool Socket::GetNoDelay() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Tcp, SocketOptionName::NoDelay).ChangeType<Int32>().ToObject() == 1;
}

int32 Socket::GetReceiveBufferSize() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer).ChangeType<Int32>().ToObject();
}

int32 Socket::GetReceiveTimeout() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout).ChangeType<Int32>().ToObject();
}

void Socket::SetReceiveTimeout(int32 value) {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout, value);
}

const EndPoint& Socket::GetRemoteEndPoint() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return *this->remoteEndPoint;
}

int32 Socket::GetSendBufferSize() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer).ChangeType<Int32>().ToObject();
}

int32 Socket::GetSendTimeout() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout).ChangeType<Int32>().ToObject();
}

UniquePointer<object> Socket::GetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName) const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);

  if (socketOptionName == SocketOptionName::MaxConnections)
    throw SocketException((int32)SocketError::ProtocolOption, pcf_current_information);
  
  if (socketOptionName == SocketOptionName::Linger) {
    //retValue = new LingerOption(false, 0);
    // [YFI] TODO
    throw NotImplementedException(pcf_current_information);
  }
  
  if (socketOptionName == SocketOptionName::AddMembership || socketOptionName == SocketOptionName::DropMembership) {
    //retValue = new MulticastOption(IPAddress());
    // [YFI] TODO
    throw NotImplementedException(pcf_current_information);
  }

  int32 socketOption = 0;
  int32 size = sizeof(int32);
  if (Os::Socket::GetSocketOption(this->socket, socketOptionLevel, socketOptionName, &socketOption, &size) == -1)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
  return new Int32(socketOption);
}

int32 Socket::GetTtl() const {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout).ChangeType<Int32>().ToObject();
}

int32 Socket::IOControl(System::Net::Sockets::IOControlCode /*ioControlCode*/, const Array<byte>& /*optionInValue*/, Array<byte>& /*optionOutValue*/) {
  throw NotImplementedException(pcf_current_information);
}

void Socket::Listen(int32 backLog) {
  if (this->bound == false)
    throw SocketException((int32)SocketError::NotConnected, pcf_current_information);
  
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  Pcf::Os::Socket::Listen(this->socket, backLog);

  this->listening = true;
}

bool Socket::Poll(int32 microseconds, SelectMode mode) {
  int32 status = Pcf::Os::Socket::Poll(this->socket, microseconds, (int32)mode);

  if (status < 0)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
  
  return (status > 0);
}

int32 Socket::Select(IList<SharedPointer<Socket>>& checkRead, IList<SharedPointer<Socket>>& checkWrite, IList<SharedPointer<Socket>>& checkError, int32 microseconds) {
  if (checkRead.Count == 0 && checkWrite.Count == 0 && checkError.Count == 0)
    throw ArgumentNullException(pcf_current_information);

  int32 nbCheckRead = checkRead.Count;
  UniquePointer<void*[]> checkReadHandles(new void*[nbCheckRead]);
  for (int32 i = 0; i < nbCheckRead; i++)
    checkReadHandles[i] = (SharedPointer<Socket>(checkRead[i]))->socket;

  int32 nbCheckWrite = checkWrite.Count;
  UniquePointer<void*[]> checkWriteHandles(new void*[nbCheckWrite]);
  for (int32 i = 0; i < nbCheckWrite; i++)
    checkWriteHandles[i] = (SharedPointer<Socket>(checkWrite[i]))->socket;

  int32 nbCheckError = checkError.Count;
  UniquePointer<void*[]> checkErrorHandles(new void*[nbCheckError]);
  for (int32 i = 0; i < nbCheckError; i++)
    checkErrorHandles[i] = (SharedPointer<Socket>(checkError[i]))->socket;

  int32 status = Pcf::Os::Socket::Select(checkReadHandles.ToPointer(), nbCheckRead, checkWriteHandles.ToPointer(), nbCheckWrite, checkErrorHandles.ToPointer(), nbCheckError, microseconds);

  if (status < 0)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
  
  // List the null sockets
  List<SharedPointer<Socket>> readToRemove;
  for (int32 i = 0; i < nbCheckRead; i++)
    if (checkReadHandles[i] == null)
      readToRemove.Add(checkRead[i]);

  // Remove the null sockets
  for (SharedPointer<Socket> item : readToRemove)
    if (checkRead.Contains(item))
      checkRead.Remove(item);

  // List the null sockets
  List<SharedPointer<Socket>> writeToRemove;
  for (int32 i = 0; i < nbCheckWrite; i++)
    if (checkWriteHandles[i] == null)
      writeToRemove.Add(checkWrite[i]);

  // Remove the null sockets
  for (SharedPointer<Socket> item : writeToRemove)
    if (checkWrite.Contains(item))
      checkWrite.Remove(item);

  // List the null sockets
  List<SharedPointer<Socket>> errorToRemove;
  for (int32 i = 0; i < nbCheckError; i++)
    if (checkErrorHandles[i] == null)
      errorToRemove.Add(checkError[i]);

  // Remove the null sockets
  for (SharedPointer<Socket> item : errorToRemove)
    if (checkError.Contains(item))
      checkError.Remove(item);

  return status;
}

int32 Socket::Receive(Array<byte>& buffer) {
  return Receive((byte*)buffer.Data(), buffer.Length, 0, buffer.Length, SocketFlags::None);
}

int32 Socket::Receive(byte buffer[], int32 length) {
  return Receive(buffer, length, 0, length, SocketFlags::None);
}

int32 Socket::Receive(Array<byte>& buffer, SocketFlags socketFlags) {
  return Receive((byte*)buffer.Data(), buffer.Length, 0, buffer.Length, socketFlags);
}

int32 Socket::Receive(byte buffer[], int32 length, SocketFlags socketFlags) {
  return Receive(buffer, length, 0, length, socketFlags);
}

int32 Socket::Receive(Array<byte>& buffer, int32 size, SocketFlags socketFlags) {
  return Receive((byte*)buffer.Data(), buffer.Length, 0, size, socketFlags);
}

int32 Socket::Receive(byte buffer[], int32 length, int32 size, SocketFlags socketFlags) {
  return Receive(buffer, length, 0, size, socketFlags);
}

int32 Socket::Receive(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags) {
  return Receive((byte*)buffer.Data(), buffer.Length, offset, size, socketFlags);
}

int32 Socket::Receive(byte buffer[], int32 length, int32 offset, int32 size, SocketFlags socketFlags) {
  if (buffer == null)
    throw ArgumentNullException(pcf_current_information);

  if (offset < 0 || offset >= length || size < 0 || size > (length - offset))
    throw IndexOutOfRangeException(pcf_current_information);

  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);

  int32 nbrReceive = Pcf::Os::Socket::Receive(this->socket, buffer, size, (int32)socketFlags);

  if (nbrReceive == -1)
    throw SocketException(Pcf::Os::Socket::GetLastError(), pcf_current_information);

  return nbrReceive;
}

int32 Socket::ReceiveFrom(Array<byte>& buffer, IPEndPoint& endPoint) {
  return ReceiveFrom((byte*)buffer.Data(), buffer.Length, 0, buffer.Length, SocketFlags::None, endPoint);
}

int32 Socket::ReceiveFrom(byte buffer[], int32 length, IPEndPoint& endPoint) {
  return ReceiveFrom(buffer, length, 0, length, SocketFlags::None, endPoint);
}

int32 Socket::ReceiveFrom(Array<byte>& buffer, SocketFlags socketFlags, IPEndPoint& endPoint) {
  return ReceiveFrom((byte*)buffer.Data(), buffer.Length, 0, buffer.Length, socketFlags, endPoint);
}

int32 Socket::ReceiveFrom(byte buffer[], int32 length, SocketFlags socketFlags, IPEndPoint& endPoint) {
  return ReceiveFrom(buffer, length, 0, length, socketFlags, endPoint);
}

int32 Socket::ReceiveFrom(Array<byte>& buffer, int32 size, SocketFlags socketFlags, IPEndPoint& endPoint) {
  return ReceiveFrom((byte*)buffer.Data(), buffer.Length, 0, size, socketFlags, endPoint);
}

int32 Socket::ReceiveFrom(byte buffer[], int32 length, int32 size, SocketFlags socketFlags, IPEndPoint& endPoint) {
  return ReceiveFrom(buffer, length, 0, size, socketFlags, endPoint);
}

int32 Socket::ReceiveFrom(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, IPEndPoint& endPoint) {
  return ReceiveFrom((byte*)buffer.Data(), buffer.Length, offset, size, socketFlags, endPoint);
}

int32 Socket::ReceiveFrom(byte buffer[], int32 length, int32 offset, int32 size, SocketFlags socketFlags, IPEndPoint& endPoint) {
  if (buffer == null)
    throw ArgumentNullException(pcf_current_information);

  if (offset < 0 || offset >= length || size < 0 || size > (length - offset))
    throw IndexOutOfRangeException(pcf_current_information);

  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);

  int32 addressBytesLength = 32; // SocketAddress::defaultBufferSize
  UniquePointer<byte[]> addressBytes(new byte[addressBytesLength]);
  int32 nbrReceive = Pcf::Os::Socket::ReceiveFrom(this->socket, buffer, size, (int32)socketFlags, addressBytes.ToPointer(), &addressBytesLength);

  if (nbrReceive == -1)
    throw SocketException(Pcf::Os::Socket::GetLastError(), pcf_current_information);

  if (addressBytesLength >= 8)
    endPoint = endPoint.Create(SocketAddress(addressBytes.ToPointer(), addressBytesLength)).ChangeType<IPEndPoint>().ToObject();

  return nbrReceive;
}

int32 Socket::Send(const Array<byte>& buffer) {
  return Send((byte*)buffer.Data(), buffer.Length, 0, buffer.Length, SocketFlags::None);
}

int32 Socket::Send(byte buffer[], int32 length) {
  return Send(buffer, length, 0, length, SocketFlags::None);
}

int32 Socket::Send(const Array<byte>& buffer, SocketFlags socketFlags) {
  return Send((byte*)buffer.Data(), buffer.Length, 0, buffer.Length, socketFlags);
}

int32 Socket::Send(byte buffer[], int32 length, SocketFlags socketFlags) {
  return Send(buffer, length, 0, length, socketFlags);
}

int32 Socket::Send(const Array<byte>& buffer, int32 size, SocketFlags socketFlags) {
  return Send((byte*)buffer.Data(), buffer.Length, 0, size, socketFlags);
}

int32 Socket::Send(byte buffer[], int32 length, int32 size, SocketFlags socketFlags) {
  return Send(buffer, length, 0, size, socketFlags);
}

int32 Socket::Send(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags) {
  return Send((byte*)buffer.Data(), buffer.Length, offset, size, socketFlags);
}

int32 Socket::Send(byte buffer[], int32 length, int32 offset, int32 size, SocketFlags socketFlags) {
  if (buffer == null)
    throw ArgumentNullException(pcf_current_information);

  if (offset < 0 || offset >= length || size < 0 || size > (length - offset))
    throw IndexOutOfRangeException(pcf_current_information);

  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);

  int32 nbrSend = Pcf::Os::Socket::Send(this->socket, (buffer + offset), size, (int32)socketFlags);

  if (nbrSend == -1)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);  

  return nbrSend;
}

int32 Socket::SendTo(const Array<byte>& buffer, const IPEndPoint& endPoint) {
  return SendTo((byte*)buffer.Data(), buffer.Length, 0, buffer.Length, SocketFlags::None, endPoint);
}

int32 Socket::SendTo(byte buffer[], int32 length, const IPEndPoint& endPoint) {
  return SendTo(buffer, length, 0, length, SocketFlags::None, endPoint);
}

int32 Socket::SendTo(const Array<byte>& buffer, SocketFlags socketFlags, const IPEndPoint& endPoint) {
  return SendTo((byte*)buffer.Data(), buffer.Length, 0, buffer.Length, socketFlags, endPoint);
}

int32 Socket::SendTo(byte buffer[], int32 length, SocketFlags socketFlags, const IPEndPoint& endPoint) {
  return SendTo(buffer, length, 0, length, socketFlags, endPoint);
}

int32 Socket::SendTo(const Array<byte>& buffer, int32 size, SocketFlags socketFlags, const IPEndPoint& endPoint) {
  return SendTo((byte*)buffer.Data(), buffer.Length, 0, size, socketFlags, endPoint);
}

int32 Socket::SendTo(byte buffer[], int32 length, int32 size, SocketFlags socketFlags, const IPEndPoint& endPoint) {
  return SendTo(buffer, length, 0, size, socketFlags, endPoint);
}

int32 Socket::SendTo(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, const IPEndPoint& endPoint) {
  return SendTo((byte*)buffer.Data(), buffer.Length, offset, size, socketFlags, endPoint);
}

int32 Socket::SendTo(byte buffer[], int32 length, int32 offset, int32 size, SocketFlags socketFlags, const IPEndPoint& endPoint) {
  if (buffer == null)
    throw ArgumentNullException(pcf_current_information);

  if (offset < 0 || offset >= length || size < 0 || size > (length - offset))
    throw IndexOutOfRangeException(pcf_current_information);

  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);

  SocketAddress socketAddress = endPoint.Serialize();
  UniquePointer<byte[]> addressBytes(new byte[static_cast<int32>(socketAddress.Size())]);

  for (int32 i =0; i < socketAddress.Size; i++)
    addressBytes[i] = socketAddress[i];

  int32 nbrSend = Pcf::Os::Socket::SendTo(this->socket, buffer, size, (int32)socketFlags, addressBytes.ToPointer(), socketAddress.Size);

  if (nbrSend == -1)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);

  return nbrSend;
}

void Socket::SetBlocking(bool blocking) {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  if (Os::Socket::SetBlocking(this->socket, blocking) == -1)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);

  this->nonBlocking = !blocking;
}

void Socket::SetDontFragment(bool dontFragment) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::DontFragment, dontFragment);
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
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  int32 option = 0;
  if (optionValue)
    option = 0xFFFFFFFF;

  if (Os::Socket::SetSocketOption(this->socket, socketOptionLevel, socketOptionName, (int32 *)&option, sizeof(option)) == -1)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const Array<byte>& optionValue) {
  SetSocketOption(socketOptionLevel, socketOptionName, optionValue.Data(), optionValue.Length);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const byte optionValue[], int32 length) {
  if (optionValue == null)
    throw ArgumentNullException(pcf_current_information);
  
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  if (Os::Socket::SetSocketOption(this->socket, socketOptionLevel, socketOptionName, (byte*)optionValue, length) == -1)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, int32 optionValue) {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  if (Os::Socket::SetSocketOption(this->socket, socketOptionLevel, socketOptionName, (byte *)&optionValue, sizeof(optionValue)) == -1)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const object& optionValue) {
  if (this->socket == IntPtr::Zero)
    throw ObjectClosedException(pcf_current_information);
  
  if (is<MulticastOption>(optionValue)) {
    // Array<byte> optionValue;
    // [YFI] TODO
    // SetSocketOption(socketOptionLevel, socketOptionName, optionValue);
    throw NotImplementedException(pcf_current_information);
  } else if (is<LingerOption>(optionValue)) {
    // Array<byte> optionValue;
    // [YFI] TODO
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
  if (this->addressFamily != System::Net::Sockets::AddressFamily::InterNetwork && this->addressFamily != System::Net::Sockets::AddressFamily::InterNetworkV6)
    throw NotSupportedException(pcf_current_information);
  
  if (ttl < 0)
    throw IndexOutOfRangeException(pcf_current_information);
  
  SetSocketOption(SocketOptionLevel::IP, SocketOptionName::IpTimeToLive, ttl);
}

void Socket::Shutdown(SocketShutdown how) {
  if (this->socket == null)
    throw ObjectClosedException(pcf_current_information);
  
  if (Os::Socket::Shutdown(this->socket, Enum<SocketShutdown>::ToInt32(how)) != 0)
    throw SocketException(Os::Socket::GetLastError(), pcf_current_information);
}
