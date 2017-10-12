#if defined(__linux__)
#include "Api.hpp"

#include <gtkmm.h>

using namespace System;
using namespace System::Drawing;

namespace {
}

intptr Native::PenApi::CreatePen(const System::Drawing::Drawing2D::DashStyle& dashStyle, int32 width, const Color& color) {
  return IntPtr::Zero;
}

void Native::PenApi::DeletePen(intptr handle) {
}

#endif
