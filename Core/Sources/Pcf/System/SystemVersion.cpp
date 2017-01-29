#include "../../../Includes/Pcf/System/SystemVersion.h"

const System::Version& Pcf::GetVersion() {
  static System::Version version(4, 0, 0);
  return version;
}

