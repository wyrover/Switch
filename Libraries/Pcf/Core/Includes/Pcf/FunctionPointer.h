/// @file
/// @brief Contains Pcf::FunctionPointer <TResult, ...Arguments> class.
#pragma once

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <functional>

#include "Types.h"

/// @cond
class __function_ptr__ {
public:
  __function_ptr__() {}
  
  __function_ptr__(const __function_ptr__& rhs) {
    this->size = rhs.size;
    if (this->size != 0) {
      this->value = malloc(this->size);
      memcpy(this->value, rhs.value, this->size);
    }
  }
  
  __function_ptr__(std::nullptr_t) : value(null), size(0) {}
  
  template<typename T>
  __function_ptr__(T* value) {
    if (value == null) {
      this->value = null;
      this->size = 0;
      return;
    }
    this->size = sizeof(T*);
    this->value = malloc(this->size);
    memcpy(this->value, &value, this->size);
  }
  
  template<typename T>
  __function_ptr__(const T* value) {
    if (value == null) {
      this->value = null;
      this->size = 0;
      return;
    }
    this->size = sizeof(T*);
    this->value = malloc(this->size);
    memcpy(this->value, &value, this->size);
  }
  
  template<typename T>
  __function_ptr__(T& value) {
    this->size = sizeof(T);
    this->value = malloc(this->size);
    new(this->value) T(value);
  }
  
  template<typename T>
  __function_ptr__(const T& value) {
    this->size = sizeof(T);
    this->value = malloc(this->size);
    new(this->value) T(value);
  }
  
  ~__function_ptr__() {
    if (this->value != null && this->size != 0)
      free(this->value);
  }
  
  __function_ptr__& operator =(const __function_ptr__& rhs) {
    if (this->value != null && this->size != 0)
      free(this->value);
    
    this->size = rhs.size;
    if (this->size != 0) {
      this->value = malloc(this->size);
      memcpy(this->value, rhs.value, this->size);
    }
    return *this;
  }
  
  bool operator ==(const __function_ptr__& rhs) const {
    if (this->size != rhs.size)
      return false;
    return memcmp(this->value, rhs.value, this->size) == 0;
  }
  
  bool operator !=(const __function_ptr__& rhs) const {
    if (this->size != rhs.size)
      return true;
    return memcmp(this->value, rhs.value, this->size) != 0;
  }
  
  template<typename T>
  operator T&() const {
    return *(reinterpret_cast<T*>(this->value));
  }
  
  template<typename T>
  operator T*() const {
    return *reinterpret_cast<T**>(this->value);
  }
  
  bool IsEmpty() const {return this->value == null;}
  bool IsNull() const {return this->value == null;}
  
private:
  void* value = null;
  int size = 0;
};
/// @endcond

namespace Pcf {
  // FunctionPointer<...> 16 arguments
  template<typename TResult = void, typename T1 = std::nullptr_t, typename T2 = std::nullptr_t, typename T3 = std::nullptr_t, typename T4 = std::nullptr_t, typename T5 = std::nullptr_t, typename T6 = std::nullptr_t, typename T7 = std::nullptr_t, typename T8 = std::nullptr_t, typename T9 = std::nullptr_t, typename T10 = std::nullptr_t, typename T11 = std::nullptr_t, typename T12 = std::nullptr_t, typename T13 = std::nullptr_t, typename T14 = std::nullptr_t, typename T15 = std::nullptr_t, typename T16 = std::nullptr_t>
  class FunctionPointer {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 15 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 14 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 13 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 12 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 11 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 10 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 9 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 8 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8);
    };
    
    template<typename T> struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 7 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6, T7) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 6 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5, T6> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5, T6);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6);
    };
    
    template<typename T> struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method), invoker(StaticFunctionInvoker::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5, a6);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5, T6) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 5 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5>
  class FunctionPointer<TResult, T1, T2, T3, T4, T5> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4, T5);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4, T5>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4, T5) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4, a5);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4, a5);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4, T5) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 4 arguments
  template<typename TResult, typename T1, typename T2, typename T3, typename T4>
  class FunctionPointer<TResult, T1, T2, T3, T4> {
  public:
    using Function = TResult(*)(T1, T2, T3, T4);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3, T4>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3, T4);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3, T4) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4) const { return this->invoker(this->target, this->method, a1, a2, a3, a4); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3, T4 a4) const { return this->invoker(this->target, this->method, a1, a2, a3, a4); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3, a4);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3, a4);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3, T4) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 3 arguments
  template<typename TResult, typename T1, typename T2, typename T3>
  class FunctionPointer<TResult, T1, T2, T3> {
  public:
    using Function = TResult(*)(T1, T2, T3);
    
    using FunctionType = FunctionPointer<TResult, T1, T2, T3>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2, T3);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2, T3) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2, T3 a3) const { return this->invoker(this->target, this->method, a1, a2, a3); }
    
    TResult operator ()(T1 a1, T2 a2, T3 a3) const { return this->invoker(this->target, this->method, a1, a2, a3); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2, a3);
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2, T3 a3) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2, a3);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2, T3) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 2 arguments
  template<typename TResult, typename T1, typename T2>
  class FunctionPointer<TResult, T1, T2> {
  public:
    using Function = TResult(*)(T1, T2);
    
    using FunctionType = FunctionPointer<TResult, T1, T2>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1, T2);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1, T2) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1, T2 a2) const { return this->invoker(this->target, this->method, a1, a2); }
    
    TResult operator ()(T1 a1, T2 a2) const { return this->invoker(this->target, this->method, a1, a2); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1, a2);
      }
    };
    
    template<typename T> struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2);
      }
    };
    
    template<typename T> struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2);
      }
    };
    
    template<typename T> struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1, T2 a2) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1, a2);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1, T2) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 1 argument
  template<typename TResult, typename T1>
  class FunctionPointer<TResult, T1> {
  public:
    using Function = TResult(*)(T1);
    
    using FunctionType = FunctionPointer<TResult, T1>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)(T1);
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)(T1) const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke(T1 a1) const { return this->invoker(this->target, this->method, a1); }
    
    TResult operator ()(T1 a1) const { return this->invoker(this->target, this->method, a1); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))(a1);
      }
    };
    
    template<typename T> struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1);
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1);
      }
    };
    
    template<typename T>
    struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function, T1 a1) {
        if (target.IsNull())
          throw std::exception();
        return static_cast<T>(target)(a1);
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&, T1) = StaticFunctionInvoker::Invoke;
  };
  
  // FunctionPointer<...> 0 argument
  template<typename TResult>
  class FunctionPointer<TResult> {
  public:
    using Function = TResult(*)();
    
    using FunctionType = FunctionPointer<TResult>;
    
    template<typename T>
    struct Member {
      using Type = TResult(T::*)();
    };
    
    template<typename T>
    struct ConstMember {
      using Type = TResult(T::*)() const;
    };
    
    FunctionPointer() {}
    
    FunctionPointer(std::nullptr_t) {}
    
    FunctionPointer(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}
    
    FunctionPointer(Function method) : method(method) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}
    
    template<typename T>
    FunctionPointer(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}
    
    FunctionType& operator =(const FunctionType& function) {
      this->target = function.target;
      this->method = function.method;
      this->invoker = function.invoker;
      return *this;
    }
    
    TResult Invoke() const { return this->invoker(this->target, this->method); }
    
    TResult operator ()() const { return this->invoker(this->target, this->method); }
    
    bool operator ==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }
    
    bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }
    
    template<typename T>
    T Target() const {
      return static_cast<T>(this->target);
    }
    
    Function Method() const {
      return static_cast<Function>(this->method);
    }
    
    template<typename T>
    typename ConstMember<T>::Type ConstMethod() const {
      return static_cast<typename ConstMember<T>::Type>(this->method);
    }
    
    template<typename T>
    typename Member<T>::Type Method() const {
      return static_cast<typename Member<T>::Type>(this->method);
    }
    
    bool IsEmpty() const { return target.IsNull() && method.IsNull(); }
    
    bool IsNull() const { return target.IsNull() && method.IsNull(); }
    
  private:
    struct StaticFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function) {
        if (function.IsNull())
          throw std::exception();
        return (static_cast<Function>(function))();
      }
    };
    
    template<typename T>
    struct MemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))();
      }
    };
    
    template<typename T>
    struct ConstMemberFunctionInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function) {
        if (target.IsNull() || function.IsNull())
          throw std::exception();
        return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))();
      }
    };
    
    template<typename T> struct FunctorInvoker {
      static TResult Invoke(const __function_ptr__& target, const __function_ptr__& function) {
        if (target.IsNull())
          throw std::exception();
        return (static_cast<T>(target))();
      }
    };
    
    __function_ptr__ target = null;
    __function_ptr__ method = null;
    TResult(*invoker)(const __function_ptr__&, const __function_ptr__&) = StaticFunctionInvoker::Invoke;
  };

  template<typename TResult = void, typename T1 = std::nullptr_t, typename T2 = std::nullptr_t, typename T3 = std::nullptr_t, typename T4 = std::nullptr_t, typename T5 = std::nullptr_t, typename T6 = std::nullptr_t, typename T7 = std::nullptr_t, typename T8 = std::nullptr_t, typename T9 = std::nullptr_t, typename T10 = std::nullptr_t, typename T11 = std::nullptr_t, typename T12 = std::nullptr_t, typename T13 = std::nullptr_t, typename T14 = std::nullptr_t, typename T15 = std::nullptr_t, typename T16 = std::nullptr_t>
  using fp = FunctionPointer<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>;
}

using namespace Pcf;
