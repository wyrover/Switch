#include "../../../Includes/Switch/System/Boolean.hpp"
#include "../../../Includes/Switch/System/DateTime.hpp"
#include "../../../Includes/Switch/System/FormatException.hpp"

using namespace System;

_property<bool, _readonly> Boolean::False {
  [] {return false;}
};

_property<bool, _readonly> Boolean::True {
  [] {return true;}
};

_property<String, _readonly> Boolean::FalseString{
  [] {return "False";}
};

_property<String, _readonly> Boolean::TrueString {
  [] {return "True";}
};

bool Boolean::Parse(const String& str) {
  bool value;
  if (TryParse(str, value) == false)
    throw FormatException(_caller);
  return value;
}

bool Boolean::TryParse(const String& str, bool& value) {
  String trimed  = str.TrimStart(' ').TrimEnd(' ');
  if (String::Compare(trimed, TrueString, true) != 0 && String::Compare(trimed, FalseString, true) != 0)
    return false;
  value = String::Compare(trimed, TrueString, true) == 0;
  return true;
}

String Boolean::ToString() const {
  return this->value ? TrueString : FalseString;
}

DateTime Boolean::ToDateTime(const IFormatProvider& provider) const {
  return this->value ? DateTime::MaxValue : DateTime::MinValue;
}

String Boolean::ToString(const IFormatProvider& provider) const {
  return ToString();
}
