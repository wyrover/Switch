#pragma once

#include "../../../Includes/Pcf/Types.h"
#include "../../../Includes/Pcf/System/String.h"
#include "../../../Includes/Pcf/System/Net/Sockets/AddressFamily.h"
#include "../../../Includes/Pcf/System/Net/Sockets/ProtocolType.h"
#include "../../../Includes/Pcf/System/Net/Sockets/SocketOptionName.h"
#include "../../../Includes/Pcf/System/Net/Sockets/SocketOptionLevel.h"
#include "../../../Includes/Pcf/System/Net/Sockets/SocketType.h"

/// @cond
namespace Pcf {
  namespace Os {
    /// @brief Represents a Os object that provides the access socket API.
    /// This class cannot be inherited.
    /// Internal used only.
    class Socket final {
    public:
      /// @brief Convert System::Net::Sockets::AddressFamily value to corresponding native value.
      /// Internal used only.
      /// @param addressFamily System::Net::Sockets::AddressFamily value to convert
      /// @return Native value
      static int32 AddressFamilyToNative(System::Net::Sockets::AddressFamily addressFamily);

      /// @brief Convert native value value to corresponding System::Net::Sockets::AddressFamily.
      /// Internal used only.
      /// @param addressFamily Native value to convert
      /// @return System::Net::Sockets::AddressFamily value
      static System::Net::Sockets::AddressFamily NativeToAddressFamily(int32 addressFamily);

      /// @brief Accept a connection on a socket
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param socketAddress (like struct sockaddr)
      /// @param addressLength The address length
      /// @return int32 Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1 is returned
      static int32 Accept(void* handle, byte *socketAddress, int32* addressLength, void** socket);

      /// @brief Bind an address on a socket
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param socketAddress (like struct sockaddr)
      /// @param addressLength The address length
      /// @return int32 Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1 is returned
      static int32 Bind(void* handle, byte *socketAddress, int32 addressLength);

      /// @brief Close a socket connection.
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      static int32 Close(void* handle);

      /// @brief Initiate a connection on a socket
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param socketAddress (like struct sockaddr)
      /// @param addressLength The address length
      /// @return int32 Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1 is returned
      static int32 Connect(void* handle, byte *socketAddress, int32 addressLength);

      /// @brief Returns the error status for the last sockets operation that failed
      /// Internal used only.
      /// @return int32 Indicates the error code for this thread's last sockets operation that failed.
      static int32 GetLastError();

      static int32 GetAvailable(void* handle, int32* nbrBytesAvailable);

      /// @brief Gets a value that indicates whether the Socket is in blocking mode.
      /// @return Boolean true if the Socket will block; otherwise, false. The default is true
      static int32 GetSocketOption(void* handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32* optionLength);

      /// @brief Indicates whether the underlying operating system and network adaptors support Internet Protocol version 4 (IPv4).
      /// @return Boolean true if the operating system and network adaptors support the IPv4 protocol; otherwise, false.
      /// @remarks The majority of operating system may support both IPv4 and IPv6 protocols.
      static bool GetOSSupportsIPv4();

      /// @brief Indicates whether the underlying operating system and network adaptors support Internet Protocol version 6 (IPv6).
      /// @return Boolean true if the operating system and network adaptors support the IPv6 protocol; otherwise, false.
      /// @remarks The majority of operating system may support both IPv4 and IPv6 protocols.
      static bool GetOSSupportsIPv6();

      static int32 IoCtl(void* handle, int32 ioControl, byte* optionInValue, int32 optionInValueSize, byte* optionOutValue, int32 optionOutValueSize, int32* optionOutValueSizeReturned);

      /// @brief Places a Socket in a listening state.
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param backLog The maximum length of the pending connections queue.
      /// @return int32 Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1 is returned
      static int32 Listen(void* handle, int32 backLog);

      /// @brief open a socket using the specified address family, socket type and protocol.
      /// Internal used only.
      /// @param addressFamily Adress Family.
      /// @param socketType Socket Type
      /// @param protocolType Protocol Type
      /// @return void* Handle on a socket opened
      static int32 Open(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType, void** socket);

      /// @brief The Poll method will check the state of the Socket.
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param microseconds The time to wait for a response, in microseconds.
      /// @param mode One of following values :
      /// | Mode | Value      |
      /// |------|------------|
      /// | 1    | Mode Read  |
      /// | 2    | Mode Write |
      /// | 3    | Mode Error |
      /// @return The status of the Socket based on the polling mode value passed in the mode parameter.
      /// | Value |                                                   |
      /// |-------|---------------------------------------------------|
      /// | -1    | If an error occurred.                             |
      /// |  0    | If the time limit expires.                        |
      /// | >0    | The number of descriptors that are ready for I/O. |
      static int32 Poll(void* handle, int32 microseconds, int32 mode);

      /// @brief Determines the status of one or more sockets.
      /// Internal use only.
      /// @param checkRead : A list of Socket Handles to check for readability.
      /// @param nbCheckRead : The number of sockets in checkRead.
      /// @param checkWrite : A list of Socket Handles to check for writability.
      /// @param nbCheckWrite : The number of sockets in checkWrite.
      /// @param checkError : A list of Socket Handles to check for errors.
      /// @param nbCheckError : The number of sockets in checkError.
      /// @param microseconds : The time-out value, in microseconds. A -1 value indicates an infinite time-out.

      static int32 Select(void** checkRead, int32 nbCheckRead, void** checkWrite, int32 nbCheckWrite, void** checkError, int32 nbCheckError, int32 microseconds);

      /// @brief Send a message from a socket
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param buffer Byte Array to send
      /// @param bufferLength The Byte Array length
      /// @return int32 Upon successful completion, the number of bytes which were sent is returned.  Otherwise, -1 is returned
      static int32 Send(void* handle,  byte *buffer, int32 bufferLength, int32 flags);

      /// @brief Send a message from a socket
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param buffer Byte Array to send
      /// @param bufferLength The Byte Array length
      /// @param socketAddress (like struct sockaddr)
      /// @param addressLength The address length
      /// @return int32 Upon successful completion, the number of bytes which were sent is returned.  Otherwise, -1 is returned
      static int32 SendTo(void* handle,  byte *buffer, int32 bufferLength, int32 flags, byte *socketAddress, int32 addressLength);

      /// @brief Sets a value that indicates whether the Socket is in blocking mode.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param blocking true if the Socket will block; otherwise, false. The default is true
      static int32 SetBlocking(void* handle, bool blocking);

      static int32 SetSocketOption(void* handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32 optionLength);

      /// @brief Receive a message from a socket
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param buffer Byte Array into write
      /// @param bufferLength The Byte Array length
      /// @return int32 Upon successful completion, the number of bytes which were sent is returned.  Otherwise, -1 is returned
      static int32 Receive(void* handle, byte* buffer, int32 bufferLength, int32 flags);

      /// @brief Receive a message from a socket
      /// Internal used only.
      /// @param handle Handle on a socket (generate by Socket::Open)
      /// @param buffer Byte Array into write
      /// @param bufferLength The Byte Array length
      /// @param socketAddress (like struct sockaddr)
      /// @param addressLength The address length
      /// @return int32 Upon successful completion, the number of bytes which were sent is returned.  Otherwise, -1 is returned
      static int32 ReceiveFrom(void* handle,  byte* buffer, int32 bufferLength, int32 flags, byte *socketAddress, int32* addressLength);

      static int32 Shutdown(void* handle, int32 how);

    private:
      Socket() = delete;
    };
  }
}

using namespace Pcf;
/// @endcond
