#include <cstdarg>
#include <cstdlib>
#include <ctime>

#include "../../../Includes/Pcf/System/Random.h"
#include "../../../Includes/Pcf/System/Convert.h"
#include "../../../Includes/Pcf/System/DateTime.h"
#include "../../../Includes/Pcf/System/Math.h"

using namespace System;

Random::Random() {
  srand((uint32_t)time(null));
}

Random::Random(int32 seed) {
  srand(Math::Abs(seed));
}

int32 Random::Next() const {
  return Next(0, Int32::MaxValue);
}

int32 Random::Next(int32 maxValue) const {
  return Next(0, maxValue);
}

int32 Random::Next(int32 minValue, int32 maxValue) const {
  if (minValue > maxValue)
    throw ArgumentOutOfRangeException(pcf_current_information);

  if (maxValue == minValue)
    return minValue;
  
  return minValue + Convert::ToInt32(Sample() * RAND_MAX) % ((maxValue-1) - minValue + 1);
}

void Random::NextBytes(Array<byte>& buffer) const {
  for (int32 i = 0; i < buffer.Length; i++)
    buffer[i] = Convert::ToByte(Next(0, Byte::MaxValue+1));
}

double Random::NextDouble() const {
  return Sample();
}

double Random::Sample() const {
  return Convert::ToDouble(rand()) / RAND_MAX;
}

