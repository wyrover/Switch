#include "../../../../../Includes/Pcf/System/Net/Sockets/UdpClient.h"
#include "../../../../../Includes/Pcf/System/Convert.h"
#include "../../../../../Includes/Pcf/System/NullReferenceException.h"
#include "../../../../../Includes/Pcf/System/Net/Dns.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/IPv6MulticastOption.h"
#include "../../../../../Includes/Pcf/System/Net/Sockets/MulticastOption.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

UdpClient::UdpClient() {
  this->client = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
}

UdpClient::UdpClient(AddressFamily addressFamily) {
  this->client = SharedPointer<Socket>::Create(addressFamily, SocketType::Dgram, ProtocolType::Udp);
}

UdpClient::UdpClient(int32 port) {
  this->client = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
  this->client->Bind(new IPEndPoint(IPAddress::Any, port));
}

UdpClient::UdpClient(SharedPointer<IPEndPoint> endPoint) {
  this->client = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
  this->client->Bind(endPoint.ChangeType<EndPoint>());
}

UdpClient::UdpClient(int32 port, AddressFamily addressFamily) {
  this->client = SharedPointer<Socket>::Create(addressFamily, SocketType::Dgram, ProtocolType::Udp);

  // Retrieve local IPAddress and use the 1st one
  this->client->Bind(new IPEndPoint(Dns::GetHostAddresses(Dns::GetHostName())[0], port));
}

UdpClient::UdpClient(const string& hostname, int32 port) {
  this->client = SharedPointer<Socket>::Create(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
  Connect(hostname, port);
}

int32 UdpClient::GetAvailable() const {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->Available();
}

SharedPointer<Socket> UdpClient::GetClient() {
  return this->client;
}

const SharedPointer<Socket> UdpClient::GetClient() const {
  return this->client;
}

bool UdpClient::GetConnected() const {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->Connected();
}

void UdpClient::SetClient(const SharedPointer<Socket>& client) {
  this->client = client;
}

bool UdpClient::GetDontFragment() const {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->DontFragment();
}

void UdpClient::SetDontFragment(bool dontFragment) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  this->client->SetDontFragment(dontFragment);
}

bool UdpClient::GetEnableBroadcast() const {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->EnableBroadcast();
}

void UdpClient::SetEnableBroadcast(bool enableBroadcast) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  this->client->SetEnableBroadcast(enableBroadcast);
}

bool UdpClient::GetExclusiveAddressUse() const
{
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->ExclusiveAddressUse();
}

void UdpClient::SetExclusiveAddressUse(bool exclusiveAddressUse) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  this->client->SetExclusiveAddressUse(exclusiveAddressUse);
}

bool UdpClient::GetMulticastLoopback() const {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->MulticastLoopback();
}

void UdpClient::SetMulticastLoopback(bool multicastLoopback) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  this->client->SetMulticastLoopback(multicastLoopback);
}

int32 UdpClient::GetTtl() const {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->Ttl();
}

void UdpClient::SetTtl(int32 ttl) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  this->client->SetTtl(ttl);
}

void UdpClient::Close() {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  this->client->Close();
}

void UdpClient::Connect(SharedPointer<IPEndPoint> endPoint) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);
  if (SharedPointer<IPEndPoint>::IsNullOrInvalid(endPoint))
    throw NullReferenceException(pcf_current_information);

  this->client->Connect(endPoint.ChangeType<EndPoint>());
}

void UdpClient::Connect(const IPAddress& ipAddress, int32 port) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);
  
  this->client->Connect(ipAddress, port);
}

void UdpClient::Connect(const string& hostname, int32 port) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  // Use the 1st IPAddress corresponding to the hostname
  this->client->Connect(Dns::GetHostAddresses(hostname)[0], port);
}

void UdpClient::JoinMulticastGroup(const IPAddress& multicastAddress) {
  if (this->client->AddressFamily() == AddressFamily::InterNetwork)
    this->client->SetSocketOption(SocketOptionLevel::IP, SocketOptionName::AddMembership, MulticastOption(multicastAddress));
  else
    this->client->SetSocketOption(SocketOptionLevel::IPv6, SocketOptionName::AddMembership, IPv6MulticastOption(multicastAddress));
}

void UdpClient::JoinMulticastGroup(int32 ifIndex, const IPAddress& multicastAddress) {
  if (this->client->AddressFamily() == AddressFamily::InterNetworkV6)
    this->client->SetSocketOption(SocketOptionLevel::IPv6, SocketOptionName::AddMembership, IPv6MulticastOption(multicastAddress, Convert::ToInt64(ifIndex)));
  else
    throw SocketException((int32)SocketError::OperationNotSupported, pcf_current_information);
}

void UdpClient::JoinMulticastGroup(const IPAddress& multicastAddress, int32 /*ttl*/) {
  
}

void UdpClient::JoinMulticastGroup(const IPAddress& multicastAddress, const IPAddress& localAddress) {
  
}

int32 UdpClient::Receive(Array<byte>& buffer, IPEndPoint& endPoint) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->ReceiveFrom(buffer, endPoint);
}

int32 UdpClient::Receive(byte buffer[], int32 bufferLength, IPEndPoint& endPoint) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);

  return this->client->ReceiveFrom(buffer, bufferLength, endPoint);
}

int32 UdpClient::Send(const Array<byte>& data) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);
  if (!GetConnected())
    throw SocketException((int32)SocketError::NotConnected, pcf_current_information);

  return this->client->Send(data);
}

int32 UdpClient::Send(byte buffer[], int32 bufferLength) {
  if (this->client.IsNull() || buffer == null)
    throw NullReferenceException(pcf_current_information);
  if (!GetConnected())
    throw SocketException((int32)SocketError::NotConnected, pcf_current_information);

  return this->client->Send(buffer, bufferLength);
}

int32 UdpClient::Send(const Array<byte>& data, const IPEndPoint& endPoint) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);
  if (GetConnected())
    throw InvalidOperationException(pcf_current_information);

  if (endPoint.Address() == IPAddress::Broadcast)
    this->client->SetEnableBroadcast(true);

  return this->client->SendTo(data, endPoint);
}

int32 UdpClient::Send(byte buffer[], int32 bufferLength, const IPEndPoint& endPoint) {
  if (this->client.IsNull() || buffer == null)
    throw NullReferenceException(pcf_current_information);
  if (GetConnected())
    throw InvalidOperationException(pcf_current_information);

  if (endPoint.Address() == IPAddress::Broadcast)
    this->client->SetEnableBroadcast(true);

  return this->client->SendTo(buffer, bufferLength, endPoint);
}

int32 UdpClient::Send(const Array<byte>& data, const string& hostname, int32 port) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);
  if (GetConnected())
    throw InvalidOperationException(pcf_current_information);

  if (hostname == IPAddress::Broadcast.ToString()) {
    // hostname can be 255.255.255.255
    this->client->SetEnableBroadcast(true);
    return this->client->SendTo(data, IPEndPoint(IPAddress::Broadcast, port));
  }
  else {
    // Use the 1st IPAddress corresponding to the hostname
    return this->client->SendTo(data, IPEndPoint(Dns::GetHostAddresses(hostname)[0], port));
  }
}

int32 UdpClient::Send(byte buffer[], int32 bufferLength, const string& hostname, int32 port) {
  if (this->client.IsNull())
    throw NullReferenceException(pcf_current_information);
  if (GetConnected())
    throw InvalidOperationException(pcf_current_information);

  if (hostname == IPAddress::Broadcast.ToString()) {
    // hostname can be 255.255.255.255
    this->client->SetEnableBroadcast(true);
    return this->client->SendTo(buffer, bufferLength, IPEndPoint(IPAddress::Broadcast, port));
  }
  else {
    // Use the 1st IPAddress corresponding to the hostname
    return this->client->SendTo(buffer, bufferLength, IPEndPoint(Dns::GetHostAddresses(hostname)[0], port));
  }
}

