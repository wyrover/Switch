#include "../../../../Includes/Switch/Lock.hpp"
#include "../../../../Includes/Switch/System/Threading/Monitor.hpp"

System::Threading::LockGuard::LockGuard(const object& lock) : lock(lock) {
  System::Threading::Monitor::Enter(this->lock);
}

System::Threading::LockGuard::~LockGuard() {
  System::Threading::Monitor::Exit(this->lock);
}
