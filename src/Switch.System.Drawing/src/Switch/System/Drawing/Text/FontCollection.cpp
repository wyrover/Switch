#include "../../../../../include/Switch/System/Drawing/Text/FontCollection.hpp"
#include "../../../../Native/DrawingApi.hpp"

System::Drawing::Text::FontCollection::FontCollection() : families(Native::DrawingApi::FontFamily::GetInstalledFontFamilies()) {
}
