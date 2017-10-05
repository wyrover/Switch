#include "../../../../../include/Switch/System/Drawing/Text/FontCollection.hpp"
#include "../../../../__OS/DrawingApi.hpp"

System::Drawing::Text::FontCollection::FontCollection() : families(__OS::DrawingApi::FontFamily::GetInstalledFontFamilies()) {
}
