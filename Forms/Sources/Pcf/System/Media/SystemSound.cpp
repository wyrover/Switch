#include "../../../../Includes/Pcf/System/Media/SystemSound.h"
#include "../../../__OS/FormsApi.h"

using namespace System::Media;

void SystemSound::Play() const {
  __OS::FormsApi::Application::MessageBeep(this->type);
}
