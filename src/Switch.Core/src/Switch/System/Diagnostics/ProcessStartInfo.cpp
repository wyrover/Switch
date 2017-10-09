#include <cstdarg>
#include <cstdlib>
#include <ctime>

#include "../../../../include/Switch/System/Diagnostics/ProcessStartInfo.hpp"
#include "../../../Native/CoreApi.hpp"

using namespace System;
using namespace System::Diagnostics;

string ProcessStartInfo::GetPasswordInClearText() const {
  return Native::CoreApi::Security::ToUnsecureString(this->data->password);
}

void ProcessStartInfo::SetPasswordInClearText(const string& password) {
  this->data->password = Native::CoreApi::Security::ToSecureSecureString(password);
}

Array<string> ProcessStartInfo::GetVerbs(const string& fileName) {
  return {};
}
