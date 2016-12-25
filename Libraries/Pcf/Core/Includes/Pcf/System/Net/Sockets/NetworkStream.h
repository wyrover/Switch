/// @file
/// @brief Contains Pcf::System::Net::Sockets::NetworkStream class.
#pragma once

#include "../../../Types.h"
#include "../../../SharedPointer.h"
#include "../../IO/FileAccess.h"
#include "../../IO/Stream.h"
#include "Socket.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Provides the underlying stream of data for network access.
        /// @remarks The NetworkStream class provides methods for sending and receiving data over Stream sockets in blocking mode. For more information about blocking versus
        /// @remarks nonblocking Sockets, see pcf_using an Asynchronous Client Socket. You can use the NetworkStream class for both synchronous and asynchronous data transfer.
        /// @remarks For more information about synchronous and asynchronous communication, see Sockets::
        /// @remarks To create a NetworkStream, you must provide a connected Socket. You can also specify what FileAccess permission the NetworkStream has over the provided Socket.
        /// @remarks By default, closing the NetworkStream does not close the provided Socket. If you want the NetworkStream to have permission to close the provided Socket,
        /// @remarks you must specify true for the value of the ownsSocket parameter.Use the Write and Read methods for simple single thread synchronous blocking I/O.
        /// @remarks If you want to process your I/O using separate threads, consider using the BeginWrite and EndWrite methods, or the BeginRead and EndRead methods for communication.
        /// @remarks The NetworkStream does not support random access to the network data stream. The value of the CanSeek property, which indicates whether the stream supports seeking,
        /// @remarks is always false; reading the Position property, reading the Length property, or calling the Seek method will throw a NotSupportedException.
        /// @remarks Read and write operations can be performed simultaneously on an instance of the NetworkStream class without the need for synchronization.
        /// @remarks As long as there is one unique thread for the write operations and one unique thread for the read operations, there will be no cross-interference between
        /// @remarks read and write threads and no synchronization is required.
        class NetworkStream : public System::IO::Stream {
          bool GetCanRead() const override;
          bool GetCanSeek() const override;
          bool GetCanTimeout() const override;
          bool GetCanWrite() const override;
          int64 GetLength() const override;
          int64 GetPosition() const override;
          void SetPosition(int64 position) override;
          int32 GetReadTimeout() const override;
          void SetReadTimeout(int32 ReadTimeout) override;
          int32 GetWriteTimeout() const override;
          void SetWriteTimeout(int32 WriteTimeout) override;
          
        protected:
          /// @cond
          virtual bool GetDataAvailable() const;
          virtual bool GetReadable() const;
          virtual void SetReadable(bool readable);
          virtual bool GetWriteable() const;
          /// @endcond
          
        public:
          /// @brief Creates a new instance of the NetworkStream class for the specified Socket.
          /// @param socket The Socket that the NetworkStream will use to send and receive data.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectClosedException The Socket has been closed.
          /// @remarks The NetworkStream is created with read/write access to the specified Socket. The NetworkStream does not own the underlying Socket,
          /// @remarks so calling the Close method does not close the Socket.
          NetworkStream(const SharedPointer<Socket>& socket);

          /// @brief Creates a new instance of the NetworkStream class for the specified Socket.
          /// @param socket      The Socket that the NetworkStream will use to send and receive data.
          /// @param ownsSocket  Set to true to indicate that the NetworkStream will take ownership of the Socket; otherwise, false.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectClosedException The Socket has been closed.
          /// @remarks The NetworkStream is created with read/write access to the specified Socket. If the value of ownsSocket parameter is true,
          /// @remarks the NetworkStream takes ownership of the underlying Socket, and calling the Close method also closes the underlying Socket.
		      NetworkStream(const SharedPointer<Socket>& socket, bool ownsSocket);

          /// @brief Creates a new instance of the NetworkStream class for the specified Socket with the specified access rights.
          /// @param socket     The Socket that the NetworkStream will use to send and receive data.
          /// @param access     A bitwise combination of the FileAccess values that specify the type of access given to the NetworkStream over the provided Socket.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectClosedException The Socket has been closed.
          /// @remarks The NetworkStream is created with the specified access to the specified Socket. With this constructor, the NetworkStream does not own the underlying Socket,
          /// @remarks so calling the Close method does not close the underlying Socket.
          /// @remarks The access parameter sets the CanRead and CanWrite properties of the NetworkStream. If you specify Write, then the NetworkStream allows calls to the Write method.
          /// @remarks If you specify Read, then the NetworkStream allows calls to the Read method. If you specify ReadWrite, both method calls are allowed.
		      NetworkStream(const SharedPointer<Socket>& socket, System::IO::FileAccess access);

          /// @brief Creates a new instance of the NetworkStream class for the specified Socket with the specified access rights and the specified Socket ownership.
          /// @param socket      The Socket that the NetworkStream will use to send and receive data.
          /// @param access      A bitwise combination of the FileAccess values that specify the type of access given to the NetworkStream over the provided Socket.
          /// @param ownsSocket  Set to true to indicate that the NetworkStream will take ownership of the Socket; otherwise, false.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectClosedException The Socket has been closed.
          /// @remarks The NetworkStream is created with read/write access to the specified Socket. If the value of the ownsSocket parameter is true, the NetworkStream takes ownership
          /// @remarks of the underlying Socket, and calling the Close method also closes the underlying Socket.
          /// @remarks The access parameter sets the CanRead and CanWrite properties of the NetworkStream. If you specify Write, then the NetworkStream allows calls to the Write method.
          /// @remarks If you specify Read, then the NetworkStream allows calls to the Read method. If you specify ReadWrite, both method calls are allowed.
		      NetworkStream(const SharedPointer<Socket>& socket,System::IO::FileAccess access, bool ownsSocket);

          /// @brief Destroy instance of the class
          ~NetworkStream();

          /// @brief Closes the current stream and releases any resources (such as sockets and file handles) associated with the current stream.
          void Close() override;

          /// @brief Gets a value that indicates whether data is available on the NetworkStream to be read.
          /// @return true if data is available on the stream to be read; otherwise, false.
          Property<bool, ReadOnly> DataAvailable {
            pcf_get {return this->GetDataAvailable();}
          };

          /// @brief Gets or Sets a value that indicates whether the NetworkStream can be read.
          /// @param readable  true to indicate that the NetworkStream can be read; otherwise, false. The default value is true.
          /// @return true to indicate that the NetworkStream can be read; otherwise, false. The default value is true.
          Property<bool> Readable {
            pcf_get {return this->GetReadable();},
            pcf_set {this->SetReadable(value);}
          };

          /// @brief Reads data from the NetworkStream.
          /// @param buffer An array of bytes. When this method returns, the buffer contains the specified byte array with the values between offset and (offset + count - 1) replaced by the bytes read from the current source.
          /// @param BufferLength The length of buffer. (Total number of elements).
          /// @param offset The zero-based byte offset in buffer at which to begin storing the data read from the current stream.
          /// @param count The maximum number of bytes to be read from the current stream.
          /// @remarks This method reads data into the buffer parameter and returns the number of bytes successfully read. If no data is available for reading, the Read method returns 0.
          /// @remarks The Read operation reads as much data as is available, up to the number of bytes specified by the size parameter. If the remote host shuts down the connection,
          /// @remarks and all available data has been received, the Read method completes immediately and return zero bytes.
          /// @note Check to see if the NetworkStream is readable by calling the CanRead property. If you attempt to read from a NetworkStream that is not readable, you will get an IOException.
		      int32 Read(Array<byte>& buffer, int32 offset, int32 count) override;

          /// @brief Writes data to the NetworkStream.
          /// @param buffer An array of bytes. This method copies count bytes from buffer to the current stream.
          /// @param BufferLength The length of buffer. (Total number of elements).
          /// @param offset The zero-based byte offset in buffer at which to begin copying bytes to the current stream.
          /// @param count The number of bytes to be written to the current stream.
          /// @remarks The Write method starts at the specified offset and sends size bytes from the contents of buffer to the network. The Write method blocks until the requested number of bytes
          /// @remarks is sent or a SocketException is thrown. If you receive a SocketException, use the SocketException::ErrorCode property to obtain the specific error code, and refer to the
          /// @remarks Windows Sockets version 2 API error code documentation in MSDN for a detailed description of the error.
          /// @note Check to see if the NetworkStream is writable by accessing the CanWrite property. If you attempt to write to a NetworkStream that is not writable, you will get an IOException.
          /// @note If you receive an IOException, check the InnerException property to determine if it was caused by a SocketException.
		      void  Write(const Array<byte>& buffer, int32 offset, int32 count) override;

        protected:
          int64 Seek(int64, System::IO::SeekOrigin) override { return 0; }

          /// @brief When overridden in a derived class, reads a sequence of bytes to the current stream and advances the current position within this stream by the number of bytes read.
          /// @param Handle An Handle of bytes. This method copies count bytes from pointer to the current stream.
          /// @param count The number of bytes to be read to the current stream.
          /// @exception ArgumentNullException buffer is null.
          /// @exception ObjectClosedException The stream is closed.
          /// @exception NotSupportedException The stream does not support writing.
          /// @exception IO::IOException An I/O error occurs.
          int32 Read(void* Handle, int32 count);

          /// @brief When overridden in a derived class, writes a sequence of bytes to the current stream and advances the current position within this stream by the number of bytes written.
          /// @param Handle An Handle of bytes. This method copies count bytes from pointer to the current stream.
          /// @param count The number of bytes to be written to the current stream.
          /// @exception ArgumentNullException buffer is null.
          /// @exception ObjectClosedException The stream is closed.
          /// @exception NotSupportedException The stream does not support writing.
          /// @exception IO::IOException An I/O error occurs.
          void Write(const void* Handle, int32 count);

          /// @brief Gets the underlying Socket.
          /// @return A Socket that represents the underlying network connection.
          /// @remarks Classes deriving from NetworkStream can use this property to get the underlying Socket. Use the underlying Socket returned from the Socket property
          /// @remarks if you require access beyond that which NetworkStream provides.
          Property<SharedPointer<System::Net::Sockets::Socket>, ReadOnly> Socket {
            pcf_get {return this->streamSocket;}
          };

          /// @brief Gets a value that indicates whether the NetworkStream is writable.
          /// @param writeable  true if data can be written to the stream; otherwise, false. The default value is true.
          /// @remarks You must derive from the NetworkStream class to use the Writeable property. If Writeable is true, NetworkStream allows calls to the Write method.
          /// @remarks You can also determine whether a NetworkStream is writable by checking the publicly accessible CanWrite property.
          /// @remarks The Writeable property is set when the NetworkStream is initialized.
          Property<bool, ReadOnly> Writeable {
            pcf_get {return this->GetWriteable();}
          };

          /// @brief Internal use : init variables.
          void InitNetworkStream(const SharedPointer<System::Net::Sockets::Socket>& socket, System::IO::FileAccess Access);

          /// @brief Internal use : Call to end.
		      void Dispose(bool disposing);

        private:
          NetworkStream(const NetworkStream& networkStream) {}
          NetworkStream& operator =(const NetworkStream& networkStream) {return *this;}
		      
          SharedPointer<System::Net::Sockets::Socket> streamSocket;
		      bool readable = false;
          bool writeable = false;
		      bool ownsSocket = false;
		      bool cleanedUp = false;
        };
      }
    }
  }
}

using namespace Pcf;
