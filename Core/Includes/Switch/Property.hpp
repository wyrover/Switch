/// @file
/// @brief Contains Switch::__property__ class, #_get and #_set keywords.
#pragma once

//#include <functional>
#include "__opaque_function_pointer__.hpp"

/// @cond
struct __readonly__ {};
struct __writeonly__ {};
struct __readwrite__ {};

template <class T, class Attribute = __readwrite__>
class __property__;

template <class T, class Attribute>
class __property__ : public Attribute {
  // Don't use std::function<> because the build became very slow
  //using Getter = std::function<T()>;
  //using Setter = std::function<void(T)>;
  using Getter = __opaque_function_pointer__<T>;
  using Setter = __opaque_function_pointer__<void, T>;
  
public:
  __property__(const Getter& getter, const Setter& setter) : getter(getter), setter(setter) {}
  
  T Get() const {return this->getter();}
  
  T operator ()() const {return this->getter();}
  
  operator T () const {return this->getter();}
  __property__& operator =(const __property__& __property__) {this->setter(__property__.getter()); return *this;}
  bool operator ==(T value) const {return this->getter() == value;}
  bool operator !=(T value) const {return this->getter() != value;}
  
  T Set(T value) {this->setter(value); return this->getter();}
  
  T operator ()(T value) {this->setter(value); return this->getter();}
  
  __property__& operator =(T value) {this->setter(value); return *this;}
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
  
private:
  __property__(const __property__& __property__)  = delete;
  Getter getter;
  Setter setter;
};

template <class T>
class __property__<T, __readonly__> : public __readonly__ {
  // Don't use std::function<> because the build became very slow
  //using Getter = std::function<T()>;
  using Getter = __opaque_function_pointer__<T>;
  
public:
  __property__(const Getter& getter) : getter(getter) {}
  __property__& operator =(const __property__& __property__) {return *this;}
  
  T Get() const {return this->getter();}
  T operator ()() const {return this->getter();}
  operator T () const {return this->getter();}
  bool operator ==(T value) const {return this->getter() == value;}
  bool operator !=(T value) const {return this->getter() != value;}
  
private:
  __property__(const __property__& __property__)  = delete;
  Getter getter;
};

template <class T>
class __property__<T, __writeonly__> : public __writeonly__ {
  // Don't use std::function<> because the build became very slow
  //using Setter = std::function<void(T)>;
  using Setter = __opaque_function_pointer__<void, T>;
  
public:
  __property__(const Setter& setter) : setter(setter) {}
  __property__& operator =(const __property__& __property__) {return *this;}
  
  void Set(T value) {this->setter(value);}
  void operator ()(T value) {this->setter(value);}
  void operator =(T value) {this->setter(value);}
  
private:
  __property__(const __property__& __property__)  = delete;
  Setter setter;
};
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief __readonly__ class represent a __property__ read only attribute.
  /// @ingroup Keywords
  #define readonly __readonly__
  
  /// @brief __readwrite__ class represent a __property__ read write attribute.
  /// @ingroup Keywords
  #define readwrite __readwrite__
  
  /// @brief __writeonly__ class represent a __property__ write only attribute.
  /// @ingroup Keywords
  #define writeonly __writeonly__
  
  /// @brief A __property__ is a member that provides a flexible mechanism to read, write, or compute the value of a private field. Properties can be used as if they are public data members, but they are actually special methods called accessors. This enables data to be accessed easily and still helps promote the safety and flexibility of methods.
  /// @remarks The copy constructor is deleted. So the copy constructor of the owner class must be specified (the implicit or default copy contructor doesn't build).
  /// @par Examples
  /// This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.
  /// @include Properties.cpp
  /// @ingroup Keywords
  #define property __property__
  
  /// @brief The get keyword defines an accessor method in a __property__ or indexer that retrieves the value of the __property__ or the indexer element.
  /// @par Examples
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///   Person(const Person& person) : name(person.name) {}
  ///
  ///   __property__<string> Name {
  ///     _get {return this->name},
  ///     _set {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Keywords
  #define _get\
  [&]()
  
  /// @brief The set keyword defines an accessor method in a __property__ or indexer that assigns the value of the __property__ or the indexer element.
  /// @par Examples
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///   Person(const Person& person) : name(person.name) {}
  ///
  ///   __property__<string> Name {
  ///     _get {return this->name},
  ///     _set {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Keywords
  #define _set\
  [&](const auto& value)
}

using namespace Switch;
  
