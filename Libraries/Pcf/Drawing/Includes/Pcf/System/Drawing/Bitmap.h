/// @file
/// @brief Contains Pcf::System::Drawing::Bitmap class.
#pragma once

#include <Pcf/SharedPointer.h>
#include <Pcf/System/String.h>
#include <Pcf/System/IO/Stream.h>

#include "Image.h"

namespace Pcf {
  namespace System {
    namespace Drawing {
      /// @brief An abstract base class that provides functionality for the System::Drawing::Bitmap and System::Drawing::Imaging::Metafile descended classes.
      /// @remarks To draw an System::Drawing::Image on a Windows Form, you should use one of the Graphics::DrawImage(Image, Point) methods.
      class Bitmap : public Image {
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
