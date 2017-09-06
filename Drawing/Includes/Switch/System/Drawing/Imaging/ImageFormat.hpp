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
        class _public ImageFormat : public object {
        public:
          static property<ImageFormat, readonly> Bmp;
          
          static property<ImageFormat, readonly> Emf;
          
          static property<ImageFormat, readonly> Exif;
          
          static property<ImageFormat, readonly> Gif;
          
          static property<ImageFormat, readonly> Icon;
          
          static property<ImageFormat, readonly> Jpeg;
          
          static property<ImageFormat, readonly> MemoryBmp;
          
          static property<ImageFormat, readonly> Png;
          
          static  property<ImageFormat, readonly> Tiff;
          
          static property<ImageFormat, readonly> Wmf;
          
          ImageFormat() {}
          ImageFormat(const Guid& guid) : guid(guid) {}
          ImageFormat(const string name, const Guid& guid) : name(name), guid(guid) {}
          ImageFormat(const string name, const string& guid) : name(name), guid(guid) {}
          ImageFormat(const ImageFormat& format) : name(format.name), guid(format.guid) {}
          
          property<System::Guid, readonly> Guid {
            _get {return this->guid;}
          };
          
          property<string, readonly> Name {
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
