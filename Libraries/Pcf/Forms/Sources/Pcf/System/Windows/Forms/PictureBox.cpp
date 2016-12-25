#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/PictureBox.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
  using WidgetPictureBox = Fltk::Widget<Fl_Box>;
}

PictureBox::PictureBox() {
  this->Register(UniquePointer<IWidget>::Create<WidgetPictureBox>(0, 0, 100, 50, ""));
  this->HandleCreated(*this, EventArgs());
  WidgetPictureBox::ToWidget(this->widget()).align(FL_ALIGN_IMAGE_BACKDROP);
}

PictureBox::~PictureBox() {
  this->Unregister();
  if (this->handle != null)
    delete (Fl_Image*)this->handle;
}

System::Windows::Forms::BorderStyle PictureBox::GetBorderStyle() const {
  switch (WidgetPictureBox::ToWidget(this->widget()).box()) {
    case FL_NO_BOX: return System::Windows::Forms::BorderStyle::None; break;
    case FL_FLAT_BOX: return System::Windows::Forms::BorderStyle::None; break;
    case FL_BORDER_BOX: return System::Windows::Forms::BorderStyle::FixedSingle; break;
    case FL_BORDER_FRAME: return System::Windows::Forms::BorderStyle::FixedSingle; break;
    case FL_DOWN_BOX: return System::Windows::Forms::BorderStyle::Fixed3D; break;
    case FL_DOWN_FRAME: return System::Windows::Forms::BorderStyle::Fixed3D; break;
    default: return System::Windows::Forms::BorderStyle::None;
  }
}

void PictureBox::SetBorderStyle(Pcf::System::Windows::Forms::BorderStyle borderStyle) {
  switch (borderStyle) {
    case System::Windows::Forms::BorderStyle::None: WidgetPictureBox::ToWidget(this->widget()).box(this->transparent ? FL_NO_BOX : FL_FLAT_BOX); break;
    case System::Windows::Forms::BorderStyle::FixedSingle: WidgetPictureBox::ToWidget(this->widget()).box(this->transparent ? FL_BORDER_FRAME : FL_BORDER_BOX); break;
    case System::Windows::Forms::BorderStyle::Fixed3D: WidgetPictureBox::ToWidget(this->widget()).box(this->transparent ? FL_DOWN_FRAME : FL_DOWN_BOX); break;
  }
}

void PictureBox::SetImage(const System::Drawing::Image& image) {
  this->image = image;
  if (this->handle != null)
    delete (Fl_Image*)this->handle;
  this->handle = new Fl_RGB_Image(this->image.Data(), this->image.Width(), this->image.Height(), this->image.PixelFormat() == System::Drawing::Imaging::PixelFormat::Format32bppRgb ? 4 : 3);
  WidgetPictureBox::ToWidget(this->widget()).image((Fl_Image*)this->handle);
  WidgetPictureBox::ToWidget(this->widget()).redraw();
}
