#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Panel.h"
#include "../../../../__OS/FormsApi.h"

#include <Pcf/System/EventArgs.h>
#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Panel::CreateHandle() {
  __OS::FormsApi::Control::Create(*this);
  this->Control::CreateHandle();
}


