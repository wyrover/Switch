#include "Corelib.h"

using namespace System;

string PointerType::ToString() const
{
  return demangle(typeid(*this).name()).c_str();
}
