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
      static bool DebugKeyboardEvent = true;
      static bool DebugMouseEvent = false;

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
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("MouseEnter"));
      };
      
      form.MouseDown += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("MouseDown {0} {{{1}, {2}}}", e.Button, e.X, e.Y));
      };

      form.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("Click"));
      };

      form.MouseClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("MouseClick {0} {{{1}, {2}}}", e.Button, e.X, e.Y));
      };

      form.DoubleClick += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("DoubleClick"));
      };

      form.MouseDoubleClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("MouseDoubleClick {0} {{{1}, {2}}}", e.Button, e.X, e.Y));
      };

      form.MouseUp += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("MouseUp {0} {{{1}, {2}}}", e.Button, e.X, e.Y));
      };
      
      form.MouseMove += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("MouseMove {0} {{{1}, {2}}}", e.Button, e.X, e.Y));
      };

      form.MouseHover += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("MouseHover"));
      };

      form.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugMouseEvent, string::Format("MouseLeave"));
      };

      form.KeyDown += pcf_delegate(const object& sender, KeyEventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugKeyboardEvent, string::Format("KeyDown KeyCode {0} KeyValue {1} KeyData {2} KeyModifiers {3}", e.KeyCode, e.KeyValue, e.KeyData, e.Modifiers));
      };

      form.KeyPress += pcf_delegate(const object& sender, KeyPressEventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugKeyboardEvent, string::Format("KeyPress KeyChar {0}", e.KeyChar));
      };

      form.KeyUp += pcf_delegate(const object& sender, KeyEventArgs& e) {
        System::Diagnostics::Debug::WriteLineIf(DebugKeyboardEvent, string::Format("KeyUp KeyCode {0} KeyValue {1} KeyData {2} KeyModifiers {3}", e.KeyCode, e.KeyValue, e.KeyData, e.Modifiers));
      };

      Application::Run(form);
    }
  };
}

pcf_startup(PcfFormApp::Program)
