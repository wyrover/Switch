#include "../../Includes/Switch/ExceptionPtr.hpp"

using namespace System;

property<ExceptionPtr, readonly> ExceptionPtr::CurrentException {
  [] {return std::current_exception();}
};
