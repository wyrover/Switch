/// @file
/// @brief Contains #_property, #_get and #_set keywords.
#pragma once

//#include <functional>
#include "__opaque_function_pointer__.hpp"

/// @cond
struct _readonly {};
struct _writeonly {};
struct _readwrite {};

template <class T, class Attribute = _readwrite>
class _property;

template <class T, class Attribute>
class _property : public Attribute {
  // Don't use std::function<> because the build became very slow
  //using Getter = std::function<T()>;
  //using Setter = std::function<void(T)>;
  using Getter = __opaque_function_pointer__<T>;
  using Setter = __opaque_function_pointer__<void, T>;
  
public:
  _property(const Getter& getter, const Setter& setter) : getter(getter), setter(setter) {}
  
  T Get() const {return this->getter();}
  T operator ()() const {return this->getter();}
  
  operator T () const {return this->getter();}
  _property& operator=(const _property& _property) {this->setter(_property.getter()); return *this;}
  bool operator==(T value) const {return this->getter() == value;}
  bool operator !=(T value) const {return this->getter() != value;}
  
  T Set(T value) {this->setter(value); return this->getter();}
  T operator ()(T value) {this->setter(value); return this->getter();}
  
  _property& operator=(T value) {this->setter(value); return *this;}
  void operator+=(T value) {this->setter(this->getter() + value);}
  void operator-=(T value) {this->setter(this->getter() - value);}
  void operator*=(T value) {this->setter(this->getter() * value);}
  void operator /=(T value) {this->setter(this->getter() / value);}
  void operator %=(T value) {this->setter(this->getter() % value);}
  void operator &=(T value) {this->setter(this->getter() & value);}
  void operator |=(T value) {this->setter(this->getter() | value);}
  void operator ^=(T value) {this->setter(this->getter() ^ value);}
  void operator<<=(T value) {this->setter(this->getter() << value);}
  void operator>>=(T value) {this->setter(this->getter() >> value);}
  
private:
  _property(const _property& _property)  = delete;
  Getter getter;
  Setter setter;
};

template <class T>
class _property<T, _readonly> : public _readonly {
  // Don't use std::function<> because the build became very slow
  //using Getter = std::function<T()>;
  using Getter = __opaque_function_pointer__<T>;
  
public:
  _property(const Getter& getter) : getter(getter) {}
  _property& operator=(const _property& _property) {return *this;}
  
  T Get() const {return this->getter();}
  T operator ()() const {return this->getter();}
  operator T () const {return this->getter();}
  bool operator==(T value) const {return this->getter() == value;}
  bool operator !=(T value) const {return this->getter() != value;}
  
private:
  _property(const _property& _property)  = delete;
  Getter getter;
};

template <class T>
class _property<T, _writeonly> : public _writeonly {
  // Don't use std::function<> because the build became very slow
  //using Setter = std::function<void(T)>;
  using Setter = __opaque_function_pointer__<void, T>;
  
public:
  _property(const Setter& setter) : setter(setter) {}
  _property& operator=(const _property& _property) {return *this;}
  
  void Set(T value) {this->setter(value);}
  void operator ()(T value) {this->setter(value);}
  void operator=(T value) {this->setter(value);}
  
private:
  _property(const _property& _property)  = delete;
  Setter setter;
};
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief #_readonly keyword represent a #_property read only attribute.
  /// @ingroup Keywords
  #define _readonly \
  _readonly
  
  /// @brief #_readwrite keyword represent a #_property read write attribute.
  /// @ingroup Keywords
  #define _readwrite \
  _readwrite
  
  /// @brief #_writeonly keyword represent a #_property write only attribute.
  /// @ingroup Keywords
  #define _writeonly \
  _writeonly
  
  /// @brief A #_property is a member that provides a flexible mechanism to read, write, or compute the value of a private field. Properties can be used as if they are public data members, but they are actually special methods called accessors. This enables data to be accessed easily and still helps promote the safety and flexibility of methods.
  /// @remarks The copy constructor is deleted. So the copy constructor of the owner class must be specified (the implicit or default copy contructor doesn't build).
  /// @par Examples
  /// This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.
  /// @include Properties.cpp
  /// @ingroup Keywords
  #define _property \
  _property
  
  /// @brief The get keyword defines an accessor method in a #_property or indexer that retrieves the value of the #_property or the indexer element.
  /// @par Examples
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///   Person(const Person& person) : name(person.name) {}
  ///
  ///   _property<string> Name {
  ///     _get {return this->name},
  ///     _set {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Keywords
  #define _get \
  [&]()
  
  /// @brief The set keyword defines an accessor method in a #_property or indexer that assigns the value of the #_property or the indexer element.
  /// @par Examples
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///   Person(const Person& person) : name(person.name) {}
  ///
  ///   _property<string> Name {
  ///     _get {return this->name},
  ///     _set {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Keywords
  #define _set \
  [&](const auto& value)
}

using namespace Switch;
  
