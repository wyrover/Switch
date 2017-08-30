#include "../../../../../Includes/Switch/System/Net/WebSockets/WebSocket.hpp"

using namespace System;
using namespace System::Net::WebSockets;

Property<TimeSpan, ReadOnly> System::Net::WebSockets::WebSocket::DefaultKeepAliveInterval {
  [] {return TimeSpan(30 * TimeSpan::TicksPerSecond);}
};
