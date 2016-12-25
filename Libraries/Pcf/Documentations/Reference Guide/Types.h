/// @page TypesPage Types
///
/// The Corelib define Unboxed and Boxed types listed below. The Unboxed types is same as the native type. The Boxed type is a Pcf::System::ValueType inherited from object.
///
/// @section RemarksSection Remarks
/// For more performance prefere used Unboxed type. Used Boxed type when necessary, e.g., to parse, polymorphism, ...
///
/// @section TypesListSection Types list
/// | Unboxed type | Boxed type            | C++14 type  | C++98 type                                   | Size in bytes  | Value                                                                         |
/// |--------------|-----------------------|-------------|----------------------------------------------|----------------|-------------------------------------------------------------------------------|
/// | bool         | Pcf::System::Boolean  | bool        | bool                                         |              1 | Represents a Boolean value.                                                   |
/// | byte         | Pcf::System::Byte     | uin8_t      | unsigned char                                |              1 | Represents a 8-bit unsigned integer.                                          |
/// | /            | Pcf::System::DateTime | /           | /                                            |              8 | Represents an instant in time, typically expressed as a date and time of day. |
/// | double       | Pcf::System::Double   | doudle      | doudle                                       |              8 | Represents a double-precision floating-point number.                          |
/// | int16        | Pcf::System::Int16    | int16_t     | short                                        |              2 | Represents a 16-bit signed integer.                                           |
/// | int32        | Pcf::System::Int32    | int32_t     | int                                          |              4 | Represents a 32-bit signed integer.                                           |
/// | int64        | Pcf::System::Int64    | int64_t     | long long                                    |              8 | Represents a 64-bit signed integer.                                           |
/// | intptr       | Pcf::System::IntPtr   | intptr_t    | int* - or - long long* (1)                   | 4 - or - 8 (1) | Represent a pointer or a handle.                                              |
/// | sbyte        | Pcf::System::SByte    | uin8_t      | unsigned char*                               |              1 | Represents a 8-bit unsigned integer.                                          |
/// | float        | Pcf::System::Single   | float       | float                                        |              4 | Represents a single-precision floating-point number.                          |
/// | char*        | Pcf::System::String   | std::string | char*                                        |       variable | Represents text as a series of Unicode characters.                            |
/// | char32       | Pcf::System::Char     | char32_t    | int32                                        |              4 | Represents a Unicode characters.                                              |
/// | uint16       | Pcf::System::UInt16   | uint16_t    | unsigned short                               |              2 | Represents a 16-bit unsigned integer.                                         |
/// | uint32       | Pcf::System::UInt32   | uint32_t    | unsigned int                                 |              4 | Represents a 32-bit unsigned integer.                                         |
/// | uint64       | Pcf::System::UInt64   | uint64_t    | unsigned long long                           |              8 | Represents a 64-bit unsigned integer.                                         |
/// | uintptr      | Pcf::System::UIntPtr  | uintptr_t   | unsigned int* - or - unsigned long long* (1) | 4 - or - 8 (1) | Represent an unsigned pointer or a handle.                                    |
/// (1) Depend of build : if build in 32 bits the size is 4 bytes, if build in 64 bits the size is 8 bytes.
///
/// @section LimitsSection Limits
/// Pcf define the minimum and maximum constant value for each types.
/// | Type                  | Minimum value                     | Maximum value                     | Minimum Value             | Maximum Value               |
/// |-----------------------|-----------------------------------|-----------------------------------|---------------------------|-----------------------------|
/// | Pcf::System::Boolean  | Pcf::System::Boolean::False()     | Pcf::System::Boolean::True()      | false                     | true                        |
/// | Pcf::System::Byte     | Pcf::System::Byte::MinValue()     | Pcf::System::Byte::MaxValue()     | 0                         | 255                         |
/// | Pcf::System::DateTime | Pcf::System::DateTime::MinValue() | Pcf::System::DateTime::MaxValue() | midnight, January 1, 1970 | 03:14:07, Janyaury 19, 2038 |
/// | Pcf::System::Double   | Pcf::System::Double::MinValue()   | Pcf::System::Double::MaxValue()   | -1.79769e+308             | 1.79769e+308                |
/// | Pcf::System::Int16    | Pcf::System::Int16::MinValue()    | Pcf::System::Int16::MaxValue()    | -32768                    | 32767                       |
/// | Pcf::System::Int32    | Pcf::System::Int32::MinValue()    | Pcf::System::Int32::MaxValue()    | -2147483648               | 2147483647                  |
/// | Pcf::System::Int64    | Pcf::System::Int64::MinValue()    | Pcf::System::Int64::MaxValue()    | -9223372036854775808      | 9223372036854775807         |
/// | Pcf::System::SByte    | Pcf::System::SByte::MinValue()    | Pcf::System::SByte::MaxValue()    | -128                      | 127                         |
/// | Pcf::System::Single   | Pcf::System::Single::MinValue()   | Pcf::System::Single::MaxValue()   | -3.40282e+038f            | 3.40282e+038f               |
/// | Pcf::System::UInt16   | Pcf::System::UInt16::MinValue()   | Pcf::System::UInt16::MaxValue()   | 0                         | 65535                       |
/// | Pcf::System::UInt32   | Pcf::System::UInt32::MinValue()   | Pcf::System::UInt32::MaxValue()   | 0                         | 4294967295                  |
/// | Pcf::System::UInt64   | Pcf::System::UInt64::MinValue()   | Pcf::System::UInt64::MaxValue()   | 0                         | 18446744073709551615        |
///
/// @section BoxingSection Boxing
/// For boxing a type into corresponding object class use keyword Box or Pcf::Boxer::Boxing method
///
/// @code
/// boolean readyUnboxed = true;
///
/// Boolean readyBoxed = Box(readyUnboxed);
/// @endcode
///
/// @section UnboxingSection Unboxing
/// For unboxing a object class into corresponding type use keyword Unbox or Pcf::Unboxer::Unboxing method
///
/// @code
/// Boolean readyBoxed = true;
///
/// boolean readyUnboxed = Unbox(readyBoxed);
/// @endcode
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
