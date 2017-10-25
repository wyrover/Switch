#include "../../include/Switch/ExceptionPtr.hpp"

using namespace System;

ExceptionPtr ExceptionPtr::CurrentException() {
  return std::current_exception();
  
}

