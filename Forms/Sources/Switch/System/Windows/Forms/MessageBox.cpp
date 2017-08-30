#include "../../../../../Includes/Switch/System/Windows/Forms/MessageBox.hpp"
#include "../../../../../Includes/Switch/System/Media/SystemSounds.hpp"
#include "../../../../__OS/FormsApi.hpp"

using namespace System;
using namespace System::Windows::Forms;

DialogResult MessageBox::Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  System::Collections::Generic::SortedDictionary<MessageBoxIcon, Action<>> messageBeep = {{MessageBoxIcon::None, pcf_delegate {}}, {MessageBoxIcon::Hand, {System::Media::SystemSounds::Hand(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Question, {System::Media::SystemSounds::Question(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Exclamation, {System::Media::SystemSounds::Exclamation(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Asterisk, {System::Media::SystemSounds::Asterisk(), &System::Media::SystemSound::Play}}};
  messageBeep[icon]();
  return __OS::FormsApi::Application::ShowMessageBox(message, caption, buttons, icon, defaultButton, options, displayHelpButton);
}
