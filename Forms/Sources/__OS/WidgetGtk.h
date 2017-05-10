#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/fixed.h>
#include <gtkmm/widget.h>

#include "FormsApi.h"

namespace __OS {
  class IWidget pcf_interface {
  public:
    virtual const Gtk::Widget& ToWidget() const = 0;
    virtual Gtk::Widget& ToWidget() = 0;
  };

  class Widget : public IWidget {
  public:
    virtual const Gtk::Container& Container() const {return as<Gtk::Container>(this->ToWidget());}
    
    virtual Gtk::Container& Container() {return as<Gtk::Container>(this->ToWidget());}
    
    virtual void BackColor(const System::Drawing::Color& color) {this->ToWidget().override_background_color(FromColor(color));}
    
    virtual void ForeColor(const System::Drawing::Color& color) {this->ToWidget().override_color(FromColor(color));}

    static Gdk::RGBA FromColor(const System::Drawing::Color& color) {
      Gdk::RGBA result;
      result.set_rgba(as<double>(color.R()) / 255, as<double>(color.G()) / 255, as<double>(color.B()) / 255, as<double>(color.A()) / 255);
      return result;
    }
    
    virtual void Move(int32 x, int32 y) {
      if (is<Gtk::Fixed>(this->ToWidget().get_parent())) {
        as<Gtk::Fixed>(this->ToWidget().get_parent())->child_property_x(this->ToWidget()) = x;
        as<Gtk::Fixed>(this->ToWidget().get_parent())->child_property_y(this->ToWidget()) = y;
      }
    }
    
    virtual void Show() {return this->ToWidget().show();}

    virtual void Text(const string& text) = 0;
    
    static System::Drawing::Color ToColor(const Gdk::RGBA& color) {
      System::Drawing::Color result = System::Drawing::Color::FromArgb(color.get_alpha() * 255, color.get_red() * 255, color.get_green() * 255, color.get_blue() * 255);
      return result;
    }
    
    const Gtk::Widget& ToWidget() const override {return as<Gtk::Widget>(*this);}
    
    Gtk::Widget& ToWidget() override {return as<Gtk::Widget>(*this);}
  };
}
#endif
