#include "../../../Includes/Pcf/System/Boolean.h"
#include "../../../Includes/Pcf/System/DateTime.h"
#include "../../../Includes/Pcf/System/FormatException.h"

using namespace System;

Property<bool, ReadOnly> Boolean::False {
  [] {return false;}
};

Property<bool, ReadOnly> Boolean::True {
  [] {return true;}
};

Property<String, ReadOnly> Boolean::FalseString{
  [] {return "False";}
};

Property<String, ReadOnly> Boolean::TrueString {
  [] {return "True";}
};

bool Boolean::Parse(const String& str) {
  bool value;
  if (TryParse(str, value) == false)
    throw FormatException(pcf_current_information);
  return value;
}

bool Boolean::TryParse(const String& str, bool& value) {
  String trimed  = str.TrimStart(' ').TrimEnd(' ');
  if (String::Compare(trimed, TrueString, true) != 0 && String::Compare(trimed, FalseString, true) != 0)
    return false;
  value = String::Compare(trimed, TrueString, true) == 0;
  return true;
}

String Boolean::ToString() const noexcept {
  return this->value ? TrueString : FalseString;
}

DateTime Boolean::ToDateTime(const IFormatProvider& provider) const {
  return this->value ? DateTime::MaxValue : DateTime::MinValue;
}

String Boolean::ToString(const IFormatProvider& provider) const {
  return ToString();
}
