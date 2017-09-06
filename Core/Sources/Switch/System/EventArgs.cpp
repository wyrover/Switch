#include "../../../Includes/Switch/System/EventArgs.hpp"

using namespace System;

property<EventArgs, readonly> EventArgs::Empty {
  [] {return EventArgs(); }
};
