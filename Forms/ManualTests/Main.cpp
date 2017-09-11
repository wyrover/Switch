#include <Switch/System/Windows/Forms/Application.hpp>
#include <Switch/System/Windows/Forms/Button.hpp>
#include <Switch/System/Windows/Forms/TabControl.hpp>
#include <Switch/Startup.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {
      TabPage tabPage1;
      tabPage1.Text = "tabPage1";

      TabPage tabPage2;
      tabPage2.Text = "tabPage2";

      TabControl tabControl;
      tabControl.Location = Point(10, 10);
      //tabControl.TabPages().AddRange({tabPage1, tabPage2});

      Button button;
      //button.Size = Size(200, 100);
      button.Text = "My Button";
      button.Location = Point(10, 10);
      
      Form form;
      form.Controls().AddRange({button});

      Application::EnableVisualStyles();
      Application::Run(form);
    }
  };
}

startup(ManualTests::Program)
