#if defined(__linux__) || defined(__APPLE__)

#include <cxxabi.h>
#include "CoreApi.h"

string __OS::CoreApi::Type::Demangle(const string &name) {
  int32 status = 0;
  return UniquePointer<char[]>(abi::__cxa_demangle(name.Data(), 0, 0, &status)).ToPointer();
}

#endif
