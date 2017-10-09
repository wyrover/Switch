#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Panel.hpp"
#include "../../../../Native/FormsApi.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Panel::CreateHandle() {
  this->handle = Native::FormsApi::Panel::Create(*this);
  this->Control::CreateHandle();
  Native::FormsApi::Panel::SetBorderStyle(*this);
}

void Panel::SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
  if (this->borderStyle != borderStyle) {
    this->borderStyle = borderStyle;
    if (this->IsHandleCreated)
      Native::FormsApi::Panel::SetBorderStyle(*this);
  }
}

