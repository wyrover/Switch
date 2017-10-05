#include "../../Includes/Switch/ExceptionPtr.hpp"

using namespace System;

_property<ExceptionPtr, _readonly> ExceptionPtr::CurrentException {
  [] {return std::current_exception();}
};
