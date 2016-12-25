#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Message.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

string Message::ToString() const {
  return string::Format("msg=0x{0:X} ({1}) hwnd=0x{2:X} wparam=0x{3:X} lparam=0x{4:X} result=0x{5:X}", this->msg, FormsApi::Control::MessageToString(this->msg), this->hwnd, this->WParam, this->lParam, this->result);
}
