#include "../../../../include/Switch/System/Array.hpp"
#include "../../../../include/Switch/System/Threading/Monitor.hpp"
#include "../../../../include/Switch/System/Threading/Mutex.hpp"
#include "../../../../include/Switch/System/Threading/SynchronizationLockException.hpp"
#include "../../../../include/Switch/System/Threading/Timeout.hpp"

namespace {
  std::recursive_mutex mutex;
}

using namespace System;
using namespace System::Threading;

System::Collections::Generic::Dictionary<const object*, Monitor::MonitorItem> Monitor::monitorItems;

void Monitor::Pulse(const Object& obj) {
  MonitorItem* monitorItem = null;
  mutex.lock();
  if (IsEntered(obj))
    monitorItem = &monitorItems[ToKey(obj)];
  mutex.unlock();
  
  if (monitorItem == null)
    throw InvalidOperationException(_caller);
  
  monitorItem->event.ReleaseMutex();
}

void Monitor::PulseAll(const Object& obj) {
  MonitorItem* monitorItem = null;
  mutex.lock();
  if (IsEntered(obj))
    monitorItem = &monitorItems[ToKey(obj)];
  mutex.unlock();
  
  if (monitorItem == null)
    throw InvalidOperationException(_caller);
  
  monitorItem->event.ReleaseMutex();
}

 bool Monitor::Wait(const Object& obj, int32 millisecondsTimeout) {
   MonitorItem* monitorItem = null;
   mutex.lock();
   if (IsEntered(obj))
     monitorItem = &monitorItems[ToKey(obj)];
   mutex.unlock();
   
   if (monitorItem == null)
     throw InvalidOperationException(_caller);
   
   return monitorItem->event.WaitOne(millisecondsTimeout);
 }

bool Monitor::Add(const Object& obj, int32 millisecondsTimeout) {
  mutex.lock();
  if (!IsEntered(obj))
    monitorItems[ToKey(obj)] = is<string>(obj) ? MonitorItem((const string&)obj) : MonitorItem();
  MonitorItem& monitorData = monitorItems[ToKey(obj)];
  monitorData.usedCounter++;
  mutex.unlock();
  return monitorData.event.WaitOne(millisecondsTimeout);
}

void Monitor::Remove(const Object& obj) {
  MonitorItem saved;
  mutex.lock();
  if (!IsEntered(obj)) {
    mutex.unlock();
    throw SynchronizationLockException(_caller);
  }

  MonitorItem* monitorData = &monitorItems[ToKey(obj)];
  if (--monitorData->usedCounter == 0) {
    saved = monitorItems[ToKey(obj)];
    monitorItems.Remove(ToKey(obj));
    monitorData = &saved;
  }
  mutex.unlock();
  monitorData->event.ReleaseMutex();
}
