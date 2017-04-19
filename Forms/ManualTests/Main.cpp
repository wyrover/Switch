#include <Pcf/Forms.h>

using namespace System;
using namespace System::Windows::Forms;

namespace PcfFormApp {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Diagnostics::Debug::Listeners().Add(System::Diagnostics::ConsoleTraceListener());
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Name = "form1";
      this->Text = "First Application";
      this->Location = System::Drawing::Point(200, 100);
      this->BackColor = System::Drawing::SystemColors::Control;

      this->FormClosing += pcf_delegate(const object& sender, FormClosingEventArgs& e) {
        e.Cancel = MessageBox::Show("Do you want quit application ?", "Program", MessageBoxButtons::YesNo, MessageBoxIcon::Question) != DialogResult::Yes;
      };

      this->MouseMove += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label2.Text = e.Location().ToString();
      };

      /*
      this->button1.Parent = *this;
      this->button1.Name = "button1";
      this->button1.Text = "Button";
      this->button1.Location = System::Drawing::Point(10, 10);
      this->button1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        static int32 counter = 0;
        this->label1.Text = string::Format("counter = {0}", ++counter);
        System::Media::SystemSounds::Asterisk().Play();
      };

      this->button2.Parent = *this;
      this->button2.Name = "button2";
      this->button2.Text = "Message";
      this->button2.Location = System::Drawing::Point(100, 10);
      this->button2.Size = System::Drawing::Size(80, 25);
      this->button2.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLine("DialogResult = {0}", MessageBox::Show("This is a very long message for testing if MessageBox\ncan adapt his size with good values.", "A message box", MessageBoxButtons::OK, MessageBoxIcon::Hand));
      };

      this->checkBox1.Parent = *this;
      this->checkBox1.Name = "checkBox1";
      this->checkBox1.Text = "CheckBox";
      this->checkBox1.Location = System::Drawing::Point(10, 40);
      
      this->radioButton1.Parent = *this;
      this->radioButton1.Name = "radioButton1";
      this->radioButton1.Text = "RadioButton 1";
      this->radioButton1.Location = System::Drawing::Point(10, 70);
      this->radioButton1.Size = System::Drawing::Size(120, 25);

      this->radioButton2.Parent = *this;
      this->radioButton2.Name = "radioButton2";
      this->radioButton2.Text = "RadioButton 2";
      this->radioButton2.Location = System::Drawing::Point(10, 100);
      this->radioButton2.Size = System::Drawing::Size(120, 25);

      this->label1.Parent = *this;
      this->label1.BackColor = System::Drawing::Color::SpringGreen;
      this->label1.ForeColor = System::Drawing::Color::DarkRed;
      this->label1.Name = "label1";
      this->label1.Text = "counter = 0";
      this->label1.Location = System::Drawing::Point(28, 132);
      this->label1.Size = System::Drawing::Size(150, 23);

      this->label2.Parent = *this;
      this->label2.BackColor = System::Drawing::Color::FromArgb(128, System::Drawing::Color::SpringGreen);
      this->label2.Name = "label2";
      this->label2.Text = "(X=0,Y=0)";
      this->label2.Location = System::Drawing::Point(28, 162);
      this->label2.Size = System::Drawing::Size(150, 23);
    */
    }

  private:
    Button button1;
    Button button2;
    CheckBox checkBox1;
    RadioButton radioButton1;
    RadioButton radioButton2;
    Label label1;
    Label label2;
  };
}

pcf_startup (PcfFormApp::Form1)
