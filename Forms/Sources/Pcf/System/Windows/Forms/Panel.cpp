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
  if (!this->backColor.HasValue && Environment::OSVersion().Platform == PlatformID::MacOSX)
    this->backColor = Color::White;
  this->handle = __OS::FormsApi::Panel::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::Panel::SetBorderStyle(*this);
}

void Panel::SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
  if (this->borderStyle != borderStyle) {
    this->borderStyle = borderStyle;
    if (this->IsHandleCreated)
      __OS::FormsApi::Panel::SetBorderStyle(*this);
  }
}

