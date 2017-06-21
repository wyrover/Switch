#include <Pcf/Startup.hpp>
#include <Pcf/System/Diagnostics/Debug.hpp>
#include <Pcf/System/Windows/Forms/Application.hpp>
#include <Pcf/System/Windows/Forms/Button.hpp>
#include <Pcf/System/Windows/Forms/Label.hpp>
#include <Pcf/System/Windows/Forms/MessageBox.hpp>

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

      Label label;
      label.Text = "Result = ";
      label.Location = Point(10, 50);

      Button button;
      button.Text = "Message";
      button.Location = Point(10, 10);
      button.Enabled = false;
      button.Click = pcf_delegate(const object& sender, const EventArgs& e) {
        label.Text = string::Format("Result = {0}", MessageBox::Show("This is the text messge of the MessageBox", "Title MessageBox", MessageBoxButtons::OKCancel, MessageBoxIcon::Question));
      };

      Form form;
      form.Controls().AddRange({label, button});

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
