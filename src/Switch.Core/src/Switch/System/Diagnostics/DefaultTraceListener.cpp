#include "../../../../include/Switch/System/Diagnostics/DefaultTraceListener.hpp"
#include "../../../Native/CoreApi.hpp"

using namespace System::Diagnostics;

void DefaultTraceListener::WriteToOutputDebug(const string& message) {
  Native::CoreApi::Debugger::Log(0, "", message);
}

