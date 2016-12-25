#pragma once

#include "../../../Includes/Pcf/Types.h"
#include "../../../Includes/Pcf/System/PlatformID.h"
#include "../../../Includes/Pcf/System/String.h"

/// @cond
namespace Pcf {
  namespace Os {
    /// @brief Represents an Os Interface that provides the access random API.
    /// Internal used only.
    class Information final {
    public:
      static string NewLine();
      static System::PlatformID GetOsPlatformID();
      static int32 GetOsVersion(int32& major, int32& minor, int32& build, int32& revision);
      static bool IsOs64Bit();
      static string GetMachineName();
      static int32 GetTickCount();
      static string GetUserDomainName();
      static bool GetUserInteractive();
      #undef GetUserName
      static string GetUserName();
      static int64 GetWorkingSet();

    private:
      Information() = delete;
    };
  }
}

using namespace Pcf;
/// @endcond
