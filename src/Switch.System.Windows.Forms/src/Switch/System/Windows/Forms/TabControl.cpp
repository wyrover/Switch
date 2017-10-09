#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../../../Native/FormsApi.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TabControl::CreateHandle() {
  this->handle = Native::FormsApi::TabControl::Create(*this);
  this->Control::CreateHandle();
  Native::FormsApi::TabControl::SetAlignment(*this);
}

void TabControl::SetAlignment(TabAlignment alignment) {
  if (this->alignment != alignment) {
    this->alignment = alignment;
    if (this->IsHandleCreated)
      Native::FormsApi::TabControl::SetAlignment(*this);
  }
}

