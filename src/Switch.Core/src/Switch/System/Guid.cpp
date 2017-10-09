#include "../../../include/Switch/System/Guid.hpp"
#include "../../Native/CoreApi.hpp"

System::Guid System::Guid::Empty;

System::Guid System::Guid::NewGuid() {
  return Native::CoreApi::Environment::NewGuid();
}
