/// @file
/// @brief Contains Pcf::System::Allocator <T> class.
#pragma once

#include <cstddef>
#include <memory>

namespace Pcf {
  namespace System {
    template<class T> class Allocator;
    
    /// @cond
    template<>
    class Allocator<void> {
    public:
      using Pointer = void*;
      using ConstPointer = const void*;
      using ValueType = void;
      
      template<typename TT> struct Rebind {using  other = Allocator<TT>;};
      
      using pointer = void*;
      using const_pointer = const void* ;
      using value_type = void;

      template<typename TT> struct rebind {using other = Allocator<TT>;};
    };
    /// @endcond
    
    /// @brief This is the default Allocator used by all Pcf library containers if no user-specified allocator is provided. The default allocator is stateless, that is, all instances of the given allocator are interchangeable, compare equal and can deallocate memory allocated by any other instance of the same allocator type.
    template<class T>
    class Allocator {
    public:
      using SizeType = size_t;
      using DifferenceType = ptrdiff_t;
      using Pointer = T*;
      using ConstPointer = const T*;
      using Reference = T&;
      using ConstReference = const T&;
      using ValueType = T;
      
      template<typename TT> struct Rebind {using other = Allocator<TT>;};
      
      Allocator() noexcept {}
      Allocator(const Allocator&) noexcept {}

      template<typename TT>
      explicit Allocator(const Allocator<TT>&) noexcept {}
      
      virtual Pointer Address(Reference value) const noexcept {return (Pointer)&reinterpret_cast<const volatile char&>(value);}
      
      virtual ConstPointer Address(ConstReference value) const noexcept {return (Pointer)&reinterpret_cast<const volatile char&>(value);}
      
      virtual Pointer Allocate(SizeType number) {return static_cast<Pointer>(::operator new(number * sizeof(T)));}
      
      virtual Pointer Allocate(SizeType number, Allocator<void>::ConstPointer hint) {return static_cast<Pointer>(::operator new(number * sizeof(T)));}
      
      virtual void Deallocate(Pointer pointer, SizeType size) noexcept {::operator delete((void*)pointer);}
      
      virtual SizeType MaxSize() const noexcept {return SizeType(~0) / sizeof(T);}
      
      void Construct(Pointer pointer) {::new((void*)pointer) T();}
      
      template<typename T1>
      void Construct(Pointer pointer, T1& a1) {::new((void*)pointer) T(a1);}
      
      template<typename T1>
      void Construct(Pointer pointer, const T1& a1) {::new((void*)pointer) T(a1);}
      
      template<typename T1, typename T2>
      void Construct(Pointer pointer, T1& a1, T2& a2) {::new((void*)pointer) T(a1, a2);}
      
      template<typename T1, typename T2>
      void Construct(Pointer pointer, const T1& a1, T2& a2) {::new((void*)pointer) T(a1, a2);}
      
      template<typename T1, typename T2>
      void Construct(Pointer pointer, T1& a1, const T2& a2) {::new((void*)pointer) T(a1, a2);}
      
      template<typename T1, typename T2>
      void Construct(Pointer pointer, const T1& a1, const T2& a2) {::new((void*)pointer) T(a1, a2);}
      
      template<typename T1, typename T2, typename T3>
      void Construct(Pointer pointer, T1& a1, T2& a2, T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      
      template<typename T1, typename T2, typename T3>
      void Construct(Pointer pointer, const T1& a1, T2& a2, T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      
      template<typename T1, typename T2, typename T3>
      void Construct(Pointer pointer, T1& a1, const T2& a2, T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      
      template<typename T1, typename T2, typename T3>
      void Construct(Pointer pointer, T1& a1, T2& a2,const  T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      
      template<typename T1, typename T2, typename T3>
      void Construct(Pointer pointer, const T1& a1, const T2& a2, T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      
      template<typename T1, typename T2, typename T3>
      void Construct(Pointer pointer, const T1& a1, T2& a2, const T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      
      template<typename T1, typename T2, typename T3>
      void Construct(Pointer pointer, const T1& a1, const T2& a2, const T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      
      template<typename T1, typename T2, typename T3>
      void Construct(Pointer pointer, T1& a1, const T2& a2, const T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      
      void Destroy(Pointer pointer) {pointer->~T();}

      bool operator ==(const Allocator<T>& allocator) const { return true; }
      bool operator !=(const Allocator<T>& allocator) const { return !this->operator ==(allocator); }

      /// @cond
      using size_type = size_t;
      using difference_type = ptrdiff_t;
      using pointer = T*;
      using const_pointer = const T*;
      using reference = T&;
      using const_reference = const T&;
      using value_type = T;
      virtual ~Allocator() {}
      template<class TT> struct rebind {using other = Allocator<TT>;};
      Pointer address(Reference value) const noexcept {return Address(value);}
      ConstPointer address(ConstReference value) const noexcept {return Address(value);}
      Pointer allocate(SizeType number) {return Allocate(number);}
      Pointer allocate(SizeType number, Allocator<void>::ConstPointer hint) {return Allocate(number, hint);}
      void deallocate(Pointer pointer, SizeType size) noexcept {Deallocate(pointer, size);}
      SizeType max_size() const noexcept {return MaxSize();}
      void construct(Pointer pointer) {::new((void*)pointer) T();}
      template<typename T1> void construct(Pointer pointer, T1& a1) {::new((void*)pointer) T(a1);}
      template<typename T1> void construct(Pointer pointer, const T1& a1) {::new((void*)pointer) T(a1);}
      template<typename T1, typename T2> void construct(Pointer pointer, T1& a1, T2& a2) {::new((void*)pointer) T(a1, a2);}
      template<typename T1, typename T2> void construct(Pointer pointer, const T1& a1, T2& a2) {::new((void*)pointer) T(a1, a2);}
      template<typename T1, typename T2> void construct(Pointer pointer, T1& a1, const T2& a2) {::new((void*)pointer) T(a1, a2);}
      template<typename T1, typename T2> void construct(Pointer pointer, const T1& a1, const T2& a2) {::new((void*)pointer) T(a1, a2);}
      template<typename T1, typename T2, typename T3> void construct(Pointer pointer, T1& a1, T2& a2, T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      template<typename T1, typename T2, typename T3> void construct(Pointer pointer, const T1& a1, T2& a2, T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      template<typename T1, typename T2, typename T3> void construct(Pointer pointer, T1& a1, const T2& a2, T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      template<typename T1, typename T2, typename T3> void construct(Pointer pointer, T1& a1, T2& a2,const  T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      template<typename T1, typename T2, typename T3> void construct(Pointer pointer, const T1& a1, const T2& a2, T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      template<typename T1, typename T2, typename T3> void construct(Pointer pointer, const T1& a1, T2& a2, const T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      template<typename T1, typename T2, typename T3> void construct(Pointer pointer, const T1& a1, const T2& a2, const T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      template<typename T1, typename T2, typename T3> void construct(Pointer pointer, T1& a1, const T2& a2, const T3& a3) {::new((void*)pointer) T(a1, a2, a3);}
      void destroy(Pointer pointer) {pointer->~T();}
      /// @endcond
    };
  }
}

using namespace Pcf;
