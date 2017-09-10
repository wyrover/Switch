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
      Assert::IsTrue(createdNew, _current_information);
    }
    
    void CreateEventWitName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsTrue(createdNew, _current_information);
    }
    
    void CreateEventWithDifferentName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
      Assert::IsTrue(createdNew, _current_information);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
      Assert::IsTrue(createdNew, _current_information);
    }
    
    void CreateEventWithSameName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsTrue(createdNew, _current_information);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsFalse(createdNew, _current_information);
    }
    
    void CreateEventWithFalseInitialState() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
    }
    
    void CreateEventWithTrueInitialState() {
      EventWaitHandle ev(true, EventResetMode::ManualReset);
      Assert::IsTrue(ev.WaitOne(1), _current_information);
    }
    
    void CloseEventWithoutName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "", createdNew);
      Assert::DoesNotThrows(_delegate {ev.Close();}, _current_information);
    }
    
    void CloseEventWithName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::DoesNotThrows(_delegate {ev.Close();}, _current_information);
    }
    
    void CloseEventWithDifferentName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
      Assert::DoesNotThrows(_delegate {ev1.Close();}, _current_information);
      Assert::DoesNotThrows(_delegate {ev2.Close();}, _current_information);
    }
    
    void CloseEventWithSameName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::DoesNotThrows(_delegate {ev1.Close();}, _current_information);
      Assert::DoesNotThrows(_delegate {ev2.Close();}, _current_information);
    }
    
    void SetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsTrue(ev.Set(), _current_information);
    }
    
    void ResetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsTrue(ev.Reset(), _current_information);
    }
    
    void WaitManualResetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
    }
    
    void WaitManualResetEventAfterSet() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
      Assert::IsTrue(ev.Set(), _current_information);
      Assert::IsTrue(ev.WaitOne(1), _current_information);
      Assert::IsTrue(ev.WaitOne(1), _current_information);
    }
    
    void WaitAutoResetEvent() {
      EventWaitHandle ev(false, EventResetMode::AutoReset);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
    }
    
    void WaitAutoResetEventAfterSet() {
      EventWaitHandle ev(false, EventResetMode::AutoReset);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
      Assert::IsTrue(ev.Set(), _current_information);
      Assert::IsTrue(ev.WaitOne(1), _current_information);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
    }
    
    void WaitManualResetEventAfterReseSet() {
      EventWaitHandle ev(true, EventResetMode::AutoReset);
      Assert::IsTrue(ev.WaitOne(1), _current_information);
      Assert::IsTrue(ev.Reset(), _current_information);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
    }
    
    void WaitAutoResetEventAfterReseSet() {
      EventWaitHandle ev(true, EventResetMode::AutoReset);
      Assert::IsTrue(ev.WaitOne(1), _current_information);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
      Assert::IsTrue(ev.Reset(), _current_information);
      Assert::IsFalse(ev.WaitOne(1), _current_information);
    }
    
    void OpenExistingWithoutCreatingEventBebore() {
      //Assert::IsTrue(EventWaitHandle::OpenExisting("Event") == null, _current_information);
    }
    
    void OpenExistingWithCreatingAnotherEventBebore() {
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
     // Assert::IsTrue(EventWaitHandle::OpenExisting("Event 1") == null, _current_information);
    }
    
    void OpenExistingWithCreatingEventBebore() {
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
     // Assert::IsFalse(EventWaitHandle::OpenExisting("Event") == null, _current_information);
    }
    
    void DoubleAutoResesetEvent() {
      EventWaitHandle ev1(false, EventResetMode::AutoReset);
      EventWaitHandle ev2(false, EventResetMode::AutoReset);
      
      Assert::IsFalse(ev1.WaitOne(1), _current_information);
      Assert::IsFalse(ev2.WaitOne(1), _current_information);
      
      Assert::DoesNotThrows(_delegate {ev1.Set();}, _current_information);
      Assert::IsFalse(ev2.WaitOne(1), _current_information);
      Assert::IsTrue(ev1.WaitOne(1), _current_information);
      Assert::IsFalse(ev1.WaitOne(1), _current_information);
      
      Assert::DoesNotThrows(_delegate {ev2.Set();}, _current_information);
      Assert::IsFalse(ev1.WaitOne(1), _current_information);
      Assert::IsTrue(ev2.WaitOne(1), _current_information);
      Assert::IsFalse(ev2.WaitOne(1), _current_information);
    }
  };
  
  _test(EventTest, CreateEventWithoutName)
  _test(EventTest, CreateEventWitName)
  _test(EventTest, CreateEventWithDifferentName)
  _test(EventTest, CreateEventWithSameName)
  _test(EventTest, CreateEventWithFalseInitialState)
  _test(EventTest, CreateEventWithTrueInitialState)
  _test(EventTest, CloseEventWithoutName)
  _test(EventTest, CloseEventWithName)
  _test(EventTest, CloseEventWithDifferentName)
  _test(EventTest, CloseEventWithSameName)
  _test(EventTest, SetEvent)
  _test(EventTest, ResetEvent)
  _test(EventTest, WaitManualResetEvent)
  _test(EventTest, WaitManualResetEventAfterSet)
  _test(EventTest, WaitAutoResetEvent)
  _test(EventTest, WaitAutoResetEventAfterSet)
  _test(EventTest, WaitManualResetEventAfterReseSet)
  _test(EventTest, WaitAutoResetEventAfterReseSet)
  _test(EventTest, OpenExistingWithoutCreatingEventBebore)
  _test(EventTest, OpenExistingWithCreatingAnotherEventBebore)
  _test(EventTest, OpenExistingWithCreatingEventBebore)
  _test(EventTest, DoubleAutoResesetEvent)
}
