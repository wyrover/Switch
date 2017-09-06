/// @file
/// @brief Contains Switch::Property class, #_get and #_set keywords.
#pragma once

//#include <functional>
#include "__opaque_function_pointer__.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief ReadOnly class represent a Property read only attribute.
  class ReadOnly {
  public:
    /// @brief Get information about read
    /// @return true if can read; otherwise false
    /// @remarks Property<T, ReadOnly> return always true.
    static constexpr bool CanRead = true;

    /// @brief Get information about read
    /// @return true if can write; otherwise false
    /// @remarks Property<T, ReadOnly> return always false.
    static constexpr bool CanWrite = false;
  };
  
  /// @brief WriteOnly class represent a Property write only attribute.
  class WriteOnly {
  public:
    /// @brief Get information about read
    /// @return true if can read; otherwise false
    /// @remarks Property<T, WriteOnly> return always false.
    static constexpr bool CanRead = false;
    
    /// @brief Get information about read
    /// @return true if can write; otherwise false
    /// @remarks Property<T, WriteOnly> return always true.
    static constexpr bool CanWrite = true;
  };

  /// @brief ReadWrite class represent a Property read write attribute.
  class ReadWrite {
  public:
    /// @brief Get information about read
    /// @return true if can read; otherwise false
    /// @remarks Property<T, ReadWrite> return always true.
    static constexpr bool CanRead = true;
    
    /// @brief Get information about read
    /// @return true if can write; otherwise false
    /// @remarks Property<T, ReadWrite> return always true.
    static constexpr bool CanWrite = true;
  };

  /// @cond
  template <class T, class Attribute = ReadWrite>
  class Property;
  /// @endcond
  
  /// @brief A Property is a member that provides a flexible mechanism to read, write, or compute the value of a private field. Properties can be used as if they are public data members, but they are actually special methods called accessors. This enables data to be accessed easily and still helps promote the safety and flexibility of methods.
  /// @remarks The copy constructor is deleted. So the copy constructor of the owner class must be specified (the implicit or default copy contructor doesn't build).
  /// @par Examples
  /// This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.
  /// @include Properties.cpp
  template <class T, class Attribute>
  class Property : public Attribute {
    // Don't use std::function<> because the build became very slow
    //using Getter = std::function<T()>;
    //using Setter = std::function<void(T)>;
    using Getter = __opaque_function_pointer__<T>;
    using Setter = __opaque_function_pointer__<void, T>;
    
  public:
    /// @brief Initialize Property with getter and setter specified.
    /// @param getter Getter method called when get value.
    /// @param setter Setter method called when set value.
    /// This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.
    /// @include Properties.cpp
    Property(const Getter& getter, const Setter& setter) : getter(getter), setter(setter) {}

    /// @brief Get value method
    /// @return value getted by getter method
    /// @remarks call getter specified at creation.
    T Get() const {return this->getter();}

    /// @brief Get value operator
    /// @return value getted by getter method
    /// @remarks call getter specified at creation.
    T operator ()() const {return this->getter();}
    
    /// @cond
    operator T () const {return this->getter();}
    Property& operator =(const Property& property) {this->setter(property.getter()); return *this;}
    bool operator ==(T value) const {return this->getter() == value;}
    bool operator !=(T value) const {return this->getter() != value;}
    /// @endcond
    
    /// @brief Set value method
    /// @param value setted by setter method
    /// @remarks call setter specified at creation.
    T Set(T value) {this->setter(value); return this->getter();}

    /// @brief Set value operator
    /// @param value setted by setter method
    /// @remarks call setter specified at creation.
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
  ///     _get {return this->name},
  ///     _set {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Switch
  #define _get\
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
  ///     _get {return this->name},
  ///     _set {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Switch
  #define _set\
  [&](const auto& value)
}

using namespace Switch;
  
