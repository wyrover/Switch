#include <Pcf/System/Object.hpp>
#include <Pcf/System/IO//BinaryReader.hpp>

#include "../../../../Includes/Pcf/System/Drawing/Image.hpp"
#include "../../../../Includes/Pcf/System/Drawing/Imaging/FrameDimension.hpp"

namespace Pcf {
  namespace System {
    namespace Drawing {
      class Gif : public object {
      public:
        template<typename TStream>
        Gif(const TStream& stream) : reader(stream) {}
        
        Gif(refptr<System::IO::Stream> stream) : reader(stream) {}
        
        void Read(Image& image) {
        }

      private:
        System::IO::BinaryReader reader;
      };
    }
  }
}
