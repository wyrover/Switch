#include <Pcf/System/Object.h>
#include <Pcf/System/IO//BinaryReader.h>

#include "../../../../Includes/Pcf/System/Drawing/Image.h"
#include "../../../../Includes/Pcf/System/Drawing/Imaging/FrameDimension.h"

namespace Pcf {
  namespace System {
    namespace Drawing {
      class Tif : public object {
      public:
        template<typename TStream>
        Tif(const TStream& stream) : reader(stream) {}
        
        Tif(refptr<System::IO::Stream> stream) : reader(stream) {}

        void Read(Image& image) {
        }

      private:
        System::IO::BinaryReader reader;
      };
    }
  }
}
