#include "../../../Includes/Pcf/System/Guid.hpp"
#include "../../__OS/CoreApi.hpp"

System::Guid System::Guid::Empty;

System::Guid System::Guid::NewGuid() {
  return __OS::CoreApi::Environment::NewGuid();
}
