#include <chrono>
#include "../../../../Includes/Pcf/System/Diagnostics/Stopwatch.h"

using namespace System::Diagnostics;

#if !_WIN32
constexpr int64 Stopwatch::Frequency;
constexpr bool Stopwatch::IsHighResolution;
#endif

int64 Stopwatch::GetTimestamp() {
  return std::chrono::high_resolution_clock::now().time_since_epoch().count()/100;
}
