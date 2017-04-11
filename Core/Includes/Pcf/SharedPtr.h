/// @file
/// @brief Contains Pcf::SharedPtr <T> class.
#pragma once

#include <atomic>
#include <exception>
#include <string>
#include <sstream>

#include "Types.h"
#include "RefPtr.h"

namespace Pcf {
  /// @brief Represents a Reference Pointer class. A SharedPtr is a memory-managing pointer to an object.
  /// @remarks A Reference Pointer is basically a pointer with a destructor. The destructor ensures that the object pointed to is deleted when it is no longer being used. You can have multiple pointers to the same object, so the object is only deleted when the last pointer is destroyed.
  /// @remarks A Reference Pointer has to have slightly different characteristics to a conventional C pointer. These differences show up in the behaviour of the pointer on assignment and when the pointer's address (i.e. the object being pointed to) is changed. Deciding the exact behaviour is difficult and very subjective. This could be solved by having a range of different classes with slightly different behaviour. You could then choose which one suits your problem. However, I don't agree with this approach - I think you get quickly bogged down with the subtle differences and lose sight of the program you are actually trying to write. So I provide just one kind of Reference Pointer which I believe is the most general-purpose. I think this is consistent with the STL, which provides just one kind of vector, map, list etc.
  /// @remarks The Reference Pointer contains the address of the object pointed to and a counter which stores the alias count. When one Reference Pointer is assigned to another, the second Reference Pointer becomes an alias of the first, which means that it is pointing to the same object. The alias count of the object is incremented to show that there are now two pointers pointing to the same object.
  /// @remarks In fact, an extra level of indirection needs to be used. A Reference Pointer class in fact contains a pointer to a sub-object which in turn contains the address of the contained object and an integer containing the alias count.
  /// @image html sharepointer.gif
  /// @remarks In this figure, there are two SharedPtr objects pointing to the same sub-object (which is actually part of the SharedPtr structure hidden from the user), which then points to the data object which is the user's data. The alias count is stored in the sub-object. There is an alias count of 2 because there are two SharedPtr objects pointing to the sub-object.
  /// @remarks When a Reference Pointer goes out of scope or is destroyed for any reason, it is dealiased. This means that the Reference Pointer no longer points to the object. It's alias count is decremented to show that one less Reference Pointer is pointing at the object. When the alias count decrements to zero, this indicates that the object is no longer being pointed to by any Reference Pointers and so it is deleted automatically.
  /// @remarks A consequence of the Reference Pointer design is that if you change the object pointed to by one SharedPtr, you change the object pointed to by its aliases too. In other words, if you change the address of one SharedPtr, you are actually changing the address stored in the sub-object, which is visible to all other aliases, so these appear to change their stored address too. The result is that all aliases end up still being aliases and all pointing to the new object, whilst the old object gets deleted automatically because it is no longer pointed to.
  /// @remarks This behaviour is unlike conventional C pointers - if you allocate a new object to a pointer variable, you don't expect other pointer variables to change too. However, it can have very significant advantages in data structure design. It is common when designing large and complex data structures to have several different ways of accessing objects - for example you might store an object in a map which allows access to objects sorted in alphabetical order, but also store it in a vector which allows access to objects in the order in which they were created. Traditionally this could lead to problems in memory managing the object when removing it from one or other since it could become ambiguous which data structure is the container responsible for deallocating its memory. However, with Reference Pointers this problem disappears - put a Reference Pointer in both map and vector pointing to the same object, i.e. aliases. The object will persist until both Reference Pointers are deallocated. Furthermore, if the object pointed to needs to be changed, it can be changed by changing either alias. So, you can look it up in the map, change the address and the address pointed to by the other alias in the vector will automatically change to the new object - they remain consistent.
  /// @remarks For more information see also  http://stlplus.sourceforge.net/stlplus3/docs/smart_ptr.html
  /// @par Examples
  /// This example show how to used SharedPtr :
  /// @include SharedPtr.cpp
  /// @ingroup Pcf
  template<typename T>
  using SharedPtr = RefPtr<T>;
  
  template<typename T, typename ...Args>
  SharedPtr<T> MakeShared(Args... args) {return SharedPtr<T>(new T(args...));}
}

using namespace Pcf;
