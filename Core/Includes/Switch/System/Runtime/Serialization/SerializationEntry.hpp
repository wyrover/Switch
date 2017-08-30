/// @file
/// @brief Contains Switch::System::Runtime::Serialization::SerializationEntry class.
#pragma once

#include "../../../Types.hpp"
#include "../../../RefPtr.hpp"
#include "../../Object.hpp"
#include "../../String.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Runtime namespaces contain types that support an application's interaction with the common language runtime, and types that enable features such as application data caching, advanced exception handling, application activation within application domains, COM interop, distributed applications, serialization and deserialization, and versioning.
    namespace Runtime {
      /// @brief The System::Runtime::Serialization namespace contains classes that can be used for serializing and deserializing objects. Serialization is the process of converting an object or a graph of objects into a linear sequence of bytes for either storage or transmission to another location. Deserialization is the process of taking in stored information and recreating objects from it.
      /// The ISerializable interface provides a way for classes to control their own serialization behavior. Classes in the System::Runtime::Serialization::Formatters namespace control the actual formatting of various data types encapsulated in the serialized objects.
      /// Formatters that serialize and deserialize objects to and from a particular format can be found in the System::Runtime::Serialization::Formatters namespace.
      namespace Serialization {
        /// @brief Holds the value, Type, and name of a serialized object.
        class sw_public SerializationEntry : public Object {
        public:
          /// @brief Gets the value contained in the object.
          /// @param value The value contained in the object.
          Property<refptr<Object>> Value {
            sw_get {return this->value;},
            sw_set {this->value = value;}
          };
          
          /// @brief Gets the value contained in the object.
          /// @param vlue The value contained in the object.
          Property<const String&> TypeName {
            sw_get->const String& {return this->typeName;},
            sw_set {this->typeName = value;}
          };
          
          SerializationEntry() {}
          SerializationEntry(const SerializationEntry& entry) : value(entry.value), typeName(entry.typeName) {}
          
          /// @cond
          SerializationEntry& operator =(const SerializationEntry& entry) {
            this->value = entry.value;
            this->typeName = entry.typeName;
            return *this;
          }
          /// @endocnd
          
        protected:
          /// @brief Initializes a new instance of the SerializationEntry
          SerializationEntry(const refptr<Object>& value, const String& typeName) : value(value), typeName(typeName) {}
          
        private:
          friend class SerializationInfo;
          refptr<Object> value;
          String typeName;
        };
      }
    }
  }
}

using namespace Switch;
