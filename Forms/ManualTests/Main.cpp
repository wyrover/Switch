#include <Pcf/System/Windows/Forms/Application.hpp>
#include <Pcf/System/Windows/Forms/TabControl.hpp>
#include <Pcf/Startup.hpp>

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

      Form form;
      form.Controls().AddRange({tabControl});

      Application::EnableVisualStyles();
      Application::Run(form);
    }
  };
}

pcf_startup(ManualTests::Program)
