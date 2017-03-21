#include <cstdarg>
#include <cstdlib>
#include <ctime>

#include "../../../../Includes/Pcf/System/Diagnostics/ProcessStartInfo.h"
#include "../../../__OS/CoreApi.h"

using namespace System;
using namespace System::Diagnostics;

string ProcessStartInfo::GetPasswordInClearText() const {
  return __OS::CoreApi::Security::ToUnsecureString(this->data->password);
}

void ProcessStartInfo::SetPasswordInClearText(const string& password) {
  this->data->password = __OS::CoreApi::Security::ToSecureSecureString(password);
}

Array<string> ProcessStartInfo::GetVerbs(const string& fileName) {
  return {};
}
