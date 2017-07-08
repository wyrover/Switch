#include "../../../../../Includes/Pcf/System/Windows/Forms/TabPage.hpp"
#include "../../../../../Includes/Pcf/System/Windows/Forms/TabControl.hpp"
#include "../../../../__OS/FormsApi.hpp"

#include <Pcf/System/EventArgs.hpp>
#include <Pcf/System/Drawing/SystemColors.hpp>

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
    throw ArgumentException(pcf_current_information);
  Control::SetParent(parent);
}
