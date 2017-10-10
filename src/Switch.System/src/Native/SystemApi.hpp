#pragma once

#include <Switch/Static.hpp>
#include <Switch/Types.hpp>
#include "../../include/Switch/System/Net/Sockets/AddressFamily.hpp"
#include "../../include/Switch/System/Net/Sockets/ProtocolType.hpp"
#include "../../include/Switch/System/Net/Sockets/SocketOptionName.hpp"
#include "../../include/Switch/System/Net/Sockets/SocketOptionLevel.hpp"
#include "../../include/Switch/System/Net/Sockets/SocketType.hpp"
#include "../../include/Switch/System/Net/IPAddress.hpp"

namespace Native {
  class SystemApi _static {
  public:
    class Dns _static {
    public:
      static void Destroy(intptr host);
      static void EndHostent();
      static intptr GetHostByAddress(const string& hostAddress, System::Net::Sockets::AddressFamily hostAddressType);
      static intptr GetHostByName(const string& hostName);
      static System::Array<string> GetAliases(intptr host);
      static System::Array<System::Net::IPAddress> GetAddresses(intptr host);
      static string GetHostName(intptr host);
      static int GetHostName(string& hostName);
      static void SetHostent(bool stayOpen);
    };
    
    class Socket _static {
    public:
      static int32 AddressFamilyToNative(System::Net::Sockets::AddressFamily addressFamily);
      static System::Net::Sockets::AddressFamily NativeToAddressFamily(int32 addressFamily);
      static int32 Accept(intptr handle, byte* socketAddress, int32 addressLength, intptr* socket);
      static int32 Bind(intptr handle, byte* socketAddress, int32 addressLength);
      static int32 Close(intptr handle);
      static int32 Connect(intptr handle, byte* socketAddress, int32 addressLength);
      static int32 GetLastError();
      static int32 GetAvailable(intptr handle, int32* nbrBytesAvailable);
      static int32 GetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32* optionLength);
      static bool GetOSSupportsIPv4();
      static bool GetOSSupportsIPv6();
      static int32 IoCtl(intptr handle, int32 ioControl, byte* optionInValue, int32 optionInValueSize, byte* optionOutValue, int32 optionOutValueSize, int32* optionOutValueSizeReturned);
      static int32 Listen(intptr handle, int32 backLog);
      static int32 Open(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType, intptr* socket);
      static int32 Poll(intptr handle, int32 microseconds, int32 mode);
      static int32 Select(intptr* checkRead, int32 nbCheckRead, intptr* checkWrite, int32 nbCheckWrite, intptr* checkError, int32 nbCheckError, int32 microseconds);
      static int32 Send(intptr handle, byte* buffer, int32 bufferLength, int32 flags);
      static int32 SendTo(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength);
      static int32 SetBlocking(intptr handle, bool blocking);
      static int32 SetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32 optionLength);
      static int32 Receive(intptr handle, byte* buffer, int32 bufferLength, int32 flags);
      static int32 ReceiveFrom(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength);
      static int32 Shutdown(intptr handle, int32 how);
    };
  };
}
