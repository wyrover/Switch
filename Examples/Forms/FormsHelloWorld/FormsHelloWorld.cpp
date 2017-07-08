#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace FormsHelloWorld {
  class Program  {
  public:
    // The main entry point for the application.
    static void Main() {
      Button button;
      button.Text = "Click me";
      button.Location = System::Drawing::Point(10, 10);
      button.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show("Hello, World!");
      };
      
      Form form;
      form.Text = "Forms Hello World";
      form.Controls().Add(button);

      Application::EnableVisualStyles();
      Application::Run(form);
    }
  };
}

pcf_startup (FormsHelloWorld::Program)
