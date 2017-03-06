#include "../../../../../Includes/Pcf/System/Windows/Forms/MessageBox.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Windows::Forms;

DialogResult MessageBox::Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon) {
  return __OS::FormsApi::Application::ShowMessageBox(message, caption, buttons, icon);
}
