#include "../../Includes/Pcf/ExceptionPointer.h"

using namespace System;

Property<ExceptionPointer, ReadOnly> ExceptionPointer::CurrentException {
  [] {return std::current_exception();}
};
