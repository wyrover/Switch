#include <Pcf/System/Object.h>
#include <Pcf/UniquePointer.h>
#include <Pcf/System/IO//BinaryReader.h>

#include "../../../../Includes/Pcf/System/Drawing/Image.h"
#include "../../../../Includes/Pcf/System/Drawing/Imaging/FrameDimension.h"

namespace Pcf {
  namespace System {
    namespace Drawing {
      class Gif : public object {
      public:
        Gif(System::IO::Stream& stream) : reader(stream) {}

        void Read(Image& image) {
        }

      private:
        System::IO::BinaryReader reader;
      };
    }
  }
}
