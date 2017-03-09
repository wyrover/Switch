#include <Pcf/System/Windows/Forms/Application.h>
#include <Pcf/System/Windows/Forms/Button.h>
#include <Pcf/System/Windows/Forms/CheckBox.h>
#include <Pcf/System/Windows/Forms/Form.h>
#include <Pcf/System/Windows/Forms/Label.h>
#include <Pcf/System/Windows/Forms/MessageBox.h>
#include <Pcf/System/Windows/Forms/RadioButton.h>
#include <Pcf/System/Windows/Forms/SystemInformation.h>
#include <Pcf/Startup.h>

using namespace System;
using namespace System::Windows::Forms;

namespace PcfFormApp {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Name = "form1";
      this->BackColor = System::Drawing::Color::SpringGreen;
      this->Text = "First Application";
      this->Location = System::Drawing::Point(200, 100);
      
      this->button1.Parent = *this;
      this->button1.BackColor = System::Drawing::Color::SpringGreen;
      this->button1.Name = "button1";
      this->button1.Text = "Button";
      this->button1.Location = System::Drawing::Point(10, 10);
      this->button1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLine("Result = {0}", MessageBox::Show("This is my first message", "ManualTest", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation));
      };
      this->button1.Paint += pcf_delegate(const object& sender, PaintEventArgs& e) {
        e.Graphics().Clear(System::Drawing::Color::LawnGreen);
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
      this->label1.Name = "label1";
      this->label1.BackColor = System::Drawing::Color::Azure;
      this->label1.Text = "Text label";
      this->label1.Location = System::Drawing::Point(10, 130);
      this->label1.Size = System::Drawing::Size(200, 23);
    }
    
  private:
    Button button1;
    CheckBox checkBox1;
    RadioButton radioButton1;
    RadioButton radioButton2;
    Label label1;
  };
}

pcf_startup (PcfFormApp::Form1)
