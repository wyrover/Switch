#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Concurrent;

namespace Examples {
  class Program {
  public:
    // Demonstrates:
    //      ConcurrentBag<T>.Add()
    //      ConcurrentBag<T>.IsEmpty
    //      ConcurrentBag<T>.TryTake()
    //      ConcurrentBag<T>.TryPeek()
    static void Main() {
      // Construct and populate the ConcurrentBag
      ConcurrentBag<int> cb;
      cb.Add(1);
      cb.Add(2);
      cb.Add(3);

      // Consume the items in the bag
      int item;
      while (!cb.IsEmpty) {
        if (cb.TryTake(item))
          Console::WriteLine(item);
        else
          Console::WriteLine("TryTake failed for non-empty bag");
      }

      // Bag should be empty at this point
      if (cb.TryPeek(item))
        Console::WriteLine("TryPeek succeeded for empty bag!");
    }
  };
}

startup_(Examples::Program);

// This code example produces the following output:
//
// 3
// 2
// 1
