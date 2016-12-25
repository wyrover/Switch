
#include "../../../../../Includes/Pcf/System/Threading/Tasks/Task.h"

using namespace System;
using namespace System::Threading::Tasks;

#if __clang__
__thread int32 __opaque_task_id_generator__::currentId = 0;
#else
thread_local int32 __opaque_task_id_generator__::currentId = 0;
#endif

Property<Nullable<int32>, ReadOnly> Task<void>::CurrentId {
  [] {return __currentId__();}
};

Property<TaskFactory, ReadOnly> Task<void>::Factory {
  [] {return TaskFactory();}
};

Nullable<int32> Task<void>::__currentId__() {
  if (__opaque_task_id_generator__::currentId == 0)
    return Nullable<int32>();
  return Nullable<int32>(__opaque_task_id_generator__::currentId);
}
