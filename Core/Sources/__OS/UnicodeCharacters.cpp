#include <fstream>
#include <stack>
#include <vector>

#include "CoreApi.hpp"

bool __OS::CoreApi::UnicodeCharacters::ValidateCodePoint(uint32 codePoint) {
  if (codePoint > 0x0010FFFFu) return false;
  if (codePoint >= 0xD800u && codePoint <= 0xDFFFu) return false;
  return true;
}

bool __OS::CoreApi::UnicodeCharacters::IsAlpha(uint32 codePoint) {
  return __OS::CoreApi::UnicodeEncodings::IsAlpha(codePoint);
}

bool __OS::CoreApi::UnicodeCharacters::IsDigit(uint32 codePoint) {
  return __OS::CoreApi::UnicodeEncodings::IsDigit(codePoint);
}

bool __OS::CoreApi::UnicodeCharacters::IsPunctuation(uint32 codePoint) {
  return __OS::CoreApi::UnicodeEncodings::IsPunctuation(codePoint);
}
