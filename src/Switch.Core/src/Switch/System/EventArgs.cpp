#include "../../../include/Switch/System/EventArgs.hpp"

using namespace System;

_property<EventArgs, _readonly> EventArgs::Empty {
  [] {return EventArgs(); }
};
