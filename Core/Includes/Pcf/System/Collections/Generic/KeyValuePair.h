/// @file
/// @brief Contains Pcf::System::Collections::Generic::KeyValuePair <TKey, TValue> class.
#pragma once

#include "../../../Property.h"
#include "../../../Is.h"
#include "../../../Types.h"
#include "../../Object.h"
#include "../../_String.h"
#include "../../ArgumentNullException.h"
#include "../../Type.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @cond
        template<typename TKey=void, typename TValue=void>
        class KeyValuePair;
        /// @endcond
        /// @brief Defines a key/value pair that can be set || retrieved.
        template<typename TKey, typename TValue>
        class KeyValuePair : public Object {
        public:
          /// @brief Initializes a new instance of the KeyValuePair<TKey, TValue> class.
          KeyValuePair() {}

          /// @brief Initializes a new instance of the KeyValuePair<TKey, TValue> class as a copy of keyValuePair argument
          KeyValuePair(const KeyValuePair& keyValuePair) {
            this->key = keyValuePair.key;
            this->value = keyValuePair.value;
          }
          
          /// @cond
          KeyValuePair& operator =(const KeyValuePair& keyValuePair) {
            this->key = keyValuePair.key;
            this->value = keyValuePair.value;
            return *this;
          }
          /// @endcond

          /// @brief Initializes a new instance of the KeyValuePair<TKey, TValue> class with the specified key && value.
          /// @param Key The object defined in each key/value pair
          /// @param value The definition associated with key
          KeyValuePair(const TKey& key, const TValue& value) {
            this->key = key;
            this->value = value;
          }

         /// @brief Gets the key in the key/value pair.
         /// @return TKey A TKey that is the key of the KeyValuePair<TKey, TValue>.
          Property<const TKey&, ReadOnly> Key {
            pcf_get->const TKey& {return this->key;}
          };

         /// @brief Gets the value in the key/value pair.
         /// @return TValue A TValue that is the value of the KeyValuePair<TKey, TValue>.
          Property<const TValue&, ReadOnly> Value {
            pcf_get->const TValue& {return this->value;}
          };

          /// @brief Returns a String representation of the KeyValuePair<TKey, TValue>, using the String representations of the key && value.
          /// @return const String A String representation of the KeyValuePair<TKey, TValue>, which includes the String representations of the key && value.
          /// @return String
          String ToString() const override {return String::Format("[{0}, {1}]", this->key, this->value);}

          bool Equals(const KeyValuePair& value) const {return this->value == value.value;}

          bool Equals(const Object& obj) const override {return is<KeyValuePair>(obj) && Equals(static_cast<const KeyValuePair&>(obj));}

        private:
          TKey key;
          TValue value;
        };
        
        template<>
        class KeyValuePair<void, void> : public object {
        public:
          template<typename TKey, typename TValue>
          static KeyValuePair<TKey, TValue> Create(TKey key, TValue value) {return KeyValuePair<TKey, TValue>(key, value);}
        };
      }
    }
  }
}

using namespace Pcf;
