#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class MyInterlockedDecrementClass {
    class CountClass : public object {
    public:
      static int UnsafeInstanceCount;
      static int SafeInstanceCount;

      CountClass() {
        UnsafeInstanceCount++;
        Interlocked::Increment(SafeInstanceCount);
      }

      ~CountClass() {
        UnsafeInstanceCount--;
        Interlocked::Decrement(SafeInstanceCount);
      }
    };

  public:
    static void Main() {
      Thread thread1 = Thread(ThreadStart(ThreadMethod));
      Thread thread2 = Thread(ThreadStart(ThreadMethod));
      thread1.Start();
      thread2.Start();
      thread1.Join();
      thread2.Join();

      Console::WriteLine("UnsafeInstanceCount: {0}\nSafeCountInstances: {1}", CountClass::UnsafeInstanceCount, CountClass::SafeInstanceCount);
    }

  private:
    static void ThreadMethod() {
      refptr<CountClass> coutClass;

      // Create 100000 instances of CountClass.
      for (int i = 0; i < 100000; i++)
        coutClass = ref_new<CountClass>();
    }
  };

  int MyInterlockedDecrementClass::CountClass::UnsafeInstanceCount = 0;
  int MyInterlockedDecrementClass::CountClass::SafeInstanceCount = 0;
}

startup_(Examples::MyInterlockedDecrementClass);

// This code produces the following output:
//
// UnsafeInstanceCount: 26305
// SafeCountInstances: 0
