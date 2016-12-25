#if defined(_WIN32)
#pragma warning(disable:4201)
#include <windows.h>
#pragma warning(default:4201)
#endif

#include "../../../../Includes/Pcf/System/Array.h"
#include "../../../../Includes/Pcf/System/Threading/Interlocked.h"

using namespace System;
using namespace System::Threading;

std::mutex Interlocked::guard;

int32 Interlocked::Add(int32& location, int32 value) {
#if _WIN32
  InterlockedExchange((long*)&location, location + value);
#else
  __sync_fetch_and_add(&location, value);
#endif
  return location;
}

int64 Interlocked::Add(int64& location, int64 value) {
#if _WIN32
  InterlockedExchange64((long long*)&location, location + value);
  return location;
#else
  __sync_fetch_and_add(&location, value);
#endif
  return location;
}

double Interlocked::CompareExchange(double& location, double value, double comparand) {
  double retValue = location;
  std::lock_guard<std::mutex> lock(guard);
  if (location == comparand)
    location = value;
  return retValue;
}

int32 Interlocked::CompareExchange(int32& location, int32 value, int32 comparand) {
#if _WIN32
  return InterlockedCompareExchange((long*)&location, value, comparand);
#else
  return __sync_val_compare_and_swap(&location, comparand, value);
#endif
}

int64 Interlocked::CompareExchange(int64& location, int64 value, int64 comparand) {
#if _WIN32
  return InterlockedCompareExchange64((long long*)&location, value, comparand);
#else
  return __sync_val_compare_and_swap(&location, comparand, value);
#endif
}

#if __APPLE__
intptr Interlocked::CompareExchange(intptr& location, intptr value, intptr comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}
#endif

void* Interlocked::CompareExchange(void*& location, void* value, void* comparand) {
#if _WIN32
  return (void*)InterlockedCompareExchange64((long long*)&location, (long long)value, (long long)comparand);
#else
  return __sync_val_compare_and_swap(&location, comparand, value);
#endif
}

float Interlocked::CompareExchange(float& location, float value, float comparand) {
  float retValue = location;
  std::lock_guard<std::mutex> lock(guard);
  if (location == comparand)
    location = value;
  return retValue;
}

int32 Interlocked::Decrement(int32& location) {
#if _WIN32
  return InterlockedDecrement((long*)&location);
#else
  __sync_fetch_and_sub(&location, 1);
  return location;
#endif
}

int64 Interlocked::Decrement(int64& location) {
#if _WIN32
  return InterlockedDecrement64((long long*)&location);
#else
  __sync_fetch_and_sub(&location, 1);
  return location;
#endif
}

double Interlocked::Exchange(double& location, double value) {
  double original = location;
  std::lock_guard<std::mutex> lock(guard);
  location = value;
  return original;
}

int32 Interlocked::Exchange(int32& location, int32 value) {
#if _WIN32
  return InterlockedExchange((long*)&location, value);
#else
  return __sync_val_compare_and_swap(&location, location, value);
#endif
}

int64 Interlocked::Exchange(int64& location, int64 value) {
#if _WIN32
  return InterlockedExchange64((long long*)&location, value);
#else
  return __sync_val_compare_and_swap(&location, location, value);
#endif
}

#if __APPLE__
intptr Interlocked::Exchange(intptr& location, intptr value) {
  return __sync_val_compare_and_swap(&location, location, value);
}
#endif

void* Interlocked::Exchange(void*& location, void* value) {
#if _WIN32
  return (void*)InterlockedExchange64((long long*)&location, (long long)value);
#else
  return __sync_val_compare_and_swap(&location, location, value);
#endif
}

float Interlocked::Exchange(float& location, float value) {
  float original = location;
  std::lock_guard<std::mutex> lock(guard);
  location = value;
  return original;
}

int32 Interlocked::Increment(int32& location) {
#if _WIN32
  return InterlockedIncrement((long*)&location);
#else
  __sync_fetch_and_add(&location, 1);
  return location;
#endif
}

int64 Interlocked::Increment(int64& location) {
#if _WIN32
  return InterlockedIncrement64((long long*)&location);
#else
  __sync_fetch_and_add(&location, 1);
  return location;
#endif
}

void Interlocked::MemoryBarrier() {
  std::atomic_thread_fence(std::memory_order::memory_order_acquire);
}

int64 Interlocked::Read(int64& location) {
  std::atomic<int64> atomic(location);
  return std::atomic_load(&atomic);
}

