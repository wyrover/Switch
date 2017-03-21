#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/RadioButton.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void RadioButton::CreateHandle() {
  this->data->handle = __OS::FormsApi::Control::Create(*this);
  this->Control::CreateHandle();
}
