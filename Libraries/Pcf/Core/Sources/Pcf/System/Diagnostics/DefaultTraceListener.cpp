#include "../../../../Includes/Pcf/System/Diagnostics/DefaultTraceListener.h"

#if _WIN32
#pragma warning(push)
#pragma warning(disable: 4201)
#include <windows.h>
#pragma warning(pop)
#else
#include <syslog.h>
#endif

using namespace System::Diagnostics;

void DefaultTraceListener::WriteToOutputDebug(const string& message) {
#if _WIN32
  OutputDebugStringA(message.Data);
#else
  syslog(LOG_USER|LOG_NOTICE, "%s", message.Data());
#endif
}

