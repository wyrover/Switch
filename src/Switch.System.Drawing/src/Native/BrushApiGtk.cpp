#if defined(__linux__)
#include "Api.hpp"

#include <gtkmm.h>

using namespace System;
using namespace System::Drawing;

intptr Native::BrushApi::CreateSolidBrush(const Color& color) {
  return IntPtr::Zero;
}

void Native::BrushApi::DeleteBrush(intptr handle) {
}

#endif
