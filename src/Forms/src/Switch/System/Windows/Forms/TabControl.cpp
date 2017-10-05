#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../../../__OS/FormsApi.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TabControl::CreateHandle() {
  this->handle = __OS::FormsApi::TabControl::Create(*this);
  this->Control::CreateHandle();
  __OS::FormsApi::TabControl::SetAlignment(*this);
}

void TabControl::SetAlignment(TabAlignment alignment) {
  if (this->alignment != alignment) {
    this->alignment = alignment;
    if (this->IsHandleCreated)
      __OS::FormsApi::TabControl::SetAlignment(*this);
  }
}

