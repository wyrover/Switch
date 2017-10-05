#include "../../../../../include/Switch/System/Net/WebSockets/WebSocket.hpp"

using namespace System;
using namespace System::Net::WebSockets;

_property<TimeSpan, _readonly> System::Net::WebSockets::WebSocket::DefaultKeepAliveInterval {
  [] {return TimeSpan(30 * TimeSpan::TicksPerSecond);}
};
