/// @file
/// @brief Contains Pcf::System::Compare class.
#pragma once

#include "../Static.h"
#include "../Types.h"
#include "../SharedPointer.h"
#include "IComparable.h"
#include "NullType.h"
#include "Object.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents API to compare object and primitive types.
    /// This class cannot be inherited.
    class Compare pcf_static {
    public:
      /// @brief Test equality between two values
      /// @param The two objects to compare
      /// @return bool true if the two objects are equal
      /// @exception ArgumentNullException one of the parameters is null.
      /// @remarks Relies on Equals method of the first object
      static bool Equals(const void* obj1, const void* obj2);

     /// @brief Test equality between two values
     /// @param The two objects to compare
     /// @return bool true if the two objects are equal
     /// @exception ArgumentNullException one of the parameters is null.
     /// @remarks Relies on Equals method of the first object
      template<typename T1, typename T2>
      static bool Equals(const SharedPointer<T1>& obj1, const SharedPointer<T2>& obj2) {
        return obj1.ToPointer() == obj2.ToPointer();
      }

      /// @brief Test equality between two objects
      /// @param The two objects to compare
      /// @return bool true if the two objects are equal
      /// @exception ArgumentNullException one of the parameters is null.
      /// @remarks Relies on Equals method of the first object
      static bool Equals(const Object& obj1, const Object& obj2);

      /// @brief Test equality between two objects
      /// @param The two objects to compare
      /// @return bool true if the two objects are equal
      /// @exception ArgumentNullException one of the parameters is null.
      /// @remarks Relies on Equals method of the first object
      static bool Equals(const NullType& obj1, const NullType& obj2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(bool val1, bool val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(char val1, char val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(sbyte val1, sbyte val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(int16 val1, int16 val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(int32 val1, int32 val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(int64 val1, int64 val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(byte val1, byte val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(uint16 val1, uint16 val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(uint32 val1, uint32 val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(uint64 val1, uint64 val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(double val1, double val2);

      /// @brief Test equality between two values
      /// @param The two values to compare
      /// @return bool true if the two values are equal
      static bool Equals(float val1, float val2);

      /// @brief Compare two objects
      /// @param The two IComparable objects to compare
      /// @return bool 0 if the two objects are identical, <0 if the first object is smaller than the latter, otherwise >1.
      /// @remarks Relies on CompareTo method of the first IComparable object
      static int32 CompareTo(const NullType& c1, const NullType& c2);

      template<typename T1, typename T2>
      static int32 CompareTo(SharedPointer<T1> c1, SharedPointer<T2> c2) {
        if (c1.ToPointer() < c2.ToPointer()) return -1;
        if (c1.ToPointer() > c2.ToPointer()) return 1;
        return 0;
      }

      template<typename T1, typename T2>
      static int32 CompareTo(const T1& c1, const T2& c2) {
        if(c1 < c2) return -1;
        if(c1 > c2) return 1;
        return 0;
      }

      /// @brief Compare two objects
      /// @param The two IComparable objects to compare
      /// @return bool 0 if the two objects are identical, <0 if the first object is smaller than the latter, otherwise >1.
      /// @remarks Relies on CompareTo method of the first IComparable object
      static int32 CompareTo(const IComparable& c1, const IComparable& c2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(const void* c1, const void* c2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(bool val1, bool val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(char val1, char val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(sbyte val1, sbyte val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(int16 val1, int16 val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(int32 val1, int32 val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(int64 val1, int64 val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(byte val1, byte val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(uint16 val1, uint16 val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(uint32 val1, uint32 val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(uint64 val1, uint64 val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(double val1, double val2);

      /// @brief Compare two values
      /// @param The two values to compare
      /// @return bool 0 if the two values are identical, <0 if the first is smaller than the latter, otherwise >1.
      static int32 CompareTo(float val1, float val2);
    };
  }
}

using namespace Pcf;
