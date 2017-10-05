#include "../../../../include/Switch/System/Diagnostics/DefaultTraceListener.hpp"
#include "../../../__OS/CoreApi.hpp"

using namespace System::Diagnostics;

void DefaultTraceListener::WriteToOutputDebug(const string& message) {
  __OS::CoreApi::Debugger::Log(0, "", message);
}

