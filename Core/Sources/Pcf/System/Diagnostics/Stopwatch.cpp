#include <chrono>
#include "../../../../Includes/Pcf/System/Diagnostics/Stopwatch.h"

using namespace System::Diagnostics;

Property<int64, ReadOnly> Stopwatch::Frequency {
  [] {return 10000000;}
};

Property<bool, ReadOnly> Stopwatch::IsHighResolution {
  [] {return true;}
};

int64 Stopwatch::GetTimestamp() {
  return std::chrono::high_resolution_clock::now().time_since_epoch().count()/100;
}
