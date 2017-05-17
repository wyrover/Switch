#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/window.h>
#include "WidgetGtk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  Glib::RefPtr<Gtk::Application> application = Gtk::Application::create();
  int32 exitCode = 0;
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  Environment::Exit(exitCode);
}

void FormsApi::Application::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  Glib::signal_idle().connect(pcf_delegate {
    idle.Invoke(object(), EventArgs::Empty);
    return mainForm.Visible() && !idle.IsEmpty();
  });
  exitCode = application->run(as<Gtk::Window>(((__OS::IWidget*)mainForm.Handle())->ToWidget()));
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  Gtk::MessageDialog dialog(caption.c_str(), true /* use_markup */, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL, true);
  dialog.set_secondary_text(message.c_str());
  dialog.set_modal();
  dialog.set_position(Gtk::WindowPosition::WIN_POS_CENTER);
  
  switch (dialog.run()) {
    case Gtk::RESPONSE_ACCEPT: return DialogResult::OK;
    case Gtk::RESPONSE_CANCEL: return DialogResult::Cancel;
  }
  return DialogResult::Cancel;
}

void FormsApi::Application::Start() {

}

void FormsApi::Application::Stop() {
}

#endif
