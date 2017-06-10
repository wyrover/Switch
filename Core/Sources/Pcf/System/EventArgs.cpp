#include "../../../Includes/Pcf/System/EventArgs.hpp"

using namespace System;

Property<EventArgs, ReadOnly> EventArgs::Empty {
  [] {return EventArgs(); }
};
