#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/RichTextBox.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

namespace {
  using WidgetRichTextBox = Fltk::Widget<Fl_Text_Editor>;
}

RichTextBox::RichTextBox() {
  this->Register(UniquePointer<IWidget>::Create<WidgetRichTextBox>(0, 0, 100, 96, ""));
  this->text = new Fl_Text_Buffer();
  WidgetRichTextBox::ToWidget(this->widget()).buffer(WidgetRichTextBox::ToText(this->text));
  this->widget().Callback += pcf_delegate(const object& sender, const EventArgs& e) {
    this->OnTextChanged(e);
  };
  this->BackColor = SystemColors::Window;
  this->ForeColor = SystemColors::WindowText;
#if __APPLE__
  WidgetRichTextBox::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(Color::FromArgb(100, 163, 205, 255)));
#else
  WidgetRichTextBox::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Highlight));
#endif
  WidgetRichTextBox::ToWidget(this->widget()).when(FL_WHEN_CHANGED);
  this->HandleCreated(*this, EventArgs());
}

RichTextBox::~RichTextBox() {
  this->Unregister();
  delete reinterpret_cast<Fl_Text_Buffer*>(this->text);
  this->HandleDestroyed(*this, EventArgs());
}

void RichTextBox::SetBackColor(const System::Drawing::Color& color) {
  if (this->BackColor != color) {
    this->transparent = color == System::Drawing::Color::Transparent;
    this->Control::SetBackColor(color);
    this->SetBorderStyle(this->BorderStyle);
  }
}

void RichTextBox::SetFont(const System::Drawing::Font& font) {
  if (this->font != font) {
    this->font = font;
    WidgetRichTextBox::ToWidget(this->widget()).textfont((int32)this->font.ToHFont());
    WidgetRichTextBox::ToWidget(this->widget()).textsize(this->font.Size());
    
    this->FontChanged(*this, EventArgs());
  }
}

System::Windows::FormsD::BorderStyle RichTextBox::GetBorderStyle() const {
  switch (WidgetRichTextBox::ToWidget(this->widget()).box()) {
    case FL_NO_BOX: return System::Windows::FormsD::BorderStyle::None; break;
    case FL_FLAT_BOX: return System::Windows::FormsD::BorderStyle::None; break;
    case FL_BORDER_BOX: return System::Windows::FormsD::BorderStyle::FixedSingle; break;
    case FL_BORDER_FRAME: return System::Windows::FormsD::BorderStyle::FixedSingle; break;
    case FL_DOWN_BOX: return System::Windows::FormsD::BorderStyle::Fixed3D; break;
    case FL_DOWN_FRAME: return System::Windows::FormsD::BorderStyle::Fixed3D; break;
    default: return System::Windows::FormsD::BorderStyle::None;
  }
}

void RichTextBox::SetBorderStyle(Pcf::System::Windows::FormsD::BorderStyle borderStyle) {
  switch (borderStyle) {
    case System::Windows::FormsD::BorderStyle::None: WidgetRichTextBox::ToWidget(this->widget()).box(this->transparent ? FL_NO_BOX : FL_FLAT_BOX); break;
    case System::Windows::FormsD::BorderStyle::FixedSingle: WidgetRichTextBox::ToWidget(this->widget()).box(this->transparent ? FL_BORDER_FRAME : FL_BORDER_BOX); break;
    case System::Windows::FormsD::BorderStyle::Fixed3D: WidgetRichTextBox::ToWidget(this->widget()).box(this->transparent ? FL_DOWN_FRAME : FL_DOWN_BOX); break;
  }
}

bool RichTextBox::GetReadOnly() const {
  return ! WidgetRichTextBox::ToWidget(this->widget()).active();
}

void RichTextBox::SetReadOnly(bool readOnly) {
  if (readOnly)
    WidgetRichTextBox::ToWidget(this->widget()).activate();
  else
    WidgetRichTextBox::ToWidget(this->widget()).deactivate();
}

string RichTextBox::GetText() const {
  return WidgetRichTextBox::ToText(this->text).text();
}

void RichTextBox::SetText(const string& text) {
  WidgetRichTextBox::ToText(this->text).remove(0, WidgetRichTextBox::ToText(this->text).length());
  WidgetRichTextBox::ToText(this->text).append(text.Data());
  this->OnTextChanged(EventArgs());
}
