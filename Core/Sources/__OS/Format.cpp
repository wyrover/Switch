#include "CoreApi.hpp"

const string& __OS::CoreApi::Format::Integer() {
#if defined(__linux__)
  static string format = "%ld";
#else
  static string format = "%lld";
#endif
  return format;
}

const string& __OS::CoreApi::Format::IntegerWithPrecision() {
#if defined(__linux__)
  static string format = "%0*ld";
#else
  static string format = "%0*lld";
#endif
  return format;
}

const string& __OS::CoreApi::Format::UnsignedInteger() {
#if defined(__linux__)
  static string format = "%lu";
#else
  static string format = "%llu";
#endif
  return format;
}

const string& __OS::CoreApi::Format::UnsignedIntegerWithPrecision() {
#if defined(__linux__)
  static string format = "%0*lu";
#else
  static string format = "%0*llu";
#endif
  return format;
}

const string& __OS::CoreApi::Format::HexadecimalWithPrecision() {
#if defined(__linux__)
  static string format = "%0*lX";
#else
  static string format = "%0*llX";
#endif
  return format;
}

const string& __OS::CoreApi::Format::LowerHexadecimalWithPrecision() {
#if defined(__linux__)
  static string format = "%0*lx";
#else
  static string format = "%0*llx";
#endif
  return format;
}
