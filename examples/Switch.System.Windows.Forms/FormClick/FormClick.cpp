#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace FormExample {
  class FormClick {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Form form;
      form.Click += _delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show("The form is clicked", "FormClick", MessageBoxButtons::OK);
      };
      Application::Run(form);
    }
  };
}

_startup(FormExample::FormClick);
