#if defined(__use_fltk_interface__)
#include "FormsApi.h"

#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>
#include <FL/Fl_File_Icon.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Return_Button.H>

#include <Pcf/Undef.h>

#include "Exclamation.h"
#include "Information.h"
#include "Question.h"
#include "Stop.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  static Fl_Pixmap exclamationIcon(Exclamation);
  static Fl_Pixmap informationIcon(Information);
  static Fl_Pixmap noneIcon(Information);
  static Fl_Pixmap questionIcon(Question);
  static Fl_Pixmap stopIcon(Stop);
  static int32 exitCode = 0;
  static int32 defaultTextSize = 12;

  static Fl_Color FromColor(const System::Drawing::Color& color) {
    return fl_rgb_color(as<byte>(color.R()), as<byte>(color.G()), as<byte>(color.B()));
  }
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::AddForm(const System::Windows::Forms::Form& form) {
}

void FormsApi::Application::Exit() {
  Environment::Exit(exitCode);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  exitCode = Fl::run();
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
  System::Collections::Generic::SortedDictionary<MessageBoxIcon, int32> beep = {{(MessageBoxIcon)0, FL_BEEP_DEFAULT}, {MessageBoxIcon::Error, FL_BEEP_ERROR}, {MessageBoxIcon::Question, FL_BEEP_QUESTION}, {MessageBoxIcon::Warning, FL_BEEP_MESSAGE}, {MessageBoxIcon::Information, FL_BEEP_NOTIFICATION}, {(MessageBoxIcon)0xFFFFFFFF, FL_BEEP_DEFAULT}};
  fl_beep(beep[type]);
}

namespace {
  DialogResult ShowMessageBoxAbortRetryIgnore(const string& message) {
    int result = fl_choice("%s", "Abort", "Retry", "Ignore", message.c_str());
    if (result == 0) return DialogResult::Abort;
    if (result == 2) return DialogResult::Ignore;
    return DialogResult::Retry;
  }

  DialogResult ShowMessageBoxOK(const string& message) {
    fl_choice("%s", "OK", null, null, message.c_str());
    return DialogResult::OK;
  }

  DialogResult ShowMessageBoxOKCancel(const string& message) {
    int result = fl_choice("%s", "Cancel", "OK", null, message.c_str());
    if (result == 0) return DialogResult::Cancel;
    return DialogResult::OK;
  }

  DialogResult ShowMessageBoxRetryCancel(const string& message) {
    int result = fl_choice("%s", "Cancel", "Retry", null, message.c_str());
    if (result == 0) return DialogResult::Cancel;
    return DialogResult::Retry;
  }

  DialogResult ShowMessageBoxYesNo(const string& message) {
    int result = fl_choice("%s", "No", "Yes", null, message.c_str());
    if (result == 0) return DialogResult::No;
    return DialogResult::Yes;
  }

  DialogResult ShowMessageBoxYesNoCancel(const string& message) {
    int result = fl_choice("%s", "No", "Yes", "Cancel", message.c_str());
    if (result == 0) return DialogResult::No;
    if (result == 2) return DialogResult::Cancel;
    return DialogResult::Yes;
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static System::Collections::Generic::SortedDictionary<MessageBoxButtons, delegate<DialogResult, const string&>> showMessageBox = {{MessageBoxButtons::AbortRetryIgnore, ShowMessageBoxAbortRetryIgnore}, {MessageBoxButtons::OK, ShowMessageBoxOK}, {MessageBoxButtons::OKCancel, ShowMessageBoxOKCancel}, {MessageBoxButtons::RetryCancel, ShowMessageBoxRetryCancel}, {MessageBoxButtons::YesNo, ShowMessageBoxYesNo}, {MessageBoxButtons::YesNoCancel, ShowMessageBoxYesNoCancel}};
  static System::Collections::Generic::SortedDictionary<MessageBoxIcon, Fl_Pixmap*> messageBoxIcon = {{MessageBoxIcon::Exclamation, &exclamationIcon}, {MessageBoxIcon::Information, &informationIcon}, {MessageBoxIcon::None, &noneIcon}, {MessageBoxIcon::Question, &questionIcon}, {MessageBoxIcon::Stop, &stopIcon}};
  fl_message_icon()->align(FL_ALIGN_TEXT_NEXT_TO_IMAGE);
  fl_message_icon()->box(FL_NO_BOX);
  fl_message_icon()->hide();
  fl_message_icon()->label("");
  Fl_Group* messageBox = fl_message_icon()->parent();
  messageBox->color(FromColor(System::Drawing::Color::White));
  messageBox->labelsize(defaultTextSize);
  for (int index = 0; index < messageBox->children(); index++) {
    if (is<Fl_Return_Button>(messageBox->child(index))) {
      messageBox->child(index)->color(FromColor(System::Drawing::SystemColors::Highlight));
      messageBox->child(index)->labelcolor(FromColor(System::Drawing::Color::White));
    } else
      messageBox->child(index)->color(FromColor(System::Windows::Forms::Control::DefaultBackColor));
    if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX)
      messageBox->child(index)->selection_color(FromColor(System::Drawing::SystemColors::Highlight));
    messageBox->child(index)->labelsize(defaultTextSize);
  }

  fl_message_title(caption.c_str());
  fl_message_hotspot(false);
  if (icon != MessageBoxIcon::None) {
    fl_message_icon()->show();
    fl_message_icon()->image(messageBoxIcon[icon]);
  }
  return showMessageBox[buttons](message);
}

namespace {
  static int32 ApplicationHandler(int32 event) {
    return event == FL_SHORTCUT && Fl::event_key() == FL_Escape ? 1 : 0;
  }

  static void DrawLabel(const Fl_Label *label, int left, int top, int width, int height, Fl_Align align) {
    fl_font(label->font, label->size);
    fl_color((Fl_Color)label->color);
    fl_draw(label->value, left, top, width, height, align, label->image, 0 /*1 (default): replace patterns (like "@->") by symbols; 0: do not replace patterns by symbols*/);
  }

  static void MeasureLabel(const Fl_Label *label, int &width, int &height) {
    fl_font(label->font, label->size);
    fl_measure(label->value, width, height, 0 /*1 (default): replace patterns (like "@->") by symbols; 0: do not replace patterns by symbols*/);
  }
}

void FormsApi::Application::Start() {
  Fl_Window::default_xclass(System::IO::Path::GetFileName(System::Environment::GetCommandLineArgs()[0]).c_str());
  Fl::set_labeltype(FL_NORMAL_LABEL, DrawLabel, MeasureLabel);
  Fl::get_system_colors();
  if (Environment::OSVersion().Platform == PlatformID::MacOSX)
    Fl::set_color(FL_SELECTION_COLOR, 0x56, 0x96, 0xF5);
  Fl_File_Icon::load_system_icons();
  Fl::lock();
  if (HasVisualStylesEnabled())
    Fl::scheme("gtk+");
  Fl::add_handler(ApplicationHandler);
}

void FormsApi::Application::Stop() {
  Fl::remove_handler(ApplicationHandler);
}

#endif
