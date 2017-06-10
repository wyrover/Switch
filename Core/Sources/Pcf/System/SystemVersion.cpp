#include "../../../Includes/Pcf/System/SystemVersion.hpp"

System::Collections::Generic::SortedDictionary<string, System::Reflexion::Assembly> System::Reflexion::Assembly::assemblies;

const System::Version& Pcf::GetVersion() {
  static System::Version version(0, 2, 0);
  return version;
}

