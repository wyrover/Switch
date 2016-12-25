#include <FL/Fltk.h>
#include "../../../../Includes/Pcf/System/Drawing/FontFamily.h"

using namespace System;
using namespace System::Drawing;

Property<Array<FontFamily>, ReadOnly> FontFamily::Families {
  [] {return __Families__();}
};

const Property<FontFamily, ReadOnly> FontFamily::GenericMonospace {
  [] {return FontFamily("Courier New");}
};

const Property<FontFamily, ReadOnly> FontFamily::GenericSansSerif {
  [] {return FontFamily("Arial");}
};

const Property<FontFamily, ReadOnly> FontFamily::GenericSerif {
  [] {return FontFamily("Georgia");}
};

Array<FontFamily> FontFamily::__Families__() {
  static UniquePointer<Pcf::System::Array<FontFamily>> families;

  if(families.IsNull()) {
    int32 count = Fl::set_fonts();
    System::Collections::Generic::SortedDictionary<string, int32> familyNames;
    string name;
    FontStyle style = FontStyle::Regular;
    for(int32 i = 0; i < count; i++) {
      name = Fl::get_font_name((Fl_Font)i, (int*)&style);

      if(name.StartsWith("@"))
        continue;
      if(style != FontStyle::Regular) {
        if(name.EndsWith(" Italic"))
          name = name.Replace(" Italic", "");
        if(name.EndsWith(" italic"))
          name = name.Replace(" italic", "");
        if(name.EndsWith(" Bold"))
          name = name.Replace(" Bold", "");
        if(name.EndsWith(" bold"))
          name = name.Replace(" bold", "");
      }
      if(!familyNames.ContainsKey(name))
        familyNames[name] = (int32)FontStyle::Regular;
      if(style != FontStyle(0))
        familyNames[name] = familyNames[name] | int32(style);
    }
    families = new Pcf::System::Array<FontFamily>(familyNames.Count());
    count = 0;
    for(auto kvp : familyNames) {
      (*families)[count].name = kvp.Key();
      (*families)[count].id = count;
      (*families)[count].style = (FontStyle)kvp.Value();
      count++;
    }
  }

  return *families;
}
