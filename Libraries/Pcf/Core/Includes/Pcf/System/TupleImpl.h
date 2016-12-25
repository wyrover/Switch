/// @file
/// @brief Contains Pcf::System::ITuple interface and Pcf::System::TupleImpl class.
#pragma once

#include "../Types.h"
#include "../Interface.h"
#include "Compare.h"
#include "Convert.h"
#include "Hash.h"
#include "IComparable.h"
#include "IHashable.h"
#include "NullType.h"
#include "Object.h"
#include "String.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @interface ITuple
    /// @brief Interface used only for TupleImpl class.
    /// Internal used only.
    class ITuple pcf_interface {
      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  * <b>Less than zero</b> This instance is less than obj.
      ///  * <b>Zero</b> This instance is equal to obj.
      ///  * <b>Greater than zero</b> This instance is greater than obj.
      virtual int32 CompareTo(const IComparable& obj) const = 0;

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return Boolean true if the specified object is equal to the current object. otherwise, false.
      /// @exception ArgumentNullException The parameters obj is null.
      /// @return @see object
      /// @return @see Boolean
      virtual bool Equals(const Object& obj) const = 0;
    };

    /// @brief Base class for n Tuple classes.
    /// Internal used only.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    class TupleImpl : public Object, public ITuple, public IComparable, public IHashable {
    protected:
      /// @cond
      TupleImpl() { }
      TupleImpl(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5, const T6& item6, const T7& item7, const T8& item8) : item1(item1), item2(item2), item3(item3), item4(item4), item5(item5), item6(item6), item7(item7), item8(item8) { }
      TupleImpl(const TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>& tuple) : item1(tuple.item1), item2(tuple.item2), item3(tuple.item3), item4(tuple.item4), item5(tuple.item5), item6(tuple.item6), item7(tuple.item7), item8(tuple.item8) { }
      /// @endcond

    public:
      /// @brief Copy operator of the TupleImpl <T1, T2, T3, T4, T5, T6, T7, T8> class.
      /// @param tuple The TupleImpl class to copy.
      /// @remarks You can also use the static TupleImpl::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>& operator =(const TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>& tuple) {
        item1 = tuple.item1;
        item2 = tuple.item2;
        item3 = tuple.item3;
        item4 = tuple.item4;
        item5 = tuple.item5;
        item6 = tuple.item6;
        item7 = tuple.item7;
        item8 = tuple.item8;
        return *this;
      }

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {
        if (!is<TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>>(obj))
          return 1;
        return CompareTo(static_cast<const TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>&>(obj));
      }

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>& tuple) const {
        int32 ret  = -1;
        if ((ret = System::Compare::CompareTo(item1, tuple.item1)) != 0)
          return ret;

        if ((ret = System::Compare::CompareTo(item2, tuple.item2)) != 0)
          return ret;

        if ((ret = System::Compare::CompareTo(item3, tuple.item3)) != 0)
          return ret;

        if ((ret = System::Compare::CompareTo(item4, tuple.item4)) != 0)
          return ret;

        if ((ret = System::Compare::CompareTo(item5, tuple.item5)) != 0)
          return ret;

        if ((ret = System::Compare::CompareTo(item6, tuple.item6)) != 0)
          return ret;

        if ((ret = System::Compare::CompareTo(item7, tuple.item7)) != 0)
          return ret;

        if ((ret = System::Compare::CompareTo(item8, tuple.item8)) != 0)
          return ret;

        return ret;
      }
      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      /// @exception ArgumentNullException The parameters obj is null.
      bool Equals(const Object& obj) const override {
        return is<TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>>(obj) && Equals(static_cast<const TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>&>(obj));
      }

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      /// @exception ArgumentNullException The parameters obj is null.
      bool Equals(const TupleImpl<T1, T2, T3, T4, T5, T6, T7, T8>& tuple) const {
        if (System::Compare::Equals(item1, tuple.item1) == false)
          return false;

        if (System::Compare::Equals(item2, tuple.item2) == false)
          return false;

        if (System::Compare::Equals(item3, tuple.item3) == false)
          return false;

        if (System::Compare::Equals(item4, tuple.item4) == false)
          return false;

        if (System::Compare::Equals(item5, tuple.item5) == false)
          return false;

        if (System::Compare::Equals(item6, tuple.item6) == false)
          return false;

        if (System::Compare::Equals(item7, tuple.item7) == false)
          return false;

        if (System::Compare::Equals(item8, tuple.item8) == false)
          return false;

        return true;
      }

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override { return System::Hash::GetHashCode(item1) ^ System::Hash::GetHashCode(item2) ^ System::Hash::GetHashCode(item3) ^ System::Hash::GetHashCode(item4) ^ System::Hash::GetHashCode(item5)  ^ System::Hash::GetHashCode(item6) ^ System::Hash::GetHashCode(item7)  ^ System::Hash::GetHashCode(item8); }

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      String ToString() const override {
        String str = "(";

        if (!IsNullType(item1))
          str += System::Convert::ToString(item1);

        if (!IsNullType(item2))
          str += ", " + System::Convert::ToString(item2);

        if (!IsNullType(item3))
          str += ", " + System::Convert::ToString(item3);

        if (!IsNullType(item4))
          str += ", " + System::Convert::ToString(item4);

        if (!IsNullType(item5))
          str += ", " + System::Convert::ToString(item5);

        if (!IsNullType(item6))
          str += ", " + System::Convert::ToString(item6);

        if (!IsNullType(item7))
          str += ", " + System::Convert::ToString(item7);

        if (!IsNullType(item8)) {
          String item8Str = System::Convert::ToString(item8);
          if (IsTuple(item8))
            item8Str = item8Str.Substring(1, item8Str.Length()-2);
          str += ", " + item8Str;
        }

        str+= ")";
        return str;
      }

    protected:
      /// @cond
      T1 item1;
      T2 item2;
      T3 item3;
      T4 item4;
      T5 item5;
      T6 item6;
      T7 item7;
      T8 item8;
      /// @endcond

    private :
      static bool IsTuple(const ITuple&) { return true; }
      template<typename T>
      static bool IsTuple(const SharedPointer<T>&) { return false; }
      static bool IsTuple(const NullType&) { return false; }
      static bool IsTuple(const bool&) { return false; }
      static bool IsTuple(const char&) { return false; }
      static bool IsTuple(const sbyte&) { return false; }
      static bool IsTuple(const int16&) { return false; }
      static bool IsTuple(const int32&) { return false; }
      static bool IsTuple(const int64&) { return false; }
      static bool IsTuple(const byte&) { return false; }
      static bool IsTuple(const uint16&) { return false; }
      static bool IsTuple(const uint32&) { return false; }
      static bool IsTuple(const uint64&) { return false; }
      static bool IsTuple(const double&) { return false; }
      static bool IsTuple(const float&)  { return false; }

      template<typename T>
      static bool IsNullType(const SharedPointer<T>&) { return false; }
      static bool IsNullType(const Object&) {  return false; }
      static bool IsNullType(const NullType&) { return true; }
      static bool IsNullType(const bool&) { return false; }
      static bool IsNullType(const char&) { return false; }
      static bool IsNullType(const sbyte&) { return false; }
      static bool IsNullType(const int16&) { return false; }
      static bool IsNullType(const int32&) { return false; }
      static bool IsNullType(const int64&) { return false; }
      static bool IsNullType(const byte&) { return false; }
      static bool IsNullType(const uint16&) { return false; }
      static bool IsNullType(const uint32&) { return false; }
      static bool IsNullType(const uint64&) { return false; }
      static bool IsNullType(const double&) { return false; }
      static bool IsNullType(const float&)  { return false; }
    };
  }
}

using namespace Pcf;
