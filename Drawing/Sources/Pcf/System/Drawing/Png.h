#include <zlib.h>
#include <png.h>
#include <Pcf/System/Object.h>
#include <Pcf/UniquePointer.h>
#include <Pcf/System/IO//BinaryReader.h>

#include "../../../../Includes/Pcf/System/Drawing/Image.h"
#include "../../../../Includes/Pcf/System/Drawing/Imaging/FrameDimension.h"

struct PngMemory {
  png_structp pp;
  const unsigned char *current;
  const unsigned char *last;
};

extern "C" {
  static void PngReadDataFromMem(png_structp png_ptr, png_bytep data, png_size_t length) {
    struct PngMemory *png_mem_data = (PngMemory*)png_get_io_ptr(png_ptr);
    if (png_mem_data->current + length > png_mem_data->last) {
      png_error(png_mem_data->pp, "Invalid attempt to read row data");
      return;
    }
    memcpy(data, png_mem_data->current, length);
    png_mem_data->current += length;
  }
} // extern "C"

namespace Pcf {
  namespace System {
    namespace Drawing {
      class Png : public object {
      public:
        Png(System::IO::Stream& stream) {this->reader = new System::IO::BinaryReader(stream);}

        void Read(Image& image) {
          png_infop info = null;
          png_structp pp = png_create_read_struct(PNG_LIBPNG_VER_STRING, null, null, null);
          if (pp)
            info = png_create_info_struct(pp);
          if (!pp || !info) {
            if (pp)
              png_destroy_read_struct(&pp, null, null);
            throw OutOfMemoryException(pcf_current_information);
          }
          if (setjmp(png_jmpbuf(pp))) {
            png_destroy_read_struct(&pp, &info, null);
            throw OutOfMemoryException(pcf_current_information);
          }

          Array<byte> streamData((int32)reader->BaseStream().Length());
          reader->Read(streamData, 0, static_cast<int32>(reader->BaseStream().Length()));

          PngMemory png_mem_data;
          png_mem_data.current = streamData.Data();
          png_mem_data.last = streamData.Data() + reader->BaseStream().Length();
          png_mem_data.pp = pp;
          png_set_read_fn (pp, (png_voidp) &png_mem_data, PngReadDataFromMem);

          png_read_info(pp, info);

          if (png_get_color_type(pp, info) == PNG_COLOR_TYPE_PALETTE)
            png_set_expand(pp);

          image.size.Width((int)(png_get_image_width(pp, info)));
          image.size.Height((int)(png_get_image_height(pp, info)));

          switch (png_get_bit_depth(pp, info)) {
            case 8: image.pixelFormat = Imaging::PixelFormat::Format8bppIndexed; break;
            case 16: image.pixelFormat = Imaging::PixelFormat::Format16bppRgb555; break;
            case 24: image.pixelFormat = Imaging::PixelFormat::Format24bppRgb; break;
            case 32: image.pixelFormat = Imaging::PixelFormat::Format32bppRgb; break;
            default: image.pixelFormat = Imaging::PixelFormat::Undefined; break;
          }

          if (png_get_bit_depth(pp, info) < 8)
          {
            png_set_packing(pp);
            png_set_expand(pp);
          }
          else if (png_get_bit_depth(pp, info) == 16)
            png_set_strip_16(pp);

          if (png_get_valid(pp, info, PNG_INFO_tRNS))
            png_set_tRNS_to_alpha(pp);

          UniquePointer<byte[]> rawData = new byte[image.size.Width() * image.size.Height() * (image.pixelFormat == Imaging::PixelFormat::Format32bppRgb ? 4 : 3)];
          UniquePointer<png_bytep[]> rows = new png_bytep[image.size.Height()];

          for (int32 i = 0; i < image.size.Height(); i ++)
            rows[i] = (png_bytep)(rawData.ToPointer() + i * image.size.Width() * (image.pixelFormat == Imaging::PixelFormat::Format32bppRgb ? 4 : 3));

          for (int32 i = png_set_interlace_handling(pp); i > 0; i --)
            png_read_rows(pp, rows.ToPointer(), null, image.size.Height());

#ifdef WIN32
          if (image.pixelFormat == Imaging::PixelFormat::Format32bppRgb) {
            byte* ptr = rawData.ToPointer();
            for (int32 i = image.size.Width() * image.size.Height(); i > 0; i --) {
              if (!ptr[3])
                ptr[0] = ptr[1] = ptr[2] = 0;
              ptr += 4;
            }
          }
#endif // WIN32

          png_read_end(pp, info);
          png_destroy_read_struct(&pp, &info, null);

          image.rawData = Array<byte>(rawData.Release(), image.size.Width() * image.size.Height() * (image.PixelFormat() == System::Drawing::Imaging::PixelFormat::Format32bppRgb ? 4 : 3));
        }

      private:
        UniquePointer<System::IO::BinaryReader> reader;
      };
    }
  }
}
