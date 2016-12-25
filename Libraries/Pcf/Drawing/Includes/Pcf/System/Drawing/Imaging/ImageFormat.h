/// @file
/// @brief Contains Pcf::System::Drawing::Imaging::ImageFormat class.
#pragma once

#include <Pcf/System/Guid.h>
#include <Pcf/System/Object.h>
#include <Pcf/System/String.h>

namespace Pcf {
  namespace System {
    namespace Drawing {
      namespace Imaging {
        class ImageFormat : public object {
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
