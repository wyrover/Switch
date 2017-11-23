/// @file
/// @brief Contains Switch::System::Drawing::Imaging::ImageFormat class.
#pragma once

#include <Switch/System/Guid.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the System::Drawing namespace.
      namespace Imaging {
        class _export ImageFormat : public object {
        public:
          static _property<ImageFormat, _readonly> Bmp;
          
          static _property<ImageFormat, _readonly> Emf;
          
          static _property<ImageFormat, _readonly> Exif;
          
          static _property<ImageFormat, _readonly> Gif;
          
          static _property<ImageFormat, _readonly> Icon;
          
          static _property<ImageFormat, _readonly> Jpeg;
          
          static _property<ImageFormat, _readonly> MemoryBmp;
          
          static _property<ImageFormat, _readonly> Png;
          
          static  _property<ImageFormat, _readonly> Tiff;
          
          static _property<ImageFormat, _readonly> Wmf;
          
          ImageFormat() {}
          ImageFormat(const Guid& guid) : guid(guid) {}
          ImageFormat(const string name, const Guid& guid) : name(name), guid(guid) {}
          ImageFormat(const string name, const string& guid) : name(name), guid(guid) {}
          ImageFormat(const ImageFormat& format) : name(format.name), guid(format.guid) {}
          
          _property<System::Guid, _readonly> Guid {
            _get {return this->guid;}
          };
          
          _property<string, _readonly> Name {
            _get {return this->name;}
          };
          
        private:
          string name;
          System::Guid guid;
        };
      }
    }
  }
}
