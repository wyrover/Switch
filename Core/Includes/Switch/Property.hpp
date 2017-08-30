/// @file
/// @brief Contains Pcf::Property class, #pcf_get and #pcf_set keywords.
#pragma once

//#include <functional>
#include "__opaque_function_pointer__.hpp"

namespace Pcf {
  class ReadOnly {
  public:
    static constexpr bool CanRead = true;
    static constexpr bool CanWrite = false;
  };
  
  class WriteOnly {
  public:
    static constexpr bool CanRead = false;
    static constexpr bool CanWrite = true;
  };

  class ReadWrite {
  public:
    static constexpr bool CanRead = true;
    static constexpr bool CanWrite = true;
  };
  
  /// @brief A Property is a member that provides a flexible mechanism to read, write, or compute the value of a private field. Properties can be used as if they are public data members, but they are actually special methods called accessors. This enables data to be accessed easily and still helps promote the safety and flexibility of methods.
  /// @remarks The copy constructor is deleted. So the copy constructor of the owner class must be specified (the implicit or default copy contructor doesn't build).
  /// @par Examples
  /// This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.
  /// @include Properties.cpp
  template <class T, class Attribute = ReadWrite>
  class Property : public Attribute {
    // Don't use std::function<> because the build became very slow
    //using Getter = std::function<T()>;
    //using Setter = std::function<void(T)>;
    using Getter = __opaque_function_pointer__<T>;
    using Setter = __opaque_function_pointer__<void, T>;
    
  public:
    Property(const Getter& getter, const Setter& setter) : getter(getter), setter(setter) {}
    
    T Get() const {return this->getter();}
    T operator ()() const {return this->getter();}
    
    /// @cond
    operator T () const {return this->getter();}
    Property& operator =(const Property& property) {this->setter(property.getter()); return *this;}
    bool operator ==(T value) const {return this->getter() == value;}
    bool operator !=(T value) const {return this->getter() != value;}
    /// @endcond
    
    T Set(T value) {this->setter(value); return this->getter();}
    T operator ()(T value) {this->setter(value); return this->getter();}

    /// @cond
    Property& operator =(T value) {this->setter(value); return *this;}
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
    // Don't use std::function<> because the build became very slow
    //using Getter = std::function<T()>;
    using Getter = __opaque_function_pointer__<T>;
  
  public:
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
    // Don't use std::function<> because the build became very slow
    //using Setter = std::function<void(T)>;
    using Setter = __opaque_function_pointer__<void, T>;
 
  public:
    Property(const Setter& setter) : setter(setter) {}
    Property& operator =(const Property& property) {return *this;}
    
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
  /// @par Examples
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///   Person(const Person& person) : name(person.name) {}
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
  /// @par Examples
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///   Person(const Person& person) : name(person.name) {}
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
  
