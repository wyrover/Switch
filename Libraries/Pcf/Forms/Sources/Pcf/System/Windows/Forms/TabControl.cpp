#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/TabControl.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
#if __APPLE__  //&& __YFI__
  using WidgetTabControl = Fltk::Widget<Fl_Gel_Tabs>;
#else
  using WidgetTabControl = Fltk::Widget<Fl_Tabs>;
#endif
}

TabControl::TabControl() {
  this->Register(UniquePointer<IWidget>::Create<WidgetTabControl>(0, 0, 200, 100, ""));
  WidgetTabControl::ToWidget(this->widget()).end();
  WidgetTabControl::ToWidget(this->widget()).resizable(null);
  this->HandleCreated(*this, EventArgs());
#if __APPLE__
  WidgetTabControl::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::ControlLight));
#elif __linux__
  WidgetTabControl::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Control));
#else
  WidgetTabControl::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::ControlLightLight));
#endif
}

TabControl::~TabControl() {
  this->Unregister();  
  this->HandleDestroyed(*this, EventArgs());
}
