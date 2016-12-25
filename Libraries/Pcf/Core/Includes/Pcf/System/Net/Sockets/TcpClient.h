/// @file
/// @brief Contains Pcf::System::Net::Sockets::TcpClient class.
#pragma once

#include "../../NotImplementedException.h"
#include "../../NullReferenceException.h"
#include "Socket.h"
#include "NetworkStream.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
       /// @brief Provides client connections for TCP network services.
       /// @remarks The TcpClient class provides simple methods for connecting, sending, and receiving stream data over a network in synchronous blocking mode.
       /// @remarks In order for TcpClient to connect and exchange data, a TcpListener or Socket created with the TCP ProtocolType must be listening for incoming
       /// @remarks connection requests. You can connect to this listener in one of the following two ways:
       /// @remarks Create a TcpClient and call one of the three available Connect methods.
       /// @remarks Create a TcpClient using the host name and port number of the remote host. This constructor will automatically attempt a connection.
       /// @note If you want to send connectionless datagrams in synchronous blocking mode, use the UdpClient class.
       /// @note To send and receive data, use the GetStream method to obtain a NetworkStream. Call the Write and Read methods of the NetworkStream
       /// @note to send and receive data with the remote host. Use the Close method to release all resources associated with the TcpClient.
        class TcpClient : public Object {
        public:
          /// @brief Initializes a new instance of the TcpClient class
          /// This constructor creates a new TcpClient and allows the underlying service provider to assign the most appropriate local IP address
          /// and port number. You must first call the Connect method before sending and receiving data.
          TcpClient();

          /// @brief Initializes a new instance of the TcpClient class with the specified family.
          /// @param addressFamily one of the AddressFamily values that specifies the addressing scheme of the socket.
          /// @exception ArgumentException The family parameter is not equal to AddressFamily.InterNetwork or The family parameter is not equal to AddressFamily.InterNetworkV6.
          TcpClient(AddressFamily addressFamily);

          /// @brief Initializes a new instance of the TcpClient class and BINDS it to the specified local endpoint.
          /// @param endPoint The IPEndPoint to which you bind the TCP Socket.
          /// @exception ArgumentNullException The localEP parameter is null.
          TcpClient(const SharedPointer<IPEndPoint>& endPoint);

          /// @brief Initializes a new instance of the TcpClient class and connects to the specified port on the specified host.
          /// @param hostname The DNS name of the remote host to which you intend to connect.
          /// @param port The port number of the remote host to which you intend to connect.
          /// @exception ArgumentNullException The localEP parameter is null.
          /// @exception ArgumentOutOfRangeException The port parameter is not between MinPort and MaxPort.
          /// @exception SocketException An error occurred when accessing the socket.
          TcpClient(const String& hostname, int32 port);

          /// @brief Initializes a new instance of the TcpClient class
          /// @param acceptedSocket the socket to use
          /// @exception SocketException An error occurred when accessing the socket.
		      TcpClient(const SharedPointer<Socket>& acceptedSocket);

           /// @cond
          ~TcpClient();
          /// @endcond

          /// @brief Gets a value that indicates whether a connection has been made.
          /// @return bool true if the connection has been made; otherwise, false.
          bool GetActive() const;

           /// @brief Gets the amount of data that has been received from the network and is available to be read.
           /// @return int32 The number of bytes of data received from the network and available to be read.
           /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks Available is a way to determine whether data is queued for reading. If data is available, call Read to get the data.
           /// @remarks The available data is the total amount of data queued in the network buffer for reading. If no data is queued in the network buffer, Available returns 0.
           /// @remarks If the remote host shuts down or closes the connection, Available may throw a SocketException. If you receive a SocketException, use SocketException.ErrorCode to obtain the specific error code.
          int32 GetAvailable() const;

           /// @brief Gets the underlying network Socket
           /// @return The underlying network Socket
           /// @remarks TcpClient creates a Socket to send and receive data over a network. Classes deriving from TcpClient can use this property to get or set this Socket.
           /// @remarks Use the underlying Socket returned from Client if you require access beyond that which TcpClient provides.
           /// @remarks You can also use Client to set the underlying Socket to an existing Socket. This might be useful if you want to take advantage of the simplicity
           /// @remarks of TcpClient using a pre-existing Socket.
          SharedPointer<Socket> GetClient();
          const SharedPointer<Socket> GetClient() const;

           /// @brief Sets the underlying network Socket
           /// @param client the socket to use
          void SetClient(const SharedPointer<Socket>& client);

           /// @brief Gets a value that indicates whether a Socket is connected to a remote host as of the last Send or Receive operation.
           ///@return bool true if the Socket was connected to a remote resource as of the most recent operation; otherwise, false.
           /// @remarks The Connected property gets the connection state of the Client socket as of the last I/O operation. When it returns false,
           /// @remarks the Client socket was either never connected, or is no longer connected.Because the Connected property only reflects the state
           /// @remarks of the connection as of the most recent operation, you should attempt to send or receive a message to determine the current state.
           /// @remarks After the message send fails, this property no longer returns true. Note that this behavior is by design.
           /// @remarks You cannot reliably test the state of the connection because, in the time between the test and a send/receive,
           /// @remarks the connection could have been lost. Your code should assume the socket is connected, and gracefully handle failed transmissions.
          bool GetConnected() const;

           /// @brief Gets a bool value that specifies whether the TcpClient allows only one client to use a port.
           ///@return bool true if the TcpClient allows only one client to use a specific port; otherwise, false.
           ///@exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
           ///@exception ObjectClosedException The Socket has been closed.
           /// @remarks By default, multiple clients can use a specific port; however, only one of the clients can perform operations on the network traffic sent to the port.
           /// @remarks You can use the ExclusiveAddressUse property to prevent multiple clients from using a specific port.
           /// @remarks This property must be set before the underlying socket is bound to a client port. If you call Connect, BeginConnect, TcpClient(IPEndPoint),
           /// @remarks or TcpClient(string, int32), the client port is bound as a side effect of the method, and you cannot subsequently set the ExclusiveAddressUse property
          bool GetExclusiveAddressUse() const;

           /// @brief Sets a bool value that specifies whether the TcpClient allows only one client to use a port.
           /// @param exclusiveAddressUse A bool, true if the TcpClient allows only one client to use a specific port; otherwise, false.
           /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks By default, multiple clients can use a specific port; however, only one of the clients can perform operations on the network traffic sent to the port.
           /// @remarks You can use the ExclusiveAddressUse property to prevent multiple clients from using a specific port.
           /// @remarks This property must be set before the underlying socket is bound to a client port. If you call Connect, BeginConnect, TcpClient(IPEndPoint),
           /// @remarks or TcpClient(string, int32), the client port is bound as a side effect of the method, and you cannot subsequently set the ExclusiveAddressUse property
           /// @note Not available on MacOs/Linux/Android
          void SetExclusiveAddressUse(bool exclusiveAddressUse);

           /// @brief sets information about the linger state of the associated socket.
           /// @param lingerOption A LingerOption that specifies how to linger while closing a socket.
           /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks The LingerState property changes the way Close method behaves. This property when set modifies the conditions under which the connection can be reset by Winsock. Connection resets can still occur based on the IP protocol behavior.
           /// @remarks This property controls the length of time that the TCP connection will remain open after a call to Close when data remains to be sent. When you call the Write method, data is placed in the outgoing network buffer. This property can be used to ensure that this data is sent to the remote host before the Close method drops the connection.
           /// @remarks To enable lingering, create a LingerOption instance containing the desired values, and set the LingerState property to this instance.
           /// @remarks The following table describes the behavior of the Close method for the possible values of the Enabled property and the LingerTime property stored in the LingerState property.
           /// | Enabled                             | LingerTime                                 | Behavior                                                                                                                          |
           /// |-------------------------------------|--------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|
           /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data until the default IP protocol time-out expires.                                                     |
           /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
           /// | true (enabled)                      | A zero timeout.                            | Discards any pending data and Winsock resets the connection.                                                                      |
           /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application.
           /// @remarks This is the default behavior for a socket when the LingerState property is not set.
           /// @remarks When the LingerTime property stored in the LingerState property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
           /// @note Not available on MacOs/Linux/Android
          void SetLingerState(const LingerOption& lingerOption);

           /// @brief Gets a value that specifies whether the Socket will delay closing a socket in an attempt to send all pending data.
           /// @return A LingerOption that specifies how to linger while closing a socket.
           /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks The LingerState property changes the way Close method behaves. This property when set modifies the conditions under which the connection can be reset by Winsock. Connection resets can still occur based on the IP protocol behavior.
           /// @remarks This property controls the length of time that the TCP connection will remain open after a call to Close when data remains to be sent. When you call the Write method, data is placed in the outgoing network buffer. This property can be used to ensure that this data is sent to the remote host before the Close method drops the connection.
           /// @remarks To enable lingering, create a LingerOption instance containing the desired values, and set the LingerState property to this instance.
           /// @remarks The following table describes the behavior of the Close method for the possible values of the Enabled property and the LingerTime property stored in the LingerState property.
           /// | Enabled                             | LingerTime                                 | Behavior                                                                                                                          |
           /// |-------------------------------------|--------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|
           /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data until the default IP protocol time-out expires.                                                     |
           /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
           /// | true (enabled)                      | A zero timeout.                            | Discards any pending data and Winsock resets the connection.                                                                      |
           /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application.
           /// @remarks This is the default behavior for a socket when the LingerState property is not set.
           /// @remarks When the LingerTime property stored in the LingerState property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
           /// @note Not available on MacOs/Linux/Android
          LingerOption GetLingerState() const;

           /// @brief Sets a bool value that specifies whether the stream Socket is using the Nagle algorithm.
           /// @param noDelay bool true if the delay is disabled, otherwise false. The default value is false.
           /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks When noDelay is false, a TcpClient does not send a packet over the network until it has collected a significant amount of outgoing data.
           /// @remarks Because of the amount of overhead in a TCP segment, sending small amounts of data is inefficient. However, situations do exist where you need
           /// @remarks to send very small amounts of data or expect immediate responses from each packet you send. Your decision should weigh the relative importance of
           /// @remarks network efficiency versus application requirements.
           /// @note Not available on MacOs/Linux/Android
          void SetNoDelay(bool noDelay);

           /// @brief Gets a bool value that specifies whether the stream Socket is using the Nagle algorithm.
           /// @return bool false if the Socket uses the Nagle algorithm; otherwise, true. The default is false.
           /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks When noDelay is false, a TcpClient does not send a packet over the network until it has collected a significant amount of outgoing data.
           /// @remarks Because of the amount of overhead in a TCP segment, sending small amounts of data is inefficient. However, situations do exist where you need
           /// @remarks to send very small amounts of data or expect immediate responses from each packet you send. Your decision should weigh the relative importance of
           /// @remarks network efficiency versus application requirements.
           /// @note Not available on MacOs/Linux/Android
          bool GetNoDelay() const;

           /// @brief Gets the size of the receive buffer.
           /// @return int32 The size of the receive buffer, in bytes. The default value is 8192 bytes.
           /// @exception An error occurred when setting the buffer size.
           /// @remarks The receiveBufferSize property gets or sets the number of bytes that you are expecting to store in the receive buffer for each read operation.
           /// @remarks This property actually manipulates the network buffer space allocated for receiving incoming data.
           /// @remarks Your network buffer should be at least as large as your application buffer to ensure that the desired data will be available when you call the NetworkStream::Read
           /// @remarks method. Use the receiveBufferSize property to set this size. If your application will be receiving bulk data, you should pass the Read method a very large application buffer.
           /// @remarks If the network buffer is smaller than the amount of data you request in the Read method, you will not be able to retrieve the desired amount of data in one read operation.
           /// @remarks This incurs the overhead of additional calls to the Read method.
           /// @note Not available on MacOs/Linux/Android
          int32 GetReceiveBufferSize() const;

           /// @brief Sets the size of the receive buffer.
           /// @param receiveBufferSize The size of the receive buffer, in bytes.
           /// @exception An error occurred when setting the buffer size.
           /// @remarks The receiveBufferSize property gets or sets the number of bytes that you are expecting to store in the receive buffer for each read operation.
           /// @remarks This property actually manipulates the network buffer space allocated for receiving incoming data.
           /// @remarks Your network buffer should be at least as large as your application buffer to ensure that the desired data will be available when you call the NetworkStream::Read
           /// @remarks method. Use the receiveBufferSize property to set this size. If your application will be receiving bulk data, you should pass the Read method a very large application buffer.
           /// @remarks If the network buffer is smaller than the amount of data you request in the Read method, you will not be able to retrieve the desired amount of data in one read operation.
           /// @remarks This incurs the overhead of additional calls to the Read method.
           /// @note Not available on MacOs/Linux/Android
          void SetReceiveBufferSize(int32 receiveBufferSize);

           /// @brief Gets the amount of time a TcpClient will wait to receive data once a read operation is initiated.
           /// @return int32 The time-out value of the connection in milliseconds. The default value is 0.
           /// @remarks The receiveTimeout property determines the amount of time that the Read method will block until it is able to receive data.
           /// @remarks This time is measured in milliseconds. If the time-out expires before Read successfully completes, TcpClient throws a IOException. There is no time-out by default.
          int32 GetReceiveTimeout() const;

           /// @brief Sets the amount of time a TcpClient will wait to receive data once a read operation is initiated.
           /// @param receiveTimeout The time-out value of the connection in milliseconds. The default value is 0.
           /// @remarks The receiveTimeout property determines the amount of time that the Read method will block until it is able to receive data.
           /// @remarks This time is measured in milliseconds. If the time-out expires before Read successfully completes, TcpClient throws a IOException. There is no time-out by default.
           /// @note Not available on MacOs/Linux/Android
          void SetReceiveTimeout(int32 receiveTimeout);

           /// @brief Gets the size of the send buffer.
           /// @return int32  The size of the send buffer, in bytes. The default value is 8192 bytes.
           /// @remarks The sendBufferSize property gets or sets the number of bytes that you are expecting to send in each call to the NetworkStream.Write method.
           /// @remarks This property actually manipulates the network buffer space allocated for send operation.
           /// @remarks Your network buffer should be at least as large as your application buffer to ensure that the desired data will be stored and sent in one operation.
           /// @remarks Use the sendBufferSize property to set this size. If your application will be sending bulk data, you should pass the Write method a very large application buffer.
           /// @remarks If the network buffer is smaller than the amount of data you provide the Write method, several network send operations will be performed for every call you make
           /// @remarks to the Write method. You can achieve greater data throughput by ensuring that your network buffer is at least as large as your application buffer.
           /// @note Not available on MacOs/Linux/Android
          int32 GetSendBufferSize() const;

           /// @brief Sets the size of the send buffer.
           /// @param sendBufferSize The size of the send buffer, in bytes. The default value is 8192 bytes.
           /// @remarks The sendBufferSize property gets or sets the number of bytes that you are expecting to send in each call to the NetworkStream.Write method.
           /// @remarks This property actually manipulates the network buffer space allocated for send operation.
           /// @remarks Your network buffer should be at least as large as your application buffer to ensure that the desired data will be stored and sent in one operation.
           /// @remarks Use the sendBufferSize property to set this size. If your application will be sending bulk data, you should pass the Write method a very large application buffer.
           /// @remarks If the network buffer is smaller than the amount of data you provide the Write method, several network send operations will be performed for every call you make
           /// @remarks to the Write method. You can achieve greater data throughput by ensuring that your network buffer is at least as large as your application buffer.
           /// @note Not available on MacOs/Linux/Android
          void SetSendBufferSize(int32 sendBufferSize);

           /// @brief Gets the amount of time a TcpClient will wait for a send operation to complete successfully.
           /// @return int32 The send time-out value, in milliseconds. The default is 0.
           /// @remarks The SendTimeout property determines the amount of time that the Send method will block until it is able to return successfully.
           /// @remarks This time is measured in milliseconds. After you call the Write method, the underlying Socket returns the number of bytes actually sent to the host.
           /// @remarks The SendTimeout property determines the amount of time a TcpClient will wait before receiving the number of bytes returned.
           /// @remarks If the time-out expires before the Send method successfully completes, TcpClient will throw a SocketException. There is no time-out by default.
           /// @note Not available on MacOs/Linux/Android
          int32 GetSendTimeout() const;

           /// @brief Sets the amount of time a TcpClient will wait for a send operation to complete successfully.
           /// @param sendTimeout The send time-out value, in milliseconds. The default is 0.
           /// @remarks The SendTimeout property determines the amount of time that the Send method will block until it is able to return successfully.
           /// @remarks This time is measured in milliseconds. After you call the Write method, the underlying Socket returns the number of bytes actually sent to the host.
           /// @remarks The SendTimeout property determines the amount of time a TcpClient will wait before receiving the number of bytes returned.
           /// @remarks If the time-out expires before the Send method successfully completes, TcpClient will throw a SocketException. There is no time-out by default.
           /// @note Not available on MacOs/Linux/Android
          void SetSendTimeout(int32 sendTimeout);

           /// @brief Disposes this TcpClient instance and requests that the underlying TCP connection be closed.
           /// @remarks The Close method marks the instance as disposed and requests that the associated Socket close the TCP connection. Based on the LingerState property,
           /// @remarks the TCP connection may stay open for some time after the Close method is called when data remains to be sent. There is no notification provided when
           /// @remarks the underlying connection has completed closing.
           /// @remarks Calling this method will eventually result in the close of the associated Socket and will also close the associated NetworkStream that is used to send
           /// @remarks and receive data if one was created.
          void Close();

           /// @brief Connects the client to a remote TCP host using the specified remote network endpoint.
           /// @param endPoint The IPEndPoint to which you intend to connect.
           /// @exception ArgumentNullException The localEP parameter is null.
           /// @exception SocketException An error occurred when accessing the socket.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks Call this method to establish a synchronous remote host connection to the specified IPEndPoint. Before you call Connect you must create an instance of
           /// @remarks the IPEndPoint class using an IP address and a port number. Use this IPEndPoint as the remoteEP parameter. The Connect method will block until it either
           /// @remarks connects or fails. After connecting with the remote host, use the GetStream method to obtain the underlying NetworkStream. Use this NetworkStream to send and receive data.
          void Connect(const SharedPointer<IPEndPoint>& endPoint);

           /// @brief Connects the client to a remote TCP host using the specified IP address and port number.
           /// @param ipAddress The IPAddress of the remote host to which you intend to send data
           /// @param port The port number to which you intend send data
           /// @exception ArgumentOutOfRangeException The port parameter is not between MinPort and MaxPort.
           /// @exception SocketException An error occurred when accessing the socket.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks Call this method to establish a synchronous remote host connection to the specified IPAddress and port number.
           /// @remarks The Connect method will block until it either connects or fails.
           /// @remarks After connecting with the remote host, use the GetStream method to obtain the underlying NetworkStream.
           /// @remarks Use this NetworkStream to send and receive data.
          void Connect(const IPAddress& ipAddress, int32 port);

           /// @brief Connects the client to the specified port on the specified host.
           /// @param hostname The DNS name of the remote host to which you intend to connect.
           /// @param port The port number of the remote host to which you intend to connect.
           /// @exception ArgumentOutOfRangeException The port parameter is not between MinPort and MaxPort.
           /// @exception SocketException An error occurred when accessing the socket.
           /// @exception ObjectClosedException The Socket has been closed.
           /// @remarks Call this method to establish a synchronous remote host connection to the specified host name and port number. The Connect method will block until it either connects or fails.
           /// @remarks After connecting with the remote host, use the GetStream method to obtain the underlying NetworkStream.
           /// @remarks Use this NetworkStream to send and receive data.
           /// @remarks If IPv6 is enabled and the Connect(string, int32) method is called to connect to a host that resolves to both IPv6 and IPv4 addresses, the connection to the IPv6 address will be
           /// @remarks attempted first before the IPv4 address. This may have the effect of delaying the time to establish the connection if the host is not listening on the IPv6 address.
          void Connect(const String& hostname, int32 port);

           /// @brief Returns the NetworkStream used to send and receive data.
           /// @return The underlying NetworkStream.
           /// @remarks GetStream returns a NetworkStream that you can use to send and receive data. The NetworkStream class inherits from the Stream class, which provides a rich collection
           /// @remarks of methods and properties used to facilitate network communications.You must call the Connect method first, or the GetStream method will throw an InvalidOperationException.
           /// @remarks After you have obtained the NetworkStream, call the Write method to send data to the remote host. Call the Read method to receive data arriving from the remote host.
           /// @remarks Both of these methods block until the specified operation is performed. You can avoid blocking on a read operation by checking the DataAvailable property.
           /// @remarks A true value means that data has arrived from the remote host and is available for reading. In this case, Read is guaranteed to complete immediately.
           /// @remarks If the remote host has shutdown its connection, Read will immediately return with zero bytes.
           /// @note You must close the NetworkStream when you are through sending and receiving data. Closing TcpClient does not release the NetworkStream.
          SharedPointer<NetworkStream> GetStream();


        private:
		      SharedPointer<Socket> clientSocket;
		      bool active;
		      SharedPointer<NetworkStream> dataStream;
        };
      }
    }
  }
}

using namespace Pcf;
