#include <Pcf/Pcf>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace HelloWorld {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      
      Button button;
      button.Text = "Click me";
      button.Location = Point(10, 10);
      button.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show("Hello, World!");
      };
      
      Form form;
      form.Text = "Hello World Form";
      form.Controls().Add(button);
      
      Application::Run(form);
    }
  };
}

pcf_startup (HelloWorld::Program)
