#include "../../../../Includes/Pcf/System/Threading/EventWaitHandle.h"
#include "NamedHandleCollection.h"

using namespace System;
using namespace System::Threading;

namespace {
  NamedHandleCollection<EventWaitHandle> events;
}

EventWaitHandle::EventWaitHandle(bool initialState, EventResetMode mode, const string& name) {
  bool createdNew = true;
  if (name != "")
    this->operator =(events.Add(name, createdNew));
  if (createdNew) {
    *this->mode = mode;
    *this->name = name;
    if (initialState)
      this->Set();
  }
}

EventWaitHandle::EventWaitHandle(bool initialState, EventResetMode mode, const string& name, bool& createdNew) {
  createdNew = true;
  if (name != "")
    this->operator =(events.Add(name, createdNew));
  if (createdNew) {
    *this->mode = mode;
    *this->name = name;
    if (initialState)
      this->Set();
  }
}

void EventWaitHandle::Close() {
  if (this->guard.IsNull())
    return;
  if (this->name() != "")
    ::events.Remove(this->name());
  this->name.Reset();
  this->guard.Reset();
  this->signal.Reset();
  this->event.Reset();
  this->mode.Reset();
}

EventWaitHandle EventWaitHandle::OpenExisting(const string& name) {
  if (!events.Conatains(name))
    throw WaitHandleCannotBeOpenedException(pcf_current_information);
  bool createNew;
  EventWaitHandle value = events.Add(name, createNew);
  return value;
}
