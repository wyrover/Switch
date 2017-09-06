#include "../../../../../Includes/Switch/System/Net/WebSockets/WebSocket.hpp"

using namespace System;
using namespace System::Net::WebSockets;

property<TimeSpan, readonly> System::Net::WebSockets::WebSocket::DefaultKeepAliveInterval {
  [] {return TimeSpan(30 * TimeSpan::TicksPerSecond);}
};
