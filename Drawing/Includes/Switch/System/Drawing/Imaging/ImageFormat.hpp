/// @file
/// @brief Contains Switch::System::Drawing::Imaging::ImageFormat class.
#pragma once

#include <Switch/System/Guid.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the System::Drawing namespace.
      namespace Imaging {
        class pcf_public ImageFormat : public object {
        public:
          static Property<ImageFormat, ReadOnly> Bmp;
          
          static Property<ImageFormat, ReadOnly> Emf;
          
          static Property<ImageFormat, ReadOnly> Exif;
          
          static Property<ImageFormat, ReadOnly> Gif;
          
          static Property<ImageFormat, ReadOnly> Icon;
          
          static Property<ImageFormat, ReadOnly> Jpeg;
          
          static Property<ImageFormat, ReadOnly> MemoryBmp;
          
          static Property<ImageFormat, ReadOnly> Png;
          
          static  Property<ImageFormat, ReadOnly> Tiff;
          
          static Property<ImageFormat, ReadOnly> Wmf;
          
          ImageFormat() {}
          ImageFormat(const Guid& guid) : guid(guid) {}
          ImageFormat(const string name, const Guid& guid) : name(name), guid(guid) {}
          ImageFormat(const string name, const string& guid) : name(name), guid(guid) {}
          ImageFormat(const ImageFormat& format) : name(format.name), guid(format.guid) {}
          
          Property<System::Guid, ReadOnly> Guid {
            pcf_get {return this->guid;}
          };
          
          Property<string, ReadOnly> Name {
            pcf_get {return this->name;}
          };

       private:
          string name;
          System::Guid guid;
        };
      }
    }
  }
}
