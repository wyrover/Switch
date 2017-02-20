/// @file
/// @brief Contains Pcf::System::Text::UnicodeEncoding class.
#pragma once

#include "Encoding.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
   /// @brief The System::Text namespace contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats string objects without creating intermediate instances of string.
    namespace Text {
     /// @brief Represents an UTF16 character encoding of Unicode characters.
      class pcf_public UnicodeEncoding : public Encoding {
      public:
       /// @brief Initializes a new instance of the System::Text::UnicodeEncoding class.
        UnicodeEncoding();

       /// @brief Initializes a new instance of the System::Text::UnicodeEncoding class. Parameters specify whether to use the big endian byte order and whether to provide a Unicode byte order mark.
       /// @param bigEndian true to use the big endian byte order (most significant byte first), or false to use the little endian byte order (least significant byte first).
        UnicodeEncoding(bool bigEndian);

       /// @brief Initializes a new instance of the System::Text::UnicodeEncoding class. Parameters specify whether to use the big endian byte order and whether to provide a Unicode byte order mark.
       /// @param bigEndian true to use the big endian byte order (most significant byte first), or false to use the little endian byte order (least significant byte first).
       /// @param shouldEmitPreamble true to specify that a Unicode byte order mark is provided; otherwise, false.
        UnicodeEncoding(bool bigEndian, bool shouldEmitPreamble);

       /// @brief Initializes a new copy of an instance of the System::Text::UnicodeEncoding class.
       /// @param encoding The source encoding.
       /// @exception System::ArgumentNullException encoding is null.
        UnicodeEncoding(const UnicodeEncoding& encoding);

       /// @brief Changes the current instance to match an instance of the System::Text::UnicodeEncoding class.
       /// @param encoding The source encoding.
       /// @exception System::ArgumentNullException encoding is null.
        virtual UnicodeEncoding& operator =(const UnicodeEncoding& encoding);

       /// @brief Gets a value indicating whether the current encoding uses single-byte code points.
       /// @return This property is always false.
        virtual bool IsSingleByte() const { return false; }

        using Encoding::GetByteCount;

       /// @brief Calculates the number of bytes produced by encoding a character.
       /// @param c The character to encode.
       /// @return The number of bytes produced by encoding the specified character.
        virtual int32 GetByteCount(char32 c) const;

        using Encoding::GetBytes;

        virtual int32 GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 byteIndex) const;

        using Encoding::GetCharCount;

       /// @brief Calculates the number of characters produced by decoding a sequence of bytes from the specified byte array.
       /// @param bytes The byte array containing the sequence of bytes to decode.
       /// @param index The index of the first byte to decode.
       /// @param count The number of bytes to decode.
       /// @return The number of characters produced by decoding the specified sequence of bytes.
       /// @exception System::ArgumentNullException bytes is null.
       /// @exception System::ArgumentOutOfRangeException index or count is less than zero. -or- index and count do not denote a valid range in bytes. -or-  The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        virtual int32 GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const;

        using Encoding::GetChars;

       /// @brief Calculates the maximum number of bytes produced by encoding the specified number of characters.
       /// @param charCount The number of characters to encode.
        /// @return The maximum number of bytes produced by encoding the specified number of characters.
       /// @exception System::ArgumentOutOfRangeException charCount is less than zero. -or- The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        virtual int32 GetMaxByteCount(int32 charCount) const;

       /// @brief Calculates the maximum number of characters produced by decoding the specified number of bytes.
       /// @param byteCount The number of bytes to decode.
       /// @return The maximum number of characters produced by decoding the specified number of bytes.
       /// @exception System::ArgumentOutOfRangeException byteCount is less than zero. -or- The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        virtual int32 GetMaxCharCount(int32 byteCount) const;

       /// @brief Returns a Unicode byte order mark encoded in UTF-16 format, if the constructor for this instance requests a byte order mark.
       /// @return A byte array containing the Unicode byte order mark, if the constructor for this instance requests a byte order mark. Otherwise, this method returns a byte array of length zero.
        virtual Array<byte> GetPreamble() const;

       /// @brief Determines whether the specified System::Object is equal to the current instance.
       /// @param value The System::Object to compare with the current instance.
       /// @return true if value is an instance of System::Text::Encoding and is equal to the current instance; otherwise, false.
        bool Equals(const object& obj) const noexcept;

        virtual UniquePointer<Decoder> CreateDecoder() const;
        virtual UniquePointer<Encoder> CreateEncoder() const;

        class Encoder : public Encoding::Encoder {
        public:
          Encoder(bool bigE) : Encoding::Encoder() { this->bigEndian = bigE; }
          Encoder(const Encoder& e) : Encoding::Encoder(e) { this->bigEndian = e.bigEndian; }

          Encoder& operator =(const Encoder& b);
          virtual int32 GetNbBytes(char32 c) const;
          virtual void Encode(char32 c, byte bytes[]) const;
          virtual String ToString() const;

        private:
          bool bigEndian;
        };

        class Decoder : public Encoding::Decoder {
        public:
          Decoder(bool be) : Encoding::Decoder(), bigEndian(be) {}
          Decoder(const Decoder& b) : Encoding::Decoder(b), bigEndian(b.bigEndian) {}

          Decoder& operator =(const Decoder& b);
          virtual void Add(byte b);
          virtual char32 GetCodePoint() const { return codePoint; }
          virtual String ToString() const;

        private:
          bool bigEndian;
        };

        /// @cond
      private:
        bool shouldEmitPreamble;
        bool bigEndian;
        /// @endcond
      };
    }
  }
}

using namespace Pcf;
