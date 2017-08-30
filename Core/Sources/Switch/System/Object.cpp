#include "../../../Includes/Switch/System/Object.hpp"
#include "../../../Includes/Switch/System/String.hpp"
#include "../../../Includes/Switch/System/Type.hpp"

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
