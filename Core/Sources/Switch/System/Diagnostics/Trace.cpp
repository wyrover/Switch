#include "../../../../Includes/Switch/System/Diagnostics/Trace.hpp"

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

_property<bool> Trace::AutoFlush {
  [] {return autoFlush;},
  [](bool value) {autoFlush = value;}
};

_property<int32> Trace::IndentLevel {
  [] {return indentLevel;},
  [](int32 value) {
    indentLevel = value;
    for (auto& listener : __get_listeners__())
      listener.IndentLevel = indentLevel;
  }
};

_property<int32> Trace::IndentSize {
  [] {return indentSize;},
  [](int32 value) {
    indentSize = value;
    for (auto& listener : __get_listeners__())
      listener.IndentSize = indentSize;
  }
};

_property<TraceListenerCollection&, _readonly> Trace::Listeners {
  []()->TraceListenerCollection& {return __get_listeners__();}
};

_property<bool> Trace::UseGlobalLock {
  [] {return useGlobalLock;},
  [](bool value) {useGlobalLock = value;}
};
