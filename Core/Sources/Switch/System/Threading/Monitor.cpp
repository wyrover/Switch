#include "../../../../Includes/Switch/System/Array.hpp"
#include "../../../../Includes/Switch/System/Threading/Monitor.hpp"
#include "../../../../Includes/Switch/System/Threading/Mutex.hpp"
#include "../../../../Includes/Switch/System/Threading/TimeOut.hpp"

namespace {
  std::recursive_mutex mutex;
}

using namespace System;
using namespace System::Threading;

System::Collections::Generic::SortedDictionary<const object*, Monitor::MonitorItem> Monitor::monitorItems;

void Monitor::Pulse(const Object& obj) {
  MonitorItem* monitorItem = null;
  mutex.lock();
  if (IsEntered(obj))
    monitorItem = &monitorItems[&obj];
  mutex.unlock();
  
  if (monitorItem == null)
    throw InvalidOperationException(pcf_current_information);
  
  monitorItem->event.ReleaseMutex();
}

void Monitor::PulseAll(const Object& obj) {
  MonitorItem* monitorItem = null;
  mutex.lock();
  if (IsEntered(obj))
    monitorItem = &monitorItems[&obj];
  mutex.unlock();
  
  if (monitorItem == null)
    throw InvalidOperationException(pcf_current_information);
  
  monitorItem->event.ReleaseMutex();
}

 bool Monitor::Wait(const Object& obj, int32 millisecondsTimeout) {
   MonitorItem* monitorItem = null;
   mutex.lock();
   if (IsEntered(obj))
     monitorItem = &monitorItems[&obj];
   mutex.unlock();
   
   if (monitorItem == null)
     throw InvalidOperationException(pcf_current_information);
   
   return monitorItem->event.WaitOne(millisecondsTimeout);
 }

bool Monitor::Add(const Object& obj, int32 millisecondsTimeout) {
  mutex.lock();
  if (!IsEntered(obj))
    monitorItems[&obj] = MonitorItem();
  MonitorItem& monitorData = monitorItems[&obj];
  monitorData.usedCounter++;
  mutex.unlock();
  return monitorData.event.WaitOne(millisecondsTimeout);
}

void Monitor::Remove(const Object& obj) {
  MonitorItem saved;
  mutex.lock();
  if (!IsEntered(obj)) {
    mutex.unlock();
    throw InvalidOperationException(pcf_current_information);
  }

  MonitorItem* monitorData = &monitorItems[&obj];
  if (--monitorData->usedCounter == 0) {
    saved = monitorItems[&obj];
    monitorItems.Remove(&obj);
    monitorData = &saved;
  }
  mutex.unlock();
  monitorData->event.ReleaseMutex();
}
