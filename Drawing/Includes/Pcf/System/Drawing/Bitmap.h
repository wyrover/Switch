/// @file
/// @brief Contains Pcf::System::Drawing::Bitmap class.
#pragma once

#include <Pcf/SharedPointer.h>
#include <Pcf/System/String.h>
#include <Pcf/System/IO/Stream.h>

#include "Image.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief An abstract base class that provides functionality for the System::Drawing::Bitmap and System::Drawing::Imaging::Metafile descended classes.
      /// @remarks To draw an System::Drawing::Image on a Windows Form, you should use one of the Graphics::DrawImage(Image, Point) methods.
      class pcf_public Bitmap : public Image {
      public:
        Bitmap(const Image& image) : Image(image) {}

        Bitmap(const string & fileName);

        Bitmap(System::IO::Stream& stream);

      private:
        Bitmap() {}
      };
    }
  }
}
