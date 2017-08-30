#include "../../Includes/Switch/ExceptionPtr.hpp"

using namespace System;

Property<ExceptionPtr, ReadOnly> ExceptionPtr::CurrentException {
  [] {return std::current_exception();}
};
