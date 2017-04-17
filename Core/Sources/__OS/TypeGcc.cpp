#if defined(__linux__) || defined(__APPLE__)

#include <cxxabi.h>
#include "CoreApi.h"

string __OS::CoreApi::Type::Demangle(const string &name) {
  struct AutoDeleteCharPointer {
    AutoDeleteCharPointer(char* value) : value(value) {}
    ~AutoDeleteCharPointer() {delete value;}
    char* operator()() const {return this->value;}
  private:
    char* value;
  };
  int32 status = 0;
  return AutoDeleteCharPointer(abi::__cxa_demangle(name.Data(), 0, 0, &status))();
}

#endif
