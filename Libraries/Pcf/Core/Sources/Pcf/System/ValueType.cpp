#include "../../../Includes/Pcf/System/String.h"
#include "../../../Includes/Pcf/System/ValueType.h"
#include "../../../Includes/Pcf/System/Convert.h"

using namespace System;

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4389)
#endif

bool ValueType::Equals(const ValueType& valueType) const {
  const IConvertible* first = dynamic_cast<const IConvertible*>(this);
  const IConvertible* second = dynamic_cast<const IConvertible*>(&valueType);
  
  if (first == null || second == null)
    return false;
  
  if (IsSigned() && valueType.IsSigned())
    return Convert::ToInt64(*first) == Convert::ToInt64(*second);
  
  if (IsSigned() && !valueType.IsSigned())
    return Convert::ToInt64(*first) >= 0 && (uint64)Convert::ToInt64(*first) == Convert::ToUInt64(*second);
  
  if (!IsSigned() && valueType.IsSigned())
    return Convert::ToInt64(*second) >= 0 && Convert::ToUInt64(*first) == (uint64)Convert::ToInt64(*second);
  
  if (!IsSigned() && !valueType.IsSigned())
    return Convert::ToUInt64(*first) == Convert::ToUInt64(*second);
  
  return object::Equals((const object&)valueType);
}

bool ValueType::Equals(const object& obj) const {
  return is<ValueType>(obj) && Equals((const ValueType&)obj);
}

#if _WIN32
#pragma warning(pop)
#endif
