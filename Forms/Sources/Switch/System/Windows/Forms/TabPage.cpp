#include "../../../../../Includes/Switch/System/Windows/Forms/TabPage.hpp"
#include "../../../../../Includes/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../../../__OS/FormsApi.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TabPage::CreateHandle() {
  this->handle = __OS::FormsApi::TabPage::Create(*this);
  this->Control::CreateHandle();
}

void TabPage::SetParent(ref<Control> parent) {
  if (!is<TabControl>(parent))
    throw ArgumentException(sw_current_information);
  Control::SetParent(parent);
}
