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
      Assert::IsTrue(createdNew, sw_current_information);
    }
    
    void CreateEventWitName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
    }
    
    void CreateEventWithDifferentName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
    }
    
    void CreateEventWithSameName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsTrue(createdNew, sw_current_information);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsFalse(createdNew, sw_current_information);
    }
    
    void CreateEventWithFalseInitialState() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
    }
    
    void CreateEventWithTrueInitialState() {
      EventWaitHandle ev(true, EventResetMode::ManualReset);
      Assert::IsTrue(ev.WaitOne(1), sw_current_information);
    }
    
    void CloseEventWithoutName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "", createdNew);
      Assert::DoesNotThrows(sw_delegate {ev.Close();}, sw_current_information);
    }
    
    void CloseEventWithName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::DoesNotThrows(sw_delegate {ev.Close();}, sw_current_information);
    }
    
    void CloseEventWithDifferentName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
      Assert::DoesNotThrows(sw_delegate {ev1.Close();}, sw_current_information);
      Assert::DoesNotThrows(sw_delegate {ev2.Close();}, sw_current_information);
    }
    
    void CloseEventWithSameName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::DoesNotThrows(sw_delegate {ev1.Close();}, sw_current_information);
      Assert::DoesNotThrows(sw_delegate {ev2.Close();}, sw_current_information);
    }
    
    void SetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsTrue(ev.Set(), sw_current_information);
    }
    
    void ResetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsTrue(ev.Reset(), sw_current_information);
    }
    
    void WaitManualResetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
    }
    
    void WaitManualResetEventAfterSet() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
      Assert::IsTrue(ev.Set(), sw_current_information);
      Assert::IsTrue(ev.WaitOne(1), sw_current_information);
      Assert::IsTrue(ev.WaitOne(1), sw_current_information);
    }
    
    void WaitAutoResetEvent() {
      EventWaitHandle ev(false, EventResetMode::AutoReset);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
    }
    
    void WaitAutoResetEventAfterSet() {
      EventWaitHandle ev(false, EventResetMode::AutoReset);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
      Assert::IsTrue(ev.Set(), sw_current_information);
      Assert::IsTrue(ev.WaitOne(1), sw_current_information);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
    }
    
    void WaitManualResetEventAfterReseSet() {
      EventWaitHandle ev(true, EventResetMode::AutoReset);
      Assert::IsTrue(ev.WaitOne(1), sw_current_information);
      Assert::IsTrue(ev.Reset(), sw_current_information);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
    }
    
    void WaitAutoResetEventAfterReseSet() {
      EventWaitHandle ev(true, EventResetMode::AutoReset);
      Assert::IsTrue(ev.WaitOne(1), sw_current_information);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
      Assert::IsTrue(ev.Reset(), sw_current_information);
      Assert::IsFalse(ev.WaitOne(1), sw_current_information);
    }
    
    void OpenExistingWithoutCreatingEventBebore() {
      //Assert::IsTrue(EventWaitHandle::OpenExisting("Event").IsNull(), sw_current_information);
    }
    
    void OpenExistingWithCreatingAnotherEventBebore() {
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
     // Assert::IsTrue(EventWaitHandle::OpenExisting("Event 1").IsNull(), sw_current_information);
    }
    
    void OpenExistingWithCreatingEventBebore() {
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
     // Assert::IsFalse(EventWaitHandle::OpenExisting("Event").IsNull(), sw_current_information);
    }
    
    void DoubleAutoResesetEvent() {
      EventWaitHandle ev1(false, EventResetMode::AutoReset);
      EventWaitHandle ev2(false, EventResetMode::AutoReset);
      
      Assert::IsFalse(ev1.WaitOne(1), sw_current_information);
      Assert::IsFalse(ev2.WaitOne(1), sw_current_information);
      
      Assert::DoesNotThrows(sw_delegate {ev1.Set();}, sw_current_information);
      Assert::IsFalse(ev2.WaitOne(1), sw_current_information);
      Assert::IsTrue(ev1.WaitOne(1), sw_current_information);
      Assert::IsFalse(ev1.WaitOne(1), sw_current_information);
      
      Assert::DoesNotThrows(sw_delegate {ev2.Set();}, sw_current_information);
      Assert::IsFalse(ev1.WaitOne(1), sw_current_information);
      Assert::IsTrue(ev2.WaitOne(1), sw_current_information);
      Assert::IsFalse(ev2.WaitOne(1), sw_current_information);
    }
  };
  
  sw_test(EventTest, CreateEventWithoutName)
  sw_test(EventTest, CreateEventWitName)
  sw_test(EventTest, CreateEventWithDifferentName)
  sw_test(EventTest, CreateEventWithSameName)
  sw_test(EventTest, CreateEventWithFalseInitialState)
  sw_test(EventTest, CreateEventWithTrueInitialState)
  sw_test(EventTest, CloseEventWithoutName)
  sw_test(EventTest, CloseEventWithName)
  sw_test(EventTest, CloseEventWithDifferentName)
  sw_test(EventTest, CloseEventWithSameName)
  sw_test(EventTest, SetEvent)
  sw_test(EventTest, ResetEvent)
  sw_test(EventTest, WaitManualResetEvent)
  sw_test(EventTest, WaitManualResetEventAfterSet)
  sw_test(EventTest, WaitAutoResetEvent)
  sw_test(EventTest, WaitAutoResetEventAfterSet)
  sw_test(EventTest, WaitManualResetEventAfterReseSet)
  sw_test(EventTest, WaitAutoResetEventAfterReseSet)
  sw_test(EventTest, OpenExistingWithoutCreatingEventBebore)
  sw_test(EventTest, OpenExistingWithCreatingAnotherEventBebore)
  sw_test(EventTest, OpenExistingWithCreatingEventBebore)
  sw_test(EventTest, DoubleAutoResesetEvent)
}
