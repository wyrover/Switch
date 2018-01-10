/// @file
/// @brief Contains Switch::System::BoxEnum class.
#pragma once

#include "../Lock.hpp"
#include "../Types.hpp"
#include "Collections/Generic/List.hpp"
#include "Collections/Generic/KeyValuePair.hpp"
#include "Collections/Generic/Dictionary.hpp"
#include "Int64.hpp"
#include "Object.hpp"
#include "_String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    template<typename T>
    class BoxEnum : public Object, public IComparable {
    public:
      BoxEnum() {}
      BoxEnum(T value) : value(value) {}
      BoxEnum(int64 value) : value((T)value) {}

      /// @cond
      friend export_ std::ostream& operator<<(std::ostream& output, const BoxEnum& value) {return output << value.ToString();}
      /// @endcond

      String GetName() const {return !Values().ContainsKey((int64)this->value) ? String("") : Values()[(int64)this->value];}

      T Value() const {return this->value;}

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than obj.
      /// Zero                This instance is equal to obj.
      /// Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {
        if (!is<BoxEnum<T>>(obj)) return 1;
        return this->CompareTo(static_cast<const BoxEnum<T>&>(obj));
      }

      /// @brief Compares this instance to a specified Int32 object and returns an indication of their relative values.
      /// @param value An Int32 object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const BoxEnum<T>& value) const {return int32((int64)this->value - (int64)value.value);}

      /// @brief Determines whether this instance of Enum and a specified object, which must also be a Enum object, have the same value.
      /// @param value The Enum to compare with the current object.
      /// @return Boolean true if the specified value is equal to the current object. otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      bool Equals(const BoxEnum<T>& value) const {return this->value == value.value;}

      /// @brief Determines whether this instance of Enum and a specified object, which must also be a Enum object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return Boolean true if the specified object is equal to the current object. otherwise, false.
      /// @exception ArgumentNullException The parameters obj is null.
      bool Equals(const object& obj) const override { return is<BoxEnum<T>>(obj) && Equals(static_cast<const BoxEnum<T>&>(obj)); }

      /// @brief Set this Enum class with specified value.
      /// @param value An int32 as value.
      /// @return Enum This enum whose value is represented by value.
      /// @exception ArgumentException The value is ! a value of enumType.
      const BoxEnum<T>& FromInt32(int32 value) {
        this->value = (T)value;
        return *this;
      }

      /// @brief Set this Enum class with specified value.
      /// @param value An int32 as value.
      /// @return Enum This enum whose value is represented by value.
      /// @exception ArgumentException The value is ! a value of enumType.
      const BoxEnum<T>& FromInt64(int64 value) {
        this->value = (T)value;
        return *this;
      }

      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current object.
      virtual int32 GetHashCode() const override {return Int64((int64)this->value).GetHashCode();}

      /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
      /// @param value The value of a particular enumerated constant in terms of its underlying type.
      /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
      /// @exception ArgumentException The value is ! a value of enumType.
      static String GetName(T value);

      /// @brief Retrieves an array of the names of the constants in a specified enumeration.
      /// @return Array<String> A String array of the names of the constants in enumType.
      /// @exception ArgumentException The value is ! a value of enumType.
      static System::Array<String> GetNames() {return Values().Values().ToArray();}

      /// @brief Retrieves an array of the values of the constants in a specified enumeration.
      /// @return Array<T> An array that contains the values of the constants in enumType.
      /// @exception ArgumentException The value is ! a value of enumType.
      static System::Array<T> GetValues() {
        static System::Collections::Generic::List<T> keys;

        if (keys.Count == 0)
          for (auto key : Values().Keys())
            keys.Add(T(key));

        return keys.ToArray();
      }

      /// @brief Retrieves an array of the values of the constants in a specified enumeration.
      /// @param flag An enumeration value.
      /// @return Boolean true if the bit field or bit fields that are set in flag are also set in the current instance; otherwise, false.
      /// @remarks The HasFlag method returns the result of the following Boolean expression : thisInstance And flag = flag
      bool HasFlag(T flag) const {return this->HasFlag(int64(flag));}

      /// @brief Retrieves an array of the values of the constants in a specified enumeration.
      /// @param flag An enumeration value.
      /// @return Boolean true if the bit field or bit fields that are set in flag are also set in the current instance; otherwise, false.
      /// @remarks The HasFlag method returns the result of the following Boolean expression : thisInstance And flag = flag
      bool HasFlag(int64 flag) const {return ((int64)this->value & flag) == flag;}

      /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
      /// @param fromValue An enumeration value.
      /// @return Boolean true if a constant in enumType has a value equal to value; otherwise, false.
      /// @exception ArgumentException The value is ! a value of enumType.
      static bool IsDefined(T fromValue) {return IsDefined(int64(fromValue));}

      /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
      /// @param fromValue An enumeration value.
      /// @return Boolean true if a constant in enumType has a value equal to value; otherwise, false.
      /// @exception ArgumentException The value is ! a value of enumType.
      static bool IsDefined(int64 fromValue) {return Values().ContainsKey(fromValue);}

      /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
      /// @param value An A String containing the name or value to convert.
      /// @return Enum An enum whose value is represented by value.
      /// @exception ArgumentException The value is ! a value of enumType.
      static T Parse(const String& value) {return Parse(value, false);}

      /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
      /// @param str An A String containing the name or value to convert.
      /// @param ignoreCase true to Ignore case; false to regard case.
      /// @return Enum An enum whose value is represented by value.
      /// @exception ArgumentException The value is ! a value of enumType.
      static T Parse(const String& str, bool ignoreCase);

      int32 ToInt32() const {return int32(this->value);}
      int64 ToInt64() const {return int64(this->value);}

      static int32 ToInt32(T value);
      static int64 ToInt64(T value);

      String ToString() const override {
        Values();
        if (flags)
          return ToStringFlags();

        if (!Values().ContainsKey(int64(this->value)))
          return string::Format("{0}", int64(this->value));

        return Values()[int64(this->value)];
      }

      static String ToString(T value) {return GetName(value);}

      /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. The return value indicates whether the conversion succeeded.
      /// @param vaue The String representation of the enumeration name or underlying value to convert.
      /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
      /// @return true if the value parameter was converted successfully; otherwise, false.
      static bool TryParse(const String& value, T& result) {
        try {
          result = Parse(value);
          return true;
        } catch (...) {
          return false;
        }
      }

      /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. A parameter specifies whether the operation is case-sensitive. The return value indicates whether the conversion succeeded.
      /// @param vaue The String representation of the enumeration name or underlying value to convert.
      /// @param ignoreCase true to Ignore case; false to regard case.
      /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
      /// @return true if the value parameter was converted successfully; otherwise, false.
      static bool TryParse(const String& value, bool ignoreCase, T& result) {
        try {
          result = Parse(value, ignoreCase);
          return true;
        } catch (...) {
          return false;
        }
      }

      virtual void InitValues(Collections::Generic::Dictionary<int64, String>& values) = 0;

    protected:
      T value;
      static bool flags;

      static Collections::Generic::Dictionary<int64, String>& Values();
      void LoadValues() {
        lock_(this->values) {
          if (values.Count == 0)
            this->InitValues(values);
        }
      }

    private:
      static T ParseFlags(const String& str, bool ignoreCase);

      String ToStringFlags() const {
        if (int64(this->value) == 0 && !Values().ContainsKey(int64(this->value)))
          return "0";

        if (int64(this->value) == 0)
          return Values()[0];

        String str;
        int64 rest = int64(this->value);
        System::Collections::Generic::List<Collections::Generic::KeyValuePair<int64, String>> reversed;
        for (auto item : Values())
          reversed.Insert(0, item);

        for (auto item : reversed) {
          if (item.Key() != 0 && (rest & item.Key()) == item.Key()) {
            rest -= item.Key();
            if (str != String::Empty)
              str = ", " + str;
            str = Values()[item.Key()] + str;
          }
        }

        if (String::IsNullOrEmpty(str) || rest > 0)
          return  Int64((int64)this->value).ToString();

        return str;
      }

      static Collections::Generic::Dictionary<int64, String> values;
    };

    template<typename T>
    System::Collections::Generic::Dictionary<int64, String> System::BoxEnum<T>::values;

    template<typename T>
    bool System::BoxEnum<T>::flags = false;
  }
}

using namespace Switch;

