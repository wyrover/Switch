#include "../../../../Includes/Switch/System/Media/SystemSounds.hpp"

using namespace System::Media;

struct __opaque_snd_access__ {
  SystemSound operator()(System::Windows::Forms::MessageBoxIcon type) {
    return SystemSound(type);
  }
};

property<SystemSound, readonly> SystemSounds::Asterisk {
  [] {return __opaque_snd_access__()(System::Windows::Forms::MessageBoxIcon::Asterisk);}
};

property<SystemSound, readonly> SystemSounds::Beep {
  [] {return __opaque_snd_access__()((System::Windows::Forms::MessageBoxIcon)0);}
};

property<SystemSound, readonly> SystemSounds::Exclamation {
  [] {return __opaque_snd_access__()(System::Windows::Forms::MessageBoxIcon::Exclamation);}
};

property<SystemSound, readonly> SystemSounds::Hand {
  [] {return __opaque_snd_access__()(System::Windows::Forms::MessageBoxIcon::Hand);}
};

property<SystemSound, readonly> SystemSounds::Question {
  [] {return __opaque_snd_access__()(System::Windows::Forms::MessageBoxIcon::Question);}
};
