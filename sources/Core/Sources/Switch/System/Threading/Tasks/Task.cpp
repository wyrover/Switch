
#include "../../../../../Includes/Switch/System/Threading/Tasks/Task.hpp"

using namespace System;
using namespace System::Threading::Tasks;

thread_local int32 __opaque_task_id_generator__::currentId = 0;

_property<Nullable<int32>, _readonly> Task<void>::CurrentId {
  [] {return __currentId__();}
};

_property<TaskFactory, _readonly> Task<void>::Factory {
  [] {return TaskFactory();}
};

Nullable<int32> Task<void>::__currentId__() {
  if (__opaque_task_id_generator__::currentId == 0)
    return Nullable<int32>();
  return Nullable<int32>(__opaque_task_id_generator__::currentId);
}
