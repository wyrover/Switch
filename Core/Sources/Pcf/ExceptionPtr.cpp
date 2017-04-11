#include "../../Includes/Pcf/ExceptionPtr.h"

using namespace System;

Property<ExceptionPtr, ReadOnly> ExceptionPtr::CurrentException {
  [] {return std::current_exception();}
};
