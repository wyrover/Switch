#include <Pcf/Pcf>

using namespace System;
using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace Examples {
  class Program {
  public:
    static void Main() {
      // Create a counter task
      Task<> counterTask = Task<>::Run(pcf_delegate {
        for (int counter = 1; counter <= 5; counter++)
          Console::WriteLine("counter = {0}", counter);
      });
      
      // Create a string result task
      Task<string> stringResultTask = Task<>::Run<string>(pcf_delegate() {
        return "This is a string result";
      });
      
      // Wait the two tasks
      Task<>::WaitAll({counterTask, stringResultTask});
      
      // Write on console the result of the second task
      Console::WriteLine(stringResultTask.Result);
      
      // Create action
      Action<> parallelAction = pcf_delegate {
        Console::WriteLine("[TaskId {0}] Run this action in parallel!", Task<>::CurrentId);
      };
      
      // Run 6 actions in parallel.
      Parallel::Invoke(parallelAction, parallelAction, parallelAction, parallelAction, parallelAction, parallelAction);
    }
  };
}

pcf_startup (Examples::Program)

// This code produces output similar to the following:
//
// counter = 1
// counter = 2
// counter = 3
// counter = 4
// counter = 5
// This is a string result
// [TaskId  3] Run this action in parallel!
// [TaskId  5] Run this action in parallel!
// [TaskId  4] Run this action in parallel!
// [TaskId  6] Run this action in parallel!
// [TaskId  7] Run this action in parallel!
// [TaskId  8] Run this action in parallel!


