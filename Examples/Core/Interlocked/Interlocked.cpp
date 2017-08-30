#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class MyInterlockedExchangeClass : public object {
    //0 for False, 1 for True.
    static int usingResource;
    
    static const int numThreadIterations = 5;
    static const int numThreads = 10;
    
  public:
    // The main entry point for the application.
    static void Main() {
      Array<Thread> myThreads(numThreads);
      Random rnd;
      
      for (int i = 0; i < numThreads; i++) {
        myThreads[i] = Thread(ThreadStart(MyThreadProc));
        myThreads[i].Name = String::Format("Thread{0}", i + 1);
        
        //Wait a random amount of time before starting next thread.
        Thread::Sleep(rnd.Next(0, 1000));
        myThreads[i].Start();
      }
    }
    
    static void MyThreadProc() {
      for (int i = 0; i < numThreadIterations; i++) {
        UseResource();
        
        //Wait 1 second before next attempt.
        Thread::Sleep(1000);
      }
    }
    
    //A simple method that denies reentrancy.
    static bool UseResource() {
      //0 indicates that the method is not in use.
      if (0 == Interlocked::Exchange(usingResource, 1)) {
        Console::WriteLine("{0} acquired the lock", Thread::CurrentThread().Name);
        
        //Code to access a resource that is not thread safe would go here.
        
        //Simulate some work
        Thread::Sleep(500);
        
        Console::WriteLine("{0} exiting lock", Thread::CurrentThread().Name);
        
        //Release the lock
        Interlocked::Exchange(usingResource, 0);
        return true;
      } else {
        Console::WriteLine("   {0} was denied the lock", Thread::CurrentThread().Name);
        return false;
      }
    }
  };
  
  //0 for False, 1 for True.
  int MyInterlockedExchangeClass::usingResource = 0;
}

sw_startup (Examples::MyInterlockedExchangeClass)
