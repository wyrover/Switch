#include <Switch/System/Threading/EventWaitHandle.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace SwitchUnitTests {
  class EventTest : public TestFixture {
  protected:
    void CreateEventWithoutName() {
      bool createdNew = false;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "", createdNew);
      Assert::IsTrue(createdNew, _caller);
    }
    
    void CreateEventWitName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsTrue(createdNew, _caller);
    }
    
    void CreateEventWithDifferentName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
      Assert::IsTrue(createdNew, _caller);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
      Assert::IsTrue(createdNew, _caller);
    }
    
    void CreateEventWithSameName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsTrue(createdNew, _caller);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsFalse(createdNew, _caller);
    }
    
    void CreateEventWithFalseInitialState() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), _caller);
    }
    
    void CreateEventWithTrueInitialState() {
      EventWaitHandle ev(true, EventResetMode::ManualReset);
      Assert::IsTrue(ev.WaitOne(1), _caller);
    }
    
    void CloseEventWithoutName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "", createdNew);
      Assert::DoesNotThrows(_delegate {ev.Close();}, _caller);
    }
    
    void CloseEventWithName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::DoesNotThrows(_delegate {ev.Close();}, _caller);
    }
    
    void CloseEventWithDifferentName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
      Assert::DoesNotThrows(_delegate {ev1.Close();}, _caller);
      Assert::DoesNotThrows(_delegate {ev2.Close();}, _caller);
    }
    
    void CloseEventWithSameName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::DoesNotThrows(_delegate {ev1.Close();}, _caller);
      Assert::DoesNotThrows(_delegate {ev2.Close();}, _caller);
    }
    
    void SetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsTrue(ev.Set(), _caller);
    }
    
    void ResetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsTrue(ev.Reset(), _caller);
    }
    
    void WaitManualResetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), _caller);
    }
    
    void WaitManualResetEventAfterSet() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), _caller);
      Assert::IsTrue(ev.Set(), _caller);
      Assert::IsTrue(ev.WaitOne(1), _caller);
      Assert::IsTrue(ev.WaitOne(1), _caller);
    }
    
    void WaitAutoResetEvent() {
      EventWaitHandle ev(false, EventResetMode::AutoReset);
      Assert::IsFalse(ev.WaitOne(1), _caller);
    }
    
    void WaitAutoResetEventAfterSet() {
      EventWaitHandle ev(false, EventResetMode::AutoReset);
      Assert::IsFalse(ev.WaitOne(1), _caller);
      Assert::IsTrue(ev.Set(), _caller);
      Assert::IsTrue(ev.WaitOne(1), _caller);
      Assert::IsFalse(ev.WaitOne(1), _caller);
    }
    
    void WaitManualResetEventAfterReseSet() {
      EventWaitHandle ev(true, EventResetMode::AutoReset);
      Assert::IsTrue(ev.WaitOne(1), _caller);
      Assert::IsTrue(ev.Reset(), _caller);
      Assert::IsFalse(ev.WaitOne(1), _caller);
    }
    
    void WaitAutoResetEventAfterReseSet() {
      EventWaitHandle ev(true, EventResetMode::AutoReset);
      Assert::IsTrue(ev.WaitOne(1), _caller);
      Assert::IsFalse(ev.WaitOne(1), _caller);
      Assert::IsTrue(ev.Reset(), _caller);
      Assert::IsFalse(ev.WaitOne(1), _caller);
    }
    
    void OpenExistingWithoutCreatingEventBebore() {
      //Assert::IsTrue(EventWaitHandle::OpenExisting("Event") == null, _caller);
    }
    
    void OpenExistingWithCreatingAnotherEventBebore() {
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
     // Assert::IsTrue(EventWaitHandle::OpenExisting("Event 1") == null, _caller);
    }
    
    void OpenExistingWithCreatingEventBebore() {
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
     // Assert::IsFalse(EventWaitHandle::OpenExisting("Event") == null, _caller);
    }
    
    void DoubleAutoResesetEvent() {
      EventWaitHandle ev1(false, EventResetMode::AutoReset);
      EventWaitHandle ev2(false, EventResetMode::AutoReset);
      
      Assert::IsFalse(ev1.WaitOne(1), _caller);
      Assert::IsFalse(ev2.WaitOne(1), _caller);
      
      Assert::DoesNotThrows(_delegate {ev1.Set();}, _caller);
      Assert::IsFalse(ev2.WaitOne(1), _caller);
      Assert::IsTrue(ev1.WaitOne(1), _caller);
      Assert::IsFalse(ev1.WaitOne(1), _caller);
      
      Assert::DoesNotThrows(_delegate {ev2.Set();}, _caller);
      Assert::IsFalse(ev1.WaitOne(1), _caller);
      Assert::IsTrue(ev2.WaitOne(1), _caller);
      Assert::IsFalse(ev2.WaitOne(1), _caller);
    }
  };
  
  _add_test (EventTest, CreateEventWithoutName)
  _add_test (EventTest, CreateEventWitName)
  _add_test (EventTest, CreateEventWithDifferentName)
  _add_test (EventTest, CreateEventWithSameName)
  _add_test (EventTest, CreateEventWithFalseInitialState)
  _add_test (EventTest, CreateEventWithTrueInitialState)
  _add_test (EventTest, CloseEventWithoutName)
  _add_test (EventTest, CloseEventWithName)
  _add_test (EventTest, CloseEventWithDifferentName)
  _add_test (EventTest, CloseEventWithSameName)
  _add_test (EventTest, SetEvent)
  _add_test (EventTest, ResetEvent)
  _add_test (EventTest, WaitManualResetEvent)
  _add_test (EventTest, WaitManualResetEventAfterSet)
  _add_test (EventTest, WaitAutoResetEvent)
  _add_test (EventTest, WaitAutoResetEventAfterSet)
  _add_test (EventTest, WaitManualResetEventAfterReseSet)
  _add_test (EventTest, WaitAutoResetEventAfterReseSet)
  _add_test (EventTest, OpenExistingWithoutCreatingEventBebore)
  _add_test (EventTest, OpenExistingWithCreatingAnotherEventBebore)
  _add_test (EventTest, OpenExistingWithCreatingEventBebore)
  _add_test (EventTest, DoubleAutoResesetEvent)
}
