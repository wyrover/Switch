#pragma once

#include "../../../Includes/Pcf/Types.h"

/// @cond
namespace Pcf {
  namespace Os {
    class UnicodeCharacters {
    public:
      static bool ValidateCodePoint(uint32 codePoint);
      static bool IsAlpha(uint32 codePoint);
      static bool IsDigit(uint32 codePoint);
      static bool IsPunctuation(uint32 codePoint);
    };
  }
}

using namespace Pcf;
/// @endcond
