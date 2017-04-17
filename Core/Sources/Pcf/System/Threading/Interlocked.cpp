#include "../../../../Includes/Pcf/System/Array.h"
#include "../../../../Includes/Pcf/System/Threading/Interlocked.h"
#include "../../../__OS/CoreApi.h"

using namespace System;
using namespace System::Threading;

std::mutex Interlocked::guard;

int32 Interlocked::Add(int32& location, int32 value) {
  return __OS::CoreApi::Interlocked::Add(location, value);
}

int64 Interlocked::Add(int64& location, int64 value) {
  return __OS::CoreApi::Interlocked::Add(location, value);
}

double Interlocked::CompareExchange(double& location, double value, double comparand) {
  double retValue = location;
  std::lock_guard<std::mutex> lock(guard);
  if (location == comparand)
    location = value;
  return retValue;
}

int32 Interlocked::CompareExchange(int32& location, int32 value, int32 comparand) {
  return __OS::CoreApi::Interlocked::CompareExchange(location, value, comparand);
}

int64 Interlocked::CompareExchange(int64& location, int64 value, int64 comparand) {
  return __OS::CoreApi::Interlocked::CompareExchange(location, value, comparand);
}

llong Interlocked::CompareExchange(llong& location, llong value, llong comparand) {
  return __OS::CoreApi::Interlocked::CompareExchange(location, value, comparand);
}

void* Interlocked::CompareExchange(void*& location, void* value, void* comparand) {
  return __OS::CoreApi::Interlocked::CompareExchange(location, value, comparand);
}

float Interlocked::CompareExchange(float& location, float value, float comparand) {
  float retValue = location;
  std::lock_guard<std::mutex> lock(guard);
  if (location == comparand)
    location = value;
  return retValue;
}

int32 Interlocked::Decrement(int32& location) {
  return __OS::CoreApi::Interlocked::Decrement(location);
}

int64 Interlocked::Decrement(int64& location) {
  return __OS::CoreApi::Interlocked::Decrement(location);
}

double Interlocked::Exchange(double& location, double value) {
  double original = location;
  std::lock_guard<std::mutex> lock(guard);
  location = value;
  return original;
}

int32 Interlocked::Exchange(int32& location, int32 value) {
  return __OS::CoreApi::Interlocked::Exchange(location, value);
}

int64 Interlocked::Exchange(int64& location, int64 value) {
  return __OS::CoreApi::Interlocked::Exchange(location, value);
}

llong Interlocked::Exchange(llong& location, llong value) {
  return __OS::CoreApi::Interlocked::Exchange(location, value);
}

void* Interlocked::Exchange(void*& location, void* value) {
  return __OS::CoreApi::Interlocked::Exchange(location, value);
}

float Interlocked::Exchange(float& location, float value) {
  float original = location;
  std::lock_guard<std::mutex> lock(guard);
  location = value;
  return original;
}

int32 Interlocked::Increment(int32& location) {
  return __OS::CoreApi::Interlocked::Increment(location);
}

int64 Interlocked::Increment(int64& location) {
  return __OS::CoreApi::Interlocked::Increment(location);
}

void Interlocked::MemoryBarrier() {
  std::atomic_thread_fence(std::memory_order::memory_order_acquire);
}

int64 Interlocked::Read(int64& location) {
  std::atomic<int64> atomic(location);
  return std::atomic_load(&atomic);
}
