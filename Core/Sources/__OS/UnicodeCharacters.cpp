#include <fstream>
#include <stack>
#include <vector>

#include "CoreApi.hpp"

bool __OS::CoreApi::UnicodeCharacters::ValidateCodePoint(uint32 codePoint) {
  return codePoint <= 0x0010FFFFu && !(codePoint >= 0xD800u && codePoint <= 0xDFFFu);
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
