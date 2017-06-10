/// @file
/// @brief Contains Pcf::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Pcf/System/Enum.hpp>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief This Enumeration represents the styles the ProgressBar can take. Blocks and Continuous.  
        enum class ProgressBarStyle {
          /// @brief The progress bar displays the progress status as a segmented bar.  
          Blocks,
          /// @brief The progress bar displays the progress status in a smooth scrolling bar.  
          Continuous,
          /// @brief The progress bar displays the progress status in the marquee style.  
          Marquee
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::ProgressBarStyle> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::ProgressBarStyle::Blocks, "Blocks"}, {(int64)System::Windows::Forms::ProgressBarStyle::Continuous, "Continuous"}, {(int64)System::Windows::Forms::ProgressBarStyle::Marquee, "Marquee"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
