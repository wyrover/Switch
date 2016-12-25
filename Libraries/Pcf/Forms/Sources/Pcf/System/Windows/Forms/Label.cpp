#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Label.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Label::CreateHandle() {
  this->data->handle = __OS::FormsApi::Control::Create(*this);
  this->Control::CreateHandle();
}
