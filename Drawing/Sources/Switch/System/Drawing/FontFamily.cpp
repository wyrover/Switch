#include <Switch/System/Collections/Generic/List.hpp>
#include "../../../../Includes/Switch/System/Drawing/FontFamily.hpp"
#include "../../../../Includes/Switch/System/Drawing/Text/InstalledFontCollection.hpp"
#include "../../../__OS/DrawingApi.hpp"

namespace {
  const string genericFontFamilySerifName = "Times New Roman";
  const string genericFontFamilySansSerifName = "Microsoft Sans Serif";
  const string genericFontFamilyMonospaceName = "Courier New";
}

System::Drawing::FontFamily::FontFamily(const string& name) {
  *this = __OS::DrawingApi::FontFamily::GetFontFamilyFromName(name);
}

System::Drawing::FontFamily::FontFamily(System::Drawing::Text::GenericFontFamilies genericFamily) {
  if (genericFamily == System::Drawing::Text::GenericFontFamilies::Serif)
    *this = System::Drawing::FontFamily(genericFontFamilySerifName);
  else if (genericFamily == System::Drawing::Text::GenericFontFamilies::SansSerif)
    *this = System::Drawing::FontFamily(genericFontFamilySansSerifName);
  else
    *this = System::Drawing::FontFamily(genericFontFamilyMonospaceName);
}

System::Drawing::FontFamily::~FontFamily() {
  if (this->data.IsUnique())
    __OS::DrawingApi::FontFamily::ReleaseResource(this->data().handle);
}

property<System::Array<System::Drawing::FontFamily>, readonly> System::Drawing::FontFamily::Families {
  [] {return System::Drawing::Text::InstalledFontCollection().Families();}
};

property<System::Drawing::FontFamily, readonly> System::Drawing::FontFamily::GenericMonospace {
  [] {return FontFamily(System::Drawing::Text::GenericFontFamilies::Monospace);}
};

property<System::Drawing::FontFamily, readonly> System::Drawing::FontFamily::GenericSansSerif {
  [] {return FontFamily(System::Drawing::Text::GenericFontFamilies::SansSerif);}
};

property<System::Drawing::FontFamily, readonly> System::Drawing::FontFamily::GenericSerif {
  [] {return FontFamily(System::Drawing::Text::GenericFontFamilies::Serif);}
};

string System::Drawing::FontFamily::GetName() const {
  return __OS::DrawingApi::FontFamily::GetName(this->data().handle);
}

bool System::Drawing::FontFamily::IsStyleAvailable(System::Drawing::FontStyle style) const {
  return __OS::DrawingApi::FontFamily::IsStyleAvailable(this->data().handle, style);
}
