#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.hpp"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Label.hpp"
#include "../../../../__OS/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Label::CreateHandle() {
  this->handle = __OS::FormsApi::Label::Create(*this);
  this->Control::CreateHandle();
}
