#include "../../../Includes/Switch/System/SystemVersion.hpp"

System::Collections::Generic::SortedDictionary<string, System::Reflexion::Assembly> System::Reflexion::Assembly::assemblies;

const System::Version& Switch::GetVersion() {
  static System::Version version(0, 3, 0);
  return version;
}

