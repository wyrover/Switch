#if defined(__linux__) || defined(__APPLE__)

#include "CoreApi.hpp"

int32 Native::CoreApi::Interlocked::Add(int32& location, int32 value) {
  __sync_fetch_and_add(&location, value);
  return location;
}

int64 Native::CoreApi::Interlocked::Add(int64& location, int64 value) {
  __sync_fetch_and_add(&location, value);
  return location;
}

int32 Native::CoreApi::Interlocked::CompareExchange(int32& location, int32 value, int32 comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

int64 Native::CoreApi::Interlocked::CompareExchange(int64& location, int64 value, int64 comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

llong Native::CoreApi::Interlocked::CompareExchange(llong& location, llong value, llong comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

void* Native::CoreApi::Interlocked::CompareExchange(void*& location, void* value, void* comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

int32 Native::CoreApi::Interlocked::Decrement(int32& location) {
  __sync_fetch_and_sub(&location, 1);
  return location;
}

int64 Native::CoreApi::Interlocked::Decrement(int64& location) {
  __sync_fetch_and_sub(&location, 1);
  return location;
}

int32 Native::CoreApi::Interlocked::Exchange(int32& location, int32 value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

int64 Native::CoreApi::Interlocked::Exchange(int64& location, int64 value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

llong Native::CoreApi::Interlocked::Exchange(llong& location, llong value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

void* Native::CoreApi::Interlocked::Exchange(void*& location, void* value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

int32 Native::CoreApi::Interlocked::Increment(int32& location) {
  __sync_fetch_and_add(&location, 1);
  return location;
}

int64 Native::CoreApi::Interlocked::Increment(int64& location) {
  __sync_fetch_and_add(&location, 1);
  return location;
}

#endif
