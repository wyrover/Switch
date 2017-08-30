#include "../../../Includes/Pcf/System/BitConverter.hpp"

using namespace System;

Property<bool, ReadOnly> BitConverter::IsLittleEndian {
  [] {
    int32 endian = 1;
    return *(sbyte *)&endian == 1;
  }
};
