#include <Pcf/Pcf>

using namespace System;
using namespace System::Threading;
using namespace System::Collections::Concurrent;

namespace Examples {
  class Program {
  public:
    // Demonstrates:
    // ConcurrentQueue<T>.Enqueue()
    // ConcurrentQueue<T>.TryPeek()
    // ConcurrentQueue<T>.TryDequeue()
    static void Main() {
      // Populate the queue.
      for (int i = 0; i < 10000; i++) {
        cq.Enqueue(i);
      }
      
      // Peek at the first element.
      int result;
      if (!cq.TryPeek(result)) {
        Console::WriteLine("CQ: TryPeek failed when it should have succeeded");
      } else {
        if (result != 0) {
          Console::WriteLine("CQ: Expected TryPeek result of 0, got {0}", result);
        }
      }
      
      // An action to consume the ConcurrentQueue.
      Array<sp<Thread>> actions(4);
      
      for (int i = 0; i < 4; i++) {
        actions[i] = sp<Thread>::Create((ThreadStart)&Program::ActionTryDequeue);
      }
      
      // Start 4 concurrent consuming actions.
      for (int i = 0; i < 4; i++) {
        actions[i]->Start();
      }
      
      // Join 4 concurrent consuming actions.
      for (int i = 0; i < 4; i++) {
        actions[i]->Join();
      }
      
      Console::WriteLine("outerSum = {0}, should be 49995000", outerSum);
    }
    
  private:
    static void ActionTryDequeue() {
      int localSum = 0;
      int localValue;
      while (cq.TryDequeue(localValue)) {
        localSum += localValue;
      }
      Interlocked::Add(outerSum, localSum);
    };
    
    static ConcurrentQueue<int> cq;
    static int outerSum;
  };

  ConcurrentQueue<int> Program::cq;
  int Program::outerSum = 0;
}

pcf_startup (Examples::Program)


// This code example produces the following output:
//
// outerSum = 49995000, should be 49995000
