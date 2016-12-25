#pragma once

#include <cstdint>
#include <string>
#include "../../../Includes/Pcf/Types.h"

/// @cond
namespace Pcf {
  namespace Os {
    class UnicodeEncodings {
    public:
      class ASCII {
      public:

      };

      class UTF8 {
      public:
        static byte GetFormat(byte b);
        static int GetNextCodeIndex(const std::string& str, int32 pos);
        static int GetPrevCodeIndex(const std::string& str, int32 pos);
        static uint32 GetCode(const byte* bytes, byte size);
        static uint32 GetLength(const std::string& str);
        static int GetLastIndex(const std::string& str);
        static int GetByteCount(uint32 code);
        static std::string Encode(uint32 code);
        static int Encode(uint32 code, byte bytes[]);
        static int Encode(uint32 code, std::string& utf8_encoding);
      };

      class UTF16 {
      public:
        static int GetByteCount(uint32 code);
        static int Encode(uint32 code, byte bytes[], bool big_endian);
        static int Decode(const byte* bytes, uint32 bytes_size, bool big_endian, uint32& code_point);
        static int GetLength(const byte* bytes, uint32 nb_bytes, bool big_endian);
      };

      class UTF32 {
      public:
        static void Encode(uint32 code, byte& b1, byte& b2, byte& b3, byte& b4, bool big_endian);
        static uint32 Decode(byte b1, byte b2, byte b3, byte b4, bool big_endian);
      };

      static uint32 to_lower(uint32 c);
      static uint32 to_upper(uint32 c);
      static uint32 to_title(uint32 c);
    };
  }
}

using namespace Pcf;
/// @endcond
