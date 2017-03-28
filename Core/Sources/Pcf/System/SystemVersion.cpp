#include "../../../Includes/Pcf/System/SystemVersion.h"

System::Collections::Generic::SortedDictionary<string, System::Reflexion::Assembly> System::Reflexion::Assembly::assemblies;

const System::Version& Pcf::GetVersion() {
  static System::Version version(4, 0, 0);
  return version;
}

