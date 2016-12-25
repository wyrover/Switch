#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/TextBox.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
  using WidgetTextBox = Fltk::Widget<Fl_Input>;
}

TextBox::TextBox() {
  this->Register(UniquePointer<IWidget>::Create<WidgetTextBox>(0, 0, 100, 25, ""));
  this->widget().Callback += pcf_delegate(const object& sender, const EventArgs& e) {
    this->OnTextChanged(e);
  };
  this->BackColor = SystemColors::Window;
  this->ForeColor = SystemColors::WindowText;
#if __APPLE__
  WidgetTextBox::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(Color::FromArgb(100, 163, 205, 255)));
#else
  WidgetTextBox::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Highlight));
#endif
  WidgetTextBox::ToWidget(this->widget()).when(FL_WHEN_CHANGED);
  this->HandleCreated(*this, EventArgs());
}

TextBox::~TextBox() {
  this->Unregister();
  this->HandleDestroyed(*this, EventArgs());
}

void TextBox::SetBackColor(const System::Drawing::Color& color) {
  if (this->BackColor != color) {
    this->transparent = color == System::Drawing::Color::Transparent;
    this->Control::SetBackColor(color);
    this->SetBorderStyle(this->BorderStyle);
  }
}

System::Windows::Forms::BorderStyle TextBox::GetBorderStyle() const {
  switch (WidgetTextBox::ToWidget(this->widget()).box()) {
    case FL_NO_BOX: return System::Windows::Forms::BorderStyle::None; break;
    case FL_FLAT_BOX: return System::Windows::Forms::BorderStyle::None; break;
    case FL_BORDER_BOX: return System::Windows::Forms::BorderStyle::FixedSingle; break;
    case FL_BORDER_FRAME: return System::Windows::Forms::BorderStyle::FixedSingle; break;
    case FL_DOWN_BOX: return System::Windows::Forms::BorderStyle::Fixed3D; break;
    case FL_DOWN_FRAME: return System::Windows::Forms::BorderStyle::Fixed3D; break;
    default: return System::Windows::Forms::BorderStyle::None;
  }
}

void TextBox::SetBorderStyle(Pcf::System::Windows::Forms::BorderStyle borderStyle) {
  switch (borderStyle) {
    case System::Windows::Forms::BorderStyle::None: WidgetTextBox::ToWidget(this->widget()).box(this->transparent ? FL_NO_BOX : FL_FLAT_BOX); break;
    case System::Windows::Forms::BorderStyle::FixedSingle: WidgetTextBox::ToWidget(this->widget()).box(this->transparent ? FL_BORDER_FRAME : FL_BORDER_BOX); break;
    case System::Windows::Forms::BorderStyle::Fixed3D: WidgetTextBox::ToWidget(this->widget()).box(this->transparent ? FL_DOWN_FRAME : FL_DOWN_BOX); break;
  }
}

void TextBox::SetFont(const System::Drawing::Font& font) {
  Control::SetFont(font);
  WidgetTextBox::ToWidget(this->widget()).textfont((int32)this->font.ToHFont());
  WidgetTextBox::ToWidget(this->widget()).textsize(this->font.Size);
}

bool TextBox::GetReadOnly() const {
  return WidgetTextBox::ToWidget(this->widget()).readonly() != 0;
}

void TextBox::SetReadOnly(bool readOnly) {
  WidgetTextBox::ToWidget(this->widget()).readonly(readOnly);
}

bool TextBox::GetUseSystemPasswordChar() const {
  return WidgetTextBox::ToWidget(this->widget()).type() != FL_SECRET_INPUT;
}

void TextBox::SetUseSystemPasswordChar(bool useSystemPasswordChar) {
  if (useSystemPasswordChar)
    WidgetTextBox::ToWidget(this->widget()).type(FL_SECRET_INPUT);
  else
    WidgetTextBox::ToWidget(this->widget()).type(FL_NORMAL_INPUT);
}

string TextBox::GetText() const {
  return WidgetTextBox::ToWidget(this->widget()).value();
}

void TextBox::SetText(const string& text) {
  WidgetTextBox::ToWidget(this->widget()).value(text.Data());
  this->OnTextChanged(EventArgs());
}

