#include "../../../../../Includes/Pcf/System/Drawing/Text/FontCollection.h"
#include "../../../../__OS/DrawingApi.h"

System::Drawing::Text::FontCollection::FontCollection() : families(__OS::DrawingApi::FontFamily::GetInstalledFontFamilies()) {
}
