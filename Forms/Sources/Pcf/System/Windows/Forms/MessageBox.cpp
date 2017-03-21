#include "../../../../../Includes/Pcf/System/Windows/Forms/MessageBox.h"
#include "../../../../../Includes/Pcf/System/Media/SystemSounds.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Windows::Forms;

DialogResult MessageBox::Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static System::Collections::Generic::SortedDictionary<MessageBoxIcon, Action<>> messageBeep = {{MessageBoxIcon::Hand, pcf_delegate {}}, {MessageBoxIcon::Hand, {System::Media::SystemSounds::Hand(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Question, {System::Media::SystemSounds::Question(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Exclamation, {System::Media::SystemSounds::Exclamation(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Asterisk, {System::Media::SystemSounds::Asterisk(), &System::Media::SystemSound::Play}}};
  messageBeep[icon]();
  return __OS::FormsApi::Application::ShowMessageBox(message, caption, buttons, icon, defaultButton, options, displayHelpButton);
}
