#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Panel.hpp"
#include "../../../../__OS/FormsApi.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Panel::CreateHandle() {
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

