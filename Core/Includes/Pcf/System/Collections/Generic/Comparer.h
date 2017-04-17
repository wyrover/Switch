/// @file
/// @brief Contains Pcf::System::Collections::Generic::Comparer <T> class.
#pragma once

#include "../../../As.h"
#include "../../../Property.h"
#include "../../../Is.h"
#include "../../../RefPtr.h"
#include "../../ArgumentNullException.h"
#include "../../Object.h"
#include "IComparer.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Exposes a method that compares two objects.
        template<typename T>
        class Comparer : public Object, public IComparer<T> {
        public:
          /// @brief Returns a default sort order comparer for the type specified by the generic argument
          static Property<const IComparer<T>&, ReadOnly> Default;

          /// @brief Create a new instance of class Comparer
          Comparer() {}
          
          /// @brief Destroy instance of the class Comparer
          ~Comparer() {}

          /// @brief Compares two entities and returns a value indicating whether one is less than, equal to, or greater than the other.
          /// @param x The first entity to compare.
          /// @param y The second entity to compare.
          /// @return Int32 A 32-bit signed integer that indicates the relative order of the entities being compared. The return value has these meanings:
          /// Less than zero      x is less than y.
          /// Zero                x equals y.
          /// Greater than zero   x is greater than y.
          virtual int32 Compare(const T& x, const T& y) const {return x < y ? -1 : (x == y ? 0 : 1);}
        };

        template<typename T>
        class ReversedComparer : public Object, public System::Collections::Generic::IComparer<T> {
        public:
          static refptr<IComparer<T>> Create(const refptr<IComparer<T>>& comparer) {
            if (is< ReversedComparer<T>> (comparer))
              return as< ReversedComparer<T>>(comparer)->comparer;
            return new ReversedComparer(comparer);
          }

          virtual int32 Compare(const T& x, const T& y) const {return -(this->comparer->Compare(x,y));}

        private:
          ReversedComparer(const refptr<IComparer<T>>& comparer) {this->comparer = comparer;}
          refptr< IComparer<T>> comparer;
        };
        
        /// @cond
        template<class T>
        inline const IComparer<T>& __get_default_comparer__() {
          static Comparer<T> comparer;
          return comparer;
        }

        template <typename T>
        Property<const IComparer<T>&, ReadOnly> Comparer<T>::Default = {&__get_default_comparer__<T>};
        /// @endcond
      }
    }
  }
}

using namespace Pcf;