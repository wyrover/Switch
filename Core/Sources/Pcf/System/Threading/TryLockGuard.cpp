#include "../../../../Includes/Pcf/System/Threading/TryLockGuard.hpp"
#include "../../../../Includes/Pcf/System/Threading/Monitor.hpp"
#include "../../../../Includes/Pcf/System/Threading/TimeOut.hpp"

using namespace System;
using namespace System::Threading;

TryLockGuard::TryLockGuard(const object& lock) : lock(lock) {
  this->result = Monitor::TryEnter(this->lock, Timeout::Infinite);
}

TryLockGuard::TryLockGuard(const object& lock, int32 timeout) : lock(lock) {
  this->result = Monitor::TryEnter(this->lock, timeout);
}

TryLockGuard::TryLockGuard(const object& lock, int64 timeout) : lock(lock) {
  this->result = Monitor::TryEnter(this->lock, timeout);
}

TryLockGuard::TryLockGuard(const object& lock, const TimeSpan& timeout) : lock(lock) {
  this->result = Monitor::TryEnter(this->lock, timeout);
}

TryLockGuard::~TryLockGuard() {
  if (this->result)
    Monitor::Exit(this->lock);
}
