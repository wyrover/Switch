#include "../../../Includes/Switch/System/EventArgs.hpp"

using namespace System;

Property<EventArgs, ReadOnly> EventArgs::Empty {
  [] {return EventArgs(); }
};
