/// @file
/// @brief Contains Pcf::System::Text::ANSIEncoding class.
#pragma once

#include "Encoding.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Text namespace contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats string objects without creating intermediate instances of string.
    namespace Text {
      /// @brief Represents an ANSI character encoding of Unicode characters (This is a generic class representing various code pages).
      class ANSIEncoding : public Encoding {
      public:
        /// @brief Initializes a new instance of the System::Text::ANSIEncoding class.
        /// @param codePage The code page of the desired Unicode code page.
        ANSIEncoding(int32 codePage);
        
        /// @brief Gets a value indicating whether the current encoding uses single-byte code points.
        /// @return This property is always true.
        virtual bool IsSingleByte() const { return true; }
        
        using Encoding::GetByteCount;
        
        /// @brief Calculates the number of bytes produced by encoding a character.
        /// @param c The character to encode.
        /// @return The number of bytes produced by encoding the specified character.
        virtual int32 GetByteCount(char32 c) const;
        
        using Encoding::GetBytes;
        using Encoding::GetCharCount;
        
        /// @brief Calculates the number of characters produced by decoding a sequence of bytes from the specified byte array.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @param index The index of the first byte to decode.
        /// @param count The number of bytes to decode.
        /// @return The number of characters produced by decoding the specified sequence of bytes.
        /// @exception System::ArgumentNullException bytes is null.
        /// @exception System::ArgumentOutOfRangeException index or count is less than zero. -or-  index and count do not denote a valid range in bytes. -or-  The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        virtual int32 GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const;
        
        using Encoding::GetChars;
        
        /// @brief Calculates the maximum number of bytes produced by encoding the specified number of characters.
        /// @param charCount The number of characters to encode.
        /// @return The maximum number of bytes produced by encoding the specified number of characters.
        /// @exception System::ArgumentOutOfRangeException charCount is less than zero. -or-  The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        virtual int32 GetMaxByteCount(int32 charCount) const;
        
        /// @brief Calculates the maximum number of characters produced by decoding the specified number of bytes.
        /// @param byteCount The number of bytes to decode.
        /// @return The maximum number of characters produced by decoding the specified number of bytes.
        /// @exception System::ArgumentOutOfRangeException byteCount is less than zero. -or- The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        virtual int32 GetMaxCharCount(int32 byteCount) const;
        
        virtual bool Equals(const object& obj) const;
        
        /// @brief Converts the given code point into its representing byte.
        /// @param codePoint The codePoint to encode.
        /// @return The byte encoding the given codePoint or the value of Unknown().
        byte GetByte(uint32 codePoint) const;
        
        /// @brief Converts the given byte into its corresponding code point.
        /// @param b The byte to decode.
        /// @return The code point corresponding to the byte.
        uint32 GetCodePoint(byte b) const;
        
        class Decoder : public Encoding::Decoder {
        public:
          Decoder(int32 cp) : Encoding::Decoder(), codePage(cp) { }
          Decoder(const Decoder& b);
          Decoder& operator =(const Decoder& b);
          virtual void Add(byte b);
          virtual void Reset();
          virtual String ToString() const;
          virtual char32 GetCodePoint(byte b) = 0;
          
        protected:
          static char32 GetCodePoint(byte b, const std::vector<char32>& codePoints, uint32 unchanged);
          
        private:
          int32 codePage;
        };
        
        class Encoder : public Encoding::Encoder {
        public:
          Encoder(int32 cp);
          Encoder(const Encoder& e);
          Encoder& operator =(const Encoder& b);
          virtual int32 GetNbBytes(char32) const;
          virtual void Encode(char32 codePoint, byte* bytes) const;
          virtual String ToString() const;
          virtual byte GetByte(char32 cp) = 0;
          
        private:
          int32 codePage;
        };
        
        /// @cond
      private:
        ANSIEncoding();
        ANSIEncoding(const ANSIEncoding& encoding);
        virtual ANSIEncoding& operator =(const ANSIEncoding& encoding);
        virtual Encoding& operator =(const Encoding& encoding);
        /// @endcond
      };
      
      //_______________________________________________________________________
      //                                                            CodePage437
      
      class CodePage437Encoding : public ANSIEncoding {
      public:
        CodePage437Encoding();
        virtual UniquePointer<Encoding::Decoder> CreateDecoder() const;
        virtual UniquePointer<Encoding::Encoder> CreateEncoder() const;
        using ANSIEncoding::GetBytes;
        virtual int32 GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 byteIndex) const;
        
        class Decoder : public ANSIEncoding::Decoder {
        public:
          Decoder() : ANSIEncoding::Decoder(437) { }
          virtual char32 GetCodePoint(byte b);
        };
        
        class Encoder : public ANSIEncoding::Encoder {
        public:
          Encoder() : ANSIEncoding::Encoder(437) { }
          virtual byte GetByte(char32 cp);
        };
      };
      
      //_______________________________________________________________________
      //                                                          CodePage28591
      
      class CodePage28591Encoding : public ANSIEncoding {
      public:
        CodePage28591Encoding();
        virtual UniquePointer<Encoding::Decoder> CreateDecoder() const;
        virtual UniquePointer<Encoding::Encoder> CreateEncoder() const;
        using ANSIEncoding::GetBytes;
        virtual int32 GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 byteIndex) const;
        
        class Decoder : public ANSIEncoding::Decoder {
        public:
          Decoder() : ANSIEncoding::Decoder(28591) { }
          virtual char32 GetCodePoint(byte b);
        };
        
        class Encoder : public ANSIEncoding::Encoder {
        public:
          Encoder() : ANSIEncoding::Encoder(28591) { }
          virtual byte GetByte(char32 cp);
        };
      };
      
      //_______________________________________________________________________
      //                                                          CodePage28592
      
      class CodePage28592Encoding : public ANSIEncoding {
      public:
        CodePage28592Encoding();
        virtual UniquePointer<Encoding::Decoder> CreateDecoder() const;
        virtual UniquePointer<Encoding::Encoder> CreateEncoder() const;
        using ANSIEncoding::GetBytes;
        virtual int32 GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 byteIndex) const;
        
        class Decoder : public ANSIEncoding::Decoder {
        public:
          Decoder() : ANSIEncoding::Decoder(28592) { }
          virtual char32 GetCodePoint(byte b);
        };
        
        class Encoder : public ANSIEncoding::Encoder {
        public:
          Encoder() : ANSIEncoding::Encoder(28592) { }
          virtual byte GetByte(char32 cp);
        };
      };
      
    }
  }
}

using namespace Pcf;
