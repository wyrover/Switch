#include "../../../../include/Switch/System/Media/SystemSound.hpp"
#include "../../../Native/FormsApi.hpp"

using namespace System::Media;

void SystemSound::Play() const {
  Native::FormsApi::Application::MessageBeep(this->type);
}
