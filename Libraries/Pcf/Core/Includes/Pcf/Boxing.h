/// @file
/// @brief Contains Pcf::Box and Pcf::Unbox operators.
#pragma once
#include "Property.h"
#include "Types.h"
#include "System/Boolean.h"
#include "System/Byte.h"
#include "System/Char.h"
#include "System/DateTime.h"
#include "System/Decimal.h"
#include "System/Double.h"
#include "System/Int16.h"
#include "System/Int32.h"
#include "System/Int64.h"
#include "System/IntPtr.h"
#include "System/Object.h"
#include "System/SByte.h"
#include "System/_String.h"
#include "System/Single.h"
#include "System/UInt16.h"
#include "System/UInt32.h"
#include "System/UInt64.h"
#include "System/UIntPtr.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief Support boxing of type
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0}", ready);                 // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Boxer::Boxing(ready));  // console output : ready = true
  /// @endcode
  class Boxer {
  public:
    /// @cond
    Boxer() = delete;
    /// @endcond

    /// @brief Boxing a bool to a Boolean
    /// @param value bool to Boxing.
    /// @return Boolean boxed value
    static System::Boolean Boxing(bool value) {return value;}
    
    /// @brief Boxing a byte to a Byte
    /// @param value byte to Boxing.
    /// @return Byte boxed value
    static System::Byte Boxing(byte value) {return value;}
  
    /// @brief Boxing a double to a Double
    /// @param value double to Boxing.
    /// @return Double boxed value
    static System::Double Boxing(double value) {return value;}
    
    /// @brief Boxing an int16 to an Int16
    /// @param value int16 to Boxing.
    /// @return Int16 boxed value
    static System::Int16 Boxing(int16 value) {return value;}
    
    /// @brief Boxing an int32 to an Int32
    /// @param value int32 to Boxing.
    /// @return Int32 boxed value
    static System::Int32 Boxing(int32 value) {return value;}
    
    /// @brief Boxing an int64 to an Int64
    /// @param value int64 to Boxing.
    /// @return Int64 boxed value
    static System::Int64 Boxing(int64 value) {return value;}
    
    /// @brief Boxing a sbyte to a SByte
    /// @param value sbyte to Boxing.
    /// @return SByte boxed value
    static System::SByte Boxing(sbyte value) {return value;}
    
    /// @brief Boxing a single to a Single
    /// @param value single to Boxing.
    /// @return Single boxed value
    static System::Single Boxing(float value) {return value;}
    
    /// @brief Boxing a const char* to a String
    /// @param value const char* to Boxing.
    /// @return String boxed value
    static System::String Boxing(const char* value) {return value;}
    
    /// @brief Boxing a const char* to a String
    /// @param value const char* to Boxing.
    /// @return String boxed value
    static System::String Boxing(const wchar* value) {return value;}
    
    /// @brief Boxing a const char* to a String
    /// @param value const char* to Boxing.
    /// @return String boxed value
    static System::String Boxing(const char16* value) {return value;}
    
    /// @brief Boxing a const char* to a String
    /// @param value const char* to Boxing.
    /// @return String boxed value
    static System::String Boxing(const char32* value) {return value;}
    
    /// @brief Boxing a char to a Char
    /// @param value Char to Boxing.
    /// @return Char boxed value
    static System::Char Boxing(char value) {return value;}
    
    /// @brief Boxing a char to a Char
    /// @param value Char to Boxing.
    /// @return Char boxed value
    static System::Char Boxing(wchar value) {return value;}
    
    /// @brief Boxing a char32 to a Char
    /// @param value Char to Boxing.
    /// @return Char boxed value
    static System::Char Boxing(char16 value) {return value;}
    
    /// @brief Boxing a char32 to a Char
    /// @param value Char to Boxing.
    /// @return Char boxed value
    static System::Char Boxing(char32 value) {return value;}
    
    /// @brief Boxing an uint16 to an UInt16
    /// @param value uint16 to Boxing.
    /// @return UInt16 boxed value
    static System::UInt16 Boxing(uint16 value) {return value;}
    
    /// @brief Boxing an uint32 to an UInt32
    /// @param value uint32 to Boxing.
    /// @return UInt32 boxed value
    static System::UInt32 Boxing(uint32 value) {return value;}
    
    /// @brief Boxing an uint64 to an UInt64
    /// @param value uint64 to Boxing.
    /// @return UInt64 boxed value
    static System::UInt64 Boxing(uint64 value) {return value;}
    
    /// @brief Boxing an void* to an UIntPtr
    /// @param value void* to Boxing.
    /// @return UIntPtr boxed value
    static System::UIntPtr Boxing(void* value) {return value;}
    
    /// @cond
    template<typename T>
    static const T& Boxing(const T& value) {return value;}
    /// @endcond
    
  private:
    friend class System::String;
  };
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);                     // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unboxer::Unboxing(ready));  // console output : ready = 1
  /// @endcode
  class Unboxer {
  public:
    /// @cond
    Unboxer() = delete;
    /// @endcond
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static bool Unboxing(const System::Boolean& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static byte Unboxing(const System::Byte& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static double Unboxing(const System::Double& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static System::DateTime Unboxing(const System::DateTime& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static int16 Unboxing(const System::Int16& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static int32 Unboxing(System::Int32& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static int32 Unboxing(const System::Int32& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static int64 Unboxing(const System::Int64& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static void* Unboxing(const System::IntPtr& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static sbyte Unboxing(const System::SByte& value) {return value;}
    
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static float Unboxing(const System::Single& value) {return value;}
    
    /// @brief Unboxing a String type to a bool Type
    /// @param value String to Unboxing.
    /// @return bool unboxed value
    static const char* Unboxing(const System::String& value) {return value.Data;}
    
    /// @brief Unboxing a Char type to a char32 Type
    /// @param value Char to Unboxing.
    /// @return char32 unboxed value
    static char32 Unboxing(const System::Char& value) {return value;}
    
    /// @brief Unboxing an UInt16 type to an uint16 Type
    /// @param value UInt16 to Unboxing.
    /// @return uint16 unboxed value
    static uint16 Unboxing(const System::UInt16& value) {return value;}
    
    /// @brief Unboxing an UInt32 type to an uint32 Type
    /// @param value UInt32 to Unboxing.
    /// @return uint32 unboxed value
    static uint32 Unboxing(const System::UInt32& value) {return value;}
    
    /// @brief Unboxing an UInt64 type to an uint64 Type
    /// @param value UInt64 to Unboxing.
    /// @return uint64 unboxed value
    static uint64 Unboxing(const System::UInt64& value) {return value;}
    
    /// @brief Unboxing a UIntPtr type to a void* Type
    /// @param value UIntPtr to Unboxing.
    /// @return void* unboxed value
    static void* Unboxing(const System::UIntPtr& value) {return value;}
    
    /// @cond
    template<typename T>
    static const T& Unboxing(const T& value) {return value;}
    /// @endcond
  };
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Boolean Box(bool value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Byte Box(byte value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Double Box(double value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Int16 Box(int16 value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Int32 Box(int32 value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Int64 Box(int64 value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::SByte Box(sbyte value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// @remarks Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Single Box(float value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::String Box(const char* value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::String Box(const wchar* value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::String Box(const char16* value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::String Box(const char32* value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Char Box(char value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Char Box(wchar value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Char Box(char16 value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::Char Box(char32 value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::UInt16 Box(uint16 value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::UInt32 Box(uint32 value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::UInt64 Box(uint64 value) {return Boxer::Boxing(value);}
  
  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Pcf::Boxer.
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  inline System::UIntPtr Box(void* value) {return Boxer::Boxing(value);}
  
  /// @cond
  template<typename T>
  inline const T& Box(const T& value) {return Boxer::Boxing(value);}

  template<typename T, typename Attribute>
  inline T Box(const Property<T, Attribute>& value) {return T(Box(value()));}
  /// @endcond
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline bool Unbox(const System::Boolean& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// @remarks Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// @remarks Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline byte Unbox(const System::Byte& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline double Unbox(const System::Double& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline System::DateTime Unbox(const System::DateTime& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline int16 Unbox(const System::Int16& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline int32 Unbox(System::Int32& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline int32 Unbox(const System::Int32& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline int64 Unbox(const System::Int64& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline void* Unbox(const System::IntPtr& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline sbyte Unbox(const System::SByte& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline float Unbox(const System::Single& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline const char* Unbox(const System::String& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline char32 Unbox(const System::Char& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline uint16 Unbox(const System::UInt16& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline uint32 Unbox(const System::UInt32& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline uint64 Unbox(const System::UInt64& value) {return Unboxer::Unboxing(value);}
  
  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Pcf::Unboxer.
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  inline void* Unbox(const System::UIntPtr& value) {return Unboxer::Unboxing(value);}
  
  /// @cond
  template<typename T>
  inline T& Unbox(T& value) {return Unboxer::Unboxing(value);}

  template<typename T>
  inline const T& Unbox(const T& value)  {return Unboxer::Unboxing(value);}
/// @endcond
}

using namespace Pcf;
