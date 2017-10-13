#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include "Api.hpp"

using namespace System;

void Native::SystemSoundApi::Play(SoundType type) {
  @autoreleasepool {
    System::Collections::Generic::SortedDictionary<SoundType, string> sounds = {{SoundType::Beep, "Funk"}, {SoundType::Hand, "Sosumi"}, {SoundType::Question, "Purr"}, {SoundType::Exclamation, "Hero"}, {SoundType::Asterisk, "Glass"}, {(SoundType)0xFFFFFFFF, "Funk"}};
    [[NSSound soundNamed:[NSString stringWithUTF8String:sounds[type].c_str()]] play];
  }
}

#endif
