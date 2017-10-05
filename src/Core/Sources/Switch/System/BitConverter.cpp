#include "../../../Includes/Switch/System/BitConverter.hpp"

using namespace System;

_property<bool, _readonly> BitConverter::IsLittleEndian {
  [] {
    int32 endian = 1;
    return *(sbyte *)&endian == 1;
  }
};
