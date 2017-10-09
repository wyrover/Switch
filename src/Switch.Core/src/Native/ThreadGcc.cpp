#if defined(__linux__) || defined(__APPLE__)

#include <cmath>
#include <pthread.h>
#include "CoreApi.hpp"

bool Native::CoreApi::Thread::Cancel(intptr handle) {
  return pthread_cancel((pthread_t)handle) == 0;
}

intptr Native::CoreApi::Thread::GetCurrent() {
  return (intptr)pthread_self();
}

void Native::CoreApi::Thread::Resume(intptr handle) {
  // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
}

void Native::CoreApi::Thread::SetNameOfCurrentThread(const string &name) {
#if defined(__APPLE__)
  pthread_setname_np(name.Data());
#else
  pthread_setname_np(pthread_self(), name.Data());
#endif
}

bool Native::CoreApi::Thread::SetPriority(intptr handle, int32 priority) {
  int32 policy;
  sched_param schedParam;
  if (::pthread_getschedparam((pthread_t)handle, &policy, &schedParam) != 0)
    return false;
  
  schedParam.sched_priority = (int32)ceil(((double)priority * (sched_get_priority_max(policy) - sched_get_priority_min(policy)) / 4) + sched_get_priority_min(policy));
  return pthread_setschedparam((pthread_t)handle, policy, &schedParam) == 0;
}

void Native::CoreApi::Thread::Suspend(intptr handle) {
  // The POSIX standard provides no mechanism by which a thread A can suspend the execution of another thread B, without cooperation from B. The only way to implement a suspend/resume mechanism is to have B check periodically some global variable for a suspend request and then suspend itself on a condition variable, which another thread can signal later to restart B.
}

#endif
