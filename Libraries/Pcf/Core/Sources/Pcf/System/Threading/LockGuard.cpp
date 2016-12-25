#include "../../../../Includes/Pcf/Lock.h"
#include "../../../../Includes/Pcf/System/Threading/Monitor.h"

System::Threading::LockGuard::LockGuard(const object& lock) : lock(lock) {
  System::Threading::Monitor::Enter(this->lock);
}

System::Threading::LockGuard::~LockGuard() {
  System::Threading::Monitor::Exit(this->lock);
}
