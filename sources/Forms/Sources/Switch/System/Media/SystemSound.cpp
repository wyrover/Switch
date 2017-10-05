#include "../../../../Includes/Switch/System/Media/SystemSound.hpp"
#include "../../../__OS/FormsApi.hpp"

using namespace System::Media;

void SystemSound::Play() const {
  __OS::FormsApi::Application::MessageBeep(this->type);
}
