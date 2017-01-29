#include "../../../Includes/Pcf/System/Object.h"
#include "../../../Includes/Pcf/System/String.h"
#include "../../../Includes/Pcf/System/Type.h"

using namespace System;

Type Object::GetType() const {
  return Type(typeid(*this));
}

String Object::ToString() const {
  return GetType().ToString();
}

std::ostream& operator<<(std::ostream& output, const System::Object& value) {
  output << value.ToString();
  return output;
}

#include "WinsockDll.h"
