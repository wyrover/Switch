#include "../../../../../Includes/Switch/System/Drawing/Imaging/ImageFormat.hpp"

using namespace System::Drawing::Imaging;

property<ImageFormat, readonly> ImageFormat::Bmp {
  [] {return ImageFormat("Bmp", "b96b3cab-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::Emf{
  [] {return ImageFormat("Emf", "b96b3cac-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::Exif {
  [] {return ImageFormat("Exif", "b96b3cb2-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::Gif {
  [] {return ImageFormat("Gif", "b96b3cb0-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::Icon {
  [] {return ImageFormat("Icon", "b96b3cb5-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::Jpeg {
  [] {return ImageFormat("Jpeg", "b96b3cae-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::MemoryBmp {
  [] {return ImageFormat("MemoryBmp", "b96b3caa-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::Png {
  [] {return ImageFormat("Png", "b96b3caf-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::Tiff {
  [] {return ImageFormat("Tiff", "b96b3cb1-0728-11d3-9d7b-0000f81ef32e");}
};

property<ImageFormat, readonly> ImageFormat::Wmf {
  [] {return ImageFormat("Wmf", "b96b3cad-0728-11d3-9d7b-0000f81ef32e");}
};

