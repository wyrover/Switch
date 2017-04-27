#include <Pcf/Forms.h>

using namespace System;
using namespace System::Windows::Forms;

namespace PcfFormApp {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      ProgressBar progressBar;
      progressBar.Location = System::Drawing::Point(10, 10);
      progressBar.Minimum = 0;
      progressBar.Maximum = 100;
      progressBar.Value = 50;
 
      Form form;
      form.Controls().AddRange({progressBar});

      Application::EnableVisualStyles();
      Application::Run(form);
    }
  };
}

pcf_startup (PcfFormApp::Program)
