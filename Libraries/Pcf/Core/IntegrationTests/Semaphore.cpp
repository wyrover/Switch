#include <Runner.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;

namespace {

  class SemaphoreThreadTask : public object
  {
    typedef KeyValuePair<Guid, Guid> KeyValuePairGuids;
    
  public:
    SemaphoreThreadTask() : _semaphore(0, Int32::MaxValue())
    {
    }

    void AddItems()
    {
      while(_nbAdd < NbSignals)
      {
        Int32 nbAddItems = _rand.Next(1, 3);

        if (_nbAdd + nbAddItems > NbSignals)
          nbAddItems = NbSignals - _nbAdd;

        for (Int32 i = 0; i < nbAddItems; i++)
        {
          lock(_queue.GetSyncRoot())
            _queue.Enqueue(_nbAdd+i);
        }
        _nbAdd += nbAddItems;
        _semaphore.Release(nbAddItems);
      }
    }
    
    void CheckItems()
    {
      //Console::WriteLine("Count = " + _queue.GetCount() + " Nb Add = " + _nbAdd + " Nb Remove = " + _nbRemove);
      
      EXPECT_EQ(0, _queue.GetCount());
      EXPECT_EQ(NbSignals, _nbAdd);
      EXPECT_EQ(NbSignals, _nbRemove);
    }
        
    void RemoveItems()
    {
      while(_nbRemove != NbSignals)
      {
        _semaphore.WaitOne();
        lock(_queue.GetSyncRoot())
        {
          EXPECT_EQ(_nbRemove, _queue.Dequeue());
        }
        _nbRemove++;
      }
    }
    
  private:
    static const int32_t NbSignals;
    Semaphore _semaphore;
    Queue<Int32> _queue;
    System::Random _rand;
    Int32 _nbAdd;
    Int32 _nbRemove;
  };
  
  const int32_t SemaphoreThreadTask::NbSignals = 10000;

  TEST(SemaphoreTest2, WaitOne)
  {
    SemaphoreThreadTask task;
    
    //task.AddItems();
    //task.RemoveItems();
    Thread addItems(task, &SemaphoreThreadTask::AddItems);
    Thread removeItems(task, &SemaphoreThreadTask::RemoveItems);
    
    addItems.Start();
    removeItems.Start();
    
    addItems.Join();
    removeItems.Join();
    
    task.CheckItems();
  }
}

