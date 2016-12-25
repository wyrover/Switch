#include <FL/Fltk.h>
#include "../../../../Includes/Pcf/System/Drawing/Font.h"
#include <Pcf/System/Tuple.h>

using namespace System;

System::Drawing::Font System::Drawing::Font::FromHFont(intptr hfont) {
  System::Drawing::Font font;
  font.name = Fl::get_font_name((Fl_Font)hfont, (int*)&font.style);
  return font;
}

void System::Drawing::Font::FromName(const string& name, float size, System::Drawing::FontStyle style) {
  using TupleNameHFont = Pcf::System::Tuple<string, int32, int32>;
  static UniquePointer<Pcf::System::Collections::Generic::List<TupleNameHFont>> list;
  
  if (list.IsNull()) {
    list = new Pcf::System::Collections::Generic::List<TupleNameHFont>();
    int32 count = Fl::set_fonts();
    int32 attribute = 0;
    for (int32 i = 0; i < count; i++)
      list->Add(TupleNameHFont(string(Fl::get_font_name((Fl_Font)i, &attribute)).ToLower(), i, attribute));
    list->Sort();
  }
  
  string nameToFind = name.ToLower();
  
  int32 index = list->BinarySearch(TupleNameHFont(nameToFind, 0, 0));
  if (index < 0)
    index = ~index;
  this->hfont = (*list)[index].Item2();
  //string nameFound = (*list)[index].GetItem1();
  
  if ((style & System::Drawing::FontStyle::Bold) == System::Drawing::FontStyle::Bold)
    nameToFind += " bold";
  
  if ((style & System::Drawing::FontStyle::Italic) == System::Drawing::FontStyle::Italic)
    nameToFind += " italic";
  
  index = list->BinarySearch(TupleNameHFont(nameToFind, 0, 0));
  if (index < 0)
    index = ~index;
  if ((*list)[index].Item1().StartsWith(name.ToLower())) {
    this->hfont = (*list)[index].Item2();
    //nameFound = (*list)[index].Item1();
  }
  
  this->name = Fl::get_font_name((Fl_Font)this->hfont, (int32*)&this->style);
  this->name = this->name.Replace(" bold", "").Replace(" Bold", "").Replace(" italic", "").Replace(" Italic", "");
  this->size = size;
  
  //System::Console::WriteLine("Name         = [{0}]", name);
  //System::Console::WriteLine("Name to find = [{0}]", nameToFind);
  //System::Console::WriteLine("Name found   = [{0}]", nameFound);
  //System::Console::WriteLine("[Font: Name=[{0}, Size={1}, style={2}]\n", this->name, this->size, this->style);
}
