#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Label.hpp"
#include "../../../../Native/FormsApi.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Label::CreateHandle() {
  this->handle = Native::FormsApi::Label::Create(*this);
  this->Control::CreateHandle();
}
