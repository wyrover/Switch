#include "../../../Includes/Pcf/System/SafeMath.h"
#include "../../../Includes/Pcf/System/Array.h"
#include "../../../Includes/Pcf/System/Int64.h"
#include "../../../Includes/Pcf/System/OverflowException.h"

using namespace System;

uint64 SafeMath::Add(uint64 x, uint64 y) {
  if (x == 0) return y;
  if (y == 0) return x;

  uint64 value = x + y;
  if (value < x)
    throw OverflowException(pcf_current_information);
  return value;
}

uint64 SafeMath::Mul(uint64 x, uint64 y) {
  if (x == 0 || y == 0) return 0;
  uint64 value = 0;
  while (y-- > 0)
    value = Add(value, x);
  return value;
}

// only positive powers !!!
uint64 SafeMath::PositivePower(uint32 x, uint32 p) {
  uint64 value = 1;
  while (p-- > 0) value = Mul(value,x);
  return value;
}

uint64 SafeMath::ShiftToUInt64(int64 x) {
  if (x >= 0) return static_cast<uint64>(x) + static_cast<uint64>(Int64::MaxValue) + 1;
  else return static_cast<uint64>(x + Int64::MaxValue);
}