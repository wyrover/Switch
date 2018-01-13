#if defined(__APPLE__)
#include "Api.hpp"
#include "TargetConditionals.h"

#if !defined(TARGET_OS_IPHONE)
#import <Cocoa/Cocoa.h>

void Native::SystemSoundApi::Play(SoundType type) {
  @autoreleasepool {
    System::Collections::Generic::Dictionary<SoundType, string> sounds = {{SoundType::Beep, "Funk"}, {SoundType::Hand, "Sosumi"}, {SoundType::Question, "Purr"}, {SoundType::Exclamation, "Hero"}, {SoundType::Asterisk, "Glass"}, {(SoundType)0xFFFFFFFF, "Funk"}};
    [[NSSound soundNamed:[NSString stringWithUTF8String:sounds[type].c_str()]] play];
  }
}
#else
void Native::SystemSoundApi::Play(SoundType type) {
}
#endif

#endif
