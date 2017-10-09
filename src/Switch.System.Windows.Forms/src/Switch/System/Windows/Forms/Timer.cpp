#include "../../../../../include/Switch/System/Windows/Forms/Timer.hpp"
#include "../../../../Native/FormsApi.hpp"

using namespace System;
using namespace System::Windows::Forms;

void Timer::SetEnabled(bool enabled) {
  if (this->enabled != enabled) {
    this->enabled = enabled;
    if (this->enabled)
      this->handle = Native::FormsApi::Timer::Create(this->interval, this->tick);
    else
      Native::FormsApi::Timer::Destroy(this->handle);
  }
}

void Timer::SetInterval(int32 interval) {
  if (interval < 1)
    throw ArgumentOutOfRangeException(_caller);

  if (this->interval != interval) {
    this->interval = interval;
    if (this->enabled) {
      Native::FormsApi::Timer::Destroy(this->handle);
      this->handle = Native::FormsApi::Timer::Create(this->interval, this->tick);
    }
  }
}
