/// @file
/// @brief Contains Pcf::UniquePtr <T> class.
#pragma once

#include <exception>
#include <string>
#include <sstream>

#include "Types.h"
#include "Ref.h"

namespace Pcf {
  /// @brief Manages the storage of a pointer, providing a limited garbage-collection facility, with little to no overhead over built-in pointers.
  template<typename T>
  class UniquePtr {
  public:
    /// @brief Represent a Null UniquePtr.
    static const UniquePtr<T>& Null() { static UniquePtr<T> nullPointer; return nullPointer; }
    
    /// @brief Represent an Empty UniquePtr.
    static const UniquePtr<T>& Empty() { static UniquePtr<T> emptyPointer; return emptyPointer; }
    
    /// @brief Create a null UniquePtr.
    UniquePtr() {}
    
    /// @brief Create a Pointer with specified pointer.
    /// @param ptr Pointer to store.
    UniquePtr(const T* ptr) { this->Reset(ptr); }
    
    /// @brief Copy a UniquePtr specified
    /// @param ptr UniquePtr to copy.
    UniquePtr(const UniquePtr& ptr) { this->Swap(const_cast<UniquePtr<T>&>(ptr)); }
    
    /// @brief Destroy the current pointer and set to null.
    void Delete() { this->Reset(null); }
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    bool IsNull() const { return this->ptr == null; }
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    static bool IsNullOrInvalid(const UniquePtr<T>& up) { return &up == null || up.IsNull(); }
    
    /// @brief Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer.
    /// @return A pointer to the object managed by UniquePtr before the call.
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
    
    /// @brief Exchanges the contents of the UniquePtr object with those of ptr, transferring ownership of any managed object between them without destroying either.
    /// @param ptr Another UniquePtr object of the same type.
    void Swap(UniquePtr<T>& ptr) {
      T* p = ptr.ptr;
      ptr.ptr = this->ptr;
      this->ptr = p;
    }
    
    static void Swap(UniquePtr<T>& ptrA, UniquePtr<T>& ptrB) { ptrA.Swap(ptrB); }
    
    /// @brief Get the value stored in UniquePtr.
    /// @return the value stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    T& ToObject() {
      if (this->ptr == null)
        throw std::exception();
      
      return *this->ptr;
    }
    
    /// @brief Get the value stored in UniquePtr.
    /// @return the value stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    const T& ToObject() const {
      if (this->ptr == null)
        throw std::exception();
      
      return *this->ptr;
    }
    
    /// @brief Get the value stored in UniquePtr with specified type.
    /// @return the value stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    template<typename TT>
    TT& ToObject() {
      if (this->ptr == null)
        throw std::exception();
      
      TT* cast = reinterpret_cast<TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return *cast;
    }
    
    /// @brief Get the value stored in UniquePtr with specified type.
    /// @return the value stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    template<typename TT>
    const TT& ToObject() const {
      if (this->ptr == null)
        throw std::exception();
      
      const TT* cast = reinterpret_cast<const TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return *cast;
    }
    
    /// @brief Get the value stored in UniquePtr.
    /// @return the value stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    ref<T> ToReference() {
      if (this->ptr == null)
        return ref<T>();
      return ToObject();
    }
    
    /// @brief Get the value stored in UniquePtr.
    /// @return the value stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    ref<T> ToReference() const {
      if (this->ptr == null)
        return ref<T>();
      return ToObject();
    }
    
    /// @brief Get the value stored in UniquePtr with specified type.
    /// @return the value stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    template<typename TT>
    ref<TT> ToReference() {
      if (this->ptr == null)
        return ref<T>();
      return ToObject<TT>();
    }
    
    /// @brief Get the value stored in UniquePtr with specified type.
    /// @return the value stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    template<typename TT>
    ref<TT> ToReference() const {
      if (this->ptr == null)
        return ref<T>();
      return ToObject<TT>();
    }
    
    /// @brief Get the pointer stored in UniquePtr.
    /// @return the pointer stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    T* ToPointer() {
      if (this->ptr == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Get the pointer stored in UniquePtr.
    /// @return the pointer stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    const T* ToPointer() const {
      if (this->ptr == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Get the pointer stored in UniquePtr with specified type.
    /// @return the pointer stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    template<typename TT>
    TT* ToPointer() {
      if (this->ptr == null)
        throw std::exception();
      
      TT* cast = dynamic_cast<TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      
      return cast;
    }
    
    /// @brief Get the pointer stored in UniquePtr with specified type.
    /// @return the pointer stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
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
    /// UniquePtr<string> s = new string("Test string");
    /// UniquePtr<IComparable> comparable = s.ToDynamicInstanceOfType<IComparable>();
    /// @endcode
    template<typename TT>
    UniquePtr<TT> As() {
      try {
        if (this->ptr == null)
          return UniquePtr<TT>::Null();
        TT* ptr = dynamic_cast<TT*>(this->ptr);
        Release();
        return UniquePtr<TT>(ptr);
      } catch (const std::bad_cast&) {
        return UniquePtr<TT>::Null();
      }
    }
    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// UniquePtr<string> s = new string("Test string");
    /// UniquePtr<IComparable> comparables = Pointer<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static UniquePtr<TT> As(UniquePtr<T>& up) { return up.As<TT>(); }
    
    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// UniquePtr<string> s = new string("Test string");
    /// UniquePtr<IComparable> comparable = s.ToDynamicInstanceOfType<IComparable>();
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
    /// UniquePtr<string> s = new string("Test string");
    /// UniquePtr<IComparable> comparables = Pointer<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static bool Is(UniquePtr<T>& up) { return up.Is<TT>(); }
    
    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// UniquePtr<string> s = new string("Test string");
    /// UniquePtr<IComparable> comparable = s.ToDynamicInstanceOfType<IComparable>();
    /// @endcode
    template<typename TT>
    UniquePtr<TT> ChangeType() {
      TT* ptr = this->ToPointer<TT>();
      Release();
      return UniquePtr<TT>(ptr);
    }

    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// UniquePtr<string> s = new string("Test string");
    /// UniquePtr<IComparable> comparables = Pointer<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static UniquePtr<TT> ChangeType(UniquePtr<T>& up) { return up.ChangeType<TT>(); }
    
    /*
    /// @brief Creates a shared pointer out of the current unique pointer, which looses the ownership of the pointed data.
    /// @par Examples
    /// @code
    /// UniquePtr<string> uniqueString = new string("Test string");
    /// refptr<string> sharedString = uniqueString.Share();
    /// @endcode
     refptr<T> Share() {
     return Release();
     }
     */
    
    /*
    /// @brief Creates a shared pointer out of the up unique pointer, which looses the ownership of the pointed data.
    /// @par Examples
    /// @code
    /// UniquePtr<string> uniqueString = new string("Test string");
    /// refptr<string> sharedString = UniquePtr<string>::Share(uniqueString);
    /// @endcode
     static refptr<T> Share(UniquePtr<T>& up) {
     return up.Share();
     }
     */
    
    /// @brief Returns a string that represents the current UniquePtr.
    /// @return string A string that represents the current object.
    std::string ToString() const {
      if (this->ptr == null)
        return "Pcf::UniquePtr [Pointer=null]";
      std::stringstream s;
      s << "Pcf::UniquePtr [Pointer=" << this->ptr << "]";
      return s.str();
    }
    
    template<typename ...Arguments>
    static UniquePtr<T> Create(Arguments... arguments) {
      return UniquePtr<T>(new T(arguments...));
    }
    
    template<typename TT, typename ...Arguments>
    static UniquePtr<T> Create(Arguments... arguments) {
      return UniquePtr<T>(new TT(arguments...));
    }
    
    /// @cond
    virtual ~UniquePtr() { Delete(); }
    
    const T& operator *() const { return ToObject(); }
    T& operator *() { return ToObject(); }
    
    const T& operator()() const { return ToObject(); }
    T& operator()() { return ToObject(); }
    
    const T* operator ->() const { return ToPointer(); }
    T* operator ->() { return ToPointer(); }
    
    UniquePtr<T>& operator =(const T* ptr) {
      Reset(ptr);
      return *this;
    }
    
    UniquePtr<T>& operator =(const UniquePtr<T>& ptr) {
      Swap(const_cast<UniquePtr<T>&>(ptr));
      return *this;
    }
    
    bool operator ==(const T* ptr) { return this->ptr == ptr; }
    
    bool operator ==(const UniquePtr<T>& ptr) { return this->ptr == ptr.ptr; }
    
    bool operator !=(const T* ptr) { return this->ptr != ptr; }
    
    bool operator !=(const UniquePtr<T>& ptr) { return this->ptr != ptr.ptr; }
    
    operator bool() const { return this->ptr != null; }
    
    bool operator !() const { return this->ptr == null; }
    /// @endcond
    
  private:
    T* ptr = null;
  };
  
  /// @brief Manages the storage of an array, providing a limited garbage-collection facility, with little to no overhead over built-in pointers.
  template<typename T>
  class UniquePtr<T[]> {
  public:
    /// @brief Represent a Null UniquePtr.
    static const UniquePtr<T[]>& Null() { static UniquePtr<T> nullPointer; return nullPointer; }
    
    /// @brief Represent an Empty UniquePtr.
    static const UniquePtr<T[]>& Empty() { static UniquePtr<T> emptyPointer; return emptyPointer; }
    
    /// @brief Create a null UniquePtr.
    UniquePtr() {}
    
    /// @brief Create a Pointer with specified pointer.
    /// @param ptr Pointer to store.
    UniquePtr(const T* ptr) { Reset(ptr); }
    
    /// @brief Copy a UniquePtr specified
    /// @param ptr UniquePtr to copy.
    UniquePtr(const UniquePtr<T[]>& ptr) { Swap(ptr); }
    
    /// @brief Destroy the current pointer and set to null.
    void Delete() { Reset(null); }
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    bool IsNull() const { return this->ptr == null; }
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    static bool IsNullOrInvalid(const UniquePtr<T[]>& up) { return &up == null || up.IsNull(); }
    
    /// @brief Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer.
    /// @return A pointer to the object managed by UniquePtr before the call.
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
    
    /// @brief Exchanges the contents of the UniquePtr object with those of p, transferring ownership of any managed object between them without destroying either.
    /// @param ptr Another UniquePtr object of the same type.
    void Swap(const UniquePtr<T[]>& ptr) {
      T* p = ptr.ptr;
      const_cast<UniquePtr<T[]>& >(ptr).ptr = this->ptr;
      Reset(p);
    }
    
    /// @brief Get the pointer stored in UniquePtr.
    /// @return the pointer stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    T* ToPointer() {
      if (this->ptr == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Get the pointer stored in UniquePtr.
    /// @return the pointer stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    const T* ToPointer() const {
      if (this->ptr == null)
        throw std::exception();
      
      return this->ptr;
    }
    
    /// @brief Get the pointer stored in UniquePtr with specified type.
    /// @return the pointer stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
    template<typename TT>
    TT* ToPointer() {
      if (this->ptr == null)
        throw std::exception();
      
      TT* cast = reinterpret_cast<TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      
      return cast;
    }
    
    /// @brief Get the pointer stored in UniquePtr with specified type.
    /// @return the pointer stored in UniquePtr.
    /// @exception NullPointerException the UniquePtr is null
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
    /// UniquePtr<string> s = new string("Test string");
    /// UniquePtr<IComparable> comparable = s.ToDynamicInstanceOfType<IComparable>();
    /// @endcode
    template<typename TT>
    UniquePtr<TT> ChangeType() {
      TT* ptr = ToPointer<TT>();
      Release();
      return UniquePtr<TT[]>(ptr);
    }
    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// Pointer<string[]> strings = new string[23];
    /// Pointer<IComparable[]> comparables = Pointer<string[]>::ChangeType<IComparable[]>(strings);
    /// @endcode
    template<typename TT>
    static UniquePtr<TT> ChangeType(UniquePtr<T[]>& up) { return up.ChangeType<TT>(); }
    
    /// @brief Returns a string that represents the current UniquePtr.
    /// @return string A string that represents the current object.
    std::string ToString() const {
      if (this->ptr == null)
        return "Pcf::UniquePtr [Pointer=null]";
      std::stringstream s;
      s << "Pcf::UniquePtr [Pointer=" << this->ptr << "]";
      return s.str();
    }
    
    static UniquePtr<T[]> Create(int32 size) {
      return UniquePtr<T[]>(new T[size]);
    }
    
    /// @cond
    virtual ~UniquePtr() { Delete(); }
    
    const T* operator ->() const { return ToPointer(); }
    
    T* operator ->() { return ToPointer(); }
    
    T& operator [](int i) { return this->ptr[i]; }
    
    const T& operator [](int i) const { return this->ptr[i]; }
    
    UniquePtr<T[]>& operator =(const T* ptr) {
      Reset(ptr);
      return *this;
    }
    
    UniquePtr<T[]>& operator =(const UniquePtr<T>& ptr) {
      Swap(ptr);
      return *this;
    }
    
    bool operator ==(const T* ptr) { return this->ptr == ptr; }
    
    bool operator ==(const UniquePtr<T[]>& ptr) { return this->ptr == ptr.ptr; }
    
    bool operator !=(const T* ptr) { return this->ptr != ptr; }
    
    bool operator !=(const UniquePtr<T[]>& ptr) { return this->ptr != ptr.ptr; }
    
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
  using up = UniquePtr<T>;
}

using namespace Pcf;
