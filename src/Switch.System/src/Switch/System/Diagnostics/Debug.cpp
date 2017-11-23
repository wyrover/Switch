#include "../../../../include/Switch/System/Diagnostics/Debug.hpp"

using namespace System;
using namespace System::Diagnostics;

namespace {
  static bool autoFlush = false;
  static int32 indentLevel = 0;
  static int32 indentSize = 4;
  static bool useGlobalLock = true;
}

_property<bool> Debug::AutoFlush {
  [] {return autoFlush;},
  [](bool value) {autoFlush = value;}
};

_property<int32> Debug::IndentLevel {
  [] {return indentLevel;},
  [](int32 value) {
    indentLevel = value;
    for(auto& listener : Trace::__get_listeners__())
      listener.IndentLevel = indentLevel;
  }
};

_property<int32> Debug::IndentSize {
  [] {return indentSize;},
  [](int32 value) {
    indentSize = value;
    for(auto& listener : Trace::__get_listeners__())
      listener.IndentSize = indentSize;
  }
};

_property<TraceListenerCollection&, _readonly> Debug::Listeners {
  []()->TraceListenerCollection& {return Trace::__get_listeners__();}
};

_property<bool> Debug::UseGlobalLock {
  [] {return useGlobalLock;},
  [](bool value) {useGlobalLock = value;}
};
