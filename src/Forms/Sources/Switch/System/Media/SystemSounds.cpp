#include "../../../../Includes/Switch/System/Media/SystemSounds.hpp"

using namespace System::Media;

struct __opaque_sound_access__ {
  SystemSound operator()(System::Windows::Forms::MessageBoxIcon type) {
    return SystemSound(type);
  }
};

_property<SystemSound, _readonly> SystemSounds::Asterisk {
  [] {return __opaque_sound_access__()(System::Windows::Forms::MessageBoxIcon::Asterisk);}
};

_property<SystemSound, _readonly> SystemSounds::Beep {
  [] {return __opaque_sound_access__()((System::Windows::Forms::MessageBoxIcon)0);}
};

_property<SystemSound, _readonly> SystemSounds::Exclamation {
  [] {return __opaque_sound_access__()(System::Windows::Forms::MessageBoxIcon::Exclamation);}
};

_property<SystemSound, _readonly> SystemSounds::Hand {
  [] {return __opaque_sound_access__()(System::Windows::Forms::MessageBoxIcon::Hand);}
};

_property<SystemSound, _readonly> SystemSounds::Question {
  [] {return __opaque_sound_access__()(System::Windows::Forms::MessageBoxIcon::Question);}
};
