#include "../../../../Includes/Pcf/System/Media/SystemSounds.h"

using namespace System::Media;

Property<SystemSound, ReadOnly> SystemSounds::Asterisk {
  [] {return SystemSound(System::Windows::Forms::MessageBoxIcon::Asterisk);}
};

Property<SystemSound, ReadOnly> SystemSounds::Beep {
  [] {return SystemSound((System::Windows::Forms::MessageBoxIcon)0);}
};

Property<SystemSound, ReadOnly> SystemSounds::Exclamation {
  [] {return SystemSound(System::Windows::Forms::MessageBoxIcon::Exclamation);}
};

Property<SystemSound, ReadOnly> SystemSounds::Hand {
  [] {return SystemSound(System::Windows::Forms::MessageBoxIcon::Hand);}
};

Property<SystemSound, ReadOnly> SystemSounds::Question {
  [] {return SystemSound(System::Windows::Forms::MessageBoxIcon::Question);}
};
