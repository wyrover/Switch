#include "../../../../Includes/Pcf/System/Media/SystemSounds.h"

using namespace System::Media;

struct __opaque_snd_access__ {
  SystemSound operator()(System::Windows::Forms::MessageBoxIcon type) {
    return SystemSound(type);
  }
};

Property<SystemSound, ReadOnly> SystemSounds::Asterisk {
  [] {return __opaque_snd_access__()(System::Windows::Forms::MessageBoxIcon::Asterisk);}
};

Property<SystemSound, ReadOnly> SystemSounds::Beep {
  [] {return __opaque_snd_access__()((System::Windows::Forms::MessageBoxIcon)0);}
};

Property<SystemSound, ReadOnly> SystemSounds::Exclamation {
  [] {return __opaque_snd_access__()(System::Windows::Forms::MessageBoxIcon::Exclamation);}
};

Property<SystemSound, ReadOnly> SystemSounds::Hand {
  [] {return __opaque_snd_access__()(System::Windows::Forms::MessageBoxIcon::Hand);}
};

Property<SystemSound, ReadOnly> SystemSounds::Question {
  [] {return __opaque_snd_access__()(System::Windows::Forms::MessageBoxIcon::Question);}
};
