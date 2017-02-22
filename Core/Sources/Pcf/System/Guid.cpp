#include "../../../Includes/Pcf/System/Guid.h"
#include "../../__OS/CoreApi.h"

System::Guid System::Guid::Empty;

System::Guid System::Guid::NewGuid() {
  return __OS::CoreApi::Environment::NewGuid();
}
