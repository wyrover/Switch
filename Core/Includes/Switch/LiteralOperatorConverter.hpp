/// @file
/// @brief Contains Switch::operator""_b, Switch::operator""_c, Switch::operator""_s, ... operators.
#pragma once

#include "System/Convert.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Used to convert specified value into byte:
  /// @code
  /// System::Console::WriteLine(1.6_b);
  /// @endcode
  inline byte operator""_b(long double n) {return System::Convert::ToByte(n);}
  
  /// @brief Used to convert specified value into byte:
  /// @code
  /// System::Console::WriteLine(54_b);
  /// @endcode
  inline byte operator""_b(unsigned long long n) {return System::Convert::ToByte(n);}

  /// @brief Used to convert specified value into byte:
  /// @code
  /// System::Console::WriteLine("125"_b);
  /// @endcode
  inline byte operator""_b(const char* s, size_t) {return System::Convert::ToByte(s);}

  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine('a'_c);
  /// @endcode
  inline char32 operator""_c(char c) {return c;}
  
  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine(u'a'_C);
  /// @endcode
  inline char32 operator""_c(char16 c) {return c;}
  
  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine(U'a'_c);
  /// @endcode
  inline char32 operator""_c(char32 c) {return c;}
  
  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine(L'a'_c);
  /// @endcode
  inline char32 operator""_c(wchar c) {return c;}
  
  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine(49_c);
  /// @endcode
  inline char32 operator""_c(unsigned long long c) {return (char32)c;}
  
  /// @brief Used to convert specified value into double:
  /// @code
  /// System::Console::WriteLine(1.6_d);
  /// @endcode
  inline double operator""_d(long double n) {return System::Convert::ToDouble(n);}
  
  /// @brief Used to convert specified value into System::Double:
  /// @code
  /// System::Console::WriteLine(5436_d);
  /// @endcode
  inline double operator""_d(unsigned long long n) {return System::Convert::ToDouble(n);}

  /// @brief Used to convert specified value into double:
  /// @code
  /// System::Console::WriteLine("12.5"_d);
  /// @endcode
  inline double operator""_d(const char* s, size_t) { return System::Convert::ToDouble(s); }

  /// @brief Used to convert specified value into int16:
  /// @code
  /// System::Console::WriteLine(5436_s16);
  /// @endcode
  inline int16 operator""_s16(unsigned long long n) {return System::Convert::ToInt16(n);}
  
  /// @brief Used to convert specified value into int16:
  /// @code
  /// System::Console::WriteLine(1.6_s16);
  /// @endcode
  inline int16 operator""_s16(long double n) {return System::Convert::ToInt16(n);}

  /// @brief Used to convert specified value into int16:
  /// @code
  /// System::Console::WriteLine("125"_s16);
  /// @endcode
  inline int16 operator""_s16(const char* s, size_t) {return System::Convert::ToInt16(s);}

  /// @brief Used to convert specified value into int32:
  /// @code
  /// System::Console::WriteLine(5436_s32);
  /// @endcode
  inline int32 operator""_s32(unsigned long long n) {return System::Convert::ToInt32(n);}
  
  /// @brief Used to convert specified value into int32:
  /// @code
  /// System::Console::WriteLine(1.6_s32);
  /// @endcode
  inline int32 operator""_s32(long double n) {return System::Convert::ToInt32(n);}

  /// @brief Used to convert specified value into int32:
  /// @code
  /// System::Console::WriteLine("125"_s32);
  /// @endcode
  inline int32 operator""_s32(const char* s, size_t) { return System::Convert::ToInt32(s); }

  /// @brief Used to convert specified value into int64:
  /// @code
  /// System::Console::WriteLine(5436_s64);
  /// @endcode
  inline int64 operator""_s64(unsigned long long n) {return System::Convert::ToInt64(n);}
  
  /// @brief Used to convert specified value into int64:
  /// @code
  /// System::Console::WriteLine(1.6_s64);
  /// @endcode
  inline int64 operator""_s64(long double n) {return System::Convert::ToInt64(n);}

  /// @brief Used to convert specified value into int64:
  /// @code
  /// System::Console::WriteLine("125"_s64);
  /// @endcode
  inline int64 operator""_s64(const char* s, size_t) {return System::Convert::ToInt64(s);}

  /// @brief Used to convert specified value into sbyte:
  /// @code
  /// System::Console::WriteLine(1.6_sb);
  /// @endcode
  inline sbyte operator""_sb(long double n) {return System::Convert::ToSByte(n);}
  
  /// @brief Used to convert specified value into sbyte:
  /// @code
  /// System::Console::WriteLine(54_sb);
  /// @endcode
  inline sbyte operator""_sb(unsigned long long n) {return System::Convert::ToSByte(n);}

  /// @brief Used to convert specified value into sbyte:
  /// @code
  /// System::Console::WriteLine("125"_S64);
  /// @endcode
  inline sbyte operator""_sb(const char* s, size_t) {return System::Convert::ToSByte(s);}

  /// @brief Used to convert specified value into single:
  /// @code
  /// System::Console::WriteLine(1.6_F);
  /// @endcode
  inline float operator""_f(long double n) {return System::Convert::ToSingle(n);}
  
  /// @brief Used to convert specified value into single:
  /// @code
  /// System::Console::WriteLine(5436_F);
  /// @endcode
  inline float operator""_f(unsigned long long n) {return System::Convert::ToSingle(n);}

  /// @brief Used to convert specified value into single:
  /// @code
  /// System::Console::WriteLine("12.5"_f);
  /// @endcode
  inline float operator""_f(const char* s, size_t) {return System::Convert::ToSingle(s);}

  /// @brief Used to convert specified value into uint16:
  /// @code
  /// System::Console::WriteLine(5436_u16);
  /// @endcode
  inline uint16 operator""_u16(unsigned long long n) {return System::Convert::ToUInt16(n);}
  
  /// @brief Used to convert specified value into uint16:
  /// @code
  /// System::Console::WriteLine(1.6_u16);
  /// @endcode
  inline uint16 operator""_u16(long double n) {return System::Convert::ToUInt16(n);}

  /// @brief Used to convert specified value into uint16:
  /// @code
  /// System::Console::WriteLine("125"_u16);
  /// @endcode
  inline uint16 operator""_u16(const char* s, size_t) {return System::Convert::ToUInt16(s);}

  /// @brief Used to convert specified value into uint32:
  /// @code
  /// System::Console::WriteLine(5436_u32);
  /// @endcode
  inline uint32 operator""_u32(unsigned long long n) {return System::Convert::ToUInt32(n);}
  
  /// @brief Used to convert specified value into uint32:
  /// @code
  /// System::Console::WriteLine(1.6_u32);
  /// @endcode
  inline uint32 operator""_u32(long double n) {return System::Convert::ToUInt32(n);}

  /// @brief Used to convert specified value into uint32:
  /// @code
  /// System::Console::WriteLine("125"_u32);
  /// @endcode
  inline uint32 operator""_u32(const char* s, size_t) {return System::Convert::ToUInt32(s);}

  /// @brief Used to convert specified value into uint64:
  /// @code
  /// System::Console::WriteLine(5436_u64);
  /// @endcode
  inline uint64 operator""_u64(unsigned long long n) {return System::Convert::ToUInt64(n);}
  
  /// @brief Used to convert specified value into uint64:
  /// @code
  /// System::Console::WriteLine(1.6_u64);
  /// @endcode
  inline uint64 operator""_u64(long double n) {return System::Convert::ToUInt64(n);}

  /// @brief Used to convert specified value into uint64:
  /// @code
  /// System::Console::WriteLine("125"_u64);
  /// @endcode
  inline uint64 operator""_u64(const char* s, size_t) {return System::Convert::ToUInt64(s);}

  /// @brief Used to convert specified value into System::Byte:
  /// @code
  /// System::Console::WriteLine(1.6_B);
  /// @endcode
  inline System::Byte operator""_B(long double n) {return System::Byte(System::Convert::ToByte(n));}
  
  /// @brief Used to convert specified value into System::Byte:
  /// @code
  /// System::Console::WriteLine(54_B);
  /// @endcode
  inline System::Byte operator""_B(unsigned long long n) {return System::Byte(System::Convert::ToByte(n));}

  /// @brief Used to convert specified value into System::Byte:
  /// @code
  /// System::Console::WriteLine("125"_B);
  /// @endcode
  inline System::Byte operator""_B(const char* s, size_t) {return System::Convert::ToByte(s);}

  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine('a'_C);
  /// @endcode
  inline System::Char operator""_C(char c) {return System::Char(c);}
  
  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine(u'a'_C);
  /// @endcode
  inline System::Char operator""_C(char16 c) {return System::Char(c);}
  
  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine(U'a'_C);
  /// @endcode
  inline System::Char operator""_C(char32 c) {return System::Char(c);}
  
  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine(L'a'_C);
  /// @endcode
  inline System::Char operator""_C(wchar c) {return System::Char(c);}
  
  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine(49_C);
  /// @endcode
  inline System::Char operator""_C(unsigned long long c) {return System::Char((char32)c);}
  
  /// @brief Used to convert specified value into System::Double:
  /// @code
  /// System::Console::WriteLine(1.6_D);
  /// @endcode
  inline System::Double operator""_D(long double n) {return System::Double(System::Convert::ToDouble(n));}
  
  /// @brief Used to convert specified value into System::Double:
  /// @code
  /// System::Console::WriteLine(5436_D);
  /// @endcode
  inline System::Double operator""_D(unsigned long long n) {return System::Double(System::Convert::ToDouble(n));}

  /// @brief Used to convert specified value into System::Double:
  /// @code
  /// System::Console::WriteLine("12.5"_D);
  /// @endcode
  inline System::Double operator""_D(const char* s, size_t) {return System::Convert::ToDouble(s);}
  
  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = "This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  inline System::String operator""_s(const char* s, size_t) {return System::String(s);}
  
  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = u"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  inline System::String operator""_s(const char16* s, size_t) {return System::String(s);}
  
  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = U"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  inline System::String operator""_s(const char32* s, size_t) {return System::String(s);}
  
  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = L"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  inline System::String operator""_s(const wchar* s, size_t) {return System::String(s);}

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = "This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  inline System::String operator""_S(const char* s, size_t) {return System::String(s);}
  
  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = u"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  inline System::String operator""_S(const char16* s, size_t) {return System::String(s);}
  
  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = U"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  inline System::String operator""_S(const char32* s, size_t) {return System::String(s);}
  
  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = L"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  inline System::String operator""_S(const wchar* s, size_t) {return System::String(s);}
  
  /// @brief Used to convert specified value into System::Int16:
  /// @code
  /// System::Console::WriteLine(5436_S16);
  /// @endcode
  inline System::Int16 operator""_S16(unsigned long long n) {return System::Int16(System::Convert::ToInt16(n));}
  
  /// @brief Used to convert specified value into System::Int16:
  /// @code
  /// System::Console::WriteLine(1.6_S16);
  /// @endcode
  inline System::Int16 operator""_S16(long double n) {return System::Int16(System::Convert::ToInt16(n));}

  /// @brief Used to convert specified value into System::Int16:
  /// @code
  /// System::Console::WriteLine("125"_S16);
  /// @endcode
  inline System::Int16 operator""_S16(const char* s, size_t) {return System::Convert::ToInt16(s);}

  /// @brief Used to convert specified value into System::Int32:
  /// @code
  /// System::Console::WriteLine(5436_S32);
  /// @endcode
  inline System::Int32 operator""_S32(unsigned long long n) {return System::Int32(System::Convert::ToInt32(n));}
  
  /// @brief Used to convert specified value into System::Int32:
  /// @code
  /// System::Console::WriteLine(1.6_S32);
  /// @endcode
  inline System::Int32 operator""_S32(long double n) {return System::Int32(System::Convert::ToInt32(n));}

  /// @brief Used to convert specified value into System::Int32:
  /// @code
  /// System::Console::WriteLine("125"_S32);
  /// @endcode
  inline System::Int32 operator""_S32(const char* s, size_t) {return System::Convert::ToInt32(s);}

  /// @brief Used to convert specified value into System::Int64:
  /// @code
  /// System::Console::WriteLine(5436_S64);
  /// @endcode
  inline System::Int64 operator""_S64(unsigned long long n) {return System::Int64(System::Convert::ToInt64(n));}
  
  /// @brief Used to convert specified value into System::Int64:
  /// @code
  /// System::Console::WriteLine(1.6_S64);
  /// @endcode
  inline System::Int64 operator""_S64(long double n) {return System::Int64(System::Convert::ToInt64(n));}
 
  /// @brief Used to convert specified value into System::Int64:
  /// @code
  /// System::Console::WriteLine("125"_S64);
  /// @endcode
  inline System::Int64 operator""_S64(const char* s, size_t) {return System::Convert::ToInt64(s);}

  /// @brief Used to convert specified value into System::SByte:
  /// @code
  /// System::Console::WriteLine(1.6_SB);
  /// @endcode
  inline System::SByte operator""_SB(long double n) {return System::SByte(System::Convert::ToSByte(n));}
  
  /// @brief Used to convert specified value into System::SByte:
  /// @code
  /// System::Console::WriteLine(54_SB);
  /// @endcode
  inline System::SByte operator""_SB(unsigned long long n) {return System::SByte(System::Convert::ToSByte(n));}

  /// @brief Used to convert specified value into System::SByte:
  /// @code
  /// System::Console::WriteLine("125"_SB);
  /// @endcode
  inline System::SByte operator""_SB(const char* s, size_t) { return System::Convert::ToSByte(s); }

  /// @brief Used to convert specified value into System::Single:
  /// @code
  /// System::Console::WriteLine(1.6_F);
  /// @endcode
  inline System::Single operator""_F(long double n) {return System::Single(System::Convert::ToSingle(n));}
  
  /// @brief Used to convert specified value into System::Single:
  /// @code
  /// System::Console::WriteLine(5436_F);
  /// @endcode
  inline System::Single operator""_F(unsigned long long n) {return System::Single(System::Convert::ToSingle(n));}

  /// @brief Used to convert specified value into System::Single:
  /// @code
  /// System::Console::WriteLine("12.5"_F);
  /// @endcode
  inline System::Single operator""_F(const char* s, size_t) { return System::Convert::ToSingle(s); }

  /// @brief Used to convert specified value into System::UInt16:
  /// @code
  /// System::Console::WriteLine(5436_U16);
  /// @endcode
  inline System::UInt16 operator""_U16(unsigned long long n) {return System::UInt16(System::Convert::ToUInt16(n));}
  
  /// @brief Used to convert specified value into System::UInt16:
  /// @code
  /// System::Console::WriteLine(1.6_U16);
  /// @endcode
  inline System::UInt16 operator""_U16(long double n) {return System::UInt16(System::Convert::ToUInt16(n));}

  /// @brief Used to convert specified value into System::UInt16:
  /// @code
  /// System::Console::WriteLine("125"_U16);
  /// @endcode
  inline System::UInt16 operator""_U16(const char* s, size_t) { return System::Convert::ToUInt16(s); }

  /// @brief Used to convert specified value into System::UInt32:
  /// @code
  /// System::Console::WriteLine(5436_U32);
  /// @endcode
  inline System::UInt32 operator""_U32(unsigned long long n) {return System::UInt32(System::Convert::ToUInt32(n));}
  
  /// @brief Used to convert specified value into System::UInt32:
  /// @code
  /// System::Console::WriteLine(1.6_U32);
  /// @endcode
  inline System::UInt32 operator""_U32(long double n) {return System::UInt32(System::Convert::ToUInt32(n));}

  /// @brief Used to convert specified value into System::UInt32:
  /// @code
  /// System::Console::WriteLine("125"_U32);
  /// @endcode
  inline System::UInt32 operator""_U32(const char* s, size_t) { return System::Convert::ToUInt32(s); }

  /// @brief Used to convert specified value into System::UInt64:
  /// @code
  /// System::Console::WriteLine(5436_U64);
  /// @endcode
  inline System::UInt64 operator""_U64(unsigned long long n) {return System::UInt64(System::Convert::ToUInt64(n));}
  
  /// @brief Used to convert specified value into System::UInt64:
  /// @code
  /// System::Console::WriteLine(1.6_U64);
  /// @endcode
  inline System::UInt64 operator""_U64(long double n) {return System::UInt64(System::Convert::ToUInt64(n));}

  /// @brief Used to convert specified value into System::UInt64:
  /// @code
  /// System::Console::WriteLine("125"_U64);
  /// @endcode
  inline System::UInt64 operator""_U64(const char* s, size_t) { return System::Convert::ToUInt64(s); }
}

using namespace Switch;
