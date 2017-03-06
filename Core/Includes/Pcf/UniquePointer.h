/// @file
/// @brief Contains Pcf::UniquePointer <T> class.
#pragma once

#include <exception>
#include <string>
#include <sstream>

#include "Types.h"
#include "Reference.h"

namespace Pcf {
  /// @brief Manages the storage of a pointer, providing a limited garbage-collection facility, with little to no overhead over built-in pointers.
  template<typename T>
  class UniquePointer {
  public:
    /// @brief Represent a Null UniquePointer.
    static const UniquePointer<T>& Null() { static UniquePointer<T> nullPointer; return nullPointer; }
    
    /// @brief Represent an Empty UniquePointer.
    static const UniquePointer<T>& Empty() { static UniquePointer<T> emptyPointer; return emptyPointer; }
    
    /// @brief Create a null UniquePointer.
    UniquePointer() {}
    
    /// @brief Create a Pointer with specified pointer.
    /// @param ptr Pointer to store.
    UniquePointer(const T* ptr) { this->Reset(ptr); }
    
    /// @brief Copy a UniquePointer specified
    /// @param ptr UniquePointer to copy.
    UniquePointer(const UniquePointer& ptr) { this->Swap(const_cast<UniquePointer<T>&>(ptr)); }
    
    /// @brief Destroy the current pointer and set to null.
    void Delete() { this->Reset(null); }
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    bool IsNull() const { return this->ptr == null; }
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    static bool IsNullOrInvalid(const UniquePointer<T>& up) { return &up == null || up.IsNull(); }
    
    /// @brief Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer.
    /// @return A pointer to the object managed by UniquePointer before the call.
    T* Release() {
      T* ptr = this->ptr;
      this->ptr = null;
      return ptr;
    }
    
    /// @brief Destroy the current pointer and set to null.
    void Reset() { this->Reset(null); }
    
    /// @brief Destroy the current pointer and set to new specified pointer.
    /// @param ptr new ptr to store.
    void Reset(const T* ptr) {
      if (this->ptr != null)
        delete this->ptr;
      this->ptr = const_cast<T*>(ptr);
    }
    
    /// @brief Exchanges the contents of the UniquePointer object with those of ptr, transferring ownership of any managed object between them without destroying either.
    /// @param ptr Another UniquePointer object of the same type.
    void Swap(UniquePointer<T>& ptr) {
      T* p = ptr.ptr;
      ptr.ptr = this->ptr;
      this->ptr = p;
    }
    
    static void Swap(UniquePointer<T>& ptrA, UniquePointer<T>& ptrB) { ptrA.Swap(ptrB); }
    
    /// @brief Get the value stored in UniquePointer.
    /// @return the value stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    T& ToObject() {
      if (this->ptr == null)
        throw std::exception();
      
      return *this->ptr;
    }
    
    /// @brief Get the value stored in UniquePointer.
    /// @return the value stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    const T& ToObject() const {
      if (this->ptr == null)
        throw std::exception();
      
      return *this->ptr;
    }
    
    /// @brief Get the value stored in UniquePointer with specified type.
    /// @return the value stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    template<typename TT>
    TT& ToObject() {
      if (this->ptr == null)
        throw std::exception();
      
      TT* cast = reinterpret_cast<TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return *cast;
    }
    
    /// @brief Get the value stored in UniquePointer with specified type.
    /// @return the value stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    template<typename TT>
    const TT& ToObject() const {
      if (this->ptr == null)
        throw std::exception();
      
      const TT* cast = reinterpret_cast<const TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return *cast;
    }
    
    /// @brief Get the value stored in UniquePointer.
    /// @return the value stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    Reference<T> ToReference() {
      if (this->ptr == null)
        return Reference<T>();
      return ToObject();
    }
    
    /// @brief Get the value stored in UniquePointer.
    /// @return the value stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    Reference<T> ToReference() const {
      if (this->ptr == null)
        return Reference<T>();
      return ToObject();
    }
    
    /// @brief Get the value stored in UniquePointer with specified type.
    /// @return the value stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    template<typename TT>
    Reference<TT> ToReference() {
      if (this->ptr == null)
        return Reference<T>();
      return ToObject<TT>();
    }
    
    /// @brief Get the value stored in UniquePointer with specified type.
    /// @return the value stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    template<typename TT>
    Reference<TT> ToReference() const {
      if (this->ptr == null)
        return Reference<T>();
      return ToObject<TT>();
    }
    
    /// @brief Get the pointer stored in UniquePointer.
    /// @return the pointer stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    T* ToPointer() {
      if (this->ptr == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Get the pointer stored in UniquePointer.
    /// @return the pointer stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    const T* ToPointer() const {
      if (this->ptr == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Get the pointer stored in UniquePointer with specified type.
    /// @return the pointer stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    template<typename TT>
    TT* ToPointer() {
      if (this->ptr == null)
        throw std::exception();
      
      TT* cast = dynamic_cast<TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      
      return cast;
    }
    
    /// @brief Get the pointer stored in UniquePointer with specified type.
    /// @return the pointer stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    template<typename TT>
    const TT* ToPointer() const {
      if (this->ptr == null)
        throw std::exception();
      
      const TT* cast = reinterpret_cast<const TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return cast;
    }
    
    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// UniquePointer<string> s = new string("Test string");
    /// UniquePointer<IComparable> comparable = s.ToDynamicInstanceOfType<IComparable>();
    /// @endcode
    template<typename TT>
    UniquePointer<TT> As() {
      try {
        if (this->ptr == null)
          return UniquePointer<TT>::Null();
        TT* ptr = dynamic_cast<TT*>(this->ptr);
        Release();
        return UniquePointer<TT>(ptr);
      } catch (const std::bad_cast&) {
        return UniquePointer<TT>::Null();
      }
    }
    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// UniquePointer<string> s = new string("Test string");
    /// UniquePointer<IComparable> comparables = Pointer<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static UniquePointer<TT> As(UniquePointer<T>& up) { return up.As<TT>(); }
    
    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// UniquePointer<string> s = new string("Test string");
    /// UniquePointer<IComparable> comparable = s.ToDynamicInstanceOfType<IComparable>();
    /// @endcode
    template<typename TT>
    bool Is() {
      try {
        if (this->ptr == null)
          return false;
        return dynamic_cast<TT*>(this->ptr) != null;
      } catch (const std::bad_cast&) {
        return false;
      }
    }
    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// UniquePointer<string> s = new string("Test string");
    /// UniquePointer<IComparable> comparables = Pointer<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static bool Is(UniquePointer<T>& up) { return up.Is<TT>(); }
    
    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// UniquePointer<string> s = new string("Test string");
    /// UniquePointer<IComparable> comparable = s.ToDynamicInstanceOfType<IComparable>();
    /// @endcode
    template<typename TT>
    UniquePointer<TT> ChangeType() {
      TT* ptr = this->ToPointer<TT>();
      Release();
      return UniquePointer<TT>(ptr);
    }

    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// UniquePointer<string> s = new string("Test string");
    /// UniquePointer<IComparable> comparables = Pointer<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static UniquePointer<TT> ChangeType(UniquePointer<T>& up) { return up.ChangeType<TT>(); }
    
    /*
    /// @brief Creates a shared pointer out of the current unique pointer, which looses the ownership of the pointed data.
    /// @par Examples
    /// @code
    /// UniquePointer<string> uniqueString = new string("Test string");
    /// SharedPointer<string> sharedString = uniqueString.Share();
    /// @endcode
     SharedPointer<T> Share() {
     return Release();
     }
     */
    
    /*
    /// @brief Creates a shared pointer out of the up unique pointer, which looses the ownership of the pointed data.
    /// @par Examples
    /// @code
    /// UniquePointer<string> uniqueString = new string("Test string");
    /// SharedPointer<string> sharedString = UniquePointer<string>::Share(uniqueString);
    /// @endcode
     static SharedPointer<T> Share(UniquePointer<T>& up) {
     return up.Share();
     }
     */
    
    /// @brief Returns a string that represents the current UniquePointer.
    /// @return string A string that represents the current object.
    std::string ToString() const noexcept {
      if (this->ptr == null)
        return "Pcf::UniquePointer [Pointer=null]";
      std::stringstream s;
      s << "Pcf::UniquePointer [Pointer=" << this->ptr << "]";
      return s.str();
    }
    
    template<typename ...Arguments>
    static UniquePointer<T> Create(Arguments... arguments) {
      return UniquePointer<T>(new T(arguments...));
    }
    
    template<typename TT, typename ...Arguments>
    static UniquePointer<T> Create(Arguments... arguments) {
      return UniquePointer<T>(new TT(arguments...));
    }
    
    /// @cond
    virtual ~UniquePointer() { Delete(); }
    
    const T& operator *() const { return ToObject(); }
    T& operator *() { return ToObject(); }
    
    const T& operator()() const { return ToObject(); }
    T& operator()() { return ToObject(); }
    
    const T* operator ->() const { return ToPointer(); }
    T* operator ->() { return ToPointer(); }
    
    UniquePointer<T>& operator =(const T* ptr) {
      Reset(ptr);
      return *this;
    }
    
    UniquePointer<T>& operator =(const UniquePointer<T>& ptr) {
      Swap(const_cast<UniquePointer<T>&>(ptr));
      return *this;
    }
    
    bool operator ==(const T* ptr) { return this->ptr == ptr; }
    
    bool operator ==(const UniquePointer<T>& ptr) { return this->ptr == ptr.ptr; }
    
    bool operator !=(const T* ptr) { return this->ptr != ptr; }
    
    bool operator !=(const UniquePointer<T>& ptr) { return this->ptr != ptr.ptr; }
    
    operator bool() const { return this->ptr != null; }
    
    bool operator !() const { return this->ptr == null; }
    /// @endcond
    
  private:
    T* ptr = null;
  };
  
  /// @brief Manages the storage of an array, providing a limited garbage-collection facility, with little to no overhead over built-in pointers.
  template<typename T>
  class UniquePointer<T[]> {
  public:
    /// @brief Represent a Null UniquePointer.
    static const UniquePointer<T[]>& Null() { static UniquePointer<T> nullPointer; return nullPointer; }
    
    /// @brief Represent an Empty UniquePointer.
    static const UniquePointer<T[]>& Empty() { static UniquePointer<T> emptyPointer; return emptyPointer; }
    
    /// @brief Create a null UniquePointer.
    UniquePointer() {}
    
    /// @brief Create a Pointer with specified pointer.
    /// @param ptr Pointer to store.
    UniquePointer(const T* ptr) { Reset(ptr); }
    
    /// @brief Copy a UniquePointer specified
    /// @param ptr UniquePointer to copy.
    UniquePointer(const UniquePointer<T[]>& ptr) { Swap(ptr); }
    
    /// @brief Destroy the current pointer and set to null.
    void Delete() { Reset(null); }
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    bool IsNull() const { return this->ptr == null; }
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    static bool IsNullOrInvalid(const UniquePointer<T[]>& up) { return &up == null || up.IsNull(); }
    
    /// @brief Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer.
    /// @return A pointer to the object managed by UniquePointer before the call.
    T* Release() {
      T* ptr = this->ptr;
      this->ptr = null;
      return ptr;
    }
    
    /// @brief Destroy the current pointer and set to null.
    void Reset() { Reset(null); }
    
    /// @brief Destroy the current pointer and set to new specified pointer.
    /// @param ptr new ptr to store.
    void Reset(const T* ptr) {
      if (this->ptr != null)
        delete[] this->ptr;
      this->ptr = const_cast<T*>(ptr);
    }
    
    /// @brief Exchanges the contents of the UniquePointer object with those of p, transferring ownership of any managed object between them without destroying either.
    /// @param ptr Another UniquePointer object of the same type.
    void Swap(const UniquePointer<T[]>& ptr) {
      T* p = ptr.ptr;
      const_cast<UniquePointer<T[]>& >(ptr).ptr = this->ptr;
      Reset(p);
    }
    
    /// @brief Get the pointer stored in UniquePointer.
    /// @return the pointer stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    T* ToPointer() {
      if (this->ptr == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Get the pointer stored in UniquePointer.
    /// @return the pointer stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    const T* ToPointer() const {
      if (this->ptr == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Get the pointer stored in UniquePointer with specified type.
    /// @return the pointer stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    template<typename TT>
    TT* ToPointer() {
      if (this->ptr == null)
        throw std::exception();
      
      TT* cast = reinterpret_cast<TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      
      return cast;
    }
    
    /// @brief Get the pointer stored in UniquePointer with specified type.
    /// @return the pointer stored in UniquePointer.
    /// @exception NullPointerException the UniquePointer is null
    template<typename TT>
    const TT* ToPointer() const {
      if (this->ptr == null)
        throw std::exception();
      
      const TT* cast = reinterpret_cast<const TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return cast;
    }
    
    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// UniquePointer<string> s = new string("Test string");
    /// UniquePointer<IComparable> comparable = s.ToDynamicInstanceOfType<IComparable>();
    /// @endcode
    template<typename TT>
    UniquePointer<TT> ChangeType() {
      TT* ptr = ToPointer<TT>();
      Release();
      return UniquePointer<TT[]>(ptr);
    }
    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// Pointer<string[]> strings = new string[23];
    /// Pointer<IComparable[]> comparables = Pointer<string[]>::ChangeType<IComparable[]>(strings);
    /// @endcode
    template<typename TT>
    static UniquePointer<TT> ChangeType(UniquePointer<T[]>& up) { return up.ChangeType<TT>(); }
    
    /// @brief Returns a string that represents the current UniquePointer.
    /// @return string A string that represents the current object.
    std::string ToString() const noexcept {
      if (this->ptr == null)
        return "Pcf::UniquePointer [Pointer=null]";
      std::stringstream s;
      s << "Pcf::UniquePointer [Pointer=" << this->ptr << "]";
      return s.str();
    }
    
    static UniquePointer<T[]> Create(int32 size) {
      return UniquePointer<T[]>(new T[size]);
    }
    
    /// @cond
    virtual ~UniquePointer() { Delete(); }
    
    const T* operator ->() const { return ToPointer(); }
    
    T* operator ->() { return ToPointer(); }
    
    T& operator [](int i) { return this->ptr[i]; }
    
    const T& operator [](int i) const { return this->ptr[i]; }
    
    UniquePointer<T[]>& operator =(const T* ptr) {
      Reset(ptr);
      return *this;
    }
    
    UniquePointer<T[]>& operator =(const UniquePointer<T>& ptr) {
      Swap(ptr);
      return *this;
    }
    
    bool operator ==(const T* ptr) { return this->ptr == ptr; }
    
    bool operator ==(const UniquePointer<T[]>& ptr) { return this->ptr == ptr.ptr; }
    
    bool operator !=(const T* ptr) { return this->ptr != ptr; }
    
    bool operator !=(const UniquePointer<T[]>& ptr) { return this->ptr != ptr.ptr; }
    
    operator bool() const { return this->ptr != null; }
    
    bool operator !() const { return this->ptr == null; }
    /// @endcond
    
  private:
    T* ptr = null;
  };
  
  /// @brief Manages the storage of a pointer, providing a limited garbage-collection facility, with little to no overhead over built-in pointers.
  /// @see Pcf::Up
  /// @ingroup Pcf
  template<typename T>
  using up = UniquePointer<T>;
}

using namespace Pcf;
