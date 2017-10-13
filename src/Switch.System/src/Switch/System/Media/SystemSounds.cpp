#include "../../../../include/Switch/System/Media/SystemSounds.hpp"
#include "../../../Native/Api.hpp"

using namespace System::Media;

struct __opaque_sound_access__ {
  SystemSound operator()(Native::SoundType sounds) {
    return SystemSound((int)sounds);
  }
};

_property<SystemSound, _readonly> SystemSounds::Asterisk {
  [] {return __opaque_sound_access__()(Native::SoundType::Asterisk);}
};

_property<SystemSound, _readonly> SystemSounds::Beep {
  [] {return __opaque_sound_access__()(Native::SoundType::Beep);}
};

_property<SystemSound, _readonly> SystemSounds::Exclamation {
  [] {return __opaque_sound_access__()(Native::SoundType::Exclamation);}
};

_property<SystemSound, _readonly> SystemSounds::Hand {
  [] {return __opaque_sound_access__()(Native::SoundType::Hand);}
};

_property<SystemSound, _readonly> SystemSounds::Question {
  [] {return __opaque_sound_access__()(Native::SoundType::Question);}
};
