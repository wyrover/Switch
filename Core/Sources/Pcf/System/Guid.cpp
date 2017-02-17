#include "../../../Includes/Pcf/System/Guid.h"
#include "../../../Includes/Pcf/System/Random.h"
#include "../../__OS/CoreApi.h"

using namespace System;

Guid Guid::Empty;

namespace  {
  static Array<byte> MacAddressToBytes(const string& macAddress) {
    Array<string> substrings = macAddress.Split(':');
    Array<byte> bytes(substrings.Length);
    
    for(int i = 0; i < substrings.Length; i++)
      bytes[i] = Byte::Parse(substrings[i], 16);
    
    return bytes;
  }
}

Guid Guid::NewGuid() {
  // http://tools.ietf.org/html/rfc4122
  //
  // 0                   1                   2                   3
  // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |                          time_low                             |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |       time_mid                |         time_hi_and_version   |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |clk_seq_hi_res |  clk_seq_low  |         node (0-1)            |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |                         node (2-5)                            |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  //
  // 4.4 Algorithms for Creating a UUID from Truly Random or
  // Pseudo-Random Numbers
  //
  // The version 4 UUID is meant for generating UUIDs from truly-random or pseudo-random numbers.
  //
  // The algorithm is as follows:
  //  o  Set the two most significant bits (bits 6 and 7) of the clock_seq_hi_and_reserved to zero and one, respectively.
  //  o  Set the four most significant bits (bits 12 through 15) of the time_hi_and_version field to the 4-bit version number from Section 4.1.3.
  //  o  Set all the other bits to randomly (or pseudo-randomly) chosen values.
  static Random rand;
  static Array<byte> macAddress = MacAddressToBytes(__OS::CoreApi::Environment::GetMacAddress());
  Guid guid;
  
  rand.NextBytes(guid.data);
  guid.data[8] &= 0b11011111;
  guid.data[8] |= 0b01000000;
  guid.data[7] &= 0b00001111;
  guid.data[7] |= 0x01000000;
  Buffer::BlockCopy(macAddress, 0, guid.data, 10, macAddress.Length);

  return guid;
}
