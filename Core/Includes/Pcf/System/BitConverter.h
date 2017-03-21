/// @file
/// @brief Contains Pcf::System::BitConverter class.
#pragma once

#include "../Property.h"
#include "../Types.h"
#include "Array.h"
#include "Boolean.h"
#include "Char.h"
#include "Convert.h"
#include "String.h"
#include "Text/StringBuilder.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Converts base data types to an array of bytes, and an array of bytes to base data types.
    /// @remarks The BitConverter class helps manipulate value types in their fundamental form, as a series of bytes. A byte is defined as an 8-bit unsigned integer. The BitConverter class includes static methods to convert each of the primitive types to and from an array of bytes, as the following table illustrates.
    /// | Type     | To byte conversion                                | From byte conversion                                                  |
    /// |----------|---------------------------------------------------|-----------------------------------------------------------------------|
    /// | bool     | GetBytes(Boolean)                                 | ToBoolean(const Array< byte >&, int32)                                |
    /// | char32   | GetBytes(Char)                                    | ToChar(const Array< byte >&, int32)                                  |
    /// | double   | GetBytes(double) - or - DoubleToInt64Bits(double) | ToDouble(const Array< byte >&, int32) - or - Int64BitsToDouble(int64) |
    /// | int16    | GetBytes(int16)                                   | ToInt16(const Array< byte >&, int32)                                  |
    /// | int32    | GetBytes(int32)                                   | ToInt32(const Array< byte >&, int32)                                  |
    /// | int64    | GetBytes(int64)                                   | ToInt64(const Array< byte >&, int32)                                  |
    /// | float    | GetBytes(float) - or - SingleToInt32Bits(float)   | ToSingle(const Array< byte >&, int32) - or - Int32BitsToSingle(int32) |
    /// | uint16   | GetBytes(uint16)                                  | ToUInt16(const Array< byte >&, int32)                                 |
    /// | uint32   | GetBytes(uint32)                                  | ToUInt32(const Array< byte >&, int32)                                 |
    /// | uint64   | GetBytes(uint64)                                  | ToUInt64(const Array< byte >&, int32)                                 |
    class pcf_public BitConverter {
    public:
      /// @brief Converts the specified double-precision floating point number to a 64-bit signed integer.
      /// @param value The number to convert.
      /// @return A 64-bit signed integer whose value is equivalent to value.
      /// @remarks The order of bits in the integer returned by the DoubleToInt64Bits method depends on whether the computer architecture is little-endian or big-endian.
      static int64 DoubleToInt64Bits(double value) {return *((int64*)&value);}

      /// @brief Indicates the byte order ("endianness") in which data is stored in this computer architecture.
      /// @return Returns true if the architecture is little-endian; false if it is big-endian.
      /// @remarks Different computer architectures store data using different byte orders. "Big-endian" means the most significant byte is on the left end of a word. "Little-endian" means the most significant byte is on the right end of a word.
      /// @par Examples
      /// The following code example illustrates the use of the IsLittleEndian field.
      /// @include BitConverter.IsLittleEndian.cpp
       static Property<bool, ReadOnly> IsLittleEndian;

      /// @brief Returns the specified Boolean value as an array of bytes.
      /// @param value A Boolean value.
      /// @return An array of bytes with length 1.
      /// @par Examples
      /// The following code example converts the bit patterns of Boolean values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesBoolean.cpp
      static Array<byte> GetBytes(bool value) {return {Convert::ToByte(value)};}
      
      /// @brief Returns the specified Char value as an array of bytes.
      /// @param value A Char value.
      /// @return An array of bytes with length 4.
      /// @par Examples
      /// The following code example converts the bit patterns of Char values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesChar.cpp
      static Array<byte> GetBytes(char value) {return GetBytes(((uint32)value));}
      
      /// @brief Returns the specified Char value as an array of bytes.
      /// @param value A Char value.
      /// @return An array of bytes with length 4.
      /// @par Examples
      /// The following code example converts the bit patterns of Char values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesChar.cpp
      static Array<byte> GetBytes(char16 value) {return GetBytes(((uint32)value));}
      
      /// @brief Returns the specified Char value as an array of bytes.
      /// @param value A Char value.
      /// @return An array of bytes with length 4.
      /// @par Examples
      /// The following code example converts the bit patterns of Char values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesChar.cpp
      static Array<byte> GetBytes(char32 value) {return GetBytes(((uint32)value));}
      
      /// @brief Returns the specified Char value as an array of bytes.
      /// @param value A Char value.
      /// @return An array of bytes with length 4.
      /// @par Examples
      /// The following code example converts the bit patterns of Char values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesChar.cpp
      static Array<byte> GetBytes(wchar value) {return GetBytes(((uint32)value));}
      
      /// @brief Returns the specified double value as an array of bytes.
      /// @param value A double value.
      /// @return An array of bytes with length 8.
      /// @par Examples
      /// The following code example converts the bit patterns of double values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesDouble.cpp
      static Array<byte> GetBytes(double value) {return GetBytes(DoubleToInt64Bits(value));}

      /// @brief Returns the specified int16 value as an array of bytes.
      /// @param value A int16 value.
      /// @return An array of bytes with length 2.
      /// @par Examples
      /// The following code example converts the bit patterns of int16 values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesInt16.cpp
      static Array<byte> GetBytes(int16 value) {return GetBytes(uint16(value));}

      /// @brief Returns the specified int32 value as an array of bytes.
      /// @param value A int32 value.
      /// @return An array of bytes with length 4.
      /// @par Examples
      /// The following code example converts the bit patterns of int32 values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesInt32.cpp
      static Array<byte> GetBytes(int32 value) {return GetBytes(uint32(value));}

      /// @brief Returns the specified int64 value as an array of bytes.
      /// @param value A int64 value.
      /// @return An array of bytes with length 8.
      /// @par Examples
      /// The following code example converts the bit patterns of int64 values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesInt64.cpp
      static Array<byte> GetBytes(int64 value) {return GetBytes(uint64(value));}

      /// @brief Returns the specified single value as an array of bytes.
      /// @param value A single value.
      /// @return An array of bytes with length 4.
      /// @par Examples
      /// The following code example converts the bit patterns of single values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesSingle.cpp
      static Array<byte> GetBytes(float value) {return GetBytes(SingleToInt32Bits(value));}

      /// @brief Returns the specified uint16 value as an array of bytes.
      /// @param value A uint16 value.
      /// @return An array of bytes with length 2.
      /// @par Examples
      /// The following code example converts the bit patterns of uint16 values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesUInt16.cpp
      static Array<byte> GetBytes(uint16 value) {return {byte(value&0x00FF), byte((value&0xFF00)>> 8)};}

      /// @brief Returns the specified uint32 value as an array of bytes.
      /// @param value A uint32 value.
      /// @return An array of bytes with length 4.
      /// @par Examples
      /// The following code example converts the bit patterns of uint32 values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesUInt32.cpp
      static Array<byte> GetBytes(uint32 value){return {byte(value&0x000000FF), byte((value&0x0000FF00)>> 8), byte((value&0x00FF0000)>> 16), byte((value&0xFF000000)>> 24)};}

      /// @brief Returns the specified uint64 value as an array of bytes.
      /// @param value A uint64 value.
      /// @return An array of bytes with length 8.
      /// @par Examples
      /// The following code example converts the bit patterns of uint64 values to byte arrays with the GetBytes method.
      /// @include BitConverterGetBytesUInt64.cpp
      static Array<byte> GetBytes(uint64 value){return {byte(value&0x00000000000000FF), byte((value&0x000000000000FF00)>> 8), byte((value&0x0000000000FF0000)>> 16), byte((value&0x00000000FF000000)>> 24), byte((value&0x000000FF00000000)>> 32), byte((value&0x0000FF0000000000)>> 40), byte((value&0x00FF000000000000)>> 48), byte((value&0xFF00000000000000)>> 56)};}

      /// @cond
      static Array<byte> GetBytes(llong value) {return GetBytes(uint32(value));}
      static Array<byte> GetBytes(ullong value) {return GetBytes(uint32(value));}
      /// @endcond

      /// @brief Converts the specified 32-bit signed integer to a single-precision floating point number.
      /// @param value The number to convert.
      /// @return A single-precision floating point number whose value is equivalent to value.
      /// @remarks Typically, value is an integer that is returned by the SingleToInt32Bits method.
      static float Int32BitsToSingle(int32 value) {return *((float*)&value);}

      /// @brief Converts the specified 64-bit signed integer to a double-precision floating point number.
      /// @param value The number to convert.
      /// @return A double-precision floating point number whose value is equivalent to value.
      /// @remarks Typically, value is an integer that is returned by the DoubleToInt64Bits method.
      static double Int64BitsToDouble(int64 value) {return *((double*)&value);}

      /// @brief Converts the specified single-precision floating point number to a 32-bit signed integer.
      /// @param value The number to convert.
      /// @return A 32-bit signed integer whose value is equivalent to value.
      /// @remarks The order of bits in the integer returned by the DoubleToInt64Bits method depends on whether the computer architecture is little-endian or big-endian.
      static int32 SingleToInt32Bits(float value) {return *((int32*)&value);}

      /// @brief Returns a Boolean value converted from one byte at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return bool true if the byte at startIndex in value is nonzero; otherwise, false.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @par Examples
      /// The following code example converts elements of Byte arrays to Boolean values with the ToBoolean method.
      /// @include BitConverterToBoolean.cpp
      static bool ToBoolean(const Array<byte>& value, int32 startIndex) {
        if (startIndex < 0 || startIndex >= value.Length)
          throw ArgumentOutOfRangeException(pcf_current_information);
        return Convert::ToBoolean(value[startIndex]);
      }
      
      /// @brief Returns a char32 converted from two bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A char32 formed by four bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToChar method converts the bytes from index startIndex to startIndex + 3 to an Int32 value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static char32 ToChar(const Array<byte>& value, int32 startIndex){return char32(ToUInt32(value, startIndex));}

      /// @brief Returns a double-precision floating point number converted from eight bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A double precision floating point number formed by eight bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToDouble method converts the bytes from index startIndex to startIndex + 7 to a Double value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static double ToDouble(const Array<byte>& value, int32 startIndex) {return Int64BitsToDouble(ToInt64(value, startIndex));}

      /// @brief Returns a 16-bit signed integer converted from two bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A 16-bit signed integer formed by two bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToInt16 method converts the bytes from index startIndex to startIndex + 1 to an Int16 value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static int16 ToInt16(const Array<byte>& value, int32 startIndex) {return int16(ToUInt16(value, startIndex));}

      /// @brief Returns a 32-bit signed integer converted from two bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A 32-bit signed integer formed by four bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToInt32 method converts the bytes from index startIndex to startIndex + 3 to an Int32 value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static int32 ToInt32(const Array<byte>& value, int32 startIndex) {return int32(ToUInt32(value, startIndex));}

      /// @brief Returns a 64-bit signed integer converted from two bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A 64-bit signed integer formed by eight bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToInt64 method converts the bytes from index startIndex to startIndex + 7 to an Int64 value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static int64 ToInt64(const Array<byte>& value, int32 startIndex) {return int64(ToUInt64(value, startIndex));}

      /// @brief Returns a single-precision floating point number converted from eight bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A single precision floating point number formed by eight bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToSingle method converts the bytes from index startIndex to startIndex + 3 to a Double value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static float ToSingle(const Array<byte>& value, int32 startIndex) {return Int32BitsToSingle(ToInt32(value, startIndex));}

      /// @brief Returns a 16-bit unsigned integer converted from two bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A 16-bit unsigned integer formed by two bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToUInt16 method converts the bytes from index startIndex to startIndex + 1 to an UInt16 value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static uint16 ToUInt16(const Array<byte>& value, int32 startIndex) {
        if (startIndex == value.Length-1)
          throw ArgumentException(pcf_current_information);
        if (startIndex < 0 || startIndex > value.Length-1)
          throw ArgumentOutOfRangeException(pcf_current_information);
        return Convert::ToUInt16(value[startIndex]) + (Convert::ToUInt16(value[startIndex+1])<<8);
      }
      
      /// @brief Returns a 32-bit signed integer converted from two bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A 32-bit signed integer formed by four bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToUInt32 method converts the bytes from index startIndex to startIndex + 3 to an UInt32 value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static uint32 ToUInt32(const Array<byte>& value, int32 startIndex) {
        if (startIndex == value.Length-3)
          throw ArgumentException(pcf_current_information);
        if (startIndex < 0 || startIndex > value.Length-3)
          throw ArgumentOutOfRangeException(pcf_current_information);
        return Convert::ToUInt32(value[startIndex]) + (Convert::ToUInt32(value[startIndex+1])<<8) + (Convert::ToUInt32(value[startIndex+2])<<16) + (Convert::ToUInt32(value[startIndex+3])<<24);
      }
      
      /// @brief Returns a 64-bit unsigned integer converted from two bytes at a specified position in a byte array.
      /// @param value An array of bytes.
      /// @param startIndex he starting position within value.
      /// @return A 64-bit unsigned integer formed by eight bytes beginning at startIndex.
      /// @exception ArgumentException startIndex equals the length of value minus 1.
      /// @exception ArgumentNullException value is null
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The ToUInt64 method converts the bytes from index startIndex to startIndex + 7 to an UInt64 value. The order of bytes in the array must reflect the endianness of the computer system's architecture; for more information, see the Remarks section of the BitConverter class topic.
      static uint64 ToUInt64(const Array<byte>& value, int32 startIndex) {
        if (startIndex == value.Length-7)
          throw ArgumentException(pcf_current_information);
        if (startIndex < 0 || startIndex > value.Length-7)
          throw ArgumentOutOfRangeException(pcf_current_information);
        return Convert::ToUInt64(value[startIndex]) + (Convert::ToUInt64(value[startIndex+1])<<8) + (Convert::ToUInt64(value[startIndex+2])<<16) + (Convert::ToUInt64(value[startIndex+3])<<24) + (Convert::ToUInt64(value[startIndex+4])<<32) + (Convert::ToUInt64(value[startIndex+5])<<40) + (Convert::ToUInt64(value[startIndex+6])<<48) + (Convert::ToUInt64(value[startIndex+7])<<56);
      }
      
      /// @brief Converts the numeric value of each element of a specified array of bytes to its equivalent hexadecimal String representation.
      /// @param value An array of bytes.
      /// @return String A String of hexadecimal pairs separated by hyphens, where each pair represents the corresponding element in value; for example, "7F-2C-4A-00".
      /// @exception ArgumentNullException value is null.
      /// @remarks All the elements of value are converted. The order of hexadecimal strings returned by the ToString method depends on whether the computer architecture is little-endian or big-endian.
      /// @par Examples
      /// The following code example converts Byte arrays to String objects with the ToString method.
      /// @include BitConverterToString.cpp
      static String ToString(const Array<byte>& value) {return ToString(value, 0, value.Length);}

      /// @brief Converts the numeric value of each element of a specified subarray of bytes to its equivalent hexadecimal String representation.
      /// @param value An array of bytes.
      /// @param startIndex The starting position within value.
      /// @return String A String of hexadecimal pairs separated by hyphens, where each pair represents the corresponding element in value; for example, "7F-2C-4A-00".
      /// @exception ArgumentNullException value is null.
      /// @exception ArgumentOutOfRangeException startIndex is less than zero or greater than the length of value minus 1.
      /// @remarks The elements from array position startIndex to the end of the array are converted. The order of hexadecimal strings returned by the ToString method depends on whether the computer architecture is little-endian or big-endian.
      /// @par Examples
      /// The following code example converts Byte arrays to String objects with the ToString method.
      /// @include BitConverterToString2.cpp
      static String ToString(const Array<byte>& value, int32 startIndex) {return ToString(value, startIndex, value.Length-startIndex);}

      /// @brief Converts the numeric value of each element of a specified subarray of bytes to its equivalent hexadecimal String representation.
      /// @param value An array of bytes.
      /// @param startIndex The starting position within value.
      /// @param length The number of array elements in value to convert.
      /// @return String A String of hexadecimal pairs separated by hyphens, where each pair represents the corresponding element in value; for example, "7F-2C-4A-00".
      /// @exception ArgumentNullException value is null.
      /// @exception ArgumentOutOfRangeException startIndex or length is less than zero. -or- startIndex is greater than zero and is greater than or equal to the length of value.
      /// @exception ArgumentException The combination of startIndex and length does not specify a position within value; that is, the startIndex parameter is greater than the length of value minus the length parameter.
      /// @remarks AThe length elements from array position startIndex are converted. If length equals zero, the method returns String.Empty.
      /// @remarks The order of hexadecimal strings returned by the ToString method depends on whether the computer architecture is little-endian or big-endian.
      /// @par Examples
      /// The following code example converts Byte arrays to String objects with the ToString method.
      /// @include BitConverterToString3.cpp
      static String ToString(const Array<byte>& value, int32 startIndex, int32 length){
        if (value.Length == 0 && startIndex == 0 && length == 0) return "";
        if (startIndex < 0 || length < 0 || startIndex >= value.Length) throw ArgumentOutOfRangeException(pcf_current_information);
        if (startIndex + length > value.Length) throw ArgumentException(pcf_current_information);
        
        System::Text::StringBuilder str((startIndex + length)*3);
        for (int32 index = startIndex; index < startIndex + length; index++)
          str.Append(Byte(value[index]).ToString("X2")).Append(index < startIndex + length-1 ? "-" : "");
        return str.ToString();
      }
      
      /// @cond
       BitConverter() = delete;
      /// @endcond
    };
  }
}

using namespace Pcf;

