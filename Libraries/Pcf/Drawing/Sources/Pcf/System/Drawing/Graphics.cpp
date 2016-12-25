#include <FL/Fltk.h>
#include "../../../../Includes/Pcf/System/Drawing/Graphics.h"
#include <Pcf/System/Tuple.h>

using namespace System;
using namespace System::Drawing;

void Graphics::Clear(const Color& color) {
  SetColor(color);
  fl_draw_box(FL_FLAT_BOX, 0, 0, System::Int32::MaxValue, System::Int32::MaxValue, fl_color());
}

void Graphics::DrawArc(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
  SetColor(pen.Color);
  
  int32 startX = this->offset.X()+x;
  int32 startY = this->offset.Y()+y;
  
  for (int32 i = 0; i < Convert::ToInt32(pen.Width()); i++)
    fl_arc(startX+i, startY+i, w-(2*i), h-(2*i), startAngle, startAngle + sweepAngle);
}

void Graphics::DrawBezier(const Pen& pen, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
  SetColor(pen.Color);
  
  double startX1 = (double)this->offset.X()+x1;
  double startY1 = (double)this->offset.Y()+y1;
  double startX2 = (double)this->offset.X()+x2;
  double startY2 = (double)this->offset.Y()+y2;
  double startX3 = (double)this->offset.X()+x3;
  double startY3 = (double)this->offset.Y()+y3;
  double startX4 = (double)this->offset.X()+x4;
  double startY4 = (double)this->offset.Y()+y4;
  
  for (int32 i = 0; i < Convert::ToInt32(pen.Width()); i++)
    fl_curve(startX1+i, startY1+i, startX2+i, startY2+i, startX3+i, startY3+i, startX4+i, startY4+i);
}

void Graphics::DrawFrame(FrameType type, int32 x, int32 y, int32 w, int32 h) {
  static System::Collections::Generic::SortedDictionary<FrameType, Fl_Boxtype> boxTypes {{FrameType::Up, FL_UP_FRAME}, {FrameType::Down, FL_DOWN_FRAME}, {FrameType::ThinUp, FL_THIN_UP_FRAME}, {FrameType::ThinDown, FL_THIN_DOWN_FRAME}, {FrameType::Engraved, FL_ENGRAVED_FRAME}, {FrameType::Embossed, FL_EMBOSSED_FRAME}, {FrameType::Border, FL_BORDER_FRAME}, {FrameType::Shadow, FL_SHADOW_FRAME}, {FrameType::Rounded, FL_ROUNDED_FRAME}, {FrameType::Oval, FL_OVAL_FRAME}, {FrameType::PlasticUp, FL_PLASTIC_UP_FRAME}, {FrameType::PlasticDown, FL_PLASTIC_DOWN_FRAME}, {FrameType::GtkUp, FL_GTK_UP_FRAME}, {FrameType::GtkDown, FL_GTK_DOWN_FRAME}, {FrameType::GtkThinUp, FL_GTK_THIN_UP_FRAME}, {FrameType::GtkThinDown, FL_GTK_THIN_DOWN_FRAME}};
  fl_draw_box(boxTypes[type], this->offset.X()+x, this->offset.Y()+y, w, h, fl_color());
}

void Graphics::DrawLine(const Pen& pen, int32 x1, int32 y1, int32 x2, int32 y2) {
  SetColor(pen.Color);
  for (int32 i = 0; i < Convert::ToInt32(pen.Width()); i++)
    fl_line(this->offset.X()+x1+i, this->offset.Y()+y1+i, this->offset.X()+x2+i, this->offset.Y()+y2+i);
}

void Graphics::DrawPie(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
  SetColor(pen.Color);
  
  int32 startX = this->offset.X()+x;
  int32 startY = this->offset.Y()+y;
  
  for (int32 i = 0; i < Convert::ToInt32(pen.Width()); i++)
    fl_arc(startX+i, startY+i, w-(2*i), h-(2*i), startAngle, startAngle + sweepAngle);
}

void Graphics::DrawRectangle(const Pen& pen, int32 x, int32 y, int32 w, int32 h) {
  SetColor(pen.Color);
  for (int32 i = 0; i < Convert::ToInt32(pen.Width()); i++)
    fl_rect(this->offset.X()+x+i, this->offset.Y()+y+i, w-(2*i), h-(2*i));
}

void Graphics::DrawString(const string& str, const Font& font, const Brush& brush, const RectangleF& layoutRectangle, const StringFormat& format) {
  if (!is<SolidBrush>(brush))
    throw NotSupportedException(pcf_current_information);
  Fl_Font oldFont = fl_font();
  int32 oldFontSize = Fl_Fontsize();
  fl_font((int32)font.ToHFont(), Convert::ToInt32(font.Size()));
  SizeF size = MeasureString(str, font);
  SetColor(as<SolidBrush>(brush).Color);
  float x = Convert::ToSingle(this->offset.X()) + layoutRectangle.X();
  float y = Convert::ToSingle(this->offset.Y()) + layoutRectangle.Y() - fl_descent() + fl_height();
  if (format.Alignment == StringAlignment::Center)
    x += (layoutRectangle.Width - layoutRectangle.X - size.Width) / 2;
  if (format.Alignment == StringAlignment::Far)
    x +=  layoutRectangle.Width - size.Width;
  if (format.LineAlignment == StringAlignment::Center)
    y += (layoutRectangle.Height - layoutRectangle.Y - size.Height) / 2;
  if (format.LineAlignment == StringAlignment::Far)
    y +=  layoutRectangle.Height - size.Height;
  fl_draw(str.Data(), Convert::ToInt32(x), Convert::ToInt32(y));
  fl_font(oldFont, oldFontSize);
}

void Graphics::FillBox(BoxType type, const Brush& brush, int32 x, int32 y, int32 w, int32 h) {
  static System::Collections::Generic::SortedDictionary<BoxType, Fl_Boxtype> boxTypes {{BoxType::Flat, FL_FLAT_BOX}, {BoxType::Up, FL_UP_BOX}, {BoxType::Down, FL_DOWN_BOX}, {BoxType::ThinUp, FL_THIN_UP_BOX}, {BoxType::ThinDown, FL_THIN_DOWN_BOX}, {BoxType::Engraved, FL_ENGRAVED_BOX}, {BoxType::Embossed, FL_EMBOSSED_BOX}, {BoxType::Border, FL_BORDER_BOX}, {BoxType::Shadow, FL_SHADOW_BOX}, {BoxType::Rounded, FL_ROUNDED_BOX}, {BoxType::RoundedFlat, FL_RFLAT_BOX}, {BoxType::RoundedShadow, FL_RSHADOW_BOX}, {BoxType::Oval, FL_OVAL_BOX}, {BoxType::OvalFlat, FL_OFLAT_BOX}, {BoxType::OvalShadow, FL_OSHADOW_BOX}, {BoxType::RoundUp, FL_ROUND_UP_BOX}, {BoxType::RoundDown, FL_ROUND_DOWN_BOX}, {BoxType::Diamond, FL_DIAMOND_BOX}, {BoxType::DiamondUp, FL_DIAMOND_UP_BOX}, {BoxType::DiamondDown, FL_DIAMOND_DOWN_BOX}, {BoxType::PlasticUp, FL_PLASTIC_UP_BOX}, {BoxType::PlasticDown, FL_PLASTIC_DOWN_BOX}, {BoxType::PlasticThinUp, FL_PLASTIC_THIN_UP_BOX}, {BoxType::PlasticThinDown, FL_PLASTIC_THIN_DOWN_BOX}, {BoxType::PlasticRoundUp, FL_PLASTIC_ROUND_UP_BOX}, {BoxType::PlasticRoundDown, FL_PLASTIC_ROUND_DOWN_BOX}, {BoxType::GtkUp, FL_GTK_UP_BOX}, {BoxType::GtkDown, FL_GTK_DOWN_BOX}, {BoxType::GtkThinUp, FL_GTK_THIN_UP_BOX}, {BoxType::GtkThinDown, FL_GTK_THIN_DOWN_BOX}, {BoxType::GtkRoundUp, FL_GTK_ROUND_UP_BOX}, {BoxType::GtkRoundDown, FL_GTK_ROUND_DOWN_BOX}};
  SetColor(as<SolidBrush>(brush).Color);
  fl_draw_box(boxTypes[type], this->offset.X()+x, this->offset.Y()+y, w, h, fl_color());
}

void Graphics::FillPie(const Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
  if (!is<SolidBrush>(brush))
    throw NotSupportedException(pcf_current_information);
  
  SetColor(as<SolidBrush>(brush).Color);
  fl_pie(this->offset.X()+x, this->offset.Y()+y, w, h, startAngle, startAngle + sweepAngle);
}

void Graphics::FillRectangle(const Brush& brush, int32 x, int32 y, int32 w, int32 h) {
  if (!is<SolidBrush>(brush))
    throw NotSupportedException(pcf_current_information);
  SetColor(as<SolidBrush>(brush).Color);
  fl_draw_box(FL_FLAT_BOX, this->offset.X()+x, this->offset.Y()+y, w, h, fl_color());
}

void Graphics::SetColor(const System::Drawing::Color& color) {
  fl_color(fl_rgb_color(static_cast<byte>(color.R()), static_cast<byte>(color.G()), static_cast<byte>(color.B())));
}

SizeF Graphics::MeasureString(const string& str, const Font& font) const {
  Fl_Font fontOld = fl_font();
  Fl_Fontsize fontSizeOld = fl_size();

  fl_font((int32)font.ToHFont(), Convert::ToInt32(font.Size()));
  int32 width = 0;
  int32 height = 0;
  fl_measure(str.Data(), width, height);
  fl_font(fontOld, fontSizeOld);
  return SizeF(width+10, (float)height);
}
