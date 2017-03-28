#include "../../../../Includes/Pcf/System/Diagnostics/DefaultTraceListener.h"
#include "../../../__OS/CoreApi.h"

using namespace System::Diagnostics;

void DefaultTraceListener::WriteToOutputDebug(const string& message) {
  __OS::CoreApi::Debugger::Log(0, "", message);
}

