#include <chrono>
#include "../../../../include/Switch/System/Diagnostics/Stopwatch.hpp"

using namespace System::Diagnostics;

_property<int64, _readonly> Stopwatch::Frequency {
  [] {return 10000000;}
};

_property<bool, _readonly> Stopwatch::IsHighResolution {
  [] {return true;}
};

int64 Stopwatch::GetTimestamp() {
  return std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 100;
}
