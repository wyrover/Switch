#include "../../../Includes/Pcf/System/EventArgs.h"

using namespace System;

Property<EventArgs, ReadOnly> EventArgs::Empty {
  [] {return EventArgs(); }
};
