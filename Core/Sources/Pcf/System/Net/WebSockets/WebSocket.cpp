#include "../../../../../Includes/Pcf/System/Net/WebSockets/WebSocket.h"

using namespace System;
using namespace System::Net::WebSockets;

Property<TimeSpan, ReadOnly> System::Net::WebSockets::WebSocket::DefaultKeepAliveInterval {
  [] {return TimeSpan(30 * TimeSpan::TicksPerSecond);}
};
