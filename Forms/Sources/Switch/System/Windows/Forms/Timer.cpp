#include "../../../../../Includes/Switch/System/Windows/Forms/Timer.hpp"
#include "../../../../__OS/FormsApi.hpp"

using namespace System;
using namespace System::Windows::Forms;

void Timer::SetEnabled(bool enabled) {
  if (this->enabled != enabled) {
    this->enabled = enabled;
    if (this->enabled)
      this->handle = __OS::FormsApi::Timer::Create(this->interval, this->tick);
    else
      __OS::FormsApi::Timer::Destroy(this->handle);
  }
}

void Timer::SetInterval(int32 interval) {
  if (interval < 1)
    throw ArgumentOutOfRangeException(pcf_current_information);

  if (this->interval != interval) {
    this->interval = interval;
    if (this->enabled) {
      __OS::FormsApi::Timer::Destroy(this->handle);
      this->handle = __OS::FormsApi::Timer::Create(this->interval, this->tick);
    }
  }
}
