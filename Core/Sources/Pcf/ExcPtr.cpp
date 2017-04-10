#include "../../Includes/Pcf/ExcPtr.h"

using namespace System;

Property<ExcPtr, ReadOnly> ExcPtr::CurrentException {
  [] {return std::current_exception();}
};
