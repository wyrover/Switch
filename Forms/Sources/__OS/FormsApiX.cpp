#if __linux__
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/NotImplementedException.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "FormsApi.h"

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_File_Icon.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Window.H>
#undef None

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  static int32 exitCode = 0;
  static int32 defaultTextSize = 12;

  class IWidget pcf_interface {
  public:
    class WidgetEventArgs : public EventArgs {
    public:
      WidgetEventArgs() {}
      WidgetEventArgs(int32 event, bool isHandled) : event(event), isHandled(isHandled) {}
      WidgetEventArgs(const WidgetEventArgs& eventArgs) : event(eventArgs.event), isHandled(eventArgs.isHandled) {}

      Property<int32, ReadOnly> Event {
        pcf_get {return this->event;}
      };

      Property<bool> IsHandled {
        pcf_get {return this->isHandled;},
        pcf_set {this->isHandled = value;}
      };

    private:
      int32 event = 0;
      bool isHandled = false;
    };

    using WidgetEventHandler = Delegate<void, const object&, WidgetEventArgs&>;

    WidgetEventHandler EventHandled;
    EventHandler Paint;
    EventHandler Callback;

    virtual void Draw() = 0;
  };

  template <typename T>
  class Widget : public T, public IWidget {
  public:
    Widget() : T(0, 0, 0, 0, "") {this->callback(&__Callback__, this);}

    Widget(int width, int height) : T(0, 0, width, height, "") { this->callback(&__Callback__, this); }

    Widget(int width, int height, const char* text) : T(0, 0, width, height, text) { this->callback(&__Callback__, this); }

    Widget(int x, int y, int width, int height) : T(x, y, width, height, "") { this->callback(&__Callback__, this); }

    Widget(int x, int y, int width, int height, const char* text) : T(x, y, width, height, text) { this->callback(&__Callback__, this); }

    Widget(const char* text) : T(0, 0, 0, 0, text) { this->callback(&__Callback__, this); }

    void Draw() override {
      this->T::draw();
    }

    static T& ToWidget(IWidget& widget) {return dynamic_cast<T&>(widget);}

    static const T& ToWidget(const IWidget& widget) {return dynamic_cast<const T&>(widget);}

    static Fl_Text_Buffer& ToText(void* text) {return *reinterpret_cast<Fl_Text_Buffer*>(text);}

    static const Fl_Text_Buffer& ToText(const void* text) {return *reinterpret_cast<const Fl_Text_Buffer*>(text);}

    void FreePosition(bool freePostion) {this->force_position(freePostion);}

  private:
    void draw() override {
      this->Paint(object(), System::EventArgs());
    }

    int handle(int event) override {
      WidgetEventArgs eventArgs(event, T::handle(event) != 0);
      this->EventHandled(object(), eventArgs);
      return as<int32>(eventArgs.IsHandled());
    }

    static void __Callback__(Fl_Widget* widget, void* param) {
      static_cast<Widget<T>*>(param)->Callback(object(), System::EventArgs());
    }
  };

  static Fl_Color FromColor(const System::Drawing::Color& color) {
    return fl_rgb_color(as<byte>(color.R()), as<byte>(color.G()), as<byte>(color.B()));
  }
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  Environment::Exit(exitCode);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  exitCode = Fl::run();
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return DialogResult::None;
}

namespace {
  static int ApplicationHandler(int event) {
    return event == FL_SHORTCUT && Fl::event_key() == FL_Escape ? 1 : 0;
  }
}

void FormsApi::Application::Start() {
  Fl::get_system_colors();
  Fl_File_Icon::load_system_icons();
  Fl::lock();
  if (HasVisualStylesEnabled())
    Fl::scheme("gtk+");
  Fl::add_handler(ApplicationHandler);
}

void FormsApi::Application::Stop() {
  Fl::remove_handler(ApplicationHandler);
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  Widget<Fl_Button>* handle = new Widget<Fl_Button>(button.Location().X, button.Location().Y, button.Size().Width, button.Size().Height, button.data().text.c_str());
  handle->color(FromColor(button.BackColor()));
  handle->labelcolor(FromColor(button.ForeColor()));
  handle->labelsize(defaultTextSize);
  handle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  Widget<Fl_Check_Button>* handle = new Widget<Fl_Check_Button>(checkBox.Location().X, checkBox.Location().Y, checkBox.Size().Width, checkBox.Size().Height, checkBox.data().text.c_str());
  handle->color(FromColor(checkBox.BackColor()));
  handle->labelcolor(FromColor(checkBox.ForeColor()));
  handle->labelsize(defaultTextSize);
  handle->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  return IntPtr::Zero;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  Widget<Fl_Double_Window>* handle = new Widget<Fl_Double_Window>(form.Location().X, form.Location().Y, form.Size().Width, form.Size().Height, form.data().text.c_str());
  handle->color(FromColor(form.BackColor()));
  handle->labelcolor(FromColor(form.ForeColor()));
  handle->labelsize(defaultTextSize);
  handle->resizable(handle);
  handle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& label) {
  Widget<Fl_Box>* handle = new Widget<Fl_Box>(label.Location().X, label.Location().Y, label.Size().Width, label.Size().Height, label.data().text.c_str());
  handle->box(FL_NO_BOX);
  handle->color(FromColor(label.BackColor()));
  handle->labelcolor(FromColor(label.ForeColor()));
  handle->labelsize(defaultTextSize);
  handle->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& radioButton) {
  Widget<Fl_Round_Button>* handle = new Widget<Fl_Round_Button>(radioButton.Location().X, radioButton.Location().Y, radioButton.Size().Width, radioButton.Size().Height, radioButton.data().text.c_str());
  handle->color(FromColor(radioButton.BackColor()));
  handle->labelcolor(FromColor(radioButton.ForeColor()));
  handle->labelsize(defaultTextSize);
  handle->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero) {
    if (is<System::Windows::Forms::ContainerControl>(control)) {
      for (int index = 0; index < ((Fl_Group*)control.data().handle)->children(); index++)
        ((Fl_Group*)control.data().handle)->remove(index);
    }
    delete (Widget<Fl_Widget>*)control.data().handle;
  }
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return {};
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return {};
}

void FormsApi::Control::SetBackColor(intptr hdc, const System::Drawing::Color& color) {
  ((Widget<Fl_Widget>*)hdc)->color(FromColor(color));
}

void FormsApi::Control::SetForeColor(intptr hdc, const System::Drawing::Color& color) {
  ((Widget<Fl_Widget>*)hdc)->labelcolor(FromColor(color));
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    ((Widget<Fl_Widget>*)control.data().handle)->color(FromColor(control.BackColor()));
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    ((Widget<Fl_Widget>*)control.data().handle)->labelcolor(FromColor(control.ForeColor()));
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    ((Widget<Fl_Widget>*)control.data().handle)->copy_label(control.Text().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  ((Widget<Fl_Widget>*)control.data().handle)->show();
}

int32 FormsApi::SystemInformation::GetActiveWindowTrackingDelay() {
  return 0;
}

ArrangeDirection FormsApi::SystemInformation::GetArrangeDirection() {
  return ArrangeDirection::Left;
}

ArrangeStartingPosition FormsApi::SystemInformation::GetArrangeStartingPosition() {
  return ArrangeStartingPosition::Hide;
}

BootMode FormsApi::SystemInformation::GetBootMode() {
  return BootMode::Normal;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorder3DSize() {
  return System::Drawing::Size(1, 1);
}

int32 FormsApi::SystemInformation::GetBorderMultiplierFactor() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorderSize() {
  return System::Drawing::Size(1, 1);
}

System::Drawing::Size FormsApi::SystemInformation::GetCaptionButtonSize() {
  return System::Drawing::Size(16, 16);
}

int32 FormsApi::SystemInformation::GetCaptionHeight() {
  return 23;
}

int32 FormsApi::SystemInformation::GetCaretBlinkTime() {
  return 530;
}

int32 FormsApi::SystemInformation::GetCaretWidth() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetCursorSize() {
  return System::Drawing::Size(32, 32);
}

bool FormsApi::SystemInformation::GetDbcsEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetDebugOS() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetDoubleClickSize() {
  return System::Drawing::Size(4, 4);
}

int32 FormsApi::SystemInformation::GetDoubleClickTime() {
  return 500;
}

bool FormsApi::SystemInformation::GetDragFullWindows() {
  return true;
}

System::Drawing::Size FormsApi::SystemInformation::GetDragSize() {
  return System::Drawing::Size(4, 4);
}

System::Drawing::Size FormsApi::SystemInformation::GetFixedFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

int32 FormsApi::SystemInformation::GetFontSmoothingContrast() {
  return 1200;
}

int32 FormsApi::SystemInformation::GetFontSmoothingType() {
  return 2;
}

System::Drawing::Size FormsApi::SystemInformation::GetFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetHighContrast() {
  return false;
}

int32 FormsApi::SystemInformation::GetHorizontalFocusThickness() {
  return 1;
}

int32 FormsApi::SystemInformation::GetHorizontalResizeBorderThickness() {
  return 4;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarHeight() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetIconHorizontalSpacing() {
  return 75;
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSize() {
  return System::Drawing::Size(64, 64);
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSpacingSize() {
  return System::Drawing::Size(75, 75);
}

int32 FormsApi::SystemInformation::GetIconVerticalSpacing() {
  return 75;
}

bool FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsDropShadowEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsFlatMenuEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsFontSmoothingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsHotTrackingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsKeyboardPreferred() {
  return false;
}

bool FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuFadeEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsSelectionFadeEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsSnapToDefaultEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsTitleBarGradientEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsToolTipAnimationEnabled() {
  return false;
}

int32 FormsApi::SystemInformation::GetKanjiWindowHeight() {
  return 0;
}

int32 FormsApi::SystemInformation::GetKeyboardDelay() {
  return 1;
}

int32 FormsApi::SystemInformation::GetKeyboardSpeed() {
  return 31;
}

System::Drawing::Size FormsApi::SystemInformation::GetMaxWindowTrackSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetMenuAccessKeysUnderlined() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuBarButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuCheckSize() {
  return System::Drawing::Size(15, 15);
}

System::Drawing::Font FormsApi::SystemInformation::GetMenuFont() {
  return System::Drawing::Font::FromLogFont((intptr)0);
}

int32 FormsApi::SystemInformation::GetMenuHeight() {
  return 23;
}

#endif
