#include <Pcf/System/Object.hpp>
#include <Pcf/System/IO//BinaryReader.hpp>

#include "../../../../Includes/Pcf/System/Drawing/Image.hpp"
#include "../../../../Includes/Pcf/System/Drawing/Imaging/FrameDimension.hpp"

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
