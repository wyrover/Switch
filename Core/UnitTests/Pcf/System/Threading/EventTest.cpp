#include <Pcf/System/Threading/EventWaitHandle.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

namespace PcfUnitTests {
  class EventTest : public TestFixture {
  protected:
    void CreateEventWithoutName() {
      bool createdNew = false;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
    }
    
    void CreateEventWitName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
    }
    
    void CreateEventWithDifferentName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
    }
    
    void CreateEventWithSameName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsTrue(createdNew, pcf_current_information);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::IsFalse(createdNew, pcf_current_information);
    }
    
    void CreateEventWithFalseInitialState() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
    }
    
    void CreateEventWithTrueInitialState() {
      EventWaitHandle ev(true, EventResetMode::ManualReset);
      Assert::IsTrue(ev.WaitOne(1), pcf_current_information);
    }
    
    void CloseEventWithoutName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "", createdNew);
      Assert::DoesNotThrows(pcf_delegate {ev.Close();}, pcf_current_information);
    }
    
    void CloseEventWithName() {
      bool createdNew;
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::DoesNotThrows(pcf_delegate {ev.Close();}, pcf_current_information);
    }
    
    void CloseEventWithDifferentName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event 1", createdNew);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event 2", createdNew);
      Assert::DoesNotThrows(pcf_delegate {ev1.Close();}, pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {ev2.Close();}, pcf_current_information);
    }
    
    void CloseEventWithSameName() {
      bool createdNew;
      EventWaitHandle ev1(false, EventResetMode::ManualReset, "Event", createdNew);
      EventWaitHandle ev2(false, EventResetMode::ManualReset, "Event", createdNew);
      Assert::DoesNotThrows(pcf_delegate {ev1.Close();}, pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {ev2.Close();}, pcf_current_information);
    }
    
    void SetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsTrue(ev.Set(), pcf_current_information);
    }
    
    void ResetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsTrue(ev.Reset(), pcf_current_information);
    }
    
    void WaitManualResetEvent() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
    }
    
    void WaitManualResetEventAfterSet() {
      EventWaitHandle ev(false, EventResetMode::ManualReset);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
      Assert::IsTrue(ev.Set(), pcf_current_information);
      Assert::IsTrue(ev.WaitOne(1), pcf_current_information);
      Assert::IsTrue(ev.WaitOne(1), pcf_current_information);
    }
    
    void WaitAutoResetEvent() {
      EventWaitHandle ev(false, EventResetMode::AutoReset);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
    }
    
    void WaitAutoResetEventAfterSet() {
      EventWaitHandle ev(false, EventResetMode::AutoReset);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
      Assert::IsTrue(ev.Set(), pcf_current_information);
      Assert::IsTrue(ev.WaitOne(1), pcf_current_information);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
    }
    
    void WaitManualResetEventAfterReseSet() {
      EventWaitHandle ev(true, EventResetMode::AutoReset);
      Assert::IsTrue(ev.WaitOne(1), pcf_current_information);
      Assert::IsTrue(ev.Reset(), pcf_current_information);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
    }
    
    void WaitAutoResetEventAfterReseSet() {
      EventWaitHandle ev(true, EventResetMode::AutoReset);
      Assert::IsTrue(ev.WaitOne(1), pcf_current_information);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
      Assert::IsTrue(ev.Reset(), pcf_current_information);
      Assert::IsFalse(ev.WaitOne(1), pcf_current_information);
    }
    
    void OpenExistingWithoutCreatingEventBebore() {
      //Assert::IsTrue(EventWaitHandle::OpenExisting("Event").IsNull(), pcf_current_information);
    }
    
    void OpenExistingWithCreatingAnotherEventBebore() {
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
     // Assert::IsTrue(EventWaitHandle::OpenExisting("Event 1").IsNull(), pcf_current_information);
    }
    
    void OpenExistingWithCreatingEventBebore() {
      EventWaitHandle ev(false, EventResetMode::ManualReset, "Event");
     // Assert::IsFalse(EventWaitHandle::OpenExisting("Event").IsNull(), pcf_current_information);
    }
    
    void DoubleAutoResesetEvent() {
      EventWaitHandle ev1(false, EventResetMode::AutoReset);
      EventWaitHandle ev2(false, EventResetMode::AutoReset);
      
      Assert::IsFalse(ev1.WaitOne(1), pcf_current_information);
      Assert::IsFalse(ev2.WaitOne(1), pcf_current_information);
      
      Assert::DoesNotThrows(pcf_delegate {ev1.Set();}, pcf_current_information);
      Assert::IsFalse(ev2.WaitOne(1), pcf_current_information);
      Assert::IsTrue(ev1.WaitOne(1), pcf_current_information);
      Assert::IsFalse(ev1.WaitOne(1), pcf_current_information);
      
      Assert::DoesNotThrows(pcf_delegate {ev2.Set();}, pcf_current_information);
      Assert::IsFalse(ev1.WaitOne(1), pcf_current_information);
      Assert::IsTrue(ev2.WaitOne(1), pcf_current_information);
      Assert::IsFalse(ev2.WaitOne(1), pcf_current_information);
    }
  };
  
  pcf_test(EventTest, CreateEventWithoutName)
  pcf_test(EventTest, CreateEventWitName)
  pcf_test(EventTest, CreateEventWithDifferentName)
  pcf_test(EventTest, CreateEventWithSameName)
  pcf_test(EventTest, CreateEventWithFalseInitialState)
  pcf_test(EventTest, CreateEventWithTrueInitialState)
  pcf_test(EventTest, CloseEventWithoutName)
  pcf_test(EventTest, CloseEventWithName)
  pcf_test(EventTest, CloseEventWithDifferentName)
  pcf_test(EventTest, CloseEventWithSameName)
  pcf_test(EventTest, SetEvent)
  pcf_test(EventTest, ResetEvent)
  pcf_test(EventTest, WaitManualResetEvent)
  pcf_test(EventTest, WaitManualResetEventAfterSet)
  pcf_test(EventTest, WaitAutoResetEvent)
  pcf_test(EventTest, WaitAutoResetEventAfterSet)
  pcf_test(EventTest, WaitManualResetEventAfterReseSet)
  pcf_test(EventTest, WaitAutoResetEventAfterReseSet)
  pcf_test(EventTest, OpenExistingWithoutCreatingEventBebore)
  pcf_test(EventTest, OpenExistingWithCreatingAnotherEventBebore)
  pcf_test(EventTest, OpenExistingWithCreatingEventBebore)
  pcf_test(EventTest, DoubleAutoResesetEvent)
}
