#include <Switch/Switch>

using namespace System;
using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      int count = 0;
      
      // Create a barrier with three participants
      // Provide a post-phase action that will print out certain information
      // And the third time through, it will throw an exception
      Barrier barrier = Barrier(3, _delegate(const Barrier& b) {
        Console::WriteLine("Post-Phase action: count={0}, phase={1}", count, b.CurrentPhaseNumber);
        if (b.CurrentPhaseNumber() == 2) throw Exception("D'oh!");
      });
      
      // Nope -- changed my mind.  Let's make it five participants.
      barrier.AddParticipants(2);
      
      // Nope -- let's settle on four participants.
      barrier.RemoveParticipant();
      
      
      // This is the logic run by all participants
      Action<> action = _delegate {
        Interlocked::Increment(count);
        barrier.SignalAndWait(); // during the post-phase action, count should be 4 and phase should be 0
        Interlocked::Increment(count);
        barrier.SignalAndWait(); // during the post-phase action, count should be 8 and phase should be 1
        
        // The third time, SignalAndWait() will throw an exception and all participants will see it
        Interlocked::Increment(count);
        try {
          barrier.SignalAndWait();
        } catch (const BarrierPostPhaseException& bppe) {
          Console::WriteLine("Caught BarrierPostPhaseException: {0}", bppe.Message);
        }
        
        // The fourth time should be hunky-dory
        Interlocked::Increment(count);
        barrier.SignalAndWait(); // during the post-phase action, count should be 16 and phase should be 3
      };
      
      // Now launch 4 parallel actions to serve as 4 participants
      Parallel::Invoke(action, action, action, action);
    }
  };
}

_startup(Examples::Program);

// This code example produces the following output:
//
// Post-Phase action: count=4, phase=0
// Post-Phase action: count=8, phase=1
// Post-Phase action: count=12, phase=2
// Caught BarrierPostPhaseException: The postPhaseAction failed with an exception.
// Caught BarrierPostPhaseException: The postPhaseAction failed with an exception.
// Caught BarrierPostPhaseException: The postPhaseAction failed with an exception.
// Caught BarrierPostPhaseException: The postPhaseAction failed with an exception.
// Post-Phase action: count=16, phase=3
