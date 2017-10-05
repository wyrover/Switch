#include "../../../include/Switch/System/Object.hpp"
#include "../../../include/Switch/System/String.hpp"
#include "../../../include/Switch/System/Type.hpp"

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
