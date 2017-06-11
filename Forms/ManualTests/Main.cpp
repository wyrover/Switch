#include <Pcf/Startup.hpp>
#include <Pcf/System/Diagnostics/Debug.hpp>
#include <Pcf/System/Windows/Forms/Application.hpp>
#include <Pcf/System/Windows/Forms/CheckBox.hpp>

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
      form.Text = "Form1";
      form.Controls().AddRange({checkBox1, checkBox2, checkBox3});
      form.BackColor = Color::White;
      form.ForeColor = Color::Black;
      
      System::Diagnostics::Debug::AutoFlush = true;
      
      form.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLine("MouseEnter");
      };
      
      form.MouseDown += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("MouseDown {0} {{{1}, {2}}}", e.Button, e.X, e.Y);
      };
      
      form.MouseUp += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("MouseUp {0} {{{1}, {2}}}", e.Button, e.X, e.Y);
      };
      
      form.MouseMove += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("MouseMove {0} {{{1}, {2}}}", e.Button, e.X, e.Y);
      };
      
      form.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLine("MouseLeave");
      };

      Application::Run(form);
    }
  };
}

pcf_startup(PcfFormApp::Program)
