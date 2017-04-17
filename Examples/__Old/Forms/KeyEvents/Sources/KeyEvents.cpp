#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace KeyEventsExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "KeyEvents example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 480);
      this->KeyPreview = true;
      
      this->KeyDown += pcf_delegate(const object& sender, KeyEventArgs& e) {
        this->label1.Text = string::Format("[Form] Event = KeyDown\n") +
        String::Format("KeyData = {0}\n", e.KeyData) +
        String::Format("KeyValue = {0:X}\n", e.KeyValue) +
        String::Format("KeyCode = {0}\n", e.KeyCode) +
        String::Format("Modifiers = {0}\n", e.Modifiers) +
        String::Format("Shift = {0}\n", e.Shift) +
        String::Format("Control = {0}\n", e.Control) +
        String::Format("Alt = {0}\n", e.Alt) +
        String::Format("Command = {0}\n\n", e.Command);
      };
      
      this->KeyPress += pcf_delegate(const object& sender, KeyPressEventArgs& e) {
        this->label1.Text += string::Format("[Form] Event = KeyPress\n") +
        String::Format("KeyChar = {0}\n", e.KeyChar) +
        String::Format("value = {0}\n\n", Convert::ToInt32(e.KeyChar));
      };

      this->KeyUp += pcf_delegate(const object& sender, KeyEventArgs& e) {
        this->label1.Text += string::Format("[Form] Event = KeyUp\n") +
        String::Format("KeyData = {0}\n", e.KeyData) +
        String::Format("KeyValue = {0:X}\n", e.KeyValue) +
        String::Format("KeyCode = {0}\n", e.KeyCode) +
        String::Format("Modifiers = {0}\n", e.Modifiers) +
        String::Format("Shift = {0}\n", e.Shift) +
        String::Format("Control = {0}\n", e.Control) +
        String::Format("Alt = {0}\n", e.Alt) +
        String::Format("Command = {0}\n\n", e.Command);
      };
      
      this->label1.Parent = *this;
      this->label1.AutoSize = false;
      this->label1.BorderStyle = BorderStyle::Fixed3D;
      this->label1.BackColor = System::Drawing::Color::White;
      this->label1.Dock = DockStyle::Fill;
      this->label1.KeyDown += pcf_delegate(const object& sender, KeyEventArgs& e) {
        this->label1.Text = string::Format("[Label] Event = KeyDown\n") +
        String::Format("KeyData = {0}\n", e.KeyData) +
        String::Format("KeyValue = {0:X}\n", e.KeyValue) +
        String::Format("KeyCode = {0}\n", e.KeyCode) +
        String::Format("Modifiers = {0}\n", e.Modifiers) +
        String::Format("Shift = {0}\n", e.Shift) +
        String::Format("Control = {0}\n", e.Control) +
        String::Format("Alt = {0}\n", e.Alt) +
        String::Format("Command = {0}\n\n", e.Command);
      };
    }
    
  private:
    Label label1;
  };
}

pcf_startup (KeyEventsExample::Form1)
