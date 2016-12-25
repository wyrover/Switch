/// @file
/// @brief Contains Pcf::System::IO::BinaryWriter class.
#pragma once

#include "../../Types.h"
#include "../../SharedPointer.h"
#include "../Array.h"
#include "../Object.h"
#include "Stream.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Writes primitive types in binary to a stream and supports writing strings in a specific encoding.
      class BinaryWriter : public Object {
      public:
        /// @brief Initializes a new instance of the System::IO::BinaryWriter class.
        BinaryWriter();

        /// @brief Initializes a new instance of the System::IO::BinaryWriter class for the specified file on the specified stream pointer.
        /// @param stream The stream pointer to write to.
        /// @exception ArgumentException stream is null.
        /// @exception ArgumentException stream is not writable.
        BinaryWriter(Stream& stream);

        /// @cond
        virtual ~BinaryWriter();
        /// @endcond

        /// @brief Gets the underlying stream that interfaces with a backing store.
        /// @return The stream this StreamWriter is writing to.
        Property<Stream&, ReadOnly> BaseStream {
          pcf_get->Stream& {return this->GetBaseStream();}
        };

        /// @brief Closes the current BinaryWriter object and the underlying stream.
        /// @exception ObjectClosedException The stream is closed.
        /// @exception IO::IOException an error occurred while the file is being closed -or- An I/O error occurs.
        virtual void Close();

        /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying stream.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Flush();

        /// @brief Sets the position within the current stream.
        /// @param A byte offset relative to origin.
        /// @param A field of SeekOrigin indicating the reference point from which the new position is to be obtained.
        /// @return The position with the current stream.
        virtual int64 Seek(int32 offset, SeekOrigin origin);

        /// @brief Writes the specified bool value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(bool value);

        /// @brief Writes the specified byte value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(byte value);

        /// @brief Writes the specified byte Array value to the binary stream.
        /// @param value The byte Array to write
        /// @exception ArgumentNullException param is null.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(const Array<byte>& value);

        /// @brief Writes the specified Char value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(Char value);

        /// @brief Writes the specified Char Array value to the binary stream.
        /// @param value The Char Array to write
        /// @exception ArgumentNullException param is null.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(const Array<char32>& value);

        /// @brief Writes the specified double value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(double value);

        /// @brief Writes the specified int16 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(int16 value);

        /// @brief Writes the specified int32 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(int32 value);

        /// @brief Writes the specified int64 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(int64 value);

        /// @brief Writes the specified signed byte value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(sbyte value);

        /// @brief Writes the specified single value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(float value);

        /// @brief Writes a length-prefixed String to this stream in the current encoding of the BinaryWriter, and advances the current position of the stream in accordance with the encoding used and the specific characters being written to the stream.
        /// @param value The value to write
        /// @exception ArgumentNullException param is null.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(const String& value);
        /// @cond
        virtual void Write(const char value[]) {Write(string(value));}
        virtual void Write(const wchar value[]) {Write(string(value));}
        virtual void Write(const char16 value[]) {Write(string(value));}
        virtual void Write(const char32 value[]) {Write(string(value));}
        /// @endcond
        
        /// @brief Writes the specified uint16 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(uint16 value);

        /// @brief Writes the specified uint32 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(uint32 value);

        /// @brief Writes the specified uint64 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(uint64 value);
        
      protected:
        /// @brief Gets the underlying stream that interfaces with a backing store.
        /// @return The stream this StreamWriter is writing to.
        virtual Stream& GetBaseStream() const;
        
      private:
        Stream& stream;
      };
    }
  }
}

using namespace Pcf;
