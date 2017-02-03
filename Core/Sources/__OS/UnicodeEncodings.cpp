#include <map>
#include <set>
#include <vector>

#include "CoreApi.h"

byte __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat(byte b) {
  if (b  < 0x80)          return 1;  // 0XXXXXXX
  if ((b & 0xE0) == 0xC0) return 2;  // 110XXXXX & 11100000 = 11000000
  if ((b & 0xF0) == 0xE0) return 3;  // 1110XXXX & 11110000 = 11100000
  if ((b & 0xF8) == 0xF0) return 4;  // 11110XXX & 11111000 = 11110000
  if ((b & 0xFC) == 0xF8) return 5;  // 111110XX & 11111000 = 11111000
  if ((b & 0xFE) == 0xFC) return 6;  // 1111110X & 11111100 = 11111100
  if ((b & 0xC0) == 0x80) return 0;  // 10XXXXXX & 11000000 = 10000000
  return 0xFF;
}

static bool readZeroFormats(const std::string& str, uint32 pos, byte nb) {
  for (uint32 i = pos+1; i < str.size() ; i += 1) {
    if (nb-- <= 0) return true;
    byte format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat((byte)str[i]);
    if (format != 0)
        return false;
  }  
  return nb == 0;
}

int __OS::CoreApi::UnicodeEncodings::UTF8::GetNextCodeIndex(const std::string& str, int32 pos) {
  for (uint32 i = pos+1; i < str.size() ; i += 1) {
    byte format = GetFormat((byte)str[i]);
    if (format != 0 && format != 0xFF && readZeroFormats(str,i,format-1))
      return (uint32)i;
  }
  return -1;
}

int __OS::CoreApi::UnicodeEncodings::UTF8::GetPrevCodeIndex(const std::string& str, int32 pos) {
  for (int32 i = static_cast<int32>(pos-1); i >= 0 ; i -= 1) {
    byte format = GetFormat((byte)str[i]);
    if (format != 0 && format != 0xFF)
      return i;
  }
  return -1;
}

uint32 __OS::CoreApi::UnicodeEncodings::UTF8::GetCode(const byte* bytes, byte size) {
  uint32 code = 0;
  byte offset = 0;
  byte rest = size - 1;
  for (int i = 0; i < size; i += 1) {
    if (i == 0)  { // head byte
      if (size == 1) 
        offset = 1;
      else           
        offset = size + 1;
    } else {
      offset = 2;
    }
    byte mask = 0xFF >> offset; 
    uint32 filtered = bytes[i] & mask;
    uint32 toSet =  filtered << (rest * 6);
    rest -= 1;
    code = code | toSet;
  }
  return code;
}

uint32 __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(const std::string& str) {
  uint32 len = 0;
  for (int i = __OS::CoreApi::UnicodeEncodings::UTF8::GetNextCodeIndex(str, -1); str.size() > 0 && i != -1; i = __OS::CoreApi::UnicodeEncodings::UTF8::GetNextCodeIndex(str, i))
    len += 1;
  return len;
}

int __OS::CoreApi::UnicodeEncodings::UTF8::GetLastIndex(const std::string& str) {
  return GetPrevCodeIndex(str,static_cast<int32>(str.size()));
}

std::string __OS::CoreApi::UnicodeEncodings::UTF8::Encode(uint32 code) {
  std::string utf8_string;
  Encode(code,utf8_string);
  return utf8_string;
}

int __OS::CoreApi::UnicodeEncodings::UTF8::GetByteCount(uint32 code) {
  if (!UnicodeCharacters::ValidateCodePoint(code))
    return 0;

  if (code < 0x80) return 1;
  if (code < 0x800) return 2;
  if (code < 0x10000) return 3;
  return 4;
}

int __OS::CoreApi::UnicodeEncodings::UTF8::Encode(uint32 code, byte bytes[]) {
  if (!UnicodeCharacters::ValidateCodePoint(code))
    return 0;

  if (code < 0x80) {
      bytes[0] = static_cast<byte>(code);
      return 1;
  } else if (code < 0x800) {
    bytes[0] = static_cast<byte>((code >> 6) | 0xc0);
    bytes[1] = static_cast<byte>((code & 0x3f) | 0x80);
    return 2;
  } else if (code < 0x10000) {
    bytes[0] = static_cast<byte>((code >> 12) | 0xe0);
    bytes[1] = static_cast<byte>(((code >> 6) & 0x3f) | 0x80);
    bytes[2] = static_cast<byte>((code & 0x3f) | 0x80);
    return 3;
  } else {
    bytes[0] = static_cast<byte>((code >> 18) | 0xf0);
    bytes[1] = static_cast<byte>(((code >> 12) & 0x3f) | 0x80);
    bytes[2] = static_cast<byte>(((code >> 6) & 0x3f) | 0x80);
    bytes[3] = static_cast<byte>((code & 0x3f) | 0x80);
    return 4;
  }  
}

int __OS::CoreApi::UnicodeEncodings::UTF8::Encode(uint32 code, std::string& utf8_encoding) {
  if (!UnicodeCharacters::ValidateCodePoint(code)) return 0;

  if (code < 0x80) {
      utf8_encoding.push_back(static_cast<byte>(code));
      return 1;
  } else if (code < 0x800) {
    utf8_encoding.push_back(static_cast<byte>((code >> 6) | 0xc0));
    utf8_encoding.push_back(static_cast<byte>((code & 0x3f) | 0x80));
    return 2;
  } else if (code < 0x10000) {
    utf8_encoding.push_back(static_cast<byte>((code >> 12) | 0xe0));
    utf8_encoding.push_back(static_cast<byte>(((code >> 6) & 0x3f) | 0x80));
    utf8_encoding.push_back(static_cast<byte>((code & 0x3f) | 0x80));
    return 3;
  } else { 
    utf8_encoding.push_back(static_cast<byte>((code >> 18) | 0xf0));
    utf8_encoding.push_back(static_cast<byte>(((code >> 12) & 0x3f) | 0x80));
    utf8_encoding.push_back(static_cast<byte>(((code >> 6) & 0x3f) | 0x80));
    utf8_encoding.push_back(static_cast<byte>((code & 0x3f) | 0x80));
    return 4;
  }  
}

int __OS::CoreApi::UnicodeEncodings::UTF16::GetByteCount(uint32 code) {
  if (!UnicodeCharacters::ValidateCodePoint(code)) return 0;
  if (code > 0xFFFF) return 4;
  return 2;
}

using BytePush = void (*)(uint16, byte& b1, byte& b2);

static void PushBigEndian(uint16 val, byte& b1, byte& b2) {
  b1 = static_cast<byte>(val >> 8);
  b2 = static_cast<byte>(val & 0xFF);
}

static void PushLittleEndian(uint16 val, byte& b1, byte& b2) {
  b1 = static_cast<byte>(val & 0xFF);
  b2 = static_cast<byte>(val >> 8);
}

int __OS::CoreApi::UnicodeEncodings::UTF16::Encode(uint32 code, byte bytes[], bool bigEndian ) {
  if (!UnicodeCharacters::ValidateCodePoint(code))
    return 0;

  BytePush pushFunc = bigEndian ? &PushBigEndian : &PushLittleEndian;

  if (code > 0xFFFF) {
    uint16 high = static_cast<uint16>((code >> 10)   + 0xD7C0u);
    uint16 low = static_cast<uint16>((code & 0x3ff) + 0xDC00u);
    pushFunc(high, bytes[0], bytes[1]);
    pushFunc(low, bytes[2], bytes[3]);
    return 4;
  }

  pushFunc(static_cast<uint16>(code), bytes[0], bytes[1]);
  return 2;
}

using MakeWord = uint16 (*)(byte, byte);

static uint16 MakeWordBigEndian(byte byte1, byte byte2) {
  uint16 word = static_cast<uint16>(byte1) << 8;
  return word + static_cast<uint16>(byte2);
}

static uint16 MakeWordLittleEndian(byte byte1, byte byte2) {
  uint16 word = static_cast<uint16>(byte2) << 8;
  return word + static_cast<uint16>(byte1);
}

int __OS::CoreApi::UnicodeEncodings::UTF16::Decode(const byte* bytes, uint32 size , bool bigEndian, uint32& codePoint) {
  if (size < 2) return 0;

  MakeWord makeWordFunc = bigEndian ? &MakeWordBigEndian : &MakeWordLittleEndian;

  uint16 word = makeWordFunc(bytes[0],bytes[1]);
  
  if (word >= 0xD800 && word <= 0xDBFF) { // 4 bytes code point
    if (size < 4) return 0;
    codePoint = ((word - 0xD800) << 10) + 0x10000;
    codePoint |= makeWordFunc(bytes[2],bytes[3]) - 0xdc00;
    return 4;
  } else {
    // 2 bytes code point
    codePoint = word;
    return 2;
  }
}

int __OS::CoreApi::UnicodeEncodings::UTF16::GetLength(const byte* bytes, uint32 nb_bytes, bool bigEndian) {
  MakeWord makeWordFunc = bigEndian ? &MakeWordBigEndian : &MakeWordLittleEndian;

  uint32 nb_code_points = 0;
  for (std::vector<byte>::size_type i = 0; i < nb_bytes; i += 2) {
    if ( i+1 >= nb_bytes )
      return nb_code_points;

    uint16 word = makeWordFunc(bytes[i],bytes[i+1]);
    if (word < 0xD800 || word > 0xDBFF)
        nb_code_points += 1;
  }

  return nb_code_points;
}

void __OS::CoreApi::UnicodeEncodings::UTF32::Encode(uint32 code, byte& b1, byte& b2, byte& b3, byte& b4, bool bigEndian) {
  if (bigEndian) {
    b1 = static_cast<byte>(code >> 24);
    b2 = static_cast<byte>(code >> 16);
    b3 = static_cast<byte>(code >> 8);
    b4 = static_cast<byte>(code);
  } else {
    b4 = static_cast<byte>(code >> 24);
    b3 = static_cast<byte>(code >> 16);
    b2 = static_cast<byte>(code >> 8);
    b1 = static_cast<byte>(code);
  }
}

uint32 __OS::CoreApi::UnicodeEncodings::UTF32::Decode(byte b1, byte b2, byte b3, byte b4, bool bigEndian) {
  if (bigEndian) {
    return 
      (static_cast<uint32>(b1) << 24) | 
      (static_cast<uint32>(b2) << 16) | 
      (static_cast<uint32>(b3) <<  8) | 
       static_cast<uint32>(b4);
  } else {
    return 
      (static_cast<uint32>(b4) << 24) |
      (static_cast<uint32>(b3) << 16) | 
      (static_cast<uint32>(b2) <<  8) | 
       static_cast<uint32>(b1);
  }
}

//_____________________________________________________________________________
//                                                           Unicode Characters

using unicodeMap = std::map<uint32, uint32>;
static unicodeMap unicode_to_lower;
static unicodeMap unicode_to_upper;
static unicodeMap unicode_to_title;
static std::set<uint32> unicode_is_digit;
static std::set<uint32> unicode_is_alpha;
static std::set<uint32> unicode_is_punctuation;

namespace {
  static void InitUnicode() {
    if (unicode_to_lower.size() > 0)
      return;
    
    #include "toUpper.map"
    #include "toLower.map"
    #include "toTitle.map"
  }
}

uint32 __OS::CoreApi::UnicodeEncodings::to_lower(uint32 c) {
  InitUnicode();
  unicodeMap::iterator it = unicode_to_lower.find(c);
  if (it == unicode_to_lower.end())
    return c;
  return it->second;
}

uint32 __OS::CoreApi::UnicodeEncodings::to_upper(uint32 c) {
  InitUnicode();
  unicodeMap::iterator it = unicode_to_upper.find(c);
  if (it == unicode_to_upper.end())
    return c;
  return it->second;
}

uint32 __OS::CoreApi::UnicodeEncodings::to_title(uint32 c) {
  InitUnicode();
  unicodeMap::iterator it = unicode_to_title.find(c);
  if (it == unicode_to_title.end())
    return c;
  return it->second;
}
