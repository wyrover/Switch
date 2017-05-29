#include <Pcf/Startup.h>
#include <Pcf/System/Windows/Forms/Application.h>
#include <Pcf/System/Windows/Forms/Button.h>
#include <Pcf/System/Windows/Forms/CheckBox.h>
#include <Pcf/System/Windows/Forms/ProgressBar.h>
#include <Pcf/System/Windows/Forms/RadioButton.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace PcfFormApp {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();

      CheckBox checkBox1;
      checkBox1.Text = "Checked";
      checkBox1.Location = Point(30, 30);
      checkBox1.CheckState = System::Windows::Forms::CheckState::Checked;

      CheckBox checkBox2;
      checkBox2.Text = "Unchecked";
      checkBox2.Location = Point(30, 60);
      checkBox2.CheckState = System::Windows::Forms::CheckState::Unchecked;

      CheckBox checkBox3;
      checkBox3.Text = "Indeterminate";
      checkBox3.Location = Point(30, 90);
      checkBox3.CheckState = System::Windows::Forms::CheckState::Indeterminate;

      Form form;
      form.Controls().AddRange({checkBox1, checkBox2, checkBox3});
      //form.BackColor = Color::White;
      //form.ForeColor = Color::Black;

      Application::Run(form);
    }
  };
}

pcf_startup(PcfFormApp::Program)

