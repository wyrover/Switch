#include "../../../Includes/Pcf/System/Guid.h"
#include "../../../Includes/Pcf/System/Random.h"
#include "../../__OS/CoreApi.h"

using namespace System;

Guid Guid::Empty;

Guid Guid::NewGuid() {
  return Guid(__OS::CoreApi::Environment::GenerateGuid());
}
