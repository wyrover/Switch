#include "../../../../../Includes/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../Includes/Switch/System/Windows/Forms/GroupBox.hpp"
#include "../../../../__OS/FormsApi.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

GroupBox::GroupBox() {
  if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX)
    this->backColor = System::Drawing::Color::FromArgb(255, 228, 228, 228);
}

void GroupBox::CreateHandle() {
  this->handle = __OS::FormsApi::GroupBox::Create(*this);
  this->Control::CreateHandle();
}

