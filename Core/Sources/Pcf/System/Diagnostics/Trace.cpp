#include "../../../../Includes/Pcf/System/Diagnostics/Trace.h"

using namespace System;
using namespace System::Diagnostics;

namespace {
  bool autoFlush = false;
  int32 indentLevel = 0;
  int32 indentSize = 4;
  bool useGlobalLock = true;
}

TraceListenerCollection Trace::listeners  {DefaultTraceListener()};
object Trace::lock;

Property<bool> Trace::AutoFlush {
  [] {return autoFlush;},
  [](bool value) {autoFlush = value;}
};

Property<int32> Trace::IndentLevel {
  [] {return indentLevel;},
  [](int32 value) {
    indentLevel = value;
    for (auto& listener : __get_listeners__())
      listener.IndentLevel = indentLevel;
  }
};

Property<int32> Trace::IndentSize {
  [] {return indentSize;},
  [](int32 value) {
    indentSize = value;
    for (auto& listener : __get_listeners__())
      listener.IndentSize = indentSize;
  }
};

Property<TraceListenerCollection&, ReadOnly> Trace::Listeners {
  []()->TraceListenerCollection& {return __get_listeners__();}
};

Property<bool> Trace::UseGlobalLock {
  [] {return useGlobalLock;},
  [](bool value) {useGlobalLock = value;}
};
