#include <chrono>
#include "../../../../Includes/Switch/System/Diagnostics/Stopwatch.hpp"

using namespace System::Diagnostics;

property<int64, readonly> Stopwatch::Frequency {
  [] {return 10000000;}
};

property<bool, readonly> Stopwatch::IsHighResolution {
  [] {return true;}
};

int64 Stopwatch::GetTimestamp() {
  return std::chrono::high_resolution_clock::now().time_since_epoch().count()/100;
}
