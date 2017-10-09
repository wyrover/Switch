#if defined(__linux__)

#include <gtkmm.h>
#include "DrawingApi.hpp"

using namespace System;
using namespace Native;

Glib::RefPtr<Gtk::Application> __application__ = Gtk::Application::create();

namespace {
  System::Drawing::Color ToColor(const Gdk::RGBA& color) {
    return System::Drawing::Color::FromArgb(color.get_alpha() * 255, color.get_red() * 255, color.get_green() * 255, color.get_blue() * 255);
  }
}

int32 DrawingApi::SystemColors::GetActiveBorder() {
  return (int32)0xFFB4B4B4;
}

int32 DrawingApi::SystemColors::GetActiveCaption() {
  return (int32)0xFF99B4D1;
}

int32 DrawingApi::SystemColors::GetActiveCaptionText() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetAppWorkspace() {
  return (int32)0xFFABABAB;
}

int32 DrawingApi::SystemColors::GetButtonFace() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetButtonHighlight() {
  return (int32)0xFFFFFFFF;
}

int32 DrawingApi::SystemColors::GetButtonShadow() {
  return (int32)0xFFF0F0F0;
}

int32 DrawingApi::SystemColors::GetControl() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlDark() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlDarkDark() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlLight() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlLightLight() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetControlText() {
  //return ToColor(Gtk::Button().get_style_context()->get_color()).ToArgb();
  return ToColor(Gtk::Window().get_style_context()->get_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetDesktop() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetGradientActiveCaption() {
  return (int32)0xFF99B4D1;
}

int32 DrawingApi::SystemColors::GetGradientInactiveCaption() {
  return (int32)0xFF9DB9EB;
}

int32 DrawingApi::SystemColors::GetGrayText() {
  return (int32)0xFF6D6D6D;
}

int32 DrawingApi::SystemColors::GetHighlight() {
  return (int32)0xFF3399FF;
}

int32 DrawingApi::SystemColors::GetHighlightText() {
  return (int32)0xFFFFFFFF;
}

int32 DrawingApi::SystemColors::GetHotTrack() {
  return (int32)0xFF0066CC;
}

int32 DrawingApi::SystemColors::GetInactiveBorder() {
  return (int32)0xFFF4F7FC;
}

int32 DrawingApi::SystemColors::GetInactiveCaption() {
  return (int32)0xFFBFCDDB;
}

int32 DrawingApi::SystemColors::GetInactiveCaptionText() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetInfo() {
  return (int32)0xFFFFFFE1;
}

int32 DrawingApi::SystemColors::GetInfoText() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetMenu() {
  return (int32)0xFFF0F0F0;
}

int32 DrawingApi::SystemColors::GetMenuBar() {
  return (int32)0xFFF0F0F0;
}

int32 DrawingApi::SystemColors::GetMenuHighlight() {
  return (int32)0xFF3399FF;
}

int32 DrawingApi::SystemColors::GetMenuText() {
  return (int32)0xFF000000;
}

int32 DrawingApi::SystemColors::GetScrollBar() {
  return (int32)0xFFC8C8C8;
}

int32 DrawingApi::SystemColors::GetWindow() {
  return ToColor(Gtk::Window().get_style_context()->get_background_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetWindowFrame() {
  return ToColor(Gtk::Window().get_style_context()->get_border_color()).ToArgb();
}

int32 DrawingApi::SystemColors::GetWindowText() {
  return ToColor(Gtk::Window().get_style_context()->get_color()).ToArgb();
}

#endif
