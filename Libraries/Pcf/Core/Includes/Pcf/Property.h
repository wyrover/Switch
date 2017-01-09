/// @file
/// @brief Contains Pcf::Property class, #pcf_get and #pcf_set keywords.
#pragma once

#include "FunctionPointer.h"

namespace Pcf {
  class pcf_public ReadOnly {
  public:
    static constexpr bool CanRead = true;
    static constexpr bool CanWrite = false;
  };
  
  class pcf_public WriteOnly {
  public:
    static constexpr bool CanRead = false;
    static constexpr bool CanWrite = true;
  };

  class pcf_public ReadWrite {
  public:
    static constexpr bool CanRead = true;
    static constexpr bool CanWrite = true;
  };
  
  /// @brief A property is a member that provides a flexible mechanism to read, write, or compute the value of a private field. Properties can be used as if they are public data members, but they are actually special methods called accessors. This enables data to be accessed easily and still helps promote the safety and flexibility of methods.
  /// This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.
  /// @include Properties.cpp
  template <class T, class Attribute=ReadWrite>
  class Property : public Attribute {
  public:
    using Getter = FunctionPointer<T>;
    using Setter = FunctionPointer<void, T>;

    Property(const Getter& getter, const Setter& setter) : getter(getter), setter(setter) {}
    Property& operator =(const Property& property) {this->setter(property.getter()); return *this;}
    
    T Get() const {return this->getter();}
    T operator ()() const {return this->getter();}
    
    /// @cond
    operator T () const {return this->getter();}
    bool operator ==(T value) const {return this->getter() == value;}
    bool operator !=(T value) const {return this->getter() != value;}
    /// @endcond
    
    void Set(T value) {this->setter(value);}
    void operator ()(T value) {this->setter(value);}

    /// @cond
    void operator =(T value) {this->setter(value);}
    void operator +=(T value) {this->setter(this->getter() + value);}
    void operator -=(T value) {this->setter(this->getter() - value);}
    void operator *=(T value) {this->setter(this->getter() * value);}
    void operator /=(T value) {this->setter(this->getter() / value);}
    void operator %=(T value) {this->setter(this->getter() % value);}
    void operator &=(T value) {this->setter(this->getter() & value);}
    void operator |=(T value) {this->setter(this->getter() | value);}
    void operator ^=(T value) {this->setter(this->getter() ^ value);}
    void operator <<=(T value) {this->setter(this->getter() << value);}
    void operator >>=(T value) {this->setter(this->getter() >> value);}
    /// @endcond
    
  private:
    Property(const Property& property)  = delete;
    Getter getter;
    Setter setter;
  };
  
  /// @cond
  template <class T>
  class Property<T, ReadOnly> : public ReadOnly {
  public:
    using Getter = FunctionPointer<T>;

    Property(const Getter& getter) : getter(getter) {}
    Property& operator =(const Property& property) {return *this;}
    
    T Get() const {return this->getter();}
    T operator ()() const {return this->getter();}
    operator T () const {return this->getter();}
    bool operator ==(T value) const {return this->getter() == value;}
    bool operator !=(T value) const {return this->getter() != value;}
    
  private:
    Property(const Property& property)  = delete;
    Getter getter;
  };
  
  template <class T>
  class Property<T, WriteOnly> : public WriteOnly {
  public:
    using Setter = FunctionPointer<void, T>;

    Property(const Setter& setter) : setter(setter) {}
    Property& operator =(const Property& property) {this->setter(property.getter()); return *this;}
    
    void Set(T value) {this->setter(value);}
    void operator ()(T value) {this->setter(value);}
    void operator =(T value) {this->setter(value);}
    
  private:
    Property(const Property& property)  = delete;
    Setter setter;
  };
  /// @endcond
  
  template <class T, class Attribute>
  using property = Property<T, Attribute>;
  
  /// @brief The get keyword defines an accessor method in a property or indexer that retrieves the value of the property or the indexer element.
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///
  ///   Property<string> Name {
  ///     pcf_get {return this->name},
  ///     pcf_set {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Pcf
  #define pcf_get\
  [&]()
  
  /// @brief The set keyword defines an accessor method in a property or indexer that assigns the value of the property or the indexer element.
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///
  ///   Property<string> Name {
  ///     pcf_get {return this->name},
  ///     pcf_set {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Pcf
  #define pcf_set\
  [&](const auto& value)
}

using namespace Pcf;
  
