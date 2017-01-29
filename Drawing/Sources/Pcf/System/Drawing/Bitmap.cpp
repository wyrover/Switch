#include "../../../../Includes/Pcf/System/Drawing/Bitmap.h"
#include "../../../../Includes/Pcf/System/Drawing/Imaging/FrameDimension.h"

using namespace System;
using namespace System::Drawing;
using namespace System::IO;

Bitmap::Bitmap(System::IO::Stream& stream) : Image(stream) {
}

Bitmap::Bitmap(const string& fileName) : Image(fileName) {
}
