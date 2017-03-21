#include <Pcf/System/Collections/Generic/Dictionary.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Guid.h>
#include <Pcf/System/Random.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace TUnit;

namespace {
  class DictionaryThreadTask : public Object {
    using KeyValuePairGuids = KeyValuePair<Guid, Guid>;
    
  public:
    void AddItems() {
      while (!this->quit) {
        LockGuard lock(this->guids.SyncRoot);
        for (int32 i = 0; i < this->rand.Next(500); i++) {
          Guid guid = Guid::NewGuid();
          EXPECT_FALSE(this->guids.ContainsKey(guid));
          this->guids[guid] = guid;
          this->nbAdd++;
        }
        Thread::Sleep(this->rand.Next(10));
      }
    }
    
    void ListItems() {
      EXPECT_EQ(this->guids.Count, this->nbAdd - this->nbRemove);
      for (KeyValuePairGuids item : this->guids)
        EXPECT_EQ(item.Key(), item.Value());
    }
    
    void Quit() { this->quit = true; }
    
    void RemoveItems() {
      while (!this->quit) {
        LockGuard lock(this->guids.SyncRoot);
        for (int32 i = 0; i < this->rand.Next(500); i++) {
          if (!this->guids.Count)
            continue;
          
          int32 position = this->rand.Next(this->guids.Count);
          int32 index = 0;
          
          KeyValuePairGuids keyValueToRemove;
          for (KeyValuePairGuids item : this->guids)
            if (index++ == position)
              keyValueToRemove = item;
          
          EXPECT_EQ(keyValueToRemove.Key(), keyValueToRemove.Value());
          EXPECT_TRUE(this->guids.Remove(keyValueToRemove));
          this->nbRemove++;
        }
        Thread::Sleep(this->rand.Next(10));
      }
    }
    
  private:
    Dictionary<Guid, Guid> guids;
    System::Random rand;
    Boolean quit;
    Int32 nbAdd;
    Int32 nbRemove;
  };
  
  TEST(Dictionary, DictionaryFill) {
    DictionaryThreadTask task;
    Thread addItems(ThreadStart(task, &DictionaryThreadTask::AddItems));
    Thread removeItems(ThreadStart(task, &DictionaryThreadTask::RemoveItems));
    addItems.Start();
    removeItems.Start();
    Thread::Sleep(200);
    task.Quit();
    addItems.Join();
    removeItems.Join();
    task.ListItems();
  }
}

