![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

The Switch define Unboxed and Boxed types listed below. The Unboxed types is same as the native type. The Boxed type is a System::ValueType inherited from object.

# Remarks

For more performance prefere used Unboxed type. Used Boxed type when necessary, e.g., to parse, polymorphism, ...

# Types list

| Unboxed type | Boxed type       | C++14 type  | C++98 type.                                  | Size in bytes  | Value                                                                         |
|--------------|------------------|-------------|----------------------------------------------|----------------|-------------------------------------------------------------------------------|
| bool         | System::Boolean  | bool        | bool                                         | 1              | Represents a Boolean value.                                                   |
| byte         | System::Byte     | uin8_t      | unsigned char                                | 1              | Represents a 8-bit unsigned integer.                                          |
| /            | System::DateTime | /           | /                                            | 8              | Represents an instant in time, typically expressed as a date and time of day. |
| double       | System::Double   | double      | double                                       | 8              | Represents a double-precision floating-point number.                          |
| int16        | System::Int16    | int16_t     | short                                        | 2              | Represents a 16-bit signed integer.                                           |
| int32        | System::Int32    | int32_t     | int                                          | 4              | Represents a 32-bit signed integer.                                           |
| int64        | System::Int64    | int64_t     | long long.                                   | 8              | Represents a 64-bit signed integer.                                           |
| intptr       | System::IntPtr   | intptr_t    | int* - or - long long* (1)                   | 4 - or - 8 (1) | Represent a pointer or a handle.                                              |
| sbyte        | System::SByte    | int8_t      | char                                         | 1              | Represents a 8-bit signed integer.                                            |
| float        | System::Single   | float       | float                                        | 4              | Represents a single-precision floating-point number.                          |
| char*        | System::String.  | std::string | char*                                        | variable       | Represents text as a series of Unicode characters.                            |
| char32       | System::Char     | char32_t    | int                                          | 4              | Represents a Unicode characters.                                              |
| uint16       | System::UInt16   | uint16_t    | unsigned short                               | 2              | Represents a 16-bit unsigned integer.                                         |
| uint32       | System::UInt32   | uint32_t    | unsigned int                                 | 4              | Represents a 32-bit unsigned integer.                                         |
| uint64       | System::UInt64   | uint64_t    | unsigned long long                           | 8              | Represents a 64-bit unsigned integer.                                         |
| uintptr      | System::UIntPtr  | uintptr_t   | unsigned int* - or - unsigned long long* (1) | 4 - or - 8 (1) | Represent an unsigned pointer or a handle.                                    |

(1) Depend of build : if build in 32 bits the size is 4 bytes, if build in 64 bits the size is 8 bytes.

# Limits

Switch define the minimum and maximum constant value for each types.

|Type              | Minimum Value              | Maximum Value              | Minimum Value             | Maximum Value               |
|------------------|----------------------------|----------------------------|---------------------------|-----------------------------|
| System::Boolean  | System::Boolean::False.    | System::Boolean::True      | false                     | true                        |
| System::Byte     | System::Byte::MinValue     | System::Byte::MaxValue.    | 0                         | 255                         |
| System::DateTime | System::DateTime::MinValue | System::DateTime::MaxValue | 00:00:00, January 1, 0001 | 23:59:59, December 31, 9999 |
| System::Double   | System::Double::MinValue   | System::Double::MaxValue   | -1.79769e+308             | 1.79769e+308                |
| System::Int16    | System::Int16::MinValue    | System::Int16::MaxValue    | -32768                    | 32767                       |
| System::Int32    | System::Int32::MinValue    | System::Int32::MaxValue    | -2147483648               | 2147483647                  |
| System::Int64    | System::Int64::MinValue    | System::Int64::MaxValue    | -9223372036854775808      | 9223372036854775807         |
| System::SByte    | System::SByte::MinValue    | System::SByte::MaxValue    | -128                      | 127                         |
| System::Single   | System::Single::MinValue   | System::Single::MaxValue   | -3.40282e+038f            | 3.40282e+038f               |
| System::UInt16   | System::UInt16::MinValue   | System::UInt16::MaxValue   | 0                         | 65535                       |
| System::UInt32   | System::UInt32::MinValue   | System::UInt32::MaxValue   | 0                         | 4294967295                  |
| System::UInt64   | System::UInt64::MinValue   | System::UInt64::MaxValue   | 0                         | 18446744073709551615        |

# Boxing

For explicit boxing a type into corresponding object class use keyword Box or Boxer::Boxing method
Remarks : By default an implicit boxing into corresponding object class is used.

```c++
bool readyUnboxed = true;
Boolean readyBoxed = Box(readyUnboxed);  // explicit
Boolean readyBoxed2 = readyUnboxed;      // implicit
```

# Unboxing

For explicit unboxing a object class into corresponding type use keyword Unbox or Unboxer::Unboxing method
Remarks : By default an implicit unboxing into corresponding type is used.

```c++
Boolean readyBoxed = true;
bool readyUnboxed = Unbox(readyBoxed);  // explict
bool readyUnboxed2 = readyBoxed;        // implicit
```

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
