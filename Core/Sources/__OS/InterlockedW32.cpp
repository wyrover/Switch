#if defined(_WIN32)

#include <windows.h>
#include "../../Includes/Pcf/Undef.h"

#include "CoreApi.h"

int32 __OS::CoreApi::Interlocked::Add(int32& location, int32 value) {
  InterlockedExchange((long*)&location, location + value);
  return location;
}

int64 __OS::CoreApi::Interlocked::Add(int64& location, int64 value) {
  InterlockedExchange64((long long*)&location, location + value);
  return location;
}

int32 __OS::CoreApi::Interlocked::CompareExchange(int32& location, int32 value, int32 comparand) {
  return InterlockedCompareExchange((long*)&location, value, comparand);
}

int64 __OS::CoreApi::Interlocked::CompareExchange(int64& location, int64 value, int64 comparand) {
  return InterlockedCompareExchange64((long long*)&location, value, comparand);
}

llong __OS::CoreApi::Interlocked::CompareExchange(llong& location, llong value, llong comparand) {
  return InterlockedCompareExchange64((long long*)&location, value, comparand);
}

void* __OS::CoreApi::Interlocked::CompareExchange(void*& location, void* value, void* comparand) {
  return (void*)InterlockedCompareExchange64((long long*)&location, (long long)value, (long long)comparand);
}

int32 __OS::CoreApi::Interlocked::Decrement(int32& location) {
  return InterlockedDecrement((long*)&location);
}

int64 __OS::CoreApi::Interlocked::Decrement(int64& location) {
  return InterlockedDecrement64((long long*)&location);
}

int32 __OS::CoreApi::Interlocked::Exchange(int32& location, int32 value) {
  return InterlockedExchange((long*)&location, value);
}

int64 __OS::CoreApi::Interlocked::Exchange(int64& location, int64 value) {
  return InterlockedExchange64((long long*)&location, value);
}

llong __OS::CoreApi::Interlocked::Exchange(llong& location, llong value) {
  return InterlockedExchange64((long long*)&location, value);
}

void* __OS::CoreApi::Interlocked::Exchange(void*& location, void* value) {
  return (void*)InterlockedExchange64((long long*)&location, (long long)value);
}

int32 __OS::CoreApi::Interlocked::Increment(int32& location) {
  return InterlockedIncrement((long*)&location);
}

int64 __OS::CoreApi::Interlocked::Increment(int64& location) {
  return InterlockedIncrement64((long long*)&location);
}

#endif
