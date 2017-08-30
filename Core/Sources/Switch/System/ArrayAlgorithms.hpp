#pragma once

#include "../../../Includes/Switch/Types.hpp"
#include "../../../Includes/Switch/System/SystemException.hpp"

namespace {
  class ArrayAlgorithms {
  public:
    ArrayAlgorithms() = delete;
    inline static bool IsValidRange(int32 arraySize, int32 index, int count) {
      return ((index + count <= arraySize) || (arraySize == 0 && index == 1 && count == 0)) && index >= 0 && count >= 0;
    }
    
    template<typename T>
    inline static bool Contains(const T array[], int32 size, const T& item) {
      for (int32 i = 0; i < size; i++)
        if (array[i] == item)
          return true;
      return false;
    }
    
    static inline void ValidateArray(const void* array, int32 size) {
      if (size < 0)
        throw System::ArgumentException(pcf_current_information);
      if (array == null && size > 0)
        throw System::ArgumentNullException(pcf_current_information);
    }
    
    static inline void ValidateIndex(int32 index, int32 size) {
      if (index < 0 || index > size)
        throw System::ArgumentOutOfRangeException(pcf_current_information);
    }
    
    static inline void ValidateRange(int32 size, int32 index, int32 count) {
      if (! IsValidRange(size, index, count))
        throw System::ArgumentOutOfRangeException(pcf_current_information);
    }
  };
}

using namespace Switch;
